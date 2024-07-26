#include <string.h> //strlen //strcpy //strcmp //strdup
#include <unistd.h> //write //read

#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <sys/types.h>//open
#include <sys/stat.h>//open
#include <fcntl.h>//open

extern size_t   ft_strlen(const char* str);
extern char*    ft_strcpy(char *dest, const char* src);
extern int      ft_strcmp(const char *s1, const char *s2);
extern ssize_t  ft_write(int fd, const void *buf, size_t nbyte);
extern ssize_t  ft_read(int fd, void *buf, size_t nbyte);
extern char*    ft_strdup(const char* s);

int main(int argc, char **argv) {
    
    if (argc != 2)
        return (0);

    //////////////////////////
    //      FT_STRLEN       //
    //////////////////////////
    printf("----- Start Test FT_STRLEN -----\n\n");

    const char  *str = argv[1];
    int         len = ft_strlen(str);

    printf("string argv[1] = %s\n", str);
    printf("ft_strlen size argv[1] = %d\n", len);
    printf("real strlen string.h argv[1] = %lu\n", strlen(str));
    printf("\n");
    const char  *str2 = "";
    int         len2 = ft_strlen(str2);

    printf("str static = %s\n", str2);
    printf("ft_strlen size str static = %d\n", len2);
    printf("real strlen string.h str static = %lu\n", strlen(str2));
    printf("\n");
    
    //////////////////////////
    //      FT_STRCPY       //
    //////////////////////////
    printf("----- Start Test FT_STRCPY -----\n\n");

    const char  *src = "Test!Test!\n";
    int         src_len = ft_strlen(src);
    char        *dest = malloc(sizeof(char) * (src_len + 1));
    char        *dest2 = malloc(sizeof(char) * (src_len + 1));

    ft_strcpy(dest, src);
    printf("src = %sdest = %s\n", src, dest);
    
    strcpy(dest2, src);
    printf("src = %sdest = %s\n",src, dest2);

    free(dest2);
    free(dest);
    printf("\n");
    
    //////////////////////////
    //      FT_STRCMP       //
    //////////////////////////
    printf("----- Start Test FT_STRCMP -----\n\n");

    const char  *s1 = argv[1];
    const char  *s2 = "Test!";

    int         res1 = ft_strcmp(s1, s2);
    int         res2 = strcmp(s1, s2);

    printf("s1 = %s, s2 = %s\nft_strcmp res = %d\nstrcmp res = %d\n", s1, s2, res1, res2);
    printf("\n");
    
    //////////////////////////
    //      FT_WRITE        //
    //////////////////////////
    printf("----- Start Test FT_WRITE -----\n\n");

    const char  *s3 = argv[1];
    const char  *s4 = "789675 lolololo 321213.?????";
    const char  *err = "";

    size_t      len_s3 = ft_strlen(s3);
    size_t      len_s4 = ft_strlen(s4);
    
    printf("real write unistd.h argv[1]\n");
    printf("res write = %zd\n", write(1, s3, len_s3));
    printf("\n\n");

    printf("ft_write argv[1]\n");
    printf("res ft_write = %zd\n", ft_write(1, s3, len_s3));
    printf("\n\n");

    printf("real write unistd.h str static\n");
    printf("res write = %zd\n", write(1, s4, len_s4));
    printf("\n\n");

    printf("ft_write str static\n");
    printf("res ft_write = %zd\n", ft_write(1, s4, len_s4));
    printf("\n\n");

    printf("real write unistd.h empty str\n");
    printf("res write = %zd\n", write(1, err, 0));
    printf("\n\n");

    printf("ft_write empty str\n");
    printf("res ft_write = %zd\n", ft_write(1, err, 0));
    printf("\n");

    //////////////////////////
    //      FT_READ         //
    //////////////////////////
    printf("----- Start Test FT_READ -----\n\n");

    int     size = 150;

    char    buf_real[size];
    ssize_t bytesreadreal;
    int     fd = open("ft_strlen.s", O_RDONLY);
    
    if (fd == -1) {
        printf("Error open fct\n");
        return (1);
    }

    bytesreadreal = read(fd, buf_real, size - 1);
    if (bytesreadreal == -1)
        printf("Error read fct\n");
    buf_real[bytesreadreal] = '\0';
    
    printf("Buf for real read = %s\n\nbytes read = %zd\n", buf_real, bytesreadreal);
    close(fd);
    printf("\n");

    char    buf[size];
    ssize_t bytesread;

    fd = open("ft_strlen.s", O_RDONLY);    
    if (fd == -1) {
        printf("Error open fct\n");
        return (1);
    }

    bytesread = ft_read(fd, buf, size - 1);
    if (bytesread == -1)
        printf("Error ft_read fct\n");

    buf[bytesread] = '\0';
    printf("Buf for ft_read = %s\n\nbytes ft_read = %zd\n", buf, bytesread);

    close(fd);
    printf("\n");
    
    //////////////////////////
    //      FT_STRDUP       //
    //////////////////////////
    printf("----- Start Test FT_STRDUP -----\n\n");

    const char  *s5 = "YES - NO.";
    char        *s6 = strdup(s5);
    printf("real strdup = %s\n", s6);

    char        *s7 = ft_strdup(s5);
    printf("my ft_strdup = %s\n", s7);
    
    free(s6);
    free(s7);

    const char  *n = "";
    s6 = strdup(n);
    if (s6 == NULL)
        printf("s6 est null");
    printf("real strdup = %s\n", s6);

    s7 = ft_strdup(n);
    printf("my ft_strdup = %s\n", s7);
    
    free(s6);
    free(s7);
    
    return (0);
}