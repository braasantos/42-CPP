#include "phonebook.hpp"

void set_firstname(Contact& contact)
{
	std::string name;
	std::getline(std::cin, name);
	contact.set_first(name);
}
void set_lastname(Contact& contact)
{
	std::string name;
	std::getline(std::cin, name);
	contact.set_last(name);
}
void set_nickname(Contact& contact)
{
	std::string name;
	std::getline(std::cin, name);
	contact.set_nick(name);
}

int check_number(std::string input)
{
	for(size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return 1;
	}
	return (0);
}
void set_phonenumber(Contact& contact)
{
	std::string number;
	while(1)
	{
		std::getline(std::cin, number);
		if (check_number(number))
			std::cout << "Please enter a valid number.\n";
		else
		{
			contact.set_phone(number);
			break;
		}
	}
}
void set_darkestsecret(Contact& contact)
{
	std::string name;
	std::getline(std::cin, name);
	contact.set_daskest(name);
}

void contacts(Contact& contact)
{
	std::cout << "- Type the info of the contact please\n";
	std::cout << "- First Name: \n";
	set_firstname(contact);
	std::cout << "- Last Name:\n";
	set_lastname(contact);
	std::cout << "- Nickname:\n";
	set_nickname(contact);
	std::cout << "- Phone Number:\n";
	set_phonenumber(contact);
	std::cout << "- Darkest Secret: \n";
	set_darkestsecret(contact);
	std::cout << "- Done adding everything, Well done ( ˶˘ ³˘(˵ ͡° ͜ʖ ͡°˵)♡ \n";
}

int display_contacts(Phonebook& phone, int index)
{
	Contact& contact = phone.get_contact(index);
	std::cout << "First Name:     " << contact.get_firstname() << "\n";
	std::cout << "Last Name:      " << contact.get_lastname() << "\n";
	std::cout << "Nick Name:      " << contact.get_nickname() << "\n";
	std::cout << "Phone Number:   " << contact.get_phonenumber() << "\n";
	std::cout << "Darkest secret: " << contact.get_darkest() << "\n";
	return 1;
}