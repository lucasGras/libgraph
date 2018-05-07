/*
** EPITECH PROJECT, 2018
** lib graph
** File description:
** header
*/

#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <math.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "my.h"

#define SCREEN_X 1920
#define SCREEN_Y 1080


#ifndef LIB_GRAPH_DEBUG
#define LIB_GRAPH_DEBUG

extern	int	lib_graph_debug;

#endif

#ifndef LIB_GRAPH_CONF_PARSER
#define LIB_GRAPH_CONF_PARSER

sfVector2i	get_vector2i_str(char *);
sfVector2f	get_vector2f_str(char *);
sfBool		get_bool_str(char *);
int		valid_conf_file(char *, char *);
char		*get_fileconf_value(char *, FILE *);

#endif

#ifndef VECTOR_COMPONENT
#define VECTOR_COMPONENT

sfVector2f		new_vector2f(float, float);
sfVector2i		new_vector2i(int, int);
sfIntRect		get_rect_by_vector(sfVector2i);

#endif


#ifndef BUTTON_COMPONENT
#define BUTTON_COMPONENT

/**
 * \struct button_t
 * \brief Button component
 * Button structure fully automatic, hover and on_click gesture. Many set functions (message, size, font, ...)
 * */

#define BUTTON_DEF "def_ressources/def_button/button_def.png"
#define FONT_DEF "assets/Button/button_font.ttf"
#define FONT_DEF_LIB "lib/lib_graph/def_ressources/def_button/button_def_font.ttf"

typedef struct button_s {
	#define EXT_FILE	".png" /*!< Extension button's files*/
	#define EXT_H		"_hover.png" /*!< Extension button's hover files*/
	#define EXT_C		"_clicked.png" /*!< Extension button's clicked files*/
	sfRectangleShape	*shape;
	sfTexture		*txtr;
	sfVector2f		pos;
	sfVector2f		size;
	sfText			*message;
	sfFont			*font;
	char			*buble_str;
	int			id;
	int			clicked;
	char			*path_base;
	char			*path_hover;
	char			*path_click;
	void			*data_arg;
	void (*set_message)(struct button_s *, char *); /*!< Function to reset button's message*/
	void (*set_texture)(struct button_s *, char *); /*!< Function to reset button's texture*/
	void (*set_textsize)(struct button_s *, float); /*!< Function to reset button's text size*/
	void (*set_textpos)(struct button_s *, int, int); /*!< Function to reset button's text position*/
	void (*set_scale)(struct button_s *, int, int); /*!< Function to reset button's scale*/
	sfBool (*is_hovered)(struct button_s *, sfVector2f); /*!< Internal hover function*/
	void (*on_click)(void *); /*!< on_click function with generic argument*/
}	button_t;

typedef struct list_button_s {
	button_t		*data;
	struct list_button_s	*next;
}	list_button_t;

void		set_function_button(button_t *, void (*)());
button_t	create_button(sfVector2i, char *, void (*)(void *), void *);
void		display_button(button_t *, sfRenderWindow *);
void		active_button_action(button_t *, sfEvent);
void		set_path(button_t *, char *);
void		cor_set_message(button_t *, char *);
void		cor_set_texture(button_t *, char *);
void		cor_set_textsize(button_t *, float);
void		cor_set_textpos(button_t *, int, int);
void		cor_set_scale(button_t *, int, int);
sfBool		cor_is_hovered(button_t *, sfVector2f);
void		cor_on_click(void *);
int		str_is_null_or_empty(char *);
#endif


#ifndef DIALOG_BOX_COMPONENT
#define DIALOG_BOX_COMPONENT

/**
 * \struct dialog_box_t
 * \brief dialog_box component
 * dialog_box component used for pnj with read_text function
 * */

#define DIALOG_BOX_TXTR "def_ressources/def_dialog_box/dialog_box_def.png"
#define DB_SOUND "def_ressources/def_dialog_box/dialog_box_sound.ogg"

typedef struct	dialog_box_s {
	#define DB_SPEED 0.05 /*!< Speed of letter's display*/
	char		*tlk_text; /*!< Text to read*/
	sfText		*dynamic_text;
	sfFont		*font;
	sfSprite	*box_sprt;
	sfTexture	*box_txtr;
	sfSoundBuffer	*sound_buffer;
	sfSound		*sound;
	sfVector2i	button_pos;
	sfBool		displayed;
	button_t	skip_button; /*!< Skip button*/
	sfBool		skip;
	sfThread	*thread_tmp; /*!< Thread to read text in parallel*/
	void (*read_text)(struct dialog_box_s *); /*! read_text function who reads tlk_text<*/
} dialog_box_t;

