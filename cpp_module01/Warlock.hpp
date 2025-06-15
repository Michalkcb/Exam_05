#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
    std::string name;
    std::string title;
    std::map<std::string, ASpell*> spells;

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
    void forgetSpell(std::string name); // <-- przez wartość!
    void launchSpell(std::string name, const ATarget& target); // <-- przez wartość!
};

#endif // WARLOCK_HPP