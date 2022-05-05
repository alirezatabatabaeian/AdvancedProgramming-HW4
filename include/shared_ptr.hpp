////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p { ptr }
    , counter { new int { 1 } }
{
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr()
    : _p { nullptr }
    , counter { new int { 0 } }
{
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& shared_ptr)
    : _p { shared_ptr._p }
    , counter { &(++(*shared_ptr.counter)) }
{
}
////////////////////////////////////////////////
template <typename T>
void SharedPtr<T>::operator=(SharedPtr<T>& shared_ptr)
{
    if (this->_p == shared_ptr._p) {
    } else {
        _p = shared_ptr._p;
        counter = &(++(*shared_ptr.counter));
    }
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (*(this->counter) == 0) {

    } else if (*(this->counter) == 1) {
        delete _p;
        _p = nullptr;
    } else {
        _p = nullptr;
        *counter -= 1;
    }
}
////////////////////////////////////////////////
template <typename T>
T SharedPtr<T>::operator*()
{
    return *_p;
}
////////////////////////////////////////////////
template <typename T>
T* SharedPtr<T>::operator->()
{
    return _p;
}
////////////////////////////////////////////////
template <typename T>
void SharedPtr<T>::reset()
{
    delete _p;
    _p = nullptr;
    counter = new int { 0 };
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>& SharedPtr<T>::reset(T* ptr)
{
    delete _p;
    _p = ptr;
    counter = new int { 1 };
    return *this;
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::operator bool()
{
    if (_p == nullptr)
        return false;
    else
        return true;
}
////////////////////////////////////////////////
template <typename T>
int SharedPtr<T>::use_count()
{
    return *counter;
}
////////////////////////////////////////////////