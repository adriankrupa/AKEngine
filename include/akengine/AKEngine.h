//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_AKENGINE_H
#define AKENGINE_AKENGINE_H

#include <memory>
#include "akengine/Renderer/Scene.h"
#include "akengine/Renderer/GameObject.h"
#include "akengine/Renderer/Components/Camera.h"

struct GLFWwindow;

class AKEngine {

public:
    ~AKEngine();

    int init();

    int run();

    void setCurrentScene(std::shared_ptr<Scene> scene);

private:
    GLFWwindow *window;
    std::shared_ptr<Scene> currentScene;

};


#endif //AKENGINE_AKENGINE_H
