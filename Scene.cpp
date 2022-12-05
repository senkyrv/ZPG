#include "Scene.h"

void Scene::draw() {
    int i = 0;
    for (DrawableObject* o : drawableObjects) {
        o->objectId = i++;
        glStencilFunc(GL_ALWAYS, o->objectId, 0xFF);
        o->draw();
    }
}
int Scene::getAndIncTextureId()
{
    return textureId++;
}

std::vector<DrawableObject*> Scene::getDrawableObjects()
{
    return drawableObjects;
}
void Scene::insertToScene(DrawableObject* o) {
    drawableObjects.push_back(o);
}

void Scene::removeFromScene(int objectId)
{
    if (clickActionAllowed) {

        int counter = 0;
        for (auto* o : drawableObjects) {

            if (o->objectId == objectId) {

                drawableObjects.erase(drawableObjects.begin() + counter);
                break;
            }
            counter++;
        }
        
    }

}

void Scene::insertTreeToScene(glm::vec3 position)
{
    if (clickActionAllowed) {

        Transformation* t1 = new Transformation();
        t1->translate(position);
        t1->scale(0.4f);

        Aplication::getApp()->getScene()->insertToScene(new DrawableObject(new ModelTree,
            Aplication::getApp()->getScene()->drawableObjects.at(1)->getShader(),
            t1));
    }

}


Scene::Scene() {}
Scene::~Scene() {}