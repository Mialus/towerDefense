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
#include <towerdefense/World.h>

#include <cassert>
#include <algorithm>
#include <memory>

namespace towerdefense {

  void World::update(float dt) {
    std::sort(m_entities.begin(), m_entities.end(), [](const Entity* e1, const Entity* e2) {
      return e1->priority() < e2->priority();
    });

    for (auto entity : m_entities) {
      entity->update(dt);
    }
  }

  void World::render(sf::RenderWindow& window) {
    for (auto entity : m_entities) {
      entity->render(window);
    }
  }

  void World::addEntity(Entity *e, Memory from) {
    m_entities.push_back(e);
  }

  void World::removeEntity(Entity *e) {
    //std::remove_if(m_entities.begin(), m_entities.end(), e);
  }

  void World::registerHandler(EventType type, EventHandler handler) {
    assert(handler);
    auto it = m_handlers.find(type);

    if (it == m_handlers.end()) {
      bool inserted;
      std::tie(it, inserted) = m_handlers.insert(std::make_pair(type, std::vector<EventHandler>()));
      assert(inserted);
    }

    it->second.push_back(handler);
  }

  void World::triggerEvent(Entity *origin, EventType type, Event *event) {
    auto it = m_handlers.find(type);

    if (it == m_handlers.end()) {
      return;
    }

    std::vector<EventHandler> kept;

    for (auto handler : it->second) {
      if (handler(origin, type, event) == EventStatus::KEEP) {
        kept.push_back(handler);
      }
    }

    std::swap(it->second, kept);
  }

}
