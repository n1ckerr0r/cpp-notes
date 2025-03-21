#include "main.h"

int func(int a);

void func1(int a);

int main() {
    int a;
    std::cin >> a;
    std::cout << func(a) << '\n';
    func1(a);
}