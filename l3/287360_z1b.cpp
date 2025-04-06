#include <iostream>
#include <vector>

// Zadanie 1b: Obliczanie Fibonacciego rekurencyjnie z memoizacją
unsigned long long fibonacci_recur(int n, std::vector<unsigned long long>& memo) {
    if (n == 0 || n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibonacci_recur(n - 1, memo) + fibonacci_recur(n - 2, memo);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<unsigned long long> memo(n + 1, -1);
    std::cout << fibonacci_recur(n, memo) << "\n";
    return 0;
}
