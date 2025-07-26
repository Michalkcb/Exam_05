#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
private:
    SpellBook spellBook;
    std::string name;
    std::string title;


    Warlock();
    Warlock(const Warlock&);
    Warlock& operator=(const Warlock&);

public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);

    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& name);
    void launchSpell(std::string name, const ATarget& target);
};

#endif // WARLOCK_HPP