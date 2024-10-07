#include<iostream>
using namespace std;

struct coordonategps 
{
	int latitudine, longitudine;
	float altitudine;
	string locatie;
};

void afisarecoordonategps(coordonategps l) 
{
	cout << "Latitudine: " << l.latitudine << endl;
	cout << "Longitudine: " << l.longitudine << endl;
	cout << "Altitudine: " << l.altitudine << endl;
	cout << "Locatie: " << l.locatie << endl;
}

void modificareAltitudine(coordonategps *l, float nouaaltitudine) 
{
	l->altitudine = nouaaltitudine; //-> este deferentiere+accesare
}

void modificaAltitudineRef(coordonategps& l, float nouaaltitudine)
{
	l.altitudine = nouaaltitudine;
}

coordonategps initializare(int latitudine, int longitudine, float altitudine, string locatie) 
{
	coordonategps l;
	l.latitudine = latitudine;
	l.longitudine = longitudine;
	l.altitudine = altitudine;
	l.locatie = locatie;
	return l;
}

int main() 
{	
	afisarecoordonategps(l);

	coordonategps l2;
	cout << "Introduceti latitudinea: ";
	cin >> l2.latitudine;
	cout << "Introduceti longitudinea: ";
	cin >> l2.longitudine;
	cout << "Introduceti altitudinea: ";
	cin >> l2.altitudine;
	cout << "Introduceti locatia: ";
	cin >> l2.locatie;
	afisarecoordonategps(l2);

	modificareAltitudine(&l2, -20);
	
	modificaAltitudineRef(l2, 3000);

	afisarecoordonategps(l2);




	return 0;
}