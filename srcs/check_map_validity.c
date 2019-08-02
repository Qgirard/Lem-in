/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 00:17:22 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/02 05:14:59 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

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
		return (1);
	return (0);
}
