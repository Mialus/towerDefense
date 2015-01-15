/*
 * Copyright (c) 2014, Julien Bernard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <towerdefense/Entity.h>

namespace towerdefense {

  Entity::~Entity() {
  }

  int Entity::priority() const {
    return 0;
  }

  void Entity::update(float dt) {
    /*
    unsigned int x=en.getPosX();
    unsigned int y=en.getPosY();
    unsigned int xb=en.getPosXb();
    unsigned int yb=en.getPosYb();
    std::string& line= m_level[y+1];

    if((line[x]=='.')&&(yb!=y+1)){
      en.SetPosYb(en.getPosY());
      en.SetPosY(y+1);
    }else {
      line= m_level[y];
      if((line[x+1]=='.')&&(xb!=x+1)){
        en.SetPosXb(en.getPosX());
        en.SetPosX(x+1);
      }else{
        line= m_level[y];
        if((line[x-1]=='.')&&(xb!=x-1)){
          en.SetPosXb(en.getPosX());
          en.SetPosX(x-1);
        }else{
          line= m_level[y-1];
          if((line[x]=='.')&&(yb!=y-1)){
            en.SetPosYb(en.getPosY());
            en.SetPosY(y-1);
          }
        }
      }
    }
//*/
  }

  void Entity::render(sf::RenderWindow& window) {
    /*
    if(((j)==to.getPosX())&& ((i==to.getPosY()))){// we put the tower on map
      sprite=to.Show();
      sprite.setPosition(to.getPosX()*m_tileWidth, to.getPosY()*m_tileHeight);
    }else{
      if(((j)==en.getPosX())&& ((i==en.getPosY()))){//we put the enemy on map
        sprite=en.Show();
        sprite.setPosition(en.getPosX()*m_tileWidth, en.getPosY()*m_tileHeight);
      }else{
        sprite.setPosition(j*m_tileWidth, i*m_tileHeight);
      }
    }
//*/
  }

}
