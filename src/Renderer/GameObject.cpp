//
// Created by Adrian Krupa on 22.02.2017.
//

#include <algorithm>

#include "akengine/Renderer/Components/Component.h"
#include "akengine/Renderer/Components/Transform.h"
#include "akengine/Renderer/Components/Camera.h"
#include "akengine/Renderer/GameObject.h"

using namespace std;

shared_ptr<GameObject> GameObject::CreateGameObject() {
    auto go = shared_ptr<GameObject>(new GameObject());
    go->Init();
    return go;
}

void GameObject::Start() {

}

void GameObject::Update(float dt) {
    if (!isEnabled)
        return;
    for (auto &component : components) {
        component->Update(dt);
    }
}

void GameObject::FixedUpdate(float dt) {
    if (!isEnabled)
        return;
    for (auto &component : components) {
        component->FixedUpdate(dt);
    }
}

void GameObject::OnDestroy() {
    for (auto &component : components) {
        component->OnDestroy();
    }
}

void GameObject::SetName(std::string name) {
    this->name = name;
}

shared_ptr<Transform> GameObject::GetTransform() const {
    return transform;
}

shared_ptr<GameObject> GameObject::AddComponent(shared_ptr<Component> component) {
    if (component == nullptr) {
        return this->shared_from_this();
    }
    if (component->GetName() == "Transform") {
        components.erase(remove_if(components.begin(), components.end(),
                                   [](const shared_ptr<Component> c) { return c->GetName() == "Transform"; }),
                         components.end());

    }
    components.push_back(component);
    component->AssignGameObject(shared_from_this());
    return this->shared_from_this();
}

shared_ptr<GameObject> GameObject::CreateCamera() {
    auto gameObject = GameObject::CreateGameObject();
    gameObject->SetName("Camera");
    auto camera = make_shared<Camera>();
    gameObject->AddComponent(camera);

    return gameObject;
}

GameObject::GameObject() {
    isEnabled = true;
    name = "GameObject";
}

void GameObject::Init() {
    transform = make_shared<Transform>();
    AddComponent(transform);
}
