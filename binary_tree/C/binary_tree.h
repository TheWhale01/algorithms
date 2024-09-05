#pragma once

typedef struct btree_s {
	struct btree_s *left;
	struct btree_s *right;
	void	*item;
} btree_t;

btree_t *create_node(void *item);
void btree_apply_prefix(btree_t *root, void (*applyf)(void *));
void btree_apply_infix(btree_t *root, void (*applyf)(void *));
void btree_apply_suffix(btree_t *root, void (*applyf)(void *));
void btree_insert_data(btree_t **root, void *item, int (*cmpf)(void *, void *));
void *btree_search_item(btree_t *root, void *data_ref, int (*cmpf)(void *, void *));
int btree_level_count(btree_t *root);
void btree_apply_by_level(btree_t *root, void (*applyf)(void *item, int current_level, int is_first_elem));
