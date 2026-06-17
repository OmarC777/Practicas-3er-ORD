#include "fractales.h"
#include <iostream>
#include <math.h>

using namespace std;

int fractales::nElemsLvl(int n)
{
    if(n < 0){return 0;}
    if(n == 0){return 1;}
    return nElemsLvl(n-1)*3 + 2;
}

int Cantor::nElemsLvl(int n, int d)
{
    if(n < 0){return 0;}
    if(n == 0){return 1;}
    return pow(2, d)*nElemsLvl(n - 1, d);
}
