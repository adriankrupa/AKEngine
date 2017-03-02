//
// Created by akrupa on 2017-02-21.
//

#include "akengine/AKEngine.h"

#include <spdlog/spdlog.h>
#include <glfw/glfw3.h>
#include <akengine/Renderer/Renderer.h>

void error_callback(int error, const char *description) {
    auto console = spdlog::get("console");
    console->error(std::string(description));
}

AKEngine::~AKEngine() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int AKEngine::init() {
    auto console = spdlog::get("console");;
    if (!console) {
        console = spdlog::stdout_color_mt("console");
    }

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        console->critical(std::string("Failed to initialize glfw!"));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int AKEngine::createWindow() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "AKRenderer", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    renderer = new Renderer();
    renderer->init();

    return EXIT_SUCCESS;
}

int AKEngine::createHeadlessWindow() {
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    return this->createWindow();
}


int AKEngine::run() {

//    glfwSetKeyCallback(window, key_callback);


    renderer->setCurrentScene(currentScene);
    renderer->printContextInfo();

    auto time = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        auto time2 = glfwGetTime();
        auto deltaTime = time2 - time;
        renderer->updateAndDraw((float) deltaTime);

        time = time2;

    }

    return EXIT_SUCCESS;
}

void AKEngine::setCurrentScene(std::shared_ptr<Scene> scene) {
    currentScene = scene;
}

void AKEngine::destroyWindow() {
    if(window) {
        glfwDestroyWindow(window);
    }
    window = nullptr;
}
