//
// Created by Adrian Krupa on 02.03.2017.
//

#ifndef AKENGINE_POINT_H
#define AKENGINE_POINT_H

struct Point {
    union indices {
        struct
        {
            unsigned int a;
        };
        unsigned int v[1];
    } indices;

};

#endif //AKENGINE_POINT_H
