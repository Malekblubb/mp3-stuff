#ifndef MP3FILE_H
#define MP3FILE_H

#include <string>
#include "datafile.h"


namespace MP3_STUFF
{
	namespace MP3File
	{
		enum ID3_Tags
		{
			// offsets, used also a "identifier" for reading tags
			SIG_OFFSET = 0x00,
			TITLE_OFFSET = 0x03,
			ARTIST_OFFSET = 0x21,
			ALBUM_OFFSET = 0x3F,
			YEAR_OFFSET = 0x5D,
			COMM_OFFSET = 0x61,
			GENRE_OFFSET = 0x7F,

			// length of the sections
			SIG_LENGTH = 3,
			TITLE_LENGTH = 30,
			ARTIST_LENGTH = 30,
			ALBUM_LENGTH = 30,
			COMM_LENGTH = 30,
			YEAR_LENGTH = 4,
			GENRE_LENGTH = 1
		};


		std::string ReadID3Tag(const std::string &sFilePath, int iOffset);

		class ID3Writer
		{
			DataFile::DFile m_dataFile;

		public:
			~ID3Writer();
			bool Init(const std::string &sFilePath);
			void SetID3Tag(int iOffset, const std::string &sWriteBuffer);
			bool WriteID3Tags();
		};
	}
}

#endif // MP3FILE_H
