# ToDoList
Overview

This program implements a TodoList Editor, allowing users to manage and modify their to-do lists through a command-line interface. Users can add, remove, check, uncheck, save, and load tasks within the list. The program continuously accepts user commands until the user enters quit.

# Features

Add tasks with a name and description.

Remove tasks from the list.

Check and uncheck tasks to mark them as completed or incomplete.

Save the list to preserve tasks for later use.

Load a saved list to restore previously saved tasks.

Error handling for invalid commands and incorrect arguments.
Usage Instructions

1. Compiling the Program

To compile p4.cpp, use the following command in a terminal:

 g++ p4.cpp list.cpp -o todo

Ensure that list.h and list.cpp are present in the same directory.

2. Running the Program

Execute the compiled program using:

 ./todo


 # Description

add <name> <text> 
Adds a new task with the given name and description.

remove <name>
Removes a task by name.

check <name>
Marks a task as completed.

uncheck <name>
Marks a task as incomplete.

save
Saves the current tasks to a file.

load
Loads previously saved tasks.

quit
Exits the program.

3. Example Usage

add Homework Complete math exercises
check Homework
save
quit

# Implementation Details

The program uses a linked list structure (TodoList class) to store tasks.

The display_TodoList function outputs the current task list after each command.

Tasks are represented as nodes with attributes for task name, description, and check status.

The program handles incorrect input and unrecognized commands gracefully.

Dependencies

C++ Standard Library (iostream, sstream, string)

Custom TodoList class (defined in list.h and list.cpp)
