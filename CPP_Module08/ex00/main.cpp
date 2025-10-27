#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {

    std::vector<int> vectr;
    int i = 0;
    while (i < 5) {
        vectr.push_back(i * 9);
        i++;
    }
    std::cout << "What contain vectr :" << std::endl;
    i = 0;
    while (i < (int)vectr.size()) {
        std::cout << vectr[i];
        if (i != (int)vectr.size() - 1)
            std::cout << ", ";
        i++;
    }
    std::cout << "\n" << std::endl;
    try {
        std::vector<int>::iterator iter = easyfind(vectr, 18);
        std::cout << "Found in vectr : " << *iter << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::list<int> elements_list;
    elements_list.push_back(9);
    elements_list.push_back(18);
    elements_list.push_back(27);

    std::cout << "What contain the list :" << std::endl;
    std::list<int>::iterator iter = elements_list.begin();
    while (iter != elements_list.end()) {
        std::cout << *iter;
        if (iter != --elements_list.end())
            std::cout << ", ";
        ++iter;
    }
    std::cout << std::endl;
    try {
        std::list<int>::iterator iterList = easyfind(elements_list, 19);
        std::cout << "Found in elements_list : " << *iterList << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}