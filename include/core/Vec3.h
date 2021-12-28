#pragma once

class Vec3 {
    public:
        static const Vec3 ZERO;

        Vec3() : m_x(0), m_y(0), m_z(0) {}

        Vec3(double t_x, double t_y, double t_z) : m_x(t_x), m_y(t_y), m_z(t_z) {}

        double getX() const {
            return m_x;
        }

        double getY() const {
            return m_y;
        }

        double getZ() const {
            return m_z;
        }

        bool equals(const Vec3& vec) {
            return m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z;
        }

        bool operator == (const Vec3& vec) {
            return equals(vec);
        }

    private:
        double m_x;
        double m_y;
        double m_z;
};