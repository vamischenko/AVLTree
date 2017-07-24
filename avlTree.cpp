#include "avlTree.h"

avlTree::avlTree() : root(0), first(true) 	//there must be nullptr from c++11
{
}

avlTree::~avlTree()
{
	for(;;)
	{
		root = removemin(root);
		if(!root)
			break;
	}
}

unsigned char avlTree::height( node* p )
{
	return p ? p->height : 0;
}

int avlTree::bfactor( node* p )
{
	return height(p->right) - height(p->left);
}

void avlTree::fixheight( node* p )
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = ((hl > hr) ? hl : hr) + 1;
}

node* avlTree::rotateright( node* p ) /* правый поворот вокруг p */
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* avlTree::rotateleft( node* q ) /* левый поворот вокруг q */
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* avlTree::balance( node* p ) /* балансировка узла p */
{
	fixheight(p);
	if( bfactor(p) == 2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p) == -2 )
	{
		if( bfactor(p->left) > 0 )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* avlTree::insert( node* p, int k ) /* вставка ключа k в дерево с корнем p */
{
	if( !p ) return new node(k);
	if( k < p->key )
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

node* avlTree::findmin( node* p ) /* поиск узла с минимальным ключом в дереве p */
{
	return p->left ? findmin(p->left) : p;
}

node* avlTree::removemin( node* p ) /* удаление узла с минимальным ключом из дерева p */
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* avlTree::remove( node* p, int k ) /* удаление ключа k из дерева p */
{
	if( !p ) return 0;
	if( k < p->key )
		p->left = remove(p->left, k);
	else if( k > p->key )
		p->right = remove(p->right, k);	
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if( !r ) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void avlTree::insertValue( int k )
{
	if(first)
	{
		root = new node(k);
		first = false;
	}
	else
	{
		root = insert(root, k);
	}
}

void avlTree::removeValue( int k )
{
	if(first)
	{
		return;
	}
	else
	{
		root = remove(root, k);
    }
}

void avlTree::clearTree()
{
    for(;;)
    {
        root = removemin(root);
        if(!root)
            break;
    }
    root = 0;
    first = true;
}

node * avlTree::getRoot()
{
	return root;
}
