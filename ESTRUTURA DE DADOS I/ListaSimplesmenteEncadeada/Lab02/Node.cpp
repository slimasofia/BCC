#include "Node.h"

Node::Node(int data, Node* next) {
    this->data = data;
    this->next = next;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getData() {
    return this->data;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() {
    return this->next;
};