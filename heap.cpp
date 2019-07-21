#include<iostream>
using namespace std;

class heap
{
	public:
	int *harr;
	int capacity;
	int heapSize;

	public:
	heap(int cap)
	{
		heapSize = 0;
		this->capacity = cap;
		harr = new int[cap];
	}
	void insertKey(int key);
	int leftChild(int i);
	int rightChild(int i);
	int parent(int i);
	void levelOrder(int *harr);
};

int heap::leftChild(int i)
{
	return 2*i+1;
}
int heap::rightChild(int i)
{
	return 2*i+2;
}
int heap::parent(int i)
{
	return (i-1)/2;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a= *b;
	*b = temp;
}
void heap::levelOrder(int *arr)
{
	for(int i=0;i<capacity;i++)
	{
		cout<<arr[i]<<" ";
	}

}
void heap::insertKey(int key)
{
	if(heapSize == capacity)
	{
		cout<<"\n overflow";
		return;
	}
	
	
	heapSize++;
	int i = heapSize-1;
	harr[i] = key;


	while(i!=0 && harr[parent(i)]<harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i = parent(i);

	}

}

int main()
{
	heap maxHeap(6);
	maxHeap.insertKey(32);
	maxHeap.insertKey(20);
	maxHeap.insertKey(60);
	maxHeap.insertKey(21);
	maxHeap.insertKey(87);
	maxHeap.insertKey(90);

	maxHeap.levelOrder(maxHeap.harr);
}
