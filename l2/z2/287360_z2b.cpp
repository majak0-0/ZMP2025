#include <iostream>
using namespace std;

int main() {
	cout << "podaj szukana liczbe";
    int x;
    cin >> x;
	cout << "podaj dlugosc ciagu";
	int n;
	cin >> n;

    cout << "podaj ciag";
int tab[1000];
    for (int i = 0; i < n; i++) cin >> tab[i];

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (tab[mid] == x) {
            cout << "tak " << mid;
            return 0;
        } else if (tab[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "nie";
    return 0;
}