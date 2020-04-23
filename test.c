#include "libasm.h"

int main(void)
{
    char        *s1 = "ABCDEFGHIJKL";
    char        *s2 = "ABCDEFGHIJKM";
    char        *s3 = "0123456789";
    char        *s4 = "";
    char        s5[20];
    char        s6[20];
    int         i;
    int         errno_true;
    int         errno_ft;
    long int    ret_true;
    long int    ret_ft;
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
    printf("(strcmp/ft_strcmp) : s1/s2(%d/%d)\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    printf("s2/s3(%d/%d)\n", strcmp(s2, s3), ft_strcmp(s2, s3));
    printf("s3/s3(%d/%d)\n", strcmp(s3, s3), ft_strcmp(s3, s3));
    printf("s1/s4(%d/%d)\n", strcmp(s1, s4), ft_strcmp(s1, s4));
    printf("\n=================== FT_STRCPY ===================\n");
    printf("dest before = \"%s\"\n", s5);
    printf("(strcpy/ft_strcpy)\n");
    printf("s1(\"%s\"/\"%s\")\n", strcpy(s5, s1), ft_strcpy(s5, s1));
    printf("s4(\"%s\"/\"%s\")\n", strcpy(s5, s4), ft_strcpy(s5, s4));
    printf("\n============== FT_WRITE & FT_READ ===============\n");
    int fd1 = open("1.txt", O_CREAT | O_RDWR, 0666);
    int fd2 = open("2.txt", O_CREAT | O_RDWR, 0666);
    ft_write(1, "Writing 2x .txt...\n", strlen("Writing 2x .txt...\n"));
    char    *w1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut in dolor odio. Curabitur porta libero ut libero suscipit pretium. Maecenas gravida, risus a sollicitudin bibendum, est nibh posuere ante, facilisis tempor dolor mi ut nisi. Pellentesque arcu est, sagittis ut posuere quis, egestas sed eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce vitae mi mauris. Phasellus in ultricies neque. Etiam vel facilisis ante, dapibus luctus enim. Suspendisse eu fringilla erat. Ut feugiat eleifend ipsum, vitae commodo quam cursus nec. Nulla sed accumsan mi, sit amet malesuada lorem. Nunc vitae eleifend elit. ";
    char    *w2 = "";
    ft_write(fd1, w1, strlen(w1));
    ft_write(fd2, w2, strlen(w2));
    ft_write(1, "Write error test :\n", strlen("Write error test :\n"));
    ret_true = write(-1, "blabla", 6);
    errno_true = errno;
    ret_ft = ft_write(-1, "blabla", 6);
    errno_ft = errno;
    printf("(write/ft_write) : fd=-1(%li errno %d/%li errno %d)\n", ret_true, errno_true, ret_ft, errno_ft);
    ret_true = write(500, "blabla", 6);
    errno_true = errno;
    ret_ft = ft_write(500, "blabla", 6);
    errno_ft = errno;
    printf("(write/ft_write) : fd=500(%li errno %d/%li errno %d)\n", ret_true, errno_true, ret_ft, errno_ft);
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
    errno_true = errno;
    printf("1) with read (ret %d):[%s]errno %d\n", i, buffer1, errno_true);
    int j = read(fd2, buffer2, 32);
    errno_true = errno;
    printf("1) with read (ret %d):[%s]errno %d\n", j, buffer2, errno_true);
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
    i = ft_read(fd1, buffer1, 32);
    errno_ft = errno;
    printf("2) with ft_read (ret %d):[%s] errno %d\n", i, buffer1, errno_ft);
    j = ft_read(fd2, buffer2, 32);
    errno_ft = errno;
    printf("2) with ft_read (ret %d):[%s] errno %d\n", j, buffer2, errno_ft);
    close(fd1);
    close(fd2);
    ret_true = read(-1, buffer1, 32);
    errno_true = errno;
    ret_ft = ft_read(-1, buffer1, 32);
    errno_ft = errno;
    printf("Read error test :\n(read/ft_read) : fd=-1(%li errno %d/%li errno %d)\n", ret_true, errno_true, ret_ft, errno_ft);
    ret_true = read(543, buffer1, 32);
    errno_true = errno;
    ret_ft = ft_read(543, buffer1, 32);
    errno_ft = errno;
    printf("Read error test :\n(read/ft_read) : wrongfd(%li errno %d/%li errno %d)\n", ret_true, errno_true, ret_ft, errno_ft);
    ret_true = read(0, NULL, 10);
    errno_true = errno;
    ret_ft = ft_read(0, NULL, 10);
    errno_ft = errno;
    printf("Read error test :\n(read/ft_read) : buffNULL(%li errno %d/%li errno %d)\n", ret_true, errno_true, ret_ft, errno_ft);
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
    return (0);
}
