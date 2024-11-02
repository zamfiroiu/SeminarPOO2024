//#include<iostream>
//
//using namespace std;
//
//class Cofetarie {
//private:
//	string nume; //
//	int nrAngajati;//
//	float* salarii;
//	bool esteVegana;
//	const int anDeschidere;
//	float adaos;
//	static int TVA;
//
//public:
//	Cofetarie() : adaos(30), anDeschidere(2024) {
//		this->nume = "Delice";
//		this->nrAngajati = 0;
//		this->esteVegana = true;
//		this->salarii = NULL;
//	}
//
//	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
//		this->nume = nume;
//		this->nrAngajati = nrAngajati;
//		this->esteVegana = vegan;
//		this->adaos = adaos;
//		this->salarii = new float[nrAngajati];
//		for (int i = 0; i < nrAngajati; i++) {
//			this->salarii[i] = 1000 + i * 100;
//		}
//	}
//
//	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
//		this->nume = c.nume;
//		this->nrAngajati = c.nrAngajati;
//		this->salarii = new float[c.nrAngajati];
//		for (int i = 0; i < c.nrAngajati; i++) {
//			this->salarii[i] = c.salarii[i];
//		}
//		this->esteVegana = c.esteVegana;
//		this->adaos = c.adaos;
//	}
//	Cofetarie operator=(const Cofetarie& c) {
//		if (&c != this) {
//			this->nume = c.nume;
//			this->nrAngajati = c.nrAngajati;
//			if (this->salarii != NULL) {
//				delete[]this->salarii;
//			}
//			this->salarii = new float[c.nrAngajati];
//			for (int i = 0; i < c.nrAngajati; i++) {
//				this->salarii[i] = c.salarii[i];
//			}
//			this->esteVegana = c.esteVegana;
//			this->adaos = c.adaos;
//		}
//		return *this;
//	}
//
//	~Cofetarie() {
//		if (this->salarii) {
//			delete[]this->salarii;
//		}
//	}
//
//	string getNume() {
//		return this->nume;
//	}
//
//	void setNume(string nume) {
//		if (nume.length() > 1) {
//			this->nume = nume;
//		}
//	}
//
//	int getNrAngajati() {
//		return this->nrAngajati;
//	}
//	void setNrAngajati(int nrAngajati, float* salarii) {
//		if (nrAngajati > 0) {
//			this->nrAngajati = nrAngajati;
//			if (this->salarii != NULL) {
//				delete[]this->salarii;
//			}
//			this->salarii = new float[this->nrAngajati];
//			for (int i = 0; i < this->nrAngajati; i++) {
//				this->salarii[i] = salarii[i];
//			}
//		}
//	}
//
//	float* getSalarii() {
//		return this->salarii;
//	}
//
//	float getSalariu(int index) {
//		if (index >= 0 && index < this->nrAngajati) {
//			return this->salarii[index];
//		}
//	}
//
//	Cofetarie operator+(Cofetarie c)const {
//		Cofetarie temp = *this;
//		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
//		float* aux = new float[temp.nrAngajati];
//		for (int i = 0; i < this->nrAngajati; i++) {
//			aux[i] = this->salarii[i];
//		}
//		for (int i = 0; i < c.nrAngajati; i++) {
//			aux[i + this->nrAngajati] = c.salarii[i];
//		}
//		if (temp.salarii != NULL) {
//			delete[]temp.salarii;
//		}
//		temp.salarii = aux;
//		return temp;
//	}
//
//	Cofetarie& operator+=(Cofetarie c) {
//		*this = *this + c;
//		return *this;
//	}
//
//	Cofetarie operator+(float salariu)const {
//		Cofetarie temp = *this;
//		if (temp.salarii != NULL) {
//			delete[]temp.salarii;
//		}
//		temp.salarii = new float[temp.nrAngajati + 1];
//		for (int i = 0; i < this->nrAngajati; i++) {
//			temp.salarii[i] = this->salarii[i];
//		}
//		temp.salarii[temp.nrAngajati]=salariu;
//		temp.nrAngajati++;
//		return temp;
//	}
//
//	friend Cofetarie operator+(float salariu, Cofetarie c) {
//		Cofetarie temp = c;
//		if (temp.salarii != NULL) {
//			delete[]temp.salarii;
//		}
//		temp.salarii = new float[temp.nrAngajati + 1];
//		for (int i = 0; i < c.nrAngajati; i++) {
//			temp.salarii[i] = c.salarii[i];
//		}
//		temp.salarii[temp.nrAngajati] = salariu;
//		temp.nrAngajati++;
//		return temp;
//	}
//
//	void afisare() {
//		cout << "Nume:" << this->nume << endl;
//		cout << "Nr angajati:" << this->nrAngajati << endl;
//		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
//		cout << "An deschidere:" << this->anDeschidere << endl;
//		cout << "Adaos:" << this->adaos << endl;
//		cout << "TVA:" << Cofetarie::TVA << endl;
//	}
//	static void modificaTVA(int noulTVA) {
//		if (noulTVA > 0) {
//			Cofetarie::TVA = noulTVA;
//		}
//	}
//	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
//		int suma = 0;
//		for (int i = 0; i < nrCofetarii; i++) {
//			suma += vector[i].nrAngajati;
//		}
//		return suma;
//	}
//};
//int Cofetarie::TVA = 9;
//
//int main() {
//	Cofetarie c;
//	cout << c.getNume() << endl;
//	c.setNume("");
//	cout << c.getNume() << endl;
//	c.setNume("Alt nume");
//	cout << c.getNume() << endl;
//	c.setNrAngajati(4, new float[4] {2, 6, 4, 9});
//
//	Cofetarie c2("Minimal", 3, false, 2020, 10);
//	
//
//	Cofetarie c3 = c2;
//	Cofetarie c4 = c2 + 20;
//	c4.afisare();
//
//	c4 += c2;
//	c4.afisare();
//}