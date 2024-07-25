#include <string.h> //strlen //strcpy //strcmp

#include <stdio.h> //printf
#include <stdlib.h> //malloc

extern size_t   ft_strlen(const char* str);
extern char*    ft_strcpy(char *dest, const char* src);
extern int      ft_strcmp(const char *s1, const char *s2);

int main(int argc, char **argv) {
    
    //if (argc != 2)
    //    return (0);
//
    ////////////////////////////
    ////      FT_STRLEN       //
    ////////////////////////////
//
    //const char  *str = argv[1];
    //int         len = ft_strlen(str);
//
    //printf("string argv[1] = %s\n", str);
    //printf("ft_strlen size argv[1] = %d\n", len);
    //printf("real strlen string.h argv[1] = %lu\n", strlen(str));
    //printf("\n");
    //const char  *str2 = "Test!";
    //int         len2 = ft_strlen(str2);
//
    //printf("str static = %s\n", str2);
    //printf("ft_strlen size str static = %d\n", len2);
    //printf("real strlen string.h str static = %lu\n", strlen(str2));
    //printf("\n");
    ////////////////////////////
    ////      FT_STRCPY       //
    ////////////////////////////
//
    //const char  *src = "Test!Test!\n";
    //int         src_len = ft_strlen(src);
    //char        *dest = malloc(sizeof(char) * (src_len + 1));
    //char        *dest2 = malloc(sizeof(char) * (src_len + 1));
//
    //ft_strcpy(dest, src);
    //printf("src = %sdest = %s\n", src, dest);
    //
    //strcpy(dest2, src);
    //printf("src = %sdest = %s\n",src, dest2);
//
    //free(dest2);
    //free(dest);
    //printf("\n");
    ////////////////////////////
    ////      FT_STRCMP       //
    ////////////////////////////
//
    const char  *s1 = argv[1];
    const char  *s2 = "Test!";

    int         res1 = ft_strcmp(s1, s2);
    int         res2 = strcmp(s1, s2);

    printf("s1 = %s, s2 = %s\nft_strcmp res = %d\nstrcmp res = %d\n", s1, s2, res1, res2);

    printf("\n\n");

    return (0);
}