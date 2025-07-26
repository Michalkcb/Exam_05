#ifndef CLASS_HPP
#define CLASS_HPP
#include <string>

class Warlock {
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
};

#endif // CLASS_HPP