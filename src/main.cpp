#include "../include/myVector.h"
#include <iostream>
#include <vector>

int main()
{
    MyVector vect;
    vect.PrintInfoMyVector();

    for (int i = 1; i < 7; i++)
    {
        vect.PushBack(i);
        vect.PrintInfoMyVector();
    }

    std::cout << vect.Front() << std::endl;
    std::cout << vect.Back() << std::endl;

    vect.Front() = 100;
    vect.Back() = 100;
    vect.PrintInfoMyVector();
    
    return 0;
}
