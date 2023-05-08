# Collaborative Sheets
[detail](https://github.com/juliaouo/Collaborative-Sheets/blob/main/109502543%E6%9E%97%E6%80%A1%E8%90%B1.pdf)
## Feature
1. Able to create users
2. Let users can create their new sheet
3. Let users can print out their sheet
4. Let users can change the content of their sheet
5. Let sheet has two access rights, read-only or editable, for every user.
6. Let users can share their sheet with other users
7. Let sheets can deal with rational arithmetic `+` , `-` , `*` , `/` .
Possible input: rational number like `123.456` , `123` and operators like `+` ,  `-` , `*` , `/` .

## Usage
To compile:
```
g++ main.cpp ./include/application.cpp ./include/datastruc/sheet.cpp ./include/datastruc/user.cpp ./include/mvc/observerPattern.cpp ./include/mvc/controller.cpp ./include/mvc/model.cpp ./include/mvc/views.cpp -Iinclude -o main
```

To run:
```
./main.exe
```
