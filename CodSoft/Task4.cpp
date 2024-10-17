#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string name;
    bool isCompleted;

    Task(string n) : name(n), isCompleted(false) {}
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
void displayMenu();

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left by cin

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void displayMenu() {
    cout << "\nTask Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

// Function to add a task to the list
void addTask(vector<Task>& tasks) {
    string taskName;
    cout << "Enter the name of the task: ";
    getline(cin, taskName);
    tasks.emplace_back(taskName);
    cout << "Task added successfully.\n";
}

// Function to view all tasks with their status
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTask List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task marked as completed.\n";
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!\n";
    } else {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully.\n";
    }
}
