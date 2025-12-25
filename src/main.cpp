#include "../include/MyVector/myVector.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    MyVector v1{5};
    v1.PushBack(13);
    v1.PopBack();
    return 0;
}
