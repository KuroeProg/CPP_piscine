#include "MutantStack.hpp"
# include <string>
# include <iostream>
# include <list>

int     main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::list<int> nbrList;
    nbrList.push_back(5);
    nbrList.push_back(17);
    std::cout << nbrList.back() << std::endl;
    nbrList.pop_back();
    std::cout << nbrList.size() << std::endl;
    nbrList.push_back(3);
    nbrList.push_back(5);
    nbrList.push_back(737);
    nbrList.push_back(0);
    std::list<int>::iterator list_it = nbrList.begin();
    std::list<int>::iterator list_ite = nbrList.end();
    ++list_it;
    --list_it;
    while (list_it != list_ite)
    {
        std::cout << *list_it << std::endl;
        ++list_it;
    }

    return 0;
}