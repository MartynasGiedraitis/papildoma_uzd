#include "mylib.h"
#include "funkcijos.h"

int main() {

    string ivestis="tekstas.txt";
    string isvestis="rezultatai.txt";
    string URL="URL.txt";

    map<string, int>zodziuSK;
    map<string, set<int> >zodziuEil;

    nuskaitymas(ivestis, zodziuSK, zodziuEil);
    isvedimas(isvestis, zodziuSK, zodziuEil);
    URLradimas(URL);


}