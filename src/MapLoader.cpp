#include <towerdefense/MapLoader.h>

namespace towerdefense{

  Map MapLoader::loadMap(std::string levelpath){
    Map mapReturned;

    std::ifstream levelTxt(levelpath);
    std::string line;
    std::vector<std::vector<MapIdentifier>> level;

    mapReturned.setWidth(500);
    mapReturned.setHeight(500);

    // Loading text file for level definition
    if (levelTxt.is_open())
    {
      while(getline(levelTxt,line))
      {
        int j=0;
        level.push_back(std::vector<MapIdentifier>());
        for(int i=0; i<line.length(); i++){
          switch(line[i]){
          case '#':
            level.at(j).push_back(MapIdentifier::FIELD);
            break;
          case 'D':
            level.at(j).push_back(MapIdentifier::START);
            break;
          case 'A':
            level.at(j).push_back(MapIdentifier::END);
            break;
          case '.':
            level.at(j).push_back(MapIdentifier::PATH);
            break;
          default:
            level.at(j).push_back(MapIdentifier::FIELD);
            break;
          }
        }
        j++;
      }
      levelTxt.close();
    }
    else {
      std::cout << "Unable to open file";
    }
    return mapReturned;
  }
}
