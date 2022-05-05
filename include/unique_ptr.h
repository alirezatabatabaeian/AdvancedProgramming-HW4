#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>

template <typename T> // define T as a typename template
class UniquePtr {
public:
    UniquePtr(T* ptr); // main constructor
    UniquePtr(UniquePtr<T>& unique_ptr) = delete; // copy constructor for compiler error
    UniquePtr(); // default constructor
    ~UniquePtr(); // destructor
    T* get() { return _p; } // return pointer
    T operator*(); // * operator
    void operator=(UniquePtr<T>& unique_ptr) = delete; // = operator for compiler error
    T* operator->(); // -> operator
    void reset(); // reset with no input
    UniquePtr<T>& reset(T* ptr); // reset with input
    operator bool(); // cast to bool for using in "if"
    T* release(); // release function

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(T value) // make shared outside the class
{
    return UniquePtr<T> { new T { value } };
}

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR