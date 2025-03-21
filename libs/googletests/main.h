#include <iostream>
#include <limits>
#include <format>

#ifndef MAIN_H
#define MAIN_H

int func(int a) {
    if (a > std::numeric_limits<int>::max()/2) {
        throw std::runtime_error("Error: value is too big");
    }
    return a * 2;
}

void func1(int a) {
    std::cout << std::format("result: {}", a);
}

#endif
