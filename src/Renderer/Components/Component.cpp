//
// Created by akrupa on 2017-02-21.
//

#include <spdlog/spdlog.h>

#include "akengine/Renderer/Components/Component.h"


bool Component::IsEnabled() const {
    return isEnabled;
}

void Component::SetActive(bool active) {
    isEnabled = active;
}

Component::~Component() {
    gameObject.reset();
}

void Component::Start() {
    if (gameObject.expired()) {
        auto console = spdlog::get("console");
        console->error("Component " + GetName() + " has no game object");
    }
}

void Component::OnDestroy() {

}

void Component::Update(float dt) {
    (void) dt;
    if (gameObject.expired()) {
        auto console = spdlog::get("console");
        console->error("Component " + GetName() + " has no game object");
    }
}

void Component::FixedUpdate(float dt) {
    (void) dt;
    if (gameObject.expired()) {
        auto console = spdlog::get("console");
        console->error("Component " + GetName() + " has no game object");
    }
}

void Component::AssignGameObject(std::weak_ptr<GameObject> gameObject) {
    if (!gameObject.expired()) {
        this->gameObject = gameObject;
        Start();
    } else {
        this->gameObject = gameObject;
    }
}
