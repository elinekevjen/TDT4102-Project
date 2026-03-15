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

class Acidic : public Substance{

};


class Basic : public Substance{

};

class Neutral : public Substance{

};

class Inorganic : public Substance{

};