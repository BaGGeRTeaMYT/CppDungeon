//
// Created by artem on 28.02.2024.
//
#include "Event.h"
#include "Player.h"
#include "Chest.h"
#include "Use.h"
#include "Cell.h"
#include "Map.h"
#include "Item.h"
#include <memory>
#include "Monitor.h"

bool Chest::comp(std::set<std::shared_ptr<Action>>::iterator actionIterator) {
    if (typeid(*((*actionIterator).get())) == typeid(Use)) {
        Use* use = static_cast<Use*>((*actionIterator).get());
        if (use->getChest() == this) {
            return true;
        }
    }
    return false;
}

void Chest::turn(Player *player, int index) {
    player->getMonitor()->draw();
    if (!Chest::used) {
        std::shared_ptr<Action> u(static_cast<Action*>(new Use(this, index)));
        addAction(player, std::move(u));
    }
    player->getMap()->getCell(player->getPosition())->freeMoves(player, index);
}

void Chest::use(Player *player, int  /*index*/) {
    Item item1 = Item();
    getInventory(player).addItem(&item1);
    removeAction(player, [this](std::set<std::shared_ptr<Action>>::iterator actionIterator){return comp(actionIterator);});
    used = true;
}

std::vector<std::vector<char>> Chest::draw() {
//     -------
//    |___-___|
//    |__|_|__|
//    |___-___|
//     -------
    return {{' ', '-', '-', '-', '-', '-', '-', '-', ' ' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {'|', '_', '_', '|', '-', '|', '_', '_', '|' },
            {'|', '_', '_', '_', '-', '_', '_', '_', '|' },
            {' ', '-', '-', '-', '-', '-', '-', '-', ' ' }};
}