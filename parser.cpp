//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>
#include <array>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

// check if the command is valid
bool validCommand(string s){
    bool indicator = false;
    for (int i = 1; i < NUM_KEYWORDS; i++){
        if (keyWordsList[i] == s){
            indicator = true;
            break;
        }
    }
    return indicator;
}  

// check if the argument types pass in is valid
// name is reserved for shape types 
bool validShapeName(string &s){
    bool indicator;
    for (int i = 0; i < NUM_KEYWORDS; i++){
        if (s != keyWordsList[i]){
            indicator = true;
            if (i < NUM_TYPES && s == shapeTypesList[i]){
                indicator = false;
                cout << "Error: invalid shape name" << endl;
                break;
            }
        }else {
            indicator = false;
            cout << "Error: invalid shape name" << endl;
            break;
        }        
    }
    return indicator;
}  

// check if name already exists in the current database
bool nameExists(string &s){
    bool indicator;
    for ( int i = 0; i < max_shapes; i++ ) {
        if ( shapesArray[i] == nullptr ){
            return true;
        }
        if ( s == shapesArray[i]->getName() ) {
            indicator = false;
            cout << "Error: shape " << shapesArray[i]->getName() << " exists" << endl;
            break;
        } else {
            indicator = true;    
        }   
    }
    return indicator;
}

// check if the name does exist
bool nameNotFound(string &s){
    bool indicator = false;
    if (s == "all"){
        return true;
    }
    for (int i = 0; i < max_shapes; i++){
        if( shapesArray[i] == nullptr){
            cout << "Error: shape " << s << " not found" << endl;
            return false;
        }
        if ( s == shapesArray[i]->getName()){
            indicator = true;
            break;
        }
    }
    if (indicator == false){
        cout << "Error: shape " << s << " not found" << endl;
    }
    return indicator;
}

// check if the type is valid
bool validType(string &s){
    bool indicator = false;
    for (int i = 0; i < NUM_TYPES; i++){
        if ( s == shapeTypesList [i]){
            indicator = true;
            break;
        }
    }
    if (indicator == false){
        cout << "Error: invalid shape type" << endl;
    }
    return indicator;
}

// check if the argument number is too long or too few
bool argNum(string input, int command_Num){
    
    if (command_Num == 0){
        cout << "Error: invalid command" << endl;
        return false;
    }
    if (input.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    bool indicator;
    int count = 0;
    if(command_Num == 1){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 1){
            indicator = true;
            return true;
        }else if(count < 1){
            cout << "Error: too few arguments" << endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }    
    }
    if(command_Num == 2){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 6){
            indicator = true;
            return true;
        }else if(count < 6){
            cout << "Error: too few arguments" << endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }
    }
    if(command_Num == 3){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 3){
            indicator = true;
            return true;
        }else if(count < 3){
            cout << "Error: too few arguments" << endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }
    }
    if(command_Num == 4){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 2){
            indicator = true;
            return true;
        }else if(count < 2){
            cout << "Error: too few arguments" << endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }
    }
    if(command_Num == 5){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 1){
            indicator = true;
            return true;
        }else if(count < 1){
            cout << "Error: too few arguments" <<endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }
    }
    if(command_Num == 6){
        for (int i = 0; i < input.size(); i++){
            if (input[i] == ' ' && input[i + 1] == ' '){
                continue;
            }
            if (input[i] == ' '){
            count++;
            }
        }
        if (count == 1){
            indicator = true;
            return true;
        }else if(count < 1){
            cout << "Error: too few arguments" << endl;
            indicator = false;
            return false;
        } else {
            cout << "Error: too many arguments" << endl;
            indicator = false;
            return false;
        }
    }
    return indicator;
}

bool validArgument(stringstream &lineStream, string argument, int command_Num){
    if (lineStream.fail()){ 
        if (argNum(argument, command_Num)){
        cout << "Error: invalid argument" << endl;
         return false;
        }
    } else {
        return true;
    }
} 

