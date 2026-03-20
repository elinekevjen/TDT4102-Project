#include "LabWindow.h"

LabWindow::LabWindow()
      : TDT4102::AnimationWindow{100,100, 830, 620, "Kjemilab"},
      reactionButton(TDT4102::Point{60,270}, 150, 50, "Kjør reaksjon!")  {

      drawReactionButton();
      getSubstances();
      loadReactions();
      setupSubstanceButtons();
      reactionButton.setCallback([this] {startReaction(); });
}

bool SubstanceButton::contains(TDT4102::Point point) const {
      return point.x >= pos.x && point.x <= pos.x + width &&
      point.y >= pos.y && point.y <= pos.y + height;
}

void LabWindow::getSubstances(){

      try {
      std::ifstream ifs("files/substances.txt");
      std::string line;
      
            if (!ifs) {
                  throw std::runtime_error("Kunne ikke åpne fil");
            }
    
      while (std::getline(ifs, line)) {
            substances.push_back(createSubstanceFromLine(line));
      }
      } catch (const std::runtime_error& e) {
            std::cout << "Feil ved lasting av Substances: " << e.what() << std::endl;
      }
}

void LabWindow::loadReactions(){
      try {
            database.loadFromFile("files/reactions.txt");
      } catch (std::runtime_error& e) {
            std::cout << "Feil ved lasting av Reactions: " << e.what() << std::endl;
      }

}

void LabWindow::setupSubstanceButtons(){
      for (int i = 0; i <= static_cast<int>(substances.size())-1; i++) {
            substanceButtons.push_back({{startX + i*gap , y}, 20, 30, substances.at(i).get()});
      }
}

void LabWindow::drawSubstanceButtons() {
      for (const auto& button : substanceButtons) {
            if (button.substance != nullptr) {
            draw_image(button.pos, button.substance->getImage(images), button.width, button.height);
            draw_text({button.pos.x, button.pos.y + button.height}, button.substance->getName());
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
      if (substance == nullptr){
            return;
      } 
      if (selectingFirst){
           selectedSubstance1 = substance;
           if (selectedSubstance2 == selectedSubstance1) {
                  selectedSubstance2 = nullptr;
           }

      } else {
            if (substance == selectedSubstance1) {
                  return;
            }
            selectedSubstance2 = substance;
      }
      selectingFirst = !selectingFirst;
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
      draw_rectangle({60,180}, 180, 80, TDT4102::Color::white, TDT4102::Color::navy);
      draw_text({60,180}, text1);
      draw_text({60,230}, text2);
}

void LabWindow::startReaction() {
      try {
            if (selectedSubstance1 == nullptr || selectedSubstance2 == nullptr) {
                  throw std::runtime_error("Du må velge to ulike stoffer for å kunne kjøre en reaksjon!");
            }
            Reaction result = database.findReaction(selectedSubstance1->getName(), selectedSubstance2->getName());
            reactionMessage = "Det skjedde en reaksjon! \n" + result.getDescription();

      }
      catch (const std::runtime_error& e) {
            reactionMessage +=  "Feil: ";
            reactionMessage += e.what();
      }
}

void LabWindow::drawReactionButton() {
      reactionButton.setButtonColor(TDT4102::Color::white);
      reactionButton.setButtonColorBorder(TDT4102::Color::navy);
      reactionButton.setButtonColorHover(TDT4102::Color::grey);
      reactionButton.setLabelColor(TDT4102::Color::black);
      add(reactionButton);
}

void LabWindow::drawFlask() {
      draw_image(TDT4102::Point{370,320}, images.flask, flaskWidth, flaskHeight);
}


void LabWindow::drawLab() {
    draw_image({0,0}, images.backgroundLab, width(), height());
    draw_text({130,40}, "Velkommen til kjemilab!", TDT4102::Color::gold, 50, TDT4102::Font::arial_bold);

    drawSubstanceButtons();
    drawSelectedSubstances();
    drawFlask();

    draw_text({400, 100}, reactionMessage);
}


/* JournalWindow::JournalWindow()
      : TDT4102::AnimationWindow{800,600,400, 600, "Labjournal"} {} */