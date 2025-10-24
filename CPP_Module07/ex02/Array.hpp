#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>
# include <iostream>

template<typename T>
class Array {
    private:
        T*              _array;
        unsigned int    _size;
    
    public:
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int n) : _array(new T[n]), _size(n) {}
        Array(const Array &cpy) : _array(NULL), _size(0) {
            *this = cpy;
        }
        ~Array() {
            delete [] _array;
        }
        Array &operator=(const Array &op_affect) {
            if (this != &op_affect) {
                delete [] _array;
                _size = op_affect._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _array[i] = op_affect._array[i];
            }
            return *this;
        }

        T &operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index is out of bounds!");
            return _array[index];
        }
        const T &operator[](unsigned int index) const {
            if (index >= _size)
                throw std::out_of_range("Index is out of bounds!");
            return _array[index];
        }
        unsigned int size() const {
            return _size;
        }
};

#endif