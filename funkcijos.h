#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include "mylib.h"

void nuskaitymas(const string&failas, map<string, int>&zodziuSK, map<string, set<int> >&zodziaiEil);
void isvedimas(const string& failas, const map<string, int>& zodziuSK, const map<string, set<int> >& zodziuEil);
void URLradimas(const string& failas);

#endif // FUNKCIJOS_H_INCLUDED