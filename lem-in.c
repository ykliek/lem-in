/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:46:28 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 13:47:24 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	printDBList(t_dblist *list)
{
	t_anthill *tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_printf("%d == %d == %d == %s\n", tmp->room.x, tmp->room.y,
				tmp->room.status, tmp->room.name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	printList(t_links *links)
{
	t_links_node *tmp;

	tmp = links->head;
	while (tmp)
	{
		ft_printf("%s ---- %s\n", tmp->link.room_1, tmp->link.room_2);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		data.fd = fd;
		data.status = 3;
		data.anthill = create_dblist();
		data.links = create_list();
		read_map(&data);
	}
	else
		argc > 2 ? err_massage("To many arguments", 1) : err_massage(
			"Not enough arguments", 2);

	printDBList(data.anthill);
	printList(data.links);

	return (0);
}
