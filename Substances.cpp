#include "Substances.h"

Substance::Substance(std::string name, std::string formula){
    this->name = name;
    this->formula = formula;
}

string Substance::getName() const {
    return name;
}

string Substance::getFormula() const {
    return formula;
}

string Substance::getCategory() const {
    return "Unknown";
}