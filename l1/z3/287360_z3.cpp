#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    while (n) {
        cnt += n / 5;
        n /= 5;
    }
    cout << cnt << endl;
    return 0;
}
