#include "Tools.h"

string selectWord(int n, string str) {
    size_t end_;
    for (int i = 0; i < n - 1; i++) {
        size_t end_ = str.find(" ");
        str = str.substr(end_ + 1, str.length() + end_);
    }
    end_ = str.find(" ");
    str = str.substr(0, end_);
    return str;
}

vector<string> textToVector(string list, char devider) {
    vector<string> v{};
    return v;
}

vector<string> getLines(string path) {
    ifstream file(path);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}

string search(ifstream& file, int index, string value) {
    string line;
    bool found = false;
    while (getline(file, line)) {
        if (value == selectWord(index, line)) {
            found = true;
            break;
        }
    }
    if (found) {
        return line;
    }
    return "";
}