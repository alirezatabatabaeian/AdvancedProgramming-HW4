#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* ptr);
    UniquePtr(UniquePtr<T>& unique_ptr) = delete;
    UniquePtr();
    ~UniquePtr();
    T* get() { return _p; }
    T operator*();
    void operator=(UniquePtr<T>& unique_ptr) = delete;
    T* operator->();
    void reset();
    UniquePtr<T>& reset(T* ptr);
    operator bool();
    T* release();

private:
    T* _p;
};

template <typename T>
UniquePtr<T> make_unique(T value)
{
    return UniquePtr<T> { new T { value } };
}

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR