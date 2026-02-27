#pragma once
#include "CGameObject.h"

/**
 * @class CAsteroid
 * @brief Represents a moving asteroid in the game.
 *
 * CAsteroid inherits from CGameObject.
 * Asteroids move with constant velocity and wrap
 * around the screen boundaries.
 */
class CAsteroid : public CGameObject
{
public:

    /**
     * @brief Construct an asteroid.
     *
     * @param pos     Initial position.
     * @param vel     Initial velocity.
     * @param radius  Asteroid size.
     */
    CAsteroid(Point2f pos, Point2f vel, int radius);

    /**
     * @brief Update asteroid position.
     *
     * @param dt Time step in seconds.
     */
    void move(double dt);

    /**
     * @brief Draw asteroid on the canvas.
     *
     * @param im OpenCV image to draw on.
     */
    void draw(Mat& im);
};