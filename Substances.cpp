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

std::unique_ptr<Substance> createSubstanceFromLine(const std::string& line){

    std::stringstream ss(line);
    std::string type;
    std::string name;
    std::string formula;

    std::getline(ss, type, ';');
    std::getline(ss, name, ';');
    std::getline(ss, formula, ';');

    if (type == "Acid") {
        return std::make_unique<Acid>(name, formula);
    }
    else if (type == "Basic") {
        return std::make_unique<Basic>(name, formula);
    }
    else if (type == "inorganic") {
        return std::make_unique<Inorganic>(name, formula);
    }
    else{
        return std::make_unique<Neutral>(name, formula);
    }

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