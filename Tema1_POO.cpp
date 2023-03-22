#include <iostream>
#include <cstring>
#include <stdlib.h>

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

    Jucator& operator=(const Jucator&);
    friend std::istream& operator>>(std::istream&, Jucator&);
    friend std::ostream& operator<<(std::ostream&, const Jucator&);
    //Jucator operator[](int);
    //friend Echipa operator+(Echipa, Jucator);
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

    void douaGalbene() { if (this->numarCGalbene == 2) this->numarCRosii++, this->cartonasRosu = true; }

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
    std::cout << "Numar goluri: ";
    in >> obj.numarGoluri;
    std::cout << "Numar cartonase galbene: ";
    in >> obj.numarCGalbene;
    std::cout << "Numar cartonase rosii: ";
    in >> obj.numarCRosii;
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
    (*this)++;
    return copie;
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

class Echipa {
    static int cIDEchipa;
    const int idEchipa;
    std::string numeEchipa;
    std::string abreviereEchipa;
    char* orasEchipa;
    int numarTitulari, numarRezerve, puncte, victorii, egaluri, infrangeri, golaveraj;
    Jucator* listaTitulari;
    Jucator* listaRezerve;
public:
    Echipa();
    Echipa(std::string, std::string, char*);
    Echipa(std::string, std::string, char*, int, int, Jucator*, Jucator*);
    Echipa(std::string, std::string, char*, int, int, int, int, int, int, int, Jucator*, Jucator*);
    Echipa(const Echipa&);

    Echipa& operator=(const Echipa&);
    friend std::istream& operator>>(std::istream&, Echipa&);
    friend std::ostream& operator<<(std::ostream&, const Echipa&);
    Jucator operator[](int);
    friend Echipa operator+(Echipa, Jucator);
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

    void calculPuncte();

    //~Echipa();
};

int Echipa::cIDEchipa = 1;

Echipa::Echipa() :idEchipa(cIDEchipa++) {
    this->numeEchipa = "Nedefinit";
    this->abreviereEchipa = "NEDEF";
    this->orasEchipa = new char[strlen("Nedefinit") + 1];
    strcpy(this->orasEchipa, "Nedefinit");
    this->numarTitulari = 0;
    this->numarRezerve = 0;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = NULL;
    this->listaRezerve = NULL;
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = 0;
    this->numarRezerve = 0;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = NULL;
    this->listaRezerve = NULL;
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa, int numarTitulari, int numarRezerve, Jucator* listaTitulari, Jucator* listaRezerve) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = numarTitulari;
    this->numarRezerve = numarRezerve;
    this->puncte = 0;
    this->victorii = 0;
    this->egaluri = 0;
    this->infrangeri = 0;
    this->golaveraj = 0;
    this->listaTitulari = new Jucator[numarTitulari];
    for (int i = 0; i < numarTitulari; i++) {
        this->listaTitulari[i] = listaTitulari[i];
    }
    this->listaRezerve = new Jucator[numarRezerve];
    for (int i = 0; i < numarRezerve; i++) {
        this->listaRezerve[i] = listaRezerve[i];
    }
}

Echipa::Echipa(std::string numeEchipa, std::string abreviereEchipa, char* orasEchipa, int numarTitulari, int numarRezerve, int puncte, int victorii, int egaluri, int infrangeri, int golaveraj, Jucator* listaTitulari, Jucator* listaRezerve) :idEchipa(cIDEchipa++) {
    this->numeEchipa = numeEchipa;
    this->abreviereEchipa = abreviereEchipa;
    this->orasEchipa = new char[strlen(orasEchipa) + 1];
    strcpy(this->orasEchipa, orasEchipa);
    this->numarTitulari = numarTitulari;
    this->numarRezerve = numarRezerve;
    this->puncte = puncte;
    this->victorii = victorii;
    this->egaluri = egaluri;
    this->infrangeri = infrangeri;
    this->golaveraj = golaveraj;
    this->listaTitulari = new Jucator[numarTitulari];
    for (int i = 0; i < numarTitulari; i++) {
        this->listaTitulari[i] = listaTitulari[i];
    }
    this->listaRezerve = new Jucator[numarRezerve];
    for (int i = 0; i < numarRezerve; i++) {
        this->listaRezerve[i] = listaRezerve[i];
    }
}

