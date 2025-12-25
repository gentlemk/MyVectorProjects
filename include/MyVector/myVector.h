#pragma once
#include <cstddef>

class MyVector {
    private:
    int* data_;
    size_t size_;
    size_t capacity_;
    
    
    void ValidateIndex(size_t index) const; 


    public:
    using iterator = int*;

    MyVector();
    ~MyVector();
    MyVector(const MyVector& otherVector);//конструктор копирования
    MyVector(MyVector&& otherVector) noexcept;//конструктор перемещения
    MyVector& operator= (const MyVector& vector);//оператор копирования(присваивания)
    MyVector& operator= (MyVector&& vector);//оператор перемещения

    iterator Erase(MyVector::iterator position);
    iterator Insert(MyVector::iterator position, const int& value);
    int operator[] (size_t index) const;
    int& operator[] (size_t index);

    MyVector(size_t size) noexcept;

    void PushBack(int value);
    void PopBack();

    void Reserve(size_t value);
    void Clear();
    bool Empty();

    size_t GetSize() const; //const метод не меняет состояние объекта
    size_t GetCapacity() const;

    void PrintInfoMyVector() const;

    int& Front();
    int& Back();

    iterator begin();
    iterator end();
};