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
			GENRE_OFFSET = 0x7F
		};


		std::string ReadID3Tag(const std::string sFilePath, int iOffset);
	}
}

#endif // MP3FILE_H
