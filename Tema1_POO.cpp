#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <random>
#include <Windows.h>

class Jucator {
    std::string nume, prenume;
    char pozitie;
    float inaltime;
    double greutate;
    int numarTricou, numarGoluri, numarCGalbene, varsta, numarCRosii;
    bool cartonasRosu;
public:
    Jucator();
    Jucator(std::string, std::string, char, int);
    Jucator(std::string, std::string, char, float, double, int, int);
    Jucator(std::string, std::string, char, float, double, int, int, int, int, int, bool);
    Jucator(const Jucator&);

    Jucator& operator=(const Jucator&);
    friend std::istream& operator>>(std::istream&, Jucator&);
    friend std::ostream& operator<<(std::ostream&, const Jucator&);
    char operator[](int);
    Jucator operator++();
    Jucator operator++(int);
    Jucator operator+(const Jucator&);
    Jucator operator+(int x);
    friend Jucator operator+(int, Jucator);
    Jucator operator-(const Jucator&);
    Jucator operator-(int);
    friend Jucator operator-(int, Jucator);
    operator int();
    bool operator<(const Jucator&);
    bool operator==(const Jucator&);

    void douaGalbene() { this->numarCGalbene++; if (this->numarCGalbene == 2) this->numarCRosii++, this->cartonasRosu = true, this->numarCGalbene = 0; }
    void cresteCGalbene() { this->numarCGalbene++; }
    void cresteCRosii() { this->numarCRosii; }

    void setNume(std::string nume) { this->nume = nume; }
    void setPrenume(std::string prenume) { this->prenume = prenume; }
    void setPozitie(char pozitie) { this->pozitie = pozitie; }
    void setNumarTricou(int numarTricou) { this->numarTricou = numarTricou; }
    void setGreutate(double greutate) { this->greutate = greutate; }
    void setInaltime(float inaltime) { this->inaltime = inaltime; }
    void setCartonasRosu(bool cartonasRosu) { this->cartonasRosu = cartonasRosu; }
    std::string getNume() { return this->nume; }
    std::string getPrenume() { return this->prenume; }
    char getPozitie() { return this->pozitie; }
    double getGreutate() { return this->greutate; }
    float getInaltime() { return this->inaltime; }
    bool getCartonasRosu() { return this->cartonasRosu; }

    ~Jucator();
};

Jucator::Jucator() {
    this->nume = "Nedefinit";
    this->prenume = "Nedefinit";
    this->pozitie = 'N';
    this->inaltime = 0.0;
    this->greutate = 0.0;
    this->numarTricou = 0;
    this->numarCGalbene = 0;
    this->numarCRosii = 0;
    this->varsta = 0;
    this->numarGoluri = 0;
    this->cartonasRosu = false;
}

Jucator::Jucator(std::string nume, std::string prenume, char pozitie, int numarTricou) {
    this->nume = nume;
    this->prenume = prenume;
    this->pozitie = pozitie;
    this->inaltime = 0.0;
    this->greutate = 0.0;
    this->numarTricou = numarTricou;
    this->numarCGalbene = 0;
    this->numarCRosii = 0;
    this->varsta = 0;
    this->numarGoluri = 0;
    this->cartonasRosu = false;
}

Jucator::Jucator(std::string nume, std::string prenume, char pozitie, float inaltime, double greutate, int numarTricou, int varsta) {
    this->nume = nume;
    this->prenume = prenume;
    this->pozitie = pozitie;
    this->inaltime = inaltime;
    this->greutate = greutate;
    this->numarTricou = numarTricou;
    this->numarCGalbene = 0;
    this->numarCRosii = 0;
    this->varsta = varsta;
    this->numarGoluri = 0;
    this->cartonasRosu = false;
}

Jucator::Jucator(std::string nume, std::string prenume, char pozitie, float inaltime, double greutate, int numarTricou, int varsta, int numarCGalbene, int numarGoluri, int numarCRosii, bool cartonasRosu) {
    this->nume = nume;
    this->prenume = prenume;
    this->pozitie = pozitie;
    this->inaltime = inaltime;
    this->greutate = greutate;
    this->numarTricou = numarTricou;
    this->numarCGalbene = numarCGalbene;
    this->numarCRosii = numarCRosii;
    this->varsta = varsta;
    this->numarGoluri = numarGoluri;
    this->cartonasRosu = cartonasRosu;
}

Jucator::Jucator(const Jucator& obj) {
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->pozitie = obj.pozitie;
    this->inaltime = obj.inaltime;
    this->greutate = obj.greutate;
    this->numarTricou = obj.numarTricou;
    this->numarCGalbene = obj.numarCGalbene;
    this->numarCRosii = obj.numarCRosii;
    this->varsta = obj.varsta;
    this->numarGoluri = obj.numarGoluri;
    this->cartonasRosu = obj.cartonasRosu;
}

Jucator& Jucator::operator=(const Jucator& obj) {
    this->nume = obj.nume;
    this->prenume = obj.prenume;
    this->pozitie = obj.pozitie;
    this->inaltime = obj.inaltime;
    this->greutate = obj.greutate;
    this->numarTricou = obj.numarTricou;
    this->numarCGalbene = obj.numarCGalbene;
    this->numarCRosii = obj.numarCRosii;
    this->varsta = obj.varsta;
    this->numarGoluri = obj.numarGoluri;
    this->cartonasRosu = obj.cartonasRosu;
    return (*this);
}

std::istream& operator>>(std::istream& in, Jucator& obj) {
    std::cout << "Nume jucator: ";
    in >> obj.nume;
    std::cout << "Prenume jucator: ";
    in >> obj.prenume;
    std::cout << "Pozitie: ";
    in >> obj.pozitie;
    std::cout << "Numar tricou: ";
    in >> obj.numarTricou;
    std::cout << "Varsta: ";
    in >> obj.varsta;
    std::cout << "Inaltime: ";
    in >> obj.inaltime;
    std::cout << "Greutate: ";
    in >> obj.greutate;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Jucator& obj) {
    out << "Nume jucator: " << obj.nume << '\n';
    out << "Prenume jucator: " << obj.prenume << '\n';
    out << "Pozitie: " << obj.pozitie << '\n';
    out << "Numar tricou: " << obj.numarTricou << '\n';
    out << "Varsta: " << obj.varsta << '\n';
    out << "Inaltime: " << obj.inaltime << '\n';
    out << "Greutate: " << obj.greutate << '\n';
    out << "Numar goluri: " << obj.numarGoluri << '\n';
    out << "Numar cartonase galbene: " << obj.numarCGalbene << '\n';
    out << "Numar cartonase rosii: " << obj.numarCRosii << '\n';
    return out;
}

