#include "mylib.h"

int main() {

    string ivestis="tekstas.txt";
    string isvestis="rezultatai.txt";


    map<string, int>zodziuSK;
    map<string, set<int>>zodziuEil;
    vector<string> urls;

    nuskaitymas(ivestis, zodziuSK, zodziuEil);
    isvestis(isvestis, zodziuSK, zodziuEil);



}