#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

const string TASKS_FILE = "tasks.txt";

struct Task {
    string description;
    bool done;
};

vector<Task> load_tasks() {
    vector<Task> tasks;
    ifstream file(TASKS_FILE);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            size_t pos = line.find(",");
            if (pos != string::npos) {
                string done_str = line.substr(0, pos);
                string description = line.substr(pos + 1);
                bool done = (done_str == "1");
                tasks.push_back({description, done});
            }
        }
        file.close();
    }
    return tasks;
}

void save_tasks(const vector<Task>& tasks) {
    ofstream file(TASKS_FILE);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << (task.done ? "1" : "0") << "," << task.description << endl;
        }
        file.close();
    }
}

void add_task(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
    save_tasks(tasks);
    cout << "Added task: " << description << endl;
}

void list_tasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet!" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].done ? "x" : " ") << "] " << tasks[i].description << endl;
    }
}

void mark_done(vector<Task>& tasks, int task_number) {
    if (task_number > 0 && task_number <= tasks.size()) {
        tasks[task_number - 1].done = true;
        save_tasks(tasks);
        cout << "Marked task " << task_number << " as done." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks = load_tasks();

    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "add") {
            string description;
            getline(ss, description);
            // Remove leading space from description
            if (!description.empty() && description[0] == ' ') {
                description = description.substr(1);
            }
            add_task(tasks, description);
        } else if (action == "list") {
            list_tasks(tasks);
        } else if (action == "done") {
            int task_number;
            ss >> task_number;
            mark_done(tasks, task_number);
        } else if (action == "exit") {
            break;
        } else {
            cout << "Invalid command. Available commands: add, list, done, exit" << endl;
        }
    }

    return 0;
}