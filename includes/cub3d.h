/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcambaki <jcambaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:52:57 by jcambaki          #+#    #+#             */
/*   Updated: 2021/06/07 17:24:43 by jcambaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
** ------------------------------------------
**	INCLUDES
** ------------------------------------------
*/

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>
# include <string.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>

/*
** ------------------------------------------
**	STRUCTS
** ------------------------------------------
*/

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_bool		show_debug;
	t_vector3	*rcast_vectors;
	t_vector3	*rc_vect_p_index;
	char		*title;
	float		*rc_vect_len_coll;
	int			width;
	int			height;
	int			real_width;
	int			real_height;
	int			divider;
	int			nbr_pixels;
	int			render_distance;
}				t_window;

typedef struct s_state
{
	t_bool		pressed_state;
	t_bool		in_state;
	t_bool		out_state;
	long long	delta_last_time;
}				t_state;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct s_anim
{
	t_image		*sprite;
	t_image		**rescale_frames;
	long long	animation_last_time;
	int			animation_width;
	int			animation_height;
	int			animation_frames;
	int			animation_frames_width;
	int			animation_frames_height;
	int			animation_index_width;
	int			animation_index_height;
	int			animation_init_index_height;
	int			animation_refresh_time;
}				t_anim;

typedef struct s_wall
{
	float			a;
	float			b;
	float			c;
	float			d;
}				t_wall;

typedef struct s_mouse_control
{
	int			pos_x;
	int			pos_y;
	int			diff_pos_x;
	int			diff_pos_y;
}				t_mouse_control;

typedef struct s_player
{
	t_wall			player_plane;
	t_mouse_control	mouse;
	t_interval		position_sprite;
	t_anim			**anims;
	t_anim			*current_anim;
	t_image			*img;
	t_image			*hud;
	t_image			*hit;
	t_state			jump;
	t_state			run;
	t_state			idle;
	t_state			attack;
	t_state			guard;
	t_vector3		location;
	t_vector3		normal;
	t_vector3		init_location;
	t_bool			run_animation_side;
	t_bool			key_pressed;
	long long		last_time;
	long int		pixel_index;
	float			orientationx;
	float			orientationz;
	float			speed_constraint;
	float			speed;
	int				debug_mode;
	int				fov;
	int				life;
	int				number_of_animations;
}				t_player;

typedef struct s_wallsinfo
{
	t_wall			*walls;
	float			wall_dist;
	int				walls_counter;
}				t_wallsinfo;

typedef struct s_hud
{
	t_image		*life_bar_full;
	t_image		*life_bar_empty;
	t_image		*loose_screen;
	t_image		*win_screen;
	t_image		*black_screen;
}				t_hud;

typedef struct s_sprite_display
{
	t_image			*texture;
	t_color			color;
	char			*path;
}				t_sprite_display;

typedef struct s_textures
{
	t_sprite_display	no_wall;
	t_sprite_display	so_wall;
	t_sprite_display	ea_wall;
	t_sprite_display	we_wall;
	t_sprite_display	floor_wall;
	t_sprite_display	roof_wall;
}				t_textures;

typedef struct s_sprite
{
	t_anim		*current_animation;
	t_vector3	location;
	t_wall		plane;
}				t_sprite;

typedef struct s_enemy
{
	t_vector3	init_location;
	t_anim		*anims;
	t_sprite	sprite;
	t_state		run;
	t_state		idle;
	t_state		attack;
	t_state		hit;
	t_state		guard;
	long long	last_time;
	float		speed;
	float		sound_volume_value;
	int			number_of_animations;
	int			life;
	int			guard_probability;
	int			attack_time;
}				t_enemy;

typedef struct s_power_up
{
	t_sprite	sprite;
	char		*sound;
	float		added_life;
}				t_power_up;

typedef struct s_map
{
	t_wall			*walls;
	t_power_up		*power_ups;
	t_enemy			*enemys;
	char			*map_path;
	char			**map_datas;
	char			*sprite_idle_texture_path;
	float			wall_dist;
	float			enemy_dist;
	int				walls_x_counter;
	int				walls_y_counter;
	int				walls_counter;
	int				*walls_distance_render_index;
	int				walls_distance_render_len;
	int				power_up_counter;
	int				enemy_counter;
}				t_map;

