#pragma once
#include "std_lib_facilities.h"

class Substance{
    /*
    Overordnet klasse for ulike stoffer
    */
protected:
    std::string name;
    std::string formula;
public:
    Substance(std::string name, std::string fomula);
    virtual ~Substance() = default;
    std::string getName() const;
    std::string getFormula() const;
    virtual std::string getCategory() const;

};

class Acid : public Substance{
public:
    Acid(std::string name, std::string formula);
    std::string getCategory() const override;
};


class Basic : public Substance{
public:
    Basic(std::string name, std::string formula);
    std::string getCategory() const override;
};

class Neutral : public Substance{
public:
    Neutral(std::string name, std::string formula);
    std::string getCategory() const override;
};

class Inorganic : public Substance{
public:
    Inorganic(std::string name, std::string formula);
    std::string getCategory() const override;
};