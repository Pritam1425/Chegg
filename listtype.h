#ifndef LISTTYPE_FLAG
#define LISTTYPE_FLAG
#include <iostream>
#include <cmath>
using namespace std;

template <class elementType>
class listType
{
   private:
       // the definition of the struct nodeType is private
       struct nodeType
       {
           elementType payLoad;
           nodeType *left, *right;

           nodeType()
           {
               left=NULL;
               right=NULL;
               return;
           }
       };

       int numNodes, numLvls;

       nodeType *root;

       nodeType **envPtr; // double Pointer!!! (This is new.)

       //**************************************
       // called by create() and the destructor;
       void altDelete(nodeType *p) // recursive procedure with a public wrapper: void listType::delete();
       {
           if( p )
           {
               altDelete(p->left);
               altDelete(p->right);
               delete p;
           }

           return;
       }

       //***********************************
       // recursive method for print()
       void altPrint(nodeType *p, int level)
       {
           if(p)
           {
               cout<<"Level - "<<level<<'\t'<<p->payLoad<<'\n';
               altPrint(p->right, level+1);
               altPrint(p->left, level+1);
           }
           return;
       }
       //************************************

       // diagnostic routines for balance routine follow. Counting levels is used
       // extensively in balancing a binary tree

       int cntLvls(nodeType *p) // counts the number of levels in a tree or subtree
       {
           numLvls=0;
           altCntLvls(p, 1);
           return numLvls;
       }


       void altCntLvls(nodeType *p, int i) // recursive, called by int cntLvls(nodeType)
       {
           if(!p)
               return;
           else
           {
               if(i>numLvls)
                   numLvls=i; // numLvls is a class variable

               altCntLvls(p->left, i+1);
               altCntLvls(p->right, i+1);
           }
       }


       int calcLvls() // calculates the number of levels in a perfect tree (could be made public)
       {
           return ceil( log(numNodes+1)/log(2)); // ceiling( log2( numNodes+1) ) #include <cmath>
       }

       void rotL(nodeType **dp) // rotates a simple, three-node, two-level tree left while
       {                                           // preserving the logical structure of the subtrees.
           nodeType *p; p=*dp;
           *dp=p->right;
           p->right=(*dp)->left;
           (*dp)->left=p;
       }

       void rotR(nodeType **dp) // same as above, but rotates right. Note the double pointer parameter
       {
           nodeType *p; p=*dp;
           *dp=p->left;
           p->left=(*dp)->right;
           (*dp)->right=p;
       }

	int getHeight(nodeType *dp)
	{
		int left = cntLvls(dp->left);
		int right = cntLvls(dp->right);
		return left-right;
	}
   void balanceTree(nodeType **dp)
   {
      int height = getHeight(*dp);
      if()
   }
