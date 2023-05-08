#include "application.h"

// class Application
Application::Application(){ 
    views.setModel(model);
    controller.setModel(model); 
    model.notify(false, true, "");
}


void Application::run(){
    controller.MessageLoop();
}