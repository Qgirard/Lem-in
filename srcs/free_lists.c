/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/02 05:15:07 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		free_lists(t_room **rooms, char ***tab, int var)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (*rooms)
	{
		tmp = (*rooms);
		(*rooms) = (*rooms)->next;
		ft_strdel(&(tmp->name));
		free(tmp);
	}
	while (*tab && (*tab)[i])
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	free(*tab);
	if (var == 1)
		ft_putendl("ERROR");
	return (var);
}
