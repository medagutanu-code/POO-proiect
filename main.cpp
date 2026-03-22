#include <iostream>
#include <cstring>
#include <vector>

class Imobil {
private:
    static int nrImobile;
    const int id;
    char* locatie;
    double pret;
    double suprafata;
    bool balcon;
public:
    // constructori
    Imobil();
    Imobil(const char*, double, double, bool);
    // constructor copiere
    Imobil(const Imobil& obj);
    // operator copiere
    Imobil& operator=(const Imobil& obj);
    // destructor
    ~Imobil();

    // op overload
    friend std::ostream& operator<<(std::ostream&, const Imobil&);
    friend std::istream& operator>>(std::istream&, Imobil&);

    // getteri
    int getId() const;
    const char* getLocatie() const;
    double getPret() const;
    double getSuprafata() const;
    bool getBalcon() const;

    // setteri
    void setLocatie(const char*);
    void setPret(double);
    void setSuprafata(double);
    void setBalcon(bool);
};

int Imobil::nrImobile = 0;

// constructor gol
Imobil::Imobil() : id(++nrImobile) {
    locatie = new char[4];
    strcpy(locatie, "N/A");
    pret = 0.0;
    suprafata = 0.0;
    balcon = false;
}

// constructor cu args
Imobil::Imobil(const char* locatie, double pret, double suprafata, bool balcon) : id(++nrImobile) {
    this->locatie = new char[strlen(locatie) + 1];
    strcpy(this->locatie, locatie);
    this->pret = pret;
    this->suprafata = suprafata;
    this->balcon = balcon;
}

// construtor copiere
Imobil::Imobil(const Imobil& obj) : id(++nrImobile) {
    locatie = new char[strlen(obj.locatie) + 1];
    strcpy(locatie, obj.locatie);
    pret = obj.pret;
    suprafata = obj.suprafata;
    balcon = obj.balcon;
}

// op copiere
Imobil& Imobil::operator=(const Imobil& obj) {
    if (this == &obj)
        return *this;
    delete[] locatie;
    locatie = new char[strlen(obj.locatie) + 1];
    strcpy(locatie, obj.locatie);
    pret = obj.pret;
    suprafata = obj.suprafata;
    balcon = obj.balcon;
    return *this;
}

// destructor
Imobil::~Imobil() {
    delete[] locatie;
}

// getteri
int Imobil::getId() const { return id; }
const char* Imobil::getLocatie() const { return locatie; }
double Imobil::getPret() const { return pret; }
double Imobil::getSuprafata() const { return suprafata; }
bool Imobil::getBalcon() const { return balcon; }

// setteri
void Imobil::setLocatie(const char* locatie) {
    delete[] this->locatie;
    this->locatie = new char[strlen(locatie) + 1];
    strcpy(this->locatie, locatie);
}
void Imobil::setPret(double pret) { this->pret = pret; }
void Imobil::setSuprafata(double suprafata) { this->suprafata = suprafata; }
void Imobil::setBalcon(bool balcon) { this->balcon = balcon; }

// opp afisare
std::ostream& operator<<(std::ostream& os, const Imobil& obj) {
    os << "Id: " << obj.id << '\n';
    os << "Locatie: " << obj.locatie << '\n';
    os << "Pret: " << obj.pret << '\n';
    os << "Suprafata: " << obj.suprafata << '\n';
    os << "Balcon: " << (obj.balcon ? "DA" : "NU") << '\n';
    return os;
}

// opp citire
std::istream& operator>>(std::istream& is, Imobil& obj) {
    char buf[256];
    std::cout << "Locatie: ";
    is >> buf;
    obj.setLocatie(buf);

    std::cout << "Pret: ";
    double pret;
    is >> pret;
    obj.setPret(pret);

    std::cout << "Suprafata: ";
    double s;
    is >> s;
    obj.setSuprafata(s);

    std::cout << "Are balcon (1 pt DA, 0 pt NU): ";
    bool balcon;
    is >> balcon;
    obj.setBalcon(balcon);

    return is;
}


