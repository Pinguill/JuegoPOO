#include "MainMenu.h"

// Init Functions
void MainMenu::initVariables(){

}

void MainMenu::initKeybinds(){

}

void MainMenu::initBackGround(){
   this->backgrounnd.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), 
      static_cast<float>(this->window->getSize().y)));
   
   if(!this->backgroundTexture.loadFromFile("Resource/Images/backgrounds/background.jpg")){
      throw"ERROR::MAINMENU::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
   }

   this->backgrounnd.setTexture(&this->backgroundTexture);
}

void MainMenu::initFonts(){
   if(!this->font.loadFromFile("Fonts/MedievalSharp.ttf")){
      throw("ERROR::MAINMENU::COULD NOT LOAD FONT");
   }
}

void MainMenu::initBottons(){
   // Buttons
   this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
      &this->font, "PLAY", 
      sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
   
   this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, 
      &this->font, "EXIT", 
      sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
   
}

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) 
   : State(window, supportedKeys ,states)
{
   //this->initVariables();
   this->initBackGround();
   this->initFonts();
   this->initBottons();

};


MainMenu::~MainMenu()
{
   auto it = this->buttons.begin();
   for(it = this->buttons.begin(); it != this->buttons.end(); ++it ){
      it->second;
   }
}

// Functions

void MainMenu::updateInput(const float &dt){
   
}

void MainMenu::updateButtons(){
   /*Update all the buttons in the state and handles their functionality*/
   for( auto &it : this->buttons ){
      it.second->update(this->mousePosView);
   }
   
   //Join the game
   if(this->buttons["GAME_STATE"]->isPressed()){
      this->states->push(new GameState(this->window, this->supportedKeys, this->states));
   }

   //Exit the game
   if(this->buttons["EXIT_STATE"]->isPressed()){
      this->endState();
   }
}

void MainMenu::update(const float& dt){
   this->updateMousePositions();
   this->updateInput(dt);
   this->updateButtons();
}
void MainMenu::renderButtons(sf::RenderTarget* target){
   for( auto &it : this->buttons ){
      it.second->render(target);
   }
}
void MainMenu::render(sf::RenderTarget* target){
   if(!target){
      target = this->window;
   }
   target->draw(this->backgrounnd);

   this->renderButtons(target);

   /* Mouse showing position DELETE LATER!!!
   sf::Text mouseText;
   mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
   mouseText.setFont(this->font);
   mouseText.setCharacterSize(12);
   std::stringstream ss;
   ss << this->mousePosView.x << " " << this->mousePosView.y;
   mouseText.setString(ss.str());
   target->draw(mouseText)
   */
}