typedef struct s_keypressed
{
	t_bool	left_pressed;
	t_bool	right_pressed;
	t_bool	up_pressed;
	t_bool	down_pressed;
	t_bool	a_pressed;
	t_bool	d_pressed;
	t_bool	w_pressed;
	t_bool	s_pressed;
	t_bool	fly_up_pressed;
	t_bool	fly_down_pressed;
	t_bool	attack_pressed;
	t_bool	guard_pressed;
	t_bool	sprint_pressed;
	t_bool	minimap;
}				t_keypressed;

typedef struct s_minimap
{
	t_image			*minimap;
	t_image			*minimap_save;
	t_image			*background;
	int				offset;
	int				width;
	int				height;
}				t_minimap;

typedef struct s_game
{
	t_window		*window;
	pthread_t		*threads;
	t_interval		*threads_interval;
	t_map			map;
	t_minimap		minimap;
	t_hud			hud;
	t_player		player;
	t_keypressed	key_pressed;
	t_textures		textures;
	t_textures		textures_bis;
	t_textures		textures_hidden;
	t_image			*img;
	t_image			*bitmap_image;
	t_image			*debug_img;
	t_bool			bitmap;
	t_bool			game_end;
	time_t			music_time;
	long long		delta_time;
	long long		last_time;
	float			distance;
	float			bs_value;
	int				fps;
	int				debug_offset;
}				t_game;

typedef struct s_check_collider_param
{
	t_vector3		vector;
	t_interval		t;
	t_bool			x_elem;
	t_bool			y_elem;
	int				p_index;
	int				elem_index;
	int				hit;

}				t_check_collider_param;

typedef struct s_wall_hit_param
{
	t_game			*game;
	t_vector3		inter_p;
	t_vector3		vector;
	t_vector3		indexs;
}				t_wall_hit_param;

typedef struct s_parsing_state
{
	t_bool		r_state;
	t_bool		r_state_finish;
	t_bool		no_state;
	t_bool		no_state_finish;
	t_bool		so_state;
	t_bool		so_state_finish;
	t_bool		we_state;
	t_bool		we_state_finish;
	t_bool		ea_state;
	t_bool		ea_state_finish;
	t_bool		s_state;
	t_bool		s_state_finish;
	t_bool		f_state;
	t_bool		f_state_finish;
	t_bool		c_state;
	t_bool		c_state_finish;
}				t_parsing_state;

typedef struct s_pthread_param
{
	t_game					*game;
	int						id;
	t_check_collider_param	params;
}				t_pthread_param;

typedef struct s_pthread_param_sounds
{
	pthread_t		thread;
	char			*path;
	float			volume;
}				t_pthread_param_sounds;

/*
** ------------------------------------------
**	CONSTANT VARIABLES
** ------------------------------------------
*/

# define	DEBUG 0
# define	SOUND_TIME 102
# define	SYSCALL 1
# define	RADIAN 0.01745329251
# define	FOV 110
# define	M_SENSIBILITY 1
# define	THREADS 16
# define	WIN_DIVIDER 4

# if DEBUG == 1
#  define	ROTATION_SPEED 0.2
#  define	MOVEMENT_SPEED 0.0030
#  define	RENDER_DISTANCE 30
#  define	JUMP_SPEED 0.0015
# else
#  define	ROTATION_SPEED 0.2
#  define	MOVEMENT_SPEED 0.0010
#  define	RENDER_DISTANCE 5
#  define	JUMP_SPEED 0.0015
# endif

/*
** ------------------------------------------
**	MAP parsing
** ------------------------------------------
*/

/*
**	Get Paths
*/

char				*get_path(char *str);
int					set_path(char *str, char **dst);
int					is_path_flag(char **splitted_line);
int					pars_by_flag(t_game *game, char \
						**splitted_line, t_parsing_state *state);

/*
**	Get Color
*/

void				color_flags_parsing(t_game *game, char **splitted_line, \
						t_parsing_state *state);

/*
**	Game Datas
*/

int					get_game_data(t_game *game);

/*
**	Map parcing
*/

void				map_parsing_checker(t_game *game, t_map *map);

/*
**	Window Size
*/

void				get_r(t_game *game, char **splitted_line);

/*
** ------------------------------------------
**	GAMES
** ------------------------------------------
*/

/*
**	Inits game
*/

int					init_player_pos(t_game *game, float zlocation);
void				init_sprites(t_game *game, float zlocation);
void				init_walls(t_game *game);
int					init_pixels(t_game *game);
int					init_map(t_game *game, int index_param_end);
void				init_keyboard(t_game *game);
void				init_walls_textures(t_game *game, t_textures *textures);
void				init_window(t_game *game);
void				init_black_screen(t_game *game);
void				init_hud(t_game *game);
t_textures			init_wall_bis_path(char *no_path, \
						char *so_path, char *we_path, char *ea_path);

