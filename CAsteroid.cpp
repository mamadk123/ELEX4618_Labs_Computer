#include "stdafx.h"
#include "CAsteroid.h"

CAsteroid::CAsteroid(Point2f pos, Point2f vel, int radius)
{
    _position = pos;
    _velocity = vel;
    _radius = radius;
    _lives = 1;
}

void CAsteroid::move(double dt)
{
    _position += _velocity * dt;
}

void CAsteroid::draw(Mat& im)
{
    circle(im, _position, _radius, Scalar(0, 0, 200), 2);
}