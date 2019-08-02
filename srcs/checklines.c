/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/02 05:35:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_coords_in_room(char *line)
{
	int		space;
	int		i;

	space = 0;
	i = 0;
	if (!(line = ft_strchr(line, ' ') + 1))
		return (1);
	while (line && line[i])
	{
		while (line[i] && line[i] != ' ')
		{
			if (!ft_isdigit(line[i]))
				return (1);
			i++;
		}
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space != 1)
		return (1);
	return (0);
}

int		check_if_tubes(char *line, int *status)
{
	int		i;
	int		hyphen;

	i = 0;
	hyphen = 0;
	*status = 2;
	if (ft_strchr(line, ' '))
		return (1);
	if (!ft_strchr(line, '-'))
		return (1);
	while (line && line[i])
	{
		if (line[i] == '-')
			hyphen++;
		i++;
	}
	if (hyphen > 1)
		return (1);
	return (0);
}

int		check_with_status(char *line, int *status, int i)
{
	if (*status == 0)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
				return (error_of_status(status));
			i++;
		}
		*status = 1;
		return (1);
	}
	else if (*status == 1)
	{
		if (!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
			return (error_of_status(status));
		if (ft_strchr(line, '-'))
			return (check_if_tubes(line, status));
		if (check_coords_in_room(line))
			return (error_of_status(status));
	}
	if (*status == 2)
		if (check_if_tubes(line, status))
			return (error_of_status(status));
	return (0);
}

int		check_if_rooms(char *line, int *var, int *status)
{
	int		i;

	i = 0;
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			*var = (*var == 0) ? 1 : 3;
		else if (!ft_strcmp(line, "##end"))
			*var = (*var == 0) ? 2 : 4;
		return (1);
	}
	if (check_with_status(line, status, i))
		return (1);
	return (0);
}

int		checklines(t_room **rooms, char ***tab)
{
	char	*line;
	int		i;
	int		var;
	int		status;

	line = NULL;
	i = 0;
	var = 0;
	status = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!(*tab = ft_realloctab(tab)))
			return (1);
		if (!((*tab)[i] = ft_strdup(line)))
			return (1);
		if (!check_if_rooms(line, &var, &status))
			if (fill_rooms_list(rooms, line, &var))
				return (1);
		if (status == -1)
			return (1);
		i++;
		ft_strdel(&line);
	}
	return (0);
}
