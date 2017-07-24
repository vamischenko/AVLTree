#pragma once

struct node								// структура для представления узлов дерева
{
	int key;
	unsigned char height;				// разница высот левого и правого поддеревьев
	node * left;
	node * right;

    node(int k) : key(k), height(1), left(0), right(0) {}
};

class avlTree
{
public:
	avlTree();
	~avlTree();

	//интерфейс для пользователя
	void insertValue(int k);			// вставляет значение в дерево
	void removeValue(int k);			// удаляет значение из дерева
    void clearTree();                   // очищает дерево
	node * getRoot();					// возвращает корень дерева

private:
	node * root;
	bool first;

    unsigned char height(node * p);     // считает высоту и возвращает ее
	int bfactor(node * p);
    void fixheight(node * p);           // считает правильную высоту для узла

	node * rotateright(node * p);		// правый поворот вокруг p
	node * rotateleft(node * q);		// левый поворот вокруг q

	node * balance(node * p);			// балансировка узла p
	node * insert(node * p, int k);		// вставка ключа k в дерево с корнем p
	node * remove(node * p, int k);		// удаление ключа k из дерева p

	node * findmin(node * p);			// поиск узла с минимальным ключом в дереве p
	node * removemin(node * p);			// удаление узла с минимальным ключом из дерева p

};
