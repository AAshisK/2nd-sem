
#include "pch.h"
#include <iostream>
using namespace std;


// first we create nodes but here we call them as  " links "	
class link {
public:				//make it public or it will show errors
	//back pointer or pre pointer
	link * pre = NULL;
	// then we insert data = integers
	int data;
	//now the next pointer or the forward pointer
	link * next = NULL;
	// in the start both point to the null or the ABYSS XD	

};

// now we create the linked list	
class linkedlist {
public :			// always make it public
	//making the head
	link * head = NULL;
	// making the tail as it becomes usefull later
	link * tail = NULL;


	//inserting links at the end of the linked list
	void insert(int value) {
		link * temp = new link;
		temp->data = value;
		 //now we establish the head and the tail when the first link is created
		if (head == NULL) {
			head = temp;
			tail = temp;		//both point to the same link as there is only one link
		
		}
	}

	//now we insert the link at a specified position
	void insertat(int value, int position) {
		link * current = head;

		for (int = 1, i < position - 1; i++) {
			if (current == NULL) {
				cout << "this linked list does not have that many links" << endl;
				return;	
			}
			else {
				current = current->next;
			}
		}
		link * temp = new link; 
		temp->data = value; 
		if (current == head) {
			temp->next = head;
			head = temp;
		}
		else {
			temp->next = current->next;
			temp->pre = current;
			if (current->next != NULL)	current->next->pre = temp;
			current->next = temp;
		}
	}

	// deleting the last link
	void del() {
		link * temporary = tail;
		tail = temporary->pre;
		tail->next = NULL;
		delete temporary;
	}

	// Delete at position pos
	void delAt(int position) {
		link * current = head;
		for (int i = 1; i < position - 1; i++) {
			if (current == NULL) {
				cout << "The linked-list does not have that many elements\n";
				return;
			}
			else {
				current = current->next;
			}
		}
		link * temporary;
		if (current == head and position == 1) {
			temporary = head;
			if (temporary->next == NULL) {
				head = NULL;
			}
			else {
				head = temporary->next;
				temporary->next->pre = NULL;
			}
		}
		else {
			temporary = current->next;
			current->next = temporary->next;
			if (temporary->next != NULL)	temporary->next->pre = current;
		}
		delete temporary;
	}
	// count number of Link
	int count() {
		link * current = head;
		if (head == NULL) {
			return 0;
		}
		else {
			int count = 1;
			while (current->next != NULL) {
				current = current->next;
				count++;
			}
			return count;
		}

	}

	// Display
	void display() {
		link * current = head;
		while (current != NULL) {
			cout << current->data;

			//the arrows are just a fancy way to show the output it has no use whatsoever
			if (current->next != NULL)	cout << " <-> ";
			else						cout << " -> ";

			current = current->next;
		}

		cout << "End\n";
	}


};




int main()
{
	linkedlist L1;
	L1.insert(10);
	L1.insert(11);
	L1.insert(12);
	L1.insert(14);
	L1.insert(15);
	L1.insert(16);
	L1.display();
	L1.insertat(4, 13);
	L1.display();
	L1.del();
	L1.display();
	L1.delAt(4);
	L1.display();
	L1.count();


		return 0;
}




