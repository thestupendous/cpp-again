#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoubleEndedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleEndedList() : head(nullptr), tail(nullptr) {}

    // Insert at the front
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete from the front
    void deleteFront() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete from the end
    void deleteEnd() {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Search for a value
    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Display the list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    DoubleEndedList list;
    list.insertFront(10);
    list.insertEnd(20);
    list.insertFront(5);
    list.display();         // Output: 5 10 20
    list.deleteEnd();
    list.display();         // Output: 5 10
    cout << "Found 10? " << (list.search(10) ? "Yes" : "No") << endl;

    return 0;
}
