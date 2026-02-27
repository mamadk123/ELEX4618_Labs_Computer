#pragma once
#include "CGameObject.h"

/**
 * @class CBullet
 * @brief Represents a projectile fired by the ship.
 *
 * CBullet inherits from CGameObject and uses
 * position and velocity from the base class.
 *
 * Bullets move in a straight line at constant velocity
 * and are destroyed when leaving the screen.
 */
class CBullet : public CGameObject
{
public:

    /**
     * @brief Construct a bullet at a given position and direction.
     *
     * @param pos   Starting position of the bullet.
     * @param angle Direction of travel in radians.
     */
    CBullet(cv::Point2f pos, float angle);

    /**
     * @brief Update bullet position using time based motion.
     *
     * @param dt Time step in seconds.
     */
    void move(double dt);

    /**
     * @brief Check if bullet is outside the screen bounds.
     *
     * @param board Screen size.
     * @return true if bullet is off screen.
     * @return false otherwise.
     */
    bool is_off_screen(cv::Size board) const;
};