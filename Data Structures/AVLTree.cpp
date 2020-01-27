#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b))
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
struct Node
{
	int data;
	int height = 0;
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

	void calculateheight()
	{
		height = 0;
		if (left)
		{
			height = max(height, left->height + 1);
		}
		if (right)
		{
			height = max(height, right->height + 1);
		}
	}
	void recalculateheights()
	{
		if (left)
		{
			left->calculateheight();
		}
		if (right)
		{
			right->calculateheight();
		}
		this->calculateheight();

	}

	int leftheight()
	{
		if (left)
		{
			return left->height + 1;
		}
		return 0;

	}
	int rightheight()
	{
		if (right)
		{
			return right->height + 1;
		}
		return 0;
	}
	int balance()
	{
		return leftheight() - rightheight();
	}

	void rotateleft()
	{
		if (!right)
		{
			return;
		}

		Node* rightleft = this->right->left;
		Node* oldleft = this->left;
		swap(this->data, this->right->data);
		this->left = this->right;
		this->right = this->right->right;
		this->left->left = oldleft;
		this->left->right = rightleft;
	}
	void rotateright()
	{
		if (!left)
		{
			return;
		}
		
		Node* rightleft = this->right->left;
		Node* oldright = this->right;

		swap(this->data, this->left->data);

		this->right = this->left;
		this->left = this->left->left;
		this->right->right = oldright;
		this->right->left = rightleft;
	}

	void fixtree()
	{
		if (balance() < -1) // right is heavier
		{
			if (right->balance() < -1) // RR
			{
				this->rotateleft();
				recalculateheights();
			}
			else if (right->balance() > 1) //RL
			{
				right->rotateright();
				this->rotateleft();
				recalculateheights();
			}
		}
		else if (balance() > 1) // left is heavier
		{
			if (left->balance() > 1) // LL
			{
				this->rotateright();
				recalculateheights();
			}
			else if (left->balance() < -1) // LR
			{
				left->rotateleft();
				this->rotateright();
				recalculateheights();
			}
		}
	}
};

class AVL
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
		current->calculateheight();
		current->fixtree();
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

		current->calculateheight();
		current->fixtree();
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
	AVL() = default;
	AVL(Node* root)
	{
		this->root = root;
	}
	~AVL()
	{
		delete root;
	}
	AVL(const AVL& rhs)
	{
		if (rhs.root)
		{
			root = new Node(*rhs.root);
		}
	}
	AVL& operator=(const AVL& rhs)
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
	AVL tree;
	for (int i = 0; i < 12; i++)
	{
		tree.insert(i);
	}
	tree.print();
	std::cout << std::endl;
	tree.remove(10);
	tree.print();
}
