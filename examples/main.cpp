//
// Created by akrupa on 2017-02-21.
//

#include <akengine/AKEngine.h>

int main() {
    auto engine = new AKEngine();
    engine->init();

    auto scene = std::make_shared<Scene>();
    scene->AddGameObject(GameObject::CreateCamera());
    engine -> setCurrentScene(scene);

    engine->run();
}