/*
** EPITECH PROJECT, 2018
** db
** File description:
** func
*/

#include <my.h>
#include "lib_graph.h"

void		cor_skip_button(void *data)
{
	dialog_box_t	*tmp = (dialog_box_t *)data;

	if (tmp->thread_tmp)
		tmp->skip = sfTrue;
	else if (!tmp->thread_tmp)
		tmp->displayed = sfFalse;
}

void		append_dialog(void *data)
{
	int		len = 0;
	dialog_box_t	*thread = (dialog_box_t *)data;
	char		buff[my_strlen(thread->tlk_text)];

	while (len < my_strlen(thread->tlk_text)) {
		my_strncpy(buff, thread->tlk_text, len);
		sfText_setString(thread->dynamic_text, buff);
		if (thread->skip == sfFalse)
			wait_for_seconds(DB_SPEED);
		len++;
	}
	sfThread_destroy(thread->thread_tmp);
	thread->thread_tmp = NULL;
	thread->skip_button.set_message(&thread->skip_button, "leave");
}

void		cor_read_text(dialog_box_t *self)
{
	sfThread	*append_thread;

	if (!self || self->thread_tmp)
		return;
	self->displayed = sfTrue;
	self->skip_button.set_message(&self->skip_button, "skip");
	append_thread = sfThread_create(append_dialog, self);
	self->thread_tmp = append_thread;
	sfSound_play(self->sound);
	sfThread_launch(append_thread);
}

void		set_function_dialog_box(dialog_box_t *item)
{
	item->read_text = cor_read_text;
}
