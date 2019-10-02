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
# include <limits.h>

#define Finished INT_MAX

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
	GREY_PATH,
	GREEN_PATH,
	LOCK_ROOM
};

/*
 * Room visit status:
 * 		0 - Unchecked
 * 		1 - Checked
 * 		2 - Finished
 */

typedef struct			s_dblist	t_dblist;

typedef struct			s_room		t_room;

typedef struct			s_anthill	t_anthill;

typedef struct			s_link
{
	char				*room_1;
	char				*room_2;
}						t_link;

typedef struct			s_room
{
	int					x;
	int					y;
	int					id;
	char				*name;
	int					status;
	int					distance;
	t_room				*previous;
	char				*inside;
	t_dblist			*links;
	int					visit_status;
}						t_room;

/*
 * Node
 	*/

typedef struct			s_anthill
{
	t_room				*room;
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
	t_anthill			*start;
	t_anthill			*end;
}						t_dblist;


typedef struct			s_data
{
	int					fd;
	int					find;
	int					ants;
	int					count;
	int					nodes;
	int					status;
	int					num_line;
	t_dblist			*anthill;
	t_dblist			*roads;
}						t_data;

/*
 * dblst_tools.c
 */

t_dblist				*create_dblist();

void					delete_dblist(t_dblist **list);

void					push_front(t_dblist *list, t_room *room);

void					push_back(t_dblist *list, t_room *room);

t_anthill				*create_list(t_room *room);

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

void					find_start(t_data data);

#endif
