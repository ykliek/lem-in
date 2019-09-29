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
 * 		6 - Linked room is not exist
 * 		7 - No path
 */

enum
{
	ROOM,
	X,
	Y
};

enum
{
	LINK_1,
	LINK_2,
	ERROR
};

enum
{
	START,
	END,
	SKIP
};

enum
{
	Unchecked,
	Visited,
	Finished
};

/*
 * Room visit status:
 * 		0 - Unchecked
 * 		1 - Visited
 * 		2 - Finished
 */

typedef struct			s_link
{
	char				*room_1;
	char				*room_2;
}						t_link;

typedef struct			s_links_node
{
	t_link				link;
	struct s_links_node	*next;
}						t_links_node;

typedef struct			s_links
{
	int					size;
	t_links_node		*head;
	t_links_node		*tail;
}						t_links;

typedef struct			s_room
{
	int					x;
	int					y;
	int					visit_status;
	int					status;
	char				*name;
	char				*inside;
}						t_room;

/*
 * Node
 */

typedef struct			s_anthill
{
	t_room				room;
	struct s_anthill	*next;
	struct s_anthill	*prev;
}						t_anthill;

/*
 * DBLinkedList
 */

typedef struct			s_dblist
{
	int 				size;
	t_anthill			*head;
	t_anthill			*tail;
}						t_dblist;


typedef struct			s_data
{
	int					fd;
	int					ants;
	int					status;
	int					num_line;
	t_dblist			*anthill;
	t_links				*links;
}						t_data;

/*
 * dblst_tools.c
 */

t_dblist				*create_dblist();

t_anthill				*get_room(t_dblist *list, int i);

void					delete_dblist(t_dblist **list);

void					push_front(t_dblist *list, t_room room);

void					push_back(t_dblist *list, t_room room);

/*
 * lst_tools.c
 */

t_links					*create_list();

void					list_push(t_links *lt, t_link link);

void					list_push_back(t_links *lt, t_link link);

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

/*
 * validator.c
 */

void					room_exist(t_data *data, char *room);

#endif
