#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Task.h"

class FileManager {
protected:

private:
    string tasksFile;
    string idFile;
public:
    //تعريف الملفات
    FileManager(const string& _tasksFile, const string& _idFile)
        : tasksFile(_tasksFile), idFile(_idFile) {}

    bool saveTasks(const vector<Task>& tasks) {
        ofstream file(tasksFile);
        if (!file.is_open()) return false;
        for (const auto& task : tasks) {
            file << task.toFileString() << endl;
        }
        file.close();
        return true;
    }

    /*
    أخذ البيانات من ملف المهام 
    الرئيسي Tasks وتهيئتها في  
    */
    bool loadTasks(vector<Task>& tasks) {
        ifstream file(tasksFile);
        if (!file.is_open()) return false;
        tasks.clear();
        string line;
        while (getline(file, line)) {
            Task t;
            t.fromFileString(line);
            tasks.push_back(t);
        }
        file.close();
        return true;
    }

    bool saveLastId(int id) {
        ofstream file(idFile);
        if (!file.is_open()) return false;
        file << id << endl;
        file.close();
        return true;
    }

    //في الرئيسية  lastId أخذ قيمه الايدي من الملف ، وإرسالها لمتغير 
    int loadLastId() {
        ifstream file(idFile);
        int id = 0;
        if (file.is_open()) {
            file >> id;
            file.close();
        }
        return id;
    }
};