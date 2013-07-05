#include "mp3file.h"
#include <cstdlib>
#include <iostream>

using namespace MP3_STUFF;


std::string MP3_STUFF::MP3File::ReadID3Tag(const std::string sFilePath, int iOffset)
{
	int iReadLength = 0;
	unsigned char *ucTmpData;
	std::string sTmpString;
	DataFile::Reader dataFileReader;


	switch(iOffset)
	{
		case SIG_OFFSET: iReadLength = 3;
			break;
		case TITLE_OFFSET:
		case ARTIST_OFFSET:
		case ALBUM_OFFSET:
		case COMM_OFFSET: iReadLength = 30;
			break;
		case YEAR_OFFSET: iReadLength = 4;
			break;
		case GENRE_OFFSET: iReadLength = 1;
			break;
	}

	// alloc mem
	ucTmpData = (unsigned char*)std::malloc(iReadLength);
	dataFileReader.Open(sFilePath);
	dataFileReader.ReadData((dataFileReader.m_dataFile.lFileSize - 128) + iOffset, iReadLength, ucTmpData);

	// store data in string
	for(int i = 0; i < iReadLength; i++)
	{
		if((int)ucTmpData[i] == 0x00)
			break; // break if current byte is 0 -> section end

		sTmpString += ucTmpData[i];
	}

	std::free(ucTmpData);
	return sTmpString;
}
