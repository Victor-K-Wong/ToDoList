/*Victor Wong
Programming Assignment 4
Purpose: Creates a TodoList editor that allows its user to edit to-do lists
*/
#include "list.h"
#include <iostream> 
#include <sstream>
#include <string>
using namespace std;

//Function prototypes:
void display_TodoList(const TodoList& todolist);
void save(TodoList& todolist);
void load(TodoList& todolist);

int main(){
//Declaring two TodoList
    TodoList active_list;
    TodoList saved_list;
//String variable for command
    string command;

    bool run = true;
//Main loop that performs TodoList operations
    while(run == true){
        string full_command;
        getline(cin, full_command);

        istringstream is(full_command);
        is >> command;

        if(command == "quit"){
//Exits the loop and ends the program
            run = false;
        } else if(command == "add"){
            string name, text;
            is >> name;
            getline(is, text);
            active_list.add(name, text);
        } else if(command == "remove"){
            string name, extra;
            is >> name;
// Print an error message if extra input is provided
            if(!is.eof()){
                cout << "Error: Too many arguments provided." << endl;
            } else{
            getline(is, name);
            active_list.remove(name);
            }
        } else if(command == "check"){
            string name; // extra;
            is >> name;
            if(!is.eof()){
                cout << "Error: Too many arguments provided." << endl;
            } else{
            active_list.check(name);
            }
        } else if(command == "uncheck"){
            string name; //extra;
            is >> name;
            if(!is.eof()){
                cout << "Error: Too many arguments provided." << endl;
            } else{
            active_list.uncheck(name);
            }
        } else if(command == "save"){
            save(active_list);
        } else if(command == "load"){
            load(active_list);
        } else{
// Prints an error message for unrecognized commands
            cout << "Error: Please try again." << endl;
            continue;
        }
//Displays the updated TodoList after each command
        if(run){
        display_TodoList(active_list);
        }
    }
//End of the program
    return 0;
}

/*Displays the content of a TodoList
Precondition: Takes a constant reference to a TodoList (todolist)
Postcondition: Prints the tasks in the TodoList with their status 
(checked or unchecked)
*/
void display_TodoList(const TodoList& todolist){
    Node* current = todolist.get_head();
    while(current != nullptr){
        cout << "[" << (current->check ? "X" : " ") << "]" << current->name
        << current->text << endl;
        current = current->next;
    }
}

/* Function to save the current state of a TodoList
Precondition: Takes a reference to a TodoList (todolist)
Postcondition: Saves the current state of the TodoList for future 
retrieval
*/
void save(TodoList& todolist){
    todolist.save();
}

/*Function to load a saved state of a TodoList
Precondition: Takes a reference to a TodoList (todolist)
Postcondition: Replaces the current TodoList content with a previously 
saved state
*/
void load(TodoList& todolist){
    todolist.load();
}