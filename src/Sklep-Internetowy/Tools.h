#ifndef TOOLS_H
#define TOOLS_H
#pragma once

#include<fstream>
#include<vector>
#include<string>

using namespace std;
#include<iostream>
#include<vector>

string selectWord(int n, string str);
vector<string> getLines(string path);
vector<string> textToVector(string, char);
string search(ifstream& file, int index, string value);

#endif // !TOOLS_H