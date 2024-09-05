#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>

void print_node(void *item) {
	printf("%d\n", *((int*)(item)));
}

int cmpf(void *item1, void *item2) {
	if (*(int*)(item1) < *(int*)(item2))
		return -1;
	else if (*(int*)(item1) > *(int*)(item2))
		return 1;
	return 0;
}

int main(void) {
	btree_t *tree = NULL;
	btree_t *tree2 = NULL;
	int data1 = 1; // A
	int data2 = data1 + 1; // B
	int data3 = data2 + 1; // C
	int data4 = data3 + 1; // D
	int data5 = data4 + 1; // E
	int data6 = data5 + 1; // F

	printf("prefix:\n");
	tree = create_node(&data2);
	tree->left = create_node(&data1);
	tree->right = create_node(&data4);
	tree->right->left = create_node(&data3);
	tree->right->right = create_node(&data6);
	tree->right->right->left = create_node(&data5);
	btree_apply_prefix(tree, print_node);
	printf("infix:\n");
	btree_apply_infix(tree, print_node);
	printf("suffix:\n");
	btree_apply_suffix(tree, print_node);
	printf("after insert\n");
	btree_insert_data(&tree2,&data2, cmpf);
	btree_insert_data(&tree2,&data1, cmpf);
	btree_insert_data(&tree2,&data4, cmpf);
	btree_insert_data(&tree2,&data3, cmpf);
	btree_insert_data(&tree2,&data6, cmpf);
	btree_insert_data(&tree2,&data5, cmpf);
	printf("prefix:\n");
	btree_apply_prefix(tree2, print_node);
	printf("infix:\n");
	btree_apply_infix(tree2, print_node);
	printf("suffix:\n");
	btree_apply_suffix(tree2, print_node);
	printf("finding\n");
	print_node(btree_search_item(tree2, &data4, cmpf));
	printf("Longest branch\n");
	printf("%d\n", btree_level_count(tree2));
	return EXIT_SUCCESS;
}
