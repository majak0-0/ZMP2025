#include <iostream>
#include <vector>

// Zadanie 2c: Generowanie podzbiorów o rozmiarze dokładnie k
void generate_k_subsets(const std::vector<int>& T, int index, std::vector<int>& current, int k) {
    if (current.size() == k) {
        for (int num : current) std::cout << num << " ";
        std::cout << "\n";
        return;
    }
    if (index == T.size()) return;
    generate_k_subsets(T, index + 1, current, k);
    current.push_back(T[index]);
    generate_k_subsets(T, index + 1, current, k);
    current.pop_back();
}

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> T(n);
    for (int& num : T) std::cin >> num;
    std::cin >> k;
    std::vector<int> current;
    generate_k_subsets(T, 0, current, k);
    return 0;
}
