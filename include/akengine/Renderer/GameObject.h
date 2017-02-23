//
// Created by Adrian Krupa on 22.02.2017.
//

#ifndef AKENGINE_GAMEOBJECT_H
#define AKENGINE_GAMEOBJECT_H

#include <memory>
#include <vector>
#include <string>

class Component;

class Transform;

class GameObject : public std::enable_shared_from_this<GameObject> {

public:

    static std::shared_ptr<GameObject> CreateGameObject();

    void Start();

    void Update(float dt);

    void FixedUpdate(float dt);

    void OnDestroy();

    void SetName(std::string name);

    std::shared_ptr<Transform> GetTransform() const;

    std::shared_ptr<GameObject> AddComponent(std::shared_ptr<Component> component);

    static std::shared_ptr<GameObject> CreateCamera();

    template<typename T>
    std::shared_ptr<T> GetComponent() {
        static_assert(std::is_base_of<Component, T>::value,
                      "T must be a descendant of Component"
        );
        for (auto &component : components) {

            std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(component);
            if (t != nullptr) {
                return t;
            }
        }
        return nullptr;
    }

    template<typename T>
    std::vector<std::shared_ptr<T>> GetComponents() {
        static_assert(std::is_base_of<Component, T>::value,
                      "T must be a descendant of Component"
        );
        std::vector<std::shared_ptr<T>> v;
        for (auto &component : components) {

            std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(component);
            if (t != nullptr) {
                v.push_back(t);
            }
        }
        return v;
    }

private:
    GameObject();
    void Init();

    std::string name = "";
    bool isEnabled;
    std::vector<std::shared_ptr<Component>> components;
    std::shared_ptr<Transform> transform;
};


#endif //AKENGINE_GAMEOBJECT_H
