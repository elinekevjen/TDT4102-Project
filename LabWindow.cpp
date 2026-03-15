#include "LabWindow.h"

Images::Images() 
    : backgroundLab("visuals/laboratory.jpeg"),
     backgroundJournal("visuals/laboratory.jpeg"),
     flask("visuals/laboratory.jpeg"),
     tubeGreen("visuals/laboratory.jpeg"),
     tubeBlue("visuals/laboratory.jpeg"),
     tubeYellow("visuals/laboratory.jpeg"),
     tubeBlank("visuals/laboratory.jpeg"),
      
      
      bubbles{
        TDT4102::Image{"res/textures/character2.png"},
        TDT4102::Image{"res/textures/character1.png"},
        TDT4102::Image{"res/textures/character3.png"},
        TDT4102::Image{"res/textures/character1.png"}
      },
      explosion{
        TDT4102::Image{"res/textures/fly1.png"},
        TDT4102::Image{"res/textures/fly2.png"},
        TDT4102::Image{"res/textures/fly3.png"},
        TDT4102::Image{"res/textures/fly2.png"}
      } {}

LabWindow::LabWindow()
      : TDT4102::AnimationWindow{100,100,1000,800, "Virituell kjemilab"} {}