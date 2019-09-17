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

int		main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	int		err;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		data.fd = fd;
		data.anthill = create_dblist();
		err = read_map(&data);
		if (err != 0)
			return (err);
	}
	else
		return (argc > 2 ? err_massage("To many arguments", 1) : err_massage(
			"Not enough arguments", 2));
	return (0);
}
