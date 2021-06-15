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
* Odpowiada za interfejs sterowania programem.
*/
bool Scena::Interfejs(char opcja)
{
  switch (opcja)
  {
  case 'a':
  {
    cout << "Podaj nr drona ktorego chcesz aktywowac " << endl;
    for (int i = 0; i < (int)TabDronow.size(); i++)
    {
      cout << i << " " << endl;
    }
    cout << ":" << endl;
    int nr;
    cin >> nr;
    Drona = TabDronow.begin();
    for (int i = 0; i < nr; i++)
    {
      Drona++;
    }
    cout << "Dron " << nr << " aktywny" << endl;
  }
  break;
  case 'p':
    (*Drona)->Sterowanie();
    break;
  case 'd':
  {
    cout << "Ktory element chcesz dodac podaj 1-gora, 2-plaskowyz, 3 gran, 4 dron" << endl;

    int nr;
    cin >> nr;
    Vector3D srod;

    srod[0] = rand() % 400 - 200;
    srod[1] = rand() % 400 - 200;
    srod[2] = 50;

    if (nr != 4)
    {
      if (nr == 1)
      {

        ListaElemt.push_front(std::make_shared<Gora>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
      }
      if (nr == 2)
      {

        ListaElemt.push_front(std::make_shared<Plaskowyz>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
      }
      if (nr == 3)
      {

        ListaElemt.push_front(std::make_shared<Gran>(srod, 100, 50, 100, "../dat/Element" + std::to_string(nrElem) + ".dat"));
      }
      nrElem++;
      (*ListaElemt.begin())->Zapisz();
      Lacze.DodajNazwePliku((*ListaElemt.begin())->GetNazwaPliku().c_str());
    }
    else
    {
      double pozycja[3] = {(double)(rand() % 440 - 220), (double)(rand() % 440 - 220), 25};
      TabDronow.push_front(std::make_shared<Dron>(nrDrona, Lacze, Vector3D(pozycja)));
      (*TabDronow.begin())->Zapisz();
    }
  }
  break;
  case 'u':
  {
    int i = 0;
    for (std::list<std::shared_ptr<BrylaGeometryczna>>::const_iterator a = ListaElemt.begin(); a != ListaElemt.end(); a++)
    {
      cout << i << ": " << (*a)->GetNazwaPliku() << endl;
      i++;
    }
    cout << "Podaj numer elementu ktory chcesz usunac" << endl;

    int nr;
    cin >> nr;
    std::list<std::shared_ptr<BrylaGeometryczna>>::const_iterator a = ListaElemt.begin();

    for (int j = 0; j < nr; j++)
    {

      a++;
    }

    Lacze.UsunNazwePliku((*a)->GetNazwaPliku());
    ListaElemt.erase(a);
  }
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