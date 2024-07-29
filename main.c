#include <string.h> //strlen //strcpy //strcmp //strdup
#include <unistd.h> //write //read

#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <fcntl.h>//open

size_t   ft_strlen(const char* str);
char*    ft_strcpy(char *dest, const char* src);
int      ft_strcmp(const char *s1, const char *s2);
ssize_t  ft_write(int fd, const void *buf, size_t nbyte);
ssize_t  ft_read(int fd, void *buf, size_t nbyte);
char*    ft_strdup(const char* s);

int main(int argc, char **argv) {
    
    if (argc != 2)
        return (0);

    //////////////////////////
    //      FT_STRLEN       //
    //////////////////////////
    printf("\033[31m----- Start Test FT_STRLEN -----\033[0m\n\n");

    const char  *str = argv[1];
    int         len = ft_strlen(str);

    printf("string argv[1] = %s\n", str);
    printf("\033[33mft_strlen size argv[1] = \033[0m%d\n", len);
    printf("\033[32mreal strlen string.h argv[1] = \033[0m%lu\n", strlen(str));
    printf("\n");
    
    const char  *str2 = "";
    int         len2 = ft_strlen(str2);

    printf("str empty = \033[0m%s\n", str2);
    printf("\033[33mft_strlen size str empty = \033[0m%d\n", len2);
    printf("\033[32mreal strlen string.h str empty = \033[0m%lu\n", strlen(str2));
    printf("\n");

    const char  *str3 = "testtesttsttesttetsttest";
    int         len3 = ft_strlen(str3);

    printf("str static = \033[0m%s\n", str3);
    printf("\033[33mft_strlen size str static = \033[0m%d\n", len3);
    printf("\033[32mreal strlen string.h str static = \033[0m%lu\n", strlen(str3));
    printf("\n");

    //////////////////////////
    //      FT_STRCPY       //
    //////////////////////////
    printf("\033[31m----- Start Test FT_STRCPY -----\033[0m\n\n");

    const char  *src = "Test!Test!\n";
    int         src_len = ft_strlen(src);
    char        *dest = malloc(sizeof(char) * (src_len + 1));
    char        *dest2 = malloc(sizeof(char) * (src_len + 1));

    ft_strcpy(dest, src);
    printf("\033[33mft_strcpy\033[0m\n");
    printf("\033[33msrc = %sdest = %s\033[0m\n", src, dest);
    
    strcpy(dest2, src);
    printf("\033[32mstrcpy string.h\033[0m\n");
    printf("\033[32msrc = %sdest = %s\033[0m\n",src, dest2);

    free(dest2);
    free(dest);
    printf("\n");
    
    //////////////////////////
    //      FT_STRCMP       //
    //////////////////////////
    printf("\033[31m----- Start Test FT_STRCMP -----\033[0m\n\n");

    const char  *s1 = argv[1];
    const char  *s2 = "Test!";

    const char  *s10 = "Static string\n";
    const char  *s11 = "Static string\n";

    const char  *s12 = "";
    const char  *s13 = "S";
    
    int         res1 = strcmp(s1, s2);
    int         res2 = ft_strcmp(s1, s2);
    
    int         res10 = strcmp(s10, s11);
    int         res11 = ft_strcmp(s10, s11);

    int         res12 = strcmp(s12, s13);
    int         res13 = ft_strcmp(s12, s13);

    int         res14 = strcmp(s13, s12);
    int         res15 = ft_strcmp(s13, s12);   

    printf("s1 = %s | s2 = %s\n", s1, s2);
    printf("\033[32mstrcmp res = \033[0m%d\n", res1);
    printf("\033[33mft_strcmp res = \033[0m%d\n", res2);
    printf("\n");

    printf("s10 = %ss11 = %s\n", s10, s11);
    printf("\033[32mstrcmp res = \033[0m%d\n", res10);
    printf("\033[33mft_strcmp res = \033[0m%d\n", res11);
    printf("\n");

    printf("s12 = %s | s13 = %s\n", s12, s13);
    printf("\033[32mstrcmp res = \033[0m%d\n", res12);
    printf("\033[33mft_strcmp res = \033[0m%d\n", res13);
    printf("\n");

    printf("reverse s12 <-> s13\n");
    printf("\033[32mstrcmp res = \033[0m%d\n", res14);
    printf("\033[33mft_strcmp res = \033[0m%d\n", res15);
    printf("\n");

    //////////////////////////
    //      FT_WRITE        //
    //////////////////////////
    printf("\033[31m----- Start Test FT_WRITE -----\033[0m\n\n");

    const char  *s3 = argv[1];
    const char  *s4 = "789675 lolololo 321213.?????";
    const char  *err = "";

    size_t      len_s3 = ft_strlen(s3);
    size_t      len_s4 = ft_strlen(s4);
    
    printf("\033[32mwrite unistd.h argv[1] =>\033[0m\n");
    printf("\033[32m\nres write = \033[0m%zd\n", write(1, s3, len_s3));
    printf("\n\n");

    printf("\033[33mft_write argv[1] =>\033[0m\n");
    printf("\033[33m\nres ft_write = \033[0m%zd\n", ft_write(1, s3, len_s3));
    printf("\n\n");

    printf("\033[32mwrite unistd.h str static =>\033[0m\n");
    printf("\033[32m\nres write = \033[0m%zd\n", write(1, s4, len_s4));
    printf("\n\n");

    printf("\033[33mft_write str static =>\033[0m\n");
    printf("\033[33m\nres ft_write = \033[0m%zd\n", ft_write(1, s4, len_s4));
    printf("\n\n");

    printf("\033[32mwrite unistd.h empty str =>\033[0m\n");
    printf("\033[32mres write = \033[0m%zd\n", write(1, err, 0));
    printf("\n\n");

    printf("\033[33mft_write empty str =>\033[0m\n");
    printf("\033[33mres ft_write = \033[0m%zd\n", ft_write(1, err, 0));
    printf("\n");

    //////////////////////////
    //      FT_READ         //
    //////////////////////////
    printf("\033[31m----- Start Test FT_READ -----\033[0m\n\n");

    int     size = 150;

    char    buf_real[size];
    ssize_t bytesreadreal;
    int     fd = open("ft_strlen.s", O_RDONLY);
    
    if (fd == -1) {
        printf("\033[31mError open fct\033[0m\n");
        return (1);
    }

    bytesreadreal = read(fd, buf_real, size - 1);
    if (bytesreadreal == -1)
        printf("\033[31mError read fct\033[0m\n");
    buf_real[bytesreadreal] = '\0';
    
    printf("\033[32mBuf read unistd.h => \033[0m\n%s\n\n\033[32mbytes read = \033[0m%zd\n", buf_real, bytesreadreal);
    close(fd);
    printf("\n");

    char    buf[size];
    ssize_t bytesread;

    fd = open("ft_strlen.s", O_RDONLY);    
    if (fd == -1) {
        printf("\033[31mError open fct\033[0m\n");
        return (1);
    }

    bytesread = ft_read(fd, buf, size - 1);
    if (bytesread == -1)
        printf("\033[31mError ft_read fct\033[0m\n");

    buf[bytesread] = '\0';
    printf("\033[33mBuf ft_read => \033[0m\n%s\n\n\033[33mbytes ft_read = \033[0m%zd\n", buf, bytesread);

    close(fd);
    printf("\n");
    
    char    


    //////////////////////////
    //      FT_STRDUP       //
    //////////////////////////
    printf("\033[31m----- Start Test FT_STRDUP -----\033[0m\n\n");

    const char  *s5 = "YES - NO.";
    
    char        *s6 = strdup(s5);
    if (s6 == NULL)
        printf("\033[31mstrdup null\033[0m");

    printf("\033[32mreal strdup = \033[0m%s\n", s6);

    char        *s7 = ft_strdup(s5);
    if (s7 == NULL)
        printf("\033[31m ft_strdup null\033[0m");
    
    printf("\033[33mmy ft_strdup = \033[0m%s\n", s7);
    
    free(s6);
    free(s7);
    printf("\n");
    const char  *n = "";
    
    s6 = strdup(n);
    if (s6 == NULL)
        printf("\033[31mstrdup null\033[0m");
    
    printf("\033[32mreal strdup = \033[0m%s\n", s6);

    s7 = ft_strdup(n);
        if (s7 == NULL)
        printf("\033[31mft_strdup null\033[0m");

    printf("\033[33mmy ft_strdup = \033[0m%s\n", s7);
    
    free(s6);
    free(s7);
    
    return (0);
}