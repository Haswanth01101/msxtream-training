#include "array.h"

array::array(int sz):size(sz),count(0),sum(0){
	arr=new int[size];
}
void array::insert(int data)
{
	if(count<size)
	{
		arr[count]=data;
		sum+=data;
		count++;
	}else{
		cout<<"Array is full"<<endl;
	}	
}

void array::sumOfEntireArray()
{
	cout<<"Sum of the Array Elemets :"<<sum<<endl;
}
int array::MaxValue()
{
	int Max=arr[0];
	for(int i=0;i<count;i++)
	{
		if(Max<arr[i])
		{
			Max=arr[i];
		}
	}
	return Max;

}
int array::MinValue()
{
	int Min=arr[0];
	for(int i=0;i<count;i++)
	{
		if(Min>arr[i])
		{
			Min=arr[i];
		}
	}
	return Min;
}
void array::average()
{
	double avg=(double)sum/(double)count;
	cout<<"Average Number is :"<<avg<<endl;
}
void array::search(int value)
{
	for(int i=0;i<count;i++)
	{
	  if(value==arr[i])
	  {
	 cout<<"The value found at index : "<<i<<endl;
	 break;
	  }
	}
	cout<<"The value not found in the array"<<endl;
}
void array::sort()
{
for(int i=0;i<count;i++)
{
int minindex=i;
for(int j=i+1;j<count;j++)
{
	if(arr[j]<arr[minindex])
	{
		minindex=j;
	}
}
swap(arr[i],arr[minindex]);
}

cout<<"The sorted Order of Numbers: ";
for(int i=0;i<count;i++){
	cout<<arr[i]<<"  ";
}
cout<<endl;
}
void array::EvenNumbers()
{
	cout<<"This are the Following Even Numbers: ";
	for(int i=0;i<count;i++)
	{
		if(arr[i]%2==0)
		{
		cout<<arr[i]<<"\t";
		}
	}
	cout<<endl;
}
void array::OddNumbers()
{ 
	for(int i=0;i<count;i++)
	{
		if(arr[i]%2!=0)
		{
		cout<<arr[i]<<"\t";
		}
	}cout<<endl;
}
void array::display(){
	for(int i=0;i<count;i++)
	{
		cout<<arr[i]<<"\t";

	}
	cout<<endl;
}





