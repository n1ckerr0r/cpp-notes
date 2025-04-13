#include <iostream>
#include <format>

void func(int &a) {
    int b = a;
    std::cout << std::format("func1: {}\n", b);
}
void func(int &&a) {
    int b = a;
    std::cout << std::format("func2: {}\n", b);
}

int main() {
    // l_vlue a = r_value 0
    int a = 0;

    func(a);
    func(std::move(a));
    func(a+10);
}