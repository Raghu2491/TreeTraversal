#include "BinaryTree.h"
#include <vector>
#include<list>
#include<map>


BST::BST()
{
	root = NULL;
}

void BST::preorder_recursive(BSTNode* node,bool left, std::vector<int> &vec)
{
	
	if (node == NULL)
		return;
	
	if (left || node->left == NULL && node->right == NULL)
		//std::cout << node->value;
		vec.push_back(node->value);
	preorder_recursive(node->left,true,vec);
	preorder_recursive(node->right,false,vec);
	
}
void BST::preorder_recursive2(BSTNode* node, bool isright, std::vector<int> &vec)
{
	if (node == NULL)
		return;

	if (isright)
		vec.push_back(node->value);
	preorder_recursive2(node->right, true,vec);
}

void BST::inorder_iterative_withoutvector(BSTNode* root)
{
	BSTNode* temp = root;
	BSTNode* prev = NULL;
	if (root == NULL)
		return;

	while (temp != NULL) {

		if (temp->left == NULL)
		{
			std::cout << temp->value;
			temp = temp->right;
		}
		else
		{
			prev = temp->left;
			while (prev->right != NULL && prev->right != temp)
				prev = prev->right;
			if (prev->right == NULL) {
				prev->right = temp;
				temp = temp->left;
			}
			else {
				prev->right = NULL;
				std::cout << temp->value;
				temp = temp->right;
			}
			
		}
	}

}

void BST::preorder_iterative_withoutvector(BSTNode* root)
{
	BSTNode* temp = root;
	BSTNode* prev = NULL;
	while (temp != NULL)
	{
		if (temp->left == NULL) {
			std::cout << temp->value;
			temp = temp->right;
		}
		else {
			prev = temp->left;
			while (prev->right != NULL && prev->right != temp)
				prev = prev->right;

			if (prev->right == NULL)
			{
				prev->right = temp;
				std::cout << temp->value;
				temp = temp->left;
			}
			else
			{
				prev->right = NULL;
				temp = temp->right;
			}
		}
	}
}

void BST::insert(int val)
{
	
	if (root == NULL)
		root = new BSTNode(val);
	else
	{
		BSTNode *temp = root;
		BSTNode *prev=0;

		while (temp != NULL)
		{
			prev = temp;
			if (val > temp->value)
				temp = temp->right;
			else
				temp = temp->left;
		}
		BSTNode* newnode = new BSTNode(val);
		if (prev->value > val)
			prev->left = newnode;
		else
			prev->right = newnode;
	}
	
	
}

BSTNode * BST::getroot()
{
	return root;
}

void BST::inorder_iterative_usingvector(BSTNode * root)
{
	std::vector <BSTNode*> vec;
	BSTNode* temp = NULL;
	BSTNode* prev = NULL;
	vec.push_back(root);
	while (vec.size() != 0)
	{
		temp = vec.back();
		if (temp->left == NULL &&temp->right==NULL) {
			temp->goleft = 1;
			std::cout << temp->value;
			vec.pop_back();
		}
		else
		{
			if (temp->left == NULL && temp->right != NULL)
			{
				std::cout << temp->value;
				temp = temp->right;
				vec.pop_back();
				vec.push_back(temp);
			}
			else
			{
				if (temp->goleft == 0)
				{
					while (temp->left != NULL)
					{
						temp->goleft = 1;
						temp = temp->left;
						vec.push_back(temp);
					}
				}
				else
				{
					std::cout << temp->value;
					if (temp->right != NULL) {
						temp = temp->right;
						vec.pop_back();
						vec.push_back(temp);
					}
					else {
						vec.pop_back();
					}				
					
				}
			}
		}
	}
}

BSTNode* BST::deepest_leafnode(BSTNode * root)
{
	int maxlevel = 0;
	BSTNode* result = NULL;
	
	deepest_leftnode(root, 0, false, &maxlevel, &result);

	return result;
}

void BST::findancestor(BSTNode * root, int *val)
{
	if (root == NULL)
		return;
	else
	{
		vect.push_back(root);
		if ((vect.back())->value == *val)
		{
			if (vect.size() != 1)
			{
				for (int i = (vect.size())-2; i >= 0; i--)
					std::cout << (vect[i])->value << std::endl;
			}
			else
				return;
		}
		findancestor(root->left,val);
		findancestor(root->right,val);
		vect.pop_back();
	}
}

