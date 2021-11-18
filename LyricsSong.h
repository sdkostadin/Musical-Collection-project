#ifndef LYRICSSONG_H_
#define LYRICSSONG_H_
#pragma once
#include "Song.h"
class LyricsSong : public Song
{
public:
	LyricsSong();

	std::string getLyrics()const;
	std::string getLyricsWriterName() const;
	void setLyrics(std::string _lyrics);
	void setLyricsWriterName(std::string name);
	virtual void print() override;

private:

	std::string lyrics;
	std::string lyricsWriterName;
};
#endif
