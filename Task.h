#pragma once
#include <string>
#include <sstream>
using namespace std;
class Task {
private:
    int id;
    string name;
    string dueDate;
    string description;
    bool completed;
public:
    Task() : id(0), name(""), dueDate(""), description(""), completed(false) {}

    Task(int _id, string _name, string _Date, string _description, bool _completed = false)
        : id(_id), name(_name), dueDate(_Date), description(_description), completed(_completed) {}

    //لإستدعاء البيانات
    int getId() const { return id; }
    string getName() const { return name; }
    string getDueDate() const { return dueDate; }
    string getDescription() const { return description; }
    bool isCompleted() const { return completed; }

    //لوضع البيانات
    void setName(const string& _name) { name = _name; }
    void setDueDate(const string& _Date) { dueDate = _Date; }
    void setDescription(const string& _description) { description = _description; }
    void setCompleted(bool _completed) { completed = _completed; }

    //إرجاع البيانات للملفات
    string toFileString() const {
        return to_string(id) + "|" + name + "|" + dueDate + "|" + description + "|" + (completed ? "1" : "0");
    }
    // ارجاع البيانات لملف الفايلات
    void fromFileString(const string& line) {
        stringstream ss(line);
        string part;
        getline(ss, part, '|'); id = stoi(part);
        getline(ss, name, '|');
        getline(ss, dueDate, '|');
        getline(ss, description, '|');
        getline(ss, part, '|'); completed = (part == "1");
    }
};