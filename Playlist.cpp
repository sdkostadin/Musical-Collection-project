#include "Playlist.h"
#include "Playlist.h"

std::string Playlist::getTitle() const
{
	return title;
}

std::vector<Song*> Playlist::getSongs() const
{
	return songs;
}

void Playlist::setTitle(std::string _title)
{
	title = _title;
}

void Playlist::addSong(const Song& song)
{
	for (size_t i = 0; i < songs.size(); i++)
	{
		if (song.getName() == songs[i]->getName() &&
			song.getArtist() == songs[i]->getArtist() &&
			song.getGenre() == songs[i]->getGenre() &&
			song.getAlbum() == songs[i]->getAlbum() &&
			song.getYear() == songs[i]->getYear() &&
			abs(song.getRating() - songs[i]->getRating())< EPS)
		{
			std::cout << "This song is already in the playlist." << std::endl;
			return ;
		}
	}

		songs.push_back(new Song(song));
		std::sort(songs.begin(), songs.end(), [](Song* a, Song* b) {return a->getName() > b->getName(); });
		std::cout << "Successfully added song!" << std::endl;
		


}

void Playlist::print()
{
	std::cout << "...........Playlist: " << title << " ............"<<std::endl;
	for (size_t i = 0; i < songs.size(); i++)
	{
		songs[i]->print();
	}
}





