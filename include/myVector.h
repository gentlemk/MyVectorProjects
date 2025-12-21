#include <cstddef>

class MyVector {
private:
    int* data_;
    size_t size_;
    size_t capacity_;


public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector& otherVector);//конструктор копирования
    MyVector(MyVector&& otherVector) noexcept;//конструктор перемещения
    // MyVector& operator= (const MyVector& vector);//оператор копирования(присваивания)
    // MyVector& operator= (const MyVector&& vector);//оператор перемещения

    int operator[] (size_t index) const;

    MyVector(size_t size);

    void PushBack(int value);
    void Reserve(size_t value);

    size_t GetSize() const; //const метод не меняет состояние объекта
    size_t GetCapacity() const;

    void PrintInfoMyVector() const;

    int& Front();
    int& Back();
};