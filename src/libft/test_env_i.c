#include "libft.h"

int		main(int argc, char **argv, char **envp)
{
	ft_putstr("argv:\n");
	if (argc)
		ft_print_tab(argv);
	ft_putstr("ENVP:\n");
	ft_print_tab(envp);
	return (0);
}
