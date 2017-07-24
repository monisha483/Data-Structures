#include <iostream>
using namespace std;
struct heap
{
	int *array,count,capacity;
};
 heap *create(int capacity)
{
	heap *H=new heap;
	if(H==NULL)
	{
		cout<<"\nno memory";
		return H;	
	}
	H->count=0;
	H->capacity=capacity;
	//dynamic memory allocation
	H->array=new int[capacity];
	
	return H;
}

void IncreaseHeapSize(heap *H)
{
	int *temp=H->array;
	H->array=new int[2*(H->capacity)];
	if(H->array==NULL)
	{
		cout<<"\nmemory insufficient";
		return;
	}
	for(int i=0;i<H->capacity;i++)
	{
		H->array[i]=temp[i];
	}
	H->capacity*=2;
	delete temp;
}

void insert(heap *H)
{
	//assume it is max heap
	int i,data;
	cout<<"\nenter val to insert: "; cin>>data;
	if(H->count==H->capacity)
	{
		IncreaseHeapSize(H);
	}
    i=H->count;
	H->count++;
	
	while(i>0&&data>H->array[(i-1)/2])
	{
		H->array[i]=H->array[(i-1)/2];
		i=(i-1)/2;
	}
	H->array[i]=data;
	cout<<"\ninsertion successful";	
}



void PercolateDown(int p, heap *H)
{
	int left,right,max,t;
	left=2*p+1;
	right=2*p+2;
	max=p;
	if(left<H->count && H->array[left]>H->array[max])
	{
		max=left;
	}
	if(right<H->count && H->array[right]>H->array[max])
	{
		max=right;
	}
	if(max==p) 
	{
		cout<<"\npercolate down done";
		return;
	}
	//swap
	t=H->array[p];
	H->array[p]=H->array[max];
	H->array[max]=t;
	PercolateDown(max,H);
}

void DeleteMax(heap *H)
{
	if(H->count<1)
		return;
	cout<<"\ndeleted item: "<<H->array[0];
	H->array[0]=H->array[H->count-1];
	H->count--;
	PercolateDown(0,H);
}

int main()
{
	heap *h=new heap;
	int c,choice,i;
	cout<<"\nenter heap capacity: ";
	cin>>c;
	h=create(c);
	cout<<"\nheap created";
	do
	{
		cout<<"\nmenu\n1.insert into heap\n2.delete max of heap"
		    <<"\n3. view heap elements"
			<<"\n4.exit";
		cin>>choice;
		switch(choice)
		{
			case 1:insert(h);
			       break;
			case 2:DeleteMax(h);
			       break;
			case 3:cout<<"\nelements: ";
			       for(i=0;i<h->count;i++)
					   cout<<h->array[i]<<' ';
				   break;
			case 4:delete h->array;
			       delete h;
			       break;
		}
	}while(choice!=4);
	return 0;
}

