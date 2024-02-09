#ifndef SAFE_H
#define SAFE_H
#pragma once

template <typename T>
class Safe {
private:
    vector<T> data;

public:



    void add(T object) {
        this->data.push_back(object);
    }

    void remove() {
        if (!isEmpty()) {
            this->data.pop_back();
        }
        else {
            cout << "Nie ma danych" << std::endl;
        }
    }

    T show() {
        return this->data.back();
    }

    void showAll() {
        for (const T& obj : data) cout << obj << " "; cout << endl;
    }

    bool isEmpty() const {
        return this->data.empty();
    }

    ~Safe() {
        this->data.clear();
    }

    vector<T> get_vector() {
        return data;
    }

};

#endif // !SAFE_H