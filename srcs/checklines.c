/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/01 06:17:16 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_coords_in_room(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	i++;
	if (!line[i])
		return (-1);
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		i++;
	}
	return (0);
}

int		check_if_rooms(char *line, int *var)
{
	if (line[0] == '#' || ft_strchr(line, '-'))
	{
		if (!ft_strcmp(line, "##start"))
			*var = (*var == 0) ? 1 : 3;
		else if (!ft_strcmp(line, "##end"))
			*var = (*var == 0) ? 2 : 4;
		return (1);
	}
	if (!ft_strchr(line, ' '))
		return (-1);
	if ((line = ft_strchr(line, ' ') + 1))
	{
		if (check_coords_in_room(line) == -1)
			return (-1);
	}
	return (0);
}

int		checklines(t_room **rooms)
{
	char	*line;
	char	**tab;
	int		i;
	int		var;
	
	line = NULL;
	tab = NULL;
	i = 0;
	var = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!(tab = ft_realloctab(&tab)))
			return (1);
		tab[i] = ft_strdup(line);
		if (!check_if_rooms(line, &var))
			if (fill_rooms_list(rooms, line, &var))
				return (1);
		i++;
		ft_strdel(&line);
	}
	while (*rooms)
	{
		ft_printf("NAME = %s\n", (*rooms)->name);
		ft_printf("START = %d\n", (*rooms)->start);
		ft_printf("END = %d\n", (*rooms)->end);
		(*rooms) = (*rooms)->next;
	}
	return (0);
}
