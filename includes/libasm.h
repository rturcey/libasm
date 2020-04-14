#ifndef LIBASM_H
# define LIBASM_H

int      ft_strlen(const char *s);
int      ft_strcmp(const char *s1, const char *s2);
char    *ft_strcpy(char *dest, const char *src);
ssize_t  ft_write(int fd, const void *buf, size_t nbyte);
ssize_t  ft_read(int fd, void *buf, size_t nbyte);
char    *ft_strdup(const char *s);
int      ft_atoi_base(const char *s, const char *base);



typedef struct          s_list
{
        void            *data;
        struct s_list   *next;
}                       t_list;

void    ft_list_push_front(t_list **begin_list, void *data);
int    ft_list_sort(t_list **begin_list, int (*cmp)());

#endif