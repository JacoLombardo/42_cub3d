/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:16:12 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/02 16:37:43 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	while (i < (len + 1))
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (NULL);
}

void	ft_free_buff(t_list_gnl **buff, int fd)
{
	t_list_gnl	*temp;
	t_list_gnl	*prev;
	t_list_gnl	*current;

	current = *buff;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*buff = current->next;
			temp = current;
			free(temp->content);
			free(temp);
			break ;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

char	*ft_lstfree(t_list_gnl *lst, t_list_gnl **buff, int fd)
{
	t_list_gnl	*temp;

	temp = lst;
	if (lst)
	{
		while (lst)
		{
			temp = lst->next;
			free(lst->content);
			free(lst);
			lst = temp;
		}
	}
	lst = NULL;
	if (buff)
		ft_free_buff(buff, fd);
	return (NULL);
}

int	ft_line_length(t_list_gnl *lst)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (lst)
	{
		i = 0;
		if (lst->content == NULL)
			return (len);
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (++len);
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

t_list_gnl	*ft_lst_add(t_list_gnl **lst, char *str, int fd)
{
	t_list_gnl	*temp;
	t_list_gnl	*new;

	new = malloc(sizeof(t_list_gnl));
	if (!new)
		return (NULL);
	new->content = str;
	new->fd = fd;
	new->next = NULL;
	temp = *lst;
	if (*lst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
	return (new);
}
