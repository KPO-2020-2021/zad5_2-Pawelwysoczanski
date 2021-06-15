#include "Plaskowyz.hh"
    /*!
*\brief Konstruktor parametryczny klasy Plaksowyz.
*/
Plaskowyz::Plaskowyz(Vector3D srodek, double x,double y, double z,std::string NazwaPliku)
{
    double tab[]={x,y,z};
    wymiaryBryly=std::make_shared<Vector3D> (tab);
    this->NazwaPliku=NazwaPliku;
  this->SrodekBryly=srodek;
  Vector3D punkt;

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]+(z/2);
  WierzBryly.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  WierzBryly.push_back(punkt);


  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]+(z/2);
  WierzBryly.push_back(punkt);

  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]+(y/2);
  punkt[2]=srodek[2]-(z/2);
  WierzBryly.push_back(punkt);

   punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]+(z/2);
  WierzBryly.push_back(punkt);

  punkt[0]=srodek[0]+(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  WierzBryly.push_back(punkt);


  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]+(z/2);
  WierzBryly.push_back(punkt);

  punkt[0]=srodek[0]-(x/2);
  punkt[1]=srodek[1]-(y/2);
  punkt[2]=srodek[2]-(z/2);
  WierzBryly.push_back(punkt);

}
    /*!
*\brief Tworzy kopie elementu klasy Plaskowyz.
*/
Plaskowyz::Plaskowyz( Plaskowyz& pr )
{
   wymiaryBryly=pr.wymiaryBryly;
 WierzBryly=pr.WierzBryly;
  SrodekBryly=pr.SrodekBryly;
  NazwaPliku=pr.NazwaPliku;
}