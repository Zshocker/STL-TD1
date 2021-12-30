#include "Perssonne.h"

Personne::Personne(string n, string add, string nume)
{
	nom = n;
	addr = add;
	num = nume;
}

void Personne::Afficher_add_num()
{
	cout << " Address:" <<this->addr << " Numero : " << this->num << endl;
}
