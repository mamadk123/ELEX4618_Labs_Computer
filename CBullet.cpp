#include "stdafx.h"
#include "CBullet.h"
#include <cmath>

CBullet::CBullet(Point2f pos, float angle)
{
    _position = pos;
    _radius = 4;
    _lives = 1;

    float speed = 600.0f;
    _velocity.x = speed * cos(angle);
    _velocity.y = speed * sin(angle);
}

void CBullet::move(double dt)
{
    _position += _velocity * dt;
}

bool CBullet::is_off_screen(cv::Size board) const
{
    if (_position.x < 0 || _position.x > board.width)
        return true;

    if (_position.y < 0 || _position.y > board.height)
        return true;

    return false;
}