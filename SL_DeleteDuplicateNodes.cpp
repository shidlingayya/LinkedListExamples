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

    void deleteDuplicateNodes() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
       
        SinglyLinkedList* copy_of_head = head;
        
        //Until last node hit
        while (copy_of_head->next != nullptr)
        {
            //Detected the duplicate node
            if (copy_of_head->data == copy_of_head->next->data)
            {
                SinglyLinkedList* temp = copy_of_head->next->next;
                delete copy_of_head->next;
                copy_of_head->next = temp;
            }
            else
            {
                copy_of_head = copy_of_head->next;
            }
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
        linkedList->InsertElementAtFront(1);
        linkedList->InsertElementAtFront(2);
        linkedList->InsertElementAtFront(3);
        linkedList->InsertElementAtFront(3);
        linkedList->InsertElementAtFront(5);
    }
    linkedList->display();

    cout << "Delete last node:";
    linkedList->deleteDuplicateNodes();

    linkedList->display();

    return 0;
}