/*
**	Inits structs
*/

void				init_structs(t_game *game);
void				init_struct_game(t_game *game);
void				init_struct_textures(t_textures *texture);
void				init_struct_window(t_window *window);
void				init_struct_hud(t_hud *hud);
void				init_struct_map(t_map *map);
void				init_struct_player(t_player *player);

/*
**	Inits player
*/

t_anim				*init_sprites_img_idle(t_game *game);
t_anim				*init_sprites_img_run(t_game *game);
t_anim				*init_sprites_img_jump(t_game *game);
t_anim				*init_sprites_img_attack(t_game *game);
t_anim				*init_sprites_img_guard(t_game *game);
void				set_player_images(t_game *game);
void				set_player_parameters(t_game *game, float zlocation);

/*
**	Inits enemy
*/

t_anim				init_sprites_img_enemy_idle(t_game *game, t_enemy *enemy);
t_anim				init_sprites_img_enemy_run(t_game *game, t_enemy *enemy);
t_anim				init_sprites_img_enemy_attack(t_game *game, t_enemy *enemy);
t_anim				init_sprites_img_enemy_guard(t_game *game, t_enemy *enemy);
t_anim				init_sprites_img_enemy_die(t_game *game, t_enemy *enemy);
t_anim				init_sprites_img_enemy_hit(t_game *game, t_enemy *enemy);

/*
**	Create sprites
*/

t_power_up			ft_create_power_up(\
						t_game *game, t_wall plane, t_vector3 location);
t_enemy				ft_create_enemy(\
						t_game *game, t_wall plane, t_vector3 location);

/*
**	Better MLX pixel put
*/

void				bettermlx_pixel_put(t_game *game, \
						t_vector3 pixel_coordinates, t_color color, \
							float darkness);
void				bettermlx_pixel_sprite_put(t_game *game, \
	t_vector3 pixel_coordinates, t_color color, float darkness);
long long			bettermlx_get_time(void);
unsigned char		*bettermlx_get_memory_position(\
						t_image *image, int x, int y);
void				bettermlx_set_color(t_image *image, \
						int x, int y, t_color color);
t_color				bettermlx_get_color(t_image *image, int x, int y);
t_image				*bettermlx_init_image(t_game *game, t_window *window, \
						int width, int height);
t_image				*bettermlx_init_xpm_image(\
						t_game *game, t_window *window, char *path);
void				*bettermlx_destroy_image(\
						t_window *window, t_image *image);
void				bettermlx_put_image_to_image(t_image *dst, \
						t_image *src, int x, int y);

/*
**	Get Pixels
*/

t_color				ft_get_pixel_texture_y(t_image *texture, \
						t_vector3 rcast_result);
t_color				ft_get_pixel_texture_x(t_image *texture, \
						t_vector3 rcast_result);
t_color				ft_get_pixel_texture_z(t_image *texture, \
						t_vector3 rcast_result);
t_color				ft_get_pixel_texture_sprite(t_player player, \
						t_sprite *sprite, t_vector3 r_result);
float				ft_make_x_sprite(t_player player, \
						t_vector3 location, float ab, float bc);
t_color				generate_color_by_parsing(unsigned char *destination);

/*
**	Check Collider
*/

int					rcast_check_collider(t_game *game, \
						t_check_collider_param *params);
void				rcast_check_collider_sprites(t_game *game, \
						t_check_collider_param *params);
void				rcast_check_collider_sprites_power_up(\
						t_game *game, t_check_collider_param *params);
void				rectif_impact_point(t_game *game, \
						t_vector3 *inter_p, int wall_index);
t_color				select_color(t_sprite_display sprite_display, \
						t_color (*get_pixel_texture)(t_image*, t_vector3), \
							t_vector3 inter_p);
int					check_size_sprite_on_plane(\
						t_sprite sprite, t_vector3 inter_p);
float				collision_value(t_game *game, t_sprite sprite, float tmp);
int					check_if_pixel_can_put(t_game *game, \
						t_check_collider_param *params, t_sprite sprite);
int					check_walls_hit(t_game *game, t_wall_hit_param params);
t_vector3			mk_vect_coll(t_vector3 player_location, \
						t_vector3 pixel_vector, float d);
void				select_y_elems(t_game *game, \
						t_check_collider_param *params);
