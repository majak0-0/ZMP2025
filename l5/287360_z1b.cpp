#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    long long inv_count = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            inv_count += left.size() - i;
        }
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];

    return inv_count;
}

long long countInversions(vector<int>& arr, int l, int r) {
    long long inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        inv_count += countInversions(arr, l, m);
        inv_count += countInversions(arr, m + 1, r);
        inv_count += mergeAndCount(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i) cin >> T[i];

    cout << countInversions(T, 0, n - 1) << endl;
    return 0;
}