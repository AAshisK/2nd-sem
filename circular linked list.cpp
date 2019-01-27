
#include "pch.h"
#include <iostream>
using namespace std;



class Node {
public:
	int data;
	
	Node * next;																// this is the pointer to the next node
	Node * prev;
																				// Construct that makes the pointer to NULL
	Node(int value) {
		next = NULL;
		data = value;
	}
};

class CSLL {
public:
	Node * head;
	Node * tail;
	CSLL() {
		head = NULL;
		tail = NULL;
	}
																				// this Inserts  links to the end of the linked list.
	void insert(int value) {

																					//  we first Create a new node
		Node * temp = new Node(value);
																					//  then we check if list is empty so we use the if condition
		if (head == NULL) {
			head = temp;
		}
		else {																	//if the list is not empty then  
			Node * current = head;
			while (current->next != head)
				current = current->next;
			current->next = temp;
		}
		tail = temp;
		temp->next = head;
	}
																				// Displays the linked list.
	void display() {
		Node * current = head;
		if (current == NULL) {
			cout << "No elements " << endl;
			return;
		}
		while (current->next != head) {											//  this while loop is used to Stop at head
			cout << current->data << "->";
			current = current->next;
		}
				cout << current->data;											// now we print the last element
		cout << endl;
	}
	void InsertAt(int value, int pos) {
																				//here we insert at a particular position in the linked list
		Node *current = head;
		int i = 1;
		while (current->next != head) {
			i++;
			current = current->next;
		}
																			//if position entered is greater than total number of elements then it doesnt work and shows an error message
		if (pos > i) {
			cout << "the CSLL doesn't consist sufficient elements" << endl;
		}
		else {
			Node *temp = new Node(value);
																		//if position is first we use the same logic as used for inserting at first
			if (pos == 1) {
				temp->next = head;
				head = temp;
				tail->next = head;
			}
																		//otherwise we use this trick
			else {
				int j = 0;
				while (j < pos - 1) {
					j++;
					current = current->next;
				}
				temp->next = current->next;
				current->next = temp;
			}
		}

	}
	void DeleteAt(int pos) {
																		//deleting at a give position =>refer to class notes of normal linked list
		Node *current = head;
		Node *temp;
		int i = 1;
		while (current->next != head) {
			i++;
			current = current->next;
		}
																		//if position entered is greater than total elements then a error message comes up
		if (pos > i) {
			cout << "the CSLL doesn't consist sufficient elements" << endl;
		}
		else {
																		//if position is at the beginning
			if (pos == 1) {
				temp = head;
				head = head->next;
				tail->next = head;
			}
																		//for rest of the positions wedo this
			else {
				int j = 0;
				while (j < pos - 1) {
					j++;
					current = current->next;
				}
				temp = current->next;
				current->next = temp->next;
			}
		}

		delete temp;
	}
	void Delet() {
																	// this deletes the last element of the linked lsit
		Node *current = head;
		Node *temp;
		while (current->next != tail) {
			current = current->next;
		}
		temp = current->next;
		tail = current;
		current->next = head;
		delete temp;

	}
																		//counting the total number of elements is really easy though
	void CountItems() {
		int i = 1;
		Node *current = head;
		while (current->next != head) {
			i++;
			current = current->next;
		}
		cout << "The number of elements in the CSLL is " << i << endl;
	}
};

int main() {
	CSLL csll1;
	for (int i = 1; i < 11; i++) {
		csll1.insert(i);
	}
	csll1.insert(2);
	csll1.display();
	csll1.CountItems();
	csll1.InsertAt(8, 13);
	csll1.display();
	csll1.Delet();
	csll1.display();
	csll1.DeleteAt(11);
	csll1.display();
}


