#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
class node
{
    public:
        int data;
          node *left;
          node *right;
};
node *tree;

void create_tree( node *);
 node *insertElement( node *, int);
void preorderTraversal( node *);
void inorderTraversal(node *);
void postorderTraversal(node *);
 node *findSmallestElement( node *);
 node *findLargestElement( node *);
 node *deleteElement( node *, int);
 node *mirrorImage( node *);
int totalNodes( node *);
int totalExternalNodes( node *);
int totalInternalNodes(node *);
int Height( node *);
node *deleteTree( node *);


int main()
{
    int option, val;
    node *ptr;
    create_tree(tree);
    do
    {
    cout<<"\n ******MAIN MENU******* \n";
    cout<<"\n 1. Insert Element";
    cout<<"\n 2. Preorder Traversal";
    cout<<"\n 3. Inorder Traversal";
    cout<<"\n 4. Postorder Traversal";
    cout<<"\n 5. Find the smallest element";
    cout<<"\n 6. Find the largest element";
    cout<<"\n 7. Delete an element";
    cout<<"\n 8. Count the total number of nodes";
    cout<<"\n 9. Count the total number of external nodes";
    cout<<"\n 10. Count the total number of internal nodes";
    cout<<"\n 11. Determine the height of the tree";
    cout<<"\n 12. Find the mirror image of the tree";
    cout<<"\n 13. Delete the tree";
    cout<<"\n 14. Exit";
    cout<<"\n\n Enter your option : ";
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        cout<<"\n Enter the value of the new node : ";
        scanf("%d", &val);
        tree = insertElement(tree, val);
        break;
        case 2:
        cout<<"\n The elements of the tree are : \n";
        preorderTraversal(tree);
        break;
        case 3:
        cout<<"\n The elements of the tree are : \n";
        inorderTraversal(tree);
        break;
        case 4:
        cout<<"\n The elements of the tree are : \n";
        postorderTraversal(tree);
        break;
        case 5:
        ptr = findSmallestElement(tree);
        cout<<"\n Smallest element is : "<< ptr->data;
        break;
        case 6:
        ptr = findLargestElement(tree);
        cout<<"\n Largest element is : " << ptr->data;
        break;
        case 7:
        cout<<"\n Enter the element to be deleted : ";
        scanf("%d", &val);
        tree = deleteElement(tree, val);
        break;
        case 8:
        cout<<"\n Total no. of nodes = "<< totalNodes(tree);
        break;
        case 9:
        cout<<"\n Total no. of external nodes = "<<
        totalExternalNodes(tree);
        break;
        case 10:
        cout<<"\n Total no. of internal nodes = " <<totalInternalNodes(tree);
        break;
        case 11:
        cout<<"\n The height of the tree = "<<Height(tree);
        break;
        case 12:
        tree = mirrorImage(tree);
        break;
        case 13:
        tree = deleteTree(tree);
        break;
        }
    }while(option!=14);
    return 0;
}
void create_tree( node *tree)
{
    tree = NULL;
}
node *insertElement( node *tree, int val)
{
    node *ptr, *nodeptr, *parentptr;
    ptr = new node; //(  node*)malloc(sizeof(  node)); 
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
    parentptr=NULL;
    nodeptr=tree;
    while(nodeptr!=NULL)
    {
    parentptr=nodeptr;
    if(val<nodeptr->data)
        nodeptr=nodeptr->left;
    else
        nodeptr = nodeptr->right;
    }
    if(val<parentptr->data)
        parentptr->left = ptr;
    else
        parentptr->right = ptr;
    }
    return tree;
}
void preorderTraversal(  node *tree)
{
    if(tree != NULL)
    {
        cout<<"\t"<< tree->data;
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}
void inorderTraversal(  node *tree)
{
    if(tree != NULL)
    {
        inorderTraversal(tree->left);
        cout<<"\t"<< tree->data;
        inorderTraversal(tree->right);
    }
}
void postorderTraversal(  node *tree)
{
    if(tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        cout<<"\t"<< tree->data;
    }
}
node *findSmallestElement(  node *tree)
{
    if( (tree == NULL) || (tree->left == NULL))
        return tree;
    else
        return findSmallestElement(tree ->left);
}
node *findLargestElement(  node *tree)
{
    if( (tree == NULL) || (tree->right == NULL))
        return tree;
    else
        return findLargestElement(tree->right);
}
node *deleteElement(  node *tree, int val)
{
    node *cur, *parent, *suc, *psuc, *ptr;
    if(tree->left==NULL)
    {
        cout<<"\n The tree is empty ";
        return(tree);
    }
    parent = tree;
    cur = tree->left;
    while(cur!=NULL && val!= cur->data)
    {
        parent = cur;
        cur = (val<cur->data)? cur->left:cur->right;
    }
    if(cur == NULL)
    {
        cout<<"\n The value to be deleted is not present in the tree";
        return(tree);
    }
    if(cur->left == NULL)
        ptr = cur->right;
    else if(cur->right == NULL)
        ptr = cur->left;
    else
    {
    // Find the in–order successor and its parent
        psuc = cur;
        cur = cur->left;
        while(suc->left!=NULL)
        {
            psuc = suc;
            suc = suc->left;
        }
        if(cur==psuc)
        {
        // Situation 1
            suc->left = cur->right;
        }
        else
        {
        // Situation 2
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
            ptr = suc;
    }   
    // Attach ptr to the parent node
    if(parent->left == cur)
        parent->left=ptr;
    else
        parent->right=ptr;
    delete cur;
    return tree;
}
int totalNodes(  node *tree)
{
    if(tree==NULL)
        return 0;
    else
        return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int totalExternalNodes(  node *tree)
{
    if(tree==NULL)
        return 0;
    else if((tree->left==NULL) && (tree->right==NULL))
        return 1;
    else
        return (totalExternalNodes(tree->left) +
    totalExternalNodes(tree->right));
}
int totalInternalNodes(  node *tree)
{
    if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
        return 0;
    else
     return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}
int Height(  node *tree)
{
    int leftheight, rightheight;
    if(tree==NULL)
    return 0;
    else
    {
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
node *mirrorImage(  node *tree)
{
    node *ptr;
    if(tree!=NULL)
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr=tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}
node *deleteTree(  node *tree)
{
    if(tree!=NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        delete tree;
    }
}