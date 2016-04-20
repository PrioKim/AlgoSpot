#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *l, *r;
	int data;
};

struct node* create_node(int data)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->l = NULL;
	new_node->r = NULL;
	new_node->data = data;

	return new_node;
}

void insert_node(struct node *tree, struct node *new_node)
{
	struct node * pnode = tree;

	while (pnode){
		if (new_node->data >= pnode->data)
		{
			if (pnode->r != NULL)
				pnode = pnode->r;
			else{
				pnode->r = new_node;
				return;
			}
		}
		else if (new_node->data < pnode->data)
		{
			if (pnode->l != NULL)
				pnode = pnode->l;
			else{
				pnode->l = new_node;
				return;
			}
		}
	}
}

void travel_tree(struct node* tree, int *cnt, int data)
{
	if (tree == NULL)
		return;

	if (data < tree->data)
		(*cnt)++;

	if (tree->l != NULL)
		travel_tree(tree->l, cnt, data);

	if (tree->r != NULL)
		travel_tree(tree->r, cnt, data);
}

int get_bigger_num_cnt(struct node* tree, int data)
{
	int cnt = 0;

	travel_tree(tree, &cnt, data);

	return cnt;
}

int get_input()
{
	register int s = 0, ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
	for (s = ch - '0', ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		s = s * 10 + ch - '0';
	return s;

}

int main()
{
	int C, N, tmp, output;
	struct node *bst;
	fscanf(stdin, "%d", &C);

	while (C--){
		output = 0;
		fscanf(stdin, "%d", &N);

		fscanf(stdin, "%d", &tmp);
		bst = create_node(tmp);

		for (int i = 0; i < N - 1; i++){
			tmp = get_input();
			output += get_bigger_num_cnt(bst, tmp);
			insert_node(bst, create_node(tmp));
		}

		fprintf(stdout, "%d\n", output);
	}

	return 0;
}