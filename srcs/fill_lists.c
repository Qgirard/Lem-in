/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/01 05:09:13 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		fill_rooms_list(t_room **rooms, char *line, int *var)
{
	t_room	*tmp;
	t_room	*new;

	tmp = (*rooms);
	while ((*rooms) && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (1);
	new->start = (*var == 1 || *var == 4) ? 1 : 0;
	new->end = (*var == 2 || *var == 3) ? 1 : 0;
	if (*var >= 3)
		*var = (*var == 3) ? 1 : 2;
	else
		*var = 0;
	new->name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	new->next = NULL;
	if (!(*rooms))
		(*rooms) = new;
	else
		tmp->next = new;
	return (0);
}
