/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pslib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:36:10 by htrindad          #+#    #+#             */
/*   Updated: 2024/11/04 16:36:55 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSLIB_H
# define PSLIB_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				val;
	int				index;
	int				push_cost;
	int				chunk;
	bool			am;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

size_t	ps_strlen(char const *s);
long	ps_atol(char *nbr);
t_stack	*ps_stackcreate(int val);
t_stack	*ps_stacklast(t_stack *stack);
t_stack	*ps_gethighest(t_stack *node);
t_stack	*ps_getlowest(t_stack *node);
void	ps_stackaddback(t_stack **stack, t_stack *new);
void	ps_quiterror(void);
void	ps_freestack(t_stack **node);
void	ps_setindex(t_stack *stack);
void	ps_freematrix(char **av);
char	**ps_split(char const *s, char c);
char	*ps_substr(char const *s, unsigned int start, size_t len);
char	*ps_strdup(char const *s);
char	*ps_substr(char const *s, unsigned int start, size_t len);
char	*ps_strjoin(char *s1, char const *s2);
bool	ps_sorted(t_stack *node);
int		ps_strncmp(const char *s1, const char *s2, size_t n);
int		ps_countnode(t_stack *stack);
int		ps_highestval(t_stack *node);
void	ps_stackaddfront(t_stack **stack, t_stack *new);
t_stack	*ps_getcheapest(t_stack *node);
bool	ps_duplicate(t_stack *node);
void	ps_setprice(t_stack *a, t_stack *b);
void	ps_setcheapest(t_stack *node);
int		ps_atoi(char *nptr);
int		ps_isdigit(int c);
void	*ps_memset(void *str, int c, size_t t);
void	ps_bzero(void *s, size_t n);
void	*ps_calloc(size_t nmemb, size_t size);

#endif
