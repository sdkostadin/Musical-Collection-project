#include "Print.h"

void Print::print_start_menu()
{
	std::cout << "................................................................" << std::endl;
	std::cout << std::endl;
	std::cout << ".............." << " WELCOME TO YOUR MUSIC COLLECTION APP! " << "............." << std::endl;
	std::cout << std::endl;
	std::cout << ".........................................................." << std::endl;
	std::cout << std::endl;
	std::cout << "   " << "YOU CAN REGISTER IN OUR SYSTEM BY TYPING 'sign up'" << "   "
		<< std::endl << "   " << "   FOR ALREADY REGISTERED ACCOUNTS USE 'sign in'" << "     " << std::endl;
	std::cout << "           TO SEE SUPPORTED COMMANDS TYPE 'help' " << std::endl;
	std::cout << std::endl;
	std::cout << "................................................................." << std::endl;
	std::cout << std::endl;
}
void Print::print_help_command()
{
	std::cout << "........................   List of all supported commands   ........................" << std::endl;
	std::cout << std::endl;
	std::cout << "- sign in - Makes a new registration in the system." << std::endl;
	std::cout << "- log in - Signs in the system with already made registration." << std::endl;
	std::cout << "- show users - Shows a list with information for all users." << std::endl;
	std::cout << "- show collection - Shows a list with information for all songs in collection." << std::endl;
	std::cout << "- help - Shows a list with supported commands." << std::endl;
	std::cout << "- exit - Closing files and exiting program." << std::endl;
	std::cout << std::endl;
	std::cout << "........................   Once you've logged in you can   ........................" << std::endl;
	std::cout << std::endl;
	std::cout << "- add genres - Adds genres to User's favourites." << std::endl;
	std::cout << "- remove genre - Removes a genre from User's favourites. " << std::endl;
	std::cout << "- show playlist - Shows information for all songs in a playlist. " << std::endl;
	std::cout << "- generate playlist -  Generates new playlist by criteria. " << std::endl;
	std::cout << "- add song -  Adds a song in mucis collection. " << std::endl;
	std::cout << "- rate song - Allows user to set rating. (User can rate a song once)" << std::endl;
	std::cout << "- sign out - Signs out from account." << std::endl;
	std::cout << std::endl;
	std::cout << "........................................................................" << std::endl;
}
void Print::print_playlist_criterion()
{
	std::cout << "................................................" << std::endl;
	std::cout << "Now you can set criterion! " << std::endl;
	std::cout << "You can choose one of these: " << std::endl;
	std::cout << "1) Before/Ater -year- " << std::endl;
	std::cout << "2) From favourites " << std::endl;
	std::cout << "3) Rating > -rating- " << std::endl;
	std::cout << "4) Only -genre- " << std::endl;
	std::cout << " You can combine criterions. For example: 1 and 2,   2 or 4,  (1 and 2) or 4  ";
	std::cout << std::endl;
	std::cout << "................................................" << std::endl;
	std::cout << "Your criteria:     *Type the number*" << std::endl;
}
void Print::welcome_text(std::string _username)
{
	std::cout << "................................................" << std::endl;
	std::cout << std::endl;
	std::cout << "             Welcome, " << _username << "!" << std::endl;
	std::cout << std::endl;
	std::cout << "................................................" << std::endl;
}
void Print::print_ready_song()
{
	std::cout << "................................................................................................" << std::endl;
	std::cout << std::endl;
	std::cout << "Your song is ready! Successfully added to music collection! To see all songs type (show collection)." << std::endl;
	std::cout << std::endl;
	std::cout << "................................................................................................" << std::endl;
}
void Print::print_collection_start(int _size)
{
	std::cout << "................................................" << std::endl;
	std::cout << std::endl;
	std::cout << "     All songs in collection : " << _size << std::endl;
	std::cout << std::endl;
	std::cout << "................................................" << std::endl;
}
