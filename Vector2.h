#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
public:
    int x, y;

    Vector2(int x = 0, int y = 0) : x(x), y(y) {}

    Vector2 interpolate(const Vector2 &other, float t) const {
        int newX = x + t * (other.x - x);
        int newY = y + t * (other.y - y);
        return Vector2(newX, newY);
    }
};
#endif