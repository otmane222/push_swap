/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:22:56 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 19:46:53 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_listt {
	char			*text;
	struct s_listt	*next;
}	t_listt;

char	*get_next_line(int fd);
size_t	ft_strlenn(const char *s);
int		ft_strchrr(t_listt *head);
void	ft_malloc(t_listt *head, char **line);
t_listt	*ft_lstlast(t_listt *lst);
void	free_node(t_listt **lst, void (*del)(void*));

#endif