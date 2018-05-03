##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME_LIB	=	libgraph.a

NAME_EX		=	libgraph_exe

SRC_UTILS	=	src/utils/my_getnbr.c \
			src/utils/my_putchar.c \
			src/utils/my_put_nbr.c \
			src/utils/my_putstr.c \
			src/utils/my_putstr_err.c \
			src/utils/my_strcat_malloc.c \
			src/utils/my_strcmp.c \
			src/utils/my_strlen.c \
			src/utils/my_strcpy.c \
			src/utils/my_memset.c \
			src/utils/my_strncmp.c \
			src/utils/my_str_to_word_array.c \
			src/utils/clear_str.c

SRC		=	src/button/button_function.c \
			src/button/init_button.c \
			src/button/button_data_structure.c \
			src/button/button_id.c \
			src/button/display_button.c \
			src/button/button_path.c \
			src/button/cor/cor_event.c \
			src/button/cor/cor_rectangle_shape.c \
			src/button/cor/cor_text.c \
			src/animator/init_animator.c \
			src/animator/keywrapper.c \
			src/animator/active_animator.c \
			src/animator/event_animator.c \
			src/animator/event_anim_bis.c \
			src/animator/backpack.c \
			src/animator/spritesheet_mouvement.c \
			src/animator/spritesheet_flip.c \
			src/animator/xbox360_controller/manager.c \
			src/animator/xbox360_controller/mapping.c \
			src/dialog_box/init_dialog_box.c \
			src/dialog_box/dialog_box_function.c \
			src/dialog_box/display_dialog_box.c \
			src/time/timer.c \
			src/time/random.c \
			src/parser/conf_file_parser.c \
			src/parser/check_conf.c \
			src/parser/vector_parser.c \
			src/parser/boolean_parser.c \
			src/pnj/pnj_conf.c \
			src/pnj/display_pnj.c \
			src/particle_system/init_particle.c \
			src/particle_system/particlesystem_conf.c \
			src/particle_system/cor/cor_startpos.c \
			src/particle_system/cor/cor_direction.c \
			src/particle_system/cor/cor_rotation.c \
			src/particle_system/cor/cor_particle_mouvement.c \
			src/particle_system/particlesystem_display.c \
			src/particle_system/particlesystem_play.c \
			src/particle_system/particlesystem_reset.c \
			src/particle_system/operation/alpha.c \
			src/particle_system/operation/color.c \
			src/particle_system/operation/cosinus.c \
			src/particle_system/operation/down.c \
			src/particle_system/operation/explosion.c \
			src/player_system/inventory_system/inventory_action.c \
			src/player_system/inventory_system/inventory_visualizer.c \
			src/player_system/inventory_system/init_inventory.c \
			src/player_system/inventory_system/display_inventory.c \
			src/player_system/init_player.c \
			src/player_system/player_action/life_action.c \
			src/player_system/player_action/mana_action.c \
			src/vector/vector.c \
			src/enemy/enemy_target.c \
			src/enemy/enemy_trigger.c \
			src/enemy/init_enemy.c \

SRC_EX		=	main.c

OBJ_EX		=	$(SRC_EX:.c=.o) $(SRC_UTILS:.c=.o) $(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -g3

CFLAGS		+=	-I./include

lib		:	$(NAME_LIB)

exe		:	$(NAME_EX)

$(NAME_LIB)	:
			cc -c $(SRC) $(SRC_UTILS) -lc_graph_prog -lm \
			-I./include/
			@ar rc $(NAME_LIB) *.o
			make compress
			@tar -xvf assets.tar.gz
			@$(foreach file , $(SRC), echo -ne "\\033[32m[OK] \\033[m" && echo $(file);)
			@cat .makefile_ascii
			@rm -f assets.tar.gz
			@echo -e "\\033[32m[OK] Intern library [libgraph]\\033[m"

$(NAME_EX)	:	$(OBJ_EX)
			cc -o $(NAME_EX) $(OBJ_EX) -lc_graph_prog -lm \
			-I./include/
			@echo -e "\\033[32m[OK] Compilation\\033[m"
			@tar -xvf assets.tar.gz
			@echo -e "\\033[32m[OK] Untar assets\\033[m"
			@$(foreach file , $(SRC), echo -ne "\\033[32m[OK] \\033[m" && echo $(file);)
			@cat .makefile_ascii
			@rm -f assets.tar.gz
			@echo -e "\\033[32m[OK] Intern library [libgraph] EXECUTION MODE\\033[m"

clean	:
		rm -f $(NAME_LIB)
		rm -f $(NAME_EX)

fclean	:	clean
		rm -rf $(OBJ_EX)
		rm -rf *.o

re	:	fclean all

compress	:
			@rm -f assets.tar.gz
			tar -zcvf assets.tar.gz def_ressources;
			rm -rf def_ressources/
			@echo -e "\\033[32m[OK] Compression done !\\033[m"
