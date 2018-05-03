/*
** EPITECH PROJECT, 2018
** timer
** File description:
** time
*/

#include "lib_graph.h"

float		get_current_seconds(sfClock *clock)
{
	sfTime		time;
	float		seconds = 0;

	time = sfClock_getElapsedTime(clock);
	seconds = sfTime_asSeconds(time);
	return seconds;
}

int		check_timer(sfClock *clock, float timer)
{
	sfTime		time;
	float		seconds = 0;

	time = sfClock_getElapsedTime(clock);
	seconds = sfTime_asSeconds(time);
	if (seconds >= timer)
		return 1;
	return 0;
}

void		wait_for_seconds(float timer)
{
	sfClock		*clock;
	int		finished = 0;

	if (timer <= 0)
		return;
	clock = sfClock_create();
	while (finished == 0)
		finished = check_timer(clock, timer);
	sfClock_destroy(clock);
}

float		wait_and_get_seconds(float timer)
{
	sfClock		*clock;
	int		finished = 0;
	float		seconds;

	clock = sfClock_create();
	while (finished == 0)
		finished = check_timer(clock, timer);
	seconds = get_current_seconds(clock);
	sfClock_destroy(clock);
	return seconds;
}
