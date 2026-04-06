#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "Substances.h"
#include "Reactions.h"
#include "Images.h"
#include <array>
#include <vector>


struct SubstanceButton {
    TDT4102::Point pos;
    int width = 60;
    int height = 80;
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
    TDT4102::Button quitButton;
    TDT4102::Button restartButton;
    ReactionDatabase database;
    std::string reactionMessage;
public:
    LabWindow();
    void setupSubstanceButtons();
    void getSubstances();
    void loadReactions();
    void drawLab();
    void drawSubstanceButtons();
    void drawSelectedSubstances();
    void selectSubstance(Substance* substance);
    void click(TDT4102::Point clickPos);
    void drawReactionButton();
    void drawQuitButton();
    void drawRestartButton();
    void drawFlask();
    void startReaction();
    void quit();
    void restart();
};

/* class JournalWindow : public TDT4102::AnimationWindow{
public:
    JournalWindow();
    void drawJournal();
}; */