#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>

template <typename T> // define T as a typename template
class SharedPtr {
public:
    SharedPtr(T* ptr); // main constructor
    SharedPtr(SharedPtr<T>& shared_ptr); // copy constructor
    SharedPtr(); // default constructor
    ~SharedPtr(); // destructor
    T* get() { return _p; } // return pointer
    void operator=(SharedPtr<T>& shared_ptr); // = operator
    int use_count(); // count number of usage
    T operator*(); // * operator
    T* operator->(); // -> operator
    void reset(); // reset with no input
    SharedPtr<T>& reset(T* ptr); // reset with input
    operator bool(); // cast to bool for using in "if"

private: // variables
    T* _p;
    int* counter;
};

template <typename T>
SharedPtr<T> make_shared(T value) // make shared outside the class
{
    return SharedPtr<T> { new T { value } }; // return a shared pointer
}

#include "shared_ptr.hpp"

#endif // SHARED_PTR