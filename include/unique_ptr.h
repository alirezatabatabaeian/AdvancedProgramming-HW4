#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* ptr);
    UniquePtr();
    UniquePtr(UniquePtr<T> unique_ptr);
    ~UniquePtr();
    T* get() { return _p; }
    T operator*();

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(T value)
{
    UniquePtr<T> unique_ptr { new T { value } };
    return unique_ptr;
}

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR