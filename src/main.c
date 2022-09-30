// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/05/31 12:05:32 by steh              #+#    #+#             */
// /*   Updated: 2022/09/26 16:26:00 by steh             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "example.h"
// #include "../libft/libft.h"
// #include <stdio.h>
// int	key_hook(int keycode)
// {
// 	// Esc = 53
// 	if (keycode == 53)
// 		exit(1);
// 	return (0);
// }

// int	main(void)
// {
// 	// int a = ft_atoi("1");
// 	// printf("%d\n", a);
// 	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"
// 	int		count_w;
// 	int		count_h;

// 	count_h = -1;
// 	//First you need to call mlx_init and store its return value.
// 	mlx.mlx_ptr = mlx_init();
// 	//Now do the same with mlx_new_window
// 	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example");
// 	//One more time with mlx_new_image
// 	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
// 	/*
// 	 Now the important part :
// 	 mlx_get_data_addr will return a char* that is 4 times the (width * height) of your image.
// 	 Why so ? Let me explain : This char* will represent your image, pixel by pixel,
// 	 and the values of this array are the colors. That's why the array is 4 times bigger :
// 	 you need 4 char to code the color of each pixels (one for Red, Green and Blue) and one for the alpha.
// 	 But... it's not very convenient, right ? So here is my little trick : you cast
// 	 mlx_get_data_addr as an int* and store it in an int*.
// 	 This way, the array will have the exact same size as your window, and each index
// 	 will represent one complete color of a pixel !
// 	*/
// 	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
// 		&mlx.img.endian);
// 	/*
// 	 Now just a little example : here is a loop that will draw each pixels that
// 	 have an odd width in white and the ones that have an even width in black.
// 	*/
// 	while (++count_h < WIN_HEIGHT)
// 	{
// 		count_w = -1;
// 		while (++count_w < WIN_WIDTH)
// 		{
// 			if (count_w % 2)
// 				/*
// 				 As you can see here instead of using the mlx_put_pixel function
// 				 I just assign a color to each pixel one by one in the image,
// 				 and the image will be printed in one time at the end of the loop.
// 				 Now one thing to understand here is that you're working on a 1-dimensional
// 				 array, while your window is (obviously) 2-dimensional.
// 				 So, instead of having data[height][width] here you'll have the following
// 				 formula : [current height * max width + current width] (as you can see below)
// 				*/
// 				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
// 			else
// 				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
// 		}
// 	}
// 	//Now you just have to print the image using mlx_put_image_to_window !
// 	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
// 	mlx_key_hook(mlx.win, key_hook, &mlx);
// 	mlx_loop(mlx.mlx_ptr);
// 	return (0);
// }


#include <fcntl.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

static int		find_length(char *str, char *charset)
{
	int count;

	count = 0;
	while (*str)
		if (!ft_strchr(charset, *str++))
			count++;
	return (count);
}

static void		import_str(char **dest, char *src, int start, int end)
{
	if (!(*dest = malloc(((end - start + 1) * sizeof(char)))))
		return ;
	ft_strlcpy(*dest, src, end - start);
	(*dest)[end - start] = '\0';
}

char			**ft_split2(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (str == 0)
		return (0);
	if (!(strs = malloc((find_length(str, charset) + 1) * sizeof(char *))))
		return (0);
	while (str[j] != '\0')
	{
		i = j;
		while (!ft_strchr(charset, str[j]) && str[j] != '\0')
			j++;
		if (i != j)
			import_str(&strs[k++], &str[i], i, j);
		else
			j++;
	}
	strs[k] = 0;
	return (strs);
}

void	get_texture(char *texture_path)
{
	char *path;

	path = ft_strdup(texture_path);
	printf("path: %s\n", path);
}

void	get_data(char **strs)
{
	// printf("strs[0]: %s\n", strs[0]);
	// // printf("strs[0][1]: %c\n", strs[0][1]);
	// printf("strs[1]: %s\n", strs[1]);
	// // printf("strs[1][1]: %c\n", strs[1][1]);
	// printf("strs[2]: %s\n", strs[2]);
	if (strs[0] == 0)
		return ;
	else if (!ft_strcmp(strs[0], "N") && strs[1] != 0 && strs[2] == 0)
		get_texture(strs[1]);
}

int		is_map(char *line)
{
	int	check;

	check = 0;
	while (*line)
	{
		if (!ft_strchr("012NSEW \n\t\v\f\r", *line))
			return (0);
		else if (*line == '1')
			check = 1;
		line++;
	}
	return (check);
}

int main(int argc, char const *argv[])
{
	int		fd;
	int		len;
	char	*ext;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			close(fd);
			printf("file not exit\n");
			return (0);
		}
		len = ft_strlen(argv[1]);
		ext = (char *)ft_memchr(argv[1], '.', len);
		if (!ft_strcmp(ext, ".cub"))
			printf("file is cub\n");
		else
			printf("file is not cub\n");
		char	*line;
		char	**strs;
		int		i;
		i = -1;
		line = get_next_line(fd);
		while (line != NULL)
		{
			if (!is_map(line))
			{
				strs = ft_split2(line, " \n\t\v\f\r");
				// printf("%s", line);
				// printf("STRS[%d]: %s\n", i, strs[i]);
				get_data(strs);
				// if (!ft_strcmp(strs[i], "NO"))
				free(line);
				// printf("%s\n", *strs);
				i++;

			}
			line = get_next_line(fd);
		}
		printf("\n\n");
		close(fd);
	}
	return (0);
}
