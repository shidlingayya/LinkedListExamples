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
    int getMiddleNodeValue()
    {
        SinglyLinkedList* slow_ptr = head;
        SinglyLinkedList* fast_ptr = head;

        if (head != NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
        }
        return slow_ptr->data;
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

    cout << "Middle node in linked list:";
    cout << linkedList->getMiddleNodeValue() << endl;

    return 0;
}