dialog_box_t	create_dialog_box(int, int);
void		display_dialog_box(dialog_box_t *, sfRenderWindow *);
void		cor_skip_button(void *);
void		set_function_dialog_box(dialog_box_t *);

#endif


#ifndef PNJ_COMPONENT
#define PNJ_COMPONENT

/**
 * \struct pnj_component_t
 * \brief Automatic pnj component
 * Pnj structure, with automatic talk detection based on player. Need a configuration file
 * */

#define ADVENTURER_PNG "def_ressources/def_npc/npc_adventurer.png"

typedef struct pnj_component_s {
	#define PNJ_EXT	"tlk" /*!< Extension of configuration file: file.tlk*/
	#define PNJ_EOF	"#end" /*!< End of configuration file*/
	char		*file_path; /*!< Path to the configuration file*/
	char		*name;
	char		*text;
	sfSprite	*sprite;
	sfTexture	*texture;
	sfVector2f	position;
	char		*dialogbox_pos;
	dialog_box_t	dialog_box;
	sfRenderWindow	*window_ptr; /*!< sfRenderWindow pointer to draw without passing reference window*/
	void		*player_ptr; /*!< Player reference to detect action*/
	void		(*talk)(void *); /*!< Talk function called when interaction is detected with player_ptr*/
} pnj_component_t;

pnj_component_t		*init_pnj(char *, sfRenderWindow *);
void			display_pnj(pnj_component_t *, sfBool);
void			cor_talk(void *);

#endif

#ifndef TIME_COMPONENT
#define TIME_COMPONENT

void		wait_for_seconds(float);
int		get_random_int(void);
int		get_random_int_range(int, int);
float		get_random_float_range(float, float);
float		wait_and_get_seconds(float);
float		get_current_seconds(sfClock *);

#endif

#ifndef PARTICLE_SYSTEM
#define PARTICLE_SYSTEM

#define MAX_PARTICLE	500
#define MAX_RSPEED	5
#define DIRECTION_OUTRANGE 10

/**
 * \struct particle_t
 * \brief Single particle behaviour
 * Single particle, with all variables
 * */

typedef struct particle_s {
	sfSprite	*sprite; /*!< Particle's sprite*/
	sfTexture	*texture; /*!< Particle's texture*/
	sfVector2f	start_pos; /*!< Particle's start position*/
	sfVector2f	alpha_direction; /*!< Particle's direction*/
	sfVector2f	position; /*!< Particle's position overtime*/
	float		alpha_speed; /*!< Particle's speed*/
	int		alpha_rotation; /*!< Particle's rotation*/
	float		alpha_speed_rotation; /*!< Particle's rotation speed*/
	int		alpha_rgb; /*!< Particle's color in RGB*/

} particle_t;

/**
 * \enum system_type_t
 * \brief System's type get with configuration file
 * */

typedef	enum {
	EXPL, COS, DOWN
} system_type_t;

/**
 * \struct rgb_t
 * \brief Basic rgb structure
 * */

typedef struct {
	int	r; /*!< Red*/
	int	g; /*!< Green*/
	int	b; /*!< Blue*/
}	rgb_t;

/**
 * \struct particle_system_t
 * \brief Simple particle engine
 * Simple particle engine based on a configuration file
 * */

typedef struct particle_system_s {
	#define PARTICLE_SYSTEM_EXT "particle"
	particle_t	*particle_array; /*!< All particles contained in the system*/
	sfRenderWindow	*ptr; /*!< sfRenderWindow reference*/
	sfClock		*mvt_clock; /*!< Clock for animation (not based on framerate)*/
	char		*txtr_path;
	char		*system_name;
	int		nb_particles;
	int		lenght; /*!< System duration in seconds*/
	sfVector2f	origin; /*!< System's origin position*/
	system_type_t	type; /*!< Enum to know direction type*/
	int		range; /*!< Range of the system*/
	int		min_speed;
	int		max_speed;
	float		max_rotation_speed;
	sfBool		fade;
	sfThread	*systemp_thread; /*!< System's thread to anim particles in paralle*/
	sfBool		displayed;
	void		(*play_system)(struct particle_system_s *); /*!< Start the particle system*/
	void		(*reset_system)(struct particle_system_s *); /*!< Reset the particle system to original pos*/
	void		(*reset_system_rgbalpha)(struct particle_system_s *); /*!< Reset the particle system to original RGB*/
} particle_system_t;

