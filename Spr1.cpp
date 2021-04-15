#include<bits/stdc++.h>
using namespace std;

double calculate(double U, double I, double t)
{
    //zwrocenie iloczynu w postaci double
    return U*I*t;
}

int main()
{
    while(1)
    {
        string U_in, I_in, t_in;
        cout << "Aby obliczyc prace podaj kolejno napiecie, natezenie oraz czas w jednostkach SI oddzielone spacja:\n";
        cout << "Aby przerwac wpisz end\n";
        cin >> U_in;
        if(U_in == "end")
            return 0;
        cin >> I_in >> t_in;
        //konwersja stringow na double
        double U = stod(U_in), I = stod(I_in), t = stod(t_in);
        //przekazanie danych do funkcji
        cout << U << "V * " << I << "A * " << t << "s = " << calculate(U, I, t) <<"J\n";
    }
}