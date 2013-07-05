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
		};

		class Reader
		{
		public:
			bool Open(const std::string &sFilePath);
			long GetSize();
			void ReadData(long lFrom, long lLength, unsigned char *ucDataBuff);

			DFile m_dataFile;
		};
	}
}

#endif // DATAFILE_H
