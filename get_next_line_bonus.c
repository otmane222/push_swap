/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboulgh <oaboulgh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:22:14 by oaboulgh          #+#    #+#             */
/*   Updated: 2023/02/22 19:51:03 by oaboulgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libc.h"

static void	node_creat(t_listt **buffer, char *buff, int red)
{
	int		i;
	t_listt	*last;
	t_listt	*new;

	new = malloc(sizeof(t_listt));
	if (!new)
		return ;
	new->next = NULL;
	new->text = malloc((red + 1) * sizeof(char));
	if (!new->text)
		return ;
	i = 0;
	while (buff[i] && i < red)
	{
		new->text[i] = buff[i];
		i++;
	}
	new->text[i] = '\0';
	if (!*buffer)
	{
		*buffer = new;
		return ;
	}
	last = ft_lstlast(*buffer);
	last->next = new;
}

static void	read_file(int fd, t_listt **head)
{
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	while (ft_strchrr(*head) && read_count > 0)
	{
		read_count = read (fd, buffer, BUFFER_SIZE);
		if (read_count < 0 || !buffer)
		{
			free(buffer);
			return ;
		}
		buffer[read_count] = '\0';
		node_creat(head, buffer, read_count);
	}
	free(buffer);
}

static void	get_line(t_listt *head, char **line)
{
	int		i;
	int		j;

	if (!head)
		return ;
	ft_malloc(head, line);
	if (!*line)
		return ;
	i = 0;
	while (head)
	{
		j = 0;
		while (head->text[j])
		{
			if (head->text[j] == '\n')
			{
				(*line)[i++] = head->text[j];
				break ;
			}
			(*line)[i++] = head->text[j++];
		}
		head = head->next;
	}
	(*line)[i] = '\0';
}

static void	rest_node(t_listt **head)
{
	t_listt	*node;
	t_listt	*rest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	rest = malloc(sizeof(t_listt));
	if (!rest || head == NULL)
		return ;
	rest->next = NULL;
	node = ft_lstlast(*head);
	while (node->text[j] && node->text[j] != '\n')
		j++;
	if (node->text[j] && node->text[j] == '\n')
		j++;
	rest->text = malloc (ft_strlenn(node->text) - j + 1);
	if (!rest->text)
		return (free(node));
	while (node->text[j])
		rest->text[i++] = node->text[j++];
	rest->text[i] = '\0';
	free_node(head, free);
	*head = rest;
}

char	*get_next_line(int fd)
{
	static t_listt	*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file(fd, &buffer);
	if (!buffer)
		return (NULL);
	get_line(buffer, &line);
	rest_node(&buffer);
	if (line[0] == '\0')
	{
		free_node(&buffer, free);
		free(line);
		line = NULL;
		return (NULL);
	}
	return (line);
}
