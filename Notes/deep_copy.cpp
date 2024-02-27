/*In shallow copy, an object is created by simply copying the data of all variables of the original object. 
This works well if none of the variables of the object are defined in the heap section of memory. 
If some variables are dynamically allocated memory from heap section, then the copied object variable will also reference the same memory location.

In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same value to the object. 
In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as well, if required. 
Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
*/
// C++ program to implement the
// deep copy
#include <iostream>
using namespace std;

// Box Class
class box {
private:
	int length;
	int* breadth; //int ptr
	int height;

public:
	// Constructor
	box()
	{
		breadth = new int; //DMA of one int to the ptr
	}

	// Function to set the dimensions
	// of the Box
	void set_dimension(int len, int brea,
					int heig)
	{
		length = len;
		*breadth = brea; //deref breadth ptr and init value to brea
		height = heig;
	}

	// Function to show the dimensions
	// of the Box
	void show_data()
	{
		cout << " Length = " << length
			<< "\n Breadth = " << *breadth
			<< "\n Height = " << height
			<< endl;
	}

	// Parameterized Constructors for
	// for implementing deep copy
	box(box& sample)
	{
		length = sample.length;
		breadth = new int; //We allocate the memory for the breadth ptr in the deep copy constructor
		*breadth = *(sample.breadth);
		height = sample.height;
	}

	// Destructors
	~box()
	{
		delete breadth; //Destructor called to delete the memory allocated in heap for the breadth ptr
	}
};

// Driver Code
int main()
{
	// Object of class first
	box first;

	// Set the dimensions
	first.set_dimension(12, 14, 16);

	// Display the dimensions
	first.show_data();

	// When the data will be copied then
	// all the resources will also get
	// allocated to the new object
	box second = first;

	// Display the dimensions
	second.show_data();

	return 0;
}
