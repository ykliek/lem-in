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
 * 	0 - start
 * 	1 - end
 * 	2 - skip
 */

void	parse_command(t_data *data, char *line)
{
	if (ft_strcmp(ft_strdup(line + 2), "start") == 0)
		data->status = START;
	else if (ft_strcmp(ft_strdup(line + 2), "end") == 0)
		data->status = END;
	else
		data->status = SKIP;
}

void	parse_comments(t_data *data, char *line)
{

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

void	parse_room(t_data *data, char *line)
{
	t_room	room;
	char	**split_room;

	split_room = ft_strsplit(line, ' ');
	if (split_room[ROOM][0] == 'L')
		err_massage(ft_strcat("Error. Not a valid room name at ",
				ft_itoa(data->num_line)), 5);
	room.name = ft_strdup(split_room[0]);
	room.status = data->status;
	room.visit_status = Unchecked;
	room.links = NULL;
	parse_room_coord(data, &room, split_room);
	push_back(data->anthill, room);
}

void	search_room(t_data *data, t_anthill *anthill, char *room)
{
	t_anthill	*search;
	int			count;

	count = 0;
	search = anthill;
	if (data->anthill->head->room.links == NULL)
		data->anthill->head->room.links = create_dblist();
	while (search)
	{
		if (ft_strcmp(search->room.name, room) == 0)
		{
			push_back(data->anthill->head->room.links, search->room);
			count++;
			break ;
		}
		search = search->next;
	}
	(count == 0) ? err_massage(ft_strcat("Error. Room not exist at ",
										 ft_itoa(data->num_line)), 5) : 0;
}

void	find_rooms_links(t_data *data, t_link link)
{
	t_anthill	*tmp;

	tmp = data->anthill->head;
 	while(data->anthill->head)
	{
		if (ft_strcmp(data->anthill->head->room.name, link.room_1) == 0)
			search_room(data, tmp, link.room_2);
		if (ft_strcmp(data->anthill->head->room.name, link.room_2) == 0)
			search_room(data, tmp, link.room_1);
		data->anthill->head = data->anthill->head->next;
	}
	data->anthill->head = tmp;
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
	}
}

/*
 * TODO:
 *		make reload all values in links of rooms like:
 *			if anthill->head->room.name == anthill->head->room->link->room.name
 *				anthill->head->room->link->room = anthill->head->room
 */
