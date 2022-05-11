#include "printf.h"

int	main(void)
{
	char	*s = "Hello World!";
	int		i = 1999;

	printf("\e[1;32m*************************************************************\n");
	printf("********                                               ******\n");
	printf("********              START TEST PRINTF                ******\n");
	printf("********                                               ******\n");
	printf("*************************************************************\e[0m\n");
	printf("\e[1;33m[1]\e[0m \e[1;34mOriginal:\e[0m\ns-%s\nd-%d\nx-%x\nX-%X\np-%p\n", s, i, i, i, s);
	ft_printf("\e[1;33m[1] \e[0m\e[1;34mMy printf:\e[0m\ns-%s\nd-%d\nx-%x\nX-%X\np-%p\n", s, i, i, i, s);
	ft_printf("\n");
	printf("\e[1;33m[2]\e[0m \e[1;34mOriginal:\e[0m\ns-%.5s\nd-%10d\n", s, i);
	ft_printf("\e[1;33m[2] \e[0m\e[1;34mMy printf:\e[0m\ns-%.5s\nd-%10d\n", s, i);
	printf("\n");
	printf("\e[1;33m[3]\e[0m \e[1;34mOriginal:\e[0m\nss234r fds-%.d__\n5%%qwe  %1.10d\n", i, i);
	ft_printf("\e[1;33m[3]\e[0m \e[1;34mMy printf:\e[0m\nss234r fds-%.d__\n5%%qwe  %1.10d\n", i, i);
	printf("\n");
	printf("\e[1;33m[4]\e[0m \e[1;34mOriginal:\e[0m\n   %-6.5d  %1.1s \n", i, s);
	ft_printf("\e[1;33m[4]\e[0m \e[1;34mMy printf:\e[0m\n   %-6.5d  %1.1s \n", i, s);
	printf("\e[1;32m*************************************************************\n");
	printf("*************************************************************\e[0m\n");
}
