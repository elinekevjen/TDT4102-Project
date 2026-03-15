#pragma once
#include "AnimationWindow.h"
#include <array>

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

class LabWindow : public TDT4102::AnimationWindow{
public:
    LabWindow();
};