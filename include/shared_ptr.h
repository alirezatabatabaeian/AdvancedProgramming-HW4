#ifndef SHARED_PTR
#define SHARED_PTR

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* ptr);
    //
    SharedPtr();
    ~SharedPtr();

private:
    T* _p;
};

template <typename T>
SharedPtr<T> make_unique(T value)
{
    SharedPtr<T> shared_ptr { new T { value } };
    return shared_ptr;
}

// #include "shared_ptr.hpp"
#endif // SHARED_PTR