#include <iostream>
#include "Simulator.cpp"
#include <cmath>
#include <vector>

const int symulacje =2000;

double odchylenie_standardowe(double tab[], double srednia)
{
    double suma_kwadratow = 0.0;
    for(int i = 0; i < symulacje; i++)
    {
        suma_kwadratow += (tab[i] - srednia) * (tab[i] - srednia);
    }

    double pom = suma_kwadratow / symulacje;

    double odchylenie = sqrt(pom);
    return odchylenie;
}

int main() {

    Simulator symulator;
    double *tab = new double[symulacje];
    double suma=0.0;
    for (int i=0; i<symulacje; i++)
    {
        tab[i]=symulator.run();
        suma+=tab[i];
    }
    double srednia = suma/=symulacje;

    double odchylenie =odchylenie_standardowe(tab,srednia);
    cout << "srednia: " << srednia << endl;
    cout << "Odchylenie standardowe: " << odchylenie << endl;
}