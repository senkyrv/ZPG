#pragma once

class Camera;
class Observer
{
public:
    Observer() {};
    ~Observer() {};
    virtual void update(Camera* camera) = 0;
};