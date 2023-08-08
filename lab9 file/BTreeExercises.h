//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"


template<class T>
int treeHeight(BtreeNode<T> *root){
	return maxDepth(root)-1;
}


template<class T>
int maxDepth(BtreeNode<T> *root){
	if(root==NULL)
		return 0;
	int left=maxDepth(root->get_left());
	int right=maxDepth(root->get_right());

	if(left>=right)
		return left+1;
	else
		return right+1;
}

template<class T>
int countNodes(BtreeNode<T> *root){
	if(root==NULL)
		return 0;
    /*const BtreeNode<T>* left=root;
    const BtreeNode<T>* right=root;
    int leftnode=0;
    while(left->get_left()!=NULL){
    	left=left->get_left();
    	leftnode++;
    }
    int rightnode=0;
    while(right->get_right()!=NULL){
    	right=right->get_right();
    	rightnode++;
    }*/
       return countNodes(root->get_left())+countNodes(root->get_right())+1;
    }


template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	if(root==NULL)
		return NULL;
	BtreeNode<T>* left=mirror(root->get_left());
	BtreeNode<T>* right=mirror(root->get_right());
	BtreeNode<T>* mirror =new BtreeNode<T>(root->get_data(),right,left);

	return mirror;


}

template<class T>
bool isComplete(BtreeNode<T> *root){
	if(root->get_left()!=NULL){
	 return(isComplete(root->get_left())&&isComplete(root->get_right()));
	}
	if(root->get_left()==NULL&&root->get_right()!=NULL)
		return false;
	return true;
}

/*template<class T>
void left(BtreeNode<T> *root,int& num){
	while(root->left!=NULL){
		root=root->left;
		num++;
	}
}
z
template<class T>
void right(BtreeNode<T> *root,int& num){
	while(root->right!=NULL){
		root=root->right;
		num++;
	}
}*/


#endif //LAB9_BTREEEXERCISES_H
