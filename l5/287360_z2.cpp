#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid;
    
    while (i < mid && j < right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i < mid) temp.push_back(arr[i++]);
    while (j < right) temp.push_back(arr[j++]);
    
    for (int k = 0; k < temp.size(); ++k)
        arr[left + k] = temp[k];
}

void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int left = i;
            int mid = min(i + width, n);
            int right = min(i + 2 * width, n);
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for (int i = 0; i < n; ++i)
        cin >> T[i];

    iterativeMergeSort(T);

    for (int i = 0; i < n; ++i)
        cout << T[i] << " ";
    cout << endl;

    return 0;
}