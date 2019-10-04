/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roads_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:26:28 by ykliek            #+#    #+#             */
/*   Updated: 2019/09/28 11:26:31 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_path(t_data data, t_room *room)
{
	room->id = room->visit_status;
	room->visit_status = FINISHED;
	if (room == data.anthill->end->room)
		return (1);
	if (room->previous)
	{
		room->distance = get_path(data, room->previous) + 1;
	}
	return (room->distance);
}

void		make_pipes(t_anthill **front, t_anthill **tmp,
		t_room *room, int status)
{
	t_anthill *pipes;

	if (room->links)
		pipes = room->links->head;
	else
		pipes = NULL;
	while (pipes)
	{
		if (pipes->room->visit_status != status
			&& pipes->room->visit_status != FINISHED)
		{
			pipes->room->previous = room;
			pipes->room->visit_status = status;
			enqueue(tmp, front, pipes->room);
		}
		pipes = pipes->next;
	}
}

t_room		*roads_handler(t_data data, t_room *end, int status)
{
	t_anthill	*front;
	t_anthill	*tmp;
	t_anthill	*test;
	t_room		*room;

	front = NULL;
	tmp = NULL;
	enqueue(&tmp, &front, end);
	test = front;
	while (front != NULL)
	{
		room = dequeued(&front);
		room->visit_status = status;
		if (room == data.anthill->start->room)
		{
			get_path(data, room->previous);
			delete_list(&test);
			return (room->previous);
		}
		make_pipes(&front, &tmp, room, status);
	}
	delete_list(&test);
	return (NULL);
}

t_dblist	*run_algorithm(t_data data)
{
	int			status;
	t_room		*road;
	t_dblist	*roads;

	status = 1;
	roads = NULL;
	while ((road = roads_handler(data, data.anthill->end->room, status)))
	{
		if (roads == NULL)
		{
			roads = create_dblist();
			push_back(roads, road);
		}
		else
			push_back(roads, road);
		if (road == data.anthill->end->room)
			break ;
		status++;
	}
	return (roads);
}
