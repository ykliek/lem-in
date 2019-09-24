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

int		num_ants(t_data *data, char *line)
{
	int		count;
	int		num;

	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] < '0' || line[count] > '9')
			return (err_massage("Error. Incorrect number of ants", 3));
		count++;
	}
	num = ft_atoi(line);
	if (num >= 0)
		data->ants = num;
	else
		return (err_massage("Error. Incorrect number of ants", 3));
	return (0);
}

int		define_line(t_data *data, char *line)
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
		return (err_massage(ft_strcat(
				"Error. Not a valid line at ", ft_itoa(data->num_line)), 4));
	return (0);
}

int		read_map(t_data *data)
{
	char	*line;
	int		err;

	get_next_line(data->fd, &line);
	data->num_line = 1;
	err = num_ants(data, line);
	if (err != 0)
		return (err);
	data->num_line++;
	ft_strdel(&line);
	while (get_next_line(data->fd, &line))
	{
		err = define_line(data, line);
		if (err != 0)
			return (err);
		data->num_line++;
		free(line);
	}
	return (0);
}
