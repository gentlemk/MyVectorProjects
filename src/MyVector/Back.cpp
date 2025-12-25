#include "../../include/MyVector/myVector.h"
#include <stdexcept>

int& MyVector::Back()
{
    //базовый вектор не вызывает исключение
    if (size_ == 0)
    {
        throw std::runtime_error("MyVector::Back(): Vector is empty");
    }
    return data_[size_ - 1];
}
