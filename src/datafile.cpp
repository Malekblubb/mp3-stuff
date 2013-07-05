#include "datafile.h"


bool MP3_STUFF::DataFile::Reader::Open(const std::string &sFilePath)
{
	m_dataFile.m_FileStream.open(sFilePath.c_str(), std::ios::in | std::ios::binary);

	if(!m_dataFile.m_FileStream.is_open())
		return false;

	m_dataFile.sFilePath = sFilePath;
	m_dataFile.lFileSize = GetSize();

	return true;
}

long MP3_STUFF::DataFile::Reader::GetSize()
{
	m_dataFile.m_FileStream.seekg(0, std::ios::end);
	return m_dataFile.m_FileStream.tellg();
}

void MP3_STUFF::DataFile::Reader::ReadData(long lFrom, long lLength, unsigned char *ucDataBuff)
{
	m_dataFile.m_FileStream.seekg(lFrom);
	m_dataFile.m_FileStream.read(reinterpret_cast<char*>(ucDataBuff), lLength);
}
