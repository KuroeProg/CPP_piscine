/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:33:17 by cfiachet          #+#    #+#             */
/*   Updated: 2025/08/12 12:33:17 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void    CopyAndReplace(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream	infile(filename.c_str());
	std::string		line;
	std::ofstream	outfile((filename + ".replace").c_str());
	
	if (!infile) {
		std::cerr << "Unable to open the input file" << std::endl;
		return ;
	}
	if (!outfile) {
		std::cerr << "Unable to create the output file" << std::endl;
		infile.close();
		return ;
	}
	while (std::getline(infile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}


int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Wrong usage : " << av[0] << "[filename] [first string] [second string]" << std::endl;
		return (1);
	}
	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cerr << filename << " does not exist" << std::endl;
		return (1);
	}
	infile.close();

	CopyAndReplace(filename, s1, s2);
	return (0);

}