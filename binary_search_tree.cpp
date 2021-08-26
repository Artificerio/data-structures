#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



const int FASTIO = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
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

		node* returnNodePrivate(int key, node* ptr){
			if (ptr != nullptr){
				if (ptr-> key == key){
					return ptr;
				}
				else{
					if(key < ptr->key){
						return returnNodePrivate(key, ptr->left);
					}
					if(key > ptr->key){
						return returnNodePrivate(key, ptr->right);
					}
				}
			}
			else{
				return nullptr;
			}
		}
		int findSmallestPrivate(node* ptr){
			if (root == nullptr){
				cout << "The tree is empty\n";
				return -1000;
			}
			else{
				if (ptr->left != nullptr){
					return findSmallestPrivate(ptr->left);
				}
				else{
					return ptr->key;
				}
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
		node* returnNode(int key){
			return returnNodePrivate(key, root);
		}
		int returnRootKey(){
			if (root != nullptr){
				return root->key;
			}
			else{
				return -1000;
			}
		}
		void PrintChildren(int key){
			node* ptr = returnNode(key);

			if (ptr != nullptr){
				cout << "Parent Node = " << ptr->key << '\n';

				ptr->left == nullptr ? 
					cout << "Left child is NULL\n":
					cout << "Left child is " << ptr->left->key << '\n';

				ptr->right == nullptr ? 
					cout << "Right child is NULL\n":
					cout << "Right child is " << ptr->right->key << '\n';
			}
			else{
				cout << "Key " << key << "is not in the tree\n";
			}
		}
		int findSmallest(){
			return findSmallestPrivate(root);
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
	myTree.PrintChildren(myTree.returnRootKey());
	cout << myTree.findSmallest() << '\n';


}
