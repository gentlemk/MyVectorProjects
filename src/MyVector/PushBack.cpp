#include "../../include/MyVector/myVector.h"

void MyVector::PushBack(int value)
{
    if (size_ == capacity_)
    {
        this->Reserve(capacity_ * 2);
    }
    if (data_ == nullptr)
    {
        data_ = new int[1];
        capacity_ = 1;
        size_ = 0;
    }
    data_[size_] = value;
    size_++;
}