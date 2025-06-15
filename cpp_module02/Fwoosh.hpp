#pragma once // Zapobiega wielokrotnemu dołączeniu pliku nagłówkowego

#include "ASpell.hpp" // Dziedziczymy po ASpell, więc musimy dołączyć nagłówek

// Klasa Fwoosh dziedziczy po ASpell i reprezentuje konkretne zaklęcie
class Fwoosh : public ASpell {
public:
    // Konstruktor domyślny - ustawia nazwę na "Fwoosh" i efekt na "fwooshed"
    Fwoosh();

    // Wirtualny destruktor - umożliwia poprawne niszczenie obiektów przez wskaźnik do klasy bazowej
    virtual ~Fwoosh();

    // Konstruktor kopiujący - pozwala kopiować obiekty klasy (Coplien's form)
    Fwoosh(Fwoosh const &other);

    // Operator przypisania - pozwala przypisywać jeden obiekt do drugiego (Coplien's form)
    Fwoosh &operator=(Fwoosh const &other);

    // Implementacja pure virtual clone() z ASpell - zwraca nowy obiekt Fwoosh
    virtual Fwoosh *clone() const;
};

/*
Wyjaśnienia:
- Dziedziczenie po ASpell: Fwoosh jest konkretnym zaklęciem.
- Konstruktor domyślny: ustawia wymagane przez zadanie wartości.
- clone: zwraca nowy obiekt Fwoosh, wymagane przez zadanie.
- Coplien's form: konstruktor kopiujący, operator przypisania, destruktor.
*/