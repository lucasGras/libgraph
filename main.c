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
	animator_t *animator = create_animator(BLUE_SPRT, 44, 60, &event);
	pnj_component_t *pnj1 = init_pnj("test.tlk", window);
	enemy_t		*enemy = create_enemy("test.enemy", player, window);

	animator->set_extern_keyboard(animator, sfKeyTab, player->inventory_status, player);
	animator->set_extern_joystick(animator, XBOX_SELECT, player->inventory_status, player);
	animator->set_extern_joystick(animator, XBOX_A, pnj1->talk, pnj1);
	animator->set_extern_joystick(animator, XBOX_RB, player->change_item, player);
	player->add_item(player, "Excalibur", 10, 0);
	player->add_item(player, "MagicBook", 0, 10);
	animator->active(animator, player);
	enemy->active(enemy);
	printf("current weapon damage: %s=%d\n", player->curent_item.name, player->curent_item.damage);
	sfRenderWindow_setFramerateLimit(window, 60);
	while (sfRenderWindow_isOpen(window)) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, animator->sprite, sfFalse);
		display_enemy(enemy);
		update_trigger(player);
		display_pnj(pnj1, sfFalse);
		display_inventory(player);
		while (sfRenderWindow_pollEvent(window, &event)) {
		}
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
