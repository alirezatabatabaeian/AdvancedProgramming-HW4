////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr(T* ptr) // Constructor with counter = 1
    : _p { ptr }
    , counter { new int { 1 } }
{
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr() // default constructor with counter = 0
    : _p { nullptr }
    , counter { new int { 0 } }
{
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& shared_ptr) // copy constructor with counter += 1
    : _p { shared_ptr._p }
    , counter { &(++(*shared_ptr.counter)) }
{
}
////////////////////////////////////////////////
template <typename T>
void SharedPtr<T>::operator=(SharedPtr<T>& shared_ptr) // equal operator like copy constructor
{
    if (this->_p == shared_ptr._p) { // do not copy repeated things
    } else {
        _p = shared_ptr._p;
        counter = &(++(*shared_ptr.counter));
    }
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::~SharedPtr() // destructor
{
    if (*(this->counter) == 0) { // if _p == nullptr

    } else if (*(this->counter) == 1) { // if only one pointer to that thing
        delete _p;
        _p = nullptr;
        *counter = 0;
    } else {
        _p = nullptr; // more than one pointer to same thing
        *counter -= 1;
    }
}
////////////////////////////////////////////////
template <typename T>
T SharedPtr<T>::operator*() // star operator for dereferencing
{
    return *_p;
}
////////////////////////////////////////////////
template <typename T>
T* SharedPtr<T>::operator->() // like (*object.)
{
    return _p;
}
////////////////////////////////////////////////
template <typename T>
void SharedPtr<T>::reset() // reset for delete value and return nullptr with counter = 0
{
    delete _p;
    _p = nullptr;
    counter = new int { 0 };
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>& SharedPtr<T>::reset(T* ptr)
{ // reset for delete value and make new value with counter = 1
    delete _p;
    _p = ptr;
    counter = new int { 1 };
    return *this;
}
////////////////////////////////////////////////
template <typename T>
SharedPtr<T>::operator bool() // bool operator for using in "if"
{
    if (_p == nullptr)
        return false;
    else
        return true;
}
////////////////////////////////////////////////
template <typename T>
int SharedPtr<T>::use_count() // for returning # of pointers
{
    return *counter;
}
////////////////////////////////////////////////