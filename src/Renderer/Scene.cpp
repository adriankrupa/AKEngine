//
// Created by Adrian Krupa on 22.02.2017.
//

#include "akengine/Renderer/Scene.h"
#include "akengine/Renderer/GameObject.h"
#include "akengine/Renderer/Components/Camera.h"

void Scene::Update(float dt) {
    for (auto &gameObject: gameObjects) {
        gameObject->Update(dt);
    }
}

void Scene::Render() {
    for (auto &camera : cameras) {
        if (camera == nullptr || !camera->IsEnabled()) {
            continue;
        }
        Render(camera);
    }
}

void Scene::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.push_back(gameObject);

    auto cameras = gameObject->GetComponents<Camera>();
    this->cameras.insert(this->cameras.end(), cameras.begin(), cameras.end());
}

void Scene::Render(const std::shared_ptr<const Camera> camera) {
    camera->Clear();
}


