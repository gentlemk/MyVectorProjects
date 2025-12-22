#include <cstddef>

class MyVector {
private:
    int* data_;
    size_t size_;
    size_t capacity_;


public:
    int* GetData();

    MyVector();
    ~MyVector();
    MyVector(const MyVector& otherVector);//конструктор копирования
    MyVector(MyVector&& otherVector) noexcept;//конструктор перемещения
    MyVector& operator= (const MyVector& vector);//оператор копирования(присваивания)
    MyVector& operator= (MyVector&& vector);//оператор перемещения

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

    using iterator = int*;

    iterator begin();
    iterator end();
};