#include <iostream>
#include <memory>

struct d_linkedList
{
	int data;
	d_linkedList* next;
	d_linkedList* prev;
};

class dLinkedList
{
public:
	dLinkedList():head(nullptr){}
	void insert_node_front(int value)
	{
		d_linkedList* new_node = new d_linkedList();
		if (new_node)
		{
			new_node->data = value;
			new_node->next = nullptr;
			new_node->prev = nullptr;
		}

		//if the list is empty
		if (!head)
		{
			head = new_node;
			return;
		}
		else
		{
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
	}

	void sortedInsert(int data)
	{
		// Complete this function
		  // Do not write the main method. 
		d_linkedList* current = NULL;
		d_linkedList* new_node = new d_linkedList;
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = NULL;

		if (head == NULL)
		{
			head = new_node;
		}
		else if (head->data >= new_node->data)
		{
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
		else
		{
			current = head;
			while (current->next != NULL && current->next->data < new_node->data)
			{
				current = current->next;
			}

			if (current->next != NULL)
			{
				new_node->next = current->next;
				current->next->prev = new_node;
			}
			current->next = new_node;
			new_node->prev = current;
		}
	}

	void display()
	{
		//list is empty
		if (!head)
		{
			return;
		}

		d_linkedList* copy_of_head = head;
		while (copy_of_head != nullptr)
		{
			std::cout << copy_of_head->data << "->";
			copy_of_head = copy_of_head->next;
		}
		std::cout << std::endl;
	}

private:
	d_linkedList* head;
};

int main() 
{
	dLinkedList list;
	list.insert_node_front(4);
	list.insert_node_front(2);
	list.insert_node_front(1);
	list.display();

	//Insert node at appropriated place in sorted list
	list.sortedInsert(3);
	list.display();
	return 0;
}
