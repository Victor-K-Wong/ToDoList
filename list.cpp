#include "list.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*Default Constructor
Precondition: None
Postcondition: Initializes an empty TodoList with head and saved list to
nullptr
*/
TodoList::TodoList() : head(nullptr), saved_list(nullptr){}

/*Copy Constructor
Precondition: Takes refrence to an existing TodoList
Postcondition: Creates a deep copy of the other TodoList, copying each Node
*/
TodoList::TodoList(TodoList const& other) : head(nullptr){
    Node* other_node = other.head;
    Node* current = nullptr;
    
    while(other_node != nullptr){
        Node* temp = 
        new Node(other_node->name, other_node->text, other_node->check);
        if(head == nullptr){
            head = temp;
            current = head;
        } else{
            current->next = temp;
            current = temp;
        }
        other_node = other_node->next;
    } 
}

/*Copy Assignment Operator
Precondition: Takes refrence to an existing TodoList (other)
Postcondition: Replaces the content of the current TodoList with a deep copy
of other TodoList
*/
TodoList& TodoList::operator=(const TodoList& other){
    if(this != &other){
        while(head != nullptr){
            Node* temp = head; 
            head = head->next;
            delete temp;
        }

        Node* other_node = other.head;
        Node* current = nullptr;

        while(other_node != nullptr){
            Node* new_node = 
            new Node(other_node->name, other_node->text, other_node->check);

            if(head == nullptr){
            head = new_node;
            current = head;
            } else{
            current->next = new_node;
            current = new_node;
            }
            other_node = other_node->next;
        }
    }
    return *this;
}

/* Destructor
Precondition: None
Postcondition: Frees all memory allocated for TodoList and saved_list
*/
TodoList::~TodoList(){
//Iterates and frees the memory of the linked list
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
//Frees the memory of the saved_list
    delete saved_list;
}

/*Add method that addds tasks to TodoList
Precondition: Takes two string parameters
Postcondition: Adds a Node to the TodoList
*/
void TodoList::add(const string& name, const string& text) {
    Node* new_node = new Node(name, text, false);

    if(head == nullptr || name < head->name){
//Adding at the beginning of the list
        new_node->next = head;
        head = new_node;
        return;
    } else if(name == head->name){
//Updates the text if the task has the same name
        head->text = text;
        delete new_node;
        return;
    }
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr && name.compare(current->name) > 0){
        previous = current;
        current = current->next;
    }

    previous->next = new_node;
    new_node->next = current;
}

/*Remove method that removes tasks from TodoList
Precondition: Takes string parameters
Postcondition: Removes the specific task from TodoList
*/
void TodoList::remove(const string& name){
    Node* current = head;
    Node* previous = nullptr;

    while(current != nullptr && current->name != name){
        previous = current;
        current = current->next;
    }

    if(current != nullptr){
        if(previous == nullptr){
//Removes first node
            head = current->next;
        } else{
//Removes a node from the middle or end of the list
            previous->next = current->next;
        }
        delete current;
    }
}

/*Check a task by name
Precondition: Takes a string parameterm (name)
Postcondition: Checks the specific task with an X
*/
void TodoList::check(const string& name){
    Node* current = head;
//Iterating through linked list
    while(current != nullptr){
        if(current->name == name){
            current->check = true;
        }
        current = current->next;
    }
}

/*Unchecks a task by name
Precondition: Takes a string parameterm (name)
Postcondition: Unchecks the specific task and leaves blank
*/
void TodoList::uncheck(const string& name){
    Node* current = head;
//Iterating through linked list
    while(current != nullptr){
        if(current->name == name){
            current->check = false;
        }
        current = current->next;
    }
}

/*Save the current state of the TodoList
// Precondition: None
Postcondition: Creates a deep copy of the current TodoList 
and assigns it to the saved_list
*/
void TodoList::save(){
    delete saved_list;
    saved_list = new TodoList(*this);
}

/*Loads the saved state of the TodoList
// Precondition: None
Postcondition: Replaces current TodoList content with deep copy of
a previously saved version of saved_list
*/
void TodoList::load(){
    if(saved_list != nullptr){
        while(head != nullptr){
            Node* temp = head;
            head = head->next; 
            delete temp;
        }
//Copies the saved_list to the current TodoList
    *this = *saved_list;
    }
}

/*Get the pointer to the head of the linked list
Precondition: None
Postcondition: Returns the pointer to the head of the linked list
*/
Node* TodoList::get_head() const{
    return head;
}