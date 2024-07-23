
#include <stdio.h>

extern int ft_strlen(const char* str);

int main(int argc, char **argv) {
    
    //      FT_STRLEN       //
    if (argc <= 1)
        return (1);
    const char    *str = argv[1];
    int     len = ft_strlen(str);

    printf("string = %s\n", str);
    printf("ft_strlen = %d\n", len);

    //      FT_WRITE        //
    
    return (0);
}