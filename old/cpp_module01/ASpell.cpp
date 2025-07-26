#include "ASpell.hpp" // Dołączenie nagłówka klasy ASpell
#include "ATarget.hpp" // Potrzebne do implementacji metody launch

// Konstruktor - inicjalizuje pola name i effects wartościami przekazanymi w argumentach
ASpell::ASpell(std::string const &name, std::string const &effects)
    : name(name), effects(effects) {}

// Destruktor wirtualny - umożliwia poprawne niszczenie obiektów pochodnych przez wskaźnik do klasy bazowej
ASpell::~ASpell() {}

// Konstruktor kopiujący - kopiuje pola name i effects z innego obiektu ASpell
ASpell::ASpell(ASpell const &other)
    : name(other.name), effects(other.effects) {}

// Operator przypisania - przypisuje wartości pól z innego obiektu ASpell, zabezpiecza przed samoprzypisaniem
ASpell &ASpell::operator=(ASpell const &other) {
    if (this != &other) { // Sprawdzenie czy nie przypisujemy do siebie samego
        name = other.name;
        effects = other.effects;
    }
    return *this;
}

// Getter zwracający nazwę zaklęcia (stała referencja, by nie kopiować stringa)
std::string const &ASpell::getName() const {
    return name;
}

// Getter zwracający efekt zaklęcia (stała referencja, by nie kopiować stringa)
std::string const &ASpell::getEffects() const {
    return effects;
}

// Metoda uruchamiająca zaklęcie na celu - wywołuje getHitBySpell na przekazanym obiekcie ATarget
void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell(*this);
}

/*
Wyjaśnienia:
- Każda metoda jest zaimplementowana zgodnie z deklaracją w nagłówku.
- launch korzysta z metody getHitBySpell klasy ATarget, przekazując siebie jako argument.
- Brak implementacji clone() - to metoda czysto wirtualna, implementują ją klasy pochodne.
*/