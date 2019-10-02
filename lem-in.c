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
		ft_printf("%d == %d == %d == %s\n", tmp->room->x, tmp->room->y,
				tmp->room->status, tmp->room->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	structure_init(t_data *data)
{
	data->status = 2;
	data->nodes = 0;
	data->count = 0;
	data->anthill = create_dblist();
}

int		main(int argc, char **argv)
{
	t_data	data;
	t_dblist *roads;
	t_anthill*tmp;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		data.fd = fd;
		structure_init(&data);
		read_map(&data);
		roads = run_algorithm(data);
		if (roads)
			tmp = roads->head;
		else
			err_massage("There is no way... !!!", 7);
		go_ants(tmp, &data);
	}
	else
		argc > 2 ? err_massage("To many arguments", 1) : err_massage(
			"Not enough arguments", 2);
	return (0);
}
