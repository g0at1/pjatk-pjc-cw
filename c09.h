#ifndef PJC_CLION_C09_H
#define PJC_CLION_C09_H

#include <iostream>
#include <ostream>

//ZADANIE 1
template <typename E>
class MyStack {
public:
    class Node {
        public:
        E data;
        Node* next;
        Node(const E& d): data(d), next(nullptr) {}
    };
private:
    Node* head;
public:
    MyStack(): head(nullptr) {};

    void push(const E& d) {
        Node* newNode = new Node(d);
        newNode->next = head;
        head = newNode;
    }

    E pop() {
        E data = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        return data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    virtual ~MyStack() {
        while (!isEmpty()) {
            pop();
        }
    }

};

//ZADANIE 2
class Resistor {
    double R;

public:
    Resistor();
    Resistor(double r);
    double r() const;
    void r(double r);
    friend std::ostream& operator<<(std::ostream&, const Resistor&);


};


#endif //PJC_CLION_C09_H
