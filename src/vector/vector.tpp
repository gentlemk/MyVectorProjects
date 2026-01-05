#include "vector/vector.hpp"

namespace s21 {




//конструкторы
template <typename T>
vector<T>::vector() {
  data_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
vector<T>::vector(const vector& otherVector) {
  size_ = otherVector.size_;
  capacity_ = otherVector.capacity_;
  data_ = new T[capacity_];
  for (size_t i = 0; i < otherVector.size_; i++) {
    data_[i] = otherVector[i];
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<T> const& items)
    : data_(new T[items.size()]), size_(items.size()), capacity_(items.size()) {
  for (size_t i = 0; i < size_; i++) {
    data_[i] = *(items.begin() + i);
  }
}

template <typename T>
vector<T>::vector(vector&& otherVector) noexcept
    : data_(otherVector.data_),
      size_(otherVector.size_),
      capacity_(otherVector.capacity_) {
  otherVector.size_ = 0;
  otherVector.capacity_ = 0;
  otherVector.data_ = nullptr;
}

template <typename T>
vector<T>::vector(size_t capacity) noexcept {
  data_ = new T[capacity];
  size_ = 0;
  capacity_ = capacity;
}

//деструктор
template <typename T>
vector<T>::~vector() {
  delete[] data_;
  size_ = 0;
  capacity_ = 0;
}

//операторы

template <typename T>
T vector<T>::operator[](size_t index) const {
  ValidateIndex(index);
  return data_[index];
}

template <typename T>
T& vector<T>::operator[](size_t index) {
  ValidateIndex(index);
  return data_[index];
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& otherVector) {
  if (this != &otherVector) {
    size_ = otherVector.size_;
    capacity_ = otherVector.capacity_;
    if (data_ != nullptr) {
      delete[] data_;
    }

    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; i++) {
      data_[i] = otherVector.data_[i];
    }
  }
  return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(vector&& otherVector) {
  if (this != &otherVector) {
    size_ = otherVector.size_;
    capacity_ = otherVector.capacity_;
    if (data_ != nullptr) {
      delete[] data_;
    }
    data_ = otherVector.data_;
    otherVector.size_ = 0;
    otherVector.capacity_ = 0;
    otherVector.data_ = nullptr;
  }
  return *this;
}

template <typename T>
bool vector<T>::Empty() {
  return size_ == 0;
}

template <typename T>
T& vector<T>::Front() {
  //базовый метод не должен вызывать исключение
  if (size_ == 0) {
    throw std::out_of_range("vector::Front(): vector is empty");
  }
  return data_[0];
}


template <typename T>
void vector<T>::PopBack() {
  if (size_ > 0) {
    size_--;
  }
}

template <typename T>
void vector<T>::PrintInfoVector() const {
  for (size_t i = 0; i < size_; i++) {
    std::cout << data_[i] << " ";
  }
  printf("\n");
}

template <typename T>
void vector<T>::PushBack(T value) {
  if (size_ == capacity_) {
    this->Reserve(capacity_ * 2);
  }
  if (data_ == nullptr) {
    data_ = new T[1];
    capacity_ = 1;
    size_ = 0;
  }
  data_[size_] = value;
  size_++;
}

template <typename T>
void vector<T>::ValidateIndex(size_t index) const {
  if (data_ == nullptr) throw std::runtime_error("data_ is nullptr");

  if (index >= size_) throw std::out_of_range("Index out of bounds");
}

template <typename T>
size_t vector<T>::GetCapacity() const {
  return capacity_;
}

template <typename T>
size_t vector<T>::GetSize() const {
  return size_;
}

template <typename T>
T& vector<T>::Back() {
    //базовый вектор не вызывает исключение
    if (size_ == 0) {
        throw std::runtime_error("vector::Back(): Vector is empty");
    }
    return data_[size_ - 1];
}

template <typename T>
void vector<T>::Clear() {
    size_ = 0;
}

//итераторы
template <typename T>
typename vector<T>::iterator vector<T>::begin()
{
    return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end()
{
    return data_ + size_;
}


template <typename T>
typename vector<T>::iterator vector<T>::Erase(vector<T>::iterator position)
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

template <typename T>
void vector<T>::Reserve(size_t new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }

  T* new_data = new T[new_capacity];

  if (data_ != nullptr) {
    for (size_t i = 0; i < capacity_; i++) {
      new_data[i] = data_[i];
    }
    delete[] data_;
  }

  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
typename vector<T>::iterator vector<T>::Insert(vector<T>::iterator position, const T&
value)
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
        auto new_data = new T[capacity_];
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
        for (auto i = size_; i > index; i--)
        {
            data_[i] = data_[i - 1];
        }
        data_[index] = value;
        size_++;
    }
    return &data_[index];
}

};  // namespace s21
