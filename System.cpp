#include "System.h"

System::System()
{
}

System::~System()
{
	filename.clear();
}

System& System::i()
{
	static System instance;
	return instance;
}

void System::dateConvert(std::string text, Date& date)
{
	for (size_t i = 0; i < text.length(); i++)
	{
		if (text[i] == '.')
		{
			text[i] = ' ';
		}
	}
	std::vector<int>numbers;
	int number;
	std::istringstream readNums(text);
	while (readNums >> number)
	{
		numbers.push_back(number);
	}
	date.setDay(numbers[0]);
	date.setMonth(numbers[1]);
	date.setYear(numbers[2]);
	
}

void System::readUsers()
{
	User curr;
	char word[32];
	std::string date;
	std::ifstream in;
	in.open("users.txt");
	if (in)
	{
		while (!in.eof())
		{
			in >> word;
			curr.setUsername(word);
			in >> word;
			curr.setPassword(word);
			in.ignore();
			in.getline(word, 100);
			curr.setFullName(word);
			in >> word;
			date = word;
			Date res;
			dateConvert(date, res);
			curr.setBirthDate(res);
			in>> word;
			while (strcmp(word,"#")!=0)
			{
				curr.addGenre(word);
				curr.getGenres().clear();
				in >> word;
			}
			users.push_back(curr);
			curr.clearGenres();
			
		
		}
	}
	in.close();
}

void System::readSongs()
{
	Song curr;
	char word[32];
	std::string date;
	std::ifstream in;
	double rate;
	in.open("songs.txt");
	if (in)
	{
		while (!in.eof())
		{
			in.getline(word, 32);
			curr.setName(word);
			in.getline(word, 32);
			curr.setArtist(word);
			in.getline(word, 32);
			curr.setGenre(word);
			in.getline(word, 32);
			curr.setAlbum(word);
			in.getline(word, 32);
			curr.setYear(std::stoi(word));
			in >> rate;
			curr.setRatingFile(rate);
			in.ignore();
			songs.push_back(curr);
			rating.insert({ curr.getName(), {} });
			for (size_t i = 0; i < users.size(); i++)
			{
				rating[curr.getName()].push_back(0);
			}
			
		}
	}
	in.close();

}

void System::save()
{
	
	std::ofstream out;
	out.open("users.txt");
	for (size_t i = 0; i < users.size(); i++)
	{
		out << users[i].getUsername() << std::endl;
		out << users[i].getPassword() <<" " << users[i].getFullName() << std::endl;
		out << users[i].getDate()<<std::endl;
		for (size_t j = 0; j < users[i].getGenres().size(); j++)
		{
			out << users[i].getGenres()[j] << std::endl;
		}
		if (i < users.size() - 1)
		{
			out << "#"<<std::endl;
		}
		else
		{
			out << "#";
		}
	}
	out.close();
	
	out.open("songs.txt");
	for (size_t i = 0; i < songs.size(); i++)
	{
		out << songs[i].getName() << std::endl;
		out << songs[i].getArtist() << std::endl;
		out << songs[i].getGenre() << std::endl;
		out << songs[i].getAlbum() << std::endl;
		out << songs[i].getYear() << std::endl;
		if (i < songs.size() - 1)
		{
			out << songs[i].getRating()<<std::endl;
		}
		else
		{
			out << songs[i].getRating();
		}

	}
}

void System::init()
{
	
	for (std::unordered_map<std::string, std::vector<bool>>::iterator it = rating.begin(); it != rating.end(); it++)
	{
		
		it->second.push_back(0);
		
	}
}

