class RandomAccessIterator
{
private:
    int* ptr_elem;
public:
    RandomAccessIterator();
    RandomAccessIterator(const RandomAccessIterator& other);
    explicit RandomAccessIterator(int* value);
    
};