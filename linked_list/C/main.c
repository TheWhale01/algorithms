#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	list_t *lst1 = NULL;
	list_t *lst2 = NULL;
	list_t *lst3 = NULL;
	list_t *lst4 = NULL;
	char *bonsoir = "bonsoir";
	char *je = "je";
	char *ne = "ne";
	char *suis = "suis";
	char *pas = "pas";
	char *moi = "moi";

	for (size_t i = 0; i < 10; i++)
		push_front(&lst1, &i, sizeof(int) * 1, INT);
	for (size_t i = 0; i < 10; i++)
		push_back(&lst2, &i, sizeof(int) * 1, INT);
	push_front(&lst3, bonsoir, sizeof(char) * (strlen(bonsoir) + 1), STRING);
	push_front(&lst3, je, sizeof(char) * (strlen(je) + 1), STRING);
	push_front(&lst3, ne, sizeof(char) * (strlen(ne) + 1), STRING);
	push_front(&lst3, suis, sizeof(char) * (strlen(suis) + 1), STRING);
	push_front(&lst3, pas, sizeof(char) * (strlen(pas) + 1), STRING);
	push_front(&lst3, moi, sizeof(char) * (strlen(moi) + 1), STRING);

	push_back(&lst4, bonsoir, sizeof(char) * (strlen(bonsoir) + 1), STRING);
	push_back(&lst4, je, sizeof(char) * (strlen(je) + 1), STRING);
	push_back(&lst4, ne, sizeof(char) * (strlen(ne) + 1), STRING);
	push_back(&lst4, suis, sizeof(char) * (strlen(suis) + 1), STRING);
	push_back(&lst4, pas, sizeof(char) * (strlen(pas) + 1), STRING);
	push_back(&lst4, moi, sizeof(char) * (strlen(moi) + 1), STRING);

	print_list(lst1);
	print_list(lst2);
	print_list(lst3);
	print_list(lst4);

	lstclear_iter(lst1);
	lstclear_recur(lst2);
	lstclear_iter(lst3);
	lstclear_recur(lst4);
	return EXIT_SUCCESS;
}
