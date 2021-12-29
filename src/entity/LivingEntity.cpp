#include "entity/LivingEntity.h"

void Entity::LivingEntity::heal(float t_amount) {
    if(l_health + t_amount > l_maxHealth) l_health = l_maxHealth;
    else l_health = t_amount;
}