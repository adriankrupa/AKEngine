//
// Created by Adrian Krupa on 22.02.2017.
//

#ifndef AKENGINE_SCENE_H
#define AKENGINE_SCENE_H

#include <memory>
#include <vector>

class GameObject;

class Camera;

class Scene {

public :
    void Update(float dt);

    void Render();

    void AddGameObject(std::shared_ptr<GameObject> gameObject);

private:
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    std::vector<std::shared_ptr<Camera>> cameras;

    void Render(const std::shared_ptr<const Camera> camera);

};


#endif //AKENGINE_SCENE_H
