// Creator: Simba Kutadzaushe
// Date: 11/20/2023
// Question 3:


//  Given the ordered list of edges of an ordered, rooted tree, list its vertices in preorder, inorder, and postorder.
//Write the program in C++ that accomplishes the statement above. The input is a string of comma-separated integers, where each integer represents a 
// vertex. The first integer is the root of the tree. The remaining integers are the vertices of the tree in preorder. The output is three lines of 
// comma-separated integers, where each integer represents a vertex. The first line is the vertices of the tree in preorder. The second line is the vertices 
// of the tree in inorder. The third line is the vertices of the tree in postorder.


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


class Solution {

	public:
		vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode* node = s.top();
			s.pop();
			result.push_back(node->val);
			if (node->right) s.push(node->right);
			if (node->left) s.push(node->left);
		}
		return result;
	}

		vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode*> s;
		TreeNode* node = root;
		while (!s.empty() || node) {
			if (node) {
				s.push(node);
				node = node->left;
			}
			else {
				node = s.top();
				s.pop();
				result.push_back(node->val);
				node = node->right;
			}
		}
		return result;
	}

		vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode* node = s.top();
			s.pop();
			result.push_back(node->val);
			if (node->left) s.push(node->left);
			if (node->right) s.push(node->right);
		}
		reverse(result.begin(), result.end());
		return result;
	}

		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty()) return nullptr;
		int n = preorder.size();
		return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1);
	}

		TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd) return nullptr;
		int rootVal = preorder[preStart];
		int rootIndex = 0;
		for (int i = inStart; i <= inEnd; ++i) {
			if (inorder[i] == rootVal) {
				rootIndex = i;
				break;
			}
		}
		int len =
			rootIndex - inStart;  // number of nodes in left subtree
		TreeNode* root = new TreeNode(rootVal);
		root->left = buildTreeHelper(preorder, preStart + 1, preStart + len, inorder, inStart, rootIndex - 1);

		root->right = buildTreeHelper(preorder, preStart + len + 1, preEnd, inorder, rootIndex + 1, inEnd);
		return root;
	}
};

void printVector(vector<int>& v) {
	for (auto& i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void printTree(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	Solution sol;
	string s = "1,2,3,4,5,6,7,8,9";
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->right->right->left = new TreeNode(9);
	printTree(root);
	cout << endl;
	return 0;
}
































































































































/*
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

	
class Solution {};

void printVector(vector<int>& v) {
	for (auto& i : v) {
		cout << i << " ";
	}
	cout << endl;
}

void printTree(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

int main() {
	Solution sol;
	string s = "1,2,3,4,5,6,7,8,9";
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->right->right->left = new TreeNode(9);
	printTree(root);
	cout << endl;
	return 0;
}
*/



