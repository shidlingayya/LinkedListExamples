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

    int countNumberOfNodes()
    {
        int counter = 0U;
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return counter;
        }

        SinglyLinkedList* head_node_copy = head;
        while (head_node_copy != nullptr)
        {
            head_node_copy = head_node_copy->next;
            counter++; 
        }
        return counter;
    }

    //Nth Node from linked List end
    int getNthNodeFromLinkedList(int targetNode)
    {
        //Head node itself is nullptr
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return -1;
        }

        auto totalNodes = countNumberOfNodes();
        cout << "Target node: " << targetNode << " Total Nodes: " << totalNodes << endl;

        //If the total number of nodes greater than list
        if (targetNode > totalNodes)
        {
            return -1;
        }

        //Traverse till targetNode reached
        SinglyLinkedList* head_node_copy = head;
        for (auto i = 1; i < targetNode; i++)
        {
            head_node_copy = head_node_copy->next;
        }
        cout << "Target node value: " << head_node_copy->data << endl;

        return head_node_copy->data;
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
    cout << "Nth Node from end of linked List: " << linkedList->getNthNodeFromLinkedList(4) << endl;

    return 0;
}