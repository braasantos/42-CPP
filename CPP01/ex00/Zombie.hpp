#ifndef ZOMBIE_CPP
#define ZOMBIE_CPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie( void );
    void announce( void );
};
#endif