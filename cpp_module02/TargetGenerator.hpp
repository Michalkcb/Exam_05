#pragma once
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator {
public:
    TargetGenerator();
    ~TargetGenerator();

    // Zakaz kopiowania
    TargetGenerator(const TargetGenerator&);
    TargetGenerator& operator=(const TargetGenerator&);

    void learnTargetType(ATarget* target);
    void forgetTargetType(const std::string& type);
    ATarget* createTarget(const std::string& type);

private:
    std::map<std::string, ATarget*> targets;
};