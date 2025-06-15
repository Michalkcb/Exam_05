#include "Dummy.hpp" // Dołączenie nagłówka klasy Dummy

// Konstruktor domyślny - ustawia typ na "Target Practice Dummy"
Dummy::Dummy()
    : ATarget("Target Practice Dummy") {}

// Destruktor wirtualny - umożliwia poprawne niszczenie obiektów przez wskaźnik do klasy bazowej
Dummy::~Dummy() {}

// Konstruktor kopiujący - kopiuje bazową część ATarget
Dummy::Dummy(Dummy const &other)
    : ATarget(other) {}

// Operator przypisania - przypisuje bazową część ATarget, zabezpiecza przed samoprzypisaniem
Dummy &Dummy::operator=(Dummy const &other) {
    if (this != &other) {
        ATarget::operator=(other);
    }
    return *this;
}

// Implementacja pure virtual clone() z ATarget - zwraca nowy obiekt Dummy
Dummy *Dummy::clone() const {
    return new Dummy(*this);
}

/*
Wyjaśnienia:
- clone: zwraca kopię obiektu, wymagane przez zadanie.
- Konstruktor kopiujący i operator przypisania: Coplien's form.
- Dziedziczenie: wywołania konstruktorów/operacji bazowej klasy ATarget.
*/