#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

node *insertbst(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (val < root->data)
    {
        root->left = insertbst(root->left, val);
    }
    else
    {
        root->right = insertbst(root->right, val);
    }

    return root;
}

node *searchinbst(node *root, int key)
{
    if (root == NULL)
    {

        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchinbst(root->left, key);
    }

    return searchinbst(root->right, key);
}

node *inordersucc(node *root)
{
    node *curr = root;

    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

node *deleteinbst(node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteinbst(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteinbst(root->right, key);
    }
    else
    {
        if (root->right == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right, temp->data);
    }

    return root;
}
void printlevel(node *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *n = q.front();
        q.pop();
        if (n != NULL)
        {
            cout << n->data << " ";
            if (n->left)
            {
                q.push(n->left);
            }
            if (n->right)
            {
                q.push(n->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int calcheight(node *root)
{
    if (root == NULL)
        return 0;

    return max(calcheight(root->left), calcheight(root->right)) + 1;
}

int main()
{
    node *root = NULL;
    root = insertbst(root, 5);
    insertbst(root, 1);
    insertbst(root, 3);
    insertbst(root, 4);
    insertbst(root, 2);
    insertbst(root, 7);

    inorder(root);
    cout << "\n";
    if (searchinbst(root, 10) == NULL)
    {
        cout << "not found";
    }
    else
    {
        cout << "found";
    }
    cout << "\n";
    deleteinbst(root, 5);
    printlevel(root);
    cout << "\n";
    preorder(root);
    cout << "\n";
    inorder(root);
    cout << "\n";
    postorder(root);
    cout << "\n";
    cout << calcheight(root);
}