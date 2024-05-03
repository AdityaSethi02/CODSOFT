#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description)
{
    tasks.push_back({description, false});
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& tasks)
{
    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i+1 << ". " << tasks[i].description << " - ";
        cout << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks, size_t index)
{
    if (index >= 0 && index < tasks.size())
    {
        tasks[index].completed = true;
        cout << "Task marked as completed: " << tasks[index].description << endl;
    }

    else
    {
        cout << "Invalid task index!" << endl;
    }
}

void removeTask(vector<Task>& tasks, size_t index)
{
    if (index >= 0 && index < tasks.size())
    {
        cout << "Task removed: " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    }

    else
    {
        cout << "Invalid task index!" << endl;
    }
}

int main()
{
    vector<Task> tasks;

    while (true)
    {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3:
            {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            }
            case 4:
            {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
