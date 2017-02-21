//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_AKENGINE_H
#define AKENGINE_AKENGINE_H

struct GLFWwindow;


class AKEngine {

public:
    ~AKEngine();
    int init();
    int run();

private:
    GLFWwindow *window;

};


#endif //AKENGINE_AKENGINE_H
