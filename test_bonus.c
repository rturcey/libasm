#include "libasm.h"

void    ft_del(void *data)
{
    free(data);
    data = NULL;
}

int main(void)
{
    char    *s1 = "ABCDEFGHIJKL";
    char    *s2 = "ABCDEFGHIJKM";
    char    *s3 = "0123456789";
    char    *s4 = "";
    char    s5[20];
    char    s6[20];
    int     i;

    i = -1;
    while (++i < 20)
    {
        s5[i] = 0;
        s6[i] = 0;
    }
    printf("=================================================\n");
    printf("s1 = \"%s\" | s2 = \"%s\" | s3 = \"%s\" | s4 = \"%s\"\n\n", s1, s2, s3, s4);

    printf("=================== FT_STRLEN ===================\n");
    printf("(strlen/ft_strlen) : s1(%lu/%lu), s2(%lu/%lu), s3(%lu/%lu), s4(%lu/%lu)\n", \
    strlen(s1), ft_strlen(s1), strlen(s2), ft_strlen(s2), strlen(s3), ft_strlen(s3), strlen(s4), ft_strlen(s4));

    printf("\n=================== FT_STRCMP ===================\n");
    printf("(strcmp/ft_strcmp) : s1/s2(%d/%d), s2/s3(%d/%d), s3/s3(%d/%d), s1/s4(%d/%d)\n", \
    strcmp(s1, s2), ft_strcmp(s1, s2), strcmp(s2, s3), ft_strcmp(s2, s3), strcmp(s3, s3), ft_strcmp(s3, s3), strcmp(s1, s4), ft_strcmp(s1, s4));
    
    printf("\n=================== FT_STRCPY ===================\n");
    printf("dest before = \"%s\"\n", s5);
    printf("(strcpy/ft_strcpy)\n");
    printf("s1(\"%s\"/\"%s\")\n", strcpy(s5, s1), ft_strcpy(s5, s1));
    printf("s4(\"%s\"/\"%s\")\n", strcpy(s5, s4), ft_strcpy(s5, s4));

    printf("\n============== FT_WRITE & FT_READ ===============\n");
    int     fd1 = open("1.txt", O_WRONLY);
    int     fd2 = open("2.txt", O_WRONLY);
    ft_write(1, "Writing 2x .txt...\n", strlen("Writing 2x .txt...\n"));
    char    *w1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut in dolor odio. Curabitur porta libero ut libero suscipit pretium. Maecenas gravida, risus a sollicitudin bibendum, est nibh posuere ante, facilisis tempor dolor mi ut nisi. Pellentesque arcu est, sagittis ut posuere quis, egestas sed eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce vitae mi mauris. Phasellus in ultricies neque. Etiam vel facilisis ante, dapibus luctus enim. Suspendisse eu fringilla erat. Ut feugiat eleifend ipsum, vitae commodo quam cursus nec. Nulla sed accumsan mi, sit amet malesuada lorem. Nunc vitae eleifend elit. ";
    char    *w2 = "";
    ft_write(fd1, w1, strlen(w1));
    ft_write(fd2, w2, strlen(w2));
    ft_write(1, "Write error test :\n", strlen("Write error test :\n"));
    printf("(write/ft_write) : fd=-1(%li/%li), fd=500(%li/%li)\n\n", \
    write(-1, "blabla", 6), ft_write(-1, "blabla", 6), write(500, "blabla", 6), ft_write(500, "blabla", 6));
    close(fd1);
    close(fd2);
    fd1 = open("1.txt", O_RDONLY);
    fd2 = open("2.txt", O_RDONLY);
    char    buffer1[33];
    char    buffer2[33];
    i = -1;
    while(++i < 33)
    {
        buffer1[i] = 0;
        buffer2[i] = 0;
    }
    i = read(fd1, buffer1, 32);
    int j = read(fd2, buffer2, 32);
    printf("1) with read (ret %d):\n%s\n", i, buffer1);
    printf("2) with read (ret %d):\n%s\n", j, buffer2);
    close(fd1);
    close(fd2);
    fd1 = open("1.txt", O_RDONLY);
    fd2 = open("2.txt", O_RDONLY);
    i = -1;
    while(++i <= 32)
    {
        buffer1[i] = 0;
        buffer2[i] = 0;
    }
    i = read(fd1, buffer1, 32);
    j = ft_read(fd2, buffer2, 32);
    printf("1) with ft_read (ret %d):\n%s\n", i, buffer1);
    printf("2) with ft_read (ret %d):\n%s\n", j, buffer2);
    close(fd1);
    close(fd2);
    printf("Read error test :\n(read/ft_read) : fd=-1(%li/%li), wrongfd(%li/%li), buffNULL(%li, %li)\n", \
    read(-1, buffer1, 32), ft_read(-1, buffer1, 32), read(543, buffer1, 32), ft_read(543, buffer1, 32), read(0, NULL, 10), ft_read(0, NULL, 10));

    printf("\n=================== FT_STRDUP ===================\n");
    s2 = strdup(s1);
    s3 = ft_strdup(s1);
    printf("with strdup (strdup(s1)): %s\n", s2);
    printf("with ft_strdup (ft_strdup(s1)): %s\n", s3);
    free(s2);
    free(s3);
    s2 = strdup("");
    s3 = ft_strdup("");
    printf("with strdup (strdup("")): %s\n", s2);
    printf("with ft_strdup (ft_strdup("")): %s\n", s3);
    free(s2);
    free(s3);
  
    printf("\n=================== ATOI_BASE ===================\n");
    
    char    *nb = "    ++---2AJKL";
    char    *base = "0123456789ABCDEF";
    printf("/!\\ multiple '-' accepted\n");
    printf("nb : %20s, base : %20s | atoi_base = %d\n", nb, base, ft_atoi_base(nb, base));
    nb = "   +++----101010bli";
    base = "01";
    printf("nb : %20s, base : %20s | atoi_base = %d\n", nb, base, ft_atoi_base(nb, base));
    nb = "  --1474462";
    base = "01234567";
    printf("nb : %20s, base : %20s | atoi_base = %d\n", nb, base, ft_atoi_base(nb, base));

    printf("\n============== FT_LIST_PUSH_FRONT ===============\n");
    
    t_list  *test;

    test = malloc(sizeof(t_list));
    test->data = ft_strdup("elt 1");
    test->next = NULL;
    printf("New list with one element, data : elt 1\n");
    printf("Pushing front 3 other elements, from 2 to 9. Full list printed :\n");
    ft_list_push_front(&test, ft_strdup("elt 2"));
    ft_list_push_front(&test, ft_strdup("elt 3"));
    ft_list_push_front(&test, ft_strdup("elt 4"));
    ft_list_push_front(&test, ft_strdup("elt 5"));
    ft_list_push_front(&test, ft_strdup("elt 6"));
    ft_list_push_front(&test, ft_strdup("elt 7"));
    ft_list_push_front(&test, ft_strdup("elt 8"));
    ft_list_push_front(&test, ft_strdup("elt 9"));
    t_list  *tmp;
    tmp = test;
    i = 0;
    while (test)
    {
        printf("DATA %d = %s\n", i, test->data);
        i++;
        test = test->next;
    }
    test = tmp;

    printf("\n================= FT_LIST_SIZE ==================\n");

    printf("Size since elt 1 = %d\n", ft_list_size(test));
    printf("Size since elt 1->next = %d\n", ft_list_size(test->next));
    
    printf("\n================= FT_LIST_SORT ==================\n");
    printf("Let's sort using strcmp !\n");
    ft_list_sort(&test, &strcmp);
    tmp = test;
    i = 0;
    while (test)
    {
        printf("DATA %d = %s\n", i, test->data);
        i++;
        test = test->next;
    }
    test = tmp;
    printf("\n============== FT_LIST_REMOVE_IF ================\n");
    char    *cp = "elt 5";
    printf("remove elt 5\n");
    ft_list_remove_if(&test, cp, &strcmp, &ft_del);
    tmp = test;
    i = 0;
    while (test)
    {
        printf("DATA %d = %s\n", i, test->data);
        i++;
        test = test->next;
    }
    test = tmp;
    cp = "elt 1";
    printf("remove elt 1\n");
    ft_list_remove_if(&test, cp, &strcmp, &ft_del);
    tmp = test;
    i = 0;
    while (test)
    {
        printf("DATA %d = %s\n", i, test->data);
        i++;
        test = test->next;
    }
    test = tmp;
    cp = "elt 9";
    printf("remove elt 9\n");
    ft_list_remove_if(&test, cp, &strcmp, &ft_del);
    tmp = test;
    i = 0;
    while (test)
    {
        printf("DATA %d = %s\n", i, test->data);
        i++;
        test = test->next;
    }
    test = tmp;
    while (test)
    {
        tmp = test->next;
        free(test->data);
        free(test);
        test = tmp;

    }
    return (0);
}