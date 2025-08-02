//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include "pyramid.h"

int main() {
    Pyramid pyramid1(1);
    Pyramid pyramid2(2);
    Pyramid pyramid3(17);
    Pyramid pyramid4(20);
    Pyramid pyramid5(34);
    
    std::cout << "Pyramid 1:\n";
    pyramid1.create();
    pyramid1.flip();
    std::cout << "\n";

    std::cout << "Pyramid 2:\n";
    pyramid2.create();
    pyramid2.flip();
    std::cout << "\n";

    std::cout << "Pyramid 3:\n";
    pyramid3.create();
    pyramid3.flip();
    std::cout << "\n";

    std::cout << "Pyramid 4:\n";
    pyramid4.create();
    pyramid4.flip();
    std::cout << "\n";

    std::cout << "Pyramid 5:\n";
    pyramid5.create();
    pyramid5.flip();
    std::cout << "\n";

    return 0;
}
