#include <iostream>
using namespace std;

int nwd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
	cout <<"podaj liczbe liczb";
    int n;
    cin >> n;
	cout <<"podaj liczby";

    int wynik;
    cin >> wynik; 

    for (int i = 1; i < n; ++i) {
        int liczba;
        cin >> liczba;
        wynik = nwd(wynik, liczba);
    }

    cout << wynik << endl;

    return 0;
}
