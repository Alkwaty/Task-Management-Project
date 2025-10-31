#include <iostream>
#include <vector>
#include "Task.h"
#include "FileManager.h"
#include "ShowPendingTasks.h"
#include "ShowAllTasks.h"
#include "TaskManager.h"
#include "Style.h"
using namespace std;

int main() {
    cout << "\033[33m" << endl;
    vector<Task> tasks;
    int lastId = 0;

    // اوبجكت من كلاس الملفات
    FileManager fileManager("tasks.txt", "id.txt");

    // tasksتحميل البيانات من الملف ل
    fileManager.loadTasks(tasks);

    // أخذ قيمة الايدي من الملف
    lastId = fileManager.loadLastId();

    ShowPendingTasks pendingViewer;
    ShowAllTasks allViewer;
    TaskManager manager(tasks, fileManager, lastId);

    while (true) {
        Style::cls();
        cout << "=============================\n";
        cout << "Task Manager Main Menu\n";
        cout << "=============================\n";
        cout << "1. Show pending tasks\n";
        cout << "2. Manage tasks\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            pendingViewer.show(tasks);
        } 

        else if (choice == "2") {
            Style::cls();
            cout << "====== Task Management ======\n";
            cout << "1. Add task\n";
            cout << "2. Edit task\n";
            cout << "3. Show all tasks\n";
            cout << "4. Delete task\n";
            cout << "5. Back to main menu\n";
            cout << "Choose option: ";
            string choos;
            cin >> choos;

            if (choos == "1") manager.addTask();
            else if (choos == "2") manager.editTask();
            else if (choos == "3") allViewer.show(tasks);
            else if (choos == "4") manager.deleteTask();
            else if (choos == "5") continue;
            else cout << "Invalid option.\n";
        } 

        else if (choice == "3") {
            cout << "Goodbye. . .\n";
            break;
        } 
        
        else {
            cout << "ERROR...\n";
        }
    }
    return 0;
}

