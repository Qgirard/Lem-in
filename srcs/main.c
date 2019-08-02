/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/02 02:07:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		main(int argc, char **argv)
{
	t_room	*rooms;
	char	**tab;

	rooms = NULL;
	tab = NULL;
	(void)argc;
	(void)argv;
	if (checklines(&rooms, &tab))
		return (free_lists(&rooms, &tab, 1));
	if (check_map_validity(&rooms))
		return (free_lists(&rooms, &tab, 1));
	ft_putendl("FINISH");
	free_lists(&rooms, &tab, 0);
	return (0);
}
