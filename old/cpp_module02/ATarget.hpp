#pragma once // Zapobiega wielokrotnemu dołączeniu pliku nagłówkowego

#include <string>   // Potrzebne do użycia std::string
#include <iostream> // Potrzebne do std::cout w getHitBySpell

// Klasa abstrakcyjna, Coplien's form: konstruktor, destruktor, konstruktor kopiujący, operator przypisania
class ATarget {
protected:
    std::string type; // Typ celu, chroniony aby był dostępny w klasach pochodnych

public:
    // Konstruktor przyjmujący typ celu, inicjalizuje pole type
    ATarget(std::string const &type);

    // Wirtualny destruktor - konieczny w klasie bazowej z wirtualnymi metodami
    virtual ~ATarget();

    // Konstruktor kopiujący - pozwala kopiować obiekty klasy (Coplien's form)
    ATarget(ATarget const &other);

    // Operator przypisania - pozwala przypisywać jeden obiekt do drugiego (Coplien's form)
    ATarget &operator=(ATarget const &other);

    // Getter zwracający typ celu (stała referencja, by nie kopiować stringa)
    std::string const &getType() const;

    // Pure virtual - wymusza implementację clone() w klasach pochodnych, zwraca wskaźnik do nowej kopii obiektu
    virtual ATarget *clone() const = 0;

    // Metoda wywoływana, gdy cel zostaje trafiony zaklęciem - wypisuje odpowiedni komunikat
    void getHitBySpell(class ASpell const &spell) const;
};

/*
Wyjaśnienia:
- #pragma once: zabezpieczenie przed wielokrotnym dołączaniem pliku nagłówkowego.
- Wirtualny destruktor: konieczny w klasie bazowej z wirtualnymi metodami.
- Konstruktor kopiujący i operator przypisania: Coplien's form.
- getHitBySpell: metoda wymagana przez zadanie, wypisuje komunikat po trafieniu zaklęciem.
- clone: pure virtual, wymusza implementację w klasach pochodnych.
*/