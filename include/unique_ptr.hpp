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
UniquePtr<T>::~UniquePtr()
{
    delete _p;
    _p = nullptr;
}
////////////////////////////////////////////////
template <typename T>
T UniquePtr<T>::operator*()
{
    return *_p;
}
////////////////////////////////////////////////
template <typename T>
T* UniquePtr<T>::operator->()
{
    return _p;
}
////////////////////////////////////////////////
template <typename T>
void UniquePtr<T>::reset()
{
    delete _p;
    _p = nullptr;
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>& UniquePtr<T>::reset(T* ptr)
{
    delete _p;
    _p = ptr;
    return *this;
}
////////////////////////////////////////////////
template <typename T>
UniquePtr<T>::operator bool()
{
    if (_p == nullptr)
        return false;
    else
        return true;
}
////////////////////////////////////////////////
template <typename T>
T* UniquePtr<T>::release()
{
    T* temp { _p };
    _p = nullptr;
    return temp;
}

////////////////////////////////////////////////