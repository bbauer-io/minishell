
#include "../include/minishell.h"
/*
** separates args at ; unless the command is enclosed in quotations ";"
** *command is set to null by cleanup when before  funciton is called from
** minishell_loop()
*/

void			separate_multiple_args(char ***args, char **line)
{
	size_t	i;
	int		l_begin;

	trim_and_free(line);
	i = 0;
	while (line && *line && i < ft_strlen(*line))
	{
		l_begin = i;
		while ((*line)[i] && (*line)[i] != ' ')
		{
			if ((*line)[i] == '\"')
			{
				i++;
				while ((*line)[i++] != '\"')
					;//if ((*line)[i] == '\0')
					//	return (unclosed_quote_parse_error(*line, i));
			}
			i++;
		}
		if ((*line)[i] == '\0' || (*line)[i] == ';')
			copy_to_list(args, line, i, l_begin);
		i++;
	}
}
