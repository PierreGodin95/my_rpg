/*
** EPITECH PROJECT, 2023
** my_rpg function_list
** File description:
** Contains the list of functions
** to proccess
** each type of variable
*/

#include <string.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include <SFML/System/Sleep.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

#ifndef MY_H_DEFS
    #define MY_H_DEFS
    #define T_NAME 50
    #define STATS_NBR 4
    #define MAX_LINES 1000
    #define MAX_LINE_LENGTH 1000
#endif

typedef struct g_data_t game_t;

// ENUM //

enum PREF {
    X = 1920,
    Y = 1080,
    FPS = 60,
    WIN = 0,
    BITS = 32
};

// SOUNDS //

typedef struct sound_t {
    sfSoundBuffer *b;
    sfSound *s;
    char *name;
    struct sound_t *next;
} sound_t;

typedef struct sounds_t {
    sound_t *bgm;
    sound_t *sfx;
    int vol;
} sounds_t;

// CHARACTER //

typedef struct character_t {
    sfTexture *t;
    sfSprite *s;
    float off_pos_x;
    float off_pos_y;
    float pos_x;
    float pos_y;
    float speed;
    int hp;
    int max_hp;
    int defence;
    int hostile;
    int is_vis;
    int anim;
    int lastdir;
    int is_moving;
    int anim_state;
    struct character_t *next;
} char_t;

typedef struct characters_t {
    char_t *plr;
    char_t *npc;
    char_t *foes;
    float damage;
    float defence;
    int hp;
    float luck; // more chance to hit the enemy
    float speed; // chance of avoiding an enemy attack
    int exp;
    int level;
} chars_t;

// UI //

typedef struct size_vec_t {
    float s_x;
    float s_y;
    float x;
    float y;
} v_size_t;

/*
    t:  Texture
        [0] = Default
        [1] = Hovered
        [2] = Selected
    callback: when a button is pressed, execute..
    index: order of displaying a UI on screen (2 will show up on top of 1)
    is_vis: Is visible (0 = False / 1 = True)
*/
typedef struct button_t {
    sfTexture *t[3];
    sfSprite *s;
    char *name;
    int is_vis;
    int is_hov;
    int index;
    int data_id;
    int is_modal;
    void (*callback)(struct button_t *);
    struct button_t *next;
} btn_t;

typedef struct sprite_t {
    sfTexture *t;
    sfSprite *s;
    char name[T_NAME];
    int is_vis;
    int index;
    struct sprite_t *next;
} sprite_t;

typedef struct rect_t {
    sfRectangleShape *s;
    int is_vis;
    int index;
    struct rect_t *next;
} rect_t;

typedef struct txt_t {
    sfText *t;
    char *name;
    int is_vis;
    int index;
    int is_modal;
    struct txt_t *next;
} text_t;

typedef struct modal_t {
    sfTexture *t;
    sfSprite *s;
    int is_vis;
    int index;
    struct modal_t *next;
} modal_t;

typedef struct ui_l {
    sfFont *font[1];
    modal_t *modals;
    text_t *texts;
    rect_t *rects;
    sprite_t *sprites;
    sound_t *sound;
    btn_t *btns;
    int ui_id;
    text_t *dialogue;
} UI_t;

// BACKPACK //

/*
    char *name = Name of the tool
    char *texture = png path that shows up
                    in the backpack thumbnail
    int off_x = offset x (in px) of the thumbnail
    int off_y = offset y (in px) of the thumbnail
    int count = current count of items in that slot
    int max_count = max count of items per slot
    int slot = slot id (0 to 5)
    int type
        0 = tool
        1 = firearm
*/
typedef struct item_s {
    char *name;
    char *texture;
    int off_x;
    int off_y;
    int count;
    int max_count;
    int slot;
    int type;
    int burst; /* number of bullets fired per round */
    int dmg; /* damage per round */
    int ammo_type; /* 0 = rifle, 1 = pistol */
    int accuracy; /* 0 to 100: chance to hit (100% the most) */
    struct item_s *next;
} item_t;

