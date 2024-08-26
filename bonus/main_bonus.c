#include "libasm_bonus.h"
//tester list size and list push front with null node

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    t_list  *node = NULL;

    char    *str = "Lol!";
    ft_list_push_front(&node, str);

    char    *str2 = "TEST!";
    ft_list_push_front(&node, str2);

    int i = 0;
    t_list *p = node;
    while (p != NULL) {
        printf("data node %d : %s\n", i, (char *)p->data);
        p = p->next;
        i++;
    }
    int res1 = ft_list_size(node);
    printf("res list ici = %d\n", res1);
    
    char    *str3 = "Saucisse\n#";
    ft_list_push_front(&node, str3);

    char    *str4 = "###Cheddar et Bacon###\n#";
    ft_list_push_front(&node, str4);
    
    i = 0;
    p = node;
    while (p != NULL) {
        printf("data node %d : %s\n", i, (char *)p->data);
        p = p->next;
        i++;
    }
    int res2 = ft_list_size(node);
    printf("res list ici = %d\n", res2);
    
    while (node != NULL) {
        p = node;
        node = node->next;
        free(p);
    }

    return (0);
}