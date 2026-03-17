#include "LabWindow.h"


Images::Images() 
    : backgroundLab("visuals/laboratory.png"),
     backgroundJournal("visuals/journal.png"),
     flask("visuals/kolbe.png"),
     tubeGreen("visuals/laboratory.jpeg"),
     tubeBlue("visuals/laboratory.jpeg"),
     tubeYellow("visuals/laboratory.jpeg"),
     tubeBlank("visuals/laboratory.jpeg"),
      
      
      bubbles{
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"}
      },
      explosion{
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"},
        TDT4102::Image{"visuals/kolbe.png"}
      } {}

bool SubstanceButton::contains(TDT4102::Point point) const {
      return point.x >= pos.x && point.x <= pos.x + width &&
      point.y >= pos.y && point.y <= pos.y + height;
}

LabWindow::LabWindow()
      : TDT4102::AnimationWindow{100,100,800, 600, "Virituell kjemilab"} {}

void LabWindow::getSubstances(){
    std::ifstream ifs("files/substances.txt");
    std::string line;
    
    std::vector<std::unique_ptr<Substance>> subs;
    while (std::getline(ifs, line)) {
        subs.push_back(createSubstanceFromLine(line));
    }
}

void LabWindow::setupSubstanceButtons(){
      int startX = 180;
      int y = 480;
      int gap = 90;

            for (int i = 0; i < static_cast<int>(substances.size()); i++) {
                  substanceButtons.push_back({{startX + i*gap,y}, flaskWidth, flaskHeight, substances.at(i).get()});
            }

            for (const auto& button : substanceButtons) {
                  if (button.substance != nullptr) {
                  draw_image(button.pos, images.flask, button.width, button.height);
                  draw_text({button.pos.x-10, button.pos.y + button.height + 20}, button.substance->getName());
            }
      }

}

void LabWindow::click(TDT4102::Point clickPos){
      for (const auto& button : substanceButtons) {
            if (button.contains(clickPos)) {
                  selectSubstance(button.substance);
                  break;
            }
      }
}

void LabWindow::selectSubstance(Substance* substance){
      if (selectedSubstance1 == nullptr){
            selectedSubstance1 = substance;
      } else if (selectedSubstance2 == nullptr){
            selectedSubstance2 = substance;
      } else {
            selectedSubstance1 = substance;
            selectedSubstance2 = nullptr;
      }
}

void LabWindow::drawSelectedSubstances(){
      std::string text1 = "Stoff 1: ";
      std::string text2 = "Stoff 2: ";

      if (selectedSubstance1 != nullptr) {
            text1 += selectedSubstance1->getName();
      } else {
            text1 += "Ingen valgt";
      }
      if (selectedSubstance2 != nullptr) {
            text2 += selectedSubstance2->getName();
      } else {
            text2 += "Ingen valgt";
      }

      draw_text({60,180}, text1);
      draw_text({60,230}, text2);
}

void LabWindow::drawLab() {
    draw_image({0,0}, images.backgroundLab, width(), height());
    draw_text({100,80}, "Velkommen til kjemilab!", TDT4102::Color::yellow, 60, TDT4102::Font::times_bold);

    getSubstances();
    setupSubstanceButtons();
    drawSelectedSubstances();

}

JournalWindow::JournalWindow()
      : TDT4102::AnimationWindow{800,600,400, 600, "Labjournal"} {}