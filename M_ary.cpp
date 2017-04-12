#include "M_ary.h"
#include <sstream>

void m_arynodeclass::display_tree(m_arynode * root)
{
	std::ostringstream out;
	if (root == NULL)
		return;
	else
	{
		container.push(root);
		while (container.size() != 0)
		{
			m_arynode* temp = container.front();
			container.pop();
			//if(temp!=NULL)
			std::cout << temp->name;
			if (temp->l1!=NULL) {
				container.push(temp->l1);
			}
			if (temp->l2 != NULL) {
				container.push(temp->l2);
			}
			if (temp->l3 != NULL) {
				container.push(temp->l3);
			}
			std::cout << std::endl;
		}
		
	}
}

void m_arynodeclass::preorder(m_arynode * root)
{
	if (root == NULL)
		return;
	std::cout << root->name << std::endl;
	preorder(root->l1);
	preorder(root->l2);
	preorder(root->l3);
	

}



//std::ostream & operator<<(std::ostream & os,std::string name)
//{
//	// TODO: insert return statement here
//	os << name;
//	return os;	
//}


