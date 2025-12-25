#include "../../include/MyVector/myVector.h"

void MyVector::Reserve(size_t new_capacity)
{
    if (new_capacity <= capacity_)
    {
        return;
    }
    
    int* new_data = new int[new_capacity];

    if (data_ != nullptr)
    {
        for (size_t i = 0; i < capacity_; i++)
        {
            new_data[i] = data_[i];
        }
        delete[] data_;
    }

    data_ = new_data;
    capacity_ = new_capacity;
}