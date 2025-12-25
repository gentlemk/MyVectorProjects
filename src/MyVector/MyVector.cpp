#include "../../include/MyVector/myVector.h"
#include <iostream>

MyVector::MyVector()
{
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

MyVector::~MyVector()
{
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
}

MyVector::MyVector(const MyVector& otherVector)
{
    size_ = otherVector.size_;
    capacity_ = otherVector.capacity_;
    data_ = new int[capacity_];
    for (size_t i = 0; i < otherVector.size_; i++)
    {
        data_[i] = otherVector[i];
    }
}

MyVector::MyVector(MyVector&& otherVector) noexcept : 
    data_(otherVector.data_), 
    size_(otherVector.size_), 
    capacity_(otherVector.capacity_)
{
    std::cout << "конструктор перемещения\n";
    otherVector.size_ = 0;
    otherVector.capacity_ = 0;
    otherVector.data_ = nullptr;
}

MyVector::MyVector(size_t size) noexcept
{
    data_ = new int[size];
    size_ = 0;
    capacity_ = size;
    std::cout << "Конструктор с параметром\n";
}

size_t MyVector::GetCapacity() const
{
    return capacity_;
}

size_t MyVector::GetSize() const
{
    return size_;
}


void MyVector::PrintInfoMyVector() const
{
    for (size_t i = 0; i < size_; i++)
    {
        std::cout << data_[i] << " ";
    }
    printf("\n");
}

MyVector::iterator MyVector::begin()
{
    return data_;
}

MyVector::iterator MyVector::end()
{
    return data_ + size_;
}

MyVector::iterator MyVector::Erase(MyVector::iterator position)
{
    auto index = position - this->begin();

    if (position < this->begin() || position >= this->end())
    {
        std::cout << "Выход за границы\n";
        throw;
    }

    for (size_t i = index; i < size_ - 1; i++)
    {
        data_[i] = data_[i + 1];
    }
    size_--;
    return &data_[index + 1];
}

MyVector::iterator MyVector::Insert(MyVector::iterator position, const int& value)
{
    auto index = position - this->begin();
    if (position < this->begin() || position >= this->end())
    {
        std::cout << "Выход за границы\n";
        throw;
    }

    if (size_ == capacity_)
    {
        capacity_ = capacity_ == 0 ? 1 : capacity_ * 2;
        auto new_data = new int[capacity_];
        for (auto i = 0; i < index; i++)
        {
            new_data[i] = data_[i];
        }
        new_data[index] = value;
        for (size_t i = index; i < size_; i++)
        {
            new_data[i + 1] = data_[i];
        }
        size_++;
        delete[] data_;
        data_ = new_data;
    }
    else
    {
        for (long i = size_; i > index; i--)
        {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
        size_++;
    }
    return &data_[index];
}