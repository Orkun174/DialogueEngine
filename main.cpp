#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct Option {
    int nextNodeId;
    string text;
};

struct DialogueNode {
    int id;
    string text;
    vector<Option> options;
};

// Reads the story text file and builds the dialogue map
map<int, DialogueNode> loadStory(const string& filename) {
    map<int, DialogueNode> storyMap;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return storyMap;
    }

    string line;
    DialogueNode currentNode;
    bool insideNode = false;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line.find("NODE:") == 0) {
            currentNode = DialogueNode();
            currentNode.id = stoi(line.substr(5));
            insideNode = true;
        }
        else if (line.find("TEXT:") == 0 && insideNode) {
            currentNode.text = line.substr(5);
            if (!currentNode.text.empty() && currentNode.text[0] == ' ') {
                currentNode.text = currentNode.text.substr(1);
            }
        }
        else if (line.find("OPTION:") == 0 && insideNode) {
            string content = line.substr(7);
            size_t pipePos = content.find('|');
            
            if (pipePos != string::npos) {
                Option opt;
                opt.nextNodeId = stoi(content.substr(0, pipePos));
                opt.text = content.substr(pipePos + 1);

                if (!opt.text.empty() && opt.text[0] == ' ') {
                    opt.text = opt.text.substr(1);
                }

                currentNode.options.push_back(opt);
            }
        }
        else if (line.find("END") == 0 && insideNode) {
            storyMap[currentNode.id] = currentNode;
            insideNode = false;
        }
    }

    file.close();
    return storyMap;
}

int main() {
    map<int, DialogueNode> story = loadStory("story.txt");

    if (story.empty()) {
        cout << "Failed to load story. Exiting game." << endl;
        return 1;
    }

    int currentId = 1;

    while (true) {
        if (story.find(currentId) == story.end()) {
            cout << "\n--- END OF STORY ---" << endl;
            break;
        }

        DialogueNode currentNode = story[currentId];

        cout << "\n========================================\n";
        cout << currentNode.text << "\n";
        cout << "========================================\n";

        if (currentNode.options.empty()) {
            cout << "\n--- GAME OVER ---" << endl;
            break;
        }

        for (size_t i = 0; i < currentNode.options.size(); ++i) {
            cout << i + 1 << ") " << currentNode.options[i].text << "\n";
        }

        cout << "\nYour choice (Enter a number): ";
        int choice;

        // Input error handling
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        if (choice >= 1 && choice <= static_cast<int>(currentNode.options.size())) {
            currentId = currentNode.options[choice - 1].nextNodeId;
        } else {
            cout << "\nInvalid choice! Please enter a valid number.\n";
        }
    }

    return 0;
}