#include <iostream>
#include <vector>
using namespace std;

int maxDifferenceBruteForce(const vector<int>& T) {
    int n = T.size();
    int maxDiff = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            maxDiff = max(maxDiff, T[j] - T[i]);
        }
    }
    return maxDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i)
        cin >> T[i];

    cout << maxDifferenceBruteForce(T) << endl;

    return 0;
}