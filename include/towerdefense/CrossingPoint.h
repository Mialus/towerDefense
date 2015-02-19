#ifndef CROSSINGPOINT_H
#define CROSSINGPOINT_H

namespace towerdefense {

  class CrossingPoint {
  public :
    CrossingPoint(int x, int y, char id);

    unsigned int getX();
    unsigned int getY();
    char getId();

  private :
    unsigned int m_id;
    unsigned int m_x;
    char m_y;
  };
}

#endif // CROSSINGPOINT_H_INCLUDED
