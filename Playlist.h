#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#pragma once
#include "Song.h"
#include <algorithm>

# define EPS 0.00001

class Playlist
{
public:
	std::string	getTitle() const;
	std::vector<Song*> getSongs() const;
	void setTitle(std::string _title);
	
	void addSong(const Song& song);
	void print();

private:


	std::string title;
	std::vector<Song*> songs;
};
#endif
