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
    SLinkedList():head(nullptr){}
    void InsertElementAtFront(int value){
        SinglyLinkedList* new_node = new SinglyLinkedList();
        if (new_node){
            new_node->data = value;
            new_node->next = nullptr;
        }

        //This is going to be first node
        if (head == nullptr){
            head = new_node;
        }
        else{
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
        while (head_node_copy != nullptr){
            cout << head_node_copy->data << "->";
            head_node_copy = head_node_copy->next;
        }
        cout << endl;       
    }

    int getTotalNumberOfNodes()
    {
       if (head == nullptr) {
          cout << "List is empty" << endl;
          total_nodes = 0;
       }

       //Do not modify the head node reference
       SinglyLinkedList* head_node_copy = head;
       while (head_node_copy != nullptr) {
            head_node_copy = head_node_copy->next;
            total_nodes++;
       }
       return total_nodes;
    }

    //Get middle node
    int getMiddleNodeValue()
    {
        if (head == nullptr) {
            total_nodes = 0;
        }
        
        int count = getTotalNumberOfNodes();
        int middle_node = round(count / 2);
        cout << "Total number of nodes in list are: " << count << "and middle node will be:" << middle_node << endl;
        SinglyLinkedList* head_node_copy = head;
        while (middle_node != 0)
        {
            middle_node--;
            head_node_copy = head_node_copy->next;
        }
        cout << "Middle node value is: " << head_node_copy->data << endl;
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

    cout << "Middle node in linked list" << endl;
    cout << linkedList->getMiddleNodeValue() << endl;

    return 0;
}