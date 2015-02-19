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
    if(m_life <= 0){
      m_gameOver = true;
    }
  }

  bool Levels::goodEnd(){
    return m_eMan->getAllEnemies().size() == 0;
  }

  bool Levels::badEnd(){
    return m_gameOver;
  }

  void Levels::render(sf::RenderWindow& window){
    sf::Text lbl_life;
    sf::Text lbl_coins;
    sf::Text txt_life;
    sf::Text txt_coins;
    std::string str;
    std::ostringstream convert;

    lbl_life.setFont(m_font);
    lbl_life.setString("Life : ");
    lbl_life.setCharacterSize(20);
    lbl_life.setColor(sf::Color::Black);
    lbl_life.setPosition(0, 460);

    lbl_coins.setFont(m_font);
    lbl_coins.setString("Coins : ");
    lbl_coins.setCharacterSize(20);
    lbl_coins.setColor(sf::Color::Black);
    lbl_coins.setPosition(0, 480);

    convert << m_life;
    str = convert.str();
    txt_life.setFont(m_font);
    txt_life.setString(str);
    txt_life.setCharacterSize(20);
    txt_life.setColor(sf::Color::Black);
    txt_life.setPosition(100, 460);

    convert.str("");
    convert.clear();
    convert << m_coins;
    str = convert.str();
    txt_coins.setFont(m_font);
    txt_coins.setString(str);
    txt_coins.setCharacterSize(20);
    txt_coins.setColor(sf::Color::Black);
    txt_coins.setPosition(100, 480);

    window.draw(lbl_life);
    window.draw(lbl_coins);
    window.draw(txt_coins);
    window.draw(txt_life);
  }

  void Levels::changeLevel(int life){
    m_life=life;
    m_gameOver=false;
    m_tMan->clearTowers();
    m_eMan->clearEnemies();
  }

  int Levels::getCoins(){
    return m_coins;
  }

  void Levels::cost(int coins){
    m_coins -= coins;
  }
}
