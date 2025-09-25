#pragma once
#include <iostream>

class vect2 {
    private:
        int x, y;
    public:
        vect2();
        vect2(int x, int y) : x(x), y(y) {};
        vect2(const vect2& v) {
            x = v.x;
            y = v.y;
        };
        ~vect2(){};
        bool operator==(const vect2& v) {
            return (x == v.x && y == v.y);
        }
        bool operator!=(const vect2& v) {
            return (*this == v);
        }
        vect2& operator=(const vect2& v) {
            if (*this != v) {
                x = v.x;
                y = v.y;
            }
            return (*this);
        }


};