Echipa::Echipa(const Echipa& obj) :idEchipa(obj.idEchipa) {
    this->numeEchipa = obj.numeEchipa;
    this->abreviereEchipa = obj.abreviereEchipa;
    this->orasEchipa = new char[strlen(obj.orasEchipa) + 1];
    strcpy(this->orasEchipa, obj.orasEchipa);
    this->numarTitulari = obj.numarTitulari;
    this->numarRezerve = obj.numarRezerve;
    this->puncte = obj.puncte;
    this->victorii = obj.victorii;
    this->egaluri = obj.egaluri;
    this->infrangeri = obj.infrangeri;
    this->golaveraj = obj.golaveraj;
    this->listaTitulari = new Jucator[obj.numarTitulari];
    for (int i = 0; i < obj.numarTitulari; i++) {
        this->listaTitulari[i] = obj.listaTitulari[i];
    }
    this->listaRezerve = new Jucator[obj.numarRezerve];
    for (int i = 0; i < obj.numarRezerve; i++) {
        this->listaRezerve[i] = obj.listaRezerve[i];
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
    this->numarRezerve = obj.numarRezerve;
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
    if (this->listaRezerve != NULL) {
        delete[] this->listaRezerve;
        this->listaRezerve = NULL;
    }
    this->listaRezerve = new Jucator[obj.numarRezerve];
    for (int i = 0; i < obj.numarRezerve; i++) {
        this->listaRezerve[i] = obj.listaRezerve[i];
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
    std::cout << "Numar titular: ";
    in >> obj.numarTitulari;
    std::cout << "Numar rezerve: ";
    in >> obj.numarRezerve;
    do {
        std::cout << "Numar puncte: ";
        in >> obj.puncte;
        std::cout << "Numar victorii: ";
        in >> obj.victorii;
        std::cout << "Numar egaluri: ";
        in >> obj.egaluri;
        std::cout << "Numar infrangeri: ";
        in >> obj.infrangeri;
    } while (3 * obj.victorii + obj.egaluri != obj.puncte);
    std::cout << "Golaveraj: ";
    in >> obj.golaveraj;
    if (obj.listaTitulari != NULL) {
        delete[] obj.listaTitulari;
        obj.listaTitulari = NULL;
    }
    obj.listaTitulari = new Jucator[obj.numarTitulari];
    for (int i = 0; i < obj.numarTitulari; i++) {
        std::cout << "Titular " << i << ": ";
        in >> obj.listaTitulari[i];
    }
    if (obj.listaRezerve != NULL) {
        delete[] obj.listaRezerve;
        obj.listaRezerve = NULL;
    }
    obj.listaRezerve = new Jucator[obj.numarRezerve];
    for (int i = 0; i < obj.numarRezerve; i++) {
        std::cout << "RES: ";
        in >> obj.listaRezerve[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Echipa& obj) {
    out << "Denumire echipa: " << obj.numeEchipa << '\n';
    out << "Abreviere echipa: " << obj.abreviereEchipa << '\n';
    out << "Oras echipa: " << obj.orasEchipa << '\n';
    out << "Numar titular: " << obj.numarTitulari << '\n';
    out << "Numar rezerve: " << obj.numarRezerve << '\n';
    out << "Numar puncte: " << obj.puncte << '\n';
    out << "Numar victorii: " << obj.victorii << '\n';
    out << "Numar egaluri: " << obj.egaluri << '\n';
    out << "Numar infrangeri: " << obj.infrangeri << '\n';
    out << "Golaveraj: " << obj.golaveraj << '\n';
    for (int i = 0; i < obj.numarTitulari; i++) {
        out << obj.listaTitulari[i];
    }
    for (int i = 0; i < obj.numarRezerve; i++) {
        out << obj.listaRezerve[i];
    }
    return out;
}

Jucator Echipa::operator[](int i) {
    if (this->listaTitulari == NULL and this->listaRezerve == NULL)
        throw std::runtime_error("Nu exista jucatori");
    if (this->listaTitulari != NULL) {
        for (int j = 0; j < numarTitulari; j++)
            if (int(this->listaTitulari[j]) == i)
                return this->listaTitulari[j];
    }
    else
        if (this->listaRezerve != NULL) {
            for (int j = 0; j < numarRezerve; j++)
                if (int(this->listaRezerve[j]) == i)
                    return this->listaRezerve[j];
        }
        else
            throw std::runtime_error("Niciun jucator nu poarta tricoul cu numarul i");
}

Echipa operator+(Echipa ech, Jucator juc) {
    Echipa rezultat(ech);
    rezultat.numarRezerve++;
    if (rezultat.listaRezerve != NULL) {
        delete[] rezultat.listaRezerve;
        rezultat.listaRezerve = NULL;
    }
    rezultat.listaRezerve = new Jucator[rezultat.numarRezerve];
    for (int i = 0; i < rezultat.numarRezerve - 1; i++)
        rezultat.listaRezerve[i] = ech.listaRezerve[i];
    rezultat.listaRezerve[rezultat.numarRezerve - 1] = juc;
    return rezultat;
}

Echipa Echipa::operator++() {
    Jucator juc;
    std::cout << "Introduceti un jucator:\n";
    std::cin >> juc;
    return *this + juc;
}

Echipa Echipa::operator++(int) {
    Echipa copie(*this);
    (* this)++;
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
    rezultat.numarRezerve += obj.numarRezerve;
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
    if (rezultat.listaRezerve != NULL) {
        delete[] rezultat.listaRezerve;
        rezultat.listaRezerve = NULL;
    }
    rezultat.listaRezerve = new Jucator[rezultat.numarRezerve];
    for (int i = 0; i < rezultat.numarRezerve; i++) {
        if (i < this->numarRezerve)
            rezultat.listaRezerve[i] = this->listaRezerve[i];
        else
            rezultat.listaRezerve[i] = obj.listaRezerve[i - this->numarRezerve];
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
    cnt = 0;
    k = 0;
    if (this->listaRezerve != NULL and obj.listaRezerve != NULL) {
        for (i = 0; i < this->numarRezerve; i++)
            for (j = 0; j < obj.numarRezerve; j++)
                if (this->listaRezerve[i] == obj.listaRezerve[j])
                    cnt++;
    }
    if (cnt != 0) {
        rezultat.numarRezerve -= cnt;
        if (rezultat.listaRezerve != NULL) {
            delete[] rezultat.listaRezerve;
            rezultat.listaRezerve = NULL;
        }
        rezultat.listaRezerve = new Jucator[rezultat.numarRezerve];
        for (i = 0; i < this->numarRezerve; i++)
            for (j = 0; j < obj.numarRezerve; j++)
                if (this->listaRezerve[i] != obj.listaRezerve[j])
                    rezultat.listaRezerve[k++] = this->listaRezerve[i];
    }
    return rezultat;
}

Echipa Echipa::operator-(int x) {
    Echipa rezultat(*this);
    if (rezultat.numarRezerve - x < 0)
        throw std::runtime_error("Scaderea returneaza rezultat negativ");
    rezultat.numarRezerve -= x;
    if (rezultat.listaRezerve != NULL) {
        delete[] rezultat.listaRezerve;
        rezultat.listaRezerve = NULL;
    }
    rezultat.listaRezerve = new Jucator[rezultat.numarRezerve];
    for (int i = 0; i < rezultat.numarRezerve; i++) {
        rezultat.listaRezerve[i] = this->listaRezerve[i];
    }
    return rezultat;
}

Echipa operator-(int x, Echipa obj) {
    return obj + x;
}

Echipa::operator int() {
    return this->numarRezerve + this->numarTitulari;
}

bool Echipa::operator==(const Echipa& obj) {

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
    Echipa operator[](int);
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

Echipa Competitie::operator[](int i) {
    if (this->listaEchipe == NULL)
        throw std::runtime_error("Nu exista echipe");
    if (this->numarEchipe <= i or i < 0)
        throw std::runtime_error("Index in afara vectorului");
    return this->listaEchipe[i];
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

/*Competitie Competitie::operator-(const Competitie& obj) {
    Competitie rezultat(*this);
    int cnt = 0, i, j, k=0;
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
}*/

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
    // if (this->listaEchipe != NULL and obj.listaEchipe != NULL)
        // for (i = 0; i < this->numarEchipe; i++)
             //if (this->listaEchipe[i] != obj.listaEchipe[i])
                //return false;
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

int main()
{
    Echipa a, b;
    std::cin >> a;
    system("CLS");
    std::cin >> b;
    system("CLS");
    std::cout << a - b;
    return 0;
}
