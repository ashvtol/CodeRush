/*

Mirror Image of a Binary Tree.



         5
       /   \
      4     3       
    /  \   /  \
   2    1  9   10 

   In order traversal: 2 4 1 5 9 3 10

        |
        |
        v

         5
       /   \
      3     4       
    /  \   /  \
   10   9  1   2 
   
    In order traversal: 10 3 9 5 1 4 2



*/





#include<iostream>
#include<stdlib.h>
#define sn struct node
#define sc(x) scanf("%d",&x)
#define p(x) printf(x)
#define br printf("\n")

sn
{
    int data;
    sn*left ;
    sn*right;
};

sn *root = NULL;

sn* insert(int data)
{
    sn *r = (sn*)malloc(sizeof(sn));
    r->data = data;
    r->left = NULL;
    r->right = NULL;

    return r;
}

void ino(sn*r)
{
    if(r==NULL)
        return;
    ino(r->left);
    printf("%d ",r->data);
    ino(r->right);
}

int height(sn* r)
{
    if(r==NULL)
        return 0;
    int lh = height(r->left) + 1;
    int rh = height(r->right) + 1;

    return (lh>rh ? lh: rh);
}

int nodes(sn *r)
{
    if(r==NULL)
        return 0;
    return(nodes(r->left) + 1 + nodes(r->right));
}

void mirror(sn* r)
{
    if(r->left!=NULL)
        mirror(r->left);
    if(r->right!=NULL)
        mirror(r->right);
    sn *t = r->left;
    r->left = r->right;
    r->right = t;

}

int main()
{
    root = insert(5);
    root->left = insert(4);
    root->right = insert(3);
    root->left->left = insert(2);
    root->left->right = insert(1);
    root->right->left = insert(9);
    root->right->right = insert(10);

    printf("Height of the tree is %d\n",height(root));
    printf("Number of nodes in the tree is %d\n",nodes(root));

    ino(root); br;

    mirror(root);
    ino(root); br;

    

}
