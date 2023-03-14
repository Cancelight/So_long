#include "oslo.h"

int direct_moves(int keycode, t_vars *vars)
{
	if (keycode == W || keycode == UP)
		up_move(vars);
	else if (keycode == S || keycode == DOWN)
		down_move(vars);
	else if (keycode == D || keycode == RIGHT)
		right_move(vars);
	else if (keycode == A || keycode == LEFT)
		left_move(vars);
	else if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int	up_move(t_vars *vars)
{
	/*check fonksiyonuna göndermen gerek t / f değeri döndür bunu directmovesta yapıp
	eğer hareket etmede sıkıntı yoksa sub functionlara göndereblirsin. hareket başarılı
	ise aynı zamanda mapte konum değiştireceksin + collectible alındı ise onları
	da check etmen lazım.
	*/
}

int	down_move(t_vars *vars)
{
	//check fonksiyonuna göndermen gerek t / f değeri döndür
}

int	right_move(t_vars *vars)
{
	//check fonksiyonuna göndermen gerek t / f değeri döndür
}

int	left_move(t_vars *vars)
{
	//check fonksiyonuna göndermen gerek t / f değeri döndür
}