// find the command number at the beginning 
int find_Command(string s){
    int command_Num = 0;
    if (validCommand(s)){
        for (int i = 0; i < NUM_KEYWORDS; i++){
            if (keyWordsList[i] == s){
                command_Num = i;
            }
        }
    }
    return command_Num;
}

//allocate the space for max_count of shapses
void max_Shape(int a){
    max_shapes = a;
    //shapesArray = new Shape* [max_shapes];
    shapesArray = new Shape* [max_shapes];          
    for (int i = 0; i < max_shapes; i++) {
        shapesArray[i] = nullptr;
    }
    cout << "New database: max shapes is " << max_shapes << endl;
}

//create a shape with location and size
void create_Shape(string name, string type, int x_loc, int x_sz, int y_loc, int y_sz){
    if(shapeCount < max_shapes){
    shapesArray[shapeCount] = new Shape(name, type, x_loc, y_loc, x_sz, y_sz);

    cout << "Created " << shapesArray[shapeCount]->getName() << ": " << shapesArray[shapeCount]->getType();
    cout << " " << shapesArray[shapeCount]->getXlocation();
    cout << " " << shapesArray[shapeCount]->getYlocation();
    cout << " " << shapesArray[shapeCount]->getXsize() << " " << shapesArray[shapeCount]->getYsize();
    cout << endl;
    shapeCount++;
    } else {
        cout << "Error: shape array is full" << endl;
    }
}

//move one shape to a location
void move_Shape(string name, int x_loc, int y_loc){
    for (int i = 0; i < max_shapes; i++){
        if (shapesArray[i]->getName() == name){
        shapesArray[i]->setXlocation(x_loc);
        shapesArray[i]->setYlocation(y_loc);
        
        cout << "Moved " << shapesArray[i]->getName() << " to";
        cout << " " << shapesArray[i]->getXlocation();
        cout << " " << shapesArray[i]->getYlocation();
        cout << endl;
        break;
        }
    }
}

//rotate the shape by what angle
void rotate_Shape(string name, int angle){
    for (int i = 0; i < max_shapes; i++){
        if (shapesArray[i]->getName() == name){
            shapesArray[i]->setRotate(angle);
             
            cout << "Rotated " <<  shapesArray[i]->getName()<< " " << "by "<< angle << " degrees";
            cout << endl;
            break;
        }
    }
}

//draw one shape or all shapes
void draw_Shape(string name){
    if (name != "all"){
        for (int i = 0; i < max_shapes; i++){
            if (shapesArray[i]->getName() == name){
                cout << "Drew ";
                shapesArray[i]->draw();
                break;
            }
        }
    } else {
        cout << "Drew all shapes" << endl;
        for (int i = 0; i < max_shapes; i++){
            if (shapesArray[i] != NULL){
                shapesArray[i]->draw();
            }
        }
    }
}

//delete one shape or all shapses 
void delete_Shape(string name){
    if (name != "all"){
        for (int i = 0; i < max_shapes; i++){
            if (shapesArray[i]->getName() == name){
                cout << "Deleted "<< "shape" << " " << shapesArray[i]->getName() << endl;
                delete shapesArray[i]; 
                shapesArray[i] = nullptr;
                break;
            }
        }
    } else {
        for (int i = 0; i < max_shapes; i++){
            if (shapesArray[i] != NULL){
                delete shapesArray[i];
                shapesArray[i] = nullptr;
            }
        }
        shapeCount = 0;
        max_shapes = 0;
        cout << "Deleted: all shapes" << endl;
    }
}

