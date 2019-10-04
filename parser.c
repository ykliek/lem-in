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

#include "lem_in.h"

/*
** Command codes:
** 	0 - start
** 	1 - end
** 	2 - skip
*/

void	parse_command(t_data *data, char *line)
{
	char *tmp;

	tmp = ft_strdup(line + 2);
	if (ft_strcmp(tmp, "start") == 0)
	{
		data->status = START;
		data->check++;
		free(tmp);
	}
	else if (ft_strcmp(tmp, "end") == 0)
	{
		data->status = END;
		data->check++;
		free(tmp);
	}
	else
	{
		data->status = data->status;
		free(tmp);
	}
}

void	parse_room_coord(t_data *data, t_room *room, char **split_room)
{
	if (split_room[X])
	{
		if (split_room[X][0] < '0' || split_room[X][0] > '9')
			err_massage(ft_strcat("Error. Not a valid room coord at ",
					ft_itoa(data->num_line)), 5);
	}
	else
		err_massage(ft_strcat("Error. Not a valid room coord at ",
				ft_itoa(data->num_line)), 5);
	room->x = ft_atoi(split_room[X]);
	if (split_room[Y])
	{
		if (split_room[Y][0] < '0' || split_room[Y][0] > '9')
			err_massage(ft_strcat("Error. Not a valid room coord at ",
					ft_itoa(data->num_line)), 5);
	}
	else
		err_massage(ft_strcat("Error. Not a valid room coord at ",
				ft_itoa(data->num_line)), 5);
	room->y = ft_atoi(split_room[Y]);
}

void	put_end_start(t_data *data)
{
	if (data->status == START)
	{
		if (data->anthill->tail->prev)
		{
			if (data->anthill->tail->prev->room->status != START)
				data->anthill->start = data->anthill->tail;
		}
		else
			data->anthill->start = data->anthill->tail;
	}
	if (data->status == END)
	{
		if (data->anthill->tail->prev)
		{
			if (data->anthill->tail->prev->room->status != END)
				data->anthill->end = data->anthill->tail;
		}
		else
			data->anthill->end = data->anthill->tail;
	}
}

void	parse_room(t_data *data, char *line)
{
	t_room	*room;
	char	**split_room;

	room = (t_room *)malloc(sizeof(t_room));
	split_room = ft_strsplit(line, ' ');
	if (split_room[ROOM][0] == 'L')
		err_massage(ft_strcat("Error. Not a valid room name at ",
				ft_itoa(data->num_line)), 5);
	room->name = ft_strdup(split_room[0]);
	room->status = data->status;
	room->visit_status = 0;
	room->links = NULL;
	room->inside = 0;
	room->id = 0;
	room->links = create_dblist();
	room->previous = NULL;
	parse_room_coord(data, room, split_room);
	check_room(data, room);
	push_back(data->anthill, room);
	put_end_start(data);
	free_2d_array(split_room);
}


void	parse_link(t_data *data, char *line)
{
	t_link	link;
	char	**split_link;

	split_link = ft_strsplit(line, '-');
	if (split_link[LINK_1])
	{
		link.room_1 = ft_strdup(split_link[LINK_1]);
		if (split_link[LINK_2])
		{
			link.room_2 = ft_strdup(split_link[LINK_2]);
			find_rooms_links(data, link);
			if (split_link[ERROR])
				err_massage(ft_strcat("Error. No path at ",
						ft_itoa(data->num_line)), 5);
		}
		free(link.room_1);
		free(link.room_2);
	}
	free_2d_array(split_link);
}
