#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void print_list(list_t *lst) {
	list_t *tmp;

	tmp = lst;
	while (tmp) {
		switch (tmp->type) {
			case INT:
				printf("%d -> ", *((int*)((tmp->data))));
				break;
			case STRING:
				printf("%s -> ", ((char*)((tmp->data))));
				break;
			case CHAR:
				printf("%c -> ", *((char*)((tmp->data))));
				break;
			default:
				break;
		}
		tmp = tmp->next;
	}
	printf("NULL\n");
}

list_t *push_back(list_t **lst, void *data, size_t bytes, types_t type) {
	list_t *node = NULL;
	list_t *last_node = NULL;
	
	if (!lst || !data || (!(node = malloc(sizeof(list_t) * 1))))
		return NULL;
	if ((!(node->data = malloc(bytes)))) {
		free(node);
		return NULL;
	}
	node->next = NULL;
	node->type = type;
	node->data = memcpy(node->data, data, bytes);
	if (!(*lst)) {
		*lst = node;
		return node;
	}
	last_node = lstlast(*lst);
	last_node->next = node;
	return node;
}

list_t *lstlast(list_t *lst) {
	list_t *tmp = NULL;

	if (!lst)
		return NULL;
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return tmp;
}

list_t *push_front(list_t **lst, void *data, size_t bytes, types_t type) {
	list_t *node = NULL;
	
	if (!lst || !data || (!(node = malloc(sizeof(list_t) * 1))))
		return NULL;
	if (!(node->data = malloc(bytes))) {
		free(node);
		return NULL;
	}
	node->data = memcpy(node->data, data, bytes);
	node->type = type;
	node->next = *lst;
	*lst = node;
	return node;
}

void lstclear_recur(list_t *lst) {
	if (!lst)
		return ;
	lstclear_recur(lst->next);
	free(lst->data);
	free(lst);
}

void lstclear_iter(list_t *lst) {
	list_t *tmp = NULL;
	list_t *next = NULL;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp) {
		next = tmp->next;
		free(tmp->data);
		free(tmp);
		tmp = next;
	}
}
