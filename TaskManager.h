#pragma once
#include <vector>
#include "Task.h"
#include "FileManager.h"
#include <iostream>
#include <ctime>

class TaskManager {
private:
    vector<Task>& tasks;
    FileManager& fileManager;
    int& lastId;
public:
    TaskManager(vector<Task>& _tasks, FileManager& _fileManager, int& _lastId)
        : tasks(_tasks), fileManager(_fileManager), lastId(_lastId) {}

    // ----------------------------------------------------- addTask
    void addTask() {
        Style::cls();
        string name, description;
        int days;
        cout << "----------------------\n";
        cout << "Add New Task\n";
        cout << "----------------------\n";
        int newId = lastId + 1;
        cout << "Task ID: " << newId << endl;

        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter days until due: ";
        cin >> days;
        cin.ignore();

        // حسابة التاريخ من اليوم الحالي
        time_t now = time(0);
        tm due_tm;
        localtime_s(&due_tm, &now);
        due_tm.tm_mday += days;
        mktime(&due_tm);
        char buffer[11];
        strftime(buffer, 11, "%Y-%m-%d", &due_tm);
        string dueDate(buffer);

        cout << "Enter description: ";
        getline(cin, description);

        Task t(newId, name, dueDate, description, false);

        //تغيير ع البيانات
        tasks.push_back(t);
        lastId = newId;

        //تغييير ع الملفات
        fileManager.saveTasks(tasks);
        fileManager.saveLastId(lastId);
        cout << "Task added successfully!\n";

        cin.ignore();
        cin.get();
    }

   // ----------------------------------------------------- editTask
    void editTask() {
        int id;
        cout << "Enter task ID to edit: ";
        cin >> id;
        cin.ignore();
        bool found = false;
        for (auto& task : tasks) {
            if (task.getId() == id) {
                found = true;
                string name, description;
                int days;
                cout << "Editing Task [" << id << "]\n";
                cout << "Enter new name: ";
                getline(cin, name);
                cout << "Enter new days until due: ";
                cin >> days;
                cin.ignore();

                // حسابة التاريخ من اليوم الحالي -- بعد التعديل
                time_t now = time(0);
                tm due_tm;
                localtime_s(&due_tm, &now);
                due_tm.tm_mday += days;
                mktime(&due_tm);
                char buffer[11];
                strftime(buffer, 11, "%Y-%m-%d", &due_tm);
                string dueDate(buffer);

                cout << "Enter new description: ";
                getline(cin, description);

                task.setName(name);
                task.setDueDate(dueDate);
                task.setDescription(description);

                cout << "Is task completed? (y/n): ";
                char c;
                cin >> c;
                cin.ignore();
                task.setCompleted(c == 'y' || c == 'Y');

                fileManager.saveTasks(tasks);
                cout << "Task updated successfully!\n";
                break;
            }
        }
        if (!found) cout << "Task not found.\n";

        cin.ignore();
        cin.get();
    }

    // ----------------------------------------------------- deleteTask
    void deleteTask() {
        int id;
        cout << "Enter task ID to delete: ";
        cin >> id;
        cin.ignore();
        bool found = false;
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (it->getId() == id) {
                found = true;
                tasks.erase(it);
                fileManager.saveTasks(tasks);
                cout << "Task deleted successfully!\n";
                break;
            }
        }
        if (!found) cout << "Task not found.\n";

        cin.ignore();
        cin.get();
    }

    void showAllTasks() {
        for (const auto& task : tasks) {

            cout << "ID: " << task.getId()
                << ", Name: " << task.getName()
                << ", Due Date: " << task.getDueDate()
                << ", Description: " << task.getDescription()
                << ", Status: " << (task.isCompleted() ? "Completed" : "Pending")
                << endl;

        }

        cin.ignore();
        cin.get();
    }
};