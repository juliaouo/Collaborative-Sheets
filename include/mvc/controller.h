#pragma once
#include "model.h"
#include "views.h"


class Controller{
private:
    Model* model;
public:
    void setModel(Model &a);
    void MessageLoop();
};