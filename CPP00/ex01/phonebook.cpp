#include "phonebook.hpp"

void phonebook_header(Phonebook& phonebook)
{
	while (1)
	{
		int index;
		std::cout << "\n";
		std::cout << "-Please choose an index to see the full info ＼(｀0´)／\n";
		std::cin >> index;
		if (index > phonebook.get_ncontacts() - 1)
		{
			std::cout << "Not a valid index. \n";
			std::cout << "( ͡ಥ ͜ʖ ͡ಥ)\n";
			std::cout << "Please try a number between 0 and " << phonebook.get_ncontacts() - 1 << "\n";
			continue;
		}
		if (index >= 0 && index <= phonebook.get_ncontacts())
		{
			if (index == 0)
				if (display_contacts(phonebook, index))
					break;
			if (index == 1)
				if (display_contacts(phonebook, index))
					break;
			if (index == 2)
				if (display_contacts(phonebook, index))
					break;
			if (index == 3)
				if (display_contacts(phonebook, index))
					break;
			if (index == 4)
				if (display_contacts(phonebook, index))
					break;
			if (index == 5)
				if (display_contacts(phonebook, index))
					break;
			if (index == 6)
				if (display_contacts(phonebook, index))
					break;
			if (index == 7)
				if (display_contacts(phonebook, index))
					break;
		}
	}
}

std::string truncate_string(const std::string& str, size_t width)
{
	if (str.length() <= width)
		return str;
	else
		return str.substr(0, width - 1) + ".";
}

void show_phonebook(Phonebook& phone)
{
	int n_contacts = phone.get_ncontacts();
	if (n_contacts == 0)
	{
		std::cout << "You have no contacts at the moment (⋟﹏⋞) \n";
		return;
	}
	std::cout << "Your contacts:\n";
	std::cout << "|" << std::setw(10) << "Index|" << std::setw(10) << " First Name|" << std::setw(10) << " Last Name|" << std::setw(10) << "  Nickname|\n";
	for (int i = 0; i < n_contacts; ++i)
	{
		Contact& contact = phone.get_contact(i);
		std::cout << "|" << std::setw(9) << i << "| ";
		std::cout << std::setw(10) << truncate_string(contact.get_firstname(), 10) << "|";
		std::cout << std::setw(10) << truncate_string(contact.get_lastname(), 10) << "|";
		std::cout << std::setw(10) << truncate_string(contact.get_nickname(), 10) << "|\n";
	}
	phonebook_header(phone);
}