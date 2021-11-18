#include "LyricsSong.h"

LyricsSong::LyricsSong()
	: lyrics(""),
	lyricsWriterName("")
{
}

std::string LyricsSong::getLyrics() const
{
	return lyrics;
}

std::string LyricsSong::getLyricsWriterName() const
{
	return lyricsWriterName;
}

void LyricsSong::setLyrics(std::string _lyrics)
{
	lyrics = _lyrics;
}

void LyricsSong::setLyricsWriterName(std::string name)
{
	lyricsWriterName = name;
}

void LyricsSong::print()
{
	Song::print();
	std::cout << "Lyrics by: " << lyricsWriterName<< std::endl;
	std::cout << "Lyrics: " << lyrics << std::endl;
}
