#include <iostream>
#include <string>
const int maxTask=100;
class ToDoManager {
    private:
    std::string tasks[maxTask];
    bool completed[maxTask];
    int taskCount;

public:
    ToDoManager(){
        taskCount=0;
    }

    void addTask() {
        if (taskCount < maxTask)
         {
           std::string task;
           std::cout << "\nEnter a task to add: ";
           std::cin.ignore(); // Clears the input buffer
           std::cin>>task;
            tasks[taskCount] = task;
            completed[taskCount] = false;
            ++taskCount;
            std::cout << "\nTask '" << task << "'s is added to list successfully..";
        } else {
            std::cout << "\nCannot add more tasks. Task limit reached.\n";
        }
    }

    void viewTasks() const {
        if (taskCount == 0) {
            std::cout << "\nNo tasks in the To-Do List.\n";
        } else {
            std::cout << "\nTO-DO-LIST:\n";
            std::cout<<"------------\n";
            for (int i = 0; i < taskCount; ++i) {
                std::cout << i + 1 << ") ";
                std::cout << "Description: " << tasks[i] << " -> ";
                std::cout << "Status: " << (completed[i] ? "Completed" : "Pending") << '\n';
            }
        }
    }
    void markTaskCompleted() {
        if (taskCount == 0) {
            std::cout << "\nNo tasks in the To-Do List.\n";
        }
        else{
        int index;
        std::cout << "\nEnter the task index to mark as completed: ";
        std::cin >> index;

        if (index > 0 && index <= taskCount) {
            completed[index - 1] = true;
            std::cout << "\nMarking task as completed: " << tasks[index - 1] << '\n';
            
        } else {
            std::cout << "\nInvalid task index.\n";
        }
    }
}
    void deleteTask() {
        if (taskCount == 0) {
            std::cout << "\nNo tasks in the To-Do List.\n";
        } else  {
        int index;
        std::cout << "\nEnter the task index to delete: ";
        std::cin >> index;

        if (index > 0 && index <= taskCount) {
            std::cout << "\nDeleting task: "<< tasks[index - 1]<< '\n';
            for (int i = index - 1; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
                completed[i]=completed[i+1];
            }
            --taskCount;
            std::cout << "\nTask deleted successfully." << std::endl;
        } else {
            std::cout << "\nInvalid task index.\n";
        }
    }
}
};

int main() {
    ToDoManager todo;
    int choice;

    while (choice !=5) {
       std::cout<<"\n\n************************************************************";
        std::cout<<"\n                    TO-DO LIST MANAGER                       ";
        std::cout<<"\n*************************************************************";
        std::cout <<"\n\nSelect a task to perform..\n";
        std::cout <<"\n1. Add Task";
        std::cout <<"\n2. View Tasks";
        std::cout <<"\n3. Mark task as completed.";
        std::cout <<"\n4. Delete Task";
        std::cout <<"\n5. Exit\n";
        std::cout <<"\nEnter your choice (1-5): ";
        std::cin  >> choice;

        switch (choice) {
            case 1:
                todo.addTask();
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                todo.markTaskCompleted();
                break;

            case 4: {
                todo.deleteTask();
                break;
            }
            case 5:
                std::cout << "\nExiting the To-Do List Manager.\n";
                std::cout<<"Thank you, Good bye!!\n\n";
                break;

            default:
                std::cout << "\nInvalid choice. Please enter a number between 1 and 5.\n";
                break;
        }

    } 

    return 0;
}
