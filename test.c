#include <stdio.h>
#include "libasm.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_list  *test = NULL;
    (void)argc;
    printf("Len is %d\n", ft_strlen(argv[1]));
    char dst[100];
    
    printf("Cmp is %d\n", ft_strcmp(argv[1], argv[2]));
    printf("CmpTrue is %d\n", strcmp(argv[1], argv[2]));
    printf("Rtn is %s\n", ft_strcpy(dst, argv[1]));
    printf("Cpy is %s\n", dst);
    int     fd = open("test.txt", O_WRONLY);
    int     fd1 = open("test1.txt", O_WRONLY);
    char *ch1 = "Avec vraie fonction\n";
    char *ch2 = "Avec notre fonction\n";
    char buff[100];
    printf("Ret true write = %ld\n", write(fd, ch1, strlen(ch1)));
    printf("Ret our write = %ld\n", ft_write(fd1, ch2, strlen(ch2)));
    close(fd);
    close(fd1);
    fd = open("test.txt", O_RDONLY);
    fd1 = open("test1.txt", O_RDONLY);
    printf("Ret true read = %ld\n", read(fd, buff, 50));
    printf("read -> \"%s\"\n", buff);
    printf("Ret our read = %ld\n", ft_read(fd1, buff, 50));
    printf("read -> \"%s\"\n", buff);
    close(fd);
    close(fd1);
    char *ch3 = NULL;
    ch3 = ft_strdup("bibou");
    printf("Our strdup = %s\n", ch3);
    printf("1 ft_atoi_base Ret = %d\n", ft_atoi_base("123", "abcdd"));
    printf("2 ft_atoi_base Ret = %d\n", ft_atoi_base("       -++--123", "0123456789"));
    printf("3 ft_atoi_base Ret = %d\n", ft_atoi_base("123", "ab"));
    printf("4 ft_atoi_base Ret = %d\n", ft_atoi_base("123", ""));
    printf("5 ft_atoi_base Ret = %d\n", ft_atoi_base("123", "ab+cd"));
    printf("6 ft_atoi_base Ret = %d\n", ft_atoi_base("     +++++++---C", "0123456789ABCDEF"));
    printf("7 ft_atoi_base Ret = %d\n", ft_atoi_base("1100", "01"));

    printf("%d\n", atoi("00000"));
    test = malloc(sizeof(t_list));
    test->data = "elt 12";
    test->next = NULL;
    ft_list_push_front(&test, "elt 73");
    ft_list_push_front(&test, "elt 28");
    ft_list_push_front(&test, "elt 32");
    t_list  *tmp;
    tmp = test;
    while (test)
    {
        printf("DATA = %s\n", test->data);
        test = test->next;
    }
    test = tmp;
    printf("Let's sort !\n");
    ft_list_sort(&test, &strcmp);
    while (test)
    {
        printf("DATA = %s\n", test->data);
        test = test->next;
    }
    test = tmp;
    return (0);
}