//
// Created by Амир Кашапов on 25.02.2024.
//

#ifndef CPPDUNGEON_USESKILL_H
#define CPPDUNGEON_USESKILL_H
#include "actions/Action.h"
#include <vector>
#include <memory>
#include "namespaces/entity.h"
#include "namespaces/skillDesigns.h"
namespace actions {
    class UseSkill : public Action {
    public:
        // UseSkill(Entity* actor, Skill* skill, std::vector<Entity*> entity);
        UseSkill(std::shared_ptr<entity::Entity> actor, skillDesigns::Skill *skill, std::vector<std::shared_ptr<entity::Entity>> entities);
        std::string getName() override;
        void act(Player *) override;
    };
}
#endif //CPPDUNGEON_USESKILL_H