void BST::deleteanode(BSTNode * root, int val)
{
	BSTNode *temp = root;
	BSTNode *prev = NULL;
	if (temp->value == val)
	{
		if (temp->right != NULL)
		{
			prev = temp;
			temp = temp->right;
			while (temp->left != NULL)
			{
				prev = temp;
				temp = temp->left;
			}
			if (prev->value == root->value)
			{
				root->value = temp->value;
				root->right = temp->right;
				temp->right = NULL;
			}

			if (temp->right == NULL)
			{
				root->value = temp->value;
				
				prev->left = NULL;
			}
			else
			{
				root->value = temp->value;
				prev->left = temp->right;
				temp->right = NULL;
			}

		}
		else
		{
			prev = temp;
			temp = temp->left;
			while (temp->right != NULL)
			{
				prev = temp;
				temp = temp->right;
			}
			if (prev->value == root->value)
			{
				root->value = temp->value;
				root->left = temp->left;
				temp->left = NULL;
			}
			else
			{
				if (temp->left == NULL)
				{
					root->value = temp->value;
					prev->right = NULL;
				}
				else
				{
					root->value = temp->value;
					prev->right = temp->left;
					temp->left = NULL;
				}
			}
		}
	}
}

std::vector<int> BST::levelordertraversal(BSTNode * root)
{
	
	if (root == NULL) {
		return vec;
	}
	else
	{		
		int level = 0;
		std::map<int, std::list<BSTNode*>> ref;
		BSTNode* temp = NULL;
		que.push(root);
		while (que.size() != 0)
		{
			std::list<BSTNode*> LL;
			int t = que.size();
			for (int i = 0; i < t; i++)
			{
				LL.push_back(que.front());
				BSTNode* temp = que.front();
				que.pop();
				if (temp->left)
					que.push(temp->left);
				if (temp->right)
					que.push(temp->right);
			}
			ref[level++] = LL;
			//level++;
		}
				
			
		for (int i = 0; i < level; i++)
		{
			std::list<BSTNode*>::iterator t;
			std::list<BSTNode*> temp = ref[i];
			for (t = temp.begin(); t != temp.end(); t++)
			{
				std::cout << (*t)->value <<" ";
			}
			std::cout << std::endl;
		}


			//std::cout << std::endl;
	}
	
	return vec;
}
	
void BST::deepest_leftnode(BSTNode * root, int level, bool isleft, int *height,BSTNode** result)
{
	if (root == NULL)
		return ;
	
	if (isleft && root->left==NULL && root->right==NULL && level > *height)
	{
		*height = level;
		*result = root;
		return ;
	}
	deepest_leftnode(root->left, level+1, true, height,result);
	deepest_leftnode(root->right, level+1, false, height,result);	
	
}

int BST::size(BSTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return (size(root->left) + 1 + size(root->right));
}

int BST::height(BSTNode* root)
{
	if (root == NULL)
		return -1;
	int leftheight=height(root->left);


	int rightheight = height(root->right);

	return (leftheight > rightheight) ? leftheight + 1 : rightheight + 1;
		
}

int BST::longestpath(BSTNode * root)
{
	while (root!=0)
	{
		if (root->left == NULL || root->right == NULL)
		{
			if (root->left)
				root = root->left;
			else 
				root = root->right;
		}
		if (root->left != NULL && root->right != NULL)
			break;
	}
	
	if (root == 0)
		return 0;
	else	
		return (height(root->left) + height(root->right)) + 2;
	
}

void BST::mirror(BSTNode* root)
{
	BSTNode *temp = NULL;
	if (root == NULL)
		return;
	else
	{
		mirror(root->left);
		mirror(root->right);
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;

	}
}

void BST::print_roottoleaf(BSTNode * root)
{
	if (root == NULL)
		return;
	
		vect.push_back(root);

		if (root->left == NULL && root->right == NULL)
		{
			for (int i = 0; i < vect.size(); i++)
				std::cout << (vect[i])->value;

			std::cout << std::endl;
		}
		
		print_roottoleaf(root->left);
		print_roottoleaf(root->right);
		vect.pop_back();
	
}

BSTNode::BSTNode()
{
	value = 0;
	left = NULL;
	right = NULL;
	goleft = 0;
}

BSTNode::BSTNode(int val)
{
	value = val;
}

linkedlist::linkedlist()
{
	head = NULL;
	tail = NULL;
}
