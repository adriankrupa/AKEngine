//
// Created by akrupa on 2017-02-21.
//

#ifndef AKENGINE_COMPONENT_H
#define AKENGINE_COMPONENT_H


#include <string>

class Component {

public:

    bool IsEnabled() const;

    void SetActive(bool active);
//    Transform* GetTransform() const ;

    virtual ~Component();
    virtual std::string GetName() const = 0;
    virtual void Start();
    virtual void OnDestroy();
    virtual void Update(float dt);
    virtual void FixedUpdate(float dt);

protected:
private:
    bool isEnabled;
    void *gameObject;
};


#endif //AKENGINE_COMPONENT_H
