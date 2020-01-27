#include <iostream>
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
class maxHeap
{
	int* heap;
	int size;
	int currentempty;
	
	inline bool isValid(int i) const
	{
		return (i < currentempty);
	}
	inline bool isFull()
	{
		return (!(currentempty < size));
	}
	void grow()
	{
		int* temp = new int[currentempty];
		for (int i = 0; i < currentempty; i++)
		{
			temp[i] = heap[i];
		}
		delete[] heap;
		size *= 2;
		heap = new int[size];
		for (int i = 0; i < currentempty; i++)
		{
			heap[i] = temp[i];
		}
		delete[] temp;
	}

	int getLeft(int pos)
	{
		return ((pos * 2) + 1);
	}
	int getRight(int pos)
	{
		return ((pos * 2) + 2);
	}
	int getParent(int pos)
	{
		return ((pos - 1) / 2);
	}

	void siftUp(int pos)
	{
		int parent = getParent(pos);
		while (heap[parent] < heap[pos])
		{
			swap(heap[parent], heap[pos]);
			if (parent <= 0)
			{
				return;
			}
			pos = parent;
			parent = getParent(pos);
		}
	}
	void siftDown(int pos)
	{
		bool hasleft = getLeft(pos) < currentempty;
		bool hasright = getRight(pos) < currentempty;
		if (hasright && (heap[pos] < heap[getLeft(pos)] || heap[pos] < heap[getRight(pos)]))
		{
			int swapwith = -1;
			if (heap[getLeft(pos)] < heap[getRight(pos)])
			{
				swapwith = getRight(pos);
			}
			else
			{
				swapwith = getLeft(pos);
			}

			swap(heap[pos], heap[swapwith]);
			siftDown(swapwith);
		}
		else if (hasleft && heap[pos] < heap[getLeft(pos)])
		{
			swap(heap[pos], heap[getLeft(pos)]);
			siftDown(getLeft(pos));
		}
	}
public:

	maxHeap(int size = 10)
	{
		this->size = size;
		heap = new int[this->size];
		currentempty = 0;
	}
	~maxHeap()
	{
		delete[] heap;
	}
	maxHeap(const maxHeap& rhs)
	{
		size = rhs.size;
		currentempty = rhs.currentempty;
		heap = new int[size];
		for (int i = 0; i < currentempty; i++)
		{
			heap[i] = rhs.heap[i];
		}
	}
	maxHeap& operator=(const maxHeap& rhs)
	{
		if (this != &rhs && &rhs != nullptr)
		{
			delete[] heap;
			size = rhs.getSize();
			currentempty = rhs.getCurrentempty();
			heap = new int[size];
			for (int i = 0; i < currentempty; i++)
			{
				heap[i] = rhs.getElement(i);
			}
		}
		return *this;
	}

	int getSize() const 
	{
		return size;
	}
	int getCurrentempty() const
	{
		return currentempty;
	}
	int getElement(int i) const
	{
		if (isValid(i))
		{
			return heap[i];
		}
	}

	void add(int data)
	{
		if (isFull())
		{
			grow();
		}
		heap[currentempty] = data;
		currentempty++;
		siftUp(currentempty - 1);
	}
	int pop()
	{
		if (currentempty != 0)
		{
			int pop = heap[0];
			swap(heap[0], heap[currentempty - 1]);
			currentempty--;
			siftDown(0);
			return pop;
		}
		else return -1;


	}
	int peekTop()
	{
		if (currentempty != 0)
		{
			return heap[0];
		}
		else return -1;
	}

	void heapSort()
	{
		maxHeap sorted(currentempty);
		currentempty--;
		while (currentempty)
		{
			swap(heap[currentempty], heap[0]);
			sorted.add(heap[currentempty]);
			currentempty--;
			siftDown(0);
			
		}
		*this = sorted;
	}
	void print()
	{
		for (int i = 0; i < currentempty; i++)
		{
			std::cout << heap[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	maxHeap test;
	test.add(4);
	test.add(10);
	test.add(3);
	test.add(5);
	test.add(1);
	test.add(14);
	test.add(8);
	test.add(9);
	test.add(100);
	test.add(2);
	//test.heapSort();
	while (test.getCurrentempty())
	{
		std::cout << test.pop() << " ";
	}

}
