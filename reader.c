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

void	num_ants(t_data *data, char *line)
{
	int		count;
	int		num;

	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] < '0' || line[count] > '9')
			err_massage("Error. Incorrect number of ants", 3);
		count++;
	}
	num = ft_atoi(line);
	if (num > 0)
		data->ants = num;
	else
		err_massage("Error. Incorrect number of ants", 3);
}

void	define_line(t_data *data, char *line)
{
	if (ft_strlen(line) >= 2)
	{
		if (line[0] == '#' && line[1] == '#')
			parse_command(data, line);
		if (line[0] == '#' && line[1] != '#')
			parse_comments(data, line);
		if (line[0] != '#' && !strchr(line, '-'))
			parse_room(data, line);
		else
			parse_link(data, line);
	}
	else
		err_massage(ft_strcat(
				"Error. Not a valid line at ", ft_itoa(data->num_line)), 4);
}

void	read_map(t_data *data)
{
	char	*line;

	get_next_line(data->fd, &line);
	data->num_line = 1;
	num_ants(data, line);
	data->num_line++;
	ft_strdel(&line);
	while (get_next_line(data->fd, &line))
	{
		define_line(data, line);
		data->num_line++;
	}
}
