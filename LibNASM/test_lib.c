#include "libasm.h"

void	test_strlen(char *a, char *b, char *c, char *d, char *e)
{
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("**********ft_strlen*********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- \"%s\"\n", a);
	printf("\e[1;34mft_strlen: \e[0m%zu\n", ft_strlen(a));
	printf("\e[1;34mstrlen   : \e[0m%zu\n", strlen(a));
	printf("\n\e[1;33m[2] \e[0m- \"%s\"\n", b);
	printf("\e[1;34mft_strlen: \e[0m%zu\n", ft_strlen(b));
	printf("\e[1;34mstrlen   : \e[0m%zu\n", strlen(b));
	printf("\n\e[1;33m[3] \e[0m- \"%s\"\n", c);
	printf("\e[1;34mft_strlen: \e[0m%zu\n", ft_strlen(c));
	printf("\e[1;34mstrlen   : \e[0m%zu\n", strlen(c));
	printf("\n\e[1;33m[4] \e[0m- \"%s\"\n", d);
	printf("\e[1;34mft_strlen: \e[0m%zu\n", ft_strlen(d));
	printf("\e[1;34mstrlen   : \e[0m%zu\n", strlen(d));
	printf("\n\e[1;33m[5] \e[0m- \"%s\"\n", e);
	printf("\e[1;34mft_strlen: \e[0m%zu\n", ft_strlen(e));
	printf("\e[1;34mstrlen   : \e[0m%zu\n", strlen(e));
	printf("\n\n");
}

void	test_strcpy(char *a, char *b, char *c, char *d, char *e)
{
	char buf[20];
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("**********ft_strcpy*********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- \"%s\"\n", a);
	printf("\e[1;34mft_strcpy: \e[0m\"%s\"\n", ft_strcpy(buf, a));
	printf("\e[1;34mstrcpy   : \e[0m\"%s\"\n", strcpy(buf, a));
	printf("\n\e[1;33m[2] \e[0m- \"%s\"\n", b);
	printf("\e[1;34mft_strcpy: \e[0m\"%s\"\n", ft_strcpy(buf, b));
	printf("\e[1;34mstrcpy   : \e[0m\"%s\"\n", strcpy(buf, b));
	printf("\n\e[1;33m[3] \e[0m- \"%s\"\n", c);
	printf("\e[1;34mft_strcpy: \e[0m\"%s\"\n", ft_strcpy(buf, c));
	printf("\e[1;34mstrcpy   : \e[0m\"%s\"\n", strcpy(buf, c));
	printf("\n\e[1;33m[4] \e[0m- \"%s\"\n", d);
	printf("\e[1;34mft_strcpy: \e[0m\"%s\"\n", ft_strcpy(buf, d));
	printf("\e[1;34mstrcpy   : \e[0m\"%s\"\n", strcpy(buf, d));
	printf("\n\e[1;33m[5] \e[0m- \"%s\"\n", e);
	printf("\e[1;34mft_strcpy: \e[0m\"%s\"\n", ft_strcpy(buf, e));
	printf("\e[1;34mstrcpy   : \e[0m\"%s\"\n", strcpy(buf, e));
	printf("\n\n");
}

void	test_strcmp(char *a, char *a1, char *b, char *b1, char *c, char *c1)
{
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("**********ft_strcmp*********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- \"%s\"-\"%s\"\n", a, a1);
	printf("\e[1;34mft_strcpy: \e[0m%d\n", ft_strcmp(a, a1));
	printf("\e[1;34mstrcpy   : \e[0m%d\n", strcmp(a, a1));
	printf("\n\e[1;33m[2] \e[0m- \"%s\"-\"%s\"\n", b, b1);
	printf("\e[1;34mft_strcpy: \e[0m%d\n", ft_strcmp(b, b1));
	printf("\e[1;34mstrcpy   : \e[0m%d\n", strcmp(b, b1));
	printf("\n\e[1;33m[3] \e[0m- \"%s\"-\"%s\"\n", c, c1);
	printf("\e[1;34mft_strcpy: \e[0m%d\n", ft_strcmp(c, c1));
	printf("\e[1;34mstrcpy   : \e[0m%d\n", strcmp(c, c1));
	printf("\n\e[1;33m[4] \e[0m- \"%s\"-\"%s\"\n", "", "");
	printf("\e[1;34mft_strcpy: \e[0m%d\n", ft_strcmp("", ""));
	printf("\e[1;34mstrcpy   : \e[0m%d\n", strcmp("", ""));
	printf("\n\e[1;33m[5] \e[0m- \"%s\"-\"%s\"\n", "020", "010");
	printf("\e[1;34mft_strcpy: \e[0m%d\n", ft_strcmp("020", "010"));
	printf("\e[1;34mstrcpy   : \e[0m%d\n", strcmp("020", "010"));
	printf("\n\n");
}

