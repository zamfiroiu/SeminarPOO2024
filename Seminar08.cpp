#include<iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string* producatori;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;
public:
	Masina() :anFabricatie(2024), nrRoti(0) {
		this->marca = "Dacia";
		this->pret = 5000;
		this->producatori = NULL;
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++) {
			this->producatori[i] = "Michelin";
		}
	}
	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		this->nrRoti = m.nrRoti;
		this->marca = m.marca;
		this->pret = m.pret;
		this->producatori = new string[m.nrRoti];
		for (int i = 0; i < m.nrRoti; i++) {
			this->producatori[i] = m.producatori[i];
		}
	}
	Masina operator=(const Masina& m) {
		if (this != &m) {
			this->nrRoti = m.nrRoti;
			this->marca = m.marca;
			this->pret = m.pret;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[m.nrRoti];
			for (int i = 0; i < m.nrRoti; i++) {
				this->producatori[i] = m.producatori[i];
			}
		}
		return *this;
	}


	~Masina() {
		if (this->producatori != NULL) {
			delete[]this->producatori;
		}
	}

	Masina operator+(const Masina& m) const {
		Masina temp = *this;
		temp.pret = this->pret + m.pret;
		return temp;
	}

	Masina operator+=(Masina m) {
		this->pret = this->pret + m.pret;
		return *this;
	}

	Masina operator+=(float adaosPret) {
		this->pret += adaosPret;
		return *this;
	}

	Masina operator+(float adaosPret)const {
		Masina temp = *this;
		temp.pret += adaosPret;
		return temp;
	}

	friend Masina operator+(float adaosPret, Masina m) {
		Masina temp = m;
		temp.pret += adaosPret;
		return temp;
	}
	explicit operator float()
	{
		return calculeazaPretTotal();
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			throw "Indexul este in afara limitelor.";
		}
	}
	explicit operator int()
	{
		return this->nrRoti;
	}
	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2) {
			this->marca = marca;
		}
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret) {
		if (pret > 0) {
			this->pret = pret;
		}
	}
	string* getProducatori() {
		return this->producatori;
	}

	string getProducator(int index) {
		if (index >= 0 && index < this->nrRoti) {
			return this->producatori[index];
		}
		else {
			return "NU a fost gasit.";
		}
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}

	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << ": ";
		if (this->producatori != NULL) {
			for (int i = 0; i < this->nrRoti; i++) {
				cout << this->producatori[i] << ", ";
			}
		}
		cout << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal() {
		return this->pret + (this->pret * (Masina::TVA / 100.0f));
	}

	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}

	bool operator<(Masina m) {
		return this->pret < m.pret;
	}
	friend istream& operator>>(istream& input, Masina& m) {
		cout << "Introduceti marca:";
		input >> m.marca;
		cout << "Nr roti:";
		input >> m.nrRoti;
		if (m.producatori != NULL) {
			delete[]m.producatori;
		}
		if (m.nrRoti > 0) {
			m.producatori = new string[m.nrRoti];
			cout << "Producatori:";
			for (int i = 0; i < m.nrRoti; i++) {
				input >> m.producatori[i];
			}
		}
		else {
			m.producatori = NULL;
		}
		cout << "Pret:";
		input >> m.pret;
		return input;
	}
	friend ostream& operator<<(ostream& output, Masina m);
};

int Masina::TVA = 19;

ostream& operator<<(ostream& output, Masina m) {
	output << "Marca:" << m.marca << endl;
	output << "Nr roti:" << m.nrRoti << ": ";
	if (m.producatori != NULL) {
		for (int i = 0; i < m.nrRoti; i++) {
			output << m.producatori[i] << ", ";
		}
	}
	output << endl;
	output << "Pret:" << m.pret << endl;
	output << "TVA:" << m.TVA << endl;
	output << "An fabricatie:" << m.anFabricatie << endl;
	return output;
}

