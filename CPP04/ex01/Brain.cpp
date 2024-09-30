#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain is creating new ideas" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Idea";
}
Brain::~Brain()
{
    std::cout << "Brain is tired" << std::endl;
}
Brain::Brain(const Brain &other)
{
    *this = other;
}
Brain& Brain::operator=(const Brain &otherClass)
{
    if (this != &otherClass)
    {
        for (size_t i = 0; i < 100; i++)
            this->ideas[i] = otherClass.ideas[i];
    }
    return *this;
}

void Brain::newIdea(int index, std::string idea)
{
    ideas[index] = idea;
}
