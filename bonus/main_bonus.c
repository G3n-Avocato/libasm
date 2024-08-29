#include "libasm_bonus.h"

//test avec null data for push_front list_size and list sort 

void    ft_print_node(t_list *node, int type) {
    int     i = 0;
    int     res = 0;
    t_list  *p = node;

    while (p != NULL) {
        if (type)
            printf("\033[34mdata node %d :\033[0m %d\n", i, *(int*)p->data);
        else
            printf("\033[34mdata node %d :\033[0m %s\n", i, (char *)p->data);
        p = p->next;
        i++;
    }

    //////////////////////////
    //    FT_LIST_SIZE      //
    //////////////////////////
    char    *str = "char *";
    if (type)
        str = "int";
    else if (type < 0)
        str = "NULL";
    res = ft_list_size(node);
    printf("\033[33mft_list_size for (%s) =\033[0m %d\n\n", str, res);
    return ;
}

void    ft_free_node(t_list *node) {
    t_list  *p;

    while (node != NULL) {
        p = node;
        node = node->next;
        free(p);
    }

    return ;
}

int main(void) {
    
    t_list  *node = NULL;
    
    char    *str1 = "MIAMI!";
    char    *str2 = "TEST!";
    char    *str3 = "Saucisse\n#";
    char    *str4 = "###Cheddar et Bacon###\n#";
    char    *str5 = "Very loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooonnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnng str for test!";
    char    *str6 = "";

    //////////////////////////
    //  FT_LIST_PUSH_FRONT  //
    //////////////////////////

    ft_list_push_front(&node, str1);
    ft_list_push_front(&node, str2);

    printf("\033[33mI - Linked List (char *) after 2 ft_list_push_front\033[0m\n");
    ft_print_node(node, 0);

    ft_list_push_front(&node, str3);
    ft_list_push_front(&node, str4);
    ft_list_push_front(&node, str5);
    ft_list_push_front(&node, str6);

    printf("\033[33mII - Linked List (char *) after 3 others ft_list_push_front\033[0m\n");
    ft_print_node(node, 0);

    //////////////////////////
    //    FT_LIST_SORT      //
    //////////////////////////

    ft_list_sort(&node, (int (*)(const char *, const char *))ft_strcmp);

    printf("\033[33mIIbis - Linked List (char *) ft_list_sort\033[0m\n");    
    ft_print_node(node, 0);

    ft_free_node(node);
    node = NULL;
    
    int data1 = 1;
    int data2 = 62;
    int data3 = 3;
    int data4 = -4;
    int data5 = 15;
    int data6 = 42;
    int data7 = -3;
    int data8 = 54;
    int data9 = 1;

    ft_list_push_front(&node, &data1);
    ft_list_push_front(&node, &data2);
    ft_list_push_front(&node, &data3);
    ft_list_push_front(&node, &data4);
    ft_list_push_front(&node, &data5);
    ft_list_push_front(&node, &data6);
    ft_list_push_front(&node, &data7);
    ft_list_push_front(&node, &data8);
    ft_list_push_front(&node, &data9);

    printf("\033[33mIII - Linked List (int) after 4 ft_list_push_front\033[0m\n");
    ft_print_node(node, 1);

    ft_list_sort(&node, (int (*)(const char *, const char *))ft_strcmp);

    printf("\033[33mIIIbis - Linked List (int) after ft_list_sort\033[0m\n");
    ft_print_node(node, 1);

    t_list  *_null = NULL;
    ft_list_sort(&_null, (int (*)(const char *, const char *))ft_strcmp);
    
    printf("\033[33mIV - Linked List (NULL) after ft_list_sort\033[0m\n");
    ft_print_node(_null, -1);

    ft_free_node(node);

    return (0);
}