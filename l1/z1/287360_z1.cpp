#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int len = 1;

    while (true) {
        cout << n << " ";
        if (n == 1) break;
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        len++;
    }

    cout << ", " << len << endl;
    return 0;
}