particle_system_t	init_particle_system(char *, sfRenderWindow *);
particle_t		init_particle(particle_system_t *);
sfVector2f		cor_particle_startpos(particle_system_t *);
sfVector2f		cor_particle_direction(particle_system_t *);
int			cor_particle_rotation(particle_system_t *);
float			cor_particle_Rspeed(particle_system_t *);
float			cor_particle_speed(particle_system_t *);
void			display_particle_system(particle_system_t);
void			cor_particle_mouvement(particle_system_t *, float *);
void			mouvement_cosinus(particle_system_t *, float);
void			mouvement_down(particle_system_t *);
void			mouvement_explosion(particle_system_t *);
void			set_sprite_alpha(particle_t *, int);
void			color_over_time(particle_system_t *, rgb_t, rgb_t);
void			cor_reset_system(particle_system_t *);
void			cor_play_system(particle_system_t *);
sfVector2f		unit_vector(particle_t, float);
void			cor_reset_system_rbgalpha(particle_system_t *);
rgb_t			create_rgb(int, int, int);

#endif

#ifndef ANIMATOR
#define ANIMATOR

#define WHITE_SPRT "def_ressources/def_sprite/spritesheet.png"
#define RED_SPRT "def_ressources/def_sprite/red_sword_link.png"
#define BLUE_SPRT "def_ressources/def_sprite/blue_sword_link.png"
#define LEGEND_SPRT "def_ressources/def_sprite/purpul_sword_link.png"

#define PNJ1 "def_ressources/def_npc/npc_adventurer.png"
#define PNJ_1 "def_ressources/def_sprite/pnj_1.png"
#define PNJ_2 "def_ressources/def_sprite/pnj_2.png"
#define PNJ_3 "def_ressources/def_sprite/pnj_3.png"
#define PNJ_4 "def_ressources/def_sprite/pnj_4.png"
#define PNJ_5 "def_ressources/def_sprite/pnj_5.png"
#define PNJ_KING "def_ressources/def_sprite/king.png"
#define PNJ_QUEEN "def_ressources/def_sprite/queen.png"

#define RED_SWORD "def_ressources/def_weapon/red_sword.png"
#define BLUE_SWORD "def_ressources/def_weapon/blue_sword.png"
#define WHITE_SWORD "def_ressources/def_weapon/white_sword.png"
#define LEGEND_SWORD "def_ressources/def_weapon/legendary_sword.png"

#define BOW "def_ressources/def_weapon/bow.png"

#define BOOK1 "def_ressources/def_book/book1.png"
#define BOOK2 "def_ressources/def_book/book2.png"
#define BOOK3 "def_ressources/def_book/book3.png"
#define BOOK4 "def_ressources/def_book/book4.png"

#define RED_ORB "def_ressources/def_orb/red_orb.png"
#define BLUE_ORB "def_ressources/def_orb/blue_orb.png"
#define GREEN_ORB "def_ressources/def_orb/green_orb.png"

#define XBOX_COUNT 7
#define XBOX_A 0
#define XBOX_B 1
#define XBOX_X 2
#define XBOX_Y 3
#define XBOX_SELECT 6
#define XBOX_LB 4
#define XBOX_RB 5

/**
 * \struct keywrapper_t
 * \brief Keywrapper to associate Keys and Functions
 * */
typedef struct {
	sfKeyCode	key; /*!< Key code (A, G, ..)*/
	void		*argument; /*!< Argument to send to the call function*/
	void		(*call)(void *); /*!< Function called when key is pressed*/
} keywrapper_t;

/**
 * \struct joystickwrapper_t
 * \brief Joystickwrapper to associate xbox360 buttons with Functions
 * Animator component provides keywrapper, joystickwrapper, and spritesheet animation
 * */
typedef struct {
	int		controller_id; /*!< Joystick ID*/
	void		*argument; /*!< Argument to send to the call function*/
	void		(*call)(void *); /*!< Function called when key is pressed*/
} joystickwapper_t;

