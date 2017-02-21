//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_RENDERER_H
#define AKENGINE_RENDERER_H

class Renderer {

public:
    void init();

    void printContextInfo();

    void updateAndDraw(double deltaTime);
};

#endif //AKENGINE_RENDERER_H
