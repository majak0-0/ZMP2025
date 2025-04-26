#include <iostream>
#include <vector>
using namespace std;

int countInversionsBruteForce(const vector<int>& arr) {
    int n = arr.size();
    int inv_count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j])
                ++inv_count;
        }
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i) cin >> T[i];

    cout << countInversionsBruteForce(T) << endl;
    return 0;
}