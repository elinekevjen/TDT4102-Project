#pragma once
#include "AnimationWindow.h"

struct Images {
	Images();

	TDT4102::Image backgroundLab;
    TDT4102::Image backgroundJournal;
    TDT4102::Image flask;
    TDT4102::Image tubeRed;
    TDT4102::Image tubeDBlue;
    TDT4102::Image tubeLBlue;
    TDT4102::Image tubeOrange;
    TDT4102::Image tubeGreen;
    TDT4102::Image tubeYellow;



    std::array<TDT4102::Image, 3> bubbles;
    std::array<TDT4102::Image, 3> explosion;
    std::array<TDT4102::Image, 3> precipitate;
};