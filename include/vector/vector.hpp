#pragma once
#include <cstddef>
#include <initializer_list>

namespace s21 {

template <typename T>
class vector {
 private:
  T* data_;
  size_t size_;
  size_t capacity_;

  void ValidateIndex(size_t index) const;

 public:
  using iterator = T*;

  vector();
  vector(size_t size) noexcept;
  vector(std::initializer_list<T> const& items);
  ~vector();
  vector(const vector& otherVector);  //конструктор копирования
  vector(vector&& otherVector) noexcept;  //конструктор перемещения

  vector& operator=(const vector& vector);  //оператор копирования(присваивания)
  vector& operator=(vector&& vector);  //оператор перемещения

  iterator Erase(vector::iterator position);
  iterator Insert(vector::iterator position, const T& value);

  T operator[](size_t index) const;
  T& operator[](size_t index);

  void PushBack(T value);
  void PopBack();

  void Reserve(size_t value);
  void Clear();
  bool Empty();

  size_t GetSize() const;  // const метод не меняет состояние объекта
  size_t GetCapacity() const;

  void PrintInfoVector() const;

  T& Front();
  T& Back();

  iterator begin();
  iterator end();
};
}  // namespace s21

#include "../../src/vector/vector.tpp"