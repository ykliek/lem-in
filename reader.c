/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:13:30 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 20:13:32 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		num_ants(char *line)
{
	int		num;

	while (line)
	{
		if (*line > '0' && *line < '9')
			return (err_massage("Error. Incorrect number of ants"));
		line++;
	}
	num = ft_atoi(line);
	return (num >= 0 ? num : err_massage("Error. Incorrect number of ants"));
}

void	read_line(t_data *data)
{

}

void	read_map(t_data *data)
{
	int		count;
	char	*line;

	while (get_next_line(data->fd, &line))
		data->ants = num_ants(line);
	ft_strdel(&line);
	while (get_next_line(data->fd, &line))
	{
		read_line(data);
	}
}
