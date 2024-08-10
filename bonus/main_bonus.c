#include "libasm_bonus.h"


#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    t_list  *node = NULL;
    char    *str = "Lol!";
    
    ft_list_push_front(&node, str);

    char    *str2 = "TEST!";
    ft_list_push_front(&node, str2);
    
    t_list *p = node;
    while (p != NULL) {
        printf("%s\n", (char *)p->data);
        p = p->next;
    }
    
    while (node != NULL) {
        p = node;
        node = node->next;
        free(p);
    }

    return (0);
}