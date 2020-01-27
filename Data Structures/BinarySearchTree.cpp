#include <iostream>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;

	Node() = default;
	Node(int data)
	{
		this->data = data;

	}
	~Node()
	{
		delete left;
		delete right;
	}
	Node(const Node& rhs)
	{
		this->data = data;
		if (rhs.left)
		{
			left = new Node(*rhs.left);
		}
		if (rhs.right)
		{
			right = new Node(*rhs.right);
		}
		
	}
	Node& operator=(const Node& rhs)
	{
		if (this != &rhs && &rhs != nullptr)
		{
			this->data = rhs.data;
			if (rhs.left)
			{
				left = new Node(*rhs.left);
			}
			if (rhs.right)
			{
				right = new Node(*rhs.right);
			}
		}
		return *this;
	}
};

class BST
{
private:
	Node* root = nullptr;

	bool _exists(Node* current, int data)
	{
		if (current)
		{
			if (current->data == data)
			{
				return true;
			}
			else if (current->data < data)
			{
				return _exists(current->right, data);
			}
			else if (current->data > data)
			{
				return _exists(current->left, data);
			}
		}
		else return false;
	}
	Node* _insert(Node* current, int data)
	{
		if (!current)
		{
			Node* temp = new Node(data);
			return temp;
		}
		else
		{
			if (current->data < data)
			{
				current->right = _insert(current->right, data);
			}
			else if (current->data > data)
			{
				current->left = _insert(current->left, data);
			}
		}
    
		return current;
	}
	Node* _remove(Node* current, int data)
	{
		if (!current)
		{
			return nullptr;
		}
		if (current->data < data)
		{
			current->right = _remove(current->right, data);
		}
		else if (current->data > data)
		{
			current->left = _remove(current->left, data);
		}
		else
		{
			if (!current->left && !current->right)
			{
				free(current);
				return nullptr;
			}
			else if (!current->left)
			{
				Node* temp = current->right;
				free(current);
				return temp;
			}
			else if (!current->right)
			{
				Node* temp = current->left;
				free(current);
				return temp;
			}
			else
			{
				Node* swap = current->right;
				while (swap->left)
				{
					swap = swap->left;
				}
				current->data = swap->data;
				current->right = _remove(current->right, swap->data);
			}
		}
    
		return current;
	}
	void _print(Node* current)
	{
		if (current)
		{
			_print(current->left);
			std::cout << current->data << " ";
			_print(current->right);
		}
	}
public:
	BST() = default;
	BST(Node* root)
	{
		this->root = root;
	}
	~BST()
	{
		delete root;
	}
	BST(const BST& rhs)
	{
		if (rhs.root)
		{
			root = new Node(*rhs.root);
		}
	}
	BST& operator=(const BST& rhs)
	{
		if (this != &rhs && &rhs != nullptr)
		{
			delete root;
			root = new Node(*rhs.root);
		}
		return *this;
	}
	
	bool exists(int data)
	{
		return _exists(root, data);
	}
	void insert(int data)
	{
		if (!exists(data))
		{
			root = _insert(root, data);
		}
		else std::cout << "Element is already present." << std::endl;
	}
	void remove(int data)
	{
		if (exists(data))
		{
			root = _remove(root, data);
		}
		else std::cout << "Element is currently not present." << std::endl;
	}

	void print()
	{
		if (root)
		{
			_print(root);
		}
	}
};
int main()
{
	BST tree;
	for (int i = 0; i < 12; i++)
	{
		tree.insert(i);
	}
	tree.print();
	std::cout << std::endl;
	tree.remove(10);
	tree.print();
}
