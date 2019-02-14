#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Stack
{
    public:
    Node* top;//top is a node type pointer to the first element of the stack
    public:
    Stack()//default constructor
    {
        top=NULL;//initializes top to null
    }
    void push(int value)//function to push an elemnt into the stack
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the stack is empty
        top=ptr;//the first element is added
        else
        {
            ptr->next=top;//ptr to pushed at the top of the list
            top=ptr;//the pointer top points to the new node which is the topmost node now
        }
        cout<<value<<" has been pushed into the stack.\n";
    }//end of function to push a value into the stack
    int pop()//function to pop an element into the stack
    {
        int delVal=0;//stores the value that is to be popped from the list
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else 
        {
            Node* temp=top;
            delVal=temp->data;//the value at the topmost node is stored
            top=temp->next;//top is moved to the next element in the stack
            temp->next=NULL;//the first element is removed from the stack
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
    }
    bool isEmpty()//function to check if a stack is empty or not
    {
        if(top==NULL)//if top is null
        return true;//then the stack is empty
        else
        return false;
    }//end of function to check if the stack is empty or not
    int size()//function to count the number of elements in the stack
    {
        int counter=0;//variable to store the number of elements in the stack
        Node* temp=top;//pointer to traverse the list
        while(temp!=NULL)//till the bottom of the stack is reached
        {
            temp=temp->next;//pointer moves forward
            counter++;//number of elements incremented
        }
        return counter;//number of elements returned
    }//end of function to find the size of the stack
    void display()//display function
    {
        Node* temp=top;//pointer to traverse through the stack
        while(temp!=NULL)//while the end of the stack is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }//end of display function
    int topValue()//function to return the value at the top of the stack
    {
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        return top->data;//the first element is returned
    }
};//end of class Stack
int main()
{
    cout<<"Stack Object.";
    Stack stack1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to push an element into the stack.\n";
    cout<<"Enter 2 to pop an element from the stack.\n";
    cout<<"Enter 3 to show the size of the stack.\n";
    cout<<"Enter 4 to display the elements of the stack.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be pushed into the stack.\n";
                    cin>>val;
                    stack1.push(val);
                    break;
            case 2 :val=stack1.pop();
                    cout<<val<<" has been popped from the stack.\n";
                    break;
            case 3 :val=stack1.size();
                    cout<<"The number of elements in the stack is "<<val<<endl;
                    break;
            case 4 :stack1.display();
                    break;
            case 5 :val=stack1.topValue();
                    cout<<val<<" is the value at the top of the stack.\n";
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}


#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Queue
{
    public:
    Node* front;//front is a node type pointer to the first element of the queue
    Node* end;//end is a node type pointer to the last element of the queue
    public:
    Queue()//default constructor
    {
        front=NULL;//initializes front to null
        end=NULL;//initialized end to null
    }
    void enquene(int value)//function to enqueue an element
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the queue is empty
        {
            front=ptr;//the first element is added
            end=ptr;
        }
        else
        {
            end->next=ptr;//ptr to enqueued at the end of the queue
            end=ptr;//the pointer end points to the new node which is the last node now
        }
        cout<<value<<" has been inserted in the Queue.\n";
    }//end of function to dequeue an element
    int dequene()//function to dequeue an element
    {
        int delVal=0;//stores the value that is to be dequeued
        if(isEmpty()==true)//if the queue is empty
        return -9999;
        else 
        {
            Node* temp=front;//temporary pointer to the first element of the queue
            delVal=temp->data;//the value at the first node is stored
            front=front->next;//front is moved to the next element in the queue
            temp->next=NULL;//the first element is removed from the queue
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
    }
    bool isEmpty()//function to check if a queue is empty or not
    {
        if(front==NULL||end==NULL)//if the front and the end of the queue is null
        return true;//the queue is empty
        else
        return false;
    }//end of function to check if a queue is empty or not
    int size()//function to count the number of elements in the queue
    {
        if(isEmpty()==true)
        return 0;
        else
        {
            int counter=1;//variable to store the number of elements in the queue
            Node* temp=front;//pointer to traverse the list
            do//till the end of the queue is reached
            {
                temp=temp->next;//pointer moves forward
                counter++;//number of elements incremented
            }while(temp!=end);
            return counter;//number of elements returned
        }
    }//end of function to count the number of elements of the queue
    void display()//display function
    {
        if(isEmpty()==false)
        {
            Node* temp=front;//pointer to traverse through the queue
            do//while the end of the queue is reached
            {
                cout<<temp->data<<", ";//the data is printed
                temp=temp->next;//the pointer is moved forward
            }while(temp!=end);
            cout<<end->data<<", ";//the last element is printed
            cout<<".\n";
        }
    }//end of display function
    int frontValue()//function to display the value at the front of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return front->data;
    }//end of the function to display the element at the front of the queue
    int endValue()//function to display the value at the end of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return end->data;
    }//end of the function to display the element at the end of the queue
};//end of class Queue
int main()
{
    cout<<"Quene Object.";
    Queue queue1;//object of Queue class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enquene an element.\n";
    cout<<"Enter 2 to dequene an element.\n";
    cout<<"Enter 3 to show the size of the quene.\n";
    cout<<"Enter 4 to display the elements of the quene.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enquene(val);
                    break;
            case 2 :val=queue1.dequene();
                    cout<<val<<" has been dequeued.\n";
                    break;
            case 3 :val=queue1.size();
                    cout<<"The number of elements in the queue is "<<val<<endl;
                    break;
            case 4 :queue1.display();
                    break;
            case 5 :val=queue1.frontValue();
                    cout<<val<<" is the value at the top of the stack.\n";
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}




