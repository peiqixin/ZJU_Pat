#define BLACK 0
#define RED 1
typedef struct RBNode *PtrToRBNode;
typedef PtrToRBNode TreeNode;
typedef enum RBNodeColor Color;
typedef struct RBTreeNode *PTrToRBTree;
typedef int ElementType;
typedef PTrToRBTree Tree;
enum RBNodeColor
{
	red,
	blcack
};
struct RBNode{
	PtrToRBNode left;
	PtrToRBNode right;
	PtrToRBNode parent;
	ElementType key;
	Color color;
};

struct RBTreeNode
{
	PtrToRBNode root;
	PtrToRBNode nil;
};
Tree CreateRBTree();
void LeftRotate(Tree T, TreeNode x);
void RightRotate(Tree T, TreeNode x);
void Insert(Tree T, TreeNode z);
void InsertFixup(Tree T, TreeNode z);
void Transplant(Tree T, TreeNode u, TreeNode v);
void Delete(Tree T, TreeNode z);
void DeleteFixpup(Tree T, TreeNode x);
TreeNode Minimum(Tree T);
TreeNode Maximum(Tree T);
