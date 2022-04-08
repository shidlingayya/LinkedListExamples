#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SinglyLinkedList
{
    int data;
    SinglyLinkedList* next;
};

class SLinkedList
{
public:
    SLinkedList() :head(nullptr) {}
    void InsertElementAtFront(int value) {
        SinglyLinkedList* new_node = new SinglyLinkedList();
        if (new_node) {
            new_node->data = value;
            new_node->next = nullptr;
        }

        //This is going to be first node
        if (head == nullptr) {
            head = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }

    //Display nodes
    void display()
    {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        //Do not modify the head node reference
        SinglyLinkedList* head_node_copy = head;
        while (head_node_copy != nullptr) {
            cout << head_node_copy->data << "->";
            head_node_copy = head_node_copy->next;
        }
        cout << endl;
    }

    //Get middle node
    void deleteLastNode(){
        if (head == nullptr){
            cout << "List is empty" << endl;
            return;
        }

        //Traverse till last second node
        SinglyLinkedList* head_node_copy = head;
        while (head_node_copy->next->next != nullptr){
            head_node_copy = head_node_copy->next; 
        }

        //Last node, THe pointer was stopped at last second node
        SinglyLinkedList* last_second_node = head_node_copy->next; 
        head_node_copy->next = nullptr; //Going to be last node now
        free(last_second_node);
    }

private:
    SinglyLinkedList* head;
    int total_nodes;
};

int main()
{
    SLinkedList* linkedList = new SLinkedList();
    if (linkedList) //Prepare list
    {
        linkedList->InsertElementAtFront(1);
        linkedList->InsertElementAtFront(2);
        linkedList->InsertElementAtFront(3);
        linkedList->InsertElementAtFront(4);
        linkedList->InsertElementAtFront(5);
    }
    linkedList->display();

    cout << "Delete last node:";
    linkedList->deleteLastNode();

    linkedList->display();

    return 0;
}