#include <iostream>
#include "controller.h"
using std::cin;
using std::cout; 
using std::endl;
using std::string;

// class Controller
void Controller::setModel(Model &a){
    model = &a;
}


void Controller::MessageLoop(){ 
    int choice = 0; 
    string user, sheet, option;
    int m = 0, n = 0;
    string value;
    while(true){
        cout << "> ";
        cin >> choice;
        if (choice == 7) break;
        cout << "> ";
        switch(choice){
            case 1:
                cin >> user;
                model->createUser(user);
                break; 
            case 2:
                cin >> user >> sheet;
                model->createSheet(user, sheet);
                break;
            case 3:
                cin >> user >> sheet;
                model->checkSheet(user, sheet, true);
                break;
            case 4:
                cin >> user >> sheet;
                if(model->checkSheet(user, sheet, false)){
                    cout << endl << "> ";
                    cin >> m >> n >> value;
                    model->changeSheetValue(user, sheet, m, n, value);
                }
                break;
            case 5:
                cin >> user >> sheet >> option;
                model->changeSheetRight(user, sheet, option);
                break;
            case 6:
                cin >> user >> sheet >> option;
                model->collaborate(user, sheet, option);
                break;
            default:
                cout << "please enter 1-7 to select action" << endl;
                break;
        } 
    } 
}