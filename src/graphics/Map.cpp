#include <towerdefense/graphics/Map.h>

towerdefense::Map(ResourceManager manager){
  *levelTxt = manager.getLevel("level1.txt");
}
