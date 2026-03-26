#pragma once
class Node {
    private: 
        int data;
        Node* next;
        
    public:
        void setData(int data);
        int getData();

        void setNext(Node* next);
        Node* getNext();

        Node(int data, Node* next);
};
