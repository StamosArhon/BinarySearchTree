/*========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000
#define MAX_EL 3
#define MAX_LINE_SIZE 1000

/*========================================================================================================*/

/*--------Binary Search Tree Struct Definition--------*/
struct binarySearchTreeNode
{
	float data;
	struct binarySearchTreeNode* left;
	struct binarySearchTreeNode* right;
};
/*--------Binary Search Tree Struct Definition--------*/

/*========================================================================================================*/

/*----------Global Variables----------*/
struct binarySearchTreeNode* root = NULL; //Initialize the tree as blank
struct binarySearchTreeNode coordinates[MAX];
/*----------Global Variables----------*/

/*========================================================================================================*/

/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/
struct binarySearchTreeNode* CreateNode(float data)
{
	struct binarySearchTreeNode* newNode = (struct binarySearchTreeNode*)malloc(sizeof(struct binarySearchTreeNode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/

/*========================================================================================================*/

/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/
struct binarySearchTreeNode* InsertData(struct binarySearchTreeNode* root, float data)
{
	if (root == NULL) //If the root is blank create a new node
	{
		root = CreateNode(data);
	}

	else if (data <= root->data) //If the inserted value is smaller than the root, place it on the left child of that tree
	{
		root->left = InsertData(root->left, data);
	}

	else //If the inserted value is higher than the root, place it on the right child of that tree
	{
		root->right = InsertData(root->right, data);
	}

	return root;
}
/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/

/*========================================================================================================*/

/*----- TreeSearch: A function to help us locate whether or not a specific value is present -----*/
/*----- in our binary tree or nor, generating the appropriate message and exit in response  -----*/
void TreeSearch(struct binarySearchTreeNode* root, float value_search)
{
	if (root == NULL) //If the root is blank print that the value was not found and exit with -1
	{
		printf ("\n+=================================+");
		printf ("\n| Value not found! Terminating... |");
		printf ("\n+=================================+");
		exit(-1);
	}

	else if (root->data == value_search) //If the data element is equal to the value we are searching for print that the value was found and exit with 0
	{
		printf ("\n+====================================+");
		printf ("\n| Value found! Exiting succefully... |");
		printf ("\n+====================================+");
		exit(0);
	}

	else if (value_search <= root->data) //If the requested value is smaller than the root, search for it on the left child of that tree
	{
		return TreeSearch(root->left, value_search);
	}

	else
	{
		return TreeSearch(root->right, value_search); //If the requested value is higher than the root, search for it on the right child of that tree
	}
}
/*----- TreeSearch: A function to help us locate whether or not a specific value is present -----*/
/*----- in our binary tree or nor, generating the appropriate message and exit in response  -----*/

/*========================================================================================================*/

/*----The main function of the program that makes the initial calls to the other functions----*/
int main()
{
	char user_input;
	float value_search;
	int i;
	float input_value;
	srand(time(NULL));

	printf ("Input_value:\t");

	for (i=0; i<10; i++)
	{
		input_value = rand()%100 + 2.3;
		printf ("%.1f\t", input_value);
		root = InsertData(root, input_value);
	}

	/*root = InsertData(root, 21.0);
	root = InsertData(root, 23.0);
	root = InsertData(root, 10.0);
	root = InsertData(root, 4.0);*/


	printf ("\nDo you want to search for a value?");
	scanf ("%c", &user_input);
	fflush(stdin);

	if (user_input == 'y'||user_input == 'Y')
	{
			printf ("\nEnter the value you want to search: ");
			scanf("%f", &value_search);
			fflush(stdin);
			TreeSearch(root, value_search);
	}
}


/*----The main function of the program that makes the initial calls to the other functions----*/

/*========================================================================================================*/
																						/*END OF FILE*/
