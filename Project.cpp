#include<iostream>
#include<cstdlib>
#include <graphics.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include<string>

using namespace std;

void basic_concept()
{
	cout<<"\nA min-heap is a complete binary tree in which the value of each internal node is less than or equal to the values of its children."; 
	cout<<"\nThe root of the tree is the minimum element of the tree.This property is called the min-heap property."; 
	cout<<"\nIt is one of the two types of heap data structures, the other being a max-heap, in which the value of each internal node is greater than or equal to the values of its children.";
}
void memory_representation()
{
	cout<<"\nA Minimum heap is represented as an array and linked list in the memery.\n\n-------In Array the representation follows some property---------"<<endl;
	cout<<"1. The root of the tree will be at Arr[0]."<<endl;
	cout<<"2. For any node at Arr[i], its left and right children will be at Arr[2*i + 1] and Arr[2*i+2] respectively."<<endl;
	cout<<"3. For any node at Arr[i], its parent node will be at Arr[(i-1)/2]."<<endl<<endl;
	cout<<"-------In Linked List the representation follows some property---------"<<endl;
	cout<<"1. The node is made with both its Previous and Next"<<endl;
	cout<<"2. The Previuos of node represent the Left Child"<<endl;
	cout<<"3. The Next of the Node represent the Right Child"<<endl;		
}
void uses_in_computer()
{
	cout<<"\nThere are many Advantages or uses of heap"<<endl;
	cout<<"\n1. Heap Sort : Heap Sort uses Binary Heap to sort an array in O(nlogn)."<<endl;
	cout<<"2. Priority Queue: It uses binary heap to efficient implement operations insert(), delete(), extract_max(), update() in O(logn) time."<<endl;
	cout<<"3. Graph Algorithms: Some of the Graph Algorithms also use heaps to reduce its time complexity like Dijkstra’s Algorithm and Minimum Spanning Tree."<<endl;
	cout<<"4. K-way merge: A heap data structure is useful to merge many already-sorted input streams into a single sorted output stream."<<endl;
	cout<<"5. Order statistics : The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array."<<endl;
	cout<<"6. Heap data structures are used in memory management to efficiently allocate and deallocate memory blocks."<<endl;
	cout<<"7. Heaps can be used to efficiently maintain the median element in a constantly updating data set."<<endl;
}

void uses_in_real_life()
{
	cout<<"\n1. To quickly find the smallest and largest element from a collection of items or array"<<endl;
	cout<<"2. In a hospital, an emergency patient, or the patient with more injury is treated first. Here the priority is the degree of injury."<<endl;
	cout<<"3. They have been used in operating systems for job scheduling on a priority basis."<<endl;
	cout<<"4. Systems concerned with security and embedded system such as Linux Kernel uses Heap Sort because of the O( nlog(n) )."<<endl;
	cout<<"5. To merge large numbers of sub-sequences sorted in ascending order into a single such sequence."<<endl;
	cout<<"6. For finding the order in statistics"<<endl;
	cout<<"7. Heaps can be used in the construction of Huffman coding trees."<<endl;	
}

void limitations()
{
	cout<<"\n----------limitations of heap are:----------"<<endl;
	cout<<"\n1. The time complexity for searching an element in Heap is O(N)."<<endl;
	cout<<"2. To find a successor or predecessor of an element, the heap takes O(N) time, whereas BST takes only O(log N) time."<<endl;
	cout<<"3. To print all elements of the heap in sorted order time complexity is O(N*log N), whereas, for BST, it takes only O(N) time."<<endl;
	cout<<"4. Memory management is more complex in heap memory because it is used globally. Heap memory is divided into two parts-old generations and the young generation etc. at java garbage collection."<<endl;
	cout<<"5. Not suitable for small datasets."<<endl;
	cout<<"6. Complex implementation."<<endl;
	cout<<"7. Traversing is not easy as we need to remove the top element in order to access the rest of the elements."<<endl;
}

void advantages()
{
	cout<<"\n----------Advantages Are----------"<<endl;
	cout<<"\n1. To just peek at the most prior element the time complexity is constant O(1)"<<endl;
	cout<<"2. Can be implemented using an array, it doesn’t need any extra space for pointer."<<endl;
	cout<<"3. A binary heap is a balanced binary tree, and easy to implement"<<endl;
	cout<<"4. Heap can be created with O(N) time."<<endl;
	cout<<"5.  Heaps are efficient for large data sets."<<endl;
	cout<<"6. The memory is dynamically allocated"<<endl;
	cout<<"7. Less time complexity, for inserting or deleting an element in the heap the time complexity is just O(log N)"<<endl;
}

void user_representation()
{

	initwindow(720,600,"User Representation");
	setbkcolor(WHITE);
	cleardevice();
	
	readimagefile("user_rep.jpg", 100, 50, 600, 600);
	getch();
	closegraph();
}

