#include "libasm_bonus.h"
//tester list size and list push front with null node
// MAIN START REFUND DIV FCTS

//#include <stdio.h>
//#include <stdlib.h>

int      ft_strcmp(const char *s1, const char *s2);

int main(void) {
    
    t_list  *node = NULL;
    int     i = 0;
    t_list  *p = node;
    
    char    *str = "MIAMI!";
    char    *str2 = "TEST!";
    char    *str3 = "Saucisse\n#";
    char    *str4 = "###Cheddar et Bacon###\n#";

    //////////////////////////
    //  FT_LIST_PUSH_FRONT  //
    //////////////////////////
    //////////////////////////
    //    FT_LIST_SIZE      //
    //////////////////////////    

    ft_list_push_front(&node, str);
    ft_list_push_front(&node, str2);

    printf("\033[33mI - Linked List (char *) after 2 ft_list_push_front\033[0m\n");
    p = node;
    while (p != NULL) {
        printf("\033[34mdata node %d :\033[0m %s\n", i, (char *)p->data);
        p = p->next;
        i++;
    }
    int res1 = ft_list_size(node);
    printf("\033[33mft_list_size for (char *) =\033[0m %d\n\n", res1);
    
    ft_list_push_front(&node, str3);
    ft_list_push_front(&node, str4);
    
    printf("\033[33mII - Linked List (char *) after 2 others ft_list_push_front\033[0m\n");
    i = 0;
    p = node;
    while (p != NULL) {
        printf("\033[34mdata node %d :\033[0m %s\n", i, (char *)p->data);
        p = p->next;
        i++;
    }
    int res2 = ft_list_size(node);
    printf("\033[33mft_list_size for (char *) =\033[0m %d\n\n", res2);
    
    while (node != NULL) {
        p = node;
        node = node->next;
        free(p);
    }
    //////////////////////////
    //    FT_LIST_SORT      //
    //////////////////////////

    node = NULL;
    int data1 = 1;
    ft_list_push_front(&node, &data1);
    int data2 = 2;
    ft_list_push_front(&node, &data2);
    int data3 = 3;
    ft_list_push_front(&node, &data3);
    int data4 = 4;
    ft_list_push_front(&node, &data4);
    
    printf("\033[33mIII - Linked List (int) after 4 ft_list_push_front\033[0m\n");
    i = 0;
    p = node;
    while (p != NULL) {
        printf("\033[34mdata node %d :\033[0m %d\n", i, *(int*)p->data);
        p = p->next;
        i++;
    }
    int res3 = ft_list_size(node);
    printf("\033[33mft_list_size for (int) =\033[0m %d\n\n", res3);

    ft_list_sort(&node, (int (*)(const char *, const char *))ft_strcmp);

    printf("\033[33mIIIbis - Linked List (int) after ft_list_sort\033[0m\n");
    i = 0;
    p = node;
    while (p != NULL) {
        printf("\033[34mdata node %d :\033[0m %d\n", i, *(int*)p->data);
        p = p->next;
        i++;
    }
    int res4 = ft_list_size(node);
    printf("\033[33mft_list_size for (int) =\033[0m %d\n\n", res4);

    while (node != NULL) {
        p = node;
        node = node->next;
        free(p);
    }

    return (0);
}