class Magazin {
private:
	string oras;
	int nrAngajati;//
	float* salarii;
	float suprafata;//
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin():anDeschidere(2024),nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m):anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	Magazin operator=(const Magazin& m) {
		if (&m != this) { //verificare de autoasignare
			this->oras = m.oras;
			this->nrAngajati = m.nrAngajati;
			if (this->salarii) {
				delete[]this->salarii;
			}
			this->salarii = new float[m.nrAngajati];
			for (int i = 0; i < m.nrAngajati; i++) {
				this->salarii[i] = m.salarii[i];
			}
			this->suprafata = m.suprafata;
		}
		return *this;
	}


	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float * salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}
	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafataNoua) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}
	float* getSalarii() {
		return this->salarii;
	}
	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}

	Magazin operator+(Magazin m2)const {
		Magazin temp = *this;
		temp.nrAngajati = this->nrAngajati + m2.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < m2.nrAngajati; i++) {
			aux[i + this->nrAngajati] = m2.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Magazin& operator+=(Magazin m) {
		*this = *this + m;
		return *this;
	}

	Magazin operator+(float salariu)const {
		Magazin temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati]=salariu;
		temp.nrAngajati++;
		return temp;
	}

	//friend Magazin operator+(float salariu, Magazin m) {
	//	Magazin temp = m;
	//	if (temp.salarii != NULL) {
	//		delete[]temp.salarii;
	//	}
	//	temp.salarii = new float[temp.nrAngajati + 1];
	//	for (int i = 0; i < m.nrAngajati; i++) {
	//		temp.salarii[i] = m.salarii[i];
	//	}
	//	temp.salarii[temp.nrAngajati] = salariu;
	//	temp.nrAngajati++;
	//	return temp;
	//}

	friend Magazin operator+(float salariu, Magazin m);



	void afisare() {
		cout << "Oras:" << this->oras <<endl;
		cout << "Numar angajati:" << this->nrAngajati <<endl;
		cout << "Suprafata:" << this->suprafata <<endl;
		cout << "An deschidere:" << this->anDeschidere <<endl;
		cout << "Impozit pe m2:" << Magazin::impozitM2 <<endl;
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0) {
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
	}

	static void modificaImpozit(int impozit) {
		if (impozit > 0) {
			Magazin::impozitM2 = impozit;
		}
	}

	static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
		float suma = 0;
		for (int i = 0; i < nrMagazine; i++) {
			suma += vector[i].suprafata;
		}
		return suma;
	}

	bool operator>(Magazin m)
	{
			return this->suprafata > m.suprafata && this->nrAngajati>m.nrAngajati;
	}

	bool operator==(Magazin m)
	{
		return this->suprafata == m.suprafata && this->nrAngajati == m.nrAngajati;
	}

	explicit operator int() {
		return this->nrAngajati;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "indexul este in afara limitelor";
		}
	}

	friend ostream& operator<<(ostream& out,const Magazin& m) {
		out << "Oras:" << m.oras << endl;
		out << "Numar angajati:" << m.nrAngajati << endl;
		if (m.nrAngajati >0 ) {
			for (int i = 0; i < m.nrAngajati; i++) {
				out << m.salarii[i]<<" ";
			}
		} 
		out << endl;
		out << "Suprafata:" << m.suprafata << endl;
		out << "An deschidere:" << m.anDeschidere << endl;
		out << "Impozit pe m2:" << Magazin::impozitM2 << endl;

		return out;
	}

	friend istream& operator>>(istream& input, Magazin& m);
};
int Magazin::impozitM2 = 2;


istream& operator>>(istream& input, Magazin& m) {
	cout << "Oras:";
	input >> m.oras;
	cout << "nr angajati:";
	input >> m.nrAngajati;
	if (m.salarii != NULL) {
		delete[]m.salarii;
	}
	if (m.nrAngajati > 0) {
		m.salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			cout << " Salariul " << i + 1 << ":";
			input >> m.salarii[i];
		}
	}
	else {
		m.salarii = NULL;
	}
	cout << "Suprafata:";
	input >> m.suprafata;
	return input;
}

Magazin operator+(float salariu, Magazin m) {
	float valoare = m.nrAngajati;
	return m + salariu;
}

Magazin f(Magazin m) {
	Magazin magazin;
	return magazin;
}


class Cofetarie {
private:
	string nume; //
	int nrAngajati;//
	float* salarii;
	bool esteVegana;
	const int anDeschidere;
	float adaos;
	static int TVA;

public:
	Cofetarie() : adaos(30), anDeschidere(2024) {
		this->nume = "Delice";
		this->nrAngajati = 0;
		this->esteVegana = true;
		this->salarii = NULL;
	}

