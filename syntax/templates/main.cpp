#include <vector>
#include <iostream>
#include <format>
#include <type_traits>

template<typename T>
T max(T a, T b){
    return (a > b) ? a : b;
}

template<typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(const T& item){
        data.push_back(item);
    }
};

template<int a>
void printA() {
    std::cout << a << '\n';
}

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

template <typename T>
concept AllowedTypes = std::is_same_v<T, int> || std::is_same_v<T, double>;

template <AllowedTypes T>
auto mult(T left_value, T right_value) {
    return left_value * right_value;
}

int main() {
    auto a = max<float>(3.0f, 4.7f);

    Stack<int> stack;
    stack.push(6);

    printA<5>();

    std::cout << sum<float, int, int>(1.6, 2, 3) << '\n';
    std::cout << mult(1, 10) << '\n';
}