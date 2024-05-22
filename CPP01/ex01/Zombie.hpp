#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
private :
    int N;
    std::string name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    int get_n( void );
    std::string get_name( void );
    void set_n(int input);
    void set_name(std::string input);
    void announce(void);
};
#endif