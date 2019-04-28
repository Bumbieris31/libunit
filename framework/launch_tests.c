
#include "libunit.h"

void	print_status(int status, t_unit_test *testlist)
{
	ft_printf("%s : ", testlist->name);
	if (status == 0)
		ft_printf("[OK]\n");
	else if (status == 11)
		ft_printf("[SIGSEGV]\n");
	else if (status == 10)
		ft_printf("[SIGBUS]\n");
	else
		ft_printf("[KO]\n");
	ft_printf("--THE STATUS IS => %d\n", status);
}

int	launch_tests(t_unit_test **testlist)
{
	int			ret;
	int			status;
	t_unit_test	*head;

	ret = 0;
	head = *testlist;
	while (head != 0)
	{
		if (fork() != 0)
		{
			wait(&status);
			if (status != 0)
				ret = -1;
			print_status(status, head);
		}
		else
		{
			if (head->funct() == 0)
				exit(0);
			else
				exit(1);
		}
		head = head->next;
	}
	return (ret);
}
