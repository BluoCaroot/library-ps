#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    pair<double, double> polarCoordinates()
    {
        return {sqrt(x * x + y * y), atan2(y, x)};
    }
};