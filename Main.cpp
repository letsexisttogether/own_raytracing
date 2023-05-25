#include <iostream>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/FabricSelector/FabricSelector.hpp"

std::int32_t main(std::uint32_t argc, const char* argv[])
{
	FabricSelector selector{ "ImageProcessors" };
	selector.FindDlls();

	try
	{
		CmdParser parser{ argc, argv };

		const std::string& inFile = parser.GetSourceName() + '.' + parser.GetSourceFormat();
		const std::string& outFile = parser.GetOutput() + '.' + parser.GetGoalFormat();

		ReaderFabric& readerFabric = selector.GetReaderFabric(parser.GetSourceFormat());
		readerFabric.LoadDll();

		WriterFabric& writerFabric = selector.GetWriterFabric(parser.GetGoalFormat());
		writerFabric.LoadDll();

		FileReader byteReader{ inFile };

		const auto reader = readerFabric.GetReader(byteReader.ReadFile());
		
		const ImageFormat image{ reader->Read() };

		const auto writer = writerFabric.GetWriter(image, outFile);
		writer->Write();
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << std::endl;

		return EXIT_FAILURE;
	}

	std::cout << "The file has been succeessuly converted" << std::endl;

	return EXIT_SUCCESS;
}
