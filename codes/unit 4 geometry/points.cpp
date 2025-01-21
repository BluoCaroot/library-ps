#include <bits/stdc++.h>
using namespace std;

template <typename ftype>
struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}
    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};
template <typename ftype>
point2d<ftype> operator*(ftype a, point2d<ftype> b) {
    return b * a;
}
template <typename ftype>
ftype dot(point2d<ftype> a, point2d<ftype> b) {
    return a.x * b.x + a.y * b.y;
}

template <typename ftype>
ftype norm(point2d<ftype> a) {
    return dot(a, a);
}
template <typename ftype>
double abs(point2d<ftype> a) {
    return sqrt(norm(a));
}
template <typename ftype>
double proj(point2d<ftype> a, point2d<ftype> b) {
    return dot(a, b) / abs(b);
}
template <typename ftype>
double angle(point2d<ftype> a, point2d<ftype> b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}