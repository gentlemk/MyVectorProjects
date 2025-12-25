#include "../../include/MyVector/myVector.h"

int MyVector::operator[] (size_t index) const
{
    ValidateIndex(index);
    return data_[index];
}

int& MyVector::operator[] (size_t index)
{
    ValidateIndex(index);
    return data_[index];
}

MyVector& MyVector::operator= (MyVector&& otherVector)
{
    if (this != &otherVector)
    {
        size_ = otherVector.size_;
        capacity_ = otherVector.capacity_;
        if (data_ != nullptr)
        {
            delete[] data_;
        }
        data_ = otherVector.data_;
        otherVector.size_ = 0;
        otherVector.capacity_ = 0;
        otherVector.data_ = nullptr;
    }
    return *this;
}

MyVector& MyVector::operator= (const MyVector& otherVector)
{
    if (this != &otherVector)
    {
        size_ = otherVector.size_;
        capacity_ = otherVector.capacity_;
        if (data_ != nullptr)
        {
            delete[] data_;
        }

        data_ = new int[capacity_];
        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = otherVector.data_[i];
        }
    }
    return *this;
}
