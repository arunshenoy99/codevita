#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

void inorder(Node *root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

Node *insert(Node *root, int data)
{
    if(root == NULL)
    {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    else if (data < (root->data))
    {
        root->left = insert(root->left, data);
    }
    else if (data > (root->data)) 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return root;
    }
    else if (data < root->data)
    {
        search(root->left, data);
    }
    else if (data > root->data)
    {
        search(root->right, data);
    }
    else
    {
        printf("Element found is %d\n", root->data);
        return root;
    }
}

Node *find_min(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left)
    {
        return find_min(root->left);
    }
    else
    {
        return root;
    }
    
}

Node *delete(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        if (root->left && root->right)
        {
            Node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
        else
        {
            Node *temp = root;
            if (root->left == NULL)
            {
                root = root->right;
            }
            else if (root->right == NULL)
            {
                root = root->left;
            }
            free(temp);
        } 
    }
    return root;
}

int main(void)
{
    int ch,n,i,data;
    Node *root = NULL;
    while(ch != 5)
    {
        printf("\nBST Operations\n");
        printf("1.Insert elements\n");
        printf("2.Search element\n");
        printf("3.Delete Element\n");
        printf("4.Display the tree(Inorder)\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the number of elements:");
                scanf("%d", &n);
                for(i=0;i<n;i++)
                {
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;
            case 2:
                printf("Enter the element to search:");
                scanf("%d", &data);
                search(root, data);
                break;
            case 3:
                printf("Enter the element to be deleted:");
                scanf("%d", &data);
                root = delete(root,  data);
                break;
            case 4:
                inorder(root);
                break;
        }
    }
}