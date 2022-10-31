#include "Scene.h"

void Scene::draw() {
    for (DrawableObject* o : drawableObjects) {
        o->draw();
    }
}
void Scene::insertToScene(DrawableObject* o) {
    drawableObjects.push_back(o);
}

Scene::Scene() {}
Scene::~Scene() {}