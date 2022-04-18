#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct SinglyLinkedList
{
    char data;
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

    void deleteLinkedList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
       
        SinglyLinkedList* copy_of_head = head;
        while (copy_of_head != nullptr)
        {
            //Keep copy of node into some temporary memory
            SinglyLinkedList *temp = copy_of_head->next;
            delete copy_of_head;
            copy_of_head = temp;
        }        
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
        linkedList->InsertElementAtFront('G');
        linkedList->InsertElementAtFront('A');
        linkedList->InsertElementAtFront('D');
        linkedList->InsertElementAtFront('A');
        linkedList->InsertElementAtFront('G');
    }
    linkedList->display();
    
    //Delete linked list
    linkedList->deleteLinkedList();
    return 0;
}