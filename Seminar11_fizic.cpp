#include<iostream>

using namespace std;

class PersonalMedical {
protected:
	string nume;
	float salariuBaza;
public:
	PersonalMedical() {
		this->nume = "N/A";
		this->salariuBaza = 1000;
	}

	PersonalMedical(string nume, float salariu) {
		this->nume = nume;
		this->salariuBaza = salariu;
	}

	virtual ~PersonalMedical() {

	}

	virtual float getVenitTotal() = 0;
};

class Medic :public PersonalMedical {
	float sporStudii;
	char* specializare;
public:
	Medic() :PersonalMedical() {
		this->sporStudii = 10;
		this->specializare =new char[strlen("Stomatologie")+1];
		strcpy_s(this->specializare, strlen("Stomatologie") + 1, "Stomatologie");
	}
	Medic(string nume, float salariuBaza, float sporStudii, const char* specializare) :PersonalMedical(nume, salariuBaza) {
		this->sporStudii = sporStudii;
		this->specializare = new char[strlen(specializare)+1];
		strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
	}
	~Medic() {
		if (this->specializare) {
			delete[]this->specializare;
		}
	}
	Medic(const Medic& m) :PersonalMedical(m) {
		this->sporStudii = m.sporStudii;
		this->specializare = new char[strlen(m.specializare) + 1];
		strcpy_s(this->specializare, strlen(m.specializare) + 1, m.specializare);
	}

	Medic operator=(const Medic& m)  {
		if (&m != this) {
			PersonalMedical::operator=(m);
			this->sporStudii = m.sporStudii;
			if (this->specializare) {
				delete[]this->specializare;
			}
			this->specializare = new char[strlen(m.specializare) + 1];
			strcpy_s(this->specializare, strlen(m.specializare) + 1, m.specializare);
		}
		return *this;
	}

	float getVenitTotal() {
		return this->salariuBaza + this->salariuBaza * this->sporStudii / 100;
	}
};

class Anestezist :public PersonalMedical {
public:
	Anestezist(string nume, float salariu) :PersonalMedical(nume, salariu) {

	}
	float getVenitTotal() {
		return this->salariuBaza;
	}
};

class Asistent : public PersonalMedical {
	int nrGarzi;
	float sporGarda;
public:
	Asistent() :PersonalMedical() {
		this->nrGarzi = 0;
		this->sporGarda = 0;
	}
	Asistent(string nume, float salariu, int nrGarzi, float sporGarda):PersonalMedical(nume,salariu) {
		this->nrGarzi = nrGarzi;
		this->sporGarda = sporGarda;
	}
	float getVenitTotal() {
		return this->salariuBaza + this->nrGarzi * this->sporGarda;
	}
};

void afisareVector(PersonalMedical** vector, int nr) {
	for (int i = 0; i < nr; i++) {
		cout << "Salariul " << (i + 1) << " este: " << vector[i]->getVenitTotal() << endl;
	}
}


int main() {

	PersonalMedical *pm = new Medic("Popescu",10000,15,"Cardiologie");

	PersonalMedical** pointeri = new PersonalMedical * [5];
	pointeri[0] = new Asistent("Gigel", 1000, 4, 100);
	pointeri[1] = new Medic("Ionescu", 1000, 19, "Oftalmologie");
	pointeri[2] = new Medic("Vasilescu", 1000, 27, "Endocrinologie");
	pointeri[3] = new Asistent("Georgescu", 1000, 18, 100);
	pointeri[4] = new Anestezist("Gheorghe",1000);

	afisareVector(pointeri, 5);

	for (int i = 0; i < 5; i++) {
		delete pointeri[i];
	}
	delete[]pointeri;

	delete pm;

	return 4564;
}

