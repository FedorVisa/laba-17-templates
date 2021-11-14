#ifndef templist
#define templist
#include <stdexcept>
#include <iostream>

struct point
{
	int x;
	int y;
	int z;

	bool operator==(const point obj) const
	{
		if (x == obj.x && y == obj.y && z == obj.z)
			return true;
		return false;

	}
};

std::ostream& operator<<(std::ostream& out, const point obj)
{
	std::cout << "(" << obj.x << " " << obj.y << " " << obj.z << ")";
	return out;
}


template <typename T>
class Linked_list
{

private:

	template <class T >
	class Node
	{
	public:
		Node(const T& d = T(), Node* n = NULL) : data(d), next(n) {}
		~Node() {}
		T data;
		Node<T>* next;

	};
	Node<T>* head;
	int size = 0;

public:
	Linked_list()
	{
		size = 0;
		head = NULL;
	}

	Linked_list(const Linked_list& a) {
		size = a.size;
		head = new Node<T>(a.head->data);
		Node<T>* n = a.head;
		Node<T>* cur = head;
		while (n != NULL)
		{
			if (n == a.head)
			{
				cur->data = n->data;
				n = n->next;
				continue;
			}
			cur->next = new Node<T>(n->data);

			cur = cur->next;
			n = n->next;
		}
		cur->next = NULL;
	}

	T& operator = (Linked_list& other) {
		if (&other == this)
			return *this;
		Node<T>* tmp = head;
		delete tmp;
		head = NULL;
		size = 0;
		Node<T>* cur = other.head;
		while (cur != NULL)
		{
			Push_back(cur->data);
			cur = cur->next;
		}
		return *this;
	}

	void Push_back(T& data) {
		if (head == NULL)
		{
			head = new Node<T>(data);
			head->next = NULL;
		}
		else
		{
			Node<T>* cur = this->head;
			while (cur->next != NULL) {
				cur = cur->next;
			}
			cur->next = new Node<T>(data);
			cur->next->next = NULL;
		}
		size++;
	}

	void Push_front(T& data) {
		if (head == NULL)
		{
			head = new Node<T>(data);
			head->next = NULL;
		}
		else
		{
			Node<T>* cur = new Node<T>(data);
			cur->next = head;
			head = cur;
		}
		size++;
	}

	~Linked_list() {
		while (size) {
			pop_front();
		}
	}

	void pop_front() {
		Node<T>* tmp = head;

		if (head == NULL)
		{
			delete head;
		}
		else {
			head = head->next;
			delete tmp;
		}
		size--;
	}

	int Get_size() {
		return size;
	}

	void print() {
		Node<T>* cur = head;
		for (int i = 0; cur != NULL; i++) {
			std::cout << cur->data << std::endl;
			cur = cur->next;
		}
	}

	T& get(int index, bool& err) {
		if (index >= 0 && index <= size - 1) {
			Node<T>* cur = head;
			if (index == 0) {
				return head->data;
			}
			for (int i = 0; i < index; i++) {
				cur = cur->next;
			}
			return cur->data;
		}
		else
			err = false;
		return -1;
	}

	void insert(T& data, int index) {
		if ((index < size) && (index >= 0))
		{
			Node<T>* n = new Node<T>(data);
			Node<T>* cur = head;
			if (index == 0)
			{
				n->next = cur;
				head = n;
			}
			else
			{
				for (int i = 0; i < index - 1; i++)
					cur = cur->next;
				Node<T>* tmp = cur->next;
				cur->next = n;
				n->next = tmp;
			}
			size++;
		}
	}

	void erase(int index) {
		if ((index < size) && (index >= 0))
		{
			Node<T>* cur = head;
			if (index == 0)

			{
				Node<T>* tmp = cur;
				head = cur->next;
				delete tmp;
			}
			else
			{
				for (int i = 0; i < index - 1; i++)
					cur = cur->next;
				Node<T>* tmp = cur->next;
				cur->next =
					tmp->next;
				delete tmp;

			}
		}
		size--;
	}

	void find(T& key, Node<T>* cur, int index) {
		if (cur == NULL)
			std::cout << "nothing to delete" << "\n";
		else if (cur->data == key)
			erase(index);
		else
			find(key, cur->next, index + 1);
	}

	void find_and_erase(T& key) {
		int index = 0;
		Node<T>* cur = head;
		find(key, cur, index);
	}



	int at(int n) {
		if ((n >= 0) && (n < Get_size())) return 1;
		throw std::exception("out of range");

	}
};
#endif