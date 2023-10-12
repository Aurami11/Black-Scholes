#include <iostream>
#include <cmath>
using namespace std;

main()
{
    double S; /* prix actuel de l'actif */
    double K; /* le prix d'exercice fixe par l'option */
    double T; /* Le temps qu'il reste à l'option avant son échéance (exprimé en années) */
    double r; /* le taux d'intérêt sans risque */
    double sigma; /* la volatilité du prix de l'action */
    double N(double);

    /* START */

    /* d1 et d2 */

    cout << "Entrez S, K, T, r, sigma : \n";
    cin >> S >> K >> T >> r >> sigma;

    const double d1 = (1/sigma*sqrt(T))*(log(S/K)+(r+(sigma*sigma)/2)*T);
    const double d2 = d1-sigma*sqrt(T);

    cout << "d1 : " << d1 << " , d2 :" << d2 << "\n";

    /* Call */

    double C = S*N(d1) - K*exp(-r*T)*N(d2);
    cout << "Prix proposable de l'option Call : " << C << "\n";
    
    /* Put */

    double P = -S*N(-d1) + K*exp(-r*T)*N(-d2);
    cout << "Prix proposable de l'option Put : " << P;
}

double N(double z)
{
    if (z > 6.0)
        return 1.0; // éviter les valeurs illicites
    if (z < -6.0)
        return 0.0;
    double b1 = 0.31938153;
    double b2 = -0.356563782;
    double b3 = 1.781477937;
    double b4 = -1.821255978;
    double b5 = 1.330274429;
    double p = 0.2316419;
    double c2 = 0.3989423;
    double a=fabs(z);
    double t = 1.0/(1.0+a*p);
    double b = c2*exp((-z)*(z/2.0));
    double n = ((((b5*t+b4)*t+b3)*t+b2)*t+b1)*t;
    n = 1.0-b*n;
    if ( z < 0.0 )
        n = 1.0 - n;
    return n;
}
