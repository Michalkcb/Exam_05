#include "Fwoosh.hpp" // Dołączenie nagłówka klasy Fwoosh

// Konstruktor domyślny - ustawia nazwę na "Fwoosh" i efekt na "fwooshed"
Fwoosh::Fwoosh()
    : ASpell("Fwoosh", "fwooshed") {}

// Destruktor wirtualny - umożliwia poprawne niszczenie obiektów przez wskaźnik do klasy bazowej
Fwoosh::~Fwoosh() {}

// Konstruktor kopiujący - kopiuje bazową część ASpell
Fwoosh::Fwoosh(Fwoosh const &other)
    : ASpell(other) {}

// Operator przypisania - przypisuje bazową część ASpell, zabezpiecza przed samoprzypisaniem
Fwoosh &Fwoosh::operator=(Fwoosh const &other) {
    if (this != &other) {
        ASpell::operator=(other);
    }
    return *this;
}

// Implementacja pure virtual clone() z ASpell - zwraca nowy obiekt Fwoosh
Fwoosh *Fwoosh::clone() const {
    return new Fwoosh(*this);
}

/*
Wyjaśnienia:
- clone: zwraca kopię obiektu, wymagane przez zadanie.
- Konstruktor kopiujący i operator przypisania: Coplien's form.
- Dziedziczenie: wywołania konstruktorów/operacji bazowej klasy ASpell.
*/