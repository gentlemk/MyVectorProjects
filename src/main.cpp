#include "../include/myVector.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    MyVector v1;
    
    v1.PushBack(1);
    v1.PushBack(1);
    v1.PushBack(1);
    v1.PushBack(1);

    // for (auto i = v1.begin(); i < v1.end(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    
    for (auto i : v1)
    {
        std::cout << i << std::endl;
    }

    MyVector v2(2);
    std::copy(v1.begin(), v1.end(), v2.begin());

    v2.PrintInfoMyVector();
    for (auto i : v2)
    {
        std::cout << i << std::endl;
    }












    // MyVector v1(2);
    // v1.PushBack(1);
    // v1.PushBack(1);
    // v1.PushBack(1);
    // v1.PrintInfoMyVector();
    // MyVector v2(3);
    // v2.PrintInfoMyVector();

    // v2 = v1;
    // v2.PrintInfoMyVector();


    // MyVector v3 = std::move(v2);

    // v2.PrintInfoMyVector();
    // v3.PrintInfoMyVector();

    // v1 = std::move(v3);

    // v1.PrintInfoMyVector();
    // v3.PrintInfoMyVector();


    // MyVector vect;
    // vect.PrintInfoMyVector();

    // for (int i = 1; i < 7; i++)
    // {
    //     vect.PushBack(i);
    //     vect.PrintInfoMyVector();
    // }

    // std::cout << vect.Front() << std::endl;
    // std::cout << vect.Back() << std::endl;

    // vect.Front() = 100;
    // vect.Back() = 100;
    // vect.PrintInfoMyVector();
    // MyVector vect2(5);
    // vect2.PrintInfoMyVector();
    // MyVector vect2 = vect1;
    
    return 0;
}
