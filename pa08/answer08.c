#include "answer08.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


/* charcmp is used to to compare chars for isValidState(...)
 * This function is supplied to you.
 */


int charcmp(const void * a, const void * b)
{
    return *((char*)a) - *((char*)b);
}

/* This function is supplied to you.*/


int isValidState(const char * state)
{
    int len = strlen(state);
    if(len != 16) return FALSE;
    char buffer[17];
    strcpy(buffer, state);
    qsort(buffer, len, sizeof(char), charcmp);
    const char * valid = "-123456789ABCDEF";
    if(strcmp(valid, buffer) == 0)
	return TRUE;
    return FALSE;
}

/* This function is supplied to you.*/

int isValidMoveList(const char * moves)
{
    int len = strlen(moves);
    int i;
    for(i = 0; i <  len; ++i)
	if(moves[i] != 'R' && moves[i] != 'L' &&
	   moves[i] != 'U' && moves[i] != 'D')
	    return FALSE;
    return TRUE;
}

/* This function is supplied to you.*/

void printPuzzle(const char * state)
{
    int row, col;
    for(row = 0; row < SIDELENGTH; ++row) {
	for(col = 0; col < SIDELENGTH; ++col) {
	    printf(" %c", state[row*SIDELENGTH + col]);
	}
	printf("\n");
    }
}

/* This function is supplied to you.*/

int move(char * state, char m)
{
    int dx = 0;
    int dy = 0;
    switch(m) {
    case 'U': dy = -1; break;
    case 'D': dy = 1; break;
    case 'L': dx = -1; break;
    case 'R': dx = 1; break;
    default:
	fprintf(stderr, "Invalid move '%c'!\n", m);
	return FALSE;
    }
    char * strpos = strstr(state, "-");
    if(strpos == NULL) {
	fprintf(stderr, "Invalid state '%s'!\n", state);
	return FALSE;
    }
    int pos = strpos - state;
    int row = pos / SIDELENGTH;
    int col = pos % SIDELENGTH;
    if(row + dy < 0 || row + dy >= SIDELENGTH)
	return FALSE;
    if(col + dx < 0 || col + dx >= SIDELENGTH)
	return FALSE;

    // Now we know we have a valid move...
    int target_pos = (row+dy)*SIDELENGTH + (col+dx);

    // So swap 'pos' with 'target_pos'
    state[pos] = state[target_pos];
    state[target_pos] = '-';

    return TRUE;
}

/* This function is supplied to you.*/


void processMoveList(char * state, const char * movelist)
{
    int valid = TRUE;
    int ind = 0;
    int movelist_len = strlen(movelist);
    for(ind = 0; ind < movelist_len && valid; ++ind)
	{
		if(!move(state, movelist[ind]))
		{
			valid = FALSE;
		}
    }

    if(!valid) {
		printf("I\n");
    }
	else {
		printf("%s\n", state);
    }
}

//You will need to complete the following functions (except for solve(...) and MoveTree_print(...))

MoveTree * MoveTree_create(const char * state, const char * moves)
{
	//Your code goes here
  MoveTree *newTree = malloc(sizeof(MoveTree));

	if(newTree == NULL)
	{
		fprintf(stderr, "Not able to allocate memory for MoveTree\n");
		return NULL;
	}

	newTree->state = malloc(sizeof(char)*(SIDELENGTH*SIDELENGTH+1));

	if(newTree->state == NULL)
	{
		free(newTree);
		fprintf(stderr,"Not able to allocate memory for state in MoveTree\n");
		return NULL;
	}

	strcpy(newTree->state, state);
	newTree->moves = malloc(sizeof(char)*(strlen(moves)+1));

	if(newTree->moves == NULL)
	{
		free(newTree->state);
		free(newTree);
		fprintf(stderr,"Not able to allocate memory for moves in MoveTree\n");
		return NULL;
	}

	strcpy(newTree->moves, moves);
	newTree->left = NULL;
	newTree->right = NULL;
	return newTree;
}

void MoveTree_destroy(MoveTree * node)
{
	//Your code goes here
  if(node == NULL)  return;
	free(node->state);
	free(node->moves);

  //Recursive calls
	MoveTree_destroy(node->left);
	MoveTree_destroy(node->right);
	free(node);
}

MoveTree * MoveTree_insert(MoveTree * node, const char * state, const char * moves)
{
   //Your code goes here
  if(node == NULL)  return MoveTree_create(state, moves);
	if(strcmp( state, node->state ) < 0)
	{
		node->left = MoveTree_insert(node->left, state, moves);
		return node;
	}
	else if(strcmp(state, node->state) > 0)
	{
		node->right = MoveTree_insert(node->right, state, moves);
		return node;
	}
	else
	{
		if(strlen(moves) < strlen(node->moves))
		{
			free(node->moves);
			node->moves = malloc( sizeof(char)*(strlen(moves)+1) );
			strcpy(node->moves, moves);
		}
	}
	return node;
}

MoveTree * MoveTree_find(MoveTree * node, const char * state)
{
   //Your code goes here
  if(node == NULL) return NULL; //Useless to go on!
	if(strcmp(node->state, state) == 0)  return node;
	else if(strcmp( state, node->state ) < 0)  return MoveTree_find(node->left, state);
	else return MoveTree_find(node->right, state);
}

/**
 * Print the moves in a move-tree.
 * This function is supplied to you.
 */
void MoveTree_print(MoveTree * node)
{
    if(node == NULL)
		return;
    printf("%s\n", node -> state);
    MoveTree_print(node -> left);
    MoveTree_print(node -> right);
}

/*Helper function for generateAll, you do *NOT* need to use this function but you may find it useful*/
void generateAllHelper(MoveTree * root, int n_moves, const char * state, char * movelist, int ind)
{
    //Your code goes here
  if(ind == 0)  movelist[0] = '\0';
	if(ind == n_moves) return;
	int switchCase = 0;
	char m;
	for(switchCase = 0; switchCase < 4; ++switchCase)
	{
    //Can use if...else if, but very tedious!
		switch(switchCase)
		{
			case 0: m = 'U'; break;
			case 1: m = 'D'; break;
			case 2: m = 'L'; break;
			case 3: m = 'R'; break;
			default: m = 'U'; //just a random choice, no significance of it!!
		}
		char *otherState = malloc(sizeof(char)*(SIDELENGTH*SIDELENGTH+1));
		strcpy(otherState, state);
		if(move(otherState,m)==0)  free(otherState);
		else
		{
			movelist[ind] = m;
			movelist[ind+1] = '\0';
			root = MoveTree_insert(root, otherState, movelist);
			generateAllHelper(root, n_moves, otherState, movelist, ind+1);
			free(otherState);
		}
	}
}

MoveTree * generateAll(char * state, int n_moves)
{
   //Your code goes here
  char *moveSet = malloc(sizeof(char)*(n_moves+1));
	moveSet[0] = '\0';
	MoveTree *root = MoveTree_create(state, "");

	generateAllHelper(root, n_moves, state, moveSet, 0);
	free(moveSet);
	return root;
}

/* This function is supplied to you.*/

char * solve(char * state)
{
    MoveTree * tree = generateAll(state, MAX_SEARCH_DEPTH);
    MoveTree * answer = MoveTree_find(tree, FINAL_STATE);
    char * movelist = NULL;
    if(answer != NULL){
		movelist = strdup(answer -> moves);
	}
    MoveTree_destroy(tree);
    return movelist;
}
