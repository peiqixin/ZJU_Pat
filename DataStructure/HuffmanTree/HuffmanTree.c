#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *HuffmanTree;
struct TreeNode
{
	int weight;
	HuffmanTree Left, Right;
};