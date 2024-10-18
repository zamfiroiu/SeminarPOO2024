//#include<iostream>
//using namespace std;
//
//struct Apartament {
//	char* adresa;
//	string proprietar;
//	int nrCamere;
//	float suprafata;
//};
//
//void afisareApartament(Apartament* ap) {
//	cout << "Adresa:" << ap->adresa << endl;
//	cout << "Proprietar:" << ap->proprietar << endl;
//	cout << "Numar camere:" << ap->nrCamere << endl;
//	cout << "Suprafata:" << ap->suprafata << endl;
//}
//
//Apartament citireApartament() {
//	Apartament ap;
//	cout << "Adresa:";
//	char buffer[100];
//	cin >> buffer;
//	ap.adresa = new char[strlen(buffer) + 1];
//	strcpy_s(ap.adresa, strlen(buffer) + 1, buffer);
//	cout << "Proprietar:";
//	cin >> ap.proprietar;
//	cout << "Numar camere:";
//	cin >> ap.nrCamere;
//	cout << "Suprafata:";
//	cin >> ap.suprafata;
//	return ap;
//}
//
//int main() {
//	Apartament ap;
//	ap.nrCamere = 3;
//
//	Apartament* pointer;
//	pointer = new Apartament();
//	pointer->nrCamere = 5;
//	pointer->proprietar = "Gigel";
//	pointer->adresa = new char[strlen("Bucuresti")+1];
//	strcpy_s(pointer->adresa, strlen("Bucuresti") + 1, "Bucuresti");
//	pointer->suprafata = 120;
//
//	afisareApartament(pointer);
//
//	delete pointer;
//
//	int nrApartamente = 2;
//	Apartament *apartamente;
//	apartamente = new Apartament[nrApartamente];
//	for (int i = 0; i < nrApartamente; i++) {
//		apartamente[i] = citireApartament();
//	}
//
//	for (int i = 0; i < nrApartamente; i++) {
//		afisareApartament(&(apartamente[i]));
//	}
//
//	for (int i = 0; i < nrApartamente; i++) {
//		delete[]apartamente[i].adresa;
//	}
//	delete[]apartamente;//82 - 92
//
//	//Apartament** pointeri;
//	//pointeri = new Apartament*[3];
//
//
//
//	return 0;
//}