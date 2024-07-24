
#include <stdio.h>
#include <stdlib.h>

extern unsigned int ft_strlen(const char* str);
extern char*        ft_strcpy(char *dest, const char* src);

int main(int argc, char **argv) {
    
    if (argc != 2)
        return (0);

    //////////////////////////
    //      FT_STRLEN       //
    //////////////////////////

    const char  *str = argv[1];
    int         len = ft_strlen(str);

    printf("string 1 = %s\n", str);
    printf("ft_strlen 1 = %d\n", len);

    const char  *str2 = "strlen static";
    int         len2 = ft_strlen(str2);

    printf("string 2 = %s\n", str2);
    printf("ft_strlen 2 = %d\n\n", len2);

    //////////////////////////
    //      FT_STRCPY       //
    //////////////////////////

    const char  *src = "ft_strcpy";
    int         src_len = ft_strlen(src);
    char        *dest = malloc(sizeof(char) * (src_len + 1));

    ft_strcpy(dest, src);
    printf("src = %s\ndest = %s\n", src, dest);
    
    free(dest);
    
    //////////////////////////
    //      FT_WRITE        //
    //////////////////////////

    return (0);
}