#include <iostream>
using namespace std;
class StackArr
{
	public:
	int top;//stores index of the top of the stack
	int length;//stores the length of the array
	int a[10];//array declared
	public:
	StackArr()//default constructor
	{
		top=-1;//to initialize top to -1
		length=10;//and length to 10
	}//end of default constructor
	void push(int num)//function to push an element into the stack
	{
		if(top<length)//of array index is not out of bounds
		a[++top]=num;//the value is pushed into the next element
		else
		cout<<"Stack Overflow\n";//else stack overflows
	}//end of function to pish an element into stack
	int pop()//function to pop an element from the stack
	{
		if(top>-1)//if the stack is not empty
		return a[top--];//the element is returned and top is decremented
		else
		cout<<"Stack Underflow\n";//else stack underflows
		return -9999;
	}//end of function to pop an element from the stack
	void display()//function to display the elements of the stack
	{
		for(int i=top;i>-1;i--)
		cout<<a[i]<<", ";//elements printed
	}//end of function to display the elements of the stack
	int size()//function to count the number of elements in the stack
	{
		int counter=0;
		for(int i=top;i>-1;i--)//for loop to
		counter++;//count the number of elements in the stack
		return counter;//and return it
	}//end of function to count the number of elements in the stack
	bool isEmpty()//function to find if a siack is empty or not
	{
		if(top==-1)//if top is not an array index
		return true;//then the stack is empty
		else
		return false;
	}//end of function to find if the stack is empty or not
	int topValue()//function to return the value at the top of the stack
	{
		return a[top];//value returned
	}//end of function to return the value at the top of the stack
};
int main()
{
    cout<<"Stack implemented using an Array.";
    StackArr stack1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to push an element into the stack.\n";
    cout<<"Enter 2 to pop an element from the stack.\n";
    cout<<"Enter 3 to show the size of the stack.\n";
    cout<<"Enter 4 to display the elements of the stack.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be pushed into the stack.\n";
                    cin>>val;
                    stack1.push(val);
                    break;
            case 2 :val=stack1.pop();
		    if(val!=-9999)
                    cout<<val<<" has been popped from the stack.\n";
                    break;
            case 3 :val=stack1.size();
                    cout<<"The number of elements in the stack is "<<val<<endl;
                    break;
            case 4 :stack1.display();
                    break;
            case 5 :val=stack1.topValue();
                    cout<<val<<" is the value at the top of the stack.\n";
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}

		
	