class Client {
private:
    static int nrClienti;
    const int id;
    char* nume;
    char* locatie;
    double buget;
    double suprafata;
    bool balcon;
public:
    Client(const char*, const char*, double, double, bool);
    Client(const Client& obj);
    Client& operator=(const Client& obj);
    ~Client();

    // getteri
    int getId() const;
    const char* getNume() const;
    const char* getLocatie() const;
    double getBuget() const;
    double getSuprafata() const;
    bool getBalcon() const;

    // op overload
    friend std::ostream& operator<<(std::ostream& out, const Client& obj);
};

int Client::nrClienti = 0;

// constructor cu args
Client::Client(const char* nume, const char* locatie, double buget, double suprafata, bool balcon) : id(++nrClienti) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->locatie = new char[strlen(locatie) + 1];
    strcpy(this->locatie, locatie);
    this->buget = buget;
    this->suprafata = suprafata;
    this->balcon = balcon;
}

Client::Client(const Client& obj) : id(++nrClienti) {
    nume = new char[strlen(obj.nume) + 1];
    strcpy(nume, obj.nume);
    locatie = new char[strlen(obj.locatie) + 1];
    strcpy(locatie, obj.locatie);
    buget = obj.buget;
    suprafata = obj.suprafata;
    balcon = obj.balcon;
}

Client& Client::operator=(const Client& obj) {
    if (this == &obj) return *this;
    delete[] nume;
    delete[] locatie;
    nume = new char[strlen(obj.nume) + 1];
    strcpy(nume, obj.nume);
    locatie = new char[strlen(obj.locatie) + 1];
    strcpy(locatie, obj.locatie);
    buget = obj.buget;
    suprafata = obj.suprafata;
    balcon = obj.balcon;
    return *this;
}

// destructor
Client::~Client() {
    delete[] nume;
    delete[] locatie;
}

// getteri
int Client::getId() const { return id; }
const char* Client::getNume() const { return nume; }
const char* Client::getLocatie() const { return locatie; }
double Client::getBuget() const { return buget; }
double Client::getSuprafata() const { return suprafata; }
bool Client::getBalcon() const { return balcon; }

// opp afisare
std::ostream& operator<<(std::ostream& os, const Client& obj) {
    os << "Id: " << obj.id << '\n';
    os << "Nume client: " << obj.nume << '\n';
    os << "Locatie dorita: " << obj.locatie << '\n';
    os << "Buget: " << obj.buget << '\n';
    os << "Suprafata dorita: " << obj.suprafata << '\n';
    os << "Balcon: " << (obj.balcon ? "DA" : "NU") << '\n';
    return os;
}


class Oferta {
private:
    static int nrOferte;
    const int id;
    double scor;
    int apid;
    int clientid;
    bool vanzare;

public:
    // constr
    Oferta();
    Oferta(int, int);

    // getteri
    int getId() const;
    int getApid() const;
    int getClientid() const;
    double getScor() const;
    bool getVanzare() const;

    // setteri
    void setApid(int);
    void setClientid(int);
    void setScor(double);
    void setVanzare(bool);

    double calculeazaScor(const Imobil&, const Client&);
    bool estePotrivita(const Imobil&, const Client&) const;
    void marcheazaVanzare();

    Oferta(const Oferta &other)
        : id(other.id),
          scor(other.scor),
          apid(other.apid),
          clientid(other.clientid),
          vanzare(other.vanzare) {
    }

    Oferta(Oferta &&other) noexcept
        : id(other.id),
          scor(other.scor),
          apid(other.apid),
          clientid(other.clientid),
          vanzare(other.vanzare) {
    }

    Oferta & operator=(const Oferta &other) {
        if (this == &other)
            return *this;
        scor = other.scor;
        apid = other.apid;
        clientid = other.clientid;
        vanzare = other.vanzare;
        return *this;
    }

