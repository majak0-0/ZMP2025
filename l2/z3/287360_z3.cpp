#include <iostream>
using namespace std;

int main() {
    int klucz[8], wiadomosc[8];
    cout << "Podaj klucz";
    for (int i = 0; i < 8; i++) cin >> klucz[i];     
	cout << "Podaj wiadomosc";
    for (int i = 0; i < 8; i++) cin >> wiadomosc[i];  

    for (int i = 0; i < 8; i++) 
        cout << (klucz[i] ^ wiadomosc[i]) << " ";     

    return 0;
}
