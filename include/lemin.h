/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:52:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/01 03:58:58 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct		s_links
{
	int				room;
	struct s_links	*next;
}					t_links;

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	t_links			*links;
	struct s_room	*next;
}					t_room;

int					checklines(t_room **rooms);
int					fill_rooms_list(t_room **rooms, char *line, int *var);

#endif