#pragma once
#include <iostream>
/******************************************************************************/
/*                            MACROS                                          */
/******************************************************************************/

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

/*	Erros	*/
# define ERROR_INIT_WINDOWS "Init windows: "

# define ERROR_INVALID_ARGUMENTS "Invalid arguments: the number of arguments\
must be two: num: "
# define ERROR_TOO_MANY_ARG "too many arguments: the number of arguments\
must be two: num: "

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define END "\033[m"             
# define RED "\033[1m\033[1;31m"
# define GREEN "\033[1m\033[1;32m"
# define YELLOW "\033[1m\033[1;33m"
# define BLUE "\033[1;34m"
# define TUR "\033[1m\033[1;35m"
# define CYAN "\033[1;36m"
# define ORANGE "\033[1m\033[38;5;208m"
# define PURPLE "\033[1m\033[38;5;128m"

enum e_code_errors
{
	INIT = 1
};

template <typename PrintT>
int	error_message(int	exitCode, const std::string error, PrintT foo)
{
	std::cout << RED << "Error: " << END << error << foo << std::endl;
	return (exitCode);
}