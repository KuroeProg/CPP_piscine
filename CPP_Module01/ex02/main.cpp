#include <iostream>

int	main(void) {
	std::string brain = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address of the string variable :" << &brain << std::endl;
	std::cout << "Memory address held by stringPTR :" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF :" << &stringREF << std::endl;

	std::cout << "Value of the string :" << brain << std::endl;
	std::cout << "Value pointed by stringPTR :" << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF :" << stringREF << std::endl;

	return 0;
}
