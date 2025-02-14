#include <iostream>
#include <string>
using namespace std;

//Defining structure for node in linked list
struct Node {
    string name; //Task command
    string text; //Description for the task
    bool check; //Indicated whether the task is checked or not
    Node* next; //Pointer to the next node in the linked list

//Constructor to initialize node
    Node(const string& n, const string& t, bool c)
    : name(n), text(t), check(c), next(nullptr) {}
};

//Declaration of TodoList class
class TodoList {
private:
//Pointer to head of linked list
    Node* head;
//Pointer to a saved version of the TodoList
    TodoList* saved_list;

public:
//Default Constructor
    TodoList();
// Copy constructor
    TodoList(const TodoList& other);
// Copy assignment operator
    TodoList& operator=(const TodoList& other);
// Destructor
    ~TodoList();

// Adds a new task to the TodoList
    void add(const string& name, const string& text);
// Removes a task from the TodoList
    void remove(const string& name);
// Checks a task
    void check(const string& name);
// Unchecks a task
    void uncheck(const string& name);
// Saves the current state of the TodoList
    void save();
// Loads a saved state of the TodoList
    void load();
    
// Get the pointer to the head of the linked list
    Node* get_head() const;
};