#pragma once
#include <opencv2/opencv.hpp>

using namespace cv;

/**
 * @class CGameObject
 * @brief Base class for all game entities.
 *
 * Provides common properties and behavior for all
 * moving objects such as position, velocity,
 * collision radius, lives, and orientation.
 *
 * Derived classes include:
 * - CShip
 * - CAsteroid
 * - CBullet
 */
class CGameObject
{
protected:

    Point2f _position;    ///< Current position
    Point2f _velocity;    ///< Current velocity vector
    int _radius;          ///< Collision radius
    int _lives;           ///< Remaining lives

    float _angle;         ///< Orientation angle (radians)
    float _angular_vel;   ///< Angular velocity (optional)

public:

    /**
     * @brief Construct a game object with default values.
     */
    CGameObject();

    /**
     * @brief Update position using time based motion.
     * @param dt Delta time in seconds.
     */
    void move(double dt);

    /**
     * @brief Check collision with another object.
     * @param obj Other game object.
     * @return True if objects overlap.
     */
    bool collide(CGameObject& obj);

    /**
     * @brief Check collision with screen boundaries.
     * @param board Screen size.
     * @return True if object touches boundary.
     */
    bool collide_wall(Size board);

    /**
     * @brief Reduce object life by one.
     */
    void hit();

    /// @brief Get remaining lives.
    /// @return Current life count.
    int get_lives() { return _lives; }

    /// @brief Set remaining lives.
    /// @param lives New life count.
    void set_lives(int lives) { _lives = lives; }

    /// @brief Set object position.
    /// @param pos New position.
    void set_pos(Point2f pos) { _position = pos; }

    /// @brief Get object position.
    /// @return Current position.
    Point2f get_pos() { return _position; }

    /// @brief Set object velocity.
    /// @param vel New velocity.
    void set_vel(Point2f vel) { _velocity = vel; }

    /// @brief Get object velocity.
    /// @return Current velocity.
    Point2f get_vel() { return _velocity; }

    /// @brief Set collision radius.
    /// @param r New radius.
    void set_radius(int r) { _radius = r; }

    /// @brief Get collision radius.
    /// @return Current radius.
    int get_radius() { return _radius; }

    /// @brief Set orientation angle.
    /// @param a Angle in radians.
    void set_angle(float a) { _angle = a; }

    /// @brief Get orientation angle.
    /// @return Current angle in radians.
    float get_angle() { return _angle; }

    /**
     * @brief Draw object on screen.
     *
     * Base implementation may draw a simple circle.
     * Derived classes may override for custom graphics.
     */
    void draw(Mat& im);

    /**
     * @brief Virtual destructor.
     */
    virtual ~CGameObject() {}
};