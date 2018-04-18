# include <iostream> // Ein - / Ausgabe
#include <cmath>
# define CATCH_CONFIG_RUNNER
# include "catch.hpp"


int gcd (int a , int b) {  //ggt
    int r=0;
    int temp=0;

if (a<b) {
    temp= b;
    b =a;
    a = temp;
}
if (a>b) {
    temp =a;
    a = b;
    b = temp;
}
while(true) {
     r = a%b;
     if(r ==0) {
         break;
     }
     a =b;
     b =r;
}
return b;
}

TEST_CASE ("describe_gcd","[gcd]")
{
REQUIRE (gcd (2 ,4) == 2);
REQUIRE (gcd (9 ,6) == 3);
REQUIRE (gcd (3 ,7) == 1);
}



long int sumMultiples() {
    long int sum=0;
    for(int i=3;i<=1000;++i) {
        if (i%3 ==0 || i%5 ==0) {
            sum+=i;
        }
    }
        return sum;
}

double surface (double r, double h) {  //Oberfläche Zylinder
    return 2*M_PI*r*(r+h);
}

TEST_CASE ("describe_surface","[surface]")
{
REQUIRE (surface (2 ,4) == 75.39822369);
REQUIRE (surface (9 ,6) == 848.2300165);
REQUIRE (surface (3 ,7) == 188.4955592);
}

double volume (double r, double h) {   //Volumen Zylinder
    return  M_PI*sqrt(r)*h;
   
}

TEST_CASE ("describe_volume","[volume]")
{
REQUIRE (volume (2 ,4) == 50.26548246);
REQUIRE (volume (9 ,6) == 1526.81403);
REQUIRE (volume (3 ,7) == 197.9203372);
}



int smallest_Number () {
    int x =2;
    int number =20;
    while (x < 21) {
        if (number%x == 0) {
            x+=1;
        } else {
            number += 20;
            x =2;
        }
    }
    return number;
}

bool is_prime (int p) {
    int i;
    if(p==1)
      return false;
    for (i = 2; i < p; i++)
    {
      if (p%i == 0) 
      return false;
    }
    if (i == p) 
    return true;

  }

TEST_CASE ("describe_is_prime","[is_prime]")
{
REQUIRE (is_prime (4) == false);
REQUIRE (is_prime (9) == false);
REQUIRE (is_prime (7) == true);
}

double fract (double d) {
    return (d - (int)d);
}
TEST_CASE ("describe_fract","[fract]")
{
REQUIRE(fract (1645.9753) == Approx(0.9753));
REQUIRE(fract (2.564) == Approx(0.564));
REQUIRE(fract (5.75)  == Approx(0.75));
}


int checksum (double c) {
    int j = c;
    int m =0;
    int sum =0;
    while(j>0) {
        m=j%10;
        sum +=m;
        j = j/10;
    }
    return sum;
}

TEST_CASE ("describe_checksum","[checksum]")
{
REQUIRE (checksum (117073) == 19);
REQUIRE (checksum (923464) == 28);
REQUIRE (checksum (73) == 10);
}



long int factorial (int f) {
    if (f<=1) {
        return 1;
    }
    else if (f<0) {
        std::cout<<"Invalide Eingabe. Bitte nur positive Zahlen eingeben!"<<'\n';
    }
    else {
        return (factorial(f-1)*factorial(f));
    }
}


TEST_CASE ("describe_factorial","[factorial]")
{
REQUIRE (factorial (4) == 24);
REQUIRE (factorial (9) == 362880);
REQUIRE (factorial (1) == 1);
}


long int binomial (int n, int k) {
    if (n==0 || k == 0) {
        return -1;
    }
    else {
         return (factorial(n) / (factorial(k)*factorial(n-k)));
    }
}

TEST_CASE ("describe_binomial","[binomial]")
{
REQUIRE (binomial (0,0) == -1);
REQUIRE (binomial (9,5) == 126);
REQUIRE (binomial (7,6) == 7);
}



int main (int argc , char * argv []){

//std :: cout << " Hello, World!\n";



 //Berechnung ggt
std::cout<<"Bitte gib zwei Zahlen zur Berechnung des ggt ein: \n";
int a;
int b;
std::cin>>a;
std::cin>>b;
std::cout<<"Der ggt von "<<a<<" und "<<b<<" lautet "<<gcd(a,b)<<'\n'; 


//Summe
std::cout<<"Die Summe der Zahlen von 1 bis 1000, die entwerder durch 3 oder 5 teilbar sind, lautet: "<<sumMultiples()<<'\n';  

//Zylinder
 std::cout<< "Bitte geben Sie den Radius und die Höhe des Zylinders an: "<<'\n';  
 double r;
 double h;
 std::cin>>r; 
 std::cin>>h;
 std::cout<<"Die Oberflaeche betraegt: "<<surface(r,h)<<'\n';
 std::cout<<"Das Volumen betraegt: "<<volume(r,h)  <<'\n';

 //KgV von 1 bis 20
 std::cout<<"Die kleinste Zahl, die durch 1 bis 20 teilbar ist, lautet: "<<smallest_Number()<<'\n';



// Primzahl
 std::cout<< "Bitte geben Sie eine Zahl für die Primzahlüberprüfung ein: "<<'\n';  
 int p;
 std::cin>>p;
 
if(is_prime(p) == false) {
    std::cout<<"Es handelt sich um keine Primzahl."<<'\n';
}
else {
    std::cout<<"Es handelt sich um eine Primzahl."<<'\n';  
}

//Fract
std::cout<<"Bitte gib eine Kommazahl an um die Nachkommastellen zu bestimmen: \n";
double d;
std::cin>>d;
std::cout<<"Die Nachkommastellen lauten "<<fract(d)<<'\n'; 


//Fakultät 
std::cout<<"Bitte gib eine Zahl für die Fakultät ein: \n";
int f;
std::cin>>f;
std::cout<<"Die Fakultät von "<<f<<" beträgt "<<factorial(f)<<'\n'; 

//Quersumme
std::cout<<"Bitte gib eine Zahl für die Quersumme ein: "<<'\n';
int c;
std::cin>>c;
std::cout<<"Die Quersumme lautet: "<<checksum(c)<<'\n';

// Binomialkoeffizient
std::cout<<"Bitte gib zwei Zahlen zur Berechnung des Binomialkoeffizienten ein: \n";
int n;
int k;
std::cin>>n;
std::cin>>k;

if (binomial(n,k) == -1) {
    std::cout<<"Invalide Eingabe."<<'\n';
}
else {
   std::cout<<"Das Ergebnis lautet: "<<binomial(n,k)<<'\n'; 
}

//Test
return Catch :: Session (). run ( argc , argv );

return 0;

}
