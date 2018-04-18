# include <iostream> // Ein - / Ausgabe
#include <cmath>
# define CATCH_CONFIG_RUNNER
# include "catch.hpp"


double milesToKilometer (int miles) {
  return 1.61 *miles;
  
}

TEST_CASE ("describe_milesToKilometer","[milesToKilometer]")
{
REQUIRE (milesToKilometer (4) == 6.44);
REQUIRE (milesToKilometer (9) == 14.49);
REQUIRE (milesToKilometer (7) == Approx(11.27));
}

int main (int argc , char * argv []){


//Berechnung Meilen in Kilometer
 std::cout<<"Gib bitte die Anzahl der Meilen an, die du in Kilometer umrechnen moechtest: "<<'\n';
 int miles;
 std::cin>>miles;
 std::cout<<"Ausgabe: "<<milesToKilometer(miles)<<'\n';

 //Test
return Catch :: Session (). run ( argc , argv );

return 0;

}