Jucator Jucator::operator++() {
    this->numarGoluri++;
    return (*this);
}

Jucator Jucator::operator++(int) {
    Jucator copie(*this);
    ++(*this);
    return copie;
}

char Jucator::operator[](int i) {
    if (i < 0 or i >= this->nume.size())
        throw std::runtime_error("Index in afara vectorului");
    return this->nume.at(i);
}

Jucator Jucator::operator+(const Jucator& obj) {
    Jucator rezultat(*this);
    rezultat.nume += obj.nume;
    rezultat.prenume += obj.prenume;
    rezultat.numarTricou += obj.numarTricou;
    rezultat.varsta += obj.varsta;
    rezultat.numarCGalbene += obj.numarCGalbene;
    rezultat.numarCRosii += obj.numarCRosii;
    rezultat.numarGoluri += obj.numarGoluri;
    rezultat.inaltime += obj.inaltime;
    rezultat.greutate += obj.greutate;
    return rezultat;
}

Jucator Jucator::operator+(int x) {
    Jucator rezultat(*this);
    rezultat.numarGoluri += x;
    return rezultat;
}

Jucator operator+(int x, Jucator obj) {
    return obj + x;
}

Jucator Jucator::operator-(const Jucator& obj) {
    Jucator rezultat(*this);
    rezultat.numarTricou -= obj.numarTricou;
    rezultat.varsta -= obj.varsta;
    rezultat.numarCGalbene -= obj.numarCGalbene;
    rezultat.numarCRosii -= obj.numarCRosii;
    rezultat.numarGoluri -= obj.numarGoluri;
    rezultat.inaltime -= obj.inaltime;
    rezultat.greutate -= obj.greutate;
    return rezultat;
}

Jucator Jucator::operator-(int x) {
    return (*this) + (-x);
}

Jucator operator-(int x, Jucator obj) {
    return obj - x;
}

Jucator::operator int() {
    return this->numarTricou;
}

bool Jucator::operator<(const Jucator& obj) {
    return this->numarGoluri < obj.numarGoluri;
}

bool Jucator::operator==(const Jucator& obj) {
    if (this->nume != obj.nume)
        return false;
    if (this->prenume != obj.prenume)
        return false;
    if (this->numarTricou != obj.numarTricou)
        return false;
    if (this->varsta != obj.varsta)
        return false;
    if (this->numarCGalbene != obj.numarCGalbene)
        return false;
    if (this->numarCRosii != obj.numarCRosii)
        return false;
    if (this->numarGoluri != obj.numarGoluri)
        return false;
    if (this->inaltime != obj.inaltime)
        return false;
    if (this->greutate != obj.greutate)
        return false;
    if (this->pozitie != obj.pozitie)
        return false;
    return true;
}

Jucator::~Jucator() {
    this->nume = "";
    this->prenume = "";
    this->pozitie = 0;
    this->inaltime = 0;
    this->greutate = 0;
    this->numarTricou = 0;
    this->numarCGalbene = 0;
    this->numarCRosii = 0;
    this->varsta = 0;
    this->numarGoluri = 0;
    this->cartonasRosu = 0;
}

class Echipa {
    static int cIDEchipa;
    const int idEchipa;
    std::string numeEchipa;
    std::string abreviereEchipa;
    char* orasEchipa;
    int numarTitulari, puncte, victorii, egaluri, infrangeri, golaveraj;
    Jucator* listaTitulari;

public:
    Echipa();
    Echipa(std::string, std::string, char*);
    Echipa(std::string, std::string, char*, int, Jucator*);
    Echipa(std::string, std::string, char*, int, int, int, int, int, int, Jucator*);
    Echipa(const Echipa&);

    Echipa& operator=(const Echipa&);
    friend std::istream& operator>>(std::istream&, Echipa&);
    friend std::ostream& operator<<(std::ostream&, const Echipa&);
    Jucator* operator[](int);
    friend Echipa operator+(Echipa, Jucator);
    friend Echipa operator+(Jucator, Echipa);
    friend Echipa operator-(Echipa, Jucator);
    friend Echipa operator-(Jucator, Echipa);
    Echipa operator++();
    Echipa operator++(int);
    Echipa operator+(const Echipa&);
    Echipa operator+(int x);
    friend Echipa operator+(int, Echipa);
    Echipa operator-(const Echipa&);
    Echipa operator-(int);
    friend Echipa operator-(int, Echipa);
    operator int();
    bool operator<(const Echipa&);
    bool operator==(const Echipa&);

    void calculPuncte() { this->puncte = this->egaluri + 3 * this->victorii; };
    void cresteVictorii() { this->victorii++; }
    void cresteInfrangeri() { this->infrangeri++; }
    void cresteEgaluri() { this->egaluri++; }
    void cresteGolaveraj(int x) { this->golaveraj += x; }

    int getNrJucatori() { return this->numarTitulari; }
    int getNrPuncte() { return this->puncte; }
    int getGolaveraj() { return this->golaveraj; }
    Jucator getListaTitulari() { return *this->listaTitulari; }
    std::string getAbreviere() { return this->abreviereEchipa; }
    std::string getNumeEchipa() { return this->numeEchipa; }

    ~Echipa();
};

int Echipa::cIDEchipa = 1;

Echipa::Echipa() :idEchipa(cIDEchipa++) {
    this->numeEchipa = "Nedefinit";
    this->abreviereEchipa = "NEDEF";
    this->orasEchipa = new char[strlen("Nedefinit") + 1];
    strcpy(this->orasEchipa, "Nedefinit");
    this->numarTitulari = 0;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = NULL;
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = 0;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = NULL;
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa, int numarTitulari, Jucator* listaTitulari) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = numarTitulari;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = new Jucator[numarTitulari];
    for (int i = 0; i < numarTitulari; i++) {
        this->listaTitulari[i] = listaTitulari[i];
    }
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa, int numarTitulari, int puncte, int victorii, int egaluri, int infrangeri, int golaveraj, Jucator* listaTitulari) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = numarTitulari;
    this->puncte = puncte;
    this->victorii = victorii;
    this->egaluri = egaluri;
    this->infrangeri = infrangeri;
    this->golaveraj = golaveraj;
    this->listaTitulari = new Jucator[numarTitulari];
    for (int i = 0; i < numarTitulari; i++) {
        this->listaTitulari[i] = listaTitulari[i];
    }
}

