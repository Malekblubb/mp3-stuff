#include <iostream>
#include "mp3file.h"

using namespace std;
using namespace MP3_STUFF;


int main()
{
	cout << MP3File::ReadID3Tag("/home/user/test.mp3", MP3File::ARTIST_OFFSET);
}
