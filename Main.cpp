#include <iostream>

#include "Tools/CmdParser/CmdParser.hpp"
#include "Tools/FileReader/FileReader.hpp"

#include "Fabrics/Base/ReaderFabric.hpp"
#include "Fabrics/Base/WriterFabric.hpp"

std::int32_t main(int argc, const char* argv[])
{
	try
	{
		FileReader byteReader{ "file.ppm" };

		ReaderFabric readerFabric{ "ImageProcessors/Reader.PPM.dll" };
		readerFabric.LoadDll();

		const auto reader = readerFabric.GetReader(byteReader.ReadFile());
		
		const ImageFormat image{ reader->Read() };

		WriterFabric writerFabric{ "ImageProcessors/Writer.PPM.dll" };
		writerFabric.LoadDll();

		const auto writer = writerFabric.GetWriter(image, "new_file.ppm");
		writer->Write();
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << std::endl;
	}

	return 0;
}
