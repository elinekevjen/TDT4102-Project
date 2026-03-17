#pragma once
#include "AnimationWindow.h"
#include "Substances.h"
#include <array>
#include <vector>

struct Images {
	Images();

	TDT4102::Image backgroundLab;
    TDT4102::Image backgroundJournal;
    TDT4102::Image flask;
    TDT4102::Image tubeGreen;
    TDT4102::Image tubeBlue;
    TDT4102::Image tubeYellow;
    TDT4102::Image tubeBlank;



    std::array<TDT4102::Image, 4> bubbles;
    std::array<TDT4102::Image, 4> explosion;
};

struct SubstanceButton {
    TDT4102::Point pos;
    int width;
    int height;
    Substance* substance = nullptr;

    bool contains(TDT4102::Point point) const;

};

class LabWindow : public TDT4102::AnimationWindow{
private: 
    Images images;
    std::vector<std::unique_ptr<Substance>> substances;
    std::vector<SubstanceButton> substanceButtons;
    Substance* selectedSubstance1 = nullptr;
    Substance* selectedSubstance2 = nullptr;

    static constexpr int flaskHeight = 70;
    static constexpr int flaskWidth = 50;
public:
    LabWindow();
    void setupSubstanceButtons();
    void getSubstances();
    void drawLab();
    void drawSelectedSubstances();
    void selectSubstance(Substance* substance);
    void click(TDT4102::Point clickPos);
};

class JournalWindow : public TDT4102::AnimationWindow{
public:
    JournalWindow();
    void drawJournal();
};