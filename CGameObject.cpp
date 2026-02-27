#include "stdafx.h"
#include "CGameObject.h"
#include <cmath>

CGameObject::CGameObject()
{
    _position = Point2f(0, 0);
    _velocity = Point2f(0, 0);
    _radius = 10;
    _lives = 1;
    _angle = 0.0f;
    _angular_vel = 0.0f;
}

void CGameObject::move(double dt)
{
    _position += _velocity * (float)dt;
    _angle += _angular_vel * (float)dt;
}

bool CGameObject::collide(CGameObject& obj)
{
    float distance = norm(_position - obj._position);
    return distance < (_radius + obj._radius);
}

bool CGameObject::collide_wall(Size board)
{
    if (_position.x < 0 || _position.x > board.width)
        return true;

    if (_position.y < 0 || _position.y > board.height)
        return true;

    return false;
}

void CGameObject::hit()
{
    _lives--;
}

void CGameObject::draw(Mat& im)
{
    circle(im, _position, _radius, Scalar(255, 255, 255), 1);
}

