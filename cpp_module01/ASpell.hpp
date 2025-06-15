#pragma once // Zapobiega wielokrotnemu dołączeniu tego samego nagłówka
#include <string> // Potrzebne do użycia std::string

// Klasa abstrakcyjna, Coplien's form: konstruktor, destruktor, konstruktor kopiujący, operator przypisania
class ASpell {
protected:
    std::string name;    // Nazwa zaklęcia, chroniona aby była dostępna w klasach pochodnych
    std::string effects; // Efekt zaklęcia, chroniony jak wyżej

public:
    // Konstruktor przyjmujący nazwę i efekt zaklęcia, inicjalizuje pola
    ASpell(std::string const &name, std::string const &effects);

    // Wirtualny destruktor - konieczny w klasie bazowej z wirtualnymi metodami, by poprawnie niszczyć obiekty pochodne przez wskaźnik do bazowej
    virtual ~ASpell();

    // Konstruktor kopiujący - pozwala kopiować obiekty klasy (Coplien's form)
    ASpell(ASpell const &other);

    // Operator przypisania - pozwala przypisywać jeden obiekt do drugiego (Coplien's form)
    ASpell &operator=(ASpell const &other);

    // Getter zwracający nazwę zaklęcia (stała referencja, by nie kopiować stringa)
    std::string const &getName() const;

    // Getter zwracający efekt zaklęcia (stała referencja, by nie kopiować stringa)
    std::string const &getEffects() const;

    // Pure virtual - wymusza implementację clone() w klasach pochodnych, zwraca wskaźnik do nowej kopii obiektu
    virtual ASpell *clone() const = 0;

    // Metoda uruchamiająca zaklęcie na celu - wywołuje getHitBySpell na przekazanym obiekcie ATarget
    void launch(class ATarget const &target) const;
};
