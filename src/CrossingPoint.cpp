#include <towerdefense/CrossingPoint.h>

namespace towerdefense {

  CrossingPoint::CrossingPoint(int x, int y, char id){
    m_x = x;
    m_y = y;
    m_id = id;
  }

  unsigned int CrossingPoint::getX(){
    return m_x;
  }

  unsigned int CrossingPoint::getY(){
    return m_y;
  }

  char CrossingPoint::getId(){
    return m_id;
  }
}
