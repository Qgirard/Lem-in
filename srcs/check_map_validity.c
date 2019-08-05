/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 00:17:22 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/06 00:43:34 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_links_in_map(t_room **rooms, int start, char *name, char *prev)
{
	t_room	*tmp;
	t_links	*buf;

	tmp = (*rooms);
	if (start == 1)
	{
		while (tmp && tmp->start != 1)
			tmp = tmp->next;
		if (tmp->links)
			buf = tmp->links;
		else
			return (0);
		while (buf)
		{
			if (check_links_in_map(rooms, 0, buf->room, tmp->name))
				return (1);
			buf = buf->next;
		}
	}
	else
	{
		while (tmp && ft_strcmp(tmp->name, name))
			tmp = tmp->next;
		if (tmp->end == 1)
			return (1);
		buf = tmp->links;
		while (buf)
		{
			if (buf && !ft_strcmp(buf->room, prev))
				buf = buf->next;
			if (check_links_in_map(rooms, 0, buf->room, tmp->name))
				return (1);
			buf = buf->next;
		}
	}
	return (0);
}

int		check_map_validity(t_room **rooms)
{
	t_room	*tmp;
	int		start;
	int		end;

	tmp = (*rooms);
	start = 0;
	end = 0;
	while (tmp)
	{
		if (tmp->start == 1)
			start++;
		if (tmp->end == 1)
			end++;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
		return (0);
	return (check_links_in_map(rooms, 1, NULL, NULL));
}
