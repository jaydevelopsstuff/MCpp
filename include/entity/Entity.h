#pragma once

#include "core/Vec3.h"

namespace Entity {
    class Entity {
        public:
            int getId() const {
                return l_id;
            }

            double getX() const {
                return l_position.getX();
            }

            double getY() const {
                return l_position.getY();
            }

            double getZ() const {
                return l_position.getZ();
            }

            Vec3 getPosition() const {
                return l_position;
            }

            float getYaw() const {
                return l_yaw;
            }

            float getPitch() const {
                return l_pitch;
            }

            bool isOnGround() const {
                return l_onGround;
            }

            float getFallDistance() const {
                return l_fallDistance;
            }

        protected:
            int l_id;
            Vec3 l_position;
            float l_yaw;
            float l_pitch;
            bool l_onGround;
            float l_fallDistance;
            // World l_world;
    };
}