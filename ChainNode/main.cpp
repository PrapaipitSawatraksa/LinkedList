#include<iostream>
#include"ChainNode.h"

using namespace std;

int main()
{
    cout<<"66003065 Prapaipit Sawatraksa"<<endl;
    
    ChainNode a;
    ChainNode b (10,&a);
    ChainNode c (20,&b);
    //cout<<"a = "<<a.element<<"\tb = "<<b.element<<"\tc = "<<c.element<<endl;
    

    return 0;
}