#include "ATarget.hpp"   // Dołączenie nagłówka klasy ATarget
#include "ASpell.hpp"    // Potrzebne do implementacji metody getHitBySpell

// Konstruktor - inicjalizuje pole type wartością przekazaną w argumencie
ATarget::ATarget(std::string const &type)
    : type(type) {}

// Wirtualny destruktor - umożliwia poprawne niszczenie obiektów pochodnych przez wskaźnik do klasy bazowej
ATarget::~ATarget() {}

// Konstruktor kopiujący - kopiuje pole type z innego obiektu ATarget
ATarget::ATarget(ATarget const &other)
    : type(other.type) {}

// Operator przypisania - przypisuje wartość pola type z innego obiektu ATarget, zabezpiecza przed samoprzypisaniem
ATarget &ATarget::operator=(ATarget const &other) {
    if (this != &other) { // Sprawdzenie czy nie przypisujemy do siebie samego
        type = other.type;
    }
    return *this;
}

// Getter zwracający typ celu (stała referencja, by nie kopiować stringa)
std::string const &ATarget::getType() const {
    return type;
}

// Metoda wywoływana, gdy cel zostaje trafiony zaklęciem - wypisuje odpowiedni komunikat
void ATarget::getHitBySpell(ASpell const &spell) const {
    // Wypisuje: <TYPE> has been <EFFECTS>!
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}

/*
Wyjaśnienia:
- Każda metoda jest zaimplementowana zgodnie z deklaracją w nagłówku.
- getHitBySpell korzysta z getEffects klasy ASpell, by pobrać efekt zaklęcia.
- Brak implementacji clone() - to metoda czysto wirtualna, implementują ją klasy pochodne.
*/