//check the max_Shape command
bool checkMax ( stringstream &lineStream, int value, string argument, int command_Num){
    bool indicator = false;
    if (argument.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    if (value >= 0){
        if(validArgument(lineStream, argument, command_Num) == true){
            if (argNum(argument, command_Num)){
                indicator = true;
            }
        }
    } else {
        cout << "Error: invalid value" << endl;
        return false;
    }
    return indicator;
}

//check the Create command
bool checkCreate(stringstream &lineStream, string name, string type, int x_loc, int y_loc, int x_sz, int y_sz, string argument, int command_Num){
    bool indicator = false;
    if (name.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    if (validArgument(lineStream, argument, command_Num)){
        if (argNum(argument, command_Num)){
            if (validShapeName(name) == true && nameExists(name) == true){
                if (validType(type) == true){
                    if (x_loc >= 0 && y_loc >= 0 && x_sz >= 0 && y_sz >= 0){
                        if (type == "circle"){
                            if (x_loc == y_loc && x_sz == y_sz){
                                indicator = true;
                            }
                            else {
                                cout << "Error: invalid value" << endl;
                                return false;
                            }
                        }
                        indicator = true;
                    } else {
                        cout << "Error: invalid value" << endl;
                    }
                } 
            } 
        }
    } 
    return indicator;
}

//check the move command
bool checkMove(stringstream &lineStream, string name, int x_loc, int y_loc, string argument, int command_Num){
    bool indicator = false;
    if (name.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    if (nameNotFound(name)){
        if (validArgument(lineStream, argument, command_Num)){
            if(argNum(argument, command_Num)){
                if(x_loc < 0 || y_loc < 0){
                    cout << "Error: invalid value" << endl;
                } else {
                    indicator = true;
                } 
            }
        }
    }
    return indicator;
}

//check the rotate command
bool checkRotate(stringstream &lineStream, string name, int angle, string argument, int command_Num){
    bool indicator = false;
    if (name.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    if (validArgument(lineStream, argument, command_Num)){
        if (nameNotFound(name)){
            if (argNum(argument, command_Num)){
                if (angle < 0 || angle > 360){
                    cout << "Error: invalid value" << endl;
                } else {
                    indicator = true;
                }
            }
        }
    }
    return indicator;
}

//check the Draw and delete command
bool checkDrawDelete (stringstream &lineStream, string name, string argument, int command_Num){
    bool indicator = false;
    if (name.empty()){
        cout << "Error: too few arguments" << endl;
        return false;
    }
    if (nameNotFound(name)){
        if (argNum(argument, command_Num)){
            if (validArgument(lineStream, argument, command_Num)){
                indicator = true;
            } else {
                indicator = false;
            }
        }
    }
    return indicator;
}

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input
    
    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;
        
        int command_Num;
        command_Num = find_Command(command);
        
        //check the rest of the string (except the command)
        string argument;
        getline(lineStream, argument);
        stringstream Guan(argument);
        
            string name;
            string type;
            int x_loc, y_loc, x_sz, y_sz, angle;
            switch (command_Num){
                case 0:
                    cout << "Error: invalid command" << endl;
                    break;
                case 1:
                    Guan >> max_shapes;
                    if (checkMax(Guan, max_shapes, argument, command_Num)){
                         max_Shape(max_shapes);
                    }
                    break;
                case 2:
                    Guan >> name >> type >> x_loc >> y_loc >> x_sz >> y_sz;
                    if (checkCreate(Guan, name, type, x_loc, y_loc, x_sz, y_sz, argument, command_Num)){
                        create_Shape(name, type, x_loc, y_loc, x_sz, y_sz);
                    }
                    break;
                case 3:
                    Guan >> name >> x_loc >> y_loc;
                    if (checkMove(Guan, name, x_loc, y_loc, argument, command_Num)){
                        move_Shape(name, x_loc, y_loc);
                    }
                    break;
                case 4:
                    Guan >> name >> angle;
                    if (checkRotate(Guan, name, angle, argument, command_Num)){
                        rotate_Shape(name, angle);
                    }
                    break;
                case 5:
                    Guan >> name; 
                    if(checkDrawDelete(Guan, name, argument, command_Num)){
                        draw_Shape(name);
                    }
                    break;
                case 6:
                    Guan >> name;
                    if(checkDrawDelete(Guan, name, argument, command_Num)){
                            delete_Shape(name);
                    }
                    break;
            }
         
        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        
        
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }// End input loop until EOF.
    
    return 0;
}

