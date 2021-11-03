#include "User.h"

User::User() : username("") , password(""), fullname(""), birth_date(0,0,0) 
{
	
}
User::User(const User& other)
{
	copy(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

void User::copy(const User& other)
{
	username = other.username;
	password = other.password;
	fullname = other.fullname;
	birth_date = other.birth_date;
	genres = other.genres;
}

std::string User::getUsername()const
{
	return username;
}

std::string User::getPassword()const
{
	return password;
}

std::string User::getFullName()const
{
	return fullname;
}

std::vector<std::string> User::getGenres() const
{
	return genres;
}

Date User::getDate()const
{
	return birth_date;
}

std::vector<Playlist*> User::getPlaylists() const
{
	return playlists;
}

void User::setUsername(std::string name)
{
	username = name;
}

void User::setPassword(std::string pass)
{
	password = pass;
}

void User::setFullName(std::string name)
{
	fullname = name;
}

void User::setBirthDate(Date date)
{
	birth_date = date;
}

void User::setGenres(std::vector<std::string> _genres)
{
	genres = _genres;
}

void User::addGenre(std::string genre)
{
	for (size_t i = 0; i < genres.size(); i++)
	{
		if (genres[i].compare(genre) == 0)
		{
			//std::cout << "Genre is already added.";
			return ;

		}
	}
	genres.push_back(genre);
	//std::cout << "Genre successfully added.";
	
}

void User::removeGenre(std::string genre)
{
	for (size_t i = 0; i < genre.size(); i++)
	{
		if (genres[i].compare(genre) == 0)
		{
			genres.erase(genres.begin() + i);
			//std::cout << "Genre successfully removed!" << std::endl;
			return;
		}
	}
}

void User::clearGenres()
{
	genres.clear();
}

void User::printGenres()
{
	std::cout << username << " genres: " << std::endl;
	for (size_t i = 0; i < genres.size()-1; i++)
	{
		std::cout << genres[i] << ", ";
	}
	std::cout << genres[genres.size() - 1]<<std::endl;
}

void User::addPlaylist(const Playlist& playlist)
{
	for (size_t i = 0; i < playlists.size(); i++)
	{
		if (playlists[i]->getTitle() == playlist.getTitle())
		{
			std::cout << "There is playlist with that name!";
			return;
		}
	}
	playlists.push_back(new Playlist(playlist));
}

void User::printUser()
{
	std::cout << "................................" << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Password: ";
	for (int i = 0; i < password.length(); i++) 
	{
		std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << "Full name: " << fullname << std::endl;
	std::cout << "Birth date: " << birth_date << std::endl;
	std::cout << "Favourite genres: ";
	if (genres.empty())
	{
		std::cout << "Genres list is empty for this user!" << std::endl;
	}
	else
	{
		printGenres();
		//std::cout << std::endl;
	}
	std::cout << "................................" << std::endl;
	if (playlists.empty())
	{
		std::cout << "This user has no playlists!" << std::endl;
	}
	else
	{
		std::cout << "User " << username << " playlists:" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < playlists.size(); i++)
		{
			playlists[i]->print();
		}
		std::cout << "................................" << std::endl;
		std::cout << std::endl;
	}
}
