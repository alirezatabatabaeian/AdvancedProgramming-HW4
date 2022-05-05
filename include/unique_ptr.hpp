////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) // Main Constructor
    : _p { ptr }
{
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::UniquePtr() // default constructor with counter = 0
    : _p { nullptr }
{
    
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::~UniquePtr() // destructor
{
    delete _p; // delete and nullptr
    _p = nullptr;
}
////////////////////////////////////////////////
template <typename T>
T UniquePtr<T>::operator*() // star operator for dereferencing
{
    return *_p;
}
////////////////////////////////////////////////
template <typename T>
T* UniquePtr<T>::operator->() // like (*object.)
{
    return _p;
}
////////////////////////////////////////////////
template <typename T>
void UniquePtr<T>::reset() // reset for delete value and return nullptr
{
    delete _p;
    _p = nullptr;
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>& UniquePtr<T>::reset(T* ptr) // reset for delete value and make new value
{
    delete _p;
    _p = ptr;
    return *this;
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::operator bool() // bool operator for using in "if"
{
    if (_p == nullptr)
        return false;
    else
        return true;
}
////////////////////////////////////////////////
template <typename T>
T* UniquePtr<T>::release() // release for return _p and make _p a nullptr
{
    T* temp { _p };
    _p = nullptr;
    return temp;
}

////////////////////////////////////////////////