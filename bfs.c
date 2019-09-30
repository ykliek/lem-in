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

void DFS(t_anthill *start, t_anthill *previous)
{
	if (start->room->visit_status == Checked)
		return ;
	start->room->visit_status = Checked;
	start->room->previous = previous;
	if (start->room->status == END) {
		return;
	}
	while (start->room->links->head)
	{
		DFS(start->room->links->head, start);
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

			break ;
		}
			data->anthill->head = data->anthill->head->next;
	}
	data->anthill->head = tmp;
}