#include "../ChainNode/ChainNode.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;
int main()
{
    int maxSize, choice, i, e, value;
    cout << "66003065 Prapaipit Sawatraksa" << endl;
    cout << "Enter maxSize of List :  ";
    cin >> maxSize;
    cout<<"Maxsize is : "<<maxSize<<endl;
    
    LinkedList list(maxSize);
    do
    {
        list.display();
        cout << "Welcome to Lab LinkedList" << endl;
        cout << "1. | Size ( ) " << endl;
        cout << "2. | IndexOf ( int e )" << endl;
        cout << "3. | Get ( int i )" << endl;
        cout << "4. | Remove ( int i )" << endl;
        cout << "5. | Set ( int i , int e )" << endl;
        cout << "6. | Add ( int i , int e )" << endl;
        cout << "7. | Min ( )" << endl;
        cout << "8. | Max ( )" << endl;
        cout << "9. | Display ( )" << endl;
        cout << "10.| Clear ( )" << endl;
        cout << "11.| OddCount ( )" << endl;
        cout << "12.| EvenCount ( )" << endl;
        cout << "13.| Sum ( )" << endl;
        cout << "14.| Mean ( )" << endl;
        cout << "15.| Sort ( )" << endl;
        cout << "16.| Sort2( )" << endl;
        cout << "17.| AutoInert ( ) "<<endl;
        cout << "18.| sumEven ( ) "<<endl;
        cout << "19.| sumOOD ( ) "<<endl;
        cout << "0. | Exit  Program !! " << endl;
        
        do
        {
            cout << "Select your Choice : ";cin >> choice;
            if(cin.fail() || (choice < 0 || choice >8))
            {
            cin.clear();
            cin.ignore();
            cout<<"Invaild input .Please enter a number between 0 - 8 "<<endl;
            }else{
            break;
            }
        }while(1);

        switch (choice)
        {
        case 1:
            cout << " Current list Size is : " << list.size() << endl;
            break;
        case 2:
            cout << "Enter Element : ";
            cin >> e;
            list.indexOf(e);
            cout << "First Index of " << e << "found at " << i << endl;
            break;
        case 3:
            cout << "Enter Index : ";
            cin >> i;
            e = list.get(i);
            cout << "Element is : " << e << endl;
            break;
        case 4:
            cout << "Enter Index : ";
            cin >> i;
            e = list.remove(i);
            cout << "Element is : " << e << endl;
            break;
        case 5:
            cout << "Enter Index : ";
            cin >> i;
            cout << "Enter Element : ";
            cin >> e;
            list.set(i, e);
            break;
        case 6:
            cout << "Input Add Index : ";
            cin >> i;
            cout << "Input Add Element : ";
            cin >> e;
            list.add( i , e);
            break;
        case 7:
            e = list.min();
            cout << " Minimum Element is " << e << endl;
            break;
        case 8:
            e = list.max();
            cout << " Maximum Element is " << e << endl;
            break;
        case 9:
            list.display();
            cout << "Current size of list :  " << list.size() << "/" << list.get_maxSize() << endl;
            break;
        case 10:
            list.clear();
            cout << "LinkedList Cleared . ";
            break;
        case 11:
            e = list.oddCount();
            cout << "Odd count is " << e << endl;
            break;
        case 12:
            e = list.EvenCount();
            cout << "Even count is " << e << endl;
            break;
        case 13:
            value = list.sum();
            cout << "Summation is " << value << endl;
            break;
        case 14:
            value = list.mean();
            cout << "Average is " << value << endl;
            break;
        case 15:
            //char choice;
            cout << "Sorted is ";
            //cout << "Sort from highest to lowest = Y Sort from lowest to highest = N : ";
            //cin >> choice;
            list.sort();
            break;
        case 16 :
        cout << "Sorted is ";
            //cout << "Sort from highest to lowest = Y Sort from lowest to highest = N : ";
            //cin >> choice;
            list.sort2();
            break;
        case 17 :
            list.AutoInert(maxSize);
            cout << " AutoInsert Genarate Success!" <<endl;
            break;
        case 18 :
            value = list.sumEven();
            cout << "Summation is " << value << endl;
            break;
        case 19 :
            value = list.sumOOD();
            cout << "Summation is " << value << endl;
            break;
        case 0:
            cout << " Exit Program. " << endl;
        default:
            cout << "Wrong choice ,try again..." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}