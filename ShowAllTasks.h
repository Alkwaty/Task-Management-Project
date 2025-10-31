#pragma once
#include <vector>
#include "Task.h"
#include <iostream>

class ShowAllTasks {
public:
    void show(const vector<Task>& tasks) {
        cout << "========================\n";
        cout << "All Tasks\n";
        cout << "========================\n";
        if (tasks.empty()) {
            cout << "No tasks available.\n";
        }
        else {
            cout << "| ID | Name | Due Date | Description | Status |\n";
            for (const auto& task : tasks) {
                cout << "| " << task.getId()
                    << " | " << task.getName()
                    << " | " << task.getDueDate()
                    << " | " << task.getDescription()
                    << " | " << (task.isCompleted() ? "Completed" : "Pending")
                    << " |\n";
            }
        }

        cin.ignore();
        cin.get();
    }
};