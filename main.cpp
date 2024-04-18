#include <iostream>
#include <fstream>

using namespace std;

int liczSlowaKonczaceSieNaA(ifstream& plik) {
    int liczbaSlowZakonczonychNaA = 0;
    string slowo;
    while (plik >> slowo) {
        int dlugosc = slowo.length();
        if (dlugosc > 0 && slowo[dlugosc - 1] == 'A') {
            liczbaSlowZakonczonychNaA++;
        }
    }
    return liczbaSlowZakonczonychNaA;
}

int liczWierszeZParamiSlow(ifstream& plik) {
    int liczbaWierszy = 0;
    string slowo1, slowo2;
    while (plik >> slowo1 >> slowo2) {
        bool jestParaSlow = false;
        int dlugosc1 = slowo1.length();
        int dlugosc2 = slowo2.length();

        if (dlugosc1 <= dlugosc2) {
            bool pasuje = true;
            for (int i = 0; i < dlugosc1; ++i) {
                if (slowo1[i] != slowo2[i]) {
                    pasuje = false;
                    break;
                }
            }
            if (pasuje) {
                jestParaSlow = true;
            }
        }
        if (jestParaSlow) {
            liczbaWierszy++;
        }
    }
    return liczbaWierszy;
}

string sortujLitery(string slowo) {
    int n = slowo.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (slowo[j] > slowo[j + 1]) {
                char temp = slowo[j];
                slowo[j] = slowo[j + 1];
                slowo[j + 1] = temp;
            }
        }
    }
    return slowo;
}

int liczAnagramy(ifstream& plik) {
    int liczbaAnagramow = 0;
    string slowo1, slowo2;
    while (plik >> slowo1 >> slowo2) {
        string posortowane1 = sortujLitery(slowo1);
        string posortowane2 = sortujLitery(slowo2);
        if (posortowane1 == posortowane2) {
            liczbaAnagramow++;
        }
    }
    return liczbaAnagramow;
}

int main() {
    ifstream plik("slowa.txt");
    int liczbaSlowA = liczSlowaKonczaceSieNaA(plik);
    plik.close();
    plik.open("slowa.txt");
    int liczbaWierszyZParamiSlow = liczWierszeZParamiSlow(plik);
    plik.close();
    plik.open("slowa.txt");
    int liczbaAnagramow = liczAnagramy(plik);
    plik.close();
    cout << "Liczba slow w pliku slowa.txt konczacych sie na litere A: " << liczbaSlowA << endl;
    cout << "Liczba wierszy z parami slow w pliku slowa.txt: " << liczbaWierszyZParamiSlow << endl;
    cout << "Liczba wierszy w pliku slowa.txt zawierajacych pary slow, z ktorych pierwsze slowo jest anagramem drugiego: " << liczbaAnagramow << endl;

    return 0;
}
