#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void    identify(Base *base_ptr) {
    if (dynamic_cast<A*>(base_ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(base_ptr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(base_ptr))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknow type" << std::endl;
}

void    identify(Base &base_ref) {
    try {
        (void)dynamic_cast<A&>(base_ref);
        std::cout << "A" << std::endl;
        return ;
    } catch (std::exception&) {}

    try {
        (void)dynamic_cast<B&>(base_ref);
        std::cout << "B" << std::endl;
        return ;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(base_ref);
        std::cout << "C" << std::endl;
        return ;
    } catch (std::exception&) {}
}

Base *generate(void) {
    std::srand(std::time(NULL));
    int random_number = std::rand() % 3;

    switch (random_number) {
        case 0:
            std::cout << "A will be Generated" << std::endl;
            return new A;
        case 1:
            std::cout << "B will be Generated" << std::endl;
            return new B;
        default:
            std::cout << "C will be Generated" << std::endl;
            return new C;
    }
}

int     main() {
    Base *base_ptr = generate();
    std::cout << "Identiy pointer: " << std::endl;
    identify(base_ptr);
    std::cout << std::endl;

    std::cout << "Identify reference: " << std::endl;
    identify(*base_ptr);

    delete base_ptr;
}
