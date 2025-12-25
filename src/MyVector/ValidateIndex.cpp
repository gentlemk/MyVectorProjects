#include "../../include/MyVector/myVector.h"
#include <stdexcept>

void MyVector::ValidateIndex(size_t index) const
{
    if (data_ == nullptr)
        throw std::runtime_error("data_ is nullptr");
    
    if (index >= size_)
        throw std::out_of_range("Index out of bounds");
}