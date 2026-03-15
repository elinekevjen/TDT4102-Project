#pragma once

#include "AnimationWindow.h"

class LabWindow : public TDT4102::AnimationWindow{
public:
    static constexpr int pad = 20;
	static constexpr int btnW = 75;
	static constexpr int btnH = 20;
	static constexpr int fieldW = 200;
	static constexpr int fieldH = 20;

    LabWindow(TDT4102::Point position, int width, int height, const std::string& title);
};