//
// Created by akrupa on 2017-02-21.
//

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <spdlog/spdlog.h>

#include "akengine/Renderer/Renderer.h"
#include "akengine/Renderer/Scene.h"

using namespace gl;
using namespace std;

void Renderer::init() {
    glbinding::Binding::initialize();
}

void Renderer::printContextInfo() {
    auto console = spdlog::get("console");
    console->info("GL_VENDOR: " + string((char *) glGetString(GL_VENDOR)));
    console->info("GL_VERSION: " + string((char *) glGetString(GL_VERSION)));
    console->info("GL_RENDERER: " + string((char *) glGetString(GL_RENDERER)));
    console->info("GL_SHADING_LANGUAGE_VERSION: " + string((char *) glGetString(GL_SHADING_LANGUAGE_VERSION)));
}

void Renderer::setCurrentScene(std::shared_ptr<Scene> scene) {
    currentScene = scene;
}

void Renderer::updateAndDraw(float deltaTime) {
    currentScene->Update(deltaTime);
    currentScene->Render();
}
