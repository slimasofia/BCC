#pragma once
#include "Node.h"
#include <string>

class List {
    private: 
        Node* head;

    public:
        void insert(int data);
        void print();
        void remove(int data);
        void clear();

        bool isEmpty();        
        int length();

        Node* search(int data);
        Node* getTail();

        friend std::ostream& operator<<(std::ostream& os, List& l);

        List();
};