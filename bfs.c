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

void		find_shortest(t_data *data)
{
	t_anthill *rooms;

	rooms = data->anthill->head;
	while (rooms)
	{
		if (rooms->room.status == START)
		{

		}
		rooms = rooms->next;
	}
}

