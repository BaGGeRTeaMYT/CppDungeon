//
// Created by Амир Кашапов on 28.02.2024.
//

#ifndef CPPDUNGEON_INVENTORY_H
#define CPPDUNGEON_INVENTORY_H
#include <vector>
#include <set>
#include <memory>
class Item;
class Inventory {
    std::multiset<std::shared_ptr<Item>> m_items;
public:
    void addItem(Item*);
    void removeItem(Item*);
    std::multiset<Item*> getItems();
};
#endif //CPPDUNGEON_INVENTORY_H
