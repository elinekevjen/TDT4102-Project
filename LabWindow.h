#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
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
    int width = 20;
    int height = 30;
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

    bool selectingFirst = true;
    static constexpr int flaskHeight = 150;
    static constexpr int flaskWidth = 110;

    static constexpr int startX = 90;
    static constexpr int y = 420;
    static constexpr int gap = 120;

    TDT4102::Button reactionButton;
public:
    LabWindow();
    void setupSubstanceButtons();
    void getSubstances();
    void drawLab();
    void drawSubstanceButtons();
    void drawSelectedSubstances();
    void selectSubstance(Substance* substance);
    void click(TDT4102::Point clickPos);
    void drawReactionButton();
    void drawFlask();
    void startReaction();
};

/* class JournalWindow : public TDT4102::AnimationWindow{
public:
    JournalWindow();
    void drawJournal();
}; */