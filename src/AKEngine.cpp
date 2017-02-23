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
    auto console = spdlog::stdout_color_mt("console");

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        console->critical(std::string("Failed to initialize glfw!"));
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void AKEngine::setCurrentScene(std::shared_ptr<Scene> scene) {
    currentScene = scene;
}

int AKEngine::run() {

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

//    glfwSetKeyCallback(window, key_callback);

    Renderer *renderer = new Renderer();
    renderer->init();
    renderer->setCurrentScene(currentScene);
    renderer->printContextInfo();

    auto time = glfwGetTime ();

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();

        auto time2 = glfwGetTime ();
        auto deltaTime = time2 - time;
        renderer->updateAndDraw((float)deltaTime);

        time = time2;

    }

    return EXIT_SUCCESS;
}
