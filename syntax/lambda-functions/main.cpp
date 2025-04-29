#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

class MyClass {
public:
    int value = 0;

    void print() {
        auto lambda = [this]() { std::cout << "value:\t" << this->value << '\n'; };
        lambda();
    }
};

int main() {
    auto sum = [](int a, int b)  { return a + b; };
    std::cout << sum(2, 3) << '\n';


    std::vector<int> v{1, 2, 3, 4, 5, 6};

    std::sort(v.begin(), v.end(), [](int a, int b){return a > b;});

    for (int i = 0; i < v.size(); i++) { std::cout << v[i] << ' '; }
    std::cout << '\n';

    MyClass mc;
    mc.value++;
    mc.print();

    std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << ' '; });
    std::cout << '\n';

    auto it1 = std::find(v.begin(), v.end(), 5);
    auto it2 = std::find_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

    std::cout <<  std::any_of(v.begin(), v.end(), [&](int x) { return std::find(v.begin(), v.end(), x * x) != v.end(); }) << '\n';
    std::cout << std::all_of(v.begin(), v.end(), [](int x){ return x >= 0; }) << '\n';
    std::cout << std::none_of(v.begin(), v.end(), [](int x){return x < 0;}) << '\n';

    v.erase(std::remove_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; }), v.end());

    std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x*x*x; });

    std::cout << count_if(v.begin(), v.end(), [](int x){ return x > 125; }) << '\n';

    std::partition(v.begin(), v.end(), [](int x){ return x < 27; });

    std::cout << std::accumulate(v.begin(), v.end(), 0);
}