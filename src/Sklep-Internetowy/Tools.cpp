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