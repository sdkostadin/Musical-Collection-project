#ifndef SYSTEM_H_
#define SYSTEM_H_
#pragma once
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "Print.h"
#include "Playlist.h"
#include "User.h"

class System
{
public:
	System();
	~System();
	static System& i();
	System(const System&) = delete;
	void operator =(const System&) = delete;
	
	void dateConvert(std::string text, Date& date);
	void readUsers();
	void readSongs();
	void save();
	void initRating();
	void init();
	void rate( int currid);
	void addSong();
	void showPlaylist(int currid);
	void showUsers();
	void functions(Print p, int currid);
	bool login(Print p, int& currid);
	bool signin(Print p, int& currid);
	void run();
private:
	std::string filename;
	std::vector<User> users;
	std::vector<Song> songs;
	std::unordered_map<std::string, std::vector<bool>> rating;

};
#endif
