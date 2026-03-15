#include "Substances.h"

Substance::Substance(std::string name, std::string formula)
    : name{name}, formula{formula} {}

std::string Substance::getName() const {
    return name;
}

std::string Substance::getFormula() const {
    return formula;
}

std::string Substance::getCategory() const {
    return "Unknown";
}

Acid::Acid(std::string name, std::string formula)
    : Substance{name, formula} {}

std::string Acid::getCategory() const {
    return "Acid";
}

Basic::Basic(std::string name, std::string formula)
    : Substance{name, formula} {}

std::string Basic::getCategory() const {
    return "Basic";
}

Neutral::Neutral(std::string name, std::string formula)
    : Substance{name, formula} {}

std::string Neutral::getCategory() const {
    return "Neutral";
}

Inorganic::Inorganic(std::string name, std::string formula)
    : Substance{name, formula} {}

std::string Inorganic::getCategory() const {
    return "Inorganic";
}