// void how_it_works(){
	
	const int MAX_NODES = 100;

	int heap[MAX_NODES], heapSize;

	void insert(int value) {
    	if (heapSize == MAX_NODES) {
        	printf("Error: Heap is full.\n");
        	return;
    	}
    	heapSize++;
    	heap[heapSize] = value;
    	int current = heapSize;
    	while (current > 1 && heap[current] < heap[current / 2]) {
        	swap(heap[current], heap[current / 2]);
        	current = current / 2;
    	}
	}
	
	
	void delete_node(int value) {
    	int node = -1;
    	for (int i = 1; i <= heapSize; i++) {
        	if (heap[i] == value) {
            	node = i;
            	break;
        	}
    	}
    	if (node == -1) {
        	cout << "Error: Value not found in heap." <<endl;
        	return;
    	}
    	heap[node] = heap[heapSize];
    	heapSize--;
    	int current = node;
    	while ((current * 2 <= heapSize && heap[current] > heap[current * 2]) || 
				(current * 2 + 1 <= heapSize && heap[current] > heap[current * 2 + 1])) {
        	if (current * 2 + 1 <= heapSize && heap[current * 2 + 1] < heap[current * 2]) {
            	swap(heap[current], heap[current * 2 + 1]);
            	current = current * 2 + 1;
        	} else {
            	swap(heap[current], heap[current * 2]);
            	current = current * 2;
        	}
    	}
	}
	
	

	void draw_min_heap_tree(int x, int y, int value, int node) {
    	if (node > heapSize) {
        	return;
    	}
    	char val[10];
    	sprintf(val, "%d", value);
    	outtextxy(x, y, val);

    	circle(x, y, 15);

    	if (node * 2 <= heapSize) {
        	line(x, y, x - 60, y +70);
        	draw_min_heap_tree(x - 60, y + 70, heap[node * 2], node * 2);//L
    	}
    	if (node * 2 + 1 <= heapSize) {
        	line(x, y, x + 60, y + 70);
        	draw_min_heap_tree(x + 60, y + 70, heap[node * 2 + 1], node * 2 + 1);//R
    	}
	}
	
	
//}

void mrepresent(int arr[])
{
	int gd= DETECT ,gm;
	initgraph(&gd, &gm,(char*)"");
	rectangle (2,5,30,30);			rectangle (30,5,60,30);
	rectangle (60,5,90,30);			rectangle (90,5,120,30);
	rectangle (120,5,150,30);		rectangle (150,5,180,30);
	rectangle (180,5,210,30);		rectangle (210,5,230,30);
	outtextxy(2, 35, "This is empty space in memory in which we insert data");
	outtextxy(2, 50, "After insertion some data.");
//	rectangle (2,70,30,95);			//rectangle (30,70,60,95);
//	//rectangle (60,70,90,95);		
//	rectangle (30,70,60,95);
////	rectangle (120,70,150,95);		rectangle (150,70,180,95);
////	rectangle (180,70,210,95);	
//	rectangle (60,70,90,95);
//	outtextxy(4, 77, "35");
//	outtextxy(35, 77, "15");
//	outtextxy(65, 77, "50");
//------------------------------------------------------
	//cout<<endl<<sizeof(arr)<<endl;
	
	int a = 2;
	int b = 30;
	int c = 4;
	for(int i=0; i<=sizeof(arr); i++){
		int x = arr[i];
		stringstream ss;
		ss<<x;
		string str;
		ss>>str;
		rectangle (a,70,b,95);
		outtextxy(c, 77, (char*)str.c_str());

		
		a+=30;
		b+=30;
		c+=30;
	}
	
	
//	outtextxy(2, 105, "Data is store at rondom position in RAM. In RAM suppose one block is 1MB occupy 4 Bytes.");
//	outtextxy(2, 125, "Our data is integer type so 4 bytes is enough for data.");
//	
}



int main()
{
	int choice;
	while(1)
	{
		cout<<endl<<endl;
		cout<<"1. Basic Concept"<<endl;
		cout<<"2. User Representation"<<endl;
		cout<<"3. Memory Representation"<<endl;
		cout<<"4. How it Works---"<<endl;
		cout<<"5. Uses in computer"<<endl;
		cout<<"6. Uses in Real Life"<<endl;
		cout<<"7. Advantages"<<endl;
		cout<<"8. Limitations"<<endl;
		cout<<"9. Press 9 for exit"<<endl;

		cout<<"\nEnter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				basic_concept();
				break;
			case 2:
				user_representation();
				break;
			case 3:{
				
			
				memory_representation();
				
				cout<<"For how many nodes of data for memory?";
				int nodes;
				cin>>nodes;
				int arr[nodes];
				for(int i=0; i<nodes; i++){
					cout<<"Enter data for the "<<i+1<<" node: ";
					int data;
					cin>>arr[i];  	
				}
				
				
				
				mrepresent(arr);
				break;
			}
			case 4:{
				heapSize = 0;
				
//				insert(10);
//    			insert(8);
//			    insert(14);
//    			insert(5);

				cout<<"How many nodes you want to enter?";
				int nodes;
				cin>>nodes;
				for(int i=0; i<nodes; i++){
					cout<<"Enter data for the "<<i+1<<" node: ";
					int data;
					cin>>data;
					insert(data);
					//return data;  	
				}
				
				
    			
    			int gd = DETECT, gm;
    			initgraph(&gd, &gm, "");
    			setcolor(WHITE);
    			setviewport(0, 0, 960, 720, 1);
    			draw_min_heap_tree(320, 30, heap[1], 1);
    			getch();
    			closegraph();
    			

				break;
			}
			case 5:
				uses_in_computer();
				break;
			case 6:
				uses_in_real_life();
				break;
			case 7:
				advantages();
				break;
			case 8:
				limitations();
				break;
			case 9:
				exit(1);
				break;
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
}