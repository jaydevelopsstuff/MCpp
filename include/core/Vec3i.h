#pragma once

class Vec3i {
    public:
        static const Vec3i ZERO;

        Vec3i() : m_x(0), m_y(0), m_z(0) {}

        Vec3i(int t_x, int t_y, int t_z) : m_x(t_x), m_y(t_y), m_z(t_z) {}

        int getX() const {
            return m_x;
        }

        int getY() const {
            return m_y;
        }

        int getZ() const {
            return m_z;
        }

        bool equals(const Vec3i& vec) {
            return m_x == vec.m_x && m_y == vec.m_y && m_z == vec.m_z;
        }

        bool operator == (const Vec3i& vec) {
            return equals(vec);
        }

    private:
        int m_x;
        int m_y;
        int m_z;
};