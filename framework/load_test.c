
#include "libunit.h"

t_unit_test	*make_testlist(char *str, int (*funct)(void))
{
	t_unit_test	*gacho;

	gacho = (t_unit_test*)malloc(sizeof(t_unit_test));
	gacho->ret = 0;
	gacho->name = ft_strdup(str);
	gacho->next = 0;
	gacho->funct = funct;
	return (gacho);
}

void	append(t_unit_test *testlist, char *str, int (*funct)(void))
{
	while (testlist->next != 0)
		testlist = testlist->next;
	testlist->next = make_testlist(str, funct);
}

void	load_test(t_unit_test **testlist, char *str, int (*funct)(void))
{
	if (*testlist)
		append(*testlist, str, funct);
	else
		*testlist = make_testlist(str, funct);
}