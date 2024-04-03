#include<iostream>
#include "array.h"
using namespace std;
int main(){
    int size,option;
    cout<<"enter the size of array : ";
    cin>>size;
    array arr(size);
    while(true){
        cout<<"enter the option you want or '0' to exit : "<<endl;

        cout<<"1.insert elements"<<endl;
        cout<<"2.display elements"<<endl;
        cout<<"3.sum of array elements"<<endl;
        cout<<"4.minValue"<<endl;
        cout<<"5.maxValue"<<endl;
        cout<<"6.avg"<<endl;
        cout<<"7.search element"<<endl;
        cout<<"8.sort the array"<<endl;
        cout<<"9.print even numbers"<<endl;
        cout<<"10.print odd numbers"<<endl;
        cout<<endl;

        cin>>option;

        switch(option){
            case 0:
                return 1;
            case 1:
                int value;
                cout<<"enter the value : ";
                cin>>value;
                arr.insert(value);
                break;
            case 2:
            cout<<"the elements in the array are : "<<endl;
                arr.display();
                cout<<endl;
                break;
            case 3:
                arr.sumOfEntireArray();
                break;
                
            case 4:
                cout<<"the min value in the array is: "<<arr.MinValue()<<endl;
                break;
            case 5:
            cout<<"the max value in the array is : "<<arr.MaxValue()<<endl;
                break;
            case 6:

                arr.average();
                break;
            case 7:
                int element;
                cout<<"enter the element to search : ";
                cin>>element;
                arr.search(element);
                break;
            case 8:
                arr.sort();
                break;

            case 9:
                cout<<"the odd numbers in the array are : "<<endl;
                arr.OddNumbers();
                break;
            case 10:
                cout<<"the even numbers in the array are : "<<endl;
                arr.EvenNumbers();
                break;
                
            default:
                cout<<"please choose the correct option!! and try again "<<endl;
        }
    }
    return 0;
}