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
	virtual ~Song();
	
	virtual std::string getName()const;
	virtual std::string getArtist()const;
	virtual std::string getGenre()const;
	virtual std::string getAlbum()const;
	virtual int getYear() const;
	virtual int getCountPeopleRated() const;
	virtual double getRating() const;
	
	virtual void setName(std::string _name);
	virtual void setArtist(std::string _artist);
	virtual void setGenre(std::string _genre);
	virtual void setAlbum(std::string _album);
	virtual void setYear(int _year);
	virtual void setRating(double _rating);
	virtual void setRatingFile(double _rating);
	bool operator<(const Song& other) const;
	
	//Prints song's information.
	virtual void print();


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
