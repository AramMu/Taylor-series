#include <iostream>
#include <fstream>

//using namespace std;
const double pi = 3.141592;

long long fact[20];

void initFact () {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 20; ++i) {
        fact[i] = fact[i-1] * i;
    }
}

double sinc (double x) {
    int n = 12;
    double s=0;
    double a = x*fact[n];
    int steps = n*2-1;
    int sgn = 1;
    for (int i = 1; i <= steps; i+=2) {
        s += a*sgn;
        a = a*x*x / ( (i+1)*(i+2) );
        sgn = -sgn;
    }
    return s / fact[n];
}

int main()
{
    initFact();
    //std::cout << sinc(0) << " " << sinc(pi/6) << std::endl;
    std::ofstream out;
    out.open("data/sine table.txt");

    int n = 10000;
    out << n << "\n";
    for (int i = 0; i <= n; ++i) {
        out << sinc(i*pi/2/n);
        if (i < n) out << "\n";
    }

    out.close();
    return 0;
}












