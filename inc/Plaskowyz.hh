#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH

#include "BrylaGeometryczna.hh"

class Plaskowyz : public BrylaGeometryczna
{

public:

Plaskowyz(Vector3D srodek=Vector3D(), double x=50,double y=50, double z=50,std::string nazwa="../dat/Plaskowyz.dat");
Plaskowyz( Plaskowyz& pr );
  Plaskowyz &operator=(const Plaskowyz &other)
    {
     wymiaryBryly=other.wymiaryBryly;
 WierzBryly=other.WierzBryly;
  SrodekBryly=other.SrodekBryly;
  NazwaPliku=other.NazwaPliku;
        return *this;
    }
};







#endif 