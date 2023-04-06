#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;

// define the structure of Node
struct Node {
    int data;
    Node* next;
};

// define the class Stack
class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }  // constructor
    ~Stack();                   // destructor
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    bool isEmpty();
    bool isFull();
    void display();
};

// push operation
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr) {
        cout << "Stack overflow!" << endl;
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// pop operation
int Stack::pop() {
    int x = -1;
    if (top == nullptr) {
        cout << "Stack underflow!" << endl;
    }
    else {
        x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
    }
    return x;
}

// peek operation
int Stack::peek(int index) {
    if (isEmpty()) {
        return -1;
    }
    else {
        Node* p = top;
        for (int i = 0; p != nullptr && i < index - 1; i++) {
            p = p->next;
        }
        if (p != nullptr) {
            return p->data;
        }
        else {
            return -1;
        }
    }
}

// stack top operation
int Stack::stackTop(){
    if (top == nullptr){
        return -1;
    }
    else {
        return top->data;
    }
}

// isEmpty operation
bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

// isFull operation (assuming linked list implementation)
bool Stack::isFull() {
    return false;   // always false for linked list implementation
}

// display operation
void Stack::display() {
    Node* p = top;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// destructor
Stack::~Stack() {
    Node* p = top;
    while (top != nullptr) {
        top = top->next;
        delete p;
        p = top;
    }
}

// main function to test the Stack class
int main() {
    Stack newStack; // Create a stack

    auto start = chrono::high_resolution_clock::now();
    newStack.push(9);
    newStack.push(10);
    newStack.push(85);
    newStack.push(11);
    newStack.push(15);
    newStack.push(23);
    newStack.push(6);
    newStack.push(18);
    newStack.push(20);
    newStack.push(17);
           
    newStack.display();

    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();
    newStack.pop();

    newStack.display(); 

    newStack.push(4);
    newStack.push(30);
    newStack.push(3);
    newStack.push(1);

    newStack.display();

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;

}