#include <iostream>
using namespace std;
class QueueArr
{
	public:
	int front;
	int rear;
	int length;
	int a[10];
	public:
	QueueArr()
	{
		front=-1;
		rear=-1;
		length=10;
	}
	void enqueue(int num)
	{
		if(rear==-1)
		{
			front++;
			a[++rear]=num;
		}
		else if(rear==length-1)
		cout<<"Queue Overflow\n";
		else
		a[++rear]=num;
	}
	int dequeue()
	{
		if(front==-1)
		return -9999;
		else if(front==rear)
		{
			int b=a[front];
			front=-1;
			rear=-1;
			return b;
		}
		else
		return a[front++];
	}
	void display()
	{
		for(int i=front;i<=rear;i++)
		cout<<a[i]<<", ";
	}
	int size()//function to count the number of elements in the stack
	{
		int counter=0;
		for(int i=front;i<=rear;i++)//for loop to
		counter++;//count the number of elements in the stack
		return counter;//and return it
	}//end of function to count the number of elements in the stack
	bool isEmpty()//function to find if a siack is empty or not
	{
		if(front==-1)//if top is not an array index
		return true;//then the stack is empty
		else
		return false;
	}//end of function to find if the stack is empty or not
	int frontValue()//function to return the value at the top of the stack
	{
		return a[front];//value returned
	}//end of function to return the value at the top of the stack
	int rearValue()//function to return the value at the top of the stack
	{
		return a[rear];//value returned
	}//end of function to return the value at the top of the stack
};
int main()
{
    cout<<"Stack implemented using an Array.";
    QueueArr queue1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enqueue an element.\n";
    cout<<"Enter 2 to dequeue an element.\n";
    cout<<"Enter 3 to show the size of the queue.\n";
    cout<<"Enter 4 to display the elements of the queue.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enqueue(val);
                    break;
            case 2 :val=queue1.dequeue();
		    if(val!=-9999)
                    cout<<val<<" has been dequeued.\n";
		    else
		    cout<<"Queue Underflow.\n";
                    break;
            case 3 :val=queue1.size();
                    cout<<"The number of elements in the queue is "<<val<<endl;
                    break;
            case 4 :queue1.display();
                    break;
            case 5 :val=queue1.frontValue();
                    cout<<val<<" is the value at the front of the queue.\n";
                    break;
	    case 6 :val=queue1.rearValue();
		    cout<<val<<" is the value at the end of the queue.\n";
		    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}	