	Cofetarie(string nume, int nrAngajati, bool vegan, int an, float adaos) :anDeschidere(an) {
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->esteVegana = vegan;
		this->adaos = adaos;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 1000 + i * 100;
		}
	}

	Cofetarie(const Cofetarie& c) :anDeschidere(c.anDeschidere) {
		this->nume = c.nume;
		this->nrAngajati = c.nrAngajati;
		this->salarii = new float[c.nrAngajati];
		for (int i = 0; i < c.nrAngajati; i++) {
			this->salarii[i] = c.salarii[i];
		}
		this->esteVegana = c.esteVegana;
		this->adaos = c.adaos;
	}
	Cofetarie operator=(const Cofetarie& c) {
		if (&c != this) {
			this->nume = c.nume;
			this->nrAngajati = c.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				this->salarii[i] = c.salarii[i];
			}
			this->esteVegana = c.esteVegana;
			this->adaos = c.adaos;
		}
		return *this;
	}

	~Cofetarie() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 1) {
			this->nume = nume;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0) {
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	Cofetarie operator+(Cofetarie c)const {
		Cofetarie temp = *this;
		temp.nrAngajati = this->nrAngajati + c.nrAngajati;
		float* aux = new float[temp.nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++) {
			aux[i] = this->salarii[i];
		}
		for (int i = 0; i < c.nrAngajati; i++) {
			aux[i + this->nrAngajati] = c.salarii[i];
		}
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = aux;
		return temp;
	}

	Cofetarie& operator+=(Cofetarie c) {
		*this = *this + c;
		return *this;
	}

	Cofetarie operator+(float salariu)const {
		Cofetarie temp = *this;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < this->nrAngajati; i++) {
			temp.salarii[i] = this->salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	friend Cofetarie operator+(float salariu, Cofetarie c) {
		Cofetarie temp = c;
		if (temp.salarii != NULL) {
			delete[]temp.salarii;
		}
		temp.salarii = new float[temp.nrAngajati + 1];
		for (int i = 0; i < c.nrAngajati; i++) {
			temp.salarii[i] = c.salarii[i];
		}
		temp.salarii[temp.nrAngajati] = salariu;
		temp.nrAngajati++;
		return temp;
	}

	explicit operator int() {
		return this->nrAngajati;
	}

	explicit operator float() {
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			s += this->salarii[i];
		}
		return s;
	}

	void afisare() {
		cout << "Nume:" << this->nume << endl;
		cout << "Nr angajati:" << this->nrAngajati << endl;
		cout << "Are produse vegane:" << (this->esteVegana ? "DA" : "NU") << endl;
		cout << "An deschidere:" << this->anDeschidere << endl;
		cout << "Adaos:" << this->adaos << endl;
		cout << "TVA:" << Cofetarie::TVA << endl;
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0) {
			Cofetarie::TVA = noulTVA;
		}
	}
	static int calculeazaNrTotalAngajati(int nrCofetarii, Cofetarie* vector) {
		int suma = 0;
		for (int i = 0; i < nrCofetarii; i++) {
			suma += vector[i].nrAngajati;
		}
		return suma;
	}

	friend ostream& operator<<(ostream& output, Cofetarie c);

	friend istream& operator>>(istream& input, Cofetarie& c) {
		cout << "Nume:";
		input >> c.nume;
		cout << "Nr angajati:";
		input >> c.nrAngajati;
		if (c.salarii != NULL) {
			delete[]c.salarii;
		}
		if (c.nrAngajati > 0) {
			c.salarii = new float[c.nrAngajati];
			for (int i = 0; i < c.nrAngajati; i++) {
				cout << "Salariul " << i + 1 << ":";
				input >> c.salarii[i];
			}
		}
		else {
			c.salarii = NULL;
		}
		cout << "Are produse vegane? 1-DA; 0-NU:";
		input >> c.esteVegana;
		cout << "Adaos comercial:";
		input >> c.adaos;
		return input;
	}

	bool operator<(Cofetarie c) {
		return this->nrAngajati < c.nrAngajati;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
		else {
			throw "Indexul este in afara limitelor";
		}
	}

};
int Cofetarie::TVA = 9;