typedef struct tools_d_s {
    item_t M4A1;
    item_t G17;
    item_t X26;
    item_t Handcuffs;
    item_t Baton;
} tools_d_t;

/*
    item_t *tools:  linked list to the tool list
                    in the backpack;
    int is_open:    is the backpack UI open? (1 = true)
*/
typedef struct backpack_s {
    item_t tools[7];
    item_t t_prim;
    item_t t_sec;
    text_t *slot_txt;
    btn_t *btn;
    int is_open;
    tools_d_t data;
} inv_t;

// CORE //

typedef struct game_config_t {
    int x;
    int y;
    int fps;
    int win;
    float bgm;
    float bgs;
    float sfx;
    float text;
} config_t;

typedef struct saves_l {
    FILE *fp;
    char *lm;
    btn_t *btn;
    text_t *txt;
    int is_empty;
} SAVES_t;

typedef struct clocks_l {
    sfClock *text_speed;
    sfClock *movement_clock;
    sfClock *combat_clock;
} clocks_t;

// Map struct
typedef struct map_t {
    int **map;
    int width;
    int height;
    int tile_size;
} map_t;

typedef struct tile_t {
    sfTexture *texture;
    sfSprite *sprite;
    int x;
    int y;
    struct tile_t *next;
} tile_t;

typedef struct spritemap_t {
    tile_t *tiles;
    int width;
    int height;
    int tile_size;
} spritemap_t;

typedef struct char_filepath {
    char character;
    const char *filepath;
} char_filepath_t;

typedef struct enemy_t {
    char id;
    int health;
    int maxhealth;
    int damage;
} enemy_t;

typedef struct defeated_enemies_s {
    char enemy;
    struct defeated_enemies_s* next;
} defeated_enemies_t;

typedef struct g_data_t {
    sfRenderWindow* w;
    sfEvent e;
    int scene;
    int paused;
    int elapsed_time;
    int elapsed_scene;
    UI_t ui;
    SAVES_t saves[4];
    inv_t backpack;
    config_t pref;
    clocks_t clks;
    sounds_t sound;
    chars_t chars;
    char **map;
    char spawn;
    char currmap;
    spritemap_t spritemap;
    char *dialogue;
    int dialogueline;
    char dialogueid;
    int in_combat;
    int turn;
    int playerdamage;
    int is_defending;
    int main;
    enemy_t enemy;
    defeated_enemies_t *defeated_enemies;
    char_filepath_t tilepath[];
} game_t;

#ifndef MY_H_FUNCT
    #define MY_H_FUNCT
extern game_t game;

// [[SCENES]] //
void ui_main_menu_load(void);

// [[POPULATE]] //
void populate_innit(void);
void ui_pause_requirements(void);
void ui_pause_req_sett4(void);
void ui_pause_back(int show);
void populate_backpack_ui(void);
void tool_populate_data(void);
void ui_bp_populate(void);

// [[ MUSIC ]] //
// Background Music (bgm)

// [[ DESTROY ]] //

// [[ UI ]] //
// Rectangles //
rect_t *rect_create(int vis, int index);
void rect_pos(rect_t *s, float x, float y);
void rect_size(rect_t *s, float x, float y);
void rect_origin(rect_t *s, float x, float y);
void rect_destroy(rect_t *s);

// Buttons //
void btn_new_texture(btn_t *btn, char *t_path, int type);
btn_t *btn_create(char *name, char *t_path, int vis, int index);
void btn_pos(btn_t *s, v_size_t size);
void btn_size(btn_t *s, float x, float y);
void btn_scale(btn_t *s, float x, float y);
void btn_origin(btn_t *s, float x, float y);
void btn_destroy(btn_t *s);
void btns_hover(void);
void z_index_sort(void);
int btn_set_vis(char *name, int is_vis, int group);
int btn_set_nvis(char *name, int is_vis);
void btns_click(void);
void btns_unclick(void);
void btns_unhover(void);

// Sprites //
sprite_t *sprite_create(char name[T_NAME], char *t_path, int vis, int index);
void sprite_pos(sprite_t *s, float x, float y);
void sprite_size(sprite_t *s, float x, float y);
void sprite_origin(sprite_t *s, float x, float y);
void sprite_destroy(sprite_t *s);

