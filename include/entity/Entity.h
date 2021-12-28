#pragma once

#include "core/Vec3.h"

namespace Entity {
    class Entity {
        public:
            int getId() const {
                return m_id;
            }

            double getX() const {
                return m_position.getX();
            }

            double getY() const {
                return m_position.getY();
            }

            double getZ() const {
                return m_position.getZ();
            }

            Vec3 getPosition() const {
                return m_position;
            }

            float getYaw() const {
                return m_yaw;
            }

            float getPitch() const {
                return m_pitch;
            }

            bool isOnGround() const {
                return m_onGround;
            }

            float getFallDistance() const {
                return m_fallDistance;
            }

        protected:
            int m_id;
            Vec3 m_position;
            float m_yaw;
            float m_pitch;
            bool m_onGround;
            float m_fallDistance;
            // World m_world;
    };
}