#include<iostream>

using namespace std;

class Produs {
private:
	float pret;
	int stoc;
	char* nume;
public:
	Produs() {
		this->stoc = 0;
		this->pret = 0;
		this->nume = NULL;
	}

	Produs(float pret, int stoc, const char* nume) {
		this->stoc = stoc;
		this->pret = pret;
		this->nume = new char[strlen(nume)+1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}

	Produs(const Produs& p) {
		this->stoc = p.stoc;
		this->pret = p.pret;
		this->nume = new char[strlen(p.nume) + 1];
		strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	}

	Produs operator=(const Produs& p) {
		if (this != &p) {
			this->stoc = p.stoc;
			this->pret = p.pret;
			if (this->nume) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(p.nume) + 1];
			strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
		}
	}

	~Produs() {
		if (this->nume) {
			delete[]this->nume;
		}
	}
};

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

void f(const char* param) {

}

class MagazinCuProduse :public Magazin {//relatie de is-a
private:
	int nrProduse;
	Produs** produse;//relatie de has-a

public:
	MagazinCuProduse():Magazin() {
		this->nrProduse = 0;
		this->produse = NULL;
	}

	MagazinCuProduse(int nrProduse, Produs** produse):Magazin() {
		this->nrProduse = nrProduse;
		this->produse = new Produs * [this->nrProduse];
		for (int i = 0; i < nrProduse; i++) {
			this->produse[i] = new Produs(*produse[i]);
		}
	}
	MagazinCuProduse(const MagazinCuProduse& mp):Magazin(mp) {
		this->nrProduse = mp.nrProduse;
		this->produse = new Produs * [this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->produse[i] = new Produs(*(mp.produse[i]));
		}
	}
	~MagazinCuProduse() {
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->produse[i]) {
				delete this->produse[i];
			}
		}
		if (this->produse) {
			delete[]this->produse;
		}
	}

	MagazinCuProduse operator=(const MagazinCuProduse& mp) {
		if (&mp != this) {
			for (int i = 0; i < this->nrProduse; i++) {
				if (this->produse[i]) {
					delete this->produse[i];
				}
			}
			if (this->produse) {
				delete[]this->produse;
			}
			this->nrProduse = mp.nrProduse;
			this->produse = new Produs * [this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->produse[i] = new Produs(*(mp.produse[i]));
			}
		}

	}
};

int main() {
char aux[20];
	f(aux);

	f("bucuresti");

	Magazin m1;
	Magazin m2("Bucuresti", 3, 80, 2024);

	m2.afisare();
	float suprafata = m2.calculeazaSuprafataMedie();

	if (m1 == m2) {
		cout << "cele doua sunt egale.";
	}

	bool rezultat = (m1 > m2);

	cin >> m1;
	cout << m1;
	m1 = m1 + m2;

	float valoare = (float)m1;

	MagazinCuProduse mp1;
	Produs** produse = new Produs * [3];
	produse[0] = new Produs();
	produse[1] = new Produs(23, 10, "Marker");
	produse[2] = new Produs(5, 20, "Pix");
	MagazinCuProduse mp2(3, produse);

	for (int i = 0; i < 3; i++) {
		delete produse[i];
	}
	delete[]produse;

}