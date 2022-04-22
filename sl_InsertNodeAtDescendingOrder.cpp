#include <iostream> 
struct SinglyLinkedList
{
	int data;
	struct SinglyLinkedList* next;
};

class SLinkedList
{
public:
	SLinkedList():head(nullptr) {}
	void insertNodeFront(int value)
	{
		//Create new node with given value
		SinglyLinkedList* new_node = new SinglyLinkedList;
		if (new_node != nullptr)
		{
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

	void insertNodeAscendingOrder(int value)
	{
		//Create new node with given value
		SinglyLinkedList* new_node = new SinglyLinkedList;
		if (new_node != nullptr)
		{
			new_node->data = value;
			new_node->next = nullptr;
		}

		//If list is empty
		if (head == nullptr)
		{
			head = new_node;
			return;
		}

		//Find the appropriate place to insert the node
		SinglyLinkedList* copy_of_head = head;
		while (copy_of_head->next != nullptr && copy_of_head->next->data > value)
		{
			copy_of_head = copy_of_head->next;
		}

		std::cout << "Loop broke at: " << copy_of_head->data << std::endl;

		//The copy_of_head node next is going to be new_node next
		new_node->next = copy_of_head->next;
		
		//The copy_of_head node next is going to be new_node
		copy_of_head->next = new_node;
	}

	void display()
	{
		if (head == nullptr)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}

		SinglyLinkedList* copy_of_head = head;
		while (copy_of_head != nullptr)
		{
			std::cout << copy_of_head->data << "->";
			copy_of_head = copy_of_head->next;
		}
		std::cout << std::endl;
	}
private:
	SinglyLinkedList* head;
};

int main()
{
	SLinkedList sl;
	sl.insertNodeFront(1);
	sl.insertNodeFront(2);
	sl.insertNodeFront(3);
	sl.insertNodeFront(5);
	sl.display();

	std::cout << "Insert node in sorted list in Ascending order" << std::endl;
	sl.insertNodeAscendingOrder(4);
	sl.display();

	return 0;
}
