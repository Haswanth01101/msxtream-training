#include<iostream>
#include "array.h"
using namespace std;
int main(){
    int size,option;
    cout<<"Enter the size of array : ";
    cin>>size;
    if(size<=0){
        cout<<"Invalid size!!!"<<endl;
        return 1;
    }
    array arr(size);
    while(true){
        cout<<"Enter the option you want or '0' to exit : "<<endl;

        cout<<"1.Insert elements"<<endl;
        cout<<"2.Display elements"<<endl;
        cout<<"3.Sum of array elements"<<endl;
        cout<<"4.MinValue"<<endl;
        cout<<"5.MaxValue"<<endl;
        cout<<"6.Avg"<<endl;
        cout<<"7.Search element"<<endl;
        cout<<"8.Sort the array"<<endl;
        cout<<"9.Print Odd numbers"<<endl;
        cout<<"10.Print Even numbers"<<endl;
        cout<<endl;

        cin>>option;

        switch(option){
            case 0:
                return 1;
            case 1:
                int value;
                cout<<"Enter the value : ";
                cin>>value;
                arr.insert(value);
                break;
            case 2:
            cout<<"The elements in the array are : "<<endl;
                arr.display();
                cout<<endl;
                break;
            case 3:
                arr.sumOfEntireArray();
                break;
                
            case 4:
                cout<<"The min value in the array is: "<<arr.MinValue()<<endl;
                break;
            case 5:
            cout<<"The max value in the array is : "<<arr.MaxValue()<<endl;
                break;
            case 6:

                arr.average();
                break;
            case 7:
                int element;
                cout<<"Enter the element to search : ";
                cin>>element;
                arr.search(element);
                break;
            case 8:
                arr.sort();
                break;

            case 9:
                cout<<"The odd numbers in the array are : "<<endl;
                arr.OddNumbers();
                break;
            case 10:
                cout<<"The even numbers in the array are : "<<endl;
                arr.EvenNumbers();
                break;
                
            default:
                cout<<"Choose Valid Option! and try again! "<<endl;
        }
    }
    return 0;
}
