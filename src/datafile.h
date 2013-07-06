#ifndef DATAFILE_H
#define DATAFILE_H

#include <fstream>


namespace MP3_STUFF
{
	namespace DataFile
	{
		struct DFile
		{
			std::ifstream m_FileStream;
			std::string sFilePath;
			long lFileSize;
			unsigned char *ucData;
		};

		class Reader
		{
		public:
			bool Open(const std::string &sFilePath);
			long GetSize();
			void ReadData(long lFrom, long lLength, unsigned char *ucDataBuff);
			void Close();

			DFile m_dataFile;
		};

		class Writer
		{
			std::ofstream m_writeStream;

		public:
			bool Open(const std::string &sFilePath);
			void WriteData(long lFrom, long lLength, unsigned char *ucData);
			void Close();
		};
	}
}

#endif // DATAFILE_H
