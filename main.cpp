#include "mylib.h"
#include "funkcijos.h"

int main() {

    string ivestis="tekstas.txt";
    string isvestis="rezultatai.txt";


    map<string, int>zodziuSK;
    map<string, set<int> >zodziuEil;
    vector<string> urls;

    nuskaitymas(ivestis, zodziuSK, zodziuEil);
    
    isvedimas(isvestis, zodziuSK, zodziuEil);



}