#pragma once
#include <string>
#include <map>


class Sheet{
public:
    Sheet(const std::string userName, const std::string sheetName, const std::string pms);
    std::string getSheetName();
    std::string getPermission(const std::string userName);
    double* getContent();
    void setPermission(const std::string userName, const std::string status);

private:
    std::string sheetName;
    std::map<std::string, std::string> permission;
    double content[9] = {};
};