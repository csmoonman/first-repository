#include"Linklist.h"
#include<iostream>
#pragma warning (disable :4996)
Linklist::Node* Linklist::Find_node_by_ID(const char* id) const
{
	if (Link_is_empty())
		return NULL;
	
	Node* temp = Head;
	while (temp)
	{
		if (strcmp(temp->ID, id) == 0)
			break;
		else
		{
			temp = temp->next;
		}
	}
	if (!temp)
		std::cout << "Cant find this node !\n";
	return temp;
}

Linklist::Node* Linklist::Find_node_by_name(const std::string n) const
{
	if (Link_is_empty())
		return NULL;

	Node* temp = Head;
	while (temp)
	{
		if (n == temp->name)
			break;
		else
		{
			temp = temp->next;
		}
	}
	if (!temp)
		std::cout << "Cant find this node !\n";

	return temp;
}

Linklist::Linklist()
{
	Head = Rear = NULL;
	node_count = 0;
}

Linklist::~Linklist()
{
	Node* temp ;
	while (Head)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
	}
}

bool Linklist::Link_is_empty() const
{
	return node_count == 0;
}

Linklist::Node* Linklist::Find_Node() const
{
	if (Link_is_empty())
	{
		std::cout << "Empty£¡ \n";
		return NULL;
	}

	int choice;
	Node* des = new Node;
	std::cout << "which way do you want to find by \n";
	std::cout << "#ID      -----1\n";
	std::cout << "#Name    -----2\n";
	std::cout << "Your choice : ";
	(std::cin >> choice).get();

	switch (choice)
	{
	case 1:
	{
		std::cout << "Enter ID you want to find : ";
		char* id = new char[MAX];
		std::cin.get(id, MAX);

		des = Find_node_by_ID(id);
		break;
	}
	case 2:
		{	
			std::string name;
			std::cout << "Enter name you want to find : ";
			std::getline(std::cin, name);
			des = Find_node_by_name(name);
			break;
		}
	default:
		std::cout << "Error input !\n";
		break;
	}

	if (des)
		std::cout << des;
	else
		return NULL;

	return des;
}

bool Linklist::Add_Node_by_tail()
{
	Node* temp = new Node;
	temp->next = NULL;

	char* id = new char[MAX];
	std::string name;
	std::string major;

	std::cout << "Enter ID : ";
	std::cin.get(id, MAX);
	while (std::cin.get() != '\n')
		continue;
	strcpy(temp->ID, id);

	std::cout << "Enter name : ";
	std::getline(std::cin, name);
	temp->name = name;
	
	std::cout << "Enter major : ";
	std::getline(std::cin, major);
	temp->major = major;

	if (Head == NULL)
		Head = temp;
	else
		Rear->next = temp;
	Rear = temp;
	Rear->next = NULL;
	node_count++;
	return true;
}

bool Linklist::Insert_Node()
{
	return true;
}

bool Linklist::Modify_Node()
{
	std::cout << *this;
	if (Link_is_empty())
		return false;

	Node* temp;
	int choice;
	std::cout << "Enter the student number whose info you want to modify : ";
	char* id = new char[MAX];
	std::cin.get(id, MAX);
	while (std::cin.get() != '\n')
		continue;
	temp = Find_node_by_ID(id);

	if (!temp)
		return false;
	else
		std::cout << temp;

	std::cout << "Do you want to modify its name or id \n";
	std::cout << "#ID      -----1\n";
	std::cout << "#Name    -----2\n";
	std::cout << "#Major   -----3\n";
	(std::cin >> choice).get();
	switch (choice)
	{
	case 1:
		delete[]id;
		id = new char[MAX];
		std::cout << "Enter id : ";
		std::cin.get(id, MAX);

		strcpy(temp->ID, id);
		break;
	case 2:
		{
		std::string name;
		std::cout << "Enter Name : ";
		std::getline(std::cin, name);
		temp->name = name;
		break;
		}
	case 3:
	{
		std::string major;
		std::cout << "Enter Major : ";
		std::getline(std::cin, major);
		temp->major = major;
		break;
	}
	default:
		std::cout << "Error input ! \n";
		break;
	}

	delete[] id;
	return true;
}

bool Linklist::Delete_Node()
{
	std::cout << *this;
	if (Link_is_empty())
		return false;

	Node* temp;

	std::cout << "Enter the student number whose info you want to delete : ";

	char* id = new char[MAX];
	std::cin.get(id, MAX);
	while(!std::cin)
		std::cin.get(id, MAX);
	temp = Find_node_by_ID(id);

	if (!temp)
		return false;
	else
		std::cout << temp;
	
	Node* front = Head;

	if (node_count == 1)
	{
		if (temp == Head)
		{
			delete temp;
			std::cout << "Succeed!\n";
		}
	}
	else
	{
		if (Head == temp)
		{
			Head = Head->next;
		}
		else
		{
			while (front->next != temp)
				front = front->next;
			front->next = temp->next;
		}

		delete temp;
		std::cout << "Succeed!\n";
	}
	node_count--;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Linklist& L)
{
	if (L.Link_is_empty())
	{
		os << "Empty! \n";
		return os;
	}

	Linklist::Node* temp = L.Head;
	while (temp)
	{
		os << temp;
		temp = temp->next;
	}

	return os;
}

std::ostream& operator<<(std::ostream& os, const Linklist::Node* n)
{
	os << n->ID << "  " << n->name << "  " << n->major << std::endl;

	return os;
}



namespace login
{
	std::string user_accout;
	std::string user_password;
	void login_menu();
	bool check_is_legal();
};