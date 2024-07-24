
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

    printf("string = %s\n", str);
    printf("ft_strlen = %d\n", len);

    //////////////////////////
    //      FT_STRCPY       //
    //////////////////////////

    const char  *src = str;
    char        *dest = malloc(sizeof(char) * (len + 1));

    dest = ft_strcpy(dest, src);
    printf("src = %s\ndest = %s\n", src, dest);
    
    free(dest);
    
    //////////////////////////
    //      FT_WRITE        //
    //////////////////////////

    return (0);
}