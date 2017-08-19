#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"
Tree CreateRBTree()
{
	Tree T;
	T = (PTrToRBTree)maloc(sizeof(struct RBTreeNode));
	T->nil = (PtrToRBNode)malloc(sizeof(struct RBNode));
	T->nil->left = NULL;
	T->nil->right = NULL;
	T->nil->parent = NULL;
	T->nil->color = BLACK;
	T->root = T->nil;
	return T;
}

void LeftRotate(Tree T, TreeNode x)
{
	// set y
	TreeNode y = x->right;
	// link y's left to x
	x->right = y->left;
	if(y->left != T->nil){
		y->left->parent = x;
	}
	// link x's parent to y
	y->parent = x->parent;
	if(x->parent == T->nil){
		T->root = y;
	}else if(x = x->parent->left){
		x->parent->left = y;
	}else{
		x->parent->right = y;
	}
	// link y's left to x
	y->left = x;
	x->parent = y;
}

void RightRotate(Tree T, TreeNode x)
{
	// set y
	TreeNode y = x->left;
	// link y's left to x
	x->left = y->right;
	if(y->right != T->nil){
		y->right->parent = x;
	}
	// link x's parent to y
	if(x->parent == T->nil){
		T->root = y;
	}else if(x = x->parent->left){
		x->parent->left = y;
	}else{
		x->parent->right = y;
	}
	// put x on y's right
	y->right = x;
	x->parent = y;
}

void Insert(Tree T, TreeNode z)
{
	TreeNode y = T->nil;
	TreeNode x = T->root;
	while(x != T->nil){
		y = x;
		if(x->key > z->key)
			x = x->left;
		else
			x = x->right;
	}
	z.p = y;
	if(y == T->nil)
		T->root = z;
	else if(z->key > y->key)
		y->right = z;
	else
		y->left = z;
	z->left = T->nil;
	z->right = T->nil;
	z->color = RED;
	InsertFixup(T, z);
}

void InsertFixup(Tree T, TreeNode z)
{
	TreeNode y;
	While(z->parent->color == RED){
		// 如果z的父结点是z的祖父结点的左儿子
		if(z->parent = z->parent->parent->left){
			// y为x的叔结点
			y = z->parent->parent->right;
			// z的叔结点是红色的，将z的父结点和叔结点都染成黑色，祖父结点染成红色，并让z指向祖父结点继续循环
			if(y->color == RED){
				y->color = BLACK;
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}else{
				// 如果z是父结点的右儿子，对z父结点进行左旋，将z指向z的右儿子（即原先z的父结点）
				if(z = z->parent->right){
					LeftRotate(T, z->parent);
					z = z->right;
				}
				// 将z的父结点染成黑色，祖父结点染成红色，对祖父结点进行右旋
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				RightRotate(T, z->parent->parent);
			}
		}else{
			y = z->parent->parent->left;
			if(y->color == RED){
				y->color = BLACK;
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}else{
				if(z = z->parent->left){
					RightRotate(T, z->parent);
					z = z->left;
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				LeftRotate(T, z->parent->parent);
			}
		}
	}
	T->root->color = BLACK;
}

void Transplant(Tree T, TreeNode u, TreeNode v)
{
	v->parent = u->parent;
	if(u->parent == T->nil)
		T->root = v;
	else if(u = u->parent->left)
		u->parent->left = u;
	else
		u->parent->right = u;
}

void Delete(Tree T, TreeNode z)
{
	// y代表从树中要删除的结点或者移至树内的结点，x始终指向原始y的父结点
	TreeNode y = z, x;
	Color yoc = y->color;
	if(z->right == T->nil){
		x = z->left;
		Transplant(T, z, x);
	}else if(z->left == T->nil){
		x = z->right;
		Transplant(T, z, x);
	}else{
		y = Minimum(z->right);
		yoc = y->color;
		x = y->right;
		if(y->parent == z)
			x->parent = y;
		else{
			Transplant(T, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(T, y, z);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if(yoc == BLACK)
		DeleteFixpup(T, x);
}

void DeleteFixpup(Tree T, TreeNode x)
{
	// w始终指向x的兄弟结点
	TreeNode w;
	while(x != T->root && x->color == BLACK){
		if(x == x->parent->left){
			// 设置w
			w = x->parent->right;
			// 如果w的颜色是红色的，则
			if(w->color == RED){
				w->color == BLACK;
				w->parent->color = RED;
				LeftRotate(T, w->parent);
				w = x->parent->right;
			}
			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}else{
				if(w->right->color == BLACK){
					w->left->color = BLACK;
					w->color = RED;
					RightRotate(T, w);
					w = x->parent->right;
				}
				w->color = w->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotate(T, x->parent);
				x = T->root;
			}
		}else{
			w = x->parent->left;
			if(w->color == RED){
				w->color = BLACK;
				w->parent->color = RED;
				RightRotate(T, x->parent);
				w = x->parent->left;
			}
			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}else{
				if(w->left->color == BLACK){
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(T, w);
					w = x->parent->left;
				}
				w->right->color = BLACK;
				w->color = w->parent->color;
				w->parent->color = BLACK;
				RightRotate(T, x->parent);
				x = T->root;
			}
		}
	}
	x->color = BLACK;
}

TreeNode Minimum(Tree T)
{
	TreeNode min = T->root;
	while(min != min->nil)
		min = min->left;
	return min;
}

TreeNode Maximum(Tree T)
{
	TreeNode max = T->root;
	while(max != T->nil)
		max = max->left;
	return max;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}