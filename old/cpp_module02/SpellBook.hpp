#pragma once
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook {
public:
    SpellBook();
    ~SpellBook();

    // Zakaz kopiowania
    SpellBook(const SpellBook&);
    SpellBook& operator=(const SpellBook&);

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    ASpell* createSpell(const std::string& name);

private:
    std::map<std::string, ASpell*> spells;
};