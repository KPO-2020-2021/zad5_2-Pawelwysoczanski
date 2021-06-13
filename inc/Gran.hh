#ifndef GRAN_HH
#define GRAN_HH

#include "BrylaGeometryczna.hh"

class Gran : public BrylaGeometryczna
{

public:
    Gran(Vector3D SrodekBryly = Vector3D(), double x = 50, double y = 50, double z = 50, std::string NazwaPliku = "../dat/Gran.dat");
    Gran(Gran &pr);
    Gran &operator=(const Gran &other)
    {
        wymiaryBryly = other.wymiaryBryly;
        WierzBryly = other.WierzBryly;
        SrodekBryly = other.SrodekBryly;
        NazwaPliku = other.NazwaPliku;
        return *this;
    }
};

#endif