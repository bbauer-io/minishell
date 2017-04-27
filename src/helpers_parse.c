
/*
** Copies a section of a string to a new entry in a char ** table
** (the table will be created if it is the pointer to it is NULL.
*/

void			copy_to_list(char ***commands, char **line, int i, int l_begin)
{
	char	**tmp_com;
	char	*tmp;

	tmp_com = *commands;
	tmp = ft_strnew(i - l_begin);
	ft_strncpy(tmp, &(*line)[l_begin], i - l_begin);
	*commands = ft_tab_add_one(*commands, tmp);
	if (tmp_com)
		free(tmp_com);
	return ;
}

/*
** Takes a pointer to a string, ft_strtrims the string to remove \t \n ' '
** Frees the original string and returns the copy.
*/

void			trim_and_free(char **str)
{
	char	*trimmed;

	trimmed = ft_strtrim(*str);
	ft_strdel(str);
	*str = trimmed;
	return ;
}
