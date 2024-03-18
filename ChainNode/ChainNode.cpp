#include "ChainNode.h"
#include<iostream>

using namespace std;

 /*ChainNode::ChainNode()
{
   this->element = 0;
    this->next=NULL;
}
*/
ChainNode::ChainNode(int e, ChainNode *p)
{
    element = e;
    next = p;
       // cout<<"[This : ( e = "<<element<<" ,p = "<<next<<" ) ]"<<endl;
}
