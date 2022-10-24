#include "Scene.h"
#include "Camera.h"

void Scene::addObject(DrawableObject* o){
    drawableObjects.push_back(o);
    }

void Scene::render() {
    for (DrawableObject* o : drawableObjects) {
        o->setAndDraw();
    }
}

Scene::Scene() {}
Scene::~Scene() {}