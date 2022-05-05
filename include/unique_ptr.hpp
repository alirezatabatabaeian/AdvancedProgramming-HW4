////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::UniquePtr(T* ptr)
    : _p { ptr }
{
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::UniquePtr()
    : _p { nullptr }
{
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::UniquePtr(UniquePtr<T>& unique_ptr)
{
    // #error "Compiler Error : Copy Constructor is Banned"
}

////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::~UniquePtr()
{
    delete _p;
    _p = nullptr;
}
////////////////////////////////////////////////
template <typename T>
T UniquePtr<T>::operator*()
{
    return *(this->_p);
}
////////////////////////////////////////////////
template <typename T>
void UniquePtr<T>::operator=(UniquePtr<T>& unique_ptr)
{
    // #error "Compiler Error : Equal Operator is Banned"
}

////////////////////////////////////////////////