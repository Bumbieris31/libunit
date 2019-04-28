

#ifndef __LIBUNIT_H
# define __LIBUNIT_H
# include "../libft.h"
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_unit_test
{
	int					(*funct)(void);
	int					ret;
	char				*name;
	struct s_unit_test	*next;
}		t_unit_test;

void	load_test(t_unit_test **testlist, char *str, int (*funct)(void));
int		launch_tests(t_unit_test **testlist);
int		strlen_launcher(void);

#endif
