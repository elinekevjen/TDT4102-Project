#include "LabWindow.h"

LabWindow::LabWindow()
      : TDT4102::AnimationWindow{100,100, 830, 620, "Kjemilab"},
      reactionButton(TDT4102::Point{60,180}, 150, 50, "Kjør reaksjon!"),
      quitButton(TDT4102::Point{700,30}, 100, 50, "Avslutt"),
      restartButton(TDT4102::Point{60,220}, 150, 50, "Ny reaksjon")  {

      drawReactionButton();
      drawQuitButton();
      drawRestartButton();
      getSubstances();
      loadReactions();
      setupSubstanceButtons();
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
      int margin = width() * 0.05;
      int spacing = (width() - 2*margin) / substances.size();
      int buttonW = spacing * 0.6;
      int buttonH = height() * 0.2;
      int yPos = height() * 0.70;

      for (int i = 0; i <= (substances.size()-1); i++) {
            substanceButtons.push_back({{margin + i*spacing , yPos}, buttonW, buttonH, substances.at(i).get()});
      }
}

void LabWindow::drawSubstanceButtons() {
      int margin = width() * 0.05;
      int spacing = (width() - 2*margin) / substances.size();
      int buttonW = spacing * 0.7;
      int buttonH = height() * 0.25;
      for (const auto& button : substanceButtons) {
            if (button.substance != nullptr) {
            draw_image(button.pos, button.substance->getImage(images), buttonW, buttonH);
            draw_text({button.pos.x, button.pos.y + (buttonH-4)}, button.substance->getName());
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
      draw_rectangle({60,120}, 180, 60, TDT4102::Color::white, TDT4102::Color::navy);
      draw_text({60,120}, text1);
      draw_text({60,150}, text2);
}

void LabWindow::startReaction() {
      try {
            if (selectedSubstance1 == nullptr || selectedSubstance2 == nullptr) {
                  throw std::runtime_error("Du må velge to ulike stoffer for å kunne kjøre en reaksjon!");
            }
            Reaction result = database.findReaction(selectedSubstance1->getName(), selectedSubstance2->getName());
            reactionMessage = result.getDescription();

            currentAnimation = getAnimation(result.getReactionType());
            animationFrame = 0;
            animationCounter = 0;


      }
      catch (const std::runtime_error& e) {
            reactionMessage +=  "Feil: ";
            reactionMessage += e.what();
            currentAnimation = nullptr;
      }

}

void LabWindow::drawReactionButton() {
      reactionButton.setButtonColor(TDT4102::Color::white);
      reactionButton.setButtonColorBorder(TDT4102::Color::navy);
      reactionButton.setButtonColorHover(TDT4102::Color::grey);
      reactionButton.setLabelColor(TDT4102::Color::black);
      reactionButton.setCallback([this] {startReaction(); });
      add(reactionButton);
}

void LabWindow::drawQuitButton() {
      quitButton.setButtonColor(TDT4102::Color::white);
      quitButton.setButtonColorBorder(TDT4102::Color::navy);
      quitButton.setButtonColorHover(TDT4102::Color::grey);
      quitButton.setLabelColor(TDT4102::Color::black);
      quitButton.setCallback([this] { close();});
      add(quitButton);
}

void LabWindow::drawRestartButton() {
      restartButton.setButtonColor(TDT4102::Color::white);
      restartButton.setButtonColorBorder(TDT4102::Color::navy);
      restartButton.setButtonColorHover(TDT4102::Color::grey);
      restartButton.setLabelColor(TDT4102::Color::black);
      restartButton.setCallback([this] { restart();});
      add(restartButton);
}

void LabWindow::drawFlask() {
    int fw = width() * 0.15;
    int fh = height() * 0.30;

    int x = width() * 0.40;
    int y = height() * 0.50;

    draw_image({x, y}, images.flask, fw, fh);
}

void LabWindow::restart() {
      selectedSubstance1 = nullptr;
      selectedSubstance2 = nullptr;
      selectingFirst = true;
      reactionMessage = "";
      currentAnimation = nullptr;
}

void LabWindow::drawLab() {
    draw_image({0,0}, images.backgroundLab, width(), height());
    draw_text({130,40}, "Velkommen til kjemilab!", TDT4102::Color::gold, 50, TDT4102::Font::arial_bold);

    drawSubstanceButtons();
    drawSelectedSubstances();
    drawFlask();

    draw_text({400, 100}, reactionMessage);
    drawAnimation();
}

std::array<TDT4102::Image,3>* LabWindow::getAnimation(const std::string& type){
      if (type == "Nøytralisering") {
            return &images.neutralization;
      }
      if (type == "Bunnfall") {
            return &images.precipitate;
      }
      if (type == "Oppløsning") {
            return &images.dissolution;
      }
      if (type == "Gassutvikling") {
            return &images.bubbles;
      }
      if (type == "Eksplosjon") {
            return &images.explosion;
      }

      return &images.defaultRx;
}

void LabWindow::drawAnimation(){
      if (!currentAnimation) {
            return;
      }
      animationCounter ++;
      if (animationCounter > 10) {
            animationFrame = (animationFrame + 1) % 3;
            animationCounter = 0;
      }

      draw_image(TDT4102::Point{370, 320}, (*currentAnimation)[animationFrame], 150, 150);

}


/* JournalWindow::JournalWindow()
      : TDT4102::AnimationWindow{800,600,400, 600, "Labjournal"} {} 
*/