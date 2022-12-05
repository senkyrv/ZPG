#pragma once
#include <list>
#include "Observer.h"
#include <iostream>

class Observer;
class Camera;
class Subject {
protected:
	std::list<Observer*> observers;

public:
	void attach(Observer* ob);
	void detach(Observer* ob);
	void notify(Camera* camera);
};
