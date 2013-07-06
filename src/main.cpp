#include <cstring>
#include <iostream>
#include "mp3file.h"

using namespace std;
using namespace MP3_STUFF;


bool ParseArgs(int argc, char *argv[]);
void PrintHelp();

int main(int argc, char *argv[])
{
	if(!ParseArgs(argc, argv))
		PrintHelp();
}

bool ParseArgs(int argc, char *argv[])
{
	if(argc == 1)
		return false;

	if(argv[1][0] == '-') // first arg must be filepath
		return false;


	MP3File::ID3Writer id3Writer;
	id3Writer.Init(argv[1]);


	for(int i = 1; i < argc; i++)
	{
		if((string)argv[i] == "--title")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << "Title: " << MP3File::ReadID3Tag(argv[1], MP3File::TITLE_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::TITLE_OFFSET, argv[i+1]);

			}
			else
				cout << "Title: " << MP3File::ReadID3Tag(argv[1], MP3File::TITLE_OFFSET) << endl;
		}

		else if((string)argv[i] == "--artist")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::ARTIST_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::ARTIST_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::ARTIST_OFFSET) << endl;
		}

		else if((string)argv[i] == "--album")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::ALBUM_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::ALBUM_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::ALBUM_OFFSET) << endl;
		}

		else if((string)argv[i] == "--artist")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::ARTIST_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::ARTIST_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::ARTIST_OFFSET) << endl;
		}

		else if((string)argv[i] == "--comment")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::COMM_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::COMM_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::COMM_OFFSET) << endl;
		}

		else if((string)argv[i] == "--year")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::YEAR_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::YEAR_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::YEAR_OFFSET) << endl;
		}


		else if((string)argv[i] == "--genre")
		{
			if(i != argc - 1) // check if last arg
			{
				if((argv[i+1][0] == '-')) // only print requested tag
					cout << MP3File::ReadID3Tag(argv[1], MP3File::GENRE_OFFSET) << endl;

				else // edit tag
					id3Writer.SetID3Tag(MP3File::GENRE_OFFSET, argv[i+1]);

			}
			else
				cout << MP3File::ReadID3Tag(argv[1], MP3File::GENRE_OFFSET) << endl;
		}
	}

	id3Writer.WriteID3Tags();
	return true;
}

void PrintHelp()
{
	cout << "Usage: mp3-stuff <path/to/file> <options>" << endl;
	cout << "E.g. mp3-stuff ./my_file.mp3 --title \"New Title\" --artist \"New Artist\"" << endl << endl << endl;

	cout << "Options:" << endl << endl;

	cout << "Main options:" << endl;
	cout << "--all\t\tPrint all (ID3 and file) information." << endl;
	cout << "--help\t\tPrint this help." << endl << endl;

	cout << "ID3 Tag options:"<< endl;
	cout << "--title\t\tPrint or edit the title of the given file." << endl;
	cout << "--artist\tPrint or edit the artist of the given file." << endl;
	cout << "--album\t\tPrint or edit the album of the given file." << endl;
	cout << "--comment\tPrint or edit the comment of the given file." << endl;
	cout << "--year\t\tPrint or edit the year of the given file." << endl;
	cout << "--genre\t\tPrint or edit the genre of the given file." << endl;
}
