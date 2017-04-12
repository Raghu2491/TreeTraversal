#include<iostream>
#include<queue>
#define _OSTREAM_

struct m_arynode
{
public:
	std::string name;
	m_arynode *l1;
	m_arynode *l2;
	m_arynode *l3;
	m_arynode() {}
	m_arynode(std::string val) :name(val)
	{
		l1 = NULL;
		l2 = NULL;
		l3 = NULL;
	}
};

class m_arynodeclass :m_arynode
{
public:
	m_arynodeclass()
	{
		root = NULL;
	}
	void display_tree(m_arynode *root);
	std::queue<m_arynode*> container;
	std::vector<m_arynode*> l1;
	std::vector<m_arynode*> l2;
	std::vector<m_arynode*> l3;
	//friend _OSTREAM_& operator<<(_OSTREAM_&os, const m_arynodeclass* node);
	//friend std::ostream& operator<<(std::ostream& os, const std::string name);
	void preorder(m_arynode* root);
	
private:
	m_arynode *root;

};
