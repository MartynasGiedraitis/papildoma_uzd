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
    out<<left<<setw(15)<<"Zodis"<<left<<setw(10)<<"Kiekis"<<left<<setw(10)<<"Eilutes"<<endl;
    out<<"-----------------------------------"<<endl;
    for (const auto& [zodis, kiekis] : zodziuSK) {
        if (kiekis > 1) {
            out <<left<<setw(15)<< zodis <<left<<setw(10) << kiekis << " ";
            for (int eilNr : zodziuEil.at(zodis)) {
                out <<left<<setw(10)<< eilNr ;
            }
            out << endl;
        }
    }
    out.close();
}
void URLradimas(const string& failas){
    ifstream in(failas);
    if (!in.is_open()){
        cerr << "Nepavyko atidaryti failo: " << failas << endl;
        return;
    }

    regex url_regex("(https?://)?(www\\.)?[a-zA-Z0-9-]+\\.[a-zA-Z]{2,}(\\/([a-zA-Z0-9-]*)*)");
    set<string> urlai;
    string eilute;
    while (getline(in, eilute)){
        auto begin= sregex_iterator(eilute.begin(), eilute.end(), url_regex);
        auto end= sregex_iterator();

        for (sregex_iterator i=begin; i!=end; i++){
            string url=(*i).str();
            urlai.insert(url);
        }
    }
    cout<<"Rasti URL adresai:"<<endl;
    for (const string& url : urlai){
        cout<<url<<endl;
    }
    in.close();
}
