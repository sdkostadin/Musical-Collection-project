#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#pragma once
#include "Song.h"
#include <algorithm>

# define EPS 0.00001

class Playlist
{
public:
	Playlist();
	std::string	getTitle() const;
	std::vector<Song*> getSongs() const;
	void setTitle(std::string _title);
	
	//Adds song to playlist.
	void addSong(const Song& song);

	//Prints playlist's songs.
	void print();

	//Sorts songs in playlist by their names.
	void sort();

private:


	std::string title;
	std::vector<Song*> songs;
};
#endif