void	test_write(int fd, const void *buf, size_t count)
{
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("**********ft_write**********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- arg(1, \"Hello!\", 6)\n");
	printf("\e[1;34mft_write---return ft_write \e[0m\n");
	printf("---%zu\n", ft_write(1, "Hello!", 6));
	printf("\e[1;34mwrite---return write \e[0m\n");
	printf("---%zu\n", write(1, "Hello!", 6));
	printf("\n\e[1;33m[2] \e[0m- arg(1, \"123\", 6)\n");
	printf("\e[1;34mft_write---return ft_write \e[0m\n");
	printf("---%zu\n", ft_write(1, "123", 6));
	printf("\e[1;34mwrite---return write \e[0m\n");
	printf("---%zu\n", write(1, "123", 6));
	printf("\n\e[1;33m[3] \e[0m- arg(45, \"lol\", 0)\n");
	printf("\e[1;34mft_write---return ft_write \e[0m\n");
	printf("---%zu\n", ft_write(45, "lol", 0));
	printf("\e[1;34mwrite---return write \e[0m\n");
	printf("---%zu\n", write(45, "lol", 0));
	printf("\n\e[1;33m[4] \e[0m- arg(1, \"\", 0)\n");
	printf("\e[1;34mft_write---return ft_write \e[0m\n");
	printf("---%zu\n", ft_write(1, "", 0));
	printf("\e[1;34mwrite---return write \e[0m\n");
	printf("---%zu\n", write(1, "", 0));
	printf("\n\e[1;33m[5] \e[0m- arg(%d, \"%s\", %zu)\n", fd, buf, count);
	printf("\e[1;34mft_write---return ft_write \e[0m\n");
	printf("---%zu\n", ft_write(fd, buf, count));
	printf("\e[1;34mwrite---return write \e[0m\n");
	printf("---%zu\n", write(fd, buf, count));
	printf("\n\n");
}

void	test_read()
{
	char buf[20];
	int fd = open("./Makefile", O_RDONLY);
	int rez;
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("***********ft_read**********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- arg(fd(Makefile), buf, 10)\n");
	printf("\e[1;34mft_read---return ft_read \e[0m\n");
	rez = ft_read(fd, buf, 10);
	buf[10] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\e[1;34mread---return read \e[0m\n");
	rez = read(fd, buf, 10);
	buf[10] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\n\e[1;33m[2] \e[0m- arg(fd(Makefile), buf, 0)\n");
	printf("\e[1;34mft_read---return ft_read \e[0m\n");
	rez = ft_read(fd, buf, 0);
	buf[0] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\e[1;34mread---return read \e[0m\n");
	rez = read(fd, buf, 0);
	buf[0] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\n\e[1;33m[3] \e[0m- arg(fd(Makefile), buf, 1)\n");
	printf("\e[1;34mft_read---return ft_read \e[0m\n");
	rez = ft_read(fd, buf, 1);
	buf[1] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\e[1;34mread---return read \e[0m\n");
	rez = read(fd, buf, 1);
	buf[1] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	buf[0] = 0;
	printf("\n\e[1;33m[4] \e[0m- arg(-1, buf, 1)\n");
	printf("\e[1;34mft_read---return ft_read \e[0m\n");
	rez = ft_read(-1, buf, 1);
	printf("%s---%d\n", buf, rez);
	printf("\e[1;34mread---return read \e[0m\n");
	rez = read(-1, buf, 1);
	printf("%s---%d\n", buf, rez);
	fd = open("./Makefile", O_RDONLY);
		printf("\n\e[1;33m[5] \e[0m- arg(fd(Makefile), NULL, 10)\n");
	printf("\e[1;34mft_read---return ft_read \e[0m\n");
	rez = ft_read(fd, NULL, 10);
	buf[10] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	fd = open("./Makefile", O_RDONLY);
	printf("\e[1;34mread---return read \e[0m\n");
	rez = read(fd, NULL, 10);
	buf[10] = 0;	
	printf("%s---%d\n", buf, rez);
	close(fd);
	printf("\n\n");
}

void	test_strdup(char *a, char *b, char *c, char *d, char *e)
{
	char *buf;
	printf("\e[1;32m****************************\n");
	printf("****************************\n");
	printf("**********ft_strdup*********\n");
	printf("****************************\n");
	printf("****************************\e[0m\n");
	printf("\n\e[1;33m[1] \e[0m- \"%s\"\n", a);
	buf = ft_strdup(a);
	printf("\e[1;34mft_strdup: \e[0m\"%s\"\n", buf);
	free(buf);
	buf = strdup(a);
	printf("\e[1;34mstrdup   : \e[0m\"%s\"\n", buf);
	free(buf);
	printf("\n\e[1;33m[2] \e[0m- \"%s\"\n", b);
	buf = ft_strdup(b);
	printf("\e[1;34mft_strdup: \e[0m\"%s\"\n", buf);
	free(buf);
	buf = strdup(b);
	printf("\e[1;34mstrdup   : \e[0m\"%s\"\n", buf);
	free(buf);
	printf("\n\e[1;33m[3] \e[0m- \"%s\"\n", c);
	buf = ft_strdup(c);
	printf("\e[1;34mft_strdup: \e[0m\"%s\"\n", buf);
	free(buf);
	buf = strdup(c);
	printf("\e[1;34mstrdup   : \e[0m\"%s\"\n", buf);
	free(buf);
	printf("\n\e[1;33m[4] \e[0m- \"%s\"\n", d);
	buf = ft_strdup(d);
	printf("\e[1;34mft_strdup: \e[0m\"%s\"\n", buf);
	free(buf);
	buf = strdup(d);
	printf("\e[1;34mstrdup   : \e[0m\"%s\"\n", buf);
	free(buf);
	printf("\n\e[1;33m[5] \e[0m- \"%s\"\n", e);
	buf = ft_strdup(e);
	printf("\e[1;34mft_strdup: \e[0m\"%s\"\n", buf);
	free(buf);
	buf = strdup(e);
	printf("\e[1;34mstrdup   : \e[0m\"%s\"\n", buf);
	free(buf);
}

int	main(void)
{
	test_strlen("", "12345", "Hello!123\0qw", "      ----      ", "123\"123");
	test_strcpy("", "12345", "Hello!123\0qw", "      ----      ", "123\"123");
	test_strcmp("12345", "12345", "Hello", "Hello!", "qwert", "qwwert");
	test_write(1, "QWERTYasdfg", 7);
	test_read();
	test_strdup("", "12345", "Hello!123\0qw", "      ----      ", "123\"123");
}
