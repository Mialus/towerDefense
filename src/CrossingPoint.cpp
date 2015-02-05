#include <towerdefense/CrossingPoint.h>

namespace towerdefense {

  CrossingPoint::CrossingPoint(int x, int y){
    m_x = x;
    m_y = y;
  }

  unsigned int CrossingPoint::getX(){
    return m_x;
  }

  unsigned int CrossingPoint::getY(){
    return m_y;
  }
}
