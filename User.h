#ifndef USER_H_
#define USER_H_

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Playlist.h"
class User
{

public:
	User();
	User(const User& other);
	User& operator=(const User& other);

	std::string getUsername() const;
	std::string getPassword() const;
	std::string getFullName() const;
	std::vector<std::string> getGenres() const;
	Date getDate() const;
	std::vector<Playlist*> getPlaylists() const;

	void setUsername(std::string name);
	void setPassword(std::string pass);
	void setFullName(std::string name);
	void setBirthDate(Date date);
	void setGenres(std::vector<std::string> _genres);

	void addGenre(std::string genre);
	void removeGenre(std::string genre);
	void clearGenres();
	void printGenres();
	void addPlaylist(const Playlist& playlist );
	void printUser();

private:

	std::string username;
	std::string password;
	std::string fullname;
	Date birth_date;
	std::vector<std::string> genres;
	std::vector<Playlist*> playlists;


	void copy(const User& other);


};

#endif