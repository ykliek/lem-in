/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:46:28 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/03 16:11:05 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	structure_init(t_data *data)
{
	data->status = 2;
	data->nodes = 0;
	data->count = 0;
	data->anthill = create_dblist();
	data->check = 0;
	data->num_line = 0;
	data->i = 0;
	data->fd = 0;
	data->anthill->end = NULL;
	data->anthill->start = NULL;
}

void	print_input(t_print *start)
{
	while (start)
	{
		ft_printf("%s\n", (char*)start->content);
		start = start->next;
	}
	ft_printf("\n");
}

int		main(int argc, char **argv)
{
	t_data		data;
	t_dblist	*roads;
	t_anthill	*tmp;
	t_print		*to_print;

	data.fd = open(argv[2], O_RDONLY);
	structure_init(&data);
	to_print = read_map(&data);
	if (!data.anthill->head)
		err_massage("Not correct file", 1);
	print_input(to_print);
	if (data.check != 2)
		err_massage("Error. Check start and end position!!!", 8);
	if (!data.anthill->end || !data.anthill->start)
		err_massage("You have problem with start and end", 9);
	roads = run_algorithm(data);
	if (roads)
	{
		tmp = roads->head;
		go_ants(tmp, &data, tmp, define_path(tmp));
	}
	else
		err_massage("There is no way... !!!", 7);
	system("leaks lem-in");
	return (0);
}