    Oferta & operator=(Oferta &&other) noexcept {
        if (this == &other)
            return *this;
        scor = other.scor;
        apid = other.apid;
        clientid = other.clientid;
        vanzare = other.vanzare;
        return *this;
    }

    // op overload afisare
    friend std::ostream& operator<<(std::ostream& os, const Oferta& obj);
};

int Oferta::nrOferte = 0;

// Constructori
Oferta::Oferta() : id(++nrOferte) {
    scor = 0;
    apid = 0;
    clientid = 0;
    vanzare = false;
}
Oferta::Oferta(int apid, int clientid) : id(++nrOferte) {
    this->scor = 0;
    this->apid = apid;
    this->clientid = clientid;
    this->vanzare = false;
}

// getteri
int Oferta::getId() const { return id; }
int Oferta::getApid() const { return apid; }
int Oferta::getClientid() const { return clientid; }
double Oferta::getScor() const { return scor; }
bool Oferta::getVanzare() const { return vanzare; }

// setteri
void Oferta::setApid(int apid) { this->apid = apid; }
void Oferta::setClientid(int clientid) { this->clientid = clientid; }
void Oferta::setScor(double scor) { this->scor = scor; }
void Oferta::setVanzare(bool vanzare) { this->vanzare = vanzare; }

// op overload
std::ostream& operator<<(std::ostream& os, const Oferta& obj) {
    os << "Id Oferta: " << obj.id << '\n';
    os << "Scor: " << obj.scor << '\n';
    os << "Id Imobil: " << obj.apid << '\n';
    os << "Id Client: " << obj.clientid << '\n';
    os << "Status Vanzare: " << (obj.vanzare ? "Aprobata" : "In asteptare") << '\n';
    return os;
}


double Oferta::calculeazaScor(const Imobil& imobil, const Client& client) {
    scor = 0;
    if (imobil.getPret() <= client.getBuget())
        scor += client.getBuget() - imobil.getPret();
    if (imobil.getSuprafata() >= client.getSuprafata())
        scor += imobil.getSuprafata() - client.getSuprafata();
    if (imobil.getBalcon() == client.getBalcon())
        scor += 10;
    return scor;
}

bool Oferta::estePotrivita(const Imobil& imobil, const Client& client) const {
    return strcmp(imobil.getLocatie(), client.getLocatie()) == 0;
}

void Oferta::marcheazaVanzare() {
    if (this->scor >= 100) {
        this->vanzare = true;
    }
}

int main() {
    Imobil i1("Cluj", 130, 58, true);
    Imobil i2("Cluj", 280, 120, true);
    Imobil i3("Bucuresti", 500, 70, false);
    Imobil i4("Iasi", 170, 65, true);

    Client c1("Ana", "Cluj", 300, 50, true);
    Client c2("Mihai", "Cluj", 100, 40, true);
    Client c3("Ioana", "Bucuresti", 600, 100, false);

    std::vector<Imobil> imobile = {i1, i2, i3, i4};
    std::vector<Client> clienti = {c1, c2, c3};


    for (size_t i = 0; i < clienti.size(); i++) {

        bool gasit = false;
        Oferta best;


        for (size_t j = 0; j < imobile.size(); j++) {

            Oferta o(imobile[j].getId(), clienti[i].getId());

            if (o.estePotrivita(imobile[j], clienti[i])) {
                o.calculeazaScor(imobile[j], clienti[i]);

                if (!gasit || o.getScor() > best.getScor()) {
                    best = o;
                    gasit = true;
                }
            }
        }


        std::cout << "Client:\n" << clienti[i] << "\n";

        if (gasit) {
            best.marcheazaVanzare();
            std::cout << "Cea mai buna oferta \n";
            std::cout << best << "\n";
        } else {
            std::cout << ">> Nu exista oferta potrivita.\n";
        }
    }

    return 0;
}