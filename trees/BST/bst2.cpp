//  * Average case Time Complexity: O(log(n))
//      * Worst case Time Complexity: O(n)
    
#include <iostream>
#include <cmath>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const int& data): 
    data(data), left(nullptr), right(nullptr)
    {}
};
TreeNode* find(TreeNode* root, const int& data){
    //  * Find the node that contains the given data and return that node
    if(root == NULL)
    { cout<< "Cannot find the data"; 
    return NULL;
    }
    else if(root->data == data) { 
        return root; 
    }
    else if(root->data < data)  { 
        return find(root->right, data); 
    }
    else { 
        return find(root->left, data); 
    }
}

void Insert(TreeNode*& root, const int& data){
    //  * Create and Insert the node in the appropriate place of the tree
    
    if(root == NULL)
    { root = new TreeNode(data); }
    else if(root->data == data) 
    { cout<<"The node already exist. Duplicates not allowed"; 
    }
    else if(root->data < data)  { 
        Insert(root->right, data); }
    else{ 
        Insert(root->left, data); }
}


bool isfull(TreeNode* root){
    /**
     * Check if a binary tree is full or not
     * A binary tree is full when every node in the 
     */
    if(root == nullptr){ return true; }
    if(root->left == NULL && root->right ==  NULL) 
        { return true; }
    if((root->left != NULL && root->right != NULL) )  
    { return isfull(root->left) && isfull(root->right); }
    return false;
}

int depth(TreeNode* root){
    /**
     * Find the depth of the left most tree.
     * Here the depth of the left most tree is foun
     */

    int d = 0;
    while(root != NULL){
            root = root->left;
            d++;
    }
    return d;
}


bool perfect_recursive(TreeNode* cur, int depth, int level = 0){
    /** A Recursive strategy to check if a tree is perfect or not
     * A binary tree is perfect if when all the inner node's
     * has two children and the all the leaf node's are at the
     * same level*/

    if(cur == NULL)
        { return true; }
    if(cur->left == NULL && cur->right == NULL) { 
        return depth == level; 
        }
    if(cur->left != NULL && cur->right != NULL) {
            return perfect_recursive(cur->left, depth, level+1) && perfect_recursive(cur->right, depth, level+1);
    }
    return false;
}

int count_nodes(TreeNode* cur){
    if(cur != NULL){ 
        return 1 + count_nodes(cur->left) + count_nodes(cur->right); 
        }
    return 0;
}


int height(TreeNode* cur){
    /** Find the height of the tree */
    if(cur != nullptr){ 
        return 1 + max(height(cur->left),  height(cur->right)); 
    }
    return 0;
}

bool perfect(TreeNode* cur){
    /**
     * Knowing the height and the number of node's of
     * the tree we can find whether the tree is perfect or not
     * * A binary tree is perfect if when all the inner node's
     * has two children and the all the leaf node's are at the
     * same level.
     */
    int h = height(cur) - 1;
    int N = count_nodes(cur);
    if(N == pow(2, h+1) - 1) { return true; }
    return false;
}

bool isperfect(TreeNode* root){
        //if(perfect(root))                           { return true; }
 if(perfect_recursive(root, depth(root) - 1)) 
 { return true; }
    return false;
}

void leaf_nodes(TreeNode* root) //Print all leafnode in BST
{ 
   if (!root) 
       return; 

   if (root->left==NULL && root->right==NULL) 
   { 
       std::cout<<root->data<< " "; 
       return; 
   } 

   if (root->left) 
       leaf_nodes(root->left); 

   if (root->right) 
       leaf_nodes(root->right); 
} 

TreeNode* f_min(TreeNode* root) //Find Minimum element from root
{ 
    if(root==NULL)
    {
        cout<<"No value present in the tree"<<endl;
        return NULL;
    }
    TreeNode* p=root; 
    while(p->left!=NULL) 
    { 
        p=p->left; 
    } 
    return p;
} 

TreeNode* f_max(TreeNode* root) //Find Maximum element from root
{ 
    if(root==NULL)
    {
        cout<<"No value present in the tree"<<endl;
        return NULL;
    }
    TreeNode* p=root; 
    while(p->right!=NULL) 
    { 
        p=p->right; 
    }
    return p;
} 

TreeNode* bstdelete(TreeNode* root, int x) 
{ 
    TreeNode* m; 
    if(root==NULL) 
    { 
        cout<<"NOT FOUND!!"; 
        return root; 
    } 
    if(x < root->data) 
    { 
        root->left=bstdelete(root->left,x); 
        return root; 
    } 
    if(x>root->data) 
    { 
        root->right=bstdelete(root->right,x); 
        return root; 
    } 
    if(root->left==NULL && root->right==NULL) 
    { 
        m=root; 
        delete m; 
        return (NULL); 
    } 
    else if(root->left==NULL) 
    { 
        m=root; 
        root=root->right; 
        delete m; 
        return (root); 
    } 
    else if(root->right==NULL) 
    { 
        m=root; 
        root=root->left; 
        delete m; 
        return (root); 
    } 
    m=f_min(root->right); 
    root->data=m->data; 
    root->right=bstdelete(root->right, m->data); 
    return (root); 
}


void print(TreeNode* root){
    // inorder
    if(root != NULL){
        print(root->left);
        cout << root->data << " ";
        print(root->right);
    }   
}

void free(TreeNode* root){
        if(root != nullptr){
        free(root->left);
        free(root->right);
        delete root;
        root = nullptr;
    }
}

int main(){
    TreeNode* root = NULL;

    Insert(root, 37);
    Insert(root, 19);
    Insert(root, 4);
    Insert(root, 22);
    Insert(root, 51);
    Insert(root, 55);
    Insert(root, 42);
    Insert(root, 20);
    Insert(root, 11);
    Insert(root, 2);
    
    print(root);

    TreeNode* n = find(root, 19);
    cout << "\nValue of n: " << n->data <<endl;

    if(isfull(root)) { 
        cout << "The binary tree is FULL" <<endl; }
    else { 
        cout << "The binary tree is not FULL" <<endl;
    }

    if(isperfect(root)) { 
        cout << "The binary tree is PERFECT" << endl; 
        }
    else { 
        cout << "The binary tree is not PERFECT" << endl; }

    cout << "Leaf Nodes present in the binary tree are : ";
    leaf_nodes(root);
    cout<<endl;
    
    n = f_max(root);
    if(n)
    {
        cout<<"Maximum Value  : "<<n->data<<endl;
    }

    n=f_min(root);
    if(n)
    {
        cout<<"Minimum Value : "<<n->data<<endl;
    }

    root = bstdelete(root, 19);
    cout<<"Binary search Tree after Deletion is : "<<endl;;
    print(root);

    /* 
    Tree structure
            37
           /  \
          19  51
         / \   / \
        4  22 42 55
       /\   /   
      2 11  20
    OUTPUT:
     2 4 11 19 20 22 37 42 51 55 
     Value of n: 19
     The binary tree is not FULL
     The binary tree is not PERFECT
     Leaf Nodes present in the binary tree are : 2 11 20 42 55 
     Maximum Value Present in the tree is : 55
     Minimum Value Present in the tree is : 2
     Binary search Tree after Deletion is : 
     2 4 11 20 22 37 42 51 55 
    
     Tree structure after deletion
            37
           /  \
          11  51
         / \   / \
        4  22 42 55
       /   /   
      2   20
    
    */

    // free the memory
    free(root);
    return 0;
}