void				select_x_elems(t_game *game, \
						t_check_collider_param *params);
void				select_looking_elements(t_game *game, \
						t_check_collider_param *params);
float				mk_rcast_per_vect(t_wall plane, \
						t_vector3 vector);

/*
**	Put Window
*/

void				*ft_put_window(void *param);
void				ft_put_player_sprite(t_game *game);
void				show_fps(t_game *game);
void				show_fov(t_game *game);
void				show_render_distance(t_game *game);
void				show_divider(t_game *game);
void				show_debug(t_game *game);
void				show_game_over_screen(t_game *game);

/*
**	Keyboard Events
*/

int					keyboard_player_mouvement(t_game *game);
int					key_press_hook(int key, t_game *game);
int					key_release_hook(int key, t_game *game);
int					attack(t_game *game);
void				player_attack(t_game *game);
void				jump(t_game *game, t_player *player);
void				release_guard(t_game *game);
void				key_press_hook_debug(int key, t_game *game);

/*
**	Mouse Events
*/

int					mouse_press_hook(int button, int x, int y, t_game *game);
int					mouse_release_hook(int button, int x, int y, t_game *game);
int					mouse_move(int x, int y, t_game *game);

/*
**	Player
*/

void				player_loose_life(t_game *game, t_player *player);
void				player_displacement(t_game *game, t_vector3 *fpl);
void				player_walk_anim(t_game *game, t_player *player);
void				release_guard(t_game *game);

/*
**	Power_up
*/

void				check_power_ups(t_game *game, t_map *map, t_player *player);
void				quicksort_power_ups_by_distance(t_game *game, \
						int index_start, int index_end);

/*
**	Hud
*/

void				put_hud(t_game *game);

/*
**	Enemys
*/

void				enemy_attack(t_game *game, t_enemy *enemy);
void				enemy_ai_management(t_game *game);
void				enemy_guard(t_game *game, t_enemy *enemy);
void				enemy_mouvement(t_game *game, t_enemy *enemy);
void				enemy_check_reset_location(t_game *game, t_enemy *enemy);
void				enemy_loose_life(t_map *map, int index);
void				delete_enemy(t_game *game, t_map *map, int index);
void				quicksort_enemys_by_distance(t_game *game, \
						int index_start, int index_end);
int					check_enemy_walls_collision(t_game *game, float x, float y);

/*
**	Minimap
*/

void				generate_minimap(t_game *game);
void				minimap_put_location_color(t_game *game, \
						t_vector3 location, t_color color);
void				minimap_reset_location_color(t_game *game, \
						t_vector3 location);
void				show_minimap(t_game *game);

/*
**	Utils
*/

float				ft_fmax(float a, float b);
float				ft_fmin(float a, float b);
float				ft_fabs(float a);
int					compare_vector_vector(t_vector3 v1, t_vector3 v2);
int					random_in_range(int lower, int upper);
char				*ft_itoa(int n);
t_wall				create_wall(float a, float b, float c, float d);
void				ft_dot_vector(t_wall *wall, t_vector3 normal, \
						t_vector3 location);
void				sprite_animation_with_time(t_anim *anim);
float				ft_dst_vect_vect(t_vector3 v1, t_vector3 v2);
int					animation_end(t_anim anim);
t_image				*rescale_img(t_game *game, t_image *src_img, \
						int dst_width, int dst_height);
t_image				**rescale_frames_in_tab(\
						t_game *game, t_anim *anim, t_interval dst_size);

/*
**	Threads
*/

int					init_threads(t_game *game);
t_pthread_param		*ft_init_pthread_param(t_game *game, int id);
int					ft_multi_thread(t_game *game);

/*
**	Errors
*/

void				error_display(char *error_type, char *error_location);
void				error_parsing_path(t_game *game, char **splitted_line);
t_color				error_parsing_color(t_game *game, char **splitted_line);

/*
**	Free
*/

void				free_enemy(t_game *game, t_map *map);
void				free_power_ups(t_game *game, t_map *map);
void				free_player(t_game *game, t_player player);
void				free_game(t_game *game);
void				ft_fullfree(void *param);

/*
**	Sound
*/

void				stop_sounds(void);
void				play_sound(char *sound_path, float volume);
void				playmusic(t_game *game);

/*
**	Miscellaneous
*/

int					quit_game(t_game *game);
int					create_bitmap(t_game *game);
void				put_life_hud_for_bitmap(t_game *g);
int					ft_exec(t_game *game);

#endif
