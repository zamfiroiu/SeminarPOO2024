//#include<iostream>
//
//using namespace std;
//
//struct Masina {
//	int nrUsi;
//	bool esteElectrica;
//	float capacitateMotor;
//	string model;
//};
//
//void afisareMasina(Masina masina) {
//	cout << "Model:" << masina.model << endl;
//	cout << "Numar usi:" << masina.nrUsi << endl;
//	cout << "Capacitate motor:" << masina.capacitateMotor << endl;
//	cout << "Este electrica:" << (masina.esteElectrica == true ? "DA" : "NU") << endl;
//}
//
//void modificaNumarUsi(Masina *masina, int nrUsi) {
//	masina->nrUsi = nrUsi;
//}
//
//void modificaNumarUsiRef(Masina& masina, int nrUsi) {
//	masina.nrUsi = nrUsi;
//}
//
//int main() {
//	Masina masina;
//	masina.nrUsi = 5;
//	masina.esteElectrica = false;
//	masina.capacitateMotor = 1.5;
//	masina.model = "Audi Q3";
//
//	afisareMasina(masina);
//
//	Masina masina2;
//	cout << "Introduceti modelul:";
//	cin >> masina2.model;
//
//	cout << "Introduceti capacitate motor:";
//	cin >> masina2.capacitateMotor;
//
//	cout << "Introduceti numarul de usi:";
//	cin >> masina2.nrUsi;
//
//	cout << "Masina este electrica (1 - DA; 0 - NU):";
//	cin >> masina2.esteElectrica;
//
//	afisareMasina(masina2);
//	modificaNumarUsi(&masina2, 6);
//	modificaNumarUsiRef(masina2, 8);
//	afisareMasina(masina2);
//	
//	return 0;
//}
