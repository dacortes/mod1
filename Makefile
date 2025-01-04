################################################################################
#                               VARIABLES                                      #
################################################################################

RMV = rm -rf
CPP = g++
CFLAGS = -Wall -Werror -Wextra -g -pedantic -std=c++11 -fsanitize=address
VULKAN_FLAGS = -lvulkan -lglfw
NAME = mod1
TOTAL_FILES = $(words $(SOURCES))

DIRECTORY_OBJ = obj
DIRECTORY_DEP = dep
DIRECTORY_TEST_OBJ = test_obj
DIRECTORY_TEST_DEP = test_dep

DIRECTORI_SOURCE = src
DIRECTORI_TEST = test

OBJECTS = $(addprefix $(DIRECTORY_OBJ)/, $(SOURCES:.cpp=.o))
DEPENDENCIES = $(addprefix $(DIRECTORY_DEP)/, $(SOURCES:.cpp=.d))

OBJECTS_TEST = $(addprefix $(DIRECTORY_TEST_OBJ)/, $(SOURCES_TEST:.cpp=.o))
DEPENDENCIES_TEST = $(addprefix $(DIRECTORY_TEST_DEP)/, $(SOURCES_TEST:.cpp:.d))

INCLUDES = $(addprefix -I, inc)
SOURCES_TEST = test_main.cpp
SOURCES = main.cpp

################################################################################
#                               BOLD COLORS                                    #
################################################################################

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m

################################################################################
#  FONT                                                                        #
################################################################################

ligth = \033[1m
dark = \033[2m
italic = \033[3m

################################################################################
#                               MAKE RULES                                     #
################################################################################

DIRS_TO_CREATE =

all: DIRS_TO_CREATE = $(DIRECTORY_OBJ) $(DIRECTORY_DEP)
all: dir $(NAME)

test: DIRS_TO_CREATE = $(DIRECTORY_TEST_OBJ) $(DIRECTORY_TEST_DEP)
test: dir $(NAME)_test

$(NAME): $(OBJECTS)
	$(CPP) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(VULKAN_FLAGS)
	@echo "\n✅ ==== $(BLUE)$(ligth)Project $(NAME) compiled!$(END) ==== ✅"

$(DIRECTORY_OBJ)/%.o:$(DIRECTORI_SOURCE)/%.cpp
	@printf "  $(ligth)Compiling $(BLUE)$<$(END)      "
	@$(CPP) $(CFLAGS) $(INCLUDES) -MMD -MF $(DIRECTORY_DEP)/$*.d -c $< -o $@
	@$(call progress,$<)

$(NAME)_test: $(OBJECTS_TEST)
	$(CPP) $(CFLAGS) $(INCLUDES) $(OBJECTS_TEST) -o $(NAME)_test $(VULKAN_FLAGS)
	@echo "\n✅ ==== $(BLUE)$(ligth)Project test compiled!$(END) ==== ✅"

$(DIRECTORY_TEST_OBJ)/%.o:$(DIRECTORI_TEST)/%.cpp
	@printf "  $(ligth)Compiling $(BLUE)$<$(END)      "
	@$(CPP) $(CFLAGS) $(INCLUDES) -MMD -MF $(DIRECTORY_TEST_DEP)/$*.d -c $< -o $@
	@$(call progress,$<)

dir:
	@for DIR in $(DIRS_TO_CREATE); do \
		if [ ! -d $$DIR ]; then \
			mkdir -p $$DIR; \
			printf "$(BLUE)$(ligth)Creating directory:$(END) $$DIR\n"; \
		else \
			printf "$(BLUE)$(ligth)Directory already exists:$(END) $$DIR\n"; \
		fi \
	done

clean: DIRS_TO_CREATE = $(DIRECTORY_OBJ) $(DIRECTORY_DEP) $(DIRECTORY_TEST_OBJ) $(DIRECTORY_TEST_DEP)
clean:
	@for DIR in $(DIRS_TO_CREATE); do \
		if [ -d $$DIR ]; then \
			$(RMV) $$DIR; \
			printf "$(BLUE)$(ligth)Directory$(END) $$DIR $(BLUE)$(ligth)removed$(END)\n"; \
		else \
			printf "$(ligth)The directory does not exist:$(END) $$DIR\n"; \
		fi \
	done
	echo "✅ ==== $(PURPLE)$(ligth)$(NAME) object files cleaned!$(END) ==== ✅"

fclean: clean
	$(RMV) $(NAME) $(NAME)_test
	echo "✅ ==== $(PURPLE)$(ligth)$(NAME) executable files and name cleaned!$(END) ==== ✅"

define progress
	@$(eval COMPILED_FILES=$(shell expr $(COMPILED_FILES) + 1))
	@bash -c 'PROG_BAR_WIDTH=50; \
	PROGRESS=$$(($(COMPILED_FILES) * $$PROG_BAR_WIDTH / $(TOTAL_FILES))); \
	EMPTY=$$(($$PROG_BAR_WIDTH - $$PROGRESS)); \
	PROGRESS=$$((PROGRESS < 0 ? 0 : PROGRESS)); \
	EMPTY=$$((EMPTY < 0 ? 0 : EMPTY)); \
	printf "\r$(ligth)[$(GREEN)"; \
	for ((i = 0; i < $$PROGRESS; i++)); do echo -n "█"; done; \
	for ((i = 0; i < $$EMPTY; i++)); do echo -n " "; done; \
	printf "$(END)$(ligth)] "; \
	printf "%d%%$(END)" $$((100 * $(COMPILED_FILES) / $(TOTAL_FILES)));'
endef

-include $(DEPENDENCIES) $(DEPENDENCIES_TEST)

re: fclean all
.PHONY: all clean progress fclean test
COMPILED_FILES=0
.SILENT: