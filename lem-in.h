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

/*
 * Error codes:
 * 		0 - Success
 * 		1 - To many arguments
 * 		2 - Not enough arguments
 * 		3 - Incorrect number of ants
 * 		4 - Not a valid line
 * 		5 - Not a valid room name
 */

enum
{
	ROOM,
	X,
	Y
};

enum
{
	START,
	END,
	SKIP
};

typedef struct			s_room
{
	int					x;
	int					y;
	int					status;
	char				*name;
	char				*inside;
}						t_room;

typedef struct			s_anthill
{
	t_room				room;
	struct s_anthill	*next;
	struct s_anthill	*prev;
}						t_anthill; // Node

typedef struct			s_dblist
{
	int 				size;
	t_anthill			*head;
	t_anthill			*tail;
}						t_dblist; // DBLinkedList


typedef struct			s_data
{
	int					fd;
	int					ants;
	int					status;
	int					num_line;
	t_dblist			*anthill;
}						t_data;

/*
 * lst_tools.c
 */

t_dblist				*create_dblist();

t_anthill				*get_room(t_dblist *list, int i);

void					delete_dblist(t_dblist **list);

void					push_front(t_dblist *list, t_room room);

void					push_back(t_dblist *list, t_room room);

/*
 * reader.c
 */

void					read_map(t_data *data);

void					define_line(t_data *data, char *line);

void					num_ants(t_data *data, char *line);

/*
 * error_management.c
 */

void					err_massage(char *massage, int err);

/*
 * parser.c
 */

void					parse_command(t_data *data, char *line);

void					parse_comments(t_data *data, char *line);

void					parse_room(t_data *data, char *line);

void					parse_link(t_data *data, char *line);

#endif
