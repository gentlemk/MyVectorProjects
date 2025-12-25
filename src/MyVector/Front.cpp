#include "../../include/MyVector/myVector.h"
#include <stdexcept>

int& MyVector::Front()
{
    //базовый метод не должен вызывать исключение
    if (size_ == 0)
    {
        throw std::out_of_range("MyVector::Front(): vector is empty");
    }
    return data_[0];
}