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

    bool checkIfLinkedListIsPalindrome() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return false;
        }
       
        SinglyLinkedList* copy_of_head = head;
        std::stack<char> myStack{};
        while (copy_of_head != nullptr)
        {
            myStack.push(copy_of_head->data);
            copy_of_head = copy_of_head->next;
        }
        
        //Restore the head pointer for comparing data with stack
        copy_of_head = head;
        while (copy_of_head != nullptr)
        {
            if (copy_of_head->data != myStack.top())
            {
                return false;
            }
            //move to next node and next element in stack
            myStack.pop();
            copy_of_head = copy_of_head->next;
        }
        return true;
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
    
    if (linkedList->checkIfLinkedListIsPalindrome())
    {
        std::cout << "Linked List is Palindrome" << std::endl;
    }
    else
    {
        std::cout << "Linked List is not palindrome" << std::endl;
    }
    return 0;
}