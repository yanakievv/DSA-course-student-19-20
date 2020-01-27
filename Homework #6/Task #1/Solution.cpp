#include <iostream>
#include <string>
#include <iomanip>
#define max(a,b) ((a) > (b) ? (a) : (b))
void swap(int& a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
using namespace std;

struct Node
{
	double value;
	Node *left = nullptr;
	Node *right = nullptr;
    int height = 0;

    Node(double value)
    {
        this->value = value;
    }
    
    int leftHeight()
    {
        if (left)
        {
            return left->height + 1;
        }
        else return 0;
    }
    int rightHeight()
    {
        if (right)
        {
            return right->height + 1;
        }
        else return 0;
    }
    void calculateHeight()
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
    void recalculateHeights()
    {
        if (left)
        {
            left->calculateHeight();
        }
        if (right)
        {
            right->calculateHeight();
        }
        this->calculateHeight();
    }
    int balance()
    {
        return leftHeight() - rightHeight();
    }
    
    void rotateLeft()
    {
        if (!right)
        {
            return;
        }
        
        Node* rightLeft = this->right->left;
        Node* oldLeft = this->left;
        
        swap(this->value, this->right->value);
        this->left = this->right;
        this->right = this->right->right;
        this->left->right = rightLeft;
        this->left->left = oldLeft;
    }
    void rotateRight()
    {
        if (!left)
        {
            return;
        }
        
        Node* leftRight = this->left->right;
        Node* oldRight = this->right;
        
        swap(this->value,this->left->value);
        this->right = this->left;
        this->left = this->left->left;
        this->right->left = leftRight;
        this->right->right = oldRight;
    }
    
    void fixTree()
    {
        if (balance() < -1)
        {
            if (right->balance() <= -1)
            {
                this->rotateLeft();
                recalculateHeights();
            }
            else if (right->balance() >= 1)
            {
                this->right->rotateRight();
                this->rotateLeft();
                recalculateHeights();
            }
        }
        else if (balance() > 1)
        {
            if (left->balance() >= 1)
            {
                this->rotateRight();
                recalculateHeights();
            }
            else if (left->balance() <= -1)
            {
                this->left->rotateLeft();
                this->rotateRight();
                recalculateHeights();
            }
        }
    }
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}
    Node* _add(Node* current, double value)
    {
        if (!current)
        {
            return new Node(value);
        }
        
        if (current->value > value)
        {
            current->left = _add(current->left, value);
        }
        else if (current->value < value)
        {
            current->right = _add(current->right, value);
        }
        
        current->recalculateHeights();
        current->fixTree();
        
        return current;
    }
    Node* _remove(Node* current, double value)
    {
        if (!current)
        {
            return nullptr;
        }
        
        if (current->value > value)
        {
            current->left = _remove(current->left, value);
        }
        else if (current->value < value)
        {
            current->right = _remove(current->right, value);
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
                Node* swapWith = current->right;
                while (swapWith->left)
                {
                    swapWith = swapWith->left;
                }
                swap(current->value, swapWith->value);
                current->right = _remove(current->right,swapWith->value);
            }
        }
        
        current->recalculateHeights();
        current->fixTree();
        
        return current;
    }

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double value)
	{
        if (contains(value))
        {
            std::cout<<value<<" already added"<<std::endl;
        }
        else
        {
            root = _add(root, value);
        }
	}

	void remove(double value)
	{
        if (!contains(value))
        {
            std::cout<<value<<" not found to remove"<<std::endl;
        }
        else
        {
            root = _remove(root, value);
        }
	}

bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
        cout << endl;
	}
};



int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
    cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
