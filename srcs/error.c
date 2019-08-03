/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 05:13:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/03 04:36:57 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		error_while_gnl(char **line)
{
	ft_strdel(&(*line));
	return (1);
}

int		error_of_status(int *status)
{
	*status = -1;
	return (1);
}
