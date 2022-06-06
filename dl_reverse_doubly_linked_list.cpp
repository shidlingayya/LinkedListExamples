#include <iostream>
struct doublyLinkedList
{
    int data;
    doublyLinkedList* prev;
    doublyLinkedList* next;
};
class dLinkList
{
public:
    dLinkList():head(nullptr){}

    doublyLinkedList* getNode(int value){
        doublyLinkedList* new_node = new doublyLinkedList;
        if (new_node != nullptr){
            new_node->data = value;
            new_node->next = nullptr;
            new_node->prev = nullptr;
        }
        return new_node;
    }

    void insert_f(int value){
        doublyLinkedList* new_node = getNode(value);
        if (!head){
            head = new_node;
        }
        else{
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void display() 
    {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        else {
            doublyLinkedList* copy_of_node = head;
            while (copy_of_node)
            {
                std::cout << copy_of_node->data << "->";
                copy_of_node = copy_of_node->next;
            }
            std::cout << std::endl;
        }
    }

    void reverse()
    {
        doublyLinkedList* temp = NULL;
        doublyLinkedList* current = head;

        /* swap next and prev for all nodes of
        doubly linked list */
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        /* Before changing the head, check for the cases like empty
            list and list with only one node */
        if (temp != NULL)
        {
            head = temp->prev;
        }
    }

private:
    doublyLinkedList* head;
};


int main()
{
    dLinkList list;
    
    //Insert node at front
    list.insert_f(10);
    list.insert_f(30);
    list.insert_f(50);
    list.insert_f(1);
    list.insert_f(40);
    list.display();

    //Reverse the doubly linked list
    list.reverse();
    list.display();
    return 0;
}