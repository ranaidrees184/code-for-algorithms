#include<iostream>
using namespace std;

struct Node {
	int Data;
	Node* next;
};

Node* head = NULL;
void read_data(Node* node)
{
	cout << "\nEnter The Roll NO:  ";
	cin >> node->Data;
}

void display(Node* node)
{
	cout << "Data of the  Node is " << node->Data << "\n";
}

//Function to insert Node at Head of linked List
void insert_at_head(Node* newNode)
{

	if (head == NULL)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else {
		Node* firstNode = head;
		head = newNode;
		newNode->next = firstNode;
	}
}

//Function to Display Complete Linked List 
void display_list(Node*& Head)
{
	Node* current = Head;
	cout << "\nThe data of Node's in  Linked List is Below" << endl;
	while (current != NULL)
	{
		display(current);
		current = current->next;
	}

}


//Function to add node at the end of Linked List
void addNode_atEnd(Node* node1)
{
	Node* current = head;
	if (head == NULL)
	{
		node1 = new Node();
	}
	else {
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node1;
	}
}

//New node before node of data

void insertnewnodebefore(Node* before, Node* NewNode){

	Node* temp=before->next;
	before->next = NewNode;
	NewNode->next = temp;

}
void insertnewnodeafter(Node* current, Node* NewNode) {

	Node* temp = current->next;
	current->next = NewNode;
	NewNode->next = temp;

}


Node* search_nodebyData(int rollno)
{
	Node* previous = new Node();
	Node* temp = head;
	while (temp->Data != rollno)
	{
		previous = temp;
		temp = temp->next;
	}

	return temp;
}

Node* searchPreviousnodebyData(int rollno)
{
	Node* previous = new Node();
	Node* temp = head;
	while (temp->Data != rollno)
	{
		previous = temp;
		temp = temp->next;
	}

	return previous;
}

Node* lastNode(Node* Node1)
{
	Node* current = Node1;
	do {
		current = current->next;

	} while (current->next != NULL);

	return(current);
}

//To delete Node
void deleteNode(Node* todelete, Node* previous)
{
	previous->next = todelete->next;
	delete todelete;
}

//to delete Head from List

void todeleteHead()
{
	Node* Nodetodel = head;
	head = Nodetodel->next;
	delete Nodetodel;
}

// to delete from end;
void deleteEndnode(Node* lasttodel, Node* previous)
{
	previous->next = NULL;
	delete lasttodel;
}

//Delete Complete list
void deletelist()
{
	Node* current = head;
	while (current != NULL)
	{
		cout << "Complete list is deleted"<<endl<<endl;
		delete current;
		current = current->next;
	}
}
int main()
{
	Node* node1 = new Node();
	node1->Data = 220962;
	head = node1;
	Node* node2 = new Node();
	node2->Data = 220960;
	Node* node3 = new Node();
	node3->Data = 220955;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	int choice, subchoice;
	int delnum;
	Node* lasttodelete;
	do
	{
		cout << "Press 1 to Insert Node" << endl;
		cout << "press 2 to Search Node " << endl;
		cout << "Press 3 to display List " << endl;
		cout << "press 4 to Delete Node" << endl;
		cout << "Press 5 to Exit " << endl;
		cout << "Enter Your Choice" << endl;
		cin >> choice;
		system("CLS");
		switch (choice)
		{

		case 1:
		{
			cout << "Press 6 to add node at head of Linked lIst " << endl;
			cout << "press 7 to add node at end of the linked lIst " << endl;
			cout << "Press 8 to add Node before existing node" << endl;
			cout << "Press 9 to add node after existing Node" << endl;
			cout << "enter Your Choice";
			cin >> subchoice;
			switch (subchoice)
			{
			case 6:
			{
				Node* newhead = new Node();
				read_data(newhead);
				insert_at_head(newhead);
				break;
			}
			case 7:
			{
				Node* newEndNode = new Node();
				read_data(newEndNode);
				addNode_atEnd(newEndNode);
				break;
			}
			case 8:
			{
				//Insert before Node
				int rollno;
				cout << "Enter Roll no of node before which you want  to enter new node" << endl;
				cin >> rollno;
				Node* beforeNode = searchPreviousnodebyData(rollno);
				Node* newbefNode = new Node();
				read_data(newbefNode);
				insertnewnodebefore(beforeNode, newbefNode);
				break;
			}
			case 9:
			{
				int rollno;
				cout << "Enter Roll no of node before which you want  to enter new node" << endl;
				cin >> rollno;
				Node* temp = search_nodebyData(rollno);
				Node* newaftNode = new Node();
				read_data(newaftNode);
				insertnewnodeafter(temp, newaftNode);
				break;
			}
			default:
			{
				cout << "you enter an invalid number";
				break;
			}

			}
			break;
		}
		case 2:
		{
			cout << "Press 10 to To Get Searched node" << endl;
			cout << "press 11 to to Get Prevoius Node" << endl;
			cout << "Press 12 to To get Last Node " << endl;
			cout << "enter Your Choice";
			cin >> subchoice;
			switch (subchoice)
			{
			case 10:
			{
				int rollno;
				cout << "Enter Roll No to get Data" << endl;
				cin >> rollno;
				Node* temp = search_nodebyData(rollno);
				display(temp);
				break;
			}
			case 11:
			{
				int rollno;
				cout << "Enter Roll No to get Data" << endl;
				cin >> rollno;
				Node* previous = searchPreviousnodebyData(rollno);
				display(previous);
				break;
			}
			case 12:
			{
				Node* displayLast = lastNode(head);
				cout << "\n The Last Node's Data In the lInked List is " << endl;
				display(displayLast);
				break;
			}
			default:
			{
				cout << "you enter an invalid number";
				break;
			}
			}

			break;
		}
		case 3:
		{
			display_list(head);
			break;
		}
		case 4:
		{
			cout << "Press 13 to To delete Node" << endl;
			cout << "press 14 to Delete First Node  " << endl;
			cout << "Press 15 to Delete Last Node" << endl;
			cout << "Press 16 to Delete List" << endl;
			cout << "enter Your Choice";
			cin >> subchoice;
			switch (subchoice)
			{
				case 13:
				{
					cout << "Enter Node data to delete" << endl;
					cin >> delnum;
					Node* todelete = search_nodebyData(delnum);
					Node* previous = searchPreviousnodebyData(delnum);
					deleteNode(todelete, previous);

					break;
				}
				case 14:
				{
					todeleteHead();
					break;
				}
				case 15:
				{
				      lasttodelete   =	lastNode(head);
					  int rollno = lasttodelete->Data;
					  Node* secondLast = searchPreviousnodebyData(rollno);
					  deleteEndnode(lasttodelete, secondLast);
					break;
				}
				case 16:
				{
					deletelist();
					break;
				}
			deafult:
				{
					cout << "enter a valid number" << endl;
					break;
				}
			}
			break;
		}
		case 5:
		{
			exit(1);
			break;
		}
		default:
		{
			cout << "You entered an invalid number" << endl;

		}
		}
	} while (1);
}