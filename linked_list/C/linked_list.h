#pragma once
#include <stdlib.h>

typedef enum types {
	INT,
	STRING,
	CHAR,
} types_t;

typedef struct list_s {
	void *data;
	struct list_s *next;
	types_t type;
}	list_t;

void print_list(list_t *lst);
list_t *push_back(list_t **lst, void *data, size_t bytes, types_t type);
list_t *push_front(list_t **lst, void *data, size_t bytes, types_t type);
list_t *lstlast(list_t *lst);

void lstclear_recur(list_t *lst);
void lstclear_iter(list_t *lst);
