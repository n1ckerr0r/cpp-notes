#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>


int main() {
    std::vector vals { 10, 11, 2, -3, 4, 55, 0, 0, -4, 10, -8 };

    for (auto i :  std::views::transform(std::views::filter( vals, [](auto a){ return a > 0; } ),[](auto a){ return 2*a; })) {
        std::cout << i << ' ';
    }

    std::vector vals1 { 10, 11, 2, -3, 4, 55, 0, 0, -4, 10, -8 };

    for (auto p : vals | std::views::filter([](auto x){ return x > 0; })
    | std::views::transform([](auto x){ return 2*x; } ) ) {
        std::cout << p << ' ';
    }

    // Примеры популярных функций
    std::ranges::sort(vals);
    auto it = std::ranges::find(vals, 4);
    int count = std::ranges::count(vals, 22);
    std::ranges::for_each(vals, [](int x){ return x - 10; });

    vals | std::views::filter([](int x){ return x % 4 == 0; });
    auto new_vals = vals | std::views::transform([](int x){ return x + 5; });
    // Взять первые n элементов
    auto first3 = vals | std::views::take(3);
    // Пропустить первые n элементов
    auto after3 = vals | std::views::drop(3);
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}, {5, 0}};
    auto joined = matrix | std::views::join;

    std::vector<int> a = {1, 2, 3};
    std::vector<std::string> b = {"a", "b", "b"};
    auto ziped = std::views::zip(a, b);
}
