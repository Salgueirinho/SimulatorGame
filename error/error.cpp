#include "error.h"

std::string	parseErrorCode(const int error_code)
{
	switch (error_code)
	{
		case COMMAND_ERROR:
			return "Command doesn't exist\n";
		case NUMBER_ARGS_ERROR:
			return "Invalid number of arguments.\n";
		case FORMAT_ARGS_ERROR:
			return "Invalid format for arguments.\n";
		default:
			return "";
	}
}
