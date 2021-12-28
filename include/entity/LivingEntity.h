#pragma once

#include "entity/Entity.h"

namespace Entity {
    class LivingEntity : public Entity {
        public:
            void heal(float amount);

            float getHealth() {
                return m_health;
            }

            void setHealth(float t_health) {
                m_health = t_health;
            }

        protected:
            static float l_maxHealth;

        private:
            float m_health;
    };
}