/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 11:26:28 by ykliek            #+#    #+#             */
/*   Updated: 2019/09/28 11:26:31 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
 * TODO: algorithm logic
 *		First. Find the shortest way from start to finish and make it green.
 *		Second. Find all another ways that go to finish or connects with way
 *		first stage:
 *		If connect find rooms that don't belong to first way and try to make
 *		another way.
 *		else make eay green.
 *		Third. Find all ways that don't intersect each other.
 */

/*
 * First. Go to the end point
 * Second. Go to the intersect with first way.
 * Third. Find in intersect rooms, rooms that don't belong to first way.
 * Fourth.
 */

void	get_path(t_data *data)
{
	t_anthill	*tmp;

	tmp = data->anthill->tail;
	while (data->anthill->tail && data->anthill->tail != data->anthill->head)
	{
		data->anthill->tail->room->previous->room->color = GREEN_PATH;
		data->anthill->tail = data->anthill->tail->room->previous;
	}
	data->anthill->tail = tmp;
}

void	clean_marks(t_data *data)
{
	t_anthill	*tmp;

	tmp = data->anthill->tail;
	while(data->anthill->tail)
	{
		data->anthill->tail->room->visit_status = Unchecked;
		data->anthill->tail = data->anthill->tail->prev;
	}
	data->anthill->tail = tmp;
}

void	DFS(t_data *data, t_anthill *start, t_anthill *previous)
{
	if (start->room->visit_status == Checked)
		return ;
	if (start->room->color == GREEN_PATH)
	{
		start->room->color = LOCK_ROOM;
		return ;
	}
	start->room->visit_status = Checked;
	start->room->previous = previous;
	if (start->room->status == END)
	{
		data->find = 1;
		get_path(data);
		return ;
	}
	while (start->room->links->head)
	{
		if (data->find == 1)
		{
			data->find = 0;
			clean_marks(data);
		}
			DFS(data, start->room->links->head, start);
		start->room->links->head
		= start->room->links->head->next;
	}
}

void		find_start(t_data *data)
{
	t_anthill *tmp;

	tmp = data->anthill->head;
	while (data->anthill->head)
	{
		if (data->anthill->head->room->status == START)
		{
			while (1)
			{
				DFS(data, data->anthill->head, data->anthill->head);
				if (data->find == 0)
					break ;
			}
			break ;
		}
			data->anthill->head = data->anthill->head->next;
	}
	data->anthill->head = tmp;
}