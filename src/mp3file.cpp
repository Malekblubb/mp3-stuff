#include "mp3file.h"
#include <cstdlib>
#include <iostream>

using namespace MP3_STUFF;


std::string MP3_STUFF::MP3File::ReadID3Tag(const std::string &sFilePath, int iOffset)
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
	dataFileReader.Close();
	return sTmpString;
}

bool MP3_STUFF::MP3File::ID3Writer::Init(const std::string &sFilePath)
{
	DataFile::Reader dataFileReader;

	m_dataFile.sFilePath = sFilePath;

	// open file
	if(!dataFileReader.Open(sFilePath))
		return false;

	// alloc mem
	m_dataFile.ucData = (unsigned char *)std::malloc(dataFileReader.m_dataFile.lFileSize);

	// read whole file to buffer
	dataFileReader.ReadData(0, dataFileReader.m_dataFile.lFileSize, m_dataFile.ucData);
	m_dataFile.lFileSize = dataFileReader.m_dataFile.lFileSize;

	dataFileReader.Close();
	return true;
}

void MP3_STUFF::MP3File::ID3Writer::SetID3Tag(int iOffset, const std::string &sWriteBuffer)
{
	int iReadLength = 0;
	int iTmpOffset = 0;

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

	iTmpOffset = (m_dataFile.lFileSize - 128) + iOffset;

	// clear requested tag field
	for(int i = iTmpOffset ; i < iTmpOffset + iReadLength; i++)
		m_dataFile.ucData[i] = 0;


	// fill with data
	for(int i = iTmpOffset; i < iTmpOffset + iReadLength; i++)
	{
		if((int)sWriteBuffer[i - iTmpOffset] != 0)
			m_dataFile.ucData[i] = sWriteBuffer[i - iTmpOffset];
		else
			break;
	}
}

bool MP3_STUFF::MP3File::ID3Writer::WriteID3Tags()
{
	DataFile::Writer dataFileWriter;

	if(!dataFileWriter.Open(m_dataFile.sFilePath))
			return false;


	dataFileWriter.WriteData(0, m_dataFile.lFileSize, m_dataFile.ucData);
	dataFileWriter.Close();

	return true;
}

MP3_STUFF::MP3File::ID3Writer::~ID3Writer()
{
	std::free(m_dataFile.ucData);
}
