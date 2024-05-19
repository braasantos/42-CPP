#include "phonebook.hpp"

void header(void)
{
	std::cout << "\n";
	 std::cout << 
		"       ▒█▀▀█ ▒█░▒█ ▒█▀▀▀█ ▒█▄░▒█ ▒█▀▀▀ ▒█▀▀█ ▒█▀▀▀█ ▒█▀▀▀█ ▒█░▄▀ \n"
		"       ▒█▄▄█ ▒█▀▀█ ▒█░░▒█ ▒█▒█▒█ ▒█▀▀▀ ▒█▀▀▄ ▒█░░▒█ ▒█░░▒█ ▒█▀▄░ \n"
		"       ▒█░░░ ▒█░▒█ ▒█▄▄▄█ ▒█░░▀█ ▒█▄▄▄ ▒█▄▄█ ▒█▄▄▄█ ▒█▄▄▄█ ▒█░▒█\n" ;
		std::cout << "\n";
		std::cout << "\n";
		std::cout << " 📞 PLEASE TYPE ONE OF THE THE 3 OPTIONS 📞\n";
		std::cout << "1 - 'ADD' to add a new contact to the phonebook\n";
		std::cout << "2 - 'SEARCH' to search a contact on the phonebook\n";
		std::cout << "3 - 'EXIT' self-explanatory\n";
}

int main(void)
{
	system("clear");
	header();
	std::string line;
	Contact contact;
	Phonebook phonebook; // new instance of the phonebook class
	while(std::getline(std::cin, line))
	{
		if (line == "EXIT" || line == "exit")
		{
			std::cout << "Goodbye  ٩(◕‿◕)۶ \n" ;
			break;
		}
		if (line == "ADD" || line == "add")
		{
			system("clear");
			contacts(contact);
			phonebook.add_contact(contact);
			header();
		}
		if (line == "SEARCH" || line == "search")
		{
			system("clear");
			show_phonebook(phonebook);
			header();
		}
	}
}
