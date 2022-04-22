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
	DLinkedList() :head(nullptr) {}
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

	void insertNodeRear(int value)
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
			doublyLinkedList* copy_of_head = head;
			while (copy_of_head->next != nullptr)
			{
				copy_of_head = copy_of_head->next;
			}

			//Now copy new node to last node pointer
			copy_of_head->next = new_node;
		}
	}

	void deleteFrontNode()
	{
		//If list is empty
		if (head == nullptr)
		{
			std::cout << "Linked List is empty: " << std::endl;
			return;
		}
		
		//Take the copy of head node
		doublyLinkedList* copy_of_head = head;

		//This is going to first node
		doublyLinkedList* next_node = copy_of_head->next;
		next_node->prev = nullptr;
		head = next_node;

		//Delete the first node
		delete copy_of_head;		
	}

	void deleteLastNode()
	{
		//If list is empty
		if (head == nullptr)
		{
			std::cout << "Linked List is empty: " << std::endl;
			return;
		}

		//Traverse till second node from last
		doublyLinkedList* copy_of_head = head;
		while (copy_of_head->next->next != nullptr)
		{
			copy_of_head = copy_of_head->next;
		}

		//Last node is last second -> next
		doublyLinkedList* node_to_deleted = copy_of_head->next;
		copy_of_head->next = nullptr;
		delete node_to_deleted;
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
	std::cout << "Insert node at rear end" << std::endl;
	dll.insertNodeRear(6);
	dll.display();
	std::cout << "delete node at front" << std::endl;
	dll.deleteFrontNode();
	dll.display();
	std::cout << "delete node at Last" << std::endl;
	dll.deleteLastNode();
	dll.display();
	return 0;
}
