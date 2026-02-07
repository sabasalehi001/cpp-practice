#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

const std::string TODO_FILE = "todo.txt";

struct Task {
    std::string description;
    bool done = false;
};

std::vector<Task> load_tasks() {
    std::vector<Task> tasks;
    std::ifstream file(TODO_FILE);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string done_str;
        std::string description;
        if (std::getline(iss, done_str, '|') && std::getline(iss, description)) {
            Task task;
            task.description = description;
            task.done = (done_str == "1");
            tasks.push_back(task);
        }
    }
    return tasks;
}

void save_tasks(const std::vector<Task>& tasks) {
    std::ofstream file(TODO_FILE);
    for (const auto& task : tasks) {
        file << (task.done ? "1" : "0") << "|" << task.description << std::endl;
    }
}

void add_task(std::vector<Task>& tasks, const std::string& description) {
    tasks.push_back({description, false});
    save_tasks(tasks);
    std::cout << "Added task: " << description << std::endl;
}

void list_tasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << (tasks[i].done ? "[x]" : "[ ]") << " " << tasks[i].description << std::endl;
    }
}

void mark_done(std::vector<Task>& tasks, int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].done = true;
        save_tasks(tasks);
        std::cout << "Marked task " << index << " as done.\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main(int argc, char* argv[]) {
    std::vector<Task> tasks = load_tasks();

    if (argc < 2) {
        std::cout << "Usage: ./app add <task> | list | done <index>\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "add") {
        if (argc > 2) {
            std::string description;
            for(int i = 2; i < argc; ++i) {
               description += argv[i];
               if(i < argc - 1) description += " ";
            }
            add_task(tasks, description);
        } else {
            std::cout << "Usage: ./app add <task>\n";
            return 1;
        }
    } else if (command == "list") {
        list_tasks(tasks);
    } else if (command == "done") {
        if (argc > 2) {
            try {
                int index = std::stoi(argv[2]);
                mark_done(tasks, index);
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid index. Please provide a number.\n";
                return 1;
            }
        } else {
            std::cout << "Usage: ./app done <index>\n";
            return 1;
        }
    } else {
        std::cout << "Invalid command. Use add, list, or done.\n";
        return 1;
    }

    return 0;
}
