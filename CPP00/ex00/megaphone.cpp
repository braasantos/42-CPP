#include <iostream>

int main(int ac, char **av)
{
	int i;
	int j;
	char c;

	if (ac > 1)
	{
		i = 1;
		while (av[i])
		{
			j = 0;
			while(av[i][j])
			{
				c = av[i][j];
				if (c >= 'a' && c <= 'z')
					c -= 32;
				std::cout << c ;
				j++;
			}
			if (i != ac - 1)
				std::cout << ' ';
			i++;
		}
	std::cout << "\n" ;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}