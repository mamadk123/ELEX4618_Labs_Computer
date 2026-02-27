#include "stdafx.h"
#include "CShip.h"
#include <cmath>

CShip::CShip()
{
    _radius = 15;
    _lives = 3;
    _angle = 0.0f;
}

void CShip::move(double dt)
{
    _position += _velocity * dt;
    // face direction of movement
    if (cv::norm(_velocity) > 0.01f)
    {
        _angle = atan2(_velocity.y, _velocity.x);
    }
}

void CShip::draw(Mat& im)
{
    Point2f tip( _position.x + 20 * cos(_angle), _position.y + 20 * sin(_angle));
    circle(im, _position, _radius, Scalar(255, 255, 255), 1);
    line(im, _position, tip, Scalar(255, 255, 255), 2);
}

void CShip::thrust(Point2f accel, double dt)
{
    _velocity += accel * dt;
    float speed = cv::norm(_velocity);

    if (speed > _max_speed)
        _velocity *= _max_speed / speed;
}