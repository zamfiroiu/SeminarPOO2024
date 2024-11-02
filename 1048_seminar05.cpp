//#include<iostream>
//
//using namespace std;
//
//class Masina {
//private:
//	int nrRoti;
//	string* producatori;
//	string marca;
//	float pret;
//	static int TVA;
//	const int anFabricatie;
//public:
//	Masina() :anFabricatie(2024), nrRoti(4) {
//		this->marca = "Dacia";
//		this->pret = 5000;
//		this->producatori = NULL;
//	}
//	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
//		this->nrRoti = _nrRoti;
//		this->marca = marca;
//		this->pret = pret;
//		this->producatori = new string[this->nrRoti];
//		for (int i = 0; i < this->nrRoti; i++) {
//			this->producatori[i] = "Michelin";
//		}
//	}
//	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
//		this->nrRoti = m.nrRoti;
//		this->marca = m.marca;
//		this->pret = m.pret;
//		this->producatori = new string[m.nrRoti];
//		for (int i = 0; i < m.nrRoti; i++) {
//			this->producatori[i] = m.producatori[i];
//		}
//	}
//	Masina operator=(const Masina& m) {
//		if (this != &m) {
//			this->nrRoti = m.nrRoti;
//			this->marca = m.marca;
//			this->pret = m.pret;
//			if (this->producatori != NULL) {
//				delete[]this->producatori;
//			}
//			this->producatori = new string[m.nrRoti];
//			for (int i = 0; i < m.nrRoti; i++) {
//				this->producatori[i] = m.producatori[i];
//			}
//		}
//		return *this;
//	}
//
//
//	~Masina() {
//		if (this->producatori != NULL) {
//			delete[]this->producatori;
//		}
//	}
//
//	Masina operator+(const Masina& m) const{
//		Masina temp = *this;
//		temp.pret = this->pret + m.pret;
//		return temp;
//	}
//
//	Masina operator+=(Masina m) {
//		this->pret = this->pret + m.pret;
//		return *this;
//	}
//
//	Masina operator+=(float adaosPret)  {
//		this->pret += adaosPret;
//		return *this;
//	}	
//	
//	Masina operator+(float adaosPret)const {
//		Masina temp = *this;
//		temp.pret += adaosPret;
//		return temp;
//	}
//
//	friend Masina operator+(float adaosPret, Masina m) {
//		Masina temp = m;
//		temp.pret += adaosPret;
//		return temp;
//	}
//
//	string getMarca() {
//		return this->marca;
//	}
//	void setMarca(string marca) {
//		if (marca.length() > 2) {
//			this->marca = marca;
//		}
//	}
//	float getPret() {
//		return this->pret;
//	}
//	void setPret(float pret) {
//		if (pret > 0) {
//			this->pret = pret;
//		}
//	}
//	string* getProducatori() {
//		return this->producatori;
//	}
//
//	string getProducator(int index) {
//		if (index >= 0 && index < this->nrRoti) {
//			return this->producatori[index];
//		}
//		else {
//			return "NU a fost gasit.";
//		}
//	}
//	void setNrRoti(int nrRoti, string* producatori) {
//		if (nrRoti > 0) {
//			this->nrRoti = nrRoti;
//			if (this->producatori != NULL) {
//				delete[]this->producatori;
//			}
//			this->producatori = new string[nrRoti];
//			for (int i = 0; i < nrRoti; i++) {
//				this->producatori[i] = producatori[i];
//			}
//		}
//	}
//
//	void afisare() {
//		cout << "Marca:" << this->marca << endl;
//		cout << "Nr roti:" << this->nrRoti << ": ";
//		if (this->producatori != NULL) {
//			for (int i = 0; i < this->nrRoti; i++) {
//				cout << this->producatori[i] << ", ";
//			}
//		}
//		cout << endl;
//		cout << "Pret:" << this->pret << endl;
//		cout << "TVA:" << this->TVA << endl;
//		cout << "An fabricatie:" << this->anFabricatie << endl;
//	}
//
//	float calculeazaPretTotal() {
//		return this->pret + (this->pret * (Masina::TVA / 100.0f));
//	}
//
//	static void modificaTVA(int noulTVA) {
//		if (noulTVA > 0) {
//			Masina::TVA = noulTVA;
//		}
//	}
//
//	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
//		float pretTotal = 0;
//		for (int i = 0; i < nrMasini; i++) {
//			pretTotal += vector[i].calculeazaPretTotal();
//		}
//		return pretTotal;
//	}
//
//};
//
//int Masina::TVA = 19;
//
//int main() {
//	Masina m;
//	cout << m.getMarca() << endl;
//	m.setMarca("Audi");
//	cout << m.getMarca() << endl;
//	m.afisare();
//
//	Masina m2(4, "BMW", 45000, 2021);
//	
//	Masina m3 = m2;
//
//	Masina m4 = m3 + m2;
//	Masina m5 = m2 + 30;
//	Masina m6 = 30 + m2;
//
//	m6.afisare();
//	return 9;
//
//}