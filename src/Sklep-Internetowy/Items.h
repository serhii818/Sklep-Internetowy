#pragma once
#ifndef ITEMS_H
#define ITEMS_H
#include<vector>
#include<iostream>

// dont use vectors in Admin, but in main 

// kolejka FIFO - DLA KOLEJNOSCI W SPRZEDAZY ORDEROW

// class ITEMS dla przechowywania np. USERS lista dwukierunkowa

//list


template <typename T>
class ITEMS
{
private:
    vector<T> data;
public:
    ITEMS() : data() {}
    ITEMS(ITEMS& that)
    {
        this->data.assign(that.data.begin(), that.data.end());
    }

    void add(T object)
    {
        this->data.push_back(object);
    }
    void _delete()
    {
        this->data.pop_back();
    }

    void showAll()
    {

    }

    int size()
    {

    }

    void find()
    {

    }

    void insert()
    {

    }

    //void delete()
    //{

    //}

    void clear()
    {

    }

    void traverse()
    {

    }

    void get()
    {

    }

    void isEmpty()
    {

    }
    void isFull()
    {

    }

    ~ITEMS()
    {
        this->data.erase();
    }
};

#endif ITEMS_H;
