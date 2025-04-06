#include <iostream>

// Zadanie 1a: Obliczanie Fibonacciego iteracyjnie
long long fibonacci_iter(int n) {
    if (n == 0 || n == 1) return 1;
    long long a = 1, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << fibonacci_iter(n) << "\n";
    return 0;
}
