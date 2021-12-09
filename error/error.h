#ifndef ERROR_H
#define ERROR_H

#include <string>

const int	COMMAND_ERROR = 1;
const int	NUMBER_ARGS_ERROR = 2;
const int	FORMAT_ARGS_ERROR = 3;

std::string	parseErrorCode(int error_code);

#endif
