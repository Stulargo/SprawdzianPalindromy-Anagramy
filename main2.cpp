#include <iostream>
#include <fstream>

using namespace std;

int liczA(string zdanie) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak == 'a' || znak == 'A') {
            licznik++;
        }
    }
    return licznik;
}

int liczSpacje(string zdanie) {
    int licznik = 0;
    for (char znak : zdanie) {
        if (znak == ' ') {
            licznik++;
        }
    }
    return licznik;
}

string zamienE(string zdanie) {
    for (char& znak : zdanie) {
        if (znak == 'e') {
            znak = '$';
        }
    }
    return zdanie;
}

string ostatniWyraz(string zdanie) {
    string ostatni = "";
    for (int i = zdanie.length() - 1; i >= 0; i--) {
        if (zdanie[i] == ' ') {
            break;
        }
        else {
            ostatni = zdanie[i] + ostatni;
        }
    }
    return ostatni;
}

bool czyPalindrom(string slowo) {
    int dlugosc = slowo.length();
    for (int i = 0; i < dlugosc / 2; i++) {
        if (slowo[i] != slowo[dlugosc - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string zdanie;
    ofstream plik("zmienione.txt");
    int sumaSpacjiGlobalnie = 0;

    for (int i = 0; i < 5; ++i) {
        cout << "Podaj zdanie " << i+1 << ": ";
        getline(cin, zdanie);

        int liczbaLiterA = liczA(zdanie);
        int spacjeWZdaniu = liczSpacje(zdanie);
        sumaSpacjiGlobalnie += spacjeWZdaniu;

        string ostatni = ostatniWyraz(zdanie);
        if (czyPalindrom(ostatni)) {
            cout << "Liczba liter 'a': " << liczbaLiterA << " Ostatni wyraz: " << ostatni << " - 1" << endl;
        } else {
            cout << "Liczba liter 'a': " << liczbaLiterA << " Ostatni wyraz: " << ostatni << " - 0" << endl;
        }

        // Zamie� litery 'e' na '$' i zapisz zmienione zdania do pliku
        plik << zamienE(zdanie) << endl;
    }

    cout << "Liczba wszystkich spacji: " << sumaSpacjiGlobalnie << endl;

    plik.close();

    return 0;
}

