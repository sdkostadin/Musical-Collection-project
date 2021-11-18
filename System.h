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
	
	//Converts string to date.
	void dateConvert(std::string text, Date& date);

	//Reads users from file.
	void readUsers();

	//Reads songs from file.
	void readSongs();

	//Saves new information to files.
	void save();

	//Adds new user for every song in the rating table.
	void init();

	//Allows person to rate song.
	void rate( int currid);

	//Adds new song to the collection.
	void addSong();

	//Prints all playlists.
	void showPlaylist(int currid);

	//Shows if song is released before or after given year.
	bool BeforeAfterYear(Song song, int year, std::string beforaf);

	//Shows if song is from persons favourite genres.
	bool FromFav(Song song, int currid);

	//Shows if song rating is more than given number.
	bool Rating(Song song, double rating);

	//Shows if song genre is the given genre
	bool OnlyGenre(Song song, std::string genre);

	//Fill table with every song specifies from the criteries.
	void criterion1(int n, std::unordered_map<int, std::vector<bool>>& c, int currid);

	//Generates playlist.
	void generatePlaylist(Print p, int currid);

	//Prints all users.
	void showUsers();

	//List of commands and function every user can do afterlog in or sign in.
	void functions(Print p, int currid);

	//Allows user to log in.
	bool login(Print p, int& currid);

	//Allows user to sign in.
	bool signin(Print p, int& currid);

	//Runs the program.
	void run();
private:
	std::string filename;
	std::vector<User> users;
	std::vector<Song> songs;

	//Table which shows for every song which user already voted.
	//At the beggining table is full of '0' because nobody voted yet.
	std::unordered_map<std::string, std::vector<bool>> rating;

};
#endif
