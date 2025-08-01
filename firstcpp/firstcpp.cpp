/*
CPP learning notes.
*/

#include <iostream>

template <typename T>
void printInfo(T param) {
    std::cout
        << typeid(param).name()
        << " "
        << param
        << "; At addr: "
        << &param
        << "; Using bytes: "
        << sizeof(param)
        << std::endl;
}

int main()
{
    // int: 4 bytes
    int smallInt{ 100 };
    printInfo(smallInt);

    // long long: 8 bytes
    long long bigInt{ 0 };
    printInfo(bigInt);

    // float
    float smallFloat{ 1. };
    printInfo(smallFloat);

    // double
    double bigFloat{ 0b10010 };
    printInfo(bigFloat);

    // char
    char smallChar{ 'a' };
    printInfo(smallChar);

    // string
    std::string largeString{ "Hello World" };
    printInfo(largeString);

}
