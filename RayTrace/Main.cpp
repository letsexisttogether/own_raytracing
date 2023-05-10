#include <iostream>
#include <fstream>
#include <string>

#include "CmdParser/CmdParser.hpp"

int32_t main(std::uint32_t argc, const char* argv[])
{
	try
	{
		CmdParser parser{ argc, argv };
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << std::endl;
		return EXIT_FAILURE;
	}

    return EXIT_SUCCESS;
}