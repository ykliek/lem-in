/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:13:30 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 20:13:32 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	num_ants(t_data *data, char *line)
{
	int		count;
	int		num;

	count = 0;
	while (line[count] != '\0')
	{
		if (line[count] < '0' || line[count] > '9')
			err_massage("Error. Incorrect number of ants", 3);
		count++;
	}
	num = ft_atoi(line);
	if (num > 0)
		data->ants = num;
	else
		err_massage("Error. Incorrect number of ants", 3);
}

void	define_line(t_data *data, char *line)
{
	if (ft_strlen(line) >= 2)
	{
		if (line[0] == '#' && line[1] == '#')
			parse_command(data, line);
		else if (line[0] == '#' && line[1] != '#')
			return ;
		else if (line[0] != '#' && !strchr(line, '-'))
			parse_room(data, line);
		else
		{
			if (!data->anthill->head)
				err_massage("Error. Put some rooms please", 5);
			parse_link(data, line);
		}
	}
	else
		err_massage(ft_strcat(
				"Error. Not a valid line at ", ft_itoa(data->num_line)), 4);
}

t_print	*read_map(t_data *data)
{
	char	*line;
	t_print	*print;
	t_print	*prev;
	t_print	*list;

	if (get_next_line(data->fd, &line) > 0)
	{
		print = (t_print *) malloc(sizeof(t_print));
		print->next = NULL;
		print->content = line;
		prev = print;
		data->num_line = 1;
		num_ants(data, line);
		data->num_line++;
		while (get_next_line(data->fd, &line) > 0) {
			list = (t_print *) malloc(sizeof(t_print));
			list->next = NULL;
			list->content = line;
			prev->next = list;
			prev = list;
			define_line(data, line);
			data->num_line++;
		}
	}
	return (print);
}
