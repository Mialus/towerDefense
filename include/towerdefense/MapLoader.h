#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <vector>

#include <towerdefense/Map.h>

namespace towerdefense {

  class MapLoader {
  public:
    static Map loadMap(std::string levelpath);
  private:

  };

}

#endif // MAPLOADER_H
