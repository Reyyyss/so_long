/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:16:25 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/02/11 16:34:36 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	return (free(str), NULL);
}

int	count_words(const char *phrase, char c, char **newstr)
{
	size_t	i;
	size_t	count;

	count = 0;
	while (*phrase)
	{
		while (*phrase && *phrase == c)
			phrase++;
		if (*phrase)
		{
			i = 0;
			while (phrase[i] && phrase[i] != c)
				i++;
			if (i && newstr)
			{
				newstr[count] = ft_substr(phrase, 0, i);
				if (!newstr[count])
					return (ft_free(newstr), 0);
			}
			count++;
			phrase += i;
		}
	}
	return (count);
}


char	**ft_split(char const *s, char c)
{
	char		**newstr;

	newstr = ft_calloc(count_words(s, c, NULL) + 1, sizeof(char *));
	count_words(s, c, newstr);
	return (newstr);
}

/* int main()
{
	int i = 0;
	
	char **str = ft_split("eu gosto mm de mulheres sexys que gostam de ler os maias", ' ');
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	ft_free(str);
} */
