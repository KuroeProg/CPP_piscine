#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <cstdint>
# include "Data.hpp"

class Serializer {
    public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

    private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &);
    Serializer &operator=(const Serializer &);
};


#endif