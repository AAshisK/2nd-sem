#include<iostream>
using namespace std;


void swap(int arr[],int low,int high,int *counter)
{
	
	int pivot = arr[high];
	if(arr[low]>pivot){
		int a = arr[low];
		arr[low] = arr[high-1];
		arr[high-1] = a;
		counter = &arr[high];
		if(low = high) 
		{
			return ;
		}
		return swap(arr,low,high-1,counter);
	}
	else {
		swap (arr,low+1,high,counter);
	}
	
}	
	
	
void partition(int arr[],int low,int high) 
{
	int pivot = arr[high];
	
}

int display(int arr[]){
	for(int i = 0;i<5;i++) 
	{
		cout<<arr[i]<<endl;
	}
}
int main(){
	int *p;
	 int arr[7]={2,9,1,5,4,3,7};
	 swap(arr,0,4,p);
	 display(arr);
}
