#include "BinaryTree.h"
#include "M_ary.h"
int main()
{
//	BST b;
//	
//	std::vector<BSTNode*> vec;
//	std::vector<int> resultvector;
//	std::vector<int> resultvector2;
//	
//	b.insert(3);
//	b.insert(2); 
//	b.insert(5); 
//	b.insert(1);
//	b.insert(6); 
//	b.insert(4); 
//	b.insert(7);
//
//	
//	
//	b.levelordertraversal(b.getroot());
//	
//	/*------LevelOrder Print function--------*/
//	int j = 0;
//	for (int i = 0; i < levelnodes.size(); i = i++)
//	cout << levelnodes[i] << "  ";
//
//
//
//	/*for (int i = 0; i <= vec2.size()-1; i = 2 * i + 2)
//	{
//		if (i % 2 == 0)
//			std::cout << std::endl;
//		for (; j <= i; j++)
//		{
//			if (vec2[j] == 0)
//			{
//				std::cout << "-  ";
//
//			}
//			else
//				std::cout << vec2[j] << "  ";
//
//		}
//		j = i + 1;
//
//	}
//*/
///*------LevelOrder Print function--------*/
//
//	int height = 0;
//	int val=4;
//	int level = 0;
//	
///*-----------------ClockWise-----------------*/
///*
//	b.preorder_recursive(b.getroot(),true,resultvector);
//	b.preorder_recursive2(b.getroot(), false, resultvector2);
//
//	for (int i = resultvector2.size() - 2; i >= 0; i--)
//	{
//		resultvector.push_back(resultvector2[i]);
//	}
//	for (int i = 0; i < resultvector.size() ; i++)
//	{
//		std::cout << resultvector[i];
//	}
//	std::cout << std::endl;
//	
//*/
///*-----------------ClockWise-----------------*/
//
//	/*
//	b.inorder_iterative_usingvector(b.getroot());
//	std::cout << std::endl;
//
//   
//	b.preorder_iterative_withoutvector(b.getroot());
//	std::cout << std::endl;
//
//	b.inorder_iterative_withoutvector(b.getroot());
//	std::cout << std::endl;
//	
//	std::cout<<b.size(b.getroot())<<std::endl;
//
//	std::cout << b.height(b.getroot()) << std::endl;
//	
//
//	b.print_roottoleaf(b.getroot());
//
//	b.mirror(b.getroot());
//
//	b.inorder_iterative_withoutvector(b.getroot());
//	std::cout << std::endl;
//	*/
//
//	/*
//	BSTNode* temp = NULL;
//	b.deepest_leftnode(b.getroot(), level, false, &height, &temp);
//	std::cout << temp->value;
//	std::cout << std::endl;
//	*/
//	std::cout << height << "---" << level;
//	
//	std::cout << b.longestpath(b.getroot());
//	std::cout << (b.deepest_leafnode(b.getroot()))->value;	
//	b.findancestor(b.getroot(), &val);
//	b.deleteanode(b.getroot(), 3);
//	b.inorder_iterative_withoutvector(b.getroot());
//

m_arynode* root = new m_arynode("CEO");
m_arynode* mgr1 = new m_arynode("mgr1");
m_arynode* mgr2 = new m_arynode("mgr2");
m_arynode* mgr3 = new m_arynode("mgr3");
root->l1 = mgr1;
root->l2 = mgr2;
root->l3 = mgr3;

m_arynode* sup1 = new m_arynode("sup1");
m_arynode* sup2 = new m_arynode("sup2");
mgr2->l1 = sup1;
mgr2->l2 = sup2;
m_arynode* emp1 = new m_arynode("emp1");
m_arynode* emp2 = new m_arynode("emp2");
sup2->l1 = emp1;
sup2->l2 = emp2;

m_arynodeclass m_ary;
//m_ary.display_tree(root);

m_ary.preorder(root);



	std::cout<<std::endl;
	system("pause");
	return 0;
}