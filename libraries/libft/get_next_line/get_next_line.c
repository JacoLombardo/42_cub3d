/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:19:56 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 16:37:45 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_add_buffer(t_list_gnl **buff, t_list_gnl **lst, int fd)
{
	t_list_gnl	*temp;
	t_list_gnl	*prev;
	t_list_gnl	*current;

	current = *buff;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd && current->content[0])
		{
			ft_lst_add(lst, current->content, fd);
			if (prev)
				prev->next = current->next;
			else
				*buff = current->next;
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

char	*ft_create_line(t_list_gnl *lst, t_list_gnl **buff, int fd)
{
	char	*line;
	char	*buffer;

	line = (char *)malloc((ft_line_length(lst) + 1) * sizeof(char));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line || !buffer)
		return (NULL);
	ft_copy_line(lst, line, buffer);
	if (buffer[0] != '\0')
		ft_lst_add(buff, buffer, fd);
	else
		free(buffer);
	return (line);
}

void	ft_copy_line(t_list_gnl *list, char *line, char *buffer)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				line[j++] = list->content[i++];
				line[j] = '\0';
				j = 0;
				while (list->content[i])
					buffer[j++] = list->content[i++];
				buffer[j] = '\0';
				return ;
			}
			line[j++] = list->content[i++];
		}
		list = list->next;
	}
	line[j] = '\0';
	buffer[0] = '\0';
}

int	ft_read(t_list_gnl **lst, int fd)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (bytes_read)
	{
		if ((*lst) && ft_strchr_gnl((*lst)->content, '\n'))
			break ;
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (-1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			if (!ft_lst_add(lst, buffer, fd))
				return (-1);
			if (ft_strchr_gnl(buffer, '\n'))
				break ;
		}
		else
			free(buffer);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*buff;
	char				*next_line;
	t_list_gnl			*lst;

	lst = NULL;
	next_line = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_lstfree(lst, &buff, fd));
	ft_add_buffer(&buff, &lst, fd);
	if (ft_read(&lst, fd) == -1)
		return (ft_lstfree(lst, &buff, fd));
	if (lst)
	{
		next_line = ft_create_line(lst, &buff, fd);
		if (!next_line)
			return (ft_lstfree(lst, &buff, fd));
		ft_lstfree(lst, NULL, fd);
	}
	return (next_line);
}
