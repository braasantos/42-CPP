#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <limits>
# include <cctype>
# include <iomanip>

// by default classes start private
class Contact 
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;
public:
	std::string get_firstname(void)
	{
		return firstname;
	}
    std::string get_lastname(void)
    {
        return lastname;
    }
    std::string get_nickname(void)
    {
        return nickname;
    }
    std::string get_phonenumber(void)
    {
        return phonenumber;
    }
    std::string get_darkest(void)
    {
        return darkestsecret;
    }
    void set_first(std::string input)
    {
        firstname = input;
    }
    void set_last(std::string input)
    {
        lastname = input;
    }
    void set_nick(std::string input)
    {
        nickname = input;
    }
    void set_phone(std::string input)
    {
        phonenumber = input;
    }
    void set_daskest(std::string input)
    {
        darkestsecret = input;
    }
};

class Phonebook
{
private:
	Contact contacts[8];
	int n_contacts;
public:
	Phonebook() : n_contacts(0) {}
    int get_ncontacts()
    {
        return n_contacts;
    }
    void add_contact(Contact& new_contact)
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

    Contact& get_contact(int index)
    {
        // if (index >= 0 && index < n_contacts)
        return contacts[index];
    }
};


//
//
//
// phonebook.cpp
//
//
//
void phonebook_header(Phonebook& phonebook);
std::string truncate_string(const std::string& str, size_t width);
void show_phonebook(Phonebook& phone);
//
//
//
// contacts.cpp
//
//
//
void set_firstname(Contact& contact);
void set_lastname(Contact& contact);
void set_nickname(Contact& contact);
int check_number(std::string input);
void set_phonenumber(Contact& contact);
void set_darkestsecret(Contact& contact);
void contacts(Contact& contact);
int    display_contacts(Phonebook& phone, int index);
#endif