/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:07:41 by ykliek            #+#    #+#             */
/*   Updated: 2019/09/17 20:07:42 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
 * Command codes:
 * 	1 - start
 * 	2 - end
 * 	3 - skip
 */

int		parse_command(t_data *data, char *line)
{
	if (ft_strcmp(ft_strdup(line + 2), "start") == 0)
		return (1);
	else if (ft_strcmp(ft_strdup(line + 2), "end") == 0)
		return (2);
	else
		return (3);
}

int		parse_comments(t_data *data, char *line)
{
	return (0);
}

int		parse_room_coord(t_data *data, t_room *room, char **split_room)
{
	if (split_room[X])
	{
		if (split_room[X][0] < '0' || split_room[X][0] > '9')
			return (err_massage(ft_strcat("Error. Not a valid room coord at ",
										  ft_itoa(data->num_line)), 5));
	}
	else
		return (err_massage(ft_strcat("Error. Not a valid room coord at ",
									  ft_itoa(data->num_line)), 5));
	room->x = ft_atoi(split_room[X]);
	if (split_room[Y])
	{
		if (split_room[Y][0] < '0' || split_room[Y][0] > '9')
			return (err_massage(ft_strcat("Error. Not a valid room coord at ",
										  ft_itoa(data->num_line)), 5));
	}
	else
		return (err_massage(ft_strcat("Error. Not a valid room coord at ",
									  ft_itoa(data->num_line)), 5));
	room->y = ft_atoi(split_room[Y]);
	return (0);
}

int		parse_room(t_data *data, char *line)
{
	t_room	room;
	char	**split_room;
	int		err;

	split_room = ft_strsplit(line, ' ');
	if (split_room[ROOM][0] == 'L')
		return (err_massage(ft_strcat("Error. Not a valid room name at ",
									  ft_itoa(data->num_line)), 5));
	room.name = split_room[0];
	err = parse_room_coord(data, &room, split_room);
	if (err != 0)
		return (err);
	push_back(data->anthill, &room);
	return (0);
}

int		parse_link(t_data *data, char *line)
{
	return (0);
}