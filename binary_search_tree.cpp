#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int FASTIO = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class bst
{
	private:
		struct node{
			int key;
			node* left;
			node* right;
		};

		node* root;

		void addLeafPrivate(int key, node* ptr){
			if (root == nullptr){
				root = createLeaf(key);
			} else if (key < ptr->key) { 
				if (ptr->left != nullptr){
					addLeafPrivate(key, ptr->left);
				} else{
					ptr->left = createLeaf(key);
				}
			} else if (key > ptr->key){
				if (ptr->right != nullptr){
					addLeafPrivate(key, ptr->right);
				} else{
					ptr->right = createLeaf(key);
				}
			}
			else{
				cout << "The key" << key << "has already been added to the tree" << '\n';
			}
		}
		
		void printInOrderPrivate(node* ptr){
			if (root != nullptr){
				//step 1
				if (ptr->left != nullptr){
					printInOrderPrivate(ptr->left);
				}
				//step 2
				cout << ptr->key << ' ';
				//step 3
				if (ptr->right != nullptr){
					printInOrderPrivate(ptr->right);	
				}

			} else{
				cout << "The tree is empty\n";
			}
			
		}

	public:
		bst() { root  = nullptr; }
			
		node* createLeaf(int key){
			node* n = new node;	
			n->key = key;
			n->left = nullptr;
			n->right = nullptr;
			return n;
		}

		void addLeaf(int key){
			addLeafPrivate(key, root);	
		}
		void printInOrder(){
			printInOrderPrivate(root);
		}


};




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> treeKeys{50, 76, 21, 4, 32, 64, 15, 52, 14 ,100, 83, 2, 3, 70, 87, 80};
	bst myTree;

	cout << "Printing the tree in order before adding numbers\n";
	myTree.printInOrder();
	cout << "Printing the tree in order after adding numbers\n";
	for(int& x : treeKeys) myTree.addLeaf(x);
//myTree.printInOrder();
	myTree.addLeaf(10);
	myTree.printInOrder();


}
