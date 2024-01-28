#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to create a new node
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        return newNode;
    }

    // Insertion at the beginning of the circular linked list
    void insertAtBeginning(int value) {
        Node* newNode = createNode(value);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Insertion in-between nodes
    void insertInBetween(int value, int position) {
        if (head == nullptr || position <= 0) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = createNode(value);
        Node* temp = head;

        for (int i = 0; i < position - 1; ++i) {
            temp = temp->next;
            if (temp == head)
                break;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insertion at the end of the circular linked list
    void insertAtEnd(int value) {
        if (head == nullptr) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = createNode(value);
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Display the circular linked list
    void displayList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;

    myList.insertAtBeginning(10);
    myList.insertAtBeginning(5);
    myList.insertAtEnd(20);
    myList.insertInBetween(15, 2);

    cout << "Circular Linked List: ";
    myList.displayList();

    return 0;
}
