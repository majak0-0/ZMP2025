#include <iostream>
#include <vector>
using namespace std;

int maxDifferenceEfficient(const vector<int>& T) {
    int n = T.size();
    if (n == 0) return 0;

    int min_so_far = T[0];
    int max_diff = INT_MIN;

    for (int j = 1; j < n; ++j) {
        max_diff = max(max_diff, T[j] - min_so_far);
        min_so_far = min(min_so_far, T[j]);
    }

    return max_diff;
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i)
        cin >> T[i];

    cout << maxDifferenceEfficient(T) << endl;

    return 0;
}