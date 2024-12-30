#include "funkcijos.h"

string valymas(const string& zodis) {
    string teisingasZodis;
    for (char c : zodis) {
        if (isalpha(static_cast<unsigned char>(c))) {
            teisingasZodis +=tolower(static_cast<unsigned char>(c));
        }
    }
    return teisingasZodis;
}
void nuskaitymas(const string& failas, map<string, int>& zodziuSK, map<string, set<int> >& zodziuEil) {
    ifstream in(failas);
    if (!in.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failas << endl;
        return;
    }

    string eilute;
    int eilNr = 1;
    while (getline(in, eilute)) {
        istringstream iss(eilute);
        string zodis;
        while (iss >> zodis) {
            string teisingasZodis = valymas(zodis);
            if (!teisingasZodis.empty()) {
                zodziuSK[teisingasZodis]++;
                zodziuEil[teisingasZodis].insert(eilNr);

            }
        }
        eilNr++;
    }
    in.close();
}
void isvedimas(const string& failas, const map<string, int>& zodziuSK, const map<string, set<int> >& zodziuEil) {
    ofstream out(failas);
    if (!out.is_open()) {
        cerr << "Nepavyko atidaryti failo: " << failas << endl;
        return;
    }

    for (const auto& [zodis, kiekis] : zodziuSK) {
        if (kiekis > 1) {
            out << zodis << " " << kiekis << " ";
            for (int eilNr : zodziuEil.at(zodis)) {
                out << eilNr << " ";
            }
            out << endl;
        }
    }
    out.close();
}
