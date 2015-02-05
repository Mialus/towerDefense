#ifndef CROSSINGPOINT_H
#define CROSSINGPOINT_H

namespace towerdefense {

  class CrossingPoint {
  public :
    CrossingPoint(int x, int y);

    unsigned int getX();
    unsigned int getY();
  private :
    unsigned int m_x;
    unsigned int m_y;
  };
}

#endif // CROSSINGPOINT_H_INCLUDED
