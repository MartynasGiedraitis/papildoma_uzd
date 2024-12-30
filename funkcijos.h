#include "functions.h"

void nuskaitymas(const string&failas, map<string, int>&zodziai, map<string, set<int>>&zodziaiEil){
    ifstream in(failas);
    string eilute;
    int eilNr=1;
    while(getline(in, eilute)){
        istringstream iss(eilute);
        string zodis;
        while(iss>>zodis){
            string teisingasZodis;
            for(char c:zodis){
                if(isalpha(c)){
                    teisingasZodis+=tolower(c);
                }
            }
            bool arTinka=any_of(teisingasZodis.begin(), teisingasZodis.end()), [](char c)
            {return isalpha(c);});

            if (arTinka){
                zodziai[teisingasZodis]++;
                zodziaiEil[teisingasZodis].insert(eilNr);
            }
        }
        eilNr++;
    }
    failas.close();
}