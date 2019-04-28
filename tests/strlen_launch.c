#include "tests.h"

int	strlen_launch(void)
{
	int			launch_ret;
	t_unit_test	*testlist;

	testlist = 0;
	ft_printf("STRLEN: \n");
	load_test(&testlist, "Basic test", &basic_test);
	launch_ret = launch_tests(&testlist);
	return (launch_ret);
}

int	main(void)
{
	ft_printf("RETURN VALUE (strlen) => %d \n", strlen_launch());
	return (0);
}