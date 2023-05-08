#include <iostream>
#include "views.h"
#include "model.h"
using std::cout; 
using std::endl;
using std::string;

// class MsgView : public Observer
void MsgView::update(void* a, bool printSheet, bool printMenu, string msg){
    if(msg != "")
        cout << msg << endl;
}


// class SheetView : public Observer
void SheetView::update(void* a, bool printSheet, bool printMenu, string msg){
    if(printSheet){
        sheetContent = static_cast<Model*>(a)->getSelectedSheet();
        cout << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << sheetContent[i*3+j] << ", ";
            }
            cout << endl;
        }
    }
}


// class Views : public Observer
void Views::setModel(Subject &a){
    a.attach(&msgView);
    a.attach(&sheetView);
    a.attach(this);
}


void Views::update(void* a, bool printSheet, bool printMenu, string msg){
    if(printMenu){
        cout << endl;
        cout << "---------------Menu---------------" << endl;
        cout << "1. Create a user"                   << endl;
        cout << "2. Create a sheet"                  << endl;
        cout << "3. Check a sheet"                   << endl;
        cout << "4. Change a value in a sheet"       << endl;
        cout << "5. Change a sheet's access right"   << endl;
        cout << "6. Collaborate with another user"   << endl;
        cout << "7. Exit"                            << endl;
        cout << "----------------------------------" << endl;
    }
}