typedef struct	event_stack_s {
	sfEventType		event;
	struct event_stack_s	*next;
} event_stack_t;

/**
 * \struct animator_t
 * \brief Component to animate Player
 * Animator component provides keywrapper, joystickwrapper, and spritesheet animation
 * */
typedef struct animator_s {
	char			*sprite_sheet_path; /*!< Path to spritesheet in .png*/
	sfSprite		*sprite;
	sfTexture		*txtr;
	sfIntRect		rect;
	sfVector2f		pos;
	int			stack_function;
	sfThread		*thread_ptr; /*!< Animator's thread to play animation in parallel*/
	sfMutex			*mutex;
	keywrapper_t		*keywrapper; /*!< Keywrapper to set all keyboard binds*/
	joystickwapper_t	*joystickwapper; /*!< Joystickwrapper to set all controller binds*/
	int			move_rect;
	float			d;
	sfRenderWindow		*window_ptr;
	sfBool			activate;
	void			*player; /*!< Reference to the player (player_t)*/
	void			(*manage_event_stack)(struct animator_s *);
	void			(*active)(struct animator_s *, void *); /*!< Active function, call this function at the start of your programm*/
	void			(*desactive)(struct animator_s *);/*!< Desactive function, call this function at the end of your programm*/
	void			(*manage_event)(struct animator_s *, sfEventType);
	void			(*set_extern_joystick)(struct animator_s *,
				int, void (*)(void *), void *); /*!< Allows you to associate a function (with argument, or not) with a controller ID button*/
	void			(*set_extern_keyboard)(struct animator_s *,
				sfKeyCode, void (*)(void *), void *); /*!< Allows you to associate a function (with argument, or not) with a SfKeyCode*/
} animator_t;

animator_t		*create_animator(char *, int, int, sfRenderWindow *);
void			cor_animator_activate(animator_t *, void *);
void			cor_animator_desactivate(animator_t *);
void			cor_set_extern_joystick(animator_t *,
			int, void (*)(void *), void *);
void			cor_set_extern_keyboard(animator_t *,
			sfKeyCode, void (*)(void *), void *);
void			cor_manage_event(animator_t *, sfEventType);
int			joystick_moved(animator_t *);
void			cor_manage_event_stack(animator_t *);
void			process_stack_event(event_stack_t **, animator_t *);
void			my_right(void *);
void			atk_sword(void *);
void			atk_arrow_up(animator_t *);
void			atk_arrow_down(animator_t *);
void			atk_arrow(animator_t *);
void			face_sword_up(animator_t *);
void			face_sword_down(animator_t *);
void			face_sword(animator_t *);
void			backpack(void *);
void			check_arrow(void *);
void			check_sword(void *);
void			my_down(void *);
void			my_up(void *);
void			my_left(void *);
void			flip_right(animator_t *);
keywrapper_t		*my_keywrapper(animator_t *);
keywrapper_t		init_wrapper(sfKeyCode, void (*)(void *), void *);
void			flip_left(animator_t *);
void			joystick_manager(animator_t *);
void			mapping_controller(animator_t *);
void			spritesheet_mouvement(animator_t *);
joystickwapper_t	*get_joystickwrapper(animator_t *);
void			joystick_button_manager(animator_t *);

#endif

#ifndef INVENTORY_H
#define INVENTORY_H

#define INVENTORY_VISUAL "def_ressources/def_settings/inventory.png"
#define INVENTORY_SPE ""

/**
 * \struct inventory_item_t
 * \brief single inventory's item
 * */
typedef struct {
	char		*name;  /*!< Item's name*/
	int		damage; /*!< Item's damages*/
	int		magic_damage; /*!< Item's magic damages*/
	sfSprite	*item_sprite; /*!< Item's sprite*/
	sfTexture	*item_texture; /*!< Item's texture*/
} inventory_item_t;

/**
 * \struct inventory_item_t
 * \brief single inventory's item
 * */
typedef struct inventory_s {
	inventory_item_t	item; /*!< Item in inventory*/
	struct inventory_s	*next; /*!< Pointer to the next inventory's item*/
} inventory_t;

/**
 * \struct inventory_visual_t
 * \brief inventory UI
 * */
