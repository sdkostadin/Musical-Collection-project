#ifndef SONG_H_
#define SONG_H_
#include <iostream>
#include <string>
#include <vector>
#pragma once
class Song
{
public:

	Song();
	std::string getName()const;
	std::string getArtist()const;
	std::string getGenre()const;
	std::string getAlbum()const;
	int getYear() const;
	int getCountPeopleRated() const;
	double getRating() const;
	
	void setName(std::string _name);
	void setArtist(std::string _artist);
	void setGenre(std::string _genre);
	void setAlbum(std::string _album);
	void setYear(int _year);
	void setRating(double _rating);
	bool operator<(const Song& other) const;
	void print();


private:
	
	std::string name;
	std::string artist;
	std::string genre;
	std::string album;
	int year;
	double rating;
	int countPeopleRated;

	
};
#endif
