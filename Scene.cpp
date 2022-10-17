#include "Scene.h"
#include "Camera.h"

void Scene::addObject(DrawableObject* o) { objects.push_back(o); }

void Scene::render() {
    for (DrawableObject* o : objects) {
        o->setAndDraw();
    }
}

Scene::Scene() {
    // camera = new Camera();
    // CallbackController::getInstance()->registerCamera(camera);
}

Scene::~Scene() {}