// Modals //
modal_t *modal_create(char *t_path, int vis, int index);
void modal_pos(modal_t *s, float x, float y);
void modal_size(modal_t *s, float x, float y);
void modal_origin(modal_t *s, float x, float y);
void modal_destroy(modal_t *s);

// Sounds //
sound_t *add_ui_sound(char *s_path, char *name);

// Render //

// Text //
text_t *txt_create(char *name, int font, int font_size, char *txt);
void text_pos(text_t *txt, v_size_t pos);
void text_origin(text_t *txt, float x, float y);
int text_set_vis(char *name, int is_vis, int group);
void text_linked(text_t *tmp);
int text_set_text(char *name, char *text, int group);

// Basic / Core //
void ui_main_closeall(btn_t *btn);
void game_pause_toggle(int force);

// Settings //
void pref_window_mode(btn_t *btn);
void pref_resolution_mode(btn_t *btn);
void pref_upt_slider(btn_t *hitbox);

// Backpack //

void backpack_show(int state);
void bp_update(void);

// [[ SUBTITLES ]] //

// [[ CORE ]] //
// Game Window
void game_quit_btn(btn_t *btn);
void saves_innit(void);
void ui_main_saveload(btn_t *btn);
void ui_main_prefload(btn_t *btn);
void ui_pause_req_sett(void);

// Clocks

// Heartbeat (hb)
void hb_main(void);
void hb_ui_elements(void);

// Events
void event_key_pressed(sfEvent event);
void event_mouse_rclick(sfEvent event);
void event_mouse_click(sfEvent event);
void event_mouse_moved(sfEvent event);
void event_mouse_up(sfEvent event);

// Destroy
void destroy_all(void);
void destroy_ui(void);
void destroy_ui3(void);

// [[ FILE HANDLING ]] //
// Saves
void save_game_state(char_t *character, game_t *game_data,
    item_t *current, int save_id);
void save_stats(char_t *character, char lines[][20], FILE *file);
void save_game_data(game_t *game_data, char lines[][20], FILE *file);
void save_hotbar(item_t *current, char lines[][20], FILE *file);
void save_backpack(item_t *current, char lines[][20], FILE *file);
// Load Saves
int load_main(void);
void free_array(char **array);
char **read_file_to_array(const char *file_path);
void load_save(char **array);
void replace_inv(char **array, item_t *item, int i);
void replace_stats(char **array, char_t *character, game_t *game_data, int i);

void ui_main_saveprompt(btn_t *btn);

void saves_load_file(btn_t *btn);
void saves_save_file(btn_t *btn);

// File Data

// [[ UTILITIES ]] //
// int
int get_int_len(int num);
char *int_to_str(int num);
int to_num(char const *str);
// string (str)
int m_strcmp(const char *str1, const char *str2);
char *m_strcat(char *dest, char const *src);
char *m_strcpy(char *dest, const char *src);
int m_strlen(char const *str);
char *m_strrchr(const char *str, int ch);
char *m_strdup(char *str);
int m_strequ(const char *str1, const char *str2);

//player
void init_player(void);
void move_player(sfClock *lerp);
void step(int lastdir);
void interactdialogue(void);
void animate_player(sfClock *animate);
void get_spawn(void);
void check_combat(void);
void enemy_damage(void);
void damage_enemy_primary(btn_t *btn);
void damage_enemy_secondary(btn_t *btn);
int is_defeated(char enemy);
void combat_menu_load(void);
void show_combat_ui(int show);
void defend(btn_t *btn);
void backpack_show_btn(btn_t *btn);
void assign_bars(void);
void toggle_main_menu(int toggle);
void open_main_menu(btn_t *btn);

// [[ MAP ]] //

void read_map(char path, int travel);
void draw_sprites(int offset_x, int offset_y);
tile_t *create_tile(const char *filepath, int x, int y);
tile_t *add_tile(tile_t *new_tile, tile_t *prev_tile, int i, int j);

#endif
