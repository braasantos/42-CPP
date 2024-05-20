#include "phonebook.hpp"
#include "contacts.hpp"

int Phonebook::is_digit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

int	Phonebook::not_a_digit(std::string input)
{
	for(int i = 0; input[i]; i++)
	{
		if (!is_digit(input[i]))
			return 0;
	}
	return 1;
}

int	Phonebook::stoi(std::string input)
{
	int	i;
	int	num;
	i = 0;
	num = 0;
	while ((input[i] >= 9 && input[i] <= 13) || (input[i] == 32))
		i++;
	while (isdigit(input[i]))
	{
		num = num * 10 + input[i] - 48;
		i++;
	}
	return (num);
}

Contact& Phonebook::get_contact(int index)
{
    return contacts[index];
}

void Phonebook::add_contact(Contact new_contact)
{
    if (n_contacts < 8)
    {
    	contacts[n_contacts] = new_contact;
        if (n_contacts < 8)
            n_contacts++;
        else
            std::cout << "Phonebook is full. Replacing the last contact.\n";
    }
    else
    {
        contacts[7] = new_contact;
        std::cout << "Contact added successfully by replacing the last one!\n";
    }
}

int Phonebook::get_ncontacts() const
{
    return n_contacts;
}

void Phonebook::utils(void)
{
	std::cout << "Not a valid index. \n";
	std::cout << "( ͡ಥ ͜ʖ ͡ಥ)\n";
	std::cout << "Please try a number between 0 and " << get_ncontacts() - 1 << "\n";
}

int Phonebook::newheader(void)
{
	std::string line;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "If you want to go back to Main \n";
	std::cout << "Please type 'BACK' or 'back' \n";
	std::cout << "Or please press 'ENTER' to choose a new index to see another contact\n";
	std::getline(std::cin, line);
	if (line == "BACK" || line == "back")
		return 1;
	return 0;
}
void Phonebook::phonebook_header(void)
{
	while (1)
	{
		int index;
		std::string line;
		std::cout << "\n";
		std::cout << "-Please choose an index to see the full info ＼(｀0´)／\n";
		std::getline(std::cin, line);
		index = stoi(line);
		if(!not_a_digit(line))
		{
			utils();
			continue;
		}
		if (index > get_ncontacts() - 1)
		{
			utils();
			continue;
		}
		if (index >= 0 && index <= get_ncontacts())
		{
			if (display_contacts(index))
				if (newheader())
					break ;
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

void Phonebook::show_phonebook(void)
{
	int n_contacts = get_ncontacts();
	if (n_contacts == 0)
	{
		std::cout << "You have no contacts at the moment (⋟﹏⋞) \n";
		return;
	}
	std::cout << "Your contacts:\n";
	std::cout << "|" << std::setw(10) << "Index|" << std::setw(10) << " First Name|" << std::setw(10) << " Last Name|" << std::setw(10) << "  Nickname|\n";
	for (int i = 0; i < n_contacts; ++i)
	{
		Contact& contact = get_contact(i);
		std::cout << "|" << std::setw(9) << i << "| ";
		std::cout << std::setw(10) << truncate_string(contact.get_firstname(), 10) << "|";
		std::cout << std::setw(10) << truncate_string(contact.get_lastname(), 10) << "|";
		std::cout << std::setw(10) << truncate_string(contact.get_nickname(), 10) << "|\n";
	}
	phonebook_header();
}