#include <iostream>
using namespace std;

int main() {
	int x, n;
	cout << "podaj szukana liczbe";
    cin >> x;
	cout << "podaj dlugosc ciagu";
	cin >> n;

    cout << "podaj ciag";
    int liczba;
    for (int i =0; i < n; i++) {
        cin >> liczba;
        if (liczba == x) {
            cout << "tak " << i;
            return 0;
        }
    }

    cout << "nie";
    return 0;
}
