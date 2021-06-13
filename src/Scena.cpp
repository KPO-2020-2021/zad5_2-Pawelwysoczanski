#include "Scena.hh"

/*!
*\brief 
* Tworzy scene po ktorej poruszac sie beda drony.
*/
Scena::Scena()
{

  Lacze.ZmienTrybRys(PzG::TR_3D);
  nrElem = 0;
  nrDrona = 0;
  Lacze.UstawZakresY(-300, 300);
  Lacze.UstawZakresX(-300, 300);
  Lacze.UstawZakresZ(-300, 300);

  double tab_wym[3] = {600, 600, 0};
  Vector3D wym_dna(tab_wym);
  dno = new Plaszczyzna(wym_dna, 20);
  Vector3D srod;
  for (int i = 0; i < 4; i++)
  {
    srod[0] = rand() % 400 - 200;
    srod[1] = rand() % 400 - 200;
    srod[2] = 50;
    int nrP = rand() % 3;
    if (nrP == 0)
      ListaElemt.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
    else if (nrP == 1)
      ListaElemt.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
    else if (nrP == 2)
      ListaElemt.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
    nrElem++;
  }
  for (std::list<std::shared_ptr<BrylaGeometryczna>>::const_iterator a = ListaElemt.begin(); a != ListaElemt.end(); a++)
  {
    Lacze.DodajNazwePliku((*a)->GetNazwaPliku().c_str());
    (*a)->Zapisz();
  }

  Lacze.DodajNazwePliku(dno->GetNazwa().c_str());
  dno->zapisz();
  for (int i = 0; i < N; i++)
  {
    double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
    TabDronow.push_front(std::make_shared<Dron>(i, Lacze, Vector3D(pozycja)));
    (*TabDronow.begin())->Zapisz();
    nrDrona++;
  }

  Lacze.Rysuj();
}
/*!
*\brief 
*Rysuje Scene 
*/
void Scena::Rysuj()
{

  Lacze.Rysuj();
}
/*!
*\brief 
* Metoda powoduje przejscie do sterowania dronem ktorego numer zostal podany metodzie Interfejs() 
*/

/*!
*\brief 
* Wykonuje przelot drona nr 2 po okregu.
*/

/*!
*\brief 
* Umozliwia wybor drona.
*/
bool Scena::Interfejs()
{
  std::cout << "a - wybierz aktywnego drona" << std::endl;
  std::cout << "p - zadaj parametry przelotu" << std::endl;
  std::cout << "d - dodaj element powierzchni" << std::endl;
  std::cout << "u - usun element powierzchni" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl
            << std::endl;
  std::cout << "k - koniec dzialania programu" << std::endl;
  std::cout << std::endl;
  char opcja;
  cin >> opcja;
  switch (opcja)
  {
  case 'a':
    std::cout << "Podaj numer drona ktorego chcesz aktywowac mozliwosci 1 lub 2" << std::endl;
    
    break;
  case 'p':
    break;
  case 'd':
    break;
  case 'u':
    break;
  case 'm':
    std::cout << "a - wybierz aktywnego drona" << std::endl;
    std::cout << "p - zadaj parametry przelotu" << std::endl;
    std::cout << "d - dodaj element powierzchni" << std::endl;
    std::cout << "u - usun element powierzchni" << std::endl;
    std::cout << "m - wyswietl menu" << std::endl
              << std::endl;
    std::cout << "k - koniec dzialania programu" << std::endl;
    std::cout << std::endl;
    break;
  default:
    break;
  }

  return true;
}
/*!
*\brief 
* Usuwa tablice dronow.
*/
Scena::~Scena()
{
  free(dno);
}