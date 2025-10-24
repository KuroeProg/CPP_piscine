#include "Iter.hpp"
#include <iostream>


void lowerLetter(char &letter) {
    letter = std::tolower(static_cast<unsigned char>(letter));
}

void upperLetter(char &letter) {
    letter = std::toupper(static_cast<unsigned char>(letter));
}

void putChar(char const &c) {
    std::cout << c;
}

int main() {
    char tab[] = "CecI est Une pHRaSe";
    const char ctab[] = "Ceci est uNE coNSt pHrasE";

    std::cout << "Phrase de base: ";
    std::cout << std::endl;
    iter(tab, 20, putChar);
    std::cout << std::endl;

    iter(tab, 20, lowerLetter);
    std::cout << "Phrase en minuscule: ";
    std::cout << std::endl;
    iter(tab, 20, putChar);
    std::cout << std::endl;

    iter(tab, 20, upperLetter);
    std::cout << "Phrase en MAJUSCULE: ";
    std::cout << std::endl;
    iter(tab, 20, putChar);
    std::cout << std::endl;

    std::cout << "Tab en const, car Askip je dois le gerer: ";
    std::cout << std::endl;
    iter(ctab, 26, putChar);
    std::cout << std::endl;

    return 0;
}