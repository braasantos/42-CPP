#include <iostream>

int main(int ac, char **av)
{
	char c;

	if (ac > 1)
	{
		for (int i = 1; av[i]; i++)
		{
			for(int j = 0; av[i][j]; j++)
			{
				c = av[i][j];
				if (c >= 'a' && c <= 'z')
					c -= 32;
				std::cout << c ;
			}
			if (i != ac - 1)
				std::cout << ' ';
		}
		std::cout << "\n" ;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}