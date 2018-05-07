/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

/**
 * \file main.c
 * \brief This main is only a test main
 * \author Lucas Gras
 * Function __test__ to test libgraph addons, this file is not compiled with
 * libgrah.a
 */

#include <lib_graph.h>
#include <SFML/Window.h>
#include "lib_graph.h"

void on_click(void *db)
{
	particle_system_t *sys = (particle_system_t *)db;

	sys->play_system(sys);
}

void __tester__()
{
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "__tester__",
				sfClose | sfResize, NULL);
	sfEvent event;
	player_t *player = create_player(window);
	animator_t *animator = create_animator(BLUE_SPRT, 44, 60, window);
	//pnj_component_t *pnj1 = init_pnj("test.tlk", window);
	sfVector2f pos = {400, 10};
	sfVector2f pos2 = {900, 10};
	enemy_t		*enemy = create_enemy("test.enemy", player, window, pos);
	enemy_t		*enemy2 = create_enemy("test.enemy", player, window, pos2);

	animator->set_extern_keyboard(animator, sfKeyTab, player->inventory_status, player);
	animator->set_extern_joystick(animator, XBOX_SELECT, player->inventory_status, player);
	//animator->set_extern_joystick(animator, XBOX_A, pnj1->talk, pnj1);
	animator->set_extern_joystick(animator, XBOX_RB, player->change_item, player);
	player->add_item(player, "Excalibur", 10, 0);
	player->add_item(player, "MagicBook", 0, 10);
	animator->active(animator, player);
	enemy->active(enemy);
	enemy2->active(enemy2);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		//display_pnj(pnj1, sfFalse);
		display_inventory(player);
		joystick_manager(animator); // if Joystick !
		while (sfRenderWindow_pollEvent(window, &event)) {
			animator->manage_event(animator, event.type);
		}
		sfRenderWindow_drawSprite(window, animator->sprite, sfFalse);
		display_enemy(enemy);
		display_enemy(enemy2);
		update_trigger(player);
		sfRenderWindow_display(window);
	}
	animator->desactive(animator);
}

int main(int ac, char **av, char **env)
{
	if (env == NULL)
		return 84;
	srand((unsigned int)time(NULL));
	__tester__();
	(void)ac;
	(void)av;
	return 0;
}
