#pragma once
#include "std_lib_facilities.h"
#include "Images.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream>
#include <fstream>

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
    virtual TDT4102::Image& getImage(Images& image) const = 0;
    
};

std::unique_ptr<Substance> createSubstanceFromLine(const std::string& line);

class Acid : public Substance{
public:
    Acid(std::string name, std::string formula);
    std::string getCategory() const override;
    TDT4102::Image& getImage(Images& image) const override;
};


class Basic : public Substance{
public:
    Basic(std::string name, std::string formula);
    std::string getCategory() const override;
    TDT4102::Image& getImage(Images& image) const override;
};

class Neutral : public Substance{
public:
    Neutral(std::string name, std::string formula);
    std::string getCategory() const override;
    TDT4102::Image& getImage(Images& image) const override;
};

class Inorganic : public Substance{
public:
    Inorganic(std::string name, std::string formula);
    std::string getCategory() const override;
    TDT4102::Image& getImage(Images& image) const override;
};