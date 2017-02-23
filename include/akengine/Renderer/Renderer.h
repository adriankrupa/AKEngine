//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_RENDERER_H
#define AKENGINE_RENDERER_H

class Scene;

class Renderer {

    std::shared_ptr<Scene> currentScene;

public:
    void init();

    void printContextInfo();

    void setCurrentScene(std::shared_ptr<Scene> scene);

    void updateAndDraw(float deltaTime);
};

#endif //AKENGINE_RENDERER_H
