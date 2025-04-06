#include <iostream>
#include <vector>

// Zadanie 2a: Generowanie wszystkich podzbiorów
void generate_subsets(const std::vector<int>& T, int index, std::vector<int>& current) {
    if (index == T.size()) {
        if (current.empty()) std::cout << "empty";
        else {
            for (int num : current) std::cout << num << " ";
        }
        std::cout << "\n";
        return;
    }
    generate_subsets(T, index + 1, current);
    current.push_back(T[index]);
    generate_subsets(T, index + 1, current);
    current.pop_back();
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> T(n);
    for (int& num : T) std::cin >> num;
    
    std::vector<int> current;
    generate_subsets(T, 0, current);
    return 0;
}
