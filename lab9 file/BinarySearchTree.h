//
// Binary Search Tree Class
//

#ifndef LAB9_BINARYSEARCHTREE_H
#define LAB9_BINARYSEARCHTREE_H

#include <iostream>
#include <iomanip>
using namespace std;

template<typename T1, typename T2>
class BinarySearchTree {
private:
    class BinaryNode;

public:
    BinarySearchTree() : root(NULL) {

    }

    // (Deep) Copy constructor
    BinarySearchTree(const BinarySearchTree &src) : root(src.clone(src.root)) {}

    ~BinarySearchTree() {
        makeEmpty();
    };

    bool isEmpty() const {
        return !root;
    }

    bool contains(const T1 &x, const T2 &y) const {
        return contains(x, y, root);
    }

    void printMax() const;

    void printTree() const {
        printTree(root, 0);
    };

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(const T1 &x, const T2 &y) {
        insert(x, y, root);
    }

private:
    class BinaryNode {
    public:
        T1 x;
        T2 y;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode() :
                left(NULL), right(NULL) {}

        BinaryNode(const T1 &x, const T2 &y, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
                : x(x), y(y), left(lt), right(rt) {}

    };

    BinaryNode *root;

    void insert(const T1 &x, const T2 &y, BinaryNode *&t);

    bool contains(const T1 &x, const T2 &y, BinaryNode *t) const;

    void makeEmpty(BinaryNode *t);

    void printTree(BinaryNode *t, int depth) const;

    BinaryNode *clone(BinaryNode *t) const {
        return !t ? NULL :
               new BinaryNode(t->x, t->y, clone(t->left), clone(t->right));
    };
};

// Print the BST out, the output is rotated -90 degrees.
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printTree(typename BinarySearchTree<T1, T2>::BinaryNode *t, int depth) const {
    if (t == NULL)
        return;
    const int offset = 6;
    printTree(t->right, depth + 1);
    std::cout << std::setw(depth * offset);
    std::cout << "(" << t->x << "," << t->y << ")" << std::endl;
    printTree(t->left, depth + 1);
}

template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::insert(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *&t){

	if(contains(x,y,t)){
		//cout<<"contains it"<<endl;;
		return;
	}


	 BinaryNode *temp=new BinaryNode(x,y);

	 if(isEmpty()){
		t=temp;
		//cout<<"empty"<<endl;
		return;
	 }

		//cout<<"insert"<<endl;

		if(x>t->x){
			if(t->right&&t->right->x>x){
				temp->right=t->right;
	            t->right=temp;
			}
			else if(!t->right){
				t->right=temp;
			}
			else{
				insert(x,y,t->right);
				return;
			}
		}

		if(x<t->x){
			if(t->left!=NULL&&t->left->x<x){
				temp->left=t->left;
				t->left=temp;
			}
			else if(!t->left){
				t->left=temp;
			}
			else{
				insert(x,y,t->left);
				return;
			}
		}

		if(x==t->x){
			if(y>t->y){
                 if(t->right!=NULL&&t->right->y>y){
                	 temp->right=t->right;
                	 t->right=temp;
                 }
                 else if(!t->right){
                	 t->right=temp;
                 }
                 else{
                	 insert(x,y,t->right);
                	 return;
                 }

			}


			if(y<t->y){
				if(t->left&&t->left->y<y){
					temp->left=t->left;
					t->left=temp;
				}
				else if(!t->left){
					t->left=temp;
				}
				else{
					insert(x,y,t->left);
					return;
				}
			}
		}


	}




//  Check if the BST contains the value (x,y).
template<typename T1, typename T2>
bool BinarySearchTree<T1, T2>::contains(const T1 &x, const T2 &y, BinarySearchTree<T1, T2>::BinaryNode *t) const{
	//cout<<"check contain"<<endl;
	if(t==NULL)
		return false;
	if(x==t->x&&y==t->y)
		return true;
     if((contains(x,y,t->left))||(contains(x,y,t->right))){
		return true;
	}
	   return false;
}


// Make Empty
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::makeEmpty(BinarySearchTree<T1, T2>::BinaryNode *t){
   /* BinaryNode *left=t->left;
    BinaryNode *right=t->right;
    if(t!=NULL)
    	delete t;
    else
    	return;
    makeEmpty(left);
    makeEmpty(right);
  cout<<"empty"<<endl;
*/
	if(t==NULL)
		return;
	makeEmpty(t->left);
	makeEmpty(t->right);
	//cout<<"delete"<<endl;
	delete t;
}

// Print max key
// If the tree is empty, you should print "The maximum key is undefined." 
template<typename T1, typename T2>
void BinarySearchTree<T1, T2>::printMax() const{
	if(isEmpty())
		cout<<"The maximum key is undefined."<<endl;
	else{
	BinaryNode *temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	cout<<"The maximum key is ("<<temp->x<<","<<temp->y<<")"<<endl;
	}
}

#endif //LAB9_BINARYSEARCHTREE_H
