#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Klasa bazowa
class Pojazd {
private:
    string marka;
    string model;
    int rok_produkcji;

public:
    Pojazd(string m, string mo, int rp) : marka(std::move(m)), model(std::move(mo)), rok_produkcji(rp) {}

    virtual void wyswietl(bool szczegoly) const {
        cout << "POJAZD -";
        wyswietl();
        if (szczegoly)
            cout << marka << ", " << model << ", " << rok_produkcji;
        cout << endl;

    }

    virtual ~Pojazd() = default;
};

// Klasa pochodna - Samochód
class Samochod : public Pojazd {
private:
    int liczba_drzwi;

public:
    Samochod(string m, string mo, int rp, int ld)
        : Pojazd(std::move(m), std::move(mo), rp), liczba_drzwi(ld) {}

    void wyswietl() const {
        Pojazd::wyswietl();
        cout << ", Liczba drzwi: " << liczba_drzwi << endl;
    }
};

// Klasa pochodna - Rower
class Rower : public Pojazd {
private:
    int liczba_przerzutek;

public:
    Rower(string m, string mo, int rp, int lp)
        : Pojazd(std::move(m), std::move(mo), rp), liczba_przerzutek(lp) {}

    void wyswietl() const override {
        Pojazd::wyswietl();
        cout << ", Liczba przerzutek: " << liczba_przerzutek << endl;
    }
};

int main() {
    vector<Pojazd*> pojazdy;
    int n;

    cout << "Ile pojazdów chcesz wprowadzić? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int typ;
        string marka, model;
        int rok;

        cout << "Pojazd #" << (i + 1) << ": Samochód (1) czy Rower (2)? ";
        cin >> typ;

        cout << "Podaj markę: ";
        cin >> marka;
        cout << "Podaj model: ";
        cin >> model;
        cout << "Podaj rok produkcji: ";
        cin >> rok;

        if (typ == 1) {
            int drzwi;
            cout << "Podaj liczbę drzwi: ";
            cin >> drzwi;
            pojazdy.push_back(new Samochod(marka, model, rok, drzwi));
        } else if (typ == 2) {
            int przerzutki;
            cout << "Podaj liczbę przerzutek: ";
            cin >> przerzutki;
            pojazdy.push_back(new Rower(marka, model, rok, przerzutki));
        } else {
            cout << "Nieznany typ pojazdu. Pomijam.\n";
        }
    }

    cout << "Lista pojazdów";
    for (const auto& p : pojazdy) {
        p->wyswietl();
    }

    for (auto& p : pojazdy) {
        delete p;
    }

    return 0;
}
