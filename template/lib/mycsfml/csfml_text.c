/*
** EPITECH PROJECT, 2023
** csfml_text
** File description:
** All the functions related to text in CSFML
*/

#include "mycsfml.h"

void set_text_settings(text_t *text_box, sfText* text)
{
    if (text_box->size != 0)
        sfText_setCharacterSize(text, text_box->size);
    if (text_box->lineSpacing != 0.0)
        sfText_setLineSpacing(text, text_box->lineSpacing);
    if (text_box->letterSpacing != 0.0)
        sfText_setLetterSpacing(text, text_box->letterSpacing);
    if (text_box->outlineColor_size != 0.0) {
        sfText_setOutlineColor(text, text_box->outlineColor);
        sfText_setOutlineThickness(text, text_box->outlineColor_size);
    }
    if (text_box->rotation != 0.0)
        sfText_setRotation(text, text_box->rotation);
    if (text_box->style != 0)
        sfText_setStyle(text, text_box->style);
}

void draw_text(sfRenderWindow* window, text_t *text_box, sfVector2f position)
{
    sfFont* font = sfFont_createFromFile(text_box->font);
    sfText* text = sfText_create();

    sfText_setString(text, text_box->text);
    sfText_setFont(text, font);
    sfText_setColor(text, text_box->color);
    set_text_settings(text_box, text);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

sfText *create_sf_text(text_t *text_box, sfVector2f position)
{
    sfFont* font = sfFont_createFromFile(text_box->font);
    sfText* text = sfText_create();

    sfText_setString(text, text_box->text);
    sfText_setFont(text, font);
    sfText_setColor(text, text_box->color);
    set_text_settings(text_box, text);
    sfText_setPosition(text, position);
    return text;
}