void System::rate( int currid)
{
	std::string temp;
	double rate;
	std::cout << "Insert song name: ";
	std::getline(std::cin, temp);
	for (size_t i = 0; i < songs.size(); i++)
	{
		if (temp.compare(songs[i].getName()) == 0)
		{
			if (rating[temp][currid] == 1)
			{
				std::cout << "You already rated this song!" << std::endl;
				return ;
			}
			else
			{
				std::cout << "Add rate: ";
				std::cin >> rate;
				rating[temp][currid] = 1;
				songs[i].setRating(rate);
				std::cout << "Rated successfully!" << std::endl;
				return;
			}
		}
	}
	std::cout << "Invalid song name!" << std::endl;
	return ;
	
}

void System::addSong()
{
	Song curr;
	std::string temp;
	std::cout << "Type song name: " << std::endl;
	std::getline(std::cin, temp);
	curr.setName(temp);
	temp.clear();
	std::cout << "Type song artist: " << std::endl;
	std::getline(std::cin, temp);
	curr.setArtist(temp);
	temp.clear();
	for (size_t i = 0; i < songs.size(); i++)
	{
		if (songs[i].getName().compare(curr.getName()) == 0 && songs[i].getArtist().compare(curr.getArtist()) == 0)
		{
			std::cout << "This song is already added! " << std::endl;
			return;
		}
	}
	std::cout << "Type song genre: " << std::endl;
	std::cin >> temp;
	curr.setGenre(temp);
	temp.clear();
	std::cin.ignore();
	std::cout << "Type song album: " << std::endl;
	std::getline(std::cin, temp);
	curr.setAlbum(temp);
	temp.clear();
	std::cout << "Type song release year: " << std::endl;
	int year;
	std::cin >> year;
	curr.setYear(year);
	songs.push_back(curr);
	rating.insert({ curr.getName(), {} });
	for (size_t i = 0; i < users.size(); i++)
	{
		rating[curr.getName()].push_back(0);
	}
	std::cout << "Song " << curr.getName() << " is added successfuly! " << std::endl;
}


void System::showPlaylist(int currid)
{
	std::string temp;
	std::cout << "Type playlist title: " << std::endl;
	std::getline(std::cin, temp);
	for (int i = 0; i < users[currid].getPlaylists().size(); i++)
	{
		if (users[currid].getPlaylists()[i]->getTitle().compare(temp) == 0)
		{
			users[currid].getPlaylists()[i]->print();
			return;
		}
	}
	std::cout << "There is no playlist with that title in your archive!" << std::endl;
}

bool System::BeforeAfterYear(Song song, int year, std::string beforaf)
{
	if (beforaf.compare("after")==0)
	{
		return song.getYear() > year;
	}
	else if (beforaf.compare("before") == 0)
	{
		return song.getYear() < year;
	}
}

bool System::FromFav(Song song, int currid)
{
	for (int i = 0; i < users[currid].getGenres().size(); i++)
	{
		if (song.getGenre().compare(users[currid].getGenres()[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

bool System::Rating(Song song, double rating)
{
	return song.getRating() > rating;
}

bool System::OnlyGenre(Song song, std::string genre)
{
	return genre.compare(song.getGenre()) == 0;
}

void System::criterion1(int n, std::unordered_map<int, std::vector<bool>>& c, int currid)
{
	if (std::to_string(n).compare("1")==0)
	{
		std::string command;
		int year;
		std::cout << "Type year: "<<std::endl;
		std::cin >> year;
		std::cout << "Before or after this year? " << std::endl;
		std::cin.ignore();
		std::getline(std::cin, command);
		for (size_t i = 0; i < songs.size(); i++)
		{
			if (BeforeAfterYear(songs[i], year, command))
			{
				c[1][i]=true;
			}
		}
	}
	else if (std::to_string(n).compare("2")==0)
	{
		for (size_t i = 0; i < songs.size(); i++)
		{
			if (FromFav(songs[i], currid))
			{
				c[2][i] = true;
			}
		}
	}
	else if (std::to_string(n).compare("3")==0)
	{
		double rating;
		std::cout << "Insert minimum rating: " << std::endl;
		std::cin >> rating;
		for (size_t i = 0; i < songs.size(); i++)
		{
			if (Rating(songs[i], rating))
			{
				c[3][i] = true;
			}
		}
	}
	else if (std::to_string(n).compare("4")==0)
	{
		std::string genre;
		std::cout << "Input genre:" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, genre);
		for (size_t i = 0; i < songs.size(); i++)
		{
			if (OnlyGenre(songs[i], genre))
			{
				c[4][i] = true;
			}
		}
	}
}

void System::generatePlaylist(Print p, int currid)
{
	std::string temp;
	std::string combination;
	std::cout << "Type playlist title: " << std::endl;
	std::getline(std::cin, temp);
	Playlist curr;
	curr.setTitle(temp);
	temp.clear();
	p.print_playlist_criterion();
	int n;
	std::cin >> n;
	std::unordered_map<int,std::vector<bool>> c;
	for (int i = 0; i < 4; i++)
	{
		c.insert({ i+1, {} });
		for (size_t j = 0; j < songs.size(); j++)
		{
			c[i+1].push_back(0);
		}
	}
	criterion1(n,c,currid);
	std::vector<std::string> criterion;
	criterion.push_back(std::to_string(n));
	while (temp.compare("no") != 0)
	{
		std::cout << "Do you want to combine? *yes or no*" << std::endl;
		std::cin >> temp;
		if(temp.compare("yes") == 0)
		{
			std::cout << "Insert type of combination:   'or'   or    'and' " << std::endl;
			std::cin >> combination;
			criterion.push_back(combination);
			std::cout << "Your criteria:     *Type the number* " << std::endl;
			std::cin >> n;
			criterion1(n, c, currid);
			criterion.push_back(std::to_string(n));
		}
	}
	int first = std::stoi(criterion[0]);
	std::vector<bool> vec;
	for (int i = 0; i < songs.size(); i++)
	{
		vec.push_back(0);
		vec[i] = c[first][i];
	}

	for (size_t i = 0; i < criterion.size(); i++)
	{
		if (criterion[i].compare("or") == 0)
		{
			int p = stoi(criterion[i + 1]);
			for (int j = 0; j < songs.size(); j++)
			{
				vec[j] = vec[j] || c[p][j];
			}
		}
		else if (criterion[i].compare("and") == 0)
		{
			int p = stoi(criterion[i + 1]);
			for (int j = 0; j < songs.size(); j++)
			{
				vec[j] = vec[j] && c[p][j];
			}
		}
	}
	for (size_t i = 0; i < songs.size(); i++)
	{
		if (vec[i])
		{
			curr.addSong(songs[i]);
		}
	}
	curr.sort();
	users[currid].addPlaylist(curr);
}

void System::showUsers()
{
	for (int i = 0; i < users.size(); i++)
	{
		users[i].printUser();
	}
}

bool System::login(Print p, int& currid)
{
	User curr;
	std::string username;
	std::string password;
	std::cout << "Type your username: " << std::endl;
	std::cin >> username;
	std::cout << "Type your password: " << std::endl;
	std::cin >> password;
	for (size_t i = 0; i < users.size(); i++)
	{
		if ((username.compare(users[i].getUsername()) == 0) && (password.compare(users[i].getPassword()) == 0))
		{
			curr = users[i];
			currid = i;
			return true;
		}
	}
	
	return false;
}

bool System::signin(Print p, int& currid)
{
	User curr;
	std::string temp;
	std::cout << "Type your username: " << std::endl;
	std::cin >> temp;
	curr.setUsername(temp);
	temp.clear();
	std::cout << "Type your password: " << std::endl;
	std::cin >> temp;
	curr.setPassword(temp);
	for (size_t i = 0; i < users.size(); i++)
	{
		if ((curr.getUsername().compare(users[i].getUsername()) == 0) && (curr.getPassword().compare(users[i].getPassword()) == 0))
		{
			return false;
		}
	}
	temp.clear();
	std::cin.ignore();
	std::cout << "Type your full name: " << std::endl;
	std::getline(std::cin, temp);
	curr.setFullName(temp);
	temp.clear();
	std::cout << "Type your birth date:      * for example  12.02.2002 *" << std::endl;
	std::cin >> temp;
	Date bd;
	dateConvert(temp, bd);
	curr.setBirthDate(bd);
	temp.clear();
	std::cin.ignore();
	std::cout << "Type your favourite genres: ' "<<std::endl;
	std::getline(std::cin,temp);
	std::istringstream iss(temp);
	for (std::string s; iss >> s;)
	{
		curr.addGenre(s);
	}
	temp.clear();
	users.push_back(curr);
	init();
	currid = users.size() - 1;
	return true;
}

void System::functions(Print p, int currid)
{
	std::string command;
	std::string temp;
	std::cout << "Insert command: " << std::endl;
	do
	{
		std::getline(std::cin, command);
		if (command.compare("help") == 0)
		{
			p.print_help_command();
		}
		else if (command.compare("add genre") == 0)
		{
			users[currid].printGenres();
			std::cout << "Insert new genres: ";
			std::getline(std::cin, temp);
			std::istringstream iss(temp);
			for (std::string s; iss >> s;)
			{
				users[currid].addGenre(s);
			}
			std::cout << "Genre list modified!" << std::endl;
			temp.clear();
		}
		else if (command.compare("remove genre") == 0)
		{
			users[currid].printGenres();
			std::cout << "Insert genres to remove: ";
			std::getline(std::cin, temp);
			std::istringstream iss(temp);
			for (std::string s; iss >> s;)
			{
				users[currid].removeGenre(s);
			}
			std::cout << "Genre list modified!" << std::endl;
			temp.clear();
		}
		else if (command.compare("rate song") == 0)
		{
			rate(currid);
		}
		else if (command.compare("add song") == 0)
		{
			addSong();
		}
		else if (command.compare("generate playlist") == 0)
		{
			generatePlaylist(p, currid);
		}
		else if (command.compare("show playlist") == 0)
		{
			std::cout << "Input playlist title: " << std::endl;
			std::string title;
			std::getline(std::cin, title);
			for (size_t i = 0; i < users[currid].getPlaylists().size(); i++)
			{
				if (title.compare(users[currid].getPlaylists()[i]->getTitle()) == 0)
				{
					users[currid].getPlaylists()[i]->print();
				}
			}
		}
	} while (!command.compare("sign out") == 0);
	std::cout << "You signed out from user: " << users[currid].getUsername()<<std::endl;
}

void System::run()
{
	
	Print p;
	p.print_start_menu();
	readUsers();
	int currid = 0;
	readSongs();
	std::string command;
	std::cout << "Insert command: " << std::endl;
	do
	{
		std::getline(std::cin,command);
		if (command.compare("help")==0)
		{
			p.print_help_command();
		}
		else if (command.compare("log in")==0)
		{
			if (login(p, currid))
			{
				p.welcome_text(users[currid].getUsername());
				functions(p, currid);
			}
			else
			{
				std::cout << "There is no registered user with this username or password!" << std::endl;
			}
		}
		else if (command.compare("sign in")==0)
		{
			if (signin(p, currid))
			{
				std::cout << "Successful registration!" << std::endl;
				p.welcome_text(users[currid].getUsername());
				functions(p, currid);
			}
			else
			{
				std::cout << "There is already user with this username or password!" << std::endl;
			}
		}
		else if (command.compare("show users") == 0)
		{
			for (size_t i = 0; i < users.size(); i++)
			{
				users[i].printUser();
			}
		}
		else if (command.compare("show collection") == 0)
		{
			for (size_t i = 0; i < songs.size(); i++)
			{
				songs[i].print();
			}
		}
		else 
		{
			if (!command.compare("exit") == 0)
			{
				std::cout << "Unknown command! " << std::endl;
			}
		}
	} 
	while (!command.compare("exit")==0);
	save();
}