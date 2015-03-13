#include <towerdefense/Levels.h>

namespace towerdefense {

  Levels::Levels(int life, TowerManager* iTMan, EnemyManager* iEMan, Map* m)
  {
      m_life=life;
      m_gameOver=false;
      m_tMan = iTMan;
      m_eMan = iEMan;
      m_map = m;
      m_coins = 100;
      m_paused = false;
      if(!m_font.loadFromFile("res/fonts/Square.ttf")){
        std::cout << "Font can't be loaded !" << std::endl;
        exit(1);
      }
  }

  Levels::~Levels(){
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }

  void Levels::update(float dt){
    std::vector<Enemy*> enemies = m_eMan->getAllEnemies();
    for(Enemy* enemy : enemies){
      if(enemy->GetPosX() >= m_map->getEnd()->getX()-0.1 && enemy->GetPosY() <= m_map->getEnd()->getY()+0.1
         && enemy->GetPosY() >= m_map->getEnd()->getY()-0.1 && enemy->GetPosY() <= m_map->getEnd()->getY()+0.1){
        m_life--;
        m_eMan->removeEnemy(enemy);
      }
    }

    if(m_life <= 0 && !m_gameOver){
      m_gameOver = true;
      pause();
    }

    if(m_eMan->m_enemiKilled){
      winCoins(10);
      m_eMan->m_enemiKilled = false;
    }
  }

  bool Levels::goodEnd(){
    return m_eMan->getAllEnemies().size() == 0;
  }

  bool Levels::badEnd(){
    return m_gameOver;
  }

  void Levels::render(sf::RenderWindow& window){
    std::string str;
    std::ostringstream convert;

    drawString(window, "Life : ", 0, 460);
    drawString(window, "Coins : ", 0, 480);

    convert << m_life;
    str = convert.str();
    drawString(window, convert.str(), 100, 460);
    convert.str("");
    convert.clear();
    convert << m_coins;
    str = convert.str();
    drawString(window, convert.str(), 100, 480);

    if(m_paused && !badEnd() && !goodEnd()){
      sf::Text txt("Paused", m_font, 30);
      drawString(window, "Paused", 250-txt.getLocalBounds().width/2, 235, 30);
    } else if (badEnd()) {
      sf::Text txt("You lose! Press R to restart", m_font, 30);
      drawString(window, "You lose! Press R to restart", 250-txt.getLocalBounds().width/2, 235, 30);
    } else if (goodEnd()) {
      sf::Text txt("You win!", m_font, 30);
      drawString(window, "You win!", 250-txt.getLocalBounds().width/2, 235, 30);
    }
  }

  void Levels::drawString(sf::RenderWindow& window, const std::string str, int x, int y, int charsize){
    sf::Text txt;
    txt.setFont(m_font);
    txt.setString(str);
    txt.setCharacterSize(charsize);
    txt.setColor(sf::Color::Black);
    txt.setPosition(x, y);
    window.draw(txt);
  }

  void Levels::changeLevel(int life){
    m_life=life;
    m_gameOver=false;
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
    m_coins = 100;
  }

  int Levels::getCoins(){
    return m_coins;
  }

  void Levels::cost(int coins){
    m_coins -= coins;
  }

  bool Levels::isPaused(){
    return m_paused;
  }

  void Levels::pause(){
    m_paused = !m_paused;
    m_eMan->pause();
    m_tMan->pause();
  }

  void Levels::winCoins(int coins){
    m_coins += coins;
  }
}
