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

	//Increasing order node insertion
	void insertNodeInSortedDescending(int data)
	{
		doublyLinkedList* new_node = new doublyLinkedList;
		new_node->data = data;
		new_node->prev = nullptr; //set initially
		new_node->next = nullptr; //set initially

		//If the list is empty, then this node going to be single node in list
		if (head == nullptr)
		{
			head = new_node;
		}

		//Find the appropriate place to insert new node
		doublyLinkedList* copy_of_head = head;
		while (copy_of_head->next != nullptr && copy_of_head->next->data > data)
		{
			copy_of_head = copy_of_head->next;
		}

		std::cout << "Loop broke at node:" << copy_of_head->data << std::endl;
		
		//copy_of_head node next will be now new_node next
		new_node->next = copy_of_head->next;

		// if the new node is not inserted at the end of the list 
		if (copy_of_head->next != nullptr)
		{
			new_node->next->prev = new_node;
		}

		//Adjust the pointers
		copy_of_head->next = new_node;
		new_node->prev = copy_of_head;
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
	dll.insertNodeFront(1);
	dll.insertNodeFront(2);
	dll.insertNodeFront(3);
	dll.insertNodeFront(5);
	dll.display();

	std::cout << "Insert node in sorted linked list: " << std::endl;
	dll.insertNodeInSortedDescending(4);
	dll.display();
	return 0;
}
