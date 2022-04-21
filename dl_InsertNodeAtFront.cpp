#include <iostream> 
struct doublyLinkedList
{
	struct doublyLinkedList* prev;
	int data;
	struct doublyLinkedList* next;
};

class DLinkedList
{
public:
	DLinkedList():head(nullptr){}
	void insertNodeFront(int value)
	{
		//Create new node with given value
		doublyLinkedList* new_node = new doublyLinkedList;
		if (new_node != nullptr)
		{
			new_node->prev = nullptr;
			new_node->data = value;
			new_node->next = nullptr;
		}

		//If list is empty
		if (head == nullptr)
		{
			head = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
	}

	void display()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}

		doublyLinkedList* copy_of_head = head;
		while (copy_of_head != nullptr)
		{
			std::cout << copy_of_head->data << "->";
			copy_of_head = copy_of_head->next;
		}
		std::cout << std::endl;
	}
private:
	doublyLinkedList* head;
};

int main() 
{
	DLinkedList dll;
	dll.insertNodeFront(10);
	dll.insertNodeFront(30);
	dll.insertNodeFront(5);
	dll.insertNodeFront(6);
	dll.display();
	return 0;
}