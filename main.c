#include "libasm.h"

int main(int argc, char **argv) {

    const char  *l_str = "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSA";
    const char  *empty_str = "";
    const char  *one_c = "S";
    const char  *str1 = "String";
    const char  *str2 = "String n*2 \nTESTESTESTESTTESTEST";
    const char  *str3 = "Same Static String\n";
    const char  *str4 = "Same Static String\n";
    const char  *str5 = "78868 lolololololol 6576767.??????";
    const char  *str6 = "YES - NO.";
    const char  *null = NULL;
    const char  *middle = "string\0null";

    const char  *file = "ft_strlen.s";
    const char  *empty_file = "empty_file.txt";
    int     size = 150;
    char    buf1[size];
    char    buf2[size];
    char    buf3[size];
    char    buf4[size];
    
    const char  *str = "string if no args";
    if (argc > 1)
        str = argv[1];
    
    int         cas = 0;
    if (argc > 2) {
        if (strlen(argv[2]) == 1 && isdigit(argv[2][0]) != 0) 
            cas = atoi(argv[2]);
    }
    if (cas != 0) 
        printf("\033[34m-- %d --\033[0m\n", cas);

    switch (cas) {
        case 0:
            printf("\033[34m-- ALL TEST --\033[0m\n");
        case 1:
            //////////////////////////
            //      FT_STRLEN       //
            //////////////////////////
            printf("\033[31m----- FT_STRLEN -----\033[0m\n\n");

            int     len1 = ft_strlen(str);

            printf("string argv[1] = %s\n", str);
            printf("\033[33mft_strlen size argv[1] = \033[0m%d\n", len1);
            printf("\033[32mreal strlen string.h argv[1] = \033[0m%lu\n", strlen(str));
            printf("\n");

            int     len2 = ft_strlen(empty_str);

            printf("str empty = \033[0m%s\n", empty_str);
            printf("\033[33mft_strlen size str empty = \033[0m%d\n", len2);
            printf("\033[32mreal strlen string.h str empty = \033[0m%lu\n", strlen(empty_str));
            printf("\n");

            int     len3 = ft_strlen(l_str);

            printf("str large = \033[0m%s\n", l_str);
            printf("\033[33mft_strlen size str large = \033[0m%d\n", len3);
            printf("\033[32mreal strlen string.h str large = \033[0m%lu\n", strlen(l_str));
            printf("\n");

            int     len4 = ft_strlen(one_c);
            
            printf("str one = \033[0m%s\n", one_c);
            printf("\033[33mft_strlen size str one char = \033[0m%d\n", len4);
            printf("\033[32mreal strlen string.h str one char = \033[0m%lu\n", strlen(one_c));
            printf("\n");

            int     len5 = ft_strlen(middle);
            
            printf("str middle null = \033[0m%s\n", middle);
            printf("\033[33mft_strlen size str middle null = \033[0m%d\n", len5);
            printf("\033[32mreal strlen string.h str middle null = \033[0m%lu\n", strlen(middle));
            printf("\n");

            if (cas != 0)
                break;
        case 2:
            //////////////////////////
            //      FT_STRCPY       //
            //////////////////////////
            printf("\033[31m----- FT_STRCPY -----\033[0m\n\n");

            int     len_str1 = ft_strlen(str1); 
            char    *dest1 = malloc(sizeof(char) * (len_str1 + 1));
            char    *dest2 = malloc(sizeof(char) * (len_str1 + 1));
            
            strcpy(dest1, str1);
            printf("\033[32mstrcpy string.h\033[0m\n");
            printf("\033[32msrc = %s\ndest = %s\033[0m\n", str1, dest1);

            ft_strcpy(dest2, str1);
            printf("\033[33mft_strcpy\033[0m\n");
            printf("\033[33msrc = %s\ndest = %s\033[0m\n", str1, dest2);

            free(dest1);
            free(dest2);
            printf("\n");

            int     len_l_str = ft_strlen(l_str);
            dest1 = malloc(sizeof(char) * (len_l_str + 1)); 
            dest2 = malloc(sizeof(char) * (len_l_str + 1));

            strcpy(dest1, l_str);
            printf("\033[32mstrcpy string.h\033[0m\n");
            printf("\033[32msrc = %s\ndest = %s\033[0m\n", l_str, dest1);

            ft_strcpy(dest2, l_str);
            printf("\033[33mft_strcpy\033[0m\n");
            printf("\033[33msrc = %s\ndest = %s\033[0m\n", l_str, dest2);

            free(dest1);
            free(dest2);
            printf("\n");

            int     len_empty_str = ft_strlen(empty_str);
            dest1 = malloc(sizeof(char) * (len_empty_str + 1)); 
            dest2 = malloc(sizeof(char) * (len_empty_str + 1));
            
            strcpy(dest1, empty_str);
            printf("\033[32mstrcpy string.h\033[0m\n");
            printf("\033[32msrc = %sdest = %s\033[0m\n", empty_str, dest1);

            ft_strcpy(dest2, empty_str);
            printf("\033[33mft_strcpy\033[0m\n");
            printf("\033[33msrc = %sdest = %s\033[0m\n", empty_str, dest2);

            free(dest1);
            free(dest2);
            printf("\n");

            if (cas != 0)
                break;
        case 3:
            //////////////////////////
            //      FT_STRCMP       //
            //////////////////////////
            printf("\033[31m----- FT_STRCMP -----\033[0m\n\n");
            
            int     res1 = strcmp(str, str1);
            int     res2 = ft_strcmp(str, str1);

            printf("str = %s | str1 = %s\n", str, str1);
            printf("\033[32mstrcmp res = \033[0m%d\n", res1);
            printf("\033[33mft_strcmp res = \033[0m%d\n", res2);
            printf("\n");
            
            int     res3 = strcmp(str3, str4);
            int     res4 = ft_strcmp(str3, str4);

            printf("str3 = %sstr4 = %s\n", str3, str4);
            printf("\033[32mstrcmp res = \033[0m%d\n", res3);
            printf("\033[33mft_strcmp res = \033[0m%d\n", res4);
            printf("\n");

            int     res5 = strcmp(empty_str, one_c);
            int     res6 = ft_strcmp(empty_str, one_c);

            printf("empty_str = %s | one_c = %s\n", empty_str, one_c);
            printf("\033[32mstrcmp res = \033[0m%d\n", res5);
            printf("\033[33mft_strcmp res = \033[0m%d\n", res6);
            printf("\n");

            int     res7 = strcmp(one_c, empty_str);
            int     res8 = ft_strcmp(one_c, empty_str);

            printf("reverse s12 <-> s13\n");
            printf("\033[32mstrcmp res = \033[0m%d\n", res7);
            printf("\033[33mft_strcmp res = \033[0m%d\n", res8);
            printf("\n");

            char *po = "a";
            char *po1 = "A";
            int uno = strcmp(po, po1);
            int dos = ft_strcmp(po, po1);
            
            printf("cmp %s -> %s\n", po, po1);
            printf("\033[32mstrcmp res = \033[0m%d\n", uno);
            printf("\033[33mft_strcmp res = \033[0m%d\n", dos);
            printf("\n");

            if (cas != 0)
                break;
        case 4:
            //////////////////////////
            //      FT_WRITE        //
            //////////////////////////
            printf("\033[31m----- FT_WRITE -----\033[0m\n\n");

            size_t  len_str = ft_strlen(str);

            // printf("\033[32mwrite unistd.h argv[1] =>\033[0m\n");
            // printf("\033[32m\nres write = \033[0m%zd\n", write(1, str, -1));
            // printf("\n\n");

            // printf("\033[33mft_write argv[1] =>\033[0m\n");
            // printf("\033[33m\nres ft_write = \033[0m%zd\n", ft_write(1, str, -1));
            // printf("\n\n");

            size_t  len_str5 = ft_strlen(str5);

            printf("\033[32mwrite unistd.h str static =>\033[0m\n");
            printf("\033[32m\nres write = \033[0m%zd\n", write(2, str5, len_str5));
            printf("\n\n");

            printf("\033[33mft_write str static =>\033[0m\n");
            printf("\033[33m\nres ft_write = \033[0m%zd\n", ft_write(2, str5, len_str5));
            printf("\n\n");

            size_t  len_empty = ft_strlen(empty_str);

            printf("\033[32mwrite unistd.h empty str =>\033[0m\n");
            printf("\033[32mres write = \033[0m%zd\n", write(1, empty_str, len_empty));
            printf("\n\n");

            printf("\033[33mft_write empty str =>\033[0m\n");
            printf("\033[33mres ft_write = \033[0m%zd\n", ft_write(1, empty_str, len_empty));
            printf("\n");

            if (cas != 0)
                break;
        case 5:
            //////////////////////////
            //      FT_READ         //
            //////////////////////////
            printf("\033[31m----- FT_READ -----\033[0m\n\n");

            ssize_t bytes1;

            int     fd = open(file, O_RDONLY);
            if (fd == -1) {
                printf("\033[31mError open file\033[0m\n");
                return (1);
            }
            bytes1 = read(fd, buf1, size - 1);
            if (bytes1 == -1)
                printf("\033[31mError read fct\033[0m\n");
            buf1[bytes1] = '\0';
            
            printf("\033[32mBuf read unistd.h => \033[0m\n%s\n\n\033[32mbytes read = \033[0m%zd\n", buf1, bytes1);
            
            close(fd);
            printf("\n");
            
            ssize_t bytes2;

            fd = open(file, O_RDONLY);    
            if (fd == -1) {
                printf("\033[31mError open file\033[0m\n");
                return (1);
            }
            bytes2 = ft_read(fd, buf2, size - 1);
            if (bytes2 == -1)
                printf("\033[31mError ft_read fct\033[0m\n");            
            buf2[bytes2] = '\0';

            printf("\033[33mBuf ft_read => \033[0m\n%s\n\n\033[33mbytes ft_read = \033[0m%zd\n", buf2, bytes2);

            close(fd);
            printf("\n");

            printf("Empty_file test >>\n");
            ssize_t bytes3;

            fd = open(empty_file, O_RDONLY);
            if (fd == -1) {
                printf("\033[31mError open file\033[0m\n");
                return (1); 
            }
            bytes3 = read(fd, buf3, size - 1);
            if (bytes3 == -1)
                printf("\033[31mError read fct\033[0m\n");            
            buf3[bytes3] = '\0';

            printf("\033[32mBuf read => \033[0m\n%s\033[32mbytes read = \033[0m%zd\n", buf3, bytes3);

            close(fd);
            printf("\n");

            ssize_t bytes4;

            fd = open(empty_file, O_RDONLY);
            if (fd == -1) {
                printf("\033[31mError open file\033[0m\n");
                return (1); 
            }
            bytes4 = ft_read(fd, buf4, size - 1);
            if (bytes4 == -1)
                printf("\033[31mError ft_read fct\033[0m\n");          
            buf4[bytes4] = '\0';

            printf("\033[33mBuf ft_read => \033[0m\n%s\033[33mbytes read = \033[0m%zd\n", buf4, bytes4);

            close(fd);
            printf("\n");

            if (cas != 0)
                break;
        case 6:
            //////////////////////////
            //      FT_STRDUP       //
            //////////////////////////
            printf("\033[31m----- FT_STRDUP -----\033[0m\n\n");

            char    *new1 = strdup(str6);
            if (!new1)
                printf("\033[31mstrdup null\033[0m");

            printf("\033[32mreal strdup = \033[0m%s\n", new1);
            printf("\033[32mreal strlen = \033[0m%lu\n", strlen(new1));

            char    *new2 = ft_strdup(str6);
            if (!new2)
                printf("\033[31m ft_strdup null\033[0m");
    
            printf("\033[33mmy ft_strdup = \033[0m%s\n", new2);
            printf("\033[33mmy ft_stlen = \033[0m%zu\n", ft_strlen(new2));
            
            free(new1);
            free(new2);
            printf("\n");

            new1 = strdup(empty_str);
            if (!new1)
                printf("\033[31mstrdup null\033[0m");

            printf("\033[32mreal strdup = \033[0m%s\n", new1);
            printf("\033[32mreal strlen = \033[0m%lu\n", strlen(new1));
            
            new2 = ft_strdup(empty_str);
            if (!new2)
                printf("\033[31m ft_strdup null\033[0m");
    
            printf("\033[33mmy ft_strdup = \033[0m%s\n", new2);
            printf("\033[33mmy ft_stlen = \033[0m%zu\n", ft_strlen(new2));
            
            free(new1);
            free(new2);
            printf("\n");

            new1 = strdup(one_c);
            if (!new1)
                printf("\033[31mstrdup null\033[0m");

            printf("\033[32mreal strdup = \033[0m%s\n", new1);
            printf("\033[32mreal strlen = \033[0m%lu\n", strlen(new1));

            new2 = ft_strdup(one_c);
            if (!new2)
                printf("\033[31m ft_strdup null\033[0m");
    
            printf("\033[33mmy ft_strdup = \033[0m%s\n", new2);
            printf("\033[33mmy ft_stlen = \033[0m%zu\n", ft_strlen(new2));

            free(new1);
            free(new2);
            printf("\n");

            new1 = strdup(l_str);
            if (!new1)
                printf("\033[31mstrdup null\033[0m");

            printf("\033[32mreal strdup = \033[0m%s\n", new1);
            printf("\033[32mreal strlen = \033[0m%lu\n", strlen(new1));

            new2 = ft_strdup(l_str);
            if (!new2)
                printf("\033[31m ft_strdup null\033[0m");
    
            printf("\033[33mmy ft_strdup = \033[0m%s\n", new2);
            printf("\033[33mmy ft_stlen = \033[0m%zu\n", ft_strlen(new2));

            free(new1);
            free(new2);
            printf("\n");

            new1 = strdup(str);
            if (!new1)
                printf("\033[31mstrdup null\033[0m");

            printf("\033[32mreal strdup = \033[0m%s\n", new1);
            printf("\033[32mreal strlen = \033[0m%lu\n", strlen(new1));

            new2 = ft_strdup(str);
            if (!new2)
                printf("\033[31m ft_strdup null\033[0m");
    
            printf("\033[33mmy ft_strdup = \033[0m%s\n", new2);
            printf("\033[33mmy ft_stlen = \033[0m%zu\n", ft_strlen(new2));

            printf("res strcmp = %d\n", strcmp(str, new2));

            free(new1);
            free(new2);
            printf("\n");

            break;

        default:
            printf("Default switch case.\n");
    }
    return (0);
}