#include "System.h"

System::System()
{
}

System::~System()
{
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
			songs.push_back(curr);
		}
	}
	in.close();
}


void System::addPlaylistToUser(std::string username)
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i].getUsername().compare(username) == 0)
		{
			users[i].addPlaylist(playlists[username]);
		}
	}
}


void System::initRating(std::unordered_map<std::string, std::vector<bool>>& rating)
{
	for (std::unordered_map<std::string, std::vector<bool>>::iterator it=rating.begin(); it!= rating.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			it->second[i] = false;
		}
	}
}

void System::rate(std::string username, int curruserid)
{
	
		if (rating[username][curruserid] == true)
		{
			std::cout << "You already rated this song";
			return;
		}
		else
		{
			rating[username][curruserid] = true;
			std::cout << "You successfuly rated this song";
		}
	
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
	//std::cout << "Successful registration!" << std::endl;
	//p.welcome_text(curr.getUsername());
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
		else
		{
			std::cout << "Unknown command! " << std::endl;
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
	/*
	for (size_t i = 0; i < users.size(); i++)
	{
		users[i].printUser();
	}
	*/
	readSongs();
	/*
	for (size_t i = 0; i < songs.size(); i++)
	{
		songs[i].print();
	}
	*/
	/*
	playlists["Simeon"].addSong(songs[0]);
	playlists["Simeon"].addSong(songs[1]);
	playlists["Simeon"].setTitle("Party hard");
	addPlaylistToUser("Simeon");
	users[0].printUser();
	*/
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
		else
		{
			std::cout << "Unknown command! " << std::endl;
		}
	} 
	while (!command.compare("exit")==0);
	
}