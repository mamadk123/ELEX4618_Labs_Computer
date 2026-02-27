#pragma once
#include "CGameObject.h"

/**
 * @class CShip
 * @brief Represents the player controlled spaceship.
 *
 * CShip inherits from CGameObject.
 * The ship accelerates based on joystick input,
 * has a maximum speed limit, and always faces
 * the direction of movement.
 */
class CShip : public CGameObject
{
public:

    /**
     * @brief Construct a ship object.
     *
     * Initializes radius, lives, and orientation.
     */
    CShip();

    /**
     * @brief Update ship position and orientation.
     *
     * @param dt Time step in seconds.
     */
    void move(double dt);

    /**
     * @brief Draw ship on the screen.
     *
     * @param im OpenCV image to draw on.
     */
    void draw(Mat& im);

    /**
     * @brief Apply acceleration to the ship.
     *
     * Acceleration modifies velocity. Velocity is
     * clamped to a maximum speed.
     *
     * @param accel Acceleration vector.
     * @param dt    Time step in seconds.
     */
    void thrust(Point2f accel, double dt);

private:

    /**
     * @brief Maximum ship speed in pixels per second.
     */
    float _max_speed = 300.0f;
};