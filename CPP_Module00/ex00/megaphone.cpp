#include <iostream>
#include <cctype>

void	print_char(char *str)
{
	while (*str != '\0')
	{
		if (std::isalpha(*str))
			std::cout << (char)std::toupper(*str);
		else
			std::cout << *str;
		str++;
	}
}


int	main(int ac, char **av)
{
	char **args;

	args = &av[1];
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
	while (*args)
	{
		print_char(*args);
		args++;
	}
	std::cout << std::endl;
	return 0;
}
