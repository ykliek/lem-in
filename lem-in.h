/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:47:32 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/13 13:47:33 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"

#include <stdio.h> // TODO: delete

/*
 * TODO:
 * 		1. Make all structure clear and comfortable to use;
 * 		2. Organize two dimensional structure with end and start and all necessary information
 */

typedef struct			s_data
{
	int					fd;
	int					ants;
	char				**map;
}						t_data;

typedef struct			s_node
{
	int ugit;
}						t_node;

typedef struct			s_room
{
	char	*name;
	char	*inside;
	int		x;
	int		y;
}						t_room;

typedef struct			s_anthill
{
	t_node				*node;
	struct s_anthill	*next;
	struct s_anthill	*prev;
}						t_anthill;

typedef struct			s_dblist
{
	int 				size;
	t_anthill			*head;
	t_anthill			*tail;
}						t_dblist;

/*
 * lst_tools.c
 */

t_dblist				*create_dblist();

t_anthill				*get_node(t_dblist *list, int i);

void					delete_dblist(t_dblist **list);

void					push_front(t_dblist *list, t_node *node);

void					push_back(t_dblist *list, t_node *node);

/*
 * reader.c
 */

void					read_map(t_data *data);

/*
 * error_management
 */

int						err_massage(char *massage);

#endif
