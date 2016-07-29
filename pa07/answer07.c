#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "answer07.h"

/*
 * Construct one BusinessNode. You need to allocate memory for this node first.
 *
 * The caller needs to make sure to use strdup(...) for the arguments, do not
 * use strdup(...) inside of this function.
 *
 * stars: the stars of this business
 * name: name of this business
 * address: address of this business
 */
BusinessNode *create_node(char * stars, char * name, char * address)
{
	BusinessNode *ptr = malloc(sizeof(BusinessNode));
	ptr -> name = name;
	ptr -> stars = stars;
	ptr -> address = address;

	ptr -> left = NULL;
	ptr -> right = NULL;

	return ptr;
}


/* Insert a node into a BST. Remember to order the nodes in the BST based on the BusinessNode name.
 * Primarily used in load_tree_from_file(). Return a
 * pointer to the root of the BST.
 */
BusinessNode *tree_insert(BusinessNode * node, BusinessNode * root)
{
	if (node == NULL) return root;
  if (root == NULL) return node;
	else
	{
		int move = strcmp(node->name, root->name);
		if(move <= 0)
		{
			root ->left = tree_insert(node,root->left);
		}
		else if(move > 0)
		{
			root ->right = tree_insert(node, root ->right);
		}
	}
	return root;

}

/* Parse a .tsv file line by line, create a BusinessNode for each entry, and
 * enter that node into a new BST. Return a pointer to the root of the BST.
 *
 * The explode(...) function from PA03 may be useful for breaking up a lines
 * into seperate fields.
 */
BusinessNode *load_tree_from_file(char * filename)
{
	FILE *ptr = fopen(filename,"r");
	if (ptr == NULL) return NULL;
	// Normal file structure is: stars, name, address
	char stars[3]; // there are only 4 char in stars.
	char name[300];
	char address[300];

	BusinessNode *root;
	BusinessNode *node;

	//Cool way to use fscanf, YOLO SWAG! made my work easy!!
	//4.0	Pine Cone Restaurant	6162 US Highway 51, De Forest, WI 53532
	fscanf(ptr,"%[^\t]\t%[^\t]\t%[^\n]\n",stars,name,address);
	//creating a new node
	root = create_node(strdup(stars),strdup(name),strdup(address));//using strdup to make a copy

	/*
	Keep on reading the file until the end is reached.
	1. create a new node for each line in .tsv file
	2. Since we have root, insert new node to the root and so on
	*/
	int end = feof(ptr);
	while(!end)
	{
		fscanf(ptr,"%[^\t]\t%[^\t]\t%[^\n]\n",stars,name,address);
		node = create_node(strdup(stars),strdup(name),strdup(address));
		root = tree_insert(node,root);
		end = feof(ptr);
	}
	fclose(ptr);// close the file
	return root;
}


/* Search a BusinessNode BST for the node with the name 'name'. Returns
 * pointer to the node with a match.
 *
 * If there is no match, return NULL.
 */
BusinessNode *tree_search_name(char * name, BusinessNode * root)
{
	if(root == NULL) return NULL; //Nothing found
	int move = strcmp(name, (root->name));
	if(move == 0) return root;
	if(move < 0) return tree_search_name(name,root->left);
	return tree_search_name(name, root->right);
}

/* Print out a single node: name, address, and stars
 * The format can be similar to this:
 *
 * Country Cafe
 * ============
 * Stars:
 *    3.5
 * Address:
 *    1030 Emerald Ter, Sun Prairie, WI 53590
 *
 * This function is not graded, but it could come in very handful while
 * debugging this assignment.
 * Refrence taken from Prof Lu's book
 */
void print_node(BusinessNode * node)
{
	if (node == NULL) return;
	printf("\n%s\n",node->name);
	printf("========\n");
	printf("Stars:\n  %s\n",node->stars);
	printf("Address:\n  %s\n",node->address);
}

/* Print the entire tree, starting from the root. Like the print_node(...)
 * function, this is NOT graded.
 * Refrence taken from Prof Lu's book
 */
void print_tree(BusinessNode * tree)
{
  if(tree == NULL) return;
  print_node(tree);
  print_tree(tree->left);
  print_tree(tree->right);
}

/* Deallocate all of the memory used by a BusinessNode BST, without memory
 * leaks.
 */
void destroy_tree(BusinessNode * root)
{
	if (root == NULL)
	{
		return;
	}
	destroy_tree(root -> left);
	destroy_tree(root -> right);
	free(root -> address);
	free(root -> name);
	free(root -> stars);
	free(root);
}
