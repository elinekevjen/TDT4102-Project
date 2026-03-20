#include "Images.h"

Images::Images() 
    : backgroundLab("visuals/laboratory.png"),
     backgroundJournal("visuals/journal.png"),
     flask("visuals/Kolbe2.png"),
     tubeRed("visuals/Red.png"),
     tubeDBlue("visuals/DBlue.png"),
     tubeLBlue("visuals/LBlue.png"),
     tubeGreen("visuals/Green.png"),
     tubeOrange("visuals/Orange.png"),
     tubeYellow("visuals/Yellow.png"),
      
      
      bubbles{
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
      },
      explosion{
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
      }, 
      precipitate{
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
      }{}
