#include <iostream>

#include "Tools/CmdParser/CmdParser.hpp"

std::int32_t main(int argc, const char* argv[])
{
	try
	{
		CmdParser parser(argc, argv);

		std::cout << "The source: " << parser.GetSourceName() << '.' << parser.GetSourceFormat()
			<< "\nThe output: " << parser.GetOutput() << '.' << parser.GetGoalFormat() << std::endl;
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << std::endl;
	}

	return 0;
}
