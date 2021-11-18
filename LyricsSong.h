#ifndef LYRICSSONG_H_
#define LYRICSSONG_H_
#pragma once
#include "Song.h"
class LyricsSong : public Song
{
public:
	LyricsSong();

	virtual std::string getLyrics()const;
	virtual std::string getLyricsWriterName() const;
	virtual void setLyrics(std::string _lyrics);
	virtual void setLyricsWriterName(std::string name);
	virtual void print() override;

private:

	std::string lyrics;
	std::string lyricsWriterName;
};
#endif
