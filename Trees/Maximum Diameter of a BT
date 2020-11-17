//The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
#include <iostream>
using namespace std;

class treenode
{
	int data;
	treenode* left;
	treenode* right;
public:
	treenode(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	treenode* buildTree() {
		int data;
		cin>>data;

		if(data == -1)
			return NULL;

		treenode* root = new treenode(data);
		root->left = buildTree();
		root->right = buildTree();
		return root;
	}

	int maxNoOfNodes(treenode* root) {
		if(root == NULL)
			return 0;

		return max(maxNoOfNodes(root->left),maxNoOfNodes(root->right)) + 1;
	}

	int maxDiameter(treenode* root) {
		if(root == NULL)
			return 0;

		int leftMaxDiameter = maxDiameter(root->left);
		int rightMaxDiameter = maxDiameter(root->right);
		int diameterIncludingRoot = 1 + maxNoOfNodes(root->left) + maxNoOfNodes(root->right);
		return max(diameterIncludingRoot,max(leftMaxDiameter,rightMaxDiameter));
	}
};

int main() {
	treenode* root = NULL;
	root = root->buildTree();
	cout<<"Maximum Diameter in this tree is: "<<root->maxDiameter(root)<<endl;

	return 0;
}
