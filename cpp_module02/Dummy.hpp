#pragma once // Zapobiega wielokrotnemu dołączeniu pliku nagłówkowego

#include "ATarget.hpp" // Dziedziczymy po ATarget, więc musimy dołączyć nagłówek

// Klasa Dummy dziedziczy po ATarget i reprezentuje konkretny cel
class Dummy : public ATarget {
public:
    // Konstruktor domyślny - ustawia typ na "Target Practice Dummy"
    Dummy();

    // Wirtualny destruktor - umożliwia poprawne niszczenie obiektów przez wskaźnik do klasy bazowej
    virtual ~Dummy();

    // Konstruktor kopiujący - pozwala kopiować obiekty klasy (Coplien's form)
    Dummy(Dummy const &other);

    // Operator przypisania - pozwala przypisywać jeden obiekt do drugiego (Coplien's form)
    Dummy &operator=(Dummy const &other);

    // Implementacja pure virtual clone() z ATarget - zwraca nowy obiekt Dummy
    virtual Dummy *clone() const;
};

/*
Wyjaśnienia:
- Dziedziczenie po ATarget: Dummy jest konkretnym celem.
- Konstruktor domyślny: ustawia wymagany przez zadanie typ.
- clone: zwraca nowy obiekt Dummy, wymagane przez zadanie.
- Coplien's form: konstruktor kopiujący, operator przypisania, destruktor.
*/