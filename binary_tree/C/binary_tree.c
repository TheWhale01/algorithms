#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
	return a > b ? a : b;
}

btree_t *create_node(void *item) {
	btree_t *node = NULL;

	if (!(node = malloc(sizeof(btree_t) * 1)))
		return NULL;
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return node;
}

void btree_apply_prefix(btree_t *root, void (*applyf)(void *)) {
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

void btree_apply_infix(btree_t *root, void (*applyf)(void *)) {
	if (root->left)
		btree_apply_infix(root->left, applyf);
	applyf(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}

void btree_apply_suffix(btree_t *root, void (*applyf)(void *)) {
	if (root->left)
		btree_apply_suffix(root->left, applyf);
	if (root->right)
		btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}

void btree_insert_data(btree_t **root, void *item, int (*cmpf)(void *, void *)) {
	btree_t *tmp = NULL;
	if (!root)
		return ;
	if (!*root) {
		*root = create_node(item);
		return ;
	}
	tmp = *root;
	while (tmp->left && tmp->right) {
		if (cmpf(tmp->item, item) > 0)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (cmpf(tmp->item, item) > 0)
		tmp->left = create_node(item);
	else
		tmp->right = create_node(item);
}

void *btree_search_item(btree_t *root, void *data_ref, int (*cmpf)(void *, void *)) {
	if (!root)
		return NULL;
	void *result = btree_search_item(root->left, data_ref, cmpf);
	if (result)
		return result;
	if (cmpf(root->item, data_ref) == 0)
		return root->item;
	return btree_search_item(root->right, data_ref, cmpf);
}

int btree_level_height(btree_t *root) {
	if (!root)
		return 0;
	return 1 + max(btree_level_height(root->left), btree_level_height(root->right));
}

int btree_level_count(btree_t *root) {
	int lh = 0, rh = 0;
	int ld = 0, rd = 0;

	if (!root)
		return 0;
	lh = btree_level_height(root->left);
	rh = btree_level_height(root->right);
	ld = btree_level_count(root->left);
	rd = btree_level_count(root->right);
	return max(lh + rh, max(ld, rd));
}
