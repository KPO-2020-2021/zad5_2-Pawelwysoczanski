#ifndef GORA_HH
#define GORA_HH

#include "BrylaGeometryczna.hh"

class Gora : public BrylaGeometryczna
{

public:
    Gora(Vector3D SrodekBryly = Vector3D(), double x = 50, double y = 50, double z = 50, std::string NazwaPliku = "../dat/Gora.dat");
    Gora(Gora &pr);
    Gora &operator=(const Gora &other)
    {
        wymiaryBryly = other.wymiaryBryly;
        WierzBryly = other.WierzBryly;
        SrodekBryly = other.SrodekBryly;
        NazwaPliku = other.NazwaPliku;
        return *this;
    }
};

#endif