#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "Task.h"
#include "Style.h"

using namespace std;


class ShowPendingTasks {
public:
    void show(const vector<Task>& tasks) {
        Style::cls();
        cout << "\033[33m" << endl;
        cout << "\n\n\n--------------------------------------------------------------------------------------------------ALL TASKS----------------------------------------------------------------------------------------------------\n" << endl;
        cout << setw(20) << "ID" << setw(20) << '|' << setw(23) << "Name" << setw(17) << '|' << setw(20) << "Due Date" << setw(20) << '|' << setw(20) << "Description" << setw(20) << '|' << setw(20) << "Status" << setw(20) << endl << '\n';
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        //cout << "| ID | Name | Due Date | Description |\n";
        bool found = false;
        for (const auto& task : tasks) {
            if (!task.isCompleted()) {
                found = true;

                string space = to_string(task.getId());
                int lin = 18 + space.length();
                cout << setw(lin) << task.getId();
                 lin = 23 - space.length();

                 cout << setw(lin) << " | ";

                 space = (task.getName());
                 lin = 18 + space.length();
                 cout << setw(lin) << task.getName();
                 lin = 22 - space.length();

                 cout << setw(lin) << " | ";

                 space = (task.getDueDate());
                 lin = 11 + space.length();
                 cout << setw(lin) << task.getDueDate();
                 lin = 29 - space.length();

                 cout << setw(lin) << " | ";


                     space = (task.getDescription());
                     lin = 8 + space.length();
                     cout << setw(lin) << task.getDescription();
                     lin = 32 - space.length();

                     cout << setw(lin) << " | ";
                    
                     space = (task.isCompleted());
                     lin = 16 + space.length();
                     cout << setw(lin);
                     (task.isCompleted() == 1) ? cout << "Yes" : cout << "No";
                     lin = 32 - space.length();





                    cout << "\n";
            }
        }
        cin.ignore();
        cin.get();

        if (!found) {
            cout << "No pending tasks.\n";
            cin.ignore();
            cin.get();
            cin.get();
        }
        cout << "goodbay";

    }
};