//#include<iostream>
//
//using namespace std;
//
//class Angajat {
//protected:
//	int marca;
//	string nume;
//	float salariu;
//
//public:
//	Angajat() {
//		this->marca = 1234;
//		this->nume = "No Name";
//		this->salariu = 3000;
//	}
//	Angajat(int marca, string nume,float salariu) {
//		this->marca = marca;
//		this->nume = nume;
//		this->salariu = salariu;
//	}
//	float getSalariu() {
//		return this->salariu;
//	}
//	virtual float getVenitIncasat() = 0;
//
//};
//
//class Cercetator : public Angajat {
//public:
//	Cercetator(int marca, string nume, float salariu) :Angajat(marca, nume, salariu) {
//
//	}
//	float getVenitIncasat() {
//		return this->salariu;
//	}
//};
//
//class Manager:public Angajat {
//private: 
//	int nrSubordonati;
//	float sporPerSubordonat;
//
//public:
//	Manager() :Angajat() {
//		this->nrSubordonati = 0;
//		this->sporPerSubordonat = 0;
//	}
//	Manager(int nrSubordonati, float sporPerSubordonat):Angajat()
//	{
//		this->nrSubordonati = nrSubordonati;
//		this->sporPerSubordonat = sporPerSubordonat;
//	}
//	float getSporConducere() {
//		return this->nrSubordonati * this->sporPerSubordonat;
//	}
//};
//
//class ManagerDepartament :public Manager {
//private:
//	string numeDepartament;
//	bool deCercetare;
//public:
//	ManagerDepartament() :Manager() {
//		this->numeDepartament = "Departament";
//		this->deCercetare = false;
//	}
//	ManagerDepartament(string nume, bool deCercetare, int nrSubrodoanti, float sporPerSubordonat) :Manager(nrSubrodoanti, sporPerSubordonat) {
//		this->numeDepartament = nume;
//		this->deCercetare = deCercetare;
//	}
//
//	float getVenitIncasat() {
//		float venit = this->salariu;
//		venit += this->getSporConducere();
//		if (this->deCercetare) {
//			venit += (10 / 100) * salariu;
//		}
//		return venit;
//	}
//};
//
//class MangerDeProiect :public Manager {
//private:
//	string numeProiect;
//	int nrZile;
//	float sporPerZi;
//public:
//	MangerDeProiect() :Manager() {
//		this->numeProiect = "Project";
//		this->nrZile = 0;
//		this->sporPerZi = 0;
//	}
//	MangerDeProiect(string nume, int nrZile, float sporPerZi, int nrSubordonati, float sporPerSubordonat) :Manager(nrSubordonati, sporPerSubordonat) {
//		this->numeProiect = nume;
//		this->nrZile = nrZile;
//		this->sporPerZi =sporPerZi;
//	}
//	float getVenitIncasat() {
//		float venit = this->salariu;
//		venit += this->getSporConducere();
//		venit += (this->nrZile * this->sporPerZi);
//		return venit;
//	}
//};
//
//int main() {
//	//Angajat a; //nu avem voie sa instatiem o clasa abstract
//
//	//Manager m;//la fel ca mai sus
//
//	ManagerDepartament md;
//	MangerDeProiect mdp;
//
//
//	Angajat* pointer;
//	pointer = NULL;
//	pointer = new ManagerDepartament();
//	pointer->getVenitIncasat();
//
//	int nrAngajati = 5;
//	Angajat** vector = new Angajat * [nrAngajati];
//	vector[0] = new ManagerDepartament();
//	vector[1] = new MangerDeProiect();
//	vector[2] = new MangerDeProiect("TODO list", 10, 30, 3, 15);
//	vector[3] = new ManagerDepartament("AI", true, 10, 15);
//	vector[4] = new Cercetator(9876,"Popescu",6000);
//
//	for (int i = 0; i < nrAngajati; i++) {
//		cout <<(i+1)<<". " << vector[i]->getVenitIncasat() << endl;
//	}
//
//	return 5435;
//}