typedef struct inventory_visual_s {
	sfSprite	*inventory_sprt; /*!< Inventory sprite [place in middle]*/
	sfTexture	*inventory_txtr;
	sfSprite	*current_spe_sprt; /*!< Current special item [place in bottom left corner]*/
	sfTexture	*current_spe_txtr;
} inventory_visual_t;

inventory_visual_t	init_inventory_visual(void);

#endif

#ifndef PLAYER_H
#define PLAYER_H

#define BASE_LIFE 100
#define BASE_MANA 500
#define BASE_XP 0
#define BASE_INVENTORY_SIZE 2

#define ITEM_EXCALIBUR_TXTR "def_ressources/def_inventory/excalibur.png"
#define ITEM_HAND_TXTR "def_ressources/def_inventory/hand.png"
#define ITEM_BOOK_TXTR "def_ressources/def_inventory/MagicBook.png"

#define INVENTORY_START_STATE 0

#define COLLIDER_AROUND 0
#define COLLIDER_TOP 1
#define COLLIDER_RIGHT 2
#define COLLIDER_BOT 3
#define COLLIDER_LEFT 4

typedef enum	attack_type_s {
	AROUND, TOP, RIGHT, BOT, LEFT, NONE
} attack_type_t;

/**
 * \struct player_t
 * \brief Player component
 * */
typedef  struct player_s {
	int			life; /*!< Player's life*/
	int			mana; /*!< Player's mana*/
	int			xp;
	int			max_inventory_size; /*!< Player's max inventory size*/
	int			current_inventory_size; /*!< Player's backpack size*/
	inventory_t		*inventory; /*!< Player's inventory list*/
	inventory_item_t	curent_item; /*!< Player's item*/
	inventory_visual_t	inventory_visual;
	sfBool			inventory_displayed;
	sfRectangleShape	**attack_collider;
	attack_type_t		attack_type;
	int			horizontal_dir;
	sfVector2f		position;
	sfRenderWindow		*window_ptr; /*!< sfRenderWindow reference*/
	void		(*add_item)(struct player_s *, char *, int, int); /*!< Function to add item in inventory list*/
	void		(*set_inventory_size)(struct player_s *, int);
	void		(*change_item)(void *); /*!< Change current item*/
	void		(*set_life)(struct player_s *, int);
	void		(*set_mana)(struct player_s *, int);
	void		(*set_inventory_state)(struct player_s *, int); /*!< Initializer of inventory based on MACRO*/
	void		(*inventory_status)(void *); /*!< Display or not the inventory*/
} player_t;

player_t		*create_player(sfRenderWindow *);
void			cor_add_item(player_t *, char *, int, int);
void			cor_set_inventory_size(player_t *, int);
void			cor_set_player_life(player_t *, int);
void			cor_set_player_mana(player_t *, int	);
void			cor_set_inventory_state(player_t *, int);
void			cor_change_item(void *);
void			cor_display_inventory(void *);
void			display_inventory(player_t *);
char			*get_item_visualizer(char *);
void			manage_event(animator_t *);
void			update_trigger(player_t *);

#endif

#ifndef ENEMY
#define ENEMY

/**
 * \struct enemy_t
 * \brief Enemy component
 * Collision detection, path finding, ...
 * */
typedef struct enemy_s {
	#define			ENEMY_EXT "enemy"
	sfBool			alive;
	char			*name;
	int			life;
	int			xp;
	int			speed;
	player_t		*target;
	sfRectangleShape	*box_collider;
	sfTexture		*texture;
	sfVector2f		position;
	sfIntRect		rect;
	int			max_offset;
	sfThread		*thread;
	sfRenderWindow		*window_ptr;
	void			(*on_trigger)(struct enemy_s *);
	void			(*active)(struct enemy_s *);
	void			(*desactive)(struct enemy_s *);
	void			(*mouvement)(struct enemy_s *, sfVector2f);
} enemy_t;

enemy_t		*create_enemy(char *, player_t *, sfRenderWindow *,
							sfVector2f);
void		display_enemy(enemy_t *);
void		cor_on_trigger(enemy_t *);
sfVector2f	get_target_vector(enemy_t *, sfVector2f);
void		cor_follow_target(void *);
void		cor_active_enemy(enemy_t *);
void		cor_desactive_enemy(enemy_t *);
void		cor_mouvement(enemy_t *, sfVector2f);

#endif


#endif //LIB_GRAPH
