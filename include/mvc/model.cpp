#include <iostream>
#include <vector>
#include <stack>
#include "model.h"
using std::cout; 
using std::endl;
using std::string;
using std::vector;
using std::stack;

// class Model : public Subject
User* Model::getUserPtr(string userName){
    for(vector<User*>::iterator u_iter = userList.begin(); u_iter != userList.end(); u_iter++){
        if((*u_iter)->getUserName() == userName){
            return *u_iter;
        }
    }

    return nullptr;
}


Sheet* Model::getSheetPtr(string userName, string sheetName){
    User* userPtr = getUserPtr(userName);
    if(userPtr == nullptr){
        return nullptr;
    }
    vector<Sheet*>* sheetList = userPtr->getSheetList();

    for(vector<Sheet*>::iterator s_iter = (*sheetList).begin(); s_iter != (*sheetList).end(); s_iter++){
        if((*s_iter)->getSheetName() == sheetName){
            return *s_iter;
        }
    }

    return nullptr;
}


void Model::math(char op, vector<double>& numStack){
    double r = numStack.back();
    numStack.pop_back();
    double l = numStack.back();
    numStack.pop_back();

    switch(op){
        case '+': numStack.push_back(l + r); break;
        case '-': numStack.push_back(l - r); break;
        case '*': numStack.push_back(l * r); break;
        case '/': numStack.push_back(l / r); break;
    }
}


double Model::calVal(string value){
    vector<char> charStack;
    vector<double> numStack;

    for(int i = 0; i <= value.size()-1; i++){
        if(value[i] == '(' ){
            charStack.push_back(value[i]);
        }
        else if(value[i] == ')'){
            while(charStack.back() != '('){
                math(charStack.back(), numStack);
                charStack.pop_back();
            }
            charStack.pop_back();
        }
        else if((value[i] >= '0' && value[i] <= '9') || value[i] == '.'){
            string tmp = "";
            while((value[i] >= '0' && value[i] <= '9') || value[i] == '.'){
                tmp += value[i];
                i++;
            }
            i--;
            numStack.push_back(stod(tmp));
        }
        else{
            if(value[i] == '/' || value[i] == '*'){
                charStack.push_back(value[i]);
            }
            else if(value[i] == '+' || value[i] == '-'){
                while(!charStack.empty() && (charStack.back() == '*' || charStack.back() == '/' || charStack.back() == '+' || charStack.back() == '-')){
                    math(charStack.back(), numStack);
                    charStack.pop_back();
                }
                charStack.push_back(value[i]);
            }
        }
    }
    while(!charStack.empty()) {
        math(charStack.back(), numStack);
        charStack.pop_back();
    }

    return numStack.back();
}


void Model::notify(bool printSheet, bool printMenu, string msg){ 
    for(vector<Observer*>::const_iterator o_iter = observers.begin(); o_iter != observers.end(); o_iter++){
        (*o_iter)->update(this, printSheet, printMenu, msg); 
    }
}


double* Model::getSelectedSheet(){
    return selectedSheet;
}


void Model::createUser(string userName){
    User* userPtr = new User(userName);
    userList.push_back(userPtr);

    string msg = "Create a user named \"" + userName + "\".";
    notify(false, true, msg);
}


void Model::createSheet(string userName, string sheetName){
    User* userPtr = getUserPtr(userName);
    Sheet* sheetPtr = new Sheet(userName, sheetName, "rw");
    userPtr->addSheet(sheetPtr);

    string msg = "Create a sheet named \"" + sheetName + "\" for \"" + userName + "\".";
    notify(false, true, msg);
}


bool Model::checkSheet(string userName, string sheetName, bool printMenu){
    Sheet* sheetPtr = getSheetPtr(userName, sheetName);
    if(sheetPtr == nullptr){
        string msg = "\"" + userName + "\" doesn't has \"" + sheetName + "\" or doesn't exist.";
        notify(false, true, msg);
        return false;
    }

    selectedSheet = sheetPtr->getContent();

    notify(true, printMenu, "");
    return true;
}


void Model::changeSheetValue(string userName, string sheetName, int m, int n, string value){
    Sheet* sheetPtr = getSheetPtr(userName, sheetName);
    if(sheetPtr == nullptr){
        string msg = "\"" + userName + "\" doesn't has \"" + sheetName + "\" or doesn't exist.";
        notify(false, true, msg);
        return;
    }

    string permission = sheetPtr->getPermission(userName);
    selectedSheet = sheetPtr->getContent();

    double val = calVal(value);
    if(permission == "rw"){
        selectedSheet[m*3+n] = val;
    }
    else if(permission == "r"){
        string msg = "This sheet is not accessible.";
        notify(true, true, msg);
        return;
    }

    notify(true, true, "");
}


void Model::changeSheetRight(string userName, string sheetName, string status){
    Sheet* sheetPtr = getSheetPtr(userName, sheetName);
    if(sheetPtr == nullptr){
        string msg = "\"" + userName + "\" doesn't has \"" + sheetName + "\" or doesn't exist.";
        notify(false, true, msg);
        return;
    }

    if (status == "ReadOnly"){
        sheetPtr->setPermission(userName, "r");
    }
    else if(status == "Editable"){
        sheetPtr->setPermission(userName, "rw");
    }
    else{
        string msg = "Please enter \"ReadOnly\" or \"Editable\"";
        notify(false, true, msg);
        return;
    }

    notify(false, true, "");
}


void Model::collaborate(string userName, string sheetName, string partnerName){
    User* partnerPtr = getUserPtr(partnerName);
    if(partnerPtr == nullptr){
        string msg = "User \"" + partnerName + "\" doesn't exist!";
        notify(false, true, msg);
        return;
    }

    Sheet* sheetPtr = getSheetPtr(userName, sheetName);
    if(sheetPtr == nullptr){
        string msg = "\"" + userName + "\" doesn't has \"" + sheetName + "\" or doesn't exist.";
        notify(false, true, msg);
        return;
    }

    partnerPtr->addSheet(sheetPtr);
    sheetPtr->setPermission(partnerName, "rw");

    string msg = "Share \"" + userName + "\"'s \"" + sheetName + "\" with \"" + partnerName + "\".";
    notify(false, true, msg);
}