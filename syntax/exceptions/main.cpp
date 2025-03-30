#include <iostream>
#include <stdexcept>

class TooBigValue : public std::exception {
public:
    const char* what() const noexcept override {
        return "MyException";
    }
};

class TooSmallValue : public std::runtime_error {
public:
    explicit TooSmallValue(const std::string& msg) : std::runtime_error(msg){}
};

void func(int &a) {
    int index = 10'000;
    int* arr = new int[index];
    for (int i = 0; i < 10; i++) arr[i] = i*10;
    if (a < 0) {
        throw TooSmallValue("Error: a must be more 0");
    }
    if (a >= index) {
        throw TooBigValue();
    }
    std::cout << arr[a];
}

int main() {
    int a;
    std::cin >> a;

    try {
        func(a);
    }
    catch (const TooBigValue& e) {
        std::cerr << e.what();
    }
    catch (const TooSmallValue& e) {
        std::cerr << e.what();
    }
}