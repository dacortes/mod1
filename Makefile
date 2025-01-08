################################################################################
#                               VARIABLES                                      #
################################################################################

RMV = rm -rf
CPP = g++
CFLAGS = -Wall -Werror -Wextra -g -pedantic -std=c++11 -fsanitize=address
LIB_FLAGS = -ldl -lglfw -pthread -lm
NAME = mod1
TOTAL_FILES = $(words $(SOURCES))

DIRECTORY_OBJ = obj
DIRECTORY_DEP = dep
DIRECTORY_TEST_OBJ = test_obj
DIRECTORY_TEST_DEP = test_dep

DIRECTORI_SOURCE = src
SUB_DIRECTORIES = win
DIRECTORI_TEST = test

OBJECTS = $(addprefix $(DIRECTORY_OBJ)/, $(SOURCES:.cpp=.o))
DEPENDENCIES = $(addprefix $(DIRECTORY_DEP)/, $(SOURCES:.cpp=.d))

OBJECTS_TEST = $(addprefix $(DIRECTORY_TEST_OBJ)/, $(SOURCES_TEST:.cpp=.o))
DEPENDENCIES_TEST = $(addprefix $(DIRECTORY_TEST_DEP)/, $(SOURCES_TEST:.cpp:.d))

INCLUDES = $(addprefix -I, include)
SOURCES_TEST = test_main.cpp #test_init.cpp #test_main.cpp
SOURCES = win/MlxWindow.cpp win/Scene2D.cpp main.cpp

PATH_LIB_MINILIBX = ./lib/minilibX
DIR_BUILD_MINILIBX = build
MINILIB_A = $(DIR_BUILD_MINILIBX)/libmlx42.a
MINILIB_INCLUDES = $(addprefix -I, $(PATH_LIB_MINILIBX)/include)

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
all: minilib libs dir $(NAME)

test: DIRS_TO_CREATE = $(DIRECTORY_TEST_OBJ) $(DIRECTORY_TEST_DEP)
test: minilib libs dir $(NAME)_test

minilib:
	@if [ ! -d "./lib/minilibX/.git" ]; then \
        git clone git@github.com:codam-coding-college/MLX42.git ./lib/minilibX; \
        git submodule update --init --recursive; \
    elif [ -d "./lib/minilibX/.git" ]; then \
        echo "$(YELLOW)$(ligth)[ Warnig ]$(END) $@: already exists and is a valid git repository."; \
    else \
        echo "$(YELLOW)$(ligth)[ Warnig ]$(END) $@: already exists and is not an empty directory."; \
    fi

libs:
	@cmake -B build $(PATH_LIB_MINILIBX) > /dev/null 2>&1
	@cmake --build $(DIR_BUILD_MINILIBX) -j4 > /dev/null 2>&1

$(NAME): $(OBJECTS)
	$(CPP) $(CFLAGS) $(INCLUDES) $(MINILIB_INCLUDES) $(OBJECTS) -o $(NAME) $(LIB_FLAGS) $(MINILIB_A)
	@echo "\n✅ ==== $(BLUE)$(ligth)Project $(NAME) compiled!$(END) ==== ✅"

$(DIRECTORY_OBJ)/%.o:$(DIRECTORI_SOURCE)/%.cpp
	@printf "  $(ligth)Compiling $(BLUE)$<$(END)      "
	@$(CPP) $(CFLAGS) $(INCLUDES) $(MINILIB_INCLUDES) -MMD -MF $(DIRECTORY_DEP)/$*.d -c $< -o $@
	@$(call progress,$<)

$(NAME)_test: $(OBJECTS_TEST)
	$(CPP) $(CFLAGS) $(INCLUDES) $(MINILIB_INCLUDES) $(OBJECTS_TEST) -o $(NAME)_test $(LIB_FLAGS) $(MINILIB_A)
	@echo "\n✅ ==== $(BLUE)$(ligth)Project test compiled!$(END) ==== ✅"

$(DIRECTORY_TEST_OBJ)/%.o:$(DIRECTORI_TEST)/%.cpp
	@printf "  $(ligth)Compiling $(BLUE)$<$(END)      "
	@$(CPP) $(CFLAGS) $(INCLUDES) $(MINILIB_INCLUDES) -MMD -MF $(DIRECTORY_TEST_DEP)/$*.d -c $< -o $@
	@$(call progress,$<)

dir:
	@for DIR in $(DIRS_TO_CREATE); do \
		if [ ! -d $$DIR ]; then \
			mkdir -p $$DIR; \
			$(foreach SUB, $(SUB_DIRECTORIES), mkdir -p $$DIR/$(SUB_DIRECTORIES)); \
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
	$(RMV) $(DIR_BUILD_MINILIBX)
	$(RMV) $(PATH_LIB_MINILIBX)/*
	$(RMV) $(PATH_LIB_MINILIBX)/.git*
	echo "✅ ==== $(PURPLE)$(ligth)$(NAME) object files cleaned!$(END) ==== ✅"

fclean: clean
	$(RMV) $(NAME) $(NAME)_test
	$(RMV) $(PATH_LIB_MINILIBX)
	$(RMV) $(DIR_BUILD_MINILIBX)
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
.PHONY: all clean progress fclean test dir minilib libs
COMPILED_FILES=0
.SILENT: