#include "../include/myVector.h"
#include <iostream>

// MyVector& MyVector::operator= (const MyVector& vector)
// {

// }

// MyVector& MyVector::operator= (const MyVector&& vector)
// {

// }

MyVector::MyVector()
{
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    std::cout << "По умолчанию" << std::endl;
}

MyVector::~MyVector()
{
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
    std::cout << "Деструктор" << std::endl;
}

MyVector::MyVector(const MyVector& otherVector)//конструктор копирования
{
    size_ = otherVector.size_;
    capacity_ = otherVector.capacity_;
    data_ = new int[capacity_];
    for (size_t i = 0; i < otherVector.size_; i++)
    {
        data_[i] = otherVector[i];
    }
}

//конструктор перемещения
//что такое && и чем отличается от &
MyVector::MyVector(MyVector&& otherVector) noexcept : 
    data_(otherVector.data_), 
    size_(otherVector.size_), 
    capacity_(otherVector.capacity_)
{
    otherVector.size_ = 0;
    otherVector.capacity_ = 0;
    otherVector.data_ = nullptr;
}


    // MyVector(int size);


void MyVector::PushBack(int value)
{
    printf("Вызов метода PushBack(%d)\n", value);
    if (size_ == capacity_)
    {
        printf("нехватает размера веткора\n");
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

void MyVector::Reserve(size_t new_capacity)
{
    if (new_capacity <= capacity_)
    {
        return;
    }
    
    int* new_data = new int[new_capacity];

    if (data_ != nullptr)
    {
        std::cout << "старая ссылка не null" << std::endl;
        for (size_t i = 0; i < capacity_; i++)
        {
            new_data[i] = data_[i];
        }
        std::cout << "почистил" << std::endl;
        delete[] data_;
    }

    data_ = new_data;
    capacity_ = new_capacity;

    std::cout << "Выделено " << new_capacity << " элементов" << std::endl;
}

size_t MyVector::GetCapacity() const
{
    return capacity_;
}

size_t MyVector::GetSize() const
{
    return size_;
}

int MyVector::operator[] (size_t index) const
{
    if (data_ == nullptr)
    {
        printf("%ld %ld %ld\n", size_, capacity_, index);
        printf("data_ -> nullptr");
        throw "data_ -> nullptr";
    }
    else if (index >= size_ )
    {
        printf("%ld %ld %ld\n", size_, capacity_, index);
        printf("Выход за границы массива");
        throw "Выход за границы массива";
        // throw std::exception();
    }
    else
    {
        return data_[index];
    }
}

int& MyVector::Front()
{
    std::cout << "Вызов Front()\n";
    if (size_ == 0)
    {
        std::cout << "Пустой вектор\n";
        throw "Пустой вектор\n";
    }
    return data_[0];
    
}

int& MyVector::Back()
{
    std::cout << "Вызов Back()\n";
    if (size_ == 0)
    {
        std::cout << "Пустой вектор\n";
        throw "Пустой вектор\n";
    }
    return data_[size_ - 1];
}

void MyVector::PrintInfoMyVector() const
{
    printf("%ld - capacity\n%ld - size\n", capacity_, size_);
    printf("Элементы\n");
    for (size_t i = 0; i < size_; i++)
    {
        std::cout << data_[i] << " ";
    }
    printf("\n");
    printf("\n");
}
