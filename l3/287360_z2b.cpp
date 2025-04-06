#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    int T[20];
    for (int i = 0; i < n; i++) cin >> T[i];
    cin >> k;

    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
        int count = 0;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) count++;
        if (count <= k) {
            if (count == 0) {
                cout << "empty" << endl;
                continue;
            }
            for (int i = 0; i < n; i++)
                if (mask & (1 << i)) cout << T[i] << " ";
            cout << endl;
        }
    }
    return 0;
}