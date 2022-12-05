#pragma once
#include "Subject.h"

void Subject::attach(Observer* ob)
{
    observers.push_back(ob);
};
void Subject::detach(Observer* ob) {
    observers.remove(ob);
};
void Subject::notify(Camera* camera) {
    for (Observer* ob : observers) {
        ob->update(camera);
    }
};