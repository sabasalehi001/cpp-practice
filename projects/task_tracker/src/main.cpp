#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const string TASK_FILE = "tasks.txt";

struct Task {
    int id;
    string description;
    bool done;
};

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file(TASK_FILE);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Task task;
        ss >> task.id >> task.done;
        getline(ss >> ws, task.description);
        tasks.push_back(task);
    }
    file.close();
    return tasks;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file(TASK_FILE);
    for (const auto& task : tasks) {
        file << task.id << " " << task.done << " " << task.description << endl;
    }
    file.close();
}

void addTask(vector<Task>& tasks, const string& description) {
    int nextId = 1;
    if (!tasks.empty()) {
        nextId = tasks.back().id + 1;
    }
    tasks.push_back({nextId, description, false});
    saveTasks(tasks);
    cout << "Added task: " << description << endl;
}

void listTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks yet!" << endl;
        return;
    }
    for (const auto& task : tasks) {
        cout << task.id << ". " << (task.done ? "[x]" : "[ ]") << " " << task.description << endl;
    }
}

void markDone(vector<Task>& tasks, int id) {
    auto it = find_if(tasks.begin(), tasks.end(), [id](const Task& task) { return task.id == id; });
    if (it != tasks.end()) {
        it->done = true;
        saveTasks(tasks);
        cout << "Marked task " << id << " as done." << endl;
    } else {
        cout << "Task with id " << id << " not found." << endl;
    }
}

int main(int argc, char* argv[]) {
    vector<Task> tasks = loadTasks();

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [add <task> | list | done <id>]" << endl;
        return 1;
    }

    string command = argv[1];

    if (command == "add") {
        if (argc > 2) {
            string description;
            for (int i = 2; i < argc; ++i) {
                description += argv[i];
                if (i < argc - 1) {
                    description += " ";
                }
            }
            addTask(tasks, description);
        } else {
            cout << "Usage: " << argv[0] << " add <task>" << endl;
            return 1;
        }
    } else if (command == "list") {
        listTasks(tasks);
    } else if (command == "done") {
        if (argc > 2) {
            try {
                int id = stoi(argv[2]);
                markDone(tasks, id);
            } catch (const invalid_argument& e) {
                cout << "Invalid task id." << endl;
                return 1;
            }
        } else {
            cout << "Usage: " << argv[0] << " done <id>" << endl;
            return 1;
        }
    } else {
        cout << "Invalid command." << endl;
        cout << "Usage: " << argv[0] << " [add <task> | list | done <id>]" << endl;
        return 1;
    }

    return 0;
}
