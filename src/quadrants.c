#include "../inc/struct.h"
#include "../inc/cube3d.h"

int	first_quadrant(t_player *p, char **g, int b_x, int b_y)
{
	if ((b_x == (int)p->x - 1 && b_y == (int)p->y - 1) &&
			(ft_strchr("1D", g[(int)p->y][(int)p->x - 1]) &&
			ft_strchr("1D", g[(int)p->y - 1][(int)p->x])))
			return (1);
	return (0);
}

int second_quadrant(t_player *p, char **g, int b_x, int b_y)
{
	if ((b_x == (int)p->x + 1 && b_y == (int)p->y - 1) &&
		(ft_strchr("1D", g[(int)p->y][(int)p->x + 1]) &&
		ft_strchr("1D", g[(int)p->y - 1][(int)p->x])))
		return (1);
	return (0);
}

int third_quadrant(t_player *p, char **g, int b_x, int b_y)
{
	if ((b_x == (int)p->x + 1 && b_y == (int)p->y + 1) &&	
		(ft_strchr("1D", g[(int)p->y][(int)p->x + 1]) &&
		ft_strchr("1D", g[(int)p->y + 1][(int)p->x])))
		return (1);
	return (0);
}

int fourth_quadrant(t_player *p, char **g, int b_x, int b_y)
{
	if ((b_x == (int)p->x - 1 && b_y == (int)p->y + 1) &&
		(ft_strchr("1D", g[(int)p->y][(int)p->x - 1]) &&
		ft_strchr("1D", g[(int)p->y + 1][(int)p->x])))
		return (1);
	return (0);
}