#pragma once

#include "entity/Entity.h"

namespace Entity {
    class LivingEntity : public Entity {
        public:
            void heal(float t_amount);

            float getHealth() {
                return l_health;
            }

            void setHealth(float t_health) {
                if(t_health < 0) l_health = 0;
                else l_health = t_health;
            }

            bool isDead() {
                return l_dead;
            }

        protected:
            static float l_maxHealth;
            float l_health;
            bool l_dead;
    };
}