ostream& operator<<(ostream& output, Cofetarie c) {
	output << "Nume:" << c.nume << endl;
	output << "Nr angajati:" << c.nrAngajati << endl;
	if (c.salarii != NULL) {
		for (int i = 0; i < c.nrAngajati; i++) {
			cout << c.salarii[i] << ", ";
		}
		cout << endl;
	}
	output << "Are produse vegane:" << (c.esteVegana ? "DA" : "NU") << endl;
	output << "An deschidere:" << c.anDeschidere << endl;
	output << "Adaos:" << c.adaos << endl;
	output << "TVA:" << Cofetarie::TVA << endl;
	return output;
}

//ComplexComercial
//Antreprenor
//Livrator

class ComplexComercial {
private:
	Magazin magazin;
	Cofetarie *cofetarie;
	int nrMasiniParcate;
	Masina* masiniParcate;

public:

	Magazin getMagazin()const {
		return this->magazin;
	}
	ComplexComercial(){
		this->cofetarie = new Cofetarie("Delicii", 3, true, 2024, 20);
		this->nrMasiniParcate = 3;
		this->masiniParcate = new Masina[this->nrMasiniParcate];
	}
	ComplexComercial(Magazin mag, Cofetarie* cof, int nrMasini, Masina* masini)
	{
		this->magazin = mag;
		this->cofetarie = new Cofetarie(*cof);
		this->nrMasiniParcate = nrMasini;
		this->masiniParcate = new Masina[nrMasini];
		for (int i = 0; i < nrMasini; i++) {
			this->masiniParcate[i] = masini[i];
		}
	}
	ComplexComercial(const ComplexComercial& cc) {
		this->magazin = cc.magazin;
		this->cofetarie = new Cofetarie(*(cc.cofetarie));
		this->nrMasiniParcate = cc.nrMasiniParcate;
		this->masiniParcate = new Masina[cc.nrMasiniParcate];
		for (int i = 0; i < cc.nrMasiniParcate; i++) {
			this->masiniParcate[i] = cc.masiniParcate[i];
		}
	}
	~ComplexComercial() {
		if (this->cofetarie) {
			delete this->cofetarie;
		}
		if (this->masiniParcate) {
			delete []this->masiniParcate;
		}
	}

	ComplexComercial operator=(const ComplexComercial& cc) {
		if (this != &cc) {
			this->magazin = cc.magazin;
			if (this->cofetarie) {
				delete this->cofetarie;
			}
			this->cofetarie = new Cofetarie(*(cc.cofetarie));
			this->nrMasiniParcate = cc.nrMasiniParcate;
			if (this->masiniParcate) {
				delete[]this->masiniParcate;
			}
			this->masiniParcate = new Masina[cc.nrMasiniParcate];
			for (int i = 0; i < cc.nrMasiniParcate; i++) {
				this->masiniParcate[i] = cc.masiniParcate[i];
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& o, const ComplexComercial& cc) {
		o << "Magazinul din complexul comercial: " << endl;
		o << cc.magazin << endl;
		o << "Cofetaria din complex este:" << endl;
		o << *cc.cofetarie << endl;
		o << "Avem " << cc.nrMasiniParcate << " masini parcate in complex:" << endl;
		for (int i = 0; i < cc.nrMasiniParcate; i++) {
			o << cc.masiniParcate[i] << endl;
		}
		o << endl;
		return o;
	}

	ComplexComercial operator--() {
		if (this->nrMasiniParcate > 0) {
			this->nrMasiniParcate--;
			Masina* aux = new Masina[this->nrMasiniParcate];
			for (int i = 0; i < this->nrMasiniParcate; i++) {
				aux[i] = this->masiniParcate[i];
			}
			delete[]this->masiniParcate;
			this->masiniParcate = aux;
		}
		return *this;
	}

	ComplexComercial operator--(int) {
		ComplexComercial cc = *this;
		--(*this);
		return cc;
	}
};

void main() {

	ComplexComercial cc1;

	Magazin magazin;
	Cofetarie* c = new Cofetarie();
	Masina* masini = new Masina[5];

	ComplexComercial cc2(magazin, c, 5, masini);

	cout << cc2;

	//cc2--;

	cc1=--cc2;

	cout << cc1;
}