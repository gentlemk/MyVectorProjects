#include "../../include/iterator/RandomAccessIterator.h"

RandomAccessIterator::RandomAccessIterator() { ptr_elem = nullptr; }

RandomAccessIterator::RandomAccessIterator(const RandomAccessIterator& other) {
  ptr_elem = other.ptr_elem;
}

// explicit - приведение типов производится явным образом
explicit RandomAccessIterator::RandomAccessIterator(int* value) {
  ptr_elem = value;
}