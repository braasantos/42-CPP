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
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					av[i][j] -= 32;
				c = av[i][j];
				std::cout << c ;
				j++;
			}
			i++;
		}
	std::cout << "\n" ;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}