Echipa::Echipa(const Echipa& obj) :idEchipa(obj.idEchipa) {
    this->numeEchipa = obj.numeEchipa;
    this->abreviereEchipa = obj.abreviereEchipa;
    this->orasEchipa = new char[strlen(obj.orasEchipa) + 1];
    strcpy(this->orasEchipa, obj.orasEchipa);
    this->numarTitulari = obj.numarTitulari;
    this->puncte = obj.puncte;
    this->victorii = obj.victorii;
    this->egaluri = obj.egaluri;
    this->infrangeri = obj.infrangeri;
    this->golaveraj = obj.golaveraj;
    this->listaTitulari = new Jucator[obj.numarTitulari];
    for (int i = 0; i < obj.numarTitulari; i++) {
        this->listaTitulari[i] = obj.listaTitulari[i];
    }
}

Echipa& Echipa::operator=(const Echipa& obj) {
    this->numeEchipa = obj.numeEchipa;
    this->abreviereEchipa = obj.abreviereEchipa;
    if (this->orasEchipa != NULL) {
        delete[] this->orasEchipa;
        this->orasEchipa = NULL;
    }
    this->orasEchipa = new char[strlen(obj.orasEchipa) + 1];
    strcpy(this->orasEchipa, obj.orasEchipa);
    this->numarTitulari = obj.numarTitulari;
    this->puncte = obj.puncte;
    this->victorii = obj.victorii;
    this->egaluri = obj.egaluri;
    this->infrangeri = obj.infrangeri;
    this->golaveraj = obj.golaveraj;
    if (this->listaTitulari != NULL) {
        delete[] this->listaTitulari;
        this->listaTitulari = NULL;
    }
    this->listaTitulari = new Jucator[obj.numarTitulari];
    for (int i = 0; i < obj.numarTitulari; i++) {
        this->listaTitulari[i] = obj.listaTitulari[i];
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Echipa& obj) {
    std::cout << "Denumire echipa: ";
    in >> obj.numeEchipa;
    std::cout << "Abreviere echipa: ";
    in >> obj.abreviereEchipa;
    char oras[100];
    std::cout << "Oras echipa: ";
    in >> oras;
    if (obj.orasEchipa != NULL) {
        delete[] obj.orasEchipa;
        obj.orasEchipa = NULL;
    }
    obj.orasEchipa = new char[strlen(oras) + 1];
    strcpy(obj.orasEchipa, oras);
    std::cout << "Numar titulari: ";
    in >> obj.numarTitulari;
    if (obj.listaTitulari != NULL) {
        delete[] obj.listaTitulari;
        obj.listaTitulari = NULL;
    }
    obj.listaTitulari = new Jucator[obj.numarTitulari];
    for (int i = 0; i < obj.numarTitulari; i++) {
        system("CLS");
        std::cout << "Titular " << i << ": \n";
        in >> obj.listaTitulari[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Echipa& obj) {
    out << "Denumire echipa: " << obj.numeEchipa << '\n';
    out << "Abreviere echipa: " << obj.abreviereEchipa << '\n';
    out << "Oras echipa: " << obj.orasEchipa << '\n';
    out << "Numar titular: " << obj.numarTitulari << '\n';
    out << "Numar puncte: " << obj.puncte << '\n';
    out << "Numar victorii: " << obj.victorii << '\n';
    out << "Numar egaluri: " << obj.egaluri << '\n';
    out << "Numar infrangeri: " << obj.infrangeri << '\n';
    out << "Golaveraj: " << obj.golaveraj << '\n';
    for (int i = 0; i < obj.numarTitulari; i++) {
        out <<'\n' << obj.listaTitulari[i];
    }
    return out;
}

Jucator* Echipa::operator[](int i) {
    if (this->listaTitulari == NULL)
        throw std::runtime_error("Nu exista jucatori");
    if (0 > i or i >= this->numarTitulari)
        throw std::runtime_error("Index in afara vectorului");
    return &(this->listaTitulari[i]);
}

Echipa operator+(Echipa ech, Jucator juc) {
    Echipa rezultat(ech);
    rezultat.numarTitulari++;
    if (rezultat.listaTitulari != NULL) {
        delete[] rezultat.listaTitulari;
        rezultat.listaTitulari = NULL;
    }
    rezultat.listaTitulari = new Jucator[rezultat.numarTitulari];
    for (int i = 0; i < rezultat.numarTitulari - 1; i++)
        rezultat.listaTitulari[i] = ech.listaTitulari[i];
    rezultat.listaTitulari[rezultat.numarTitulari - 1] = juc;
    return rezultat;
}

Echipa operator+(Jucator juc, Echipa ech) {
    return ech + juc;
}

Echipa operator-(Echipa ech, Jucator juc) {
    Echipa rezultat(ech);
    for (int j = 0; j < rezultat.numarTitulari; j++)
        if (*rezultat[j] == juc) {
            for (int k = j; k < rezultat.numarTitulari - 1; k++)
                rezultat.listaTitulari[k] = rezultat.listaTitulari[k + 1];
            break;
        }
    rezultat.numarTitulari--;
    Echipa copie(rezultat);
    if (rezultat.listaTitulari != NULL) {
        delete[] rezultat.listaTitulari;
        rezultat.listaTitulari = NULL;
    }
    rezultat.listaTitulari = new Jucator[rezultat.numarTitulari];
    for (int j = 0; j < rezultat.numarTitulari; j++)
        rezultat.listaTitulari[j] = copie.listaTitulari[j];
    return rezultat;
}

Echipa operator-(Jucator juc, Echipa ech) {
    return ech - juc;
}


Echipa Echipa::operator++() {
    Jucator juc;
    std::cout << "Introduceti un jucator:\n";
    std::cin >> juc;
    *this = *this + juc;
    return *this;
}

Echipa Echipa::operator++(int) {
    Echipa copie(*this);
    ++(*this);
    return copie;
}

Echipa Echipa::operator+(const Echipa& obj) {
    Echipa rezultat(*this);
    rezultat.numeEchipa += obj.numeEchipa;
    rezultat.abreviereEchipa += obj.abreviereEchipa;
    if (obj.orasEchipa != NULL) {
        if (rezultat.orasEchipa != NULL) {
            delete[] rezultat.orasEchipa;
            rezultat.orasEchipa = NULL;
        }
        if (this->orasEchipa != NULL) {
            rezultat.orasEchipa = new char[strlen(obj.orasEchipa) + strlen(this->orasEchipa) + 1];
            strcpy(rezultat.orasEchipa, this->orasEchipa);
            strcat(rezultat.orasEchipa, obj.orasEchipa);
        }
        else {
            rezultat.orasEchipa = new char[strlen(obj.orasEchipa) + 1];
            strcpy(rezultat.orasEchipa, obj.orasEchipa);
        }
    }
    rezultat.numarTitulari += obj.numarTitulari;
    rezultat.puncte += obj.puncte;
    rezultat.victorii += obj.victorii;
    rezultat.egaluri += obj.egaluri;
    rezultat.infrangeri += obj.infrangeri;
    rezultat.golaveraj += obj.golaveraj;
    if (rezultat.listaTitulari != NULL) {
        delete[] rezultat.listaTitulari;
        rezultat.listaTitulari = NULL;
    }
    rezultat.listaTitulari = new Jucator[rezultat.numarTitulari];
    for (int i = 0; i < rezultat.numarTitulari; i++) {
        if (i < this->numarTitulari)
            rezultat.listaTitulari[i] = this->listaTitulari[i];
        else
            rezultat.listaTitulari[i] = obj.listaTitulari[i - this->numarTitulari];
    }
    return rezultat;
}

Echipa Echipa::operator+(int x) {
    Echipa rezultat(*this);
    while (x > 0)
    {
        rezultat++;
        x--;
    }
    return rezultat;
}

Echipa operator+(int x, Echipa obj) {
    return obj + x;
}

Echipa Echipa::operator-(const Echipa& obj) {
    Echipa rezultat(*this);
    int cnt = 0, i, j, k = 0;
    if (this->listaTitulari != NULL and obj.listaTitulari != NULL) {
        for (i = 0; i < this->numarTitulari; i++)
            for (j = 0; j < obj.numarTitulari; j++)
                if (this->listaTitulari[i] == obj.listaTitulari[j])
                    cnt++;
    }
    if (cnt != 0) {
        rezultat.numarTitulari -= cnt;
        if (rezultat.listaTitulari != NULL) {
            delete[] rezultat.listaTitulari;
            rezultat.listaTitulari = NULL;
        }
        rezultat.listaTitulari = new Jucator[rezultat.numarTitulari];
        for (i = 0; i < this->numarTitulari; i++)
            for (j = 0; j < obj.numarTitulari; j++)
                if (this->listaTitulari[i] != obj.listaTitulari[j])
                    rezultat.listaTitulari[k++] = this->listaTitulari[i];
    }
    return rezultat;
}

Echipa Echipa::operator-(int x) {
    Echipa rezultat(*this);
    if (rezultat.numarTitulari - x < 0)
        throw std::runtime_error("Scaderea returneaza rezultat negativ");
    rezultat.numarTitulari -= x;
    if (rezultat.listaTitulari != NULL) {
        delete[] rezultat.listaTitulari;
        rezultat.listaTitulari = NULL;
    }
    rezultat.listaTitulari = new Jucator[rezultat.numarTitulari];
    for (int i = 0; i < rezultat.numarTitulari; i++) {
        rezultat.listaTitulari[i] = this->listaTitulari[i];
    }
    return rezultat;
}

Echipa operator-(int x, Echipa obj) {
    return obj + x;
}

Echipa::operator int() {
    return this->puncte;
}

bool Echipa::operator==(const Echipa& obj) {
    if (this->numeEchipa != obj.numeEchipa)
        return false;
    if (this->abreviereEchipa != obj.abreviereEchipa)
        return false;
    if (this->orasEchipa != NULL and obj.orasEchipa != NULL) {
        if (strlen(this->orasEchipa) != strlen(obj.orasEchipa))
            return false;
        for (int i = 0; i < strlen(this->orasEchipa); i++)
            if (this->orasEchipa[i] != obj.orasEchipa[i])
                return false;
    }
    else
        if (this->orasEchipa != NULL or obj.orasEchipa != NULL)
            return false;
    if (this->puncte != obj.puncte)
        return false;
    if (this->victorii != obj.victorii)
        return false;
    if (this->egaluri != obj.egaluri)
        return false;
    if (this->infrangeri != obj.infrangeri)
        return false;
    if (this->golaveraj != obj.golaveraj)
        return false;
    if (this->numarTitulari != obj.numarTitulari)
        return false;
    if (this->listaTitulari != NULL and obj.listaTitulari != NULL) {
        for (int i = 0; i < this->numarTitulari; i++)
            if (this->listaTitulari[i] != obj.listaTitulari[i])
                return false;
    }
    else
        if (this->listaTitulari != NULL or obj.listaTitulari != NULL)
            return false;
    return true;
}

bool Echipa::operator<(const Echipa& obj) {
    return this->puncte < obj.puncte;
}

Echipa::~Echipa() {
    if (this->orasEchipa != NULL) {
        delete[] this->orasEchipa;
        this->orasEchipa = NULL;
    }
    if (this->listaTitulari != NULL) {
        delete[] this->listaTitulari;
        this->listaTitulari = NULL;
    }
}

class Competitie {
    static int cID;
    const int id;
    char* denumire;
    int numarEchipe;
    Echipa* listaEchipe;
public:
    Competitie();
    Competitie(int, Echipa*);
    Competitie(char*, int, Echipa*);
    Competitie(const Competitie&);

    Competitie& operator=(const Competitie&);
    friend std::istream& operator>>(std::istream&, Competitie&);
    friend std::ostream& operator<<(std::ostream&, const Competitie&);
    friend Competitie operator-(Competitie, Echipa);
    friend Competitie operator-(Echipa, Competitie);
    Echipa* operator[](int);
    Competitie operator++();
    Competitie operator++(int);
    Competitie operator+(const Competitie&);
    Competitie operator+(int x);
    friend Competitie operator+(int, Competitie);
    Competitie operator-(const Competitie&);
    Competitie operator-(int);
    friend Competitie operator-(int, Competitie);
    operator int();
    bool operator<(const Competitie&);
    bool operator==(const Competitie&);

    void clasament();

    void setDenumire(char*);
    void setNrEchipe(int);
    char* getDenumire();
    int getNrEchipe();
    Echipa* getEchipe();

    ~Competitie();

};

int Competitie::cID = 1;

Competitie::Competitie() :id(cID++) {
    this->denumire = new char[strlen("Nedefinit") + 1];
    strcpy(this->denumire, "Nedefinit");
    this->numarEchipe = 0;
    this->listaEchipe = NULL;
}

Competitie::Competitie(int numarEchipe, Echipa* listaEchipe) :id(cID++) {
    this->denumire = new char[strlen("Nedefinit") + 1];
    strcpy(this->denumire, "Nedefinit");
    this->numarEchipe = numarEchipe;
    this->listaEchipe = new Echipa[numarEchipe];
    for (int i = 0; i < numarEchipe; i++) {
        this->listaEchipe[i] = listaEchipe[i];
    }
}

Competitie::Competitie(char* denumire, int numarEchipe, Echipa* listaEchipe) :id(cID++) {
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
    this->numarEchipe = numarEchipe;
    this->listaEchipe = new Echipa[numarEchipe];
    for (int i = 0; i < numarEchipe; i++) {
        this->listaEchipe[i] = listaEchipe[i];
    }
}

Competitie::Competitie(const Competitie& obj) :id(obj.id) {
    this->denumire = new char[strlen(obj.denumire) + 1];
    strcpy(this->denumire, obj.denumire);
    this->numarEchipe = obj.numarEchipe;
    this->listaEchipe = new Echipa[obj.numarEchipe];
    for (int i = 0; i < obj.numarEchipe; i++) {
        this->listaEchipe[i] = obj.listaEchipe[i];
    }
}

Competitie& Competitie::operator=(const Competitie& obj) {
    if (this != &obj) {
        if (this->denumire != NULL) {
            delete[] this->denumire;
            this->denumire = NULL;
        }
        this->denumire = new char[strlen(obj.denumire) + 1];
        strcpy(this->denumire, obj.denumire);
        this->numarEchipe = obj.numarEchipe;
        if (this->listaEchipe != NULL) {
            delete[] this->listaEchipe;
            this->listaEchipe = NULL;
        }
        this->listaEchipe = new Echipa[obj.numarEchipe];
        for (int i = 0; i < obj.numarEchipe; i++) {
            this->listaEchipe[i] = obj.listaEchipe[i];
        }
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Competitie& obj) {
    std::cout << "Introduceti:" << '\n';
    std::cout << "Denumire competitie: ";
    char denumire[100];
    //in.getline(denumire, 100);
    in >> denumire;
    if (obj.denumire != NULL) {
        delete[] obj.denumire;
        obj.denumire = NULL;
    }
    obj.denumire = new char[strlen(denumire) + 1];
    strcpy(obj.denumire, denumire);
    std::cout << "Numar echipe: ";
    in >> obj.numarEchipe;
    if (obj.listaEchipe != NULL) {
        delete[] obj.listaEchipe;
        obj.listaEchipe = NULL;
    }
    obj.listaEchipe = new Echipa[obj.numarEchipe];
    for (int i = 0; i < obj.numarEchipe; i++) {
        system("CLS");
        std::cout << "Echipa " << i + 1 << ": " << '\n';
        in >> obj.listaEchipe[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Competitie& obj) {
    out << "ID: " << obj.id << '\n';
    out << "Denumire: " << obj.denumire << '\n';
    out << "Numar echipe: " << obj.numarEchipe << '\n';
    for (int i = 0; i < obj.numarEchipe; i++)
        out << "\nEchipa " << i << ": " << obj.listaEchipe[i];
    return out;
}

Echipa* Competitie::operator[](int i) {
    if (this->listaEchipe == NULL)
        throw std::runtime_error("Nu exista echipe");
    if (this->numarEchipe <= i or i < 0)
        throw std::runtime_error("Index in afara vectorului");
    return &(this->listaEchipe[i]);
}

Competitie operator-(Competitie comp, Echipa ech) {
    Competitie rezultat(comp);
    for (int j = 0; j < rezultat.numarEchipe; j++)
        if (*rezultat[j] == ech) {
            for (int k = j; k < rezultat.numarEchipe - 1; k++)
                rezultat.listaEchipe[k] = rezultat.listaEchipe[k + 1];
            break;
        }
    rezultat.numarEchipe--;
    Competitie copie(rezultat);
    if (rezultat.listaEchipe != NULL) {
        delete[] rezultat.listaEchipe;
        rezultat.listaEchipe = NULL;
    }
    rezultat.listaEchipe = new Echipa[rezultat.numarEchipe];
    for (int j = 0; j < rezultat.numarEchipe; j++)
        rezultat.listaEchipe[j] = copie.listaEchipe[j];
    return rezultat;
}

Competitie operator-(Echipa ech, Competitie comp) {
    return comp - ech;
}

Competitie Competitie::operator++() {
    Competitie copie = *this;
    this->numarEchipe++;
    if (this->listaEchipe != NULL) {
        delete[] this->listaEchipe;
        this->listaEchipe = NULL;
    }
    this->listaEchipe = new Echipa[this->numarEchipe];
    for (int i = 0; i < copie.numarEchipe; i++)
        this->listaEchipe[i] = copie.listaEchipe[i];
    std::cout << "Adaugati o echipa: " << '\n';
    std::cin >> this->listaEchipe[this->numarEchipe - 1];
    return *this;
}

Competitie Competitie::operator++(int) {
    Competitie copie = *this;
    ++* this;
    return copie;
}

Competitie Competitie::operator+(const Competitie& obj) {
    Competitie rezultat(*this);
    if (obj.denumire != NULL) {
        if (rezultat.denumire != NULL) {
            delete[] rezultat.denumire;
            rezultat.denumire = NULL;
        }
        if (this->denumire != NULL) {
            rezultat.denumire = new char[strlen(this->denumire) + strlen(obj.denumire) + 1];
            strcpy(rezultat.denumire, this->denumire);
            strcat(rezultat.denumire, obj.denumire);
        }
        else {
            rezultat.denumire = new char[strlen(obj.denumire) + 1];
            strcpy(rezultat.denumire, obj.denumire);
        }
    }
    rezultat.numarEchipe = this->numarEchipe + obj.numarEchipe;
    if (rezultat.listaEchipe != NULL) {
        delete[] rezultat.listaEchipe;
        rezultat.listaEchipe = NULL;
    }
    rezultat.listaEchipe = new Echipa[rezultat.numarEchipe];
    for (int i = 0; i < rezultat.numarEchipe; i++) {
        if (i < this->numarEchipe)
            rezultat.listaEchipe[i] = this->listaEchipe[i];
        else
            rezultat.listaEchipe[i] = obj.listaEchipe[i - this->numarEchipe];
    }
    return rezultat;
}

Competitie Competitie::operator+(int x)
{
    Competitie rezultat(*this);
    rezultat.numarEchipe += x;
    if (rezultat.listaEchipe != NULL) {
        delete[] rezultat.listaEchipe;
        rezultat.listaEchipe = NULL;
    }
    rezultat.listaEchipe = new Echipa[rezultat.numarEchipe];
    for (int i = 0; i < rezultat.numarEchipe; i++)
        if (i < this->numarEchipe and this->listaEchipe != NULL)
            rezultat.listaEchipe[i] = this->listaEchipe[i];
        else {
            std::cout << "Adaugati o echipa: " << '\n';
            std::cin >> rezultat.listaEchipe[i];
        }
    return rezultat;
}

Competitie operator+(int x, Competitie obj) {
    return obj + x;
}

Competitie Competitie::operator-(const Competitie& obj) {
    Competitie rezultat(*this);
    int cnt = 0, i, j, k = 0;
    if (this->listaEchipe != NULL and obj.listaEchipe != NULL) {
        for (i = 0; i < this->numarEchipe; i++)
            for (j = 0; j < obj.numarEchipe; j++)
                if (this->listaEchipe[i] == obj.listaEchipe[j])
                    cnt++;
    }
    if (cnt != 0) {
        rezultat.numarEchipe -= cnt;
        if (rezultat.listaEchipe != NULL) {
            delete[] rezultat.listaEchipe;
            rezultat.listaEchipe = NULL;
        }
        rezultat.listaEchipe = new Echipa[rezultat.numarEchipe];
        for (i = 0; i < this->numarEchipe; i++)
            for (j = 0; j < obj.numarEchipe; j++)
                if (this->listaEchipe[i] != obj.listaEchipe[j])
                    rezultat.listaEchipe[k++] = this->listaEchipe[i];
    }
    return rezultat;
}

Competitie Competitie::operator-(int x) {
    if (this->numarEchipe - x < 0)
        throw std::runtime_error("Numarul de echipe este insuficient");
    return *this + (-x);
}

Competitie operator-(int x, Competitie obj) {
    return obj - x;
}

Competitie::operator int() {
    return this->numarEchipe;
}

bool Competitie::operator<(const Competitie& obj) {
    if (this->numarEchipe < obj.numarEchipe)
        return true;
    else
        return false;
}

bool Competitie::operator==(const Competitie& obj) {
    int i;
    if (this->denumire != NULL and obj.denumire != NULL) {
        if (strlen(this->denumire) != strlen(obj.denumire))
            return false;
        for (i = 0; i < strlen(this->denumire); i++) {
            if (this->denumire[i] != obj.denumire[i])
                return false;
        }
    }
    else
        return false;
    if (this->numarEchipe != obj.numarEchipe)
        return false;
    if (this->listaEchipe != NULL and obj.listaEchipe != NULL)
        for (i = 0; i < this->numarEchipe; i++)
            if (this->listaEchipe[i] != obj.listaEchipe[i])
                return false;
    return true;
}

void Competitie::setDenumire(char* denumire)
{
    if (this->denumire != NULL) {
        delete[] this->denumire;
        this->denumire = NULL;
    }
    this->denumire = new char[strlen(denumire) + 1];
    strcpy(this->denumire, denumire);
}

void Competitie::setNrEchipe(int x) {
    this->numarEchipe = x;
    if (this->listaEchipe != NULL) {
        delete[] this->listaEchipe;
        this->listaEchipe = NULL;
    }
    this->listaEchipe = new Echipa[x];
    for (int i = 0; i < x; i++) {
        std::cout << "Adaugati o echipa: " << '\n';
        std::cin >> this->listaEchipe[i];
    }
}

char* Competitie::getDenumire() {
    if (this->denumire == NULL)
        throw std::runtime_error("Competitia nu are nume");
    return this->denumire;
}

int Competitie::getNrEchipe() {
    return this->numarEchipe;
}

Echipa* Competitie::getEchipe() {
    if (this->listaEchipe == NULL)
        throw std::runtime_error("Competitia nu are echipe");
    return this->listaEchipe;
}

void Competitie::clasament() {
    Echipa* listae;
    listae = new Echipa[this->numarEchipe];
    for (int i = 0; i < this->numarEchipe; i++) {
        listae[i] = this->listaEchipe[i];
    }
    std::cout << "E\tP\tG\t\n";
    int n = this->numarEchipe, mxp = -1, mxg = -1;
    while (n > 0) {
        mxp = -1;
        mxg = -1;
        for (int i = 0; i < n; i++) {
            if (listae[i].getNrPuncte() > mxp)
            {
                mxp = listae[i].getNrPuncte();
                mxg = listae[i].getGolaveraj();
            }
            else
                if (listae[i].getNrPuncte() == mxp and listae[i].getGolaveraj() > mxg) {
                    mxg = listae[i].getGolaveraj();
                }
        }
        for (int i = 0; i < n; i++) {
            if (listae[i].getNrPuncte() == mxp and listae[i].getGolaveraj() == mxg) {
                std::cout << listae[i].getAbreviere() << '\t' << listae[i].getNrPuncte() << '\t' << listae[i].getGolaveraj() << '\n';
                for (int j = i; j < n - 1; j++)
                {
                    listae[j] = listae[j + 1];
                }
                break;
            }
        }
        n--;
    }
    delete[] listae;
}

Competitie::~Competitie() {
    if (this->denumire != NULL) {
        delete[] this->denumire;
        this->denumire = NULL;
    }
    if (this->listaEchipe != NULL) {
        delete[] this->listaEchipe;
        this->listaEchipe = NULL;
    }
}

class Meci {
    Echipa* echipa1;
    Echipa* echipa2;
    int* listaJucatori1;
    int* listaJucatori2;
    int scorEchipa1, scorEchipa2, nrevenimente, minut;
    char evenimente[100][100];
public:
    Meci();
    Meci(Echipa*, Echipa*);

    friend std::ostream& operator<<(std::ostream&, const Meci&);

    void simulareMeci();

    ~Meci();
};

Meci::Meci() {
    this->echipa1 = NULL;
    this->echipa2 = NULL;
    this->listaJucatori1 = NULL;
    this->listaJucatori2 = NULL;
    this->scorEchipa1 = 0;
    this->scorEchipa2 = 0;
    this->nrevenimente = 0;
    this->minut = 0;
}

Meci::Meci(Echipa* echipa1, Echipa* echipa2) {
    this->echipa1 = echipa1;
    this->echipa2 = echipa2;
    this->listaJucatori1 = new int[echipa1->getNrJucatori()];
    this->listaJucatori2 = new int[echipa2->getNrJucatori()];
    int i;
    for (i = 0; i < echipa1->getNrJucatori(); i++)
        this->listaJucatori1[i] = int(echipa1[i]);
    for (i = 0; i < echipa2->getNrJucatori(); i++)
        this->listaJucatori2[i] = int(echipa2[i]);
    this->scorEchipa1 = 0;
    this->scorEchipa2 = 0;
    this->nrevenimente = 0;
    this->minut = 0;
}

std::ostream& operator<<(std::ostream& out, const Meci& obj) {
    out << obj.echipa1->getAbreviere() << ' ' << obj.scorEchipa1 << "        " << '-' << "        " << obj.scorEchipa2 << ' ' << obj.echipa2->getAbreviere();
    out << "\n             " << obj.minut;
    out << "\n---------------------------\n";
    for (int i = 0; i < obj.nrevenimente; i++) {
        out << "\n|";
        out << "\n|" << obj.evenimente[i];
    }
    return out;
}

void Meci::simulareMeci() {
    int c1r = 0, c2r = 0;
    //srand(time(NULL));
    for (int i = 0; i < this->echipa1[0].getNrJucatori(); i++)
        this->echipa1[0][i][0].setCartonasRosu(false);
    for (int i = 0; i < this->echipa2[0].getNrJucatori(); i++)
        this->echipa2[0][i][0].setCartonasRosu(false);
    if (this->echipa1[0].getNrJucatori() == 0 or this->echipa2[0].getNrJucatori() == 0)
        std::cout << "Nu sunt destui jucatori pentru a incepe meciul!";
    else
    {
        int i, event;
        for (i = 0; i <= 90; i++)
        {
            this->minut = i;
            event = rand() % 100;
            if (event == 1 or event == 2)
            {
                this->scorEchipa1++;
                int juc;
                do {
                    juc = rand() % this->echipa1->getNrJucatori();
                } while (this->echipa1[0][juc]->getPozitie() == 'P' or this->echipa1[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'GOL:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], this->echipa1[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa1->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                (*this->echipa1[0][juc])++;
                this->nrevenimente++;
            }
            if (event == 3 or event == 4)
            {
                this->scorEchipa2++;
                int juc;
                do {
                    juc = rand() % this->echipa2->getNrJucatori();
                } while (this->echipa2[0][juc]->getPozitie() == 'P' or this->echipa2[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'GOL:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], echipa2[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa2->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                (*this->echipa2[0][juc])++;
                this->nrevenimente++;
            }
            if (event == 5 or event == 6) {
                int juc;
                do {
                    juc = rand() % this->echipa1->getNrJucatori();
                } while (this->echipa1[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'CARTONAS GALBEN:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], this->echipa1[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa1->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                this->echipa2[0][juc][0].cresteCGalbene();
                /*this->echipa1[0][juc][0].douaGalbene();
                if (this->echipa1[0][juc][0].getCartonasRosu())
                   event = 11;*/
                this->nrevenimente++;
            }
            if (event == 8 or event == 9) {
                int juc;
                do {
                    juc = rand() % this->echipa2->getNrJucatori();
                } while (this->echipa2[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'CARTONAS GALBEN:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], this->echipa2[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa2->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                this->echipa2[0][juc]->cresteCGalbene();
                /*this->echipa2[0][juc][0].douaGalbene();
                if (this->echipa2[0][juc][0].getCartonasRosu())
                    event = 12;*/
                this->nrevenimente++;
            }
            if (event == 11) {
                int juc;
                do {
                    juc = rand() % this->echipa1->getNrJucatori();
                } while (this->echipa1[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'CARTONAS ROSU:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], this->echipa1[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa1->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                this->echipa1[0][juc]->setCartonasRosu(true);
                this->echipa1[0][juc]->cresteCRosii();
                c1r++;
                this->nrevenimente++;
            }
            if (event == 12) {
                int juc;
                do {
                    juc = rand() % this->echipa2->getNrJucatori();
                } while (this->echipa2[0][juc]->getCartonasRosu() == true);
                char s[50 + sizeof(char)];
                std::sprintf(s, "%d'CARTONAS ROSU:", i);
                strcpy(this->evenimente[this->nrevenimente], s);
                strcat(this->evenimente[this->nrevenimente], this->echipa2[0][juc]->getNume().c_str());
                strcat(this->evenimente[this->nrevenimente], "(");
                strcat(this->evenimente[this->nrevenimente], this->echipa2->getAbreviere().c_str());
                strcat(this->evenimente[this->nrevenimente], ")");
                this->echipa2[0][juc]->setCartonasRosu(true);
                this->echipa2[0][juc]->cresteCRosii();
                c2r++;
                this->nrevenimente++;
            }
            Sleep(400);
            system("CLS");
            if (c1r == this->echipa1[0].getNrJucatori())
            {
                this->scorEchipa2 = 3;
                this->scorEchipa1 = 0;
                this->echipa2[0].cresteVictorii();
                this->echipa2[0].calculPuncte();
                std::cout << (*this);
                std::cout << "\nMeci oprit din cauza lipsei de jucatori disponibili in echipa " << this->echipa1->getAbreviere() << '\n';
                return;
            }
            if (c2r == this->echipa2[0].getNrJucatori())
            {
                this->scorEchipa1 = 3;
                this->scorEchipa2 = 0;
                this->echipa1[0].cresteVictorii();
                this->echipa1[0].calculPuncte();
                std::cout << (*this);
                std::cout << "\nMeci oprit din cauza lipsei de jucatori disponibili in echipa " << this->echipa2->getAbreviere() << '\n';
                return;
            }
            std::cout << (*this);
        }
        for (i = 0; i < this->echipa1[0].getNrJucatori(); i++)
            this->echipa1[0][i][0].setCartonasRosu(false);
        for (i = 0; i < this->echipa2[0].getNrJucatori(); i++)
            this->echipa2[0][i][0].setCartonasRosu(false);
        this->echipa1[0].cresteGolaveraj(this->scorEchipa1 - this->scorEchipa2);
        this->echipa2[0].cresteGolaveraj(this->scorEchipa2 - this->scorEchipa1);
        if (this->scorEchipa1 > this->scorEchipa2) {
            this->echipa1[0].cresteVictorii();
            this->echipa1[0].calculPuncte();
            this->echipa2[0].cresteInfrangeri();
        }
        else
            if (this->scorEchipa1 < this->scorEchipa2) {
                this->echipa2[0].cresteVictorii();
                this->echipa2[0].calculPuncte();
                this->echipa1[0].cresteInfrangeri();
            }
            else {
                this->echipa1[0].cresteEgaluri();
                this->echipa2[0].cresteEgaluri();
                this->echipa1[0].calculPuncte();
                this->echipa2[0].calculPuncte();
            }
    }
}

Meci::~Meci() {
    if (this->echipa1 != NULL) {
        //delete this->echipa1;
        this->echipa1 = NULL;
    }
    if (this->echipa2 != NULL) {
        //delete this->echipa2;
        this->echipa2 = NULL;
    }
    if (this->listaJucatori1 != NULL) {
        delete[] this->listaJucatori1;
        this->listaJucatori1 = NULL;
    }
    if (this->listaJucatori2 != NULL) {
        delete[] this->listaJucatori2;
        this->listaJucatori2 = NULL;
    }
}

void Meniu() {
    Competitie* comp;
    int n, numarCompetitii, k, i, l, e, j, e2;
    std::cout << "Bine ati venit!\nApasati orice tasta pentru a crea o liga\n";
    std::cin >> n;
    system("CLS");
    numarCompetitii = 1;
    comp = new Competitie[numarCompetitii];
    std::cin >> comp[0];
    while (true) {
        system("CLS");
        std::cout << "Meniu ligi 0\nMeniu echipe 1\nMeniu jucatori 2\nSimulare meci 3\nExit 4\n";
        std::cin >> k;
        if (k == 4)
            break;
        while (true) {
            system("CLS");
            for (i = 0; i < numarCompetitii; i++) {
                std::cout << comp[i].getDenumire() << " " << i << '\n';
            }
            std::cout << "Inapoi " << i<<'\n';
            std::cin >> l;
            if (l == i)
                break;
            if (k == 0) {
                while (true) {
                    system("CLS");
                    std::cout << "Adaugare o competitie noua 0\nAdaugati o echipa in competitia curenta 1\nVizualizare clasamentul competitiei curenta 2\nInapoi 3\n";
                    int o;
                    std::cin >> o;
                    if (o == 0) {
                        system("CLS");
                        Competitie* copie;
                        copie = new Competitie[numarCompetitii + 1];
                        for (i = 0; i < numarCompetitii; i++)
                            copie[i] = comp[i];
                        std::cin >> copie[i];
                        delete[] comp;
                        comp = NULL;
                        comp = new Competitie[numarCompetitii + 1];
                        numarCompetitii++;
                        for (i = 0; i < numarCompetitii; i++)
                            comp[i] = copie[i];
                        delete[]copie;
                        copie = NULL;
                    }
                    if (o == 1) {
                        system("CLS");
                        comp[l]++;
                    }
                    if (o == 2) {
                        system("CLS");
                        comp[l].clasament();
                        std::cout << "Pentru a iesi apasati orice tasta\n";
                        int t;
                        std::cin >> t;
                    }
                    if (o == 3) {
                        break;
                    }
                }
            }
            else {
                while (true) {
                    system("CLS");
                    int t;
                    for (t = 0; t < comp[l].getNrEchipe(); t++) {
                        std::cout << comp[l][t]->getNumeEchipa() << " " << t << '\n';
                    }
                    std::cout << "Inapoi " << t<<'\n';
                    std::cin >> e;
                    if (e == t)
                        break;
                    if (k == 1) {
                        int o2;
                        while (true) {
                            system("CLS");
                            std::cout << "Vizualizare echipa 0\nAdaugare jucator 1\nEliminare jucator 2\nStergeti echipa 3\nInapoi 4\n";
                            std::cin >> o2;
                            if (o2 == 4)
                                break;
                            if (o2 == 0) {
                                system("CLS");
                                std::cout << *comp[l][e];
                                std::cout << "\nPentru a iesi apasati orice tasta\n";
                                int t2;
                                std::cin >> t2;
                            }
                            if (o2 == 1) {
                                system("CLS");
                                (*comp[l][e])++;
                            }
                            if (o2 == 2) {
                                system("CLS");
                                for (j = 0; j < comp[l][e]->getNrJucatori(); j++) {
                                    std::cout << comp[l][e][0][j]->getNume() << " " << comp[l][e][0][j]->getPrenume() << " " << j << '\n';
                                }
                                int j1;
                                std::cin >> j1;
                                if (j1 == j)
                                    break;
                                *comp[l][e] = *comp[l][e] - *comp[l][e][0][j1];
                            }
                            if (o2 == 3) {
                                comp[l] = comp[l] - *comp[l][e];
                                break;
                            }
                        }
                        break;
                    }
                    if (k == 3) {
                        system("CLS");
                        std::cout << "Selectati si a doua echipa:\n";
                        for (t = 0; t < comp[l].getNrEchipe(); t++) {
                            if (t != e)
                                std::cout << comp[l][t]->getNumeEchipa() << " " << t << '\n';
                        }
                        std::cin >> e2;
                        Meci m(comp[l][e], comp[l][e2]);
                        m.simulareMeci();
                        std::cout << "\nPentru a iesi apasati orice tasta\n";
                        int t2;
                        std::cin >> t2;
                    }
                    else {
                        while (true) {
                            system("CLS");
                            for (j = 0; j < comp[l][e]->getNrJucatori(); j++) {
                                std::cout << comp[l][e][0][j]->getNume() << " " << comp[l][e][0][j]->getPrenume() << " " << j << '\n';
                            }
                            std::cout << "Inapoi " << j << '\n';
                            int j1;
                            std::cin >> j1;
                            if (j1 == j)
                                break;
                            if (k == 2) {
                                while (true) {
                                    system("CLS");
                                    std::cout << *comp[l][e][0][j1];
                                    std::cout << "\nPentru a iesi apasati orice tasta\n";
                                    int t2;
                                    std::cin >> t2;
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }
    }
    delete[] comp;
    comp = NULL;
}

int main()
{
    Meniu();
    return 0;
}
