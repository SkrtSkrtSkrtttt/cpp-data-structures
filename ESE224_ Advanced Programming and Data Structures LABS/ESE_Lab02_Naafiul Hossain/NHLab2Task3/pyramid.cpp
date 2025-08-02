//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
#include "pyramid.h"

Pyramid::Pyramid(int height) : height(height) {}

void Pyramid::create() {
    int num_x = 1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < height - i - 1; ++j)
            std::cout << " ";

        for (int k = 0; k < num_x; ++k)
            std::cout << "X";

        std::cout << "\n";
        num_x += 2;
    }

    std::cout << "Total X's in the pyramid: " << (height * (height + 1)) / 2 << "\n";
}

void Pyramid::flip() {
    int num_x = height * 2 - 1;

    for (int i = height - 1; i >= 0; --i) {
        for (int j = 0; j < height - i - 1; ++j)
            std::cout << " ";

        for (int k = 0; k < num_x; ++k)
            std::cout << "X";

        std::cout << "\n";
        num_x -= 2;
    }
}
