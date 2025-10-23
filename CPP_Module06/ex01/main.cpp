#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data data;

    data.i = 10;
    data.str = "Random str";

    std::cout << "Before serialization:" << std::endl;
    std::cout << "Adress: " << &data << std::endl;
    std::cout << "Data integer: " << data.i << std::endl;
    std::cout << "Data string: " << data.str << std::endl;
    std::cout << "\n";
    
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "\n";


    Data *deserializedPtr = Serializer::deserialize(raw);
    std::cout << "After the deserialization" << std::endl;
    std::cout << "Adress: " << deserializedPtr << std::endl;
    std::cout << "Data Integer " << deserializedPtr->i << std::endl;
    std::cout << "Data String: " << deserializedPtr->str << std::endl;

    return 0;
}