#ifndef SHARED_PTR
#define SHARED_PTR

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr);
    SharedPtr(SharedPtr<T>& shared_ptr);
    SharedPtr();
    // ~SharedPtr();
    T* get() { return _p; }
    void operator=(SharedPtr<T>& shared_ptr);
    int use_count();
    T operator*();
    T* operator->();
    void reset();
    SharedPtr<T>& reset(T* ptr);
    operator bool();

private:
    T* _p;
    int* counter;
};

template <typename T>
SharedPtr<T> make_shared(T value)
{
    return SharedPtr<T> { new T { value } };
}

#include "shared_ptr.hpp"

#endif // SHARED_PTR