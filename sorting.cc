/* Group 15 :
Team Members: Nirmal Kumar Venkatesan
            : Akash athghara
Description :Program to sort an array of integer values using function pointers.
	     and to print the signature of function used.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <typeinfo>

using namespace std;

#define MAXSIZE 100

struct signature
{
	string funcname;
	short numargs;
	const char **num;
};

typedef struct signature signature;

static int NUM_ELEMENTS;

signature sort_array(int [], signature (*sortfunc)(int [],int,int));

signature quicksort_descending( int a[], int low, int high )
{
	int pivot;
	int left, right;
	int pivot_item,temp;
	struct signature sign;
	std::stringstream buffer;
	if ( high > low )
	{
		pivot = left = low;
		pivot_item = a[low];
		right = high;
		while ( left < right )
		{
			while( a[left] >= pivot_item )
				left++;
			while( a[right] < pivot_item )
				right--;
			if ( left < right ){
				temp=a[left];
				a[left]=a[right];
				a[right]=temp;
			}
		}
		a[low] = a[right];
		a[right] = pivot_item;
		pivot =  right;
		quicksort_descending( a, low, pivot-1 );
		quicksort_descending( a, pivot+1, high );
	}
	sign.funcname = "quicksort_descending";                            /*Signature of a function is the function's name and the */
	sign.numargs = 3;                                                  /*number of arguments and type of each argument */
	sign.num = (const char **)malloc(sizeof(const char *)*sign.numargs);
	sign.num[0] = sign.num[1] = sign.num[2] = "int" ;

	return sign;
}

signature quicksort_ascending( int a[], int low, int high )
{
	int pivot;
	int left, right;
	int pivot_item,temp;
	signature sign;
	if ( high > low )
	{
		pivot = left = low;
		pivot_item = a[low];
		right = high;
		while ( left < right )
		{
			while( a[left] <= pivot_item )
				left++;
			while( a[right] > pivot_item )
				right--;
			if ( left < right ){
				temp=a[left];
				a[left]=a[right];
				a[right]=temp;
			}
		}
		a[low] = a[right];
		a[right] = pivot_item;
		pivot =  right;
		quicksort_ascending( a, low, pivot-1 );
		quicksort_ascending( a, pivot+1, high );
	}
	sign.funcname = "quicksort_ascending";				/*Signature of a function is the function's name and the */
	sign.numargs = 3;      						/*number of arguments and type of each argument */
	sign.num = (const char **)malloc(sizeof(const char *)*sign.numargs);
	sign.num[0] = sign.num[1] = sign.num[2] = "int" ;

	return sign;
}

int main()
{

	int iarray[MAXSIZE],choice,r,count,invalid_entry = 5;
	char ch;
	signature sign;
	std::string sort;
	signature (*sort_func)(int[],int,int);
	cout << setw(10);
	cout << "**********Sorting Program******\n" << endl;
	cout << "Choose an option below \n" << endl;
	cout << "1. Enter " << MAXSIZE << " elements manually " << endl;
	cout << "2.Generate " << MAXSIZE << " elements randomly " << endl;
	cin >> choice ;

	switch(choice)
	{
		case 1:
			cout << "Enter" << MAXSIZE << "elements\n" << endl ;
			for(count = 0 ;count < MAXSIZE ;count++){
				cout <<"["<<count+1<<"]:";
				cin >> iarray[count];
				if(iarray[count] == -1){
					NUM_ELEMENTS = count;
					break;
				}
			}
			break;
		case 2:
			cout << "Generating elements randomly" << endl;
			for( count =0 ; count < MAXSIZE; count++)
			{
				r= rand() % 500;
				iarray[count] = r ;

			}
			NUM_ELEMENTS = MAXSIZE;
			break;
		default:
			cout << "Wrong option "<< endl;
			exit(EXIT_FAILURE);
	}
	cout << "Do you want to print the input elements ? Press \"y\" for yes \"n\" for no\n" << endl;
	cin >> ch;
	if(ch == 'y'){
		for(count = 0 ;count < NUM_ELEMENTS;count++)
			cout << iarray[count] << " " ;
	}

	cin.ignore(255, '\n');
	cin.clear();

	while(invalid_entry) {
		cout << "\r\n\n(1) For Ascending sort - Enter \"Asc\" " << endl;
		cout << "(2) For Descending sort - Enter \"Dsc\"" << endl;

		getline(std::cin,sort);
		if(sort == "Asc" || sort == "Dsc"){
			break;	
		}
		else {
			cout << "Please enter a valid option " << endl;
			invalid_entry--;

		}
	}

	if(invalid_entry == 0)
		exit(EXIT_FAILURE);

	if(sort == "Asc")
		sort_func = quicksort_ascending;
	else if(sort == "Dsc")
		sort_func =quicksort_descending;

	sign = sort_array(iarray,sort_func);

	cout << "\n\nSorted array :" << endl;	

	for(count = 1 ;count < NUM_ELEMENTS;count++)
		cout << iarray[count] << " " ;

	cout << "\n\nSignature of function used: " << "\n\nFunction name: " << sign.funcname <<"\n\nNumber of parameters:"<< sign.numargs;
	cout << "\n"<< endl;
	for(count = 0;count < sign.numargs ;count ++)
		cout << "Type of argument["<<count<<"]:"<<sign.num[count] <<  endl;
	return 0;
}

signature sort_array(int iarray[],signature (*sort_func)(int a[],int b,int c))
{
	signature type;
	type = sort_func(iarray,0,NUM_ELEMENTS-1);

	return type;

}
