class ArrayList{
    private:
    int* dane;
    int rozmiar;
    int ilosc_el;

    void zmienRozmiar(int nowy_rozmiar);

    public:
    ArrayList();
    ~ArrayList();

    void dodPocz(int wartosc);
    void dodKon(int wartosc);
    void dodNa(int gdzie, int wartosc);

    void usunPocz();
    void usunKon();
    void usunNa(int gdzie);

    bool wyszukaj(int wartosc) const;

    int ileEl() const;
    void wyczysc();
};