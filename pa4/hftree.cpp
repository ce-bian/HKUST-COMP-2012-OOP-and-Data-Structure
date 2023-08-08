#include "hftree.h"

class cmp{
	friend class HuffmanTreeNode;
public:
	bool operator()(const HuffmanTreeNode* const&a,const HuffmanTreeNode *const&b){
		if(a->weight==b->weight){
           vector<char> a1;
           vector<char> b1;
           //HuffmanTreeNode *pa=a;
           //HuffmanTreeNode *pb=b;
           order(a,a1);
           order(b,b1);

           int mina=a1[0];
           for(int i=0;i<a1.size();i++){
        	   if(a1[i]<mina)
        		   mina=a1[i];
               }

           int minb=b1[0];
          for(int i=0;i<b1.size();i++){
        	  if(b1[i]<minb)
        		  minb=b1[i];
          }
          return mina>minb;

		}
		else
		      return a->weight>b->weight;
	}

	void order(const HuffmanTreeNode*const &root,vector<char>& v){
      if(root==NULL)
    	  return;
     if(root->leftChild==NULL&&root->rightChild==NULL){
         v.push_back(root->key);
         return;
     }

     if(root->leftChild)
       order(root->leftChild,v);
      if(root->rightChild)
        order(root->rightChild,v);


	}

};




HuffmanTree::HuffmanTree() : hfTree(NULL) {}

void HuffmanTree::loadMap(map<char, int> frequency_table)
{
    // create an minimum priority queue in STL
    // insert your code here ...

	//priority_queue <pair<int,HuffmanTreeNode*>,vector<pair<int,HuffmanTreeNode*>>,cmp>q;
	priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>,cmp>q;
	//cout<<"??"<<endl;
    map<char,int>::const_iterator p;
    for(p=frequency_table.begin();p!=frequency_table.end();++p){
    	HuffmanTreeNode*node=new HuffmanTreeNode;
    	node->key=p->first;
    	node->weight=p->second;
    	node->huffman_code="";
    	node->leftChild=NULL;
    	node->rightChild=NULL;
    	q.push(node);
    }

    while(q.size()>1)
    {
    	HuffmanTreeNode* node=new HuffmanTreeNode;
    	//HuffmanTreeNode* node1=new HuffmanTreeNode;
    	//HuffmanTreeNode* node2=new HuffmanTreeNode;
        HuffmanTreeNode* node1=q.top();
        q.pop();
        HuffmanTreeNode* node2=q.top();
        q.pop();
        mergeTree(node1,node2,node);
        q.push(node);

    }
       hfTree=q.top();

//cout<<"loadmap"<<endl;
}

void HuffmanTree::mergeTree(HuffmanTreeNode *bt1, HuffmanTreeNode *bt2,
                       HuffmanTreeNode *pt)
{
    // insert your code here ...
    pt->leftChild=bt1;
    pt->rightChild=bt2;
    pt->key=NULL;
    pt->huffman_code="";
    pt->weight=bt1->weight+bt2->weight;


}


void HuffmanTree::encode(map<char, string>& encoded_table)
{
    // go through every path from root to leaf, then get the encoding of each character(leaf node)
    // you are NOT allowed to use any recursive method here, otherwise you'll get no marks for this function
    // try level-order traversal on this Huffman Tree
    // result encoded_table: char -- character set, string -- encoding of leaf node, like "00", "1001"...

    // insert your code here ...


    queue <HuffmanTreeNode*> p;
    p.push(hfTree);

    while(!p.empty()){
    	HuffmanTreeNode* node=p.front();
    	HuffmanTreeNode* leftnode=node->leftChild;
        HuffmanTreeNode* rightnode=node->rightChild;
    if(leftnode!=NULL){
         leftnode->huffman_code=node->huffman_code+"0";
         p.push(leftnode);
         encoded_table.insert(make_pair(leftnode->key,leftnode->huffman_code));
    }

    if(rightnode!=NULL){
    	rightnode->huffman_code=node->huffman_code+"1";
    	p.push(rightnode);
    	 encoded_table.insert(make_pair(rightnode->key,rightnode->huffman_code));
    }

    p.pop();
    }
    encoded_table.erase(NULL);

}


string HuffmanTree::decode(const string& bin_str)
{
    // decode a binary string to plaintext
    // insert your code here ...
	string copy=bin_str;
	string code="";
	HuffmanTreeNode* node=hfTree;
 while(copy.length()!=0){

       int num=0;
   for(int i=0;i<copy.length();i++){

	   char temp=copy.at(i);
	   if(temp=='0'){
		   node=node->leftChild;
		   num++;
	   }
	   if(temp=='1'){
		   node=node->rightChild;
		   num++;
	   }
	     if(node->leftChild==NULL&&node->rightChild==NULL){
		  //string substring=""+node->key;
		  code+=node->key;
		  copy=copy.substr(num,copy.length()-num);
		  break;
	     }
	   }
 }

  return code;

}

void HuffmanTree::release()
{
    // release all tree nodes in post-order
    // you must use non-recursive traversal to release the tree
    // you need to print out the weight of nodes with post-order when you delete the node
    // hint: try to use stack
    // if you use recursive deletion, you will lose partial marks of this PA

    cout << "[start releasing the huffman tree...]" << endl;
    if (hfTree == NULL)
        return;

    // store the nodes in vector path with post-order first
    vector<HuffmanTreeNode*> path;
    HuffmanTreeNode* node;

    // insert your code here ...
    stack<HuffmanTreeNode*> s1,s2;
    s1.push(hfTree);
    while(!s1.empty()){
    	node=s1.top();
    	s1.pop();
    	s2.push(node);

    	if(node->leftChild)
    		s1.push(node->leftChild);
    	if(node->rightChild)
    		s1.push(node->rightChild);

    }
    while(!s2.empty()){
    	node=s2.top();
    	path.push_back(node);
    }
    
   //code


    for (int i = 0; i < path.size(); i++) {
        if (i != path.size() - 1)
            cout << dec << path[i]->weight << " ";
        else
            cout << dec << path[i]->weight << endl;

        // delete the node
        delete path[i];
    }
    cout << "[successfully released.]" << endl;
}

