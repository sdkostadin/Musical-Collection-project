#include "Song.h"

Song::Song() : name(""), artist(""), genre(""), album(""), year(0), rating(0), countPeopleRated(0)
{
}

std::string Song::getName() const
{
	return name;
}

std::string Song::getArtist() const
{
	return artist;
}

std::string Song::getGenre() const
{
	return genre;
}

std::string Song::getAlbum() const
{
	return album;
}

int Song::getYear() const
{
	return year;
}

int Song::getCountPeopleRated() const
{
	return countPeopleRated;
}

double Song::getRating() const
{
	return rating;
}

void Song::setName(std::string _name)
{
	name = _name;
}

void Song::setArtist(std::string _artist)
{
	artist = _artist;
}

void Song::setGenre(std::string _genre)
{
	genre = _genre;
}

void Song::setAlbum(std::string _album)
{
	album = _album;
}

void Song::setYear(int _year)
{
	year = _year;
}

void Song::setRating(double _rating)
{
	rating *= countPeopleRated;
	rating += _rating;
	countPeopleRated++;
	rating /= countPeopleRated;
}

void Song::setRatingFile(double _rating)
{
	rating =  _rating;
}

bool Song::operator<(const Song& other) const
{
	return this->name <= other.name;
}

void Song::print()
{
	std::cout<< "........................................."<<std::endl;
	std::cout << "Song name:" << name << std::endl;
	std::cout << "Song artist:" << artist << std::endl;
	std::cout << "Song genre:" << genre << std::endl;
	std::cout << "Song album:" << album << std::endl;
	std::cout << "Release year:" << year << std::endl;
	std::cout << "Song rating:" << rating << std::endl;
	std::cout <<"........................................." << std::endl;
}
