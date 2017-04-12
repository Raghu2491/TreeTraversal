#include<iostream>
#include<vector>
#include<queue>
class BSTNode
{

public:
	BSTNode();
	BSTNode(int val); 

	int value;
	BSTNode* left;
	BSTNode* right;
	bool goleft;
	
};


struct listnode
{
	BSTNode* _data;
	listnode* next;
};
struct headptr
{
	listnode* _ptr;
};
class linkedlist :listnode
{
public:
	linkedlist();
	void addnode(int val);
private:
	listnode* head;
	listnode* tail;
};

class BST :BSTNode
{
public:
	BST();
	BSTNode* root;
	
	void insert(int val);
	BSTNode* getroot();
	std::vector<BSTNode*> vect;
	std::vector<int> vec;
	std::queue<BSTNode*> que;

	void inorder_iterative_usingvector(BSTNode* root);
	void preorder_recursive(BSTNode* root,bool left,std::vector<int> &vec);
	void preorder_recursive2(BSTNode* node, bool left, std::vector<int> &vec);
	void inorder_iterative_withoutvector(BSTNode* root);
	void preorder_iterative_withoutvector(BSTNode* root);
	void mirror(BSTNode* root);
	void print_roottoleaf(BSTNode* root);
	void deepest_leftnode(BSTNode* root,int level,bool isleft,int *height,BSTNode** result);
	int size(BSTNode* root);
	int height(BSTNode* root);
	int longestpath(BSTNode* root);
	BSTNode* deepest_leafnode(BSTNode* root);
	void findancestor(BSTNode* root, int *val);
	void deleteanode(BSTNode * root,int val);
	std::vector<int> levelordertraversal(BSTNode* root);

};
