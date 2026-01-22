#include <iostream>
using namespace std;

int main() {

    const int MAX = 10000000;
    bool asal[MAX + 1];

    // Baslangic
    for (int i = 0; i <= MAX; i++) {
        asal[i] = true;
    }

    asal[0] = false;
    asal[1] = false;

    // Eratosthenes Eleigi
    for (int i = 2; i * i <= MAX; i++) {
        if (asal[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                asal[j] = false;
            }
        }
    }

    int pencere = 100;

    cout << "k  2^k  OncekiAsal  SonrakiAsal  AraliktakiAsal\n";

    int ikiUssu = 2;
    int k = 1;

    while (ikiUssu <= MAX) {

        int onceki = ikiUssu - 1;
        while (onceki > 1 && asal[onceki] == false) {
            onceki--;
        }

        int sonraki = ikiUssu + 1;
        while (sonraki <= MAX && asal[sonraki] == false) {
            sonraki++;
        }

        int sayac = 0;
        for (int i = ikiUssu - pencere; i <= ikiUssu + pencere; i++) {
            if (i >= 2 && i <= MAX && asal[i]) {
                sayac++;
            }
        }

        cout << k << "  "
             << ikiUssu << "  "
             << onceki << "        "
             << sonraki << "         "
             << sayac << endl;

        ikiUssu = ikiUssu * 2;
        k++;
    }

    return 0;
}
