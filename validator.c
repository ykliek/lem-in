/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:13:37 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 20:13:38 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
 * TODO:
 * 		1. Rooms looks like `name x y`
 * 		2. Links looks like name1-name2
 * 		3. Comments starts with '#' only
 * 		3. Rooms name don't start with 'L' and '#'
 * 		4. Rooms x and y must be int
 * 		5. Commands starts with "##"
 * 		6. Non-compliant or empty lines stop reading and display ERROR
 * 		7. If there is not enough data - display ERROR
 * 		8. Always must be ##start and ##end
 * 		9. Any unknown will be ignored
 */

void	room_exist(t_data *data, char *room)
{
	t_anthill	*find_base;
	int			count;

	count = 0;
	find_base = data->anthill->head;
	while (find_base)
	{
		if (ft_strcmp(find_base->room.name, room) == 0)
		{
			count = 1;
			break;
		}
		find_base = find_base->next;
	}
	(count == 0) ? err_massage(ft_strcat("Error. Linked room is not exist at ",
										 ft_itoa(data->num_line)), 5) : 0;
}
