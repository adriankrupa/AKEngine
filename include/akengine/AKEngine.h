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

class Renderer;

class AKEngine {

public:
    ~AKEngine();

    int init();

    int createWindow();
    int createHeadlessWindow();

    int run();

    void setCurrentScene(std::shared_ptr<Scene> scene);
    void destroyWindow();

private:
    GLFWwindow *window;
    std::shared_ptr<Scene> currentScene;
    Renderer *renderer;

};


#endif //AKENGINE_AKENGINE_H
