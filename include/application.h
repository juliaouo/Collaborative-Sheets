#include "mvc/model.h"
#include "mvc/views.h"
#include "mvc/controller.h"


class Application{
private:
    Model model; 
    Views views; 
    Controller controller;
public:
    Application();
    void run();
};