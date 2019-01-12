#include "pch.h"
#include <iostream>

using namespace std;

class Node {
	//this circe hsa two things 
	//data
	int data;
	//and pointer to the next Node
	Node * next;
	//and another thing that is required is a constructor that makes the pointer to null
	Node() {
		next = NULL;
	}
};

class linkedlist {
	//head + circles inside in it linked with each other
	public:
	// first and the most importnat thing in this is the head->Node type pointer
	Node * head;
	//then its the tail
	Node * tail;
	//construct
	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	
	//linkedlist itelsf doesnt contain the circles.. it just has the head that points to the 1st circle only.. and the circles are present somewhere else
	//rules how the circles will be linked to each other

	//INSERTION
	void insert(int value) {
		// If 1st Node is added
		Node * temp = new Node;
		//insert value in the node
		temp->data = value;
		// 1st Node only
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		//2nd node only
		else {
			head->next = temp;
			tail = temp;
		}		
	}

	//INSERTION AT A POINT
	void insertAt(int pos, int value) {
		Node * current = head;
		for (int i = 1; i < pos - 1; i++) {
			current = current->next;
		}
	// now we create node
		Node * temp = new Node;
		temp->data = value;
		temp->next = current->next;
		crrent->next = temp;
	}


	//DELETION
	void delete() {
	//store the tail in temp first
		Node * temp = tail;
		// before tail has to point to null
		Node * current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = NULL;
		// update tail
		tail = current;
		// delete temp
		delete temp;
	}
	

	//DELEION AT A POINT
	void deleteAt(int pos) {
		Node * current = head;
		for (int i = 1; i < pos - 1; i++) {
			current = current->next;
		}
		if (current->next!= NULL) {
			Node * deletenode = current->next;
			if (current->next->next!= NULL) {
				Node * temp = current->next->next;
				current->next = temp;
			}
			else {
				current->next = NULL;
			}
			delete deletenode;
		}

		else {
			cout << "Linked List does not have that many elements" << endl;
		}

	}

	//DISPLAY
	void display() {
		Node * current = head;
		int count = 0;
		while (current != NULL) {
			cout << current->data << "->";
			current = current->next;
			count++;
		}
		cout << "NULL" << endl;
		cout << "numbers of nodes in the linked list is " << count << endl;
	}
};

int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insert(1);
	l1.insert(2);
	l1.insert(4);
	l1.insertAt();
	l1.insert(3,3);
	l1.delete();
	l1.deleteAt(5);
	l1.display();
	l1.delRepeat();
	l1.deiplay();
	return 0;
}
