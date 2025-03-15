
#include <iostream>
using namespace std;

int NWD(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int phi(int n) {
    int cnt = 0;
    for (int k = 1; k <= n; k++)
        if (NWD(k, n) == 1) cnt++;
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << phi(n) << endl;
    return 0;
}