#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Stack
{
    public:
    Node* top;//top is a node type pointer to the first element of the stack
    public:
    Stack()//default constructor
    {
        top=NULL;//initializes top to null
    }
    void push(int value)//function to push an elemnt into the stack
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the stack is empty
        top=ptr;//the first element is added
        else
        {
            ptr->next=top;//ptr to pushed at the top of the list
            top=ptr;//the pointer top points to the new node which is the topmost node now
        }        
    }//end of function to push a value into the stack
    int pop()//function to pop an element into the stack
    {
        int delVal=0;//stores the value that is to be popped from the list
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else 
        {
            Node* temp=top;
            delVal=temp->data;//the value at the topmost node is stored
            top=top->next;//top is moved to the next element in the stack
            temp->next=NULL;//the first element is removed from the stack
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
    }
    bool isEmpty()//function to check if a stack is empty or not
    {
        if(top==NULL)//if top is null
        return true;//then the stack is empty
        else
        return false;
    }//end of function to check if the stack is empty or not
    int size()//function to count the number of elements in the stack
    {
        int counter=0;//variable to store the number of elements in the stack
        Node* temp=top;//pointer to traverse the list
        while(temp!=NULL)//till the bottom of the stack is reached
        {
            temp=temp->next;//pointer moves forward
            counter++;//number of elements incremented
        }
        return counter;//number of elements returned
    }//end of function to find the size of the stack
    void display()//display function
    {
        Node* temp=top;//pointer to traverse through the stack
        while(temp!=NULL)//while the end of the stack is reached
        {
            cout<<temp->data<<", ";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<".\n";
    }//end of display function
    void displayRev()
    {
        displayRev(top);
    }
    void displayRev(Node* temp)
    {
        if(temp->next==NULL)
        cout<<temp->data<<", ";
        else
        {
            displayRev(temp->next);
            cout<<temp->data<<", ";
        }
    }
    int topValue()//function to return the value at the top of the stack
    {
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        return top->data;//the first element is returned
    }
};//end of class Stack
class QueueFromStack
{
    public:
    Stack s1;
    public:
    void enqueue(int num)
    {
	s1.push(num);
    }
    void dequeue()
    {
	if(s1.size()==0)
        cout<<"Stack Underflow.\n";
	else if(s1.size()==1)
	cout<<s1.pop()<<" has been dequened.\n";
        else
	{
	    int poppedValue=s1.pop();
	    dequeue();
            s1.push(poppedValue);
	}
    }
    void display()
    {
        s1.displayRev();
    }
};
int main()
{
    cout<<"Quene Object.";
    QueueFromStack queue1;//object of Queue class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enquene an element.\n";
    cout<<"Enter 2 to dequene an element.\n";
    cout<<"Enter 3 to display the elements of the quene.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued.\n";
                    cin>>val;
                    queue1.enqueue(val);
		    cout<<val<<" has been enqueued.\n";
                    break;
            case 2 :queue1.dequeue();
                    break;
            case 3 :queue1.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
       





#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Queue
{
    public:
    Node* front;//front is a node type pointer to the first element of the queue
    Node* end;//end is a node type pointer to the last element of the queue
    public:
    Queue()//default constructor
    {
        front=NULL;//initializes front to null
        end=NULL;//initialized end to null
    }
    void enqueue(int value)//function to enqueue an element
    {
        Node* ptr=new Node;//new node created of Node type
        ptr->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the queue is empty
        {
            front=ptr;//the first element is added
            end=ptr;
        }
        else
        {
            end->next=ptr;//ptr to enqueued at the end of the queue
            end=ptr;//the pointer end points to the new node which is the last node now
        }
    }//end of function to dequeue an element
    int dequeue()//function to dequeue an element
    {
        int delVal=0;//stores the value that is to be dequeued
        if(isEmpty()==true)//if the queue is empty
        return -9999;
        else 
        {
            Node* temp=front;//temporary pointer to the first element of the queue
            delVal=temp->data;//the value at the first node is stored
            front=front->next;//front is moved to the next element in the queue
            temp->next=NULL;//the first element is removed from the queue
            delete temp;//and deleted
            return delVal;//the deleted value is returned
        }
        return delVal;//the value deleted is returned
    }
    bool isEmpty()//function to check if a queue is empty or not
    {
        if(front==NULL||end==NULL)//if the front and the end of the queue is null
        return true;//the queue is empty
        else
        return false;
    }//end of function to check if a queue is empty or not
    int size()//function to count the number of elements in the queue
    {
        if(isEmpty()==true)
        return 0;
        else
        {
            int counter=1;//variable to store the number of elements in the queue
            Node* temp=front;//pointer to traverse the list
            do//till the end of the queue is reached
            {
                temp=temp->next;//pointer moves forward
                counter++;//number of elements incremented
            }while(temp!=end);
            return counter;//number of elements returned
        }
    }//end of function to count the number of elements of the queue
    void display()//display function
    {
        if(isEmpty()==false)
        {
            Node* temp=front;//pointer to traverse through the queue
            do//while the end of the queue is reached
            {
                cout<<temp->data<<", ";//the data is printed
                temp=temp->next;//the pointer is moved forward
            }while(temp!=end);
            cout<<end->data<<", ";//the last element is printed
            cout<<".\n";
        }
    }//end of display function
    int frontValue()//function to display the value at the front of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return front->data;
    }//end of the function to display the element at the front of the queue
    int endValue()//function to display the value at the end of the queue
    {
        if(isEmpty()==true)
        return -9999;
        else
        return end->data;
    }//end of the function to display the element at the end of the queue
};//end of class Queue
class StackFromQueue
{
    public:
    Queue q1;
    void push(int num)
    {
	q1.enqueue(num);
	while(q1.frontValue()!=num)
	q1.enqueue(q1.dequeue());
    }
    int pop()
    {
	return q1.dequeue();
    }
    void display()
    {
	q1.display();
    }
};
int main()
{
    cout<<"Stack Object.";
    StackFromQueue stack1;//object of Stack class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to push an element into the stack.\n";
    cout<<"Enter 2 to pop an element from the stack.\n";
    cout<<"Enter 3 to display the elements of the stack.\n";
    cout<<"Enter 0 to exit.\n";
    do
    {
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be pushed into the stack.\n";
                    cin>>val;
                    stack1.push(val);
		    cout<<val<<" has been inserted in the Queue.\n";
                    break;
            case 2 :val=stack1.pop();
		    if(val!=-9999)
                    cout<<val<<" has been popped from the stack.\n";
		    else
                    cout<<"Stack underflow.\n";
                    break;
            case 3 :stack1.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer.\n";
        }
    }while(choice!=0);
    return 0;
}
