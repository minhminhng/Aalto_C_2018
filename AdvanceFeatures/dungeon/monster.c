/* monster.c -- Implementation of monster actions
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dungeon.h"

// for defining some monster types below that can be used in the game
typedef struct {
    char name[20];  // Name of monster
    char sign;  // character to show it on map
    unsigned int hplow;  // lowest possible initial maxhp
    unsigned int hphigh;  // highest possible initial maxhp
} MonstType;

// Specifying three monster types to start with.
// Feel free to add more, or change the below
// Note that it is up to you to decide whether to use this array from createMonsters
// you may or may not use it
const MonstType types[] = {
    { "Goblin", 'G', 6, 10},
    { "Rat", 'R', 3, 5},
    { "Dragon", 'D', 15, 20},
    { "Vampire", 'V', 10, 15}
};

#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4

/* One kind of attack done by monster.
 * The attack function pointer can refer to this.
 *
 * Parameters:
 * game: the game state
 * monst: The monster performing attack
 */
void attackPunch(Game* game, Creature* monst) {
    printf("%s punches you! ", monst->name);
    int hitprob = 50;
    int maxdam = 4;
    if (rand() % 100 < hitprob) {
        printf("Hit! ");
        int dam = rand() % maxdam + 1;
        printf("Damage: %d ", dam);
        game->hp = game->hp - dam;
        if (game->hp <= 0)
            printf("You died!");
        printf("\n");
    } else {
        printf("Miss!\n");
    }
}

int distance(Game* game, Creature* monst) {
    return abs(game->position.x - monst->pos.x) + abs(game->position.y - monst->pos.y);
}

/*
 * Move monster 'monst' towards the player character.
 * See exercise description for more detailed rules.
 */
void moveTowards(Game* game, Creature* monst) {

    printf("towards the player. Be careful!!!\n");
    int current_dis = distance(game, monst);
    int newx = monst->pos.x;
    int newy = monst->pos.y;

    // Check if the monster move closer to the player and the new position is approachable.
    while (((abs(newx - game->position.x) + abs(newy - game->position.y)) > current_dis) ||
            (newx == game->position.x && newy == game->position.y)) {
        newx = monst->pos.x;
        newy = monst->pos.y;

        unsigned int dir = rand() % 4;  // Randomly choose a moving direction from the possible directions.

        switch (dir){
            case 0:
                newy--;
                break;
            case 1:
                newy++;
                break;
            case 2:
                newx--;
                break;
            case 3:
                newx++;
                break;
            default:
                break;
        }
    }
    if (!isBlocked(game, newx, newy)) {
        monst->pos.x = newx;
        monst->pos.y = newy;
    }
}


/*
 * Move monster 'monst' away from the player character.
 * See exercise description for more detailed rules.
 */
void moveAway(Game* game, Creature* monst) {


    // printf("away from the player. Yeah!!!\n");
    int current_dis = distance(game, monst);
    int newx = monst->pos.x;
    int newy = monst->pos.y;

    while ((abs(newx - game->position.x) + abs(newy - game->position.y) < current_dis) || (newx == game->position.x &&
            newy == game->position.y) || isBlocked(game, newx, newy)) {
        newx = monst->pos.x;
        newy = monst->pos.y;
        unsigned int dir = rand() % 4;  // Randomly choose a moving direction from the possible directions.
        switch (dir){
            case 0:
                newy--;
                break;
            case 1:
                newy++;
                break;
            case 2:
                newx--;
                break;
            case 3:
                newx++;
                break;
            default:
                break;
        }
    }
    monst->pos.x = newx;
    monst->pos.y = newy;
}

/*
 * Check if the monster is in adjacent location with the character.
 */
int isAdjacent(Game* game, Creature* monst) {
    // printf("Character is at [%d %d], monster %s is at [%d %d].\n", game->position.x, game->position.y, monst->name, monst->pos.x, monst->pos.y);
    // printf("%d %d", abs(monst->pos.x - game->position.x), abs(monst->pos.y - game->position.y));
    if ((abs(monst->pos.x - game->position.x) == 1 && abs(monst->pos.y - game->position.y) == 0) ||
        (abs(monst->pos.x - game->position.x) == 0 && abs(monst->pos.y - game->position.y) == 1)) {
        printf("Player is next to monster %s... Attach prepare...", monst->name);
        return 1;
    }
    return 0;
}

/*
 * Take action on each monster (that is alive) in 'monsters' array.
 * Each monster either attacks or moves (or does nothing if no action is specified)
 */
void monsterAction(Game* game) {

    for (unsigned int i = 0; i < game->numMonsters; i++) {
        Creature* m = &game->monsters[i];
        if (isAdjacent(game, m)) {
            m->move = NULL;
            m->attack = attackPunch;
            m->attack(game, m);
        }
        else {
            printf("%s is moving ", m->name);
            m->attack = NULL;
            m->move(game, m);
        }
    }
}

/* Print all of the information belong to each monster.
 * Used for testing the program.
 */
void printMonster(Game* game) {
    Creature* monsters = game->monsters;

    printf("Creating monsters...\n");

    for (unsigned int i = 0; i < game->numMonsters; i++) {
        printf("Monster %s, ", monsters[i].name);
        printf("has sign %c, ", monsters[i].sign);
        printf("is currently at [%d %d], ", monsters[i].pos.x, monsters[i].pos.y);
        printf("has hitpoints %.2f, ", monsters[i].hp);
        printf("has maximum hitpoints %d.\n", monsters[i].maxhp);
    }
    printf("%d monsters were created.\n", game->numMonsters);
}

/*
 * Create opts.numMonsters monsters and position them on valid position
 * in the the game map. The moster data (hitpoints, name, map sign) should be
 * set appropriately (see exercise instructions)
 */
void createMonsters(Game* game) {
    if (!game->numMonsters) {
        game->numMonsters = game->opts.numMonsters;
    }

    game->monsters = malloc(sizeof(Creature) * game->numMonsters);

    unsigned int numType = sizeof(types) / sizeof(MonstType);
    int list[4] = {0};                // Keep the enumerating order of each type of monster.

    for (unsigned int i = 0; i < game->opts.numMonsters; i++) {
        Creature* m = &game->monsters[i];
        unsigned int r = rand() % numType;
        list[r]++;
        char name[100];
        sprintf(name, "%s%s%d", types[r].name, "_", list[r]); // Create the name of the monster from the type name and a number
        strcpy(m->name, name);
        m->sign = types[r].sign;
        int x = rand() % game->opts.mapWidth;;
        int y = rand() % game->opts.mapHeight;
        while (isBlocked(game, x, y) || (x== game->position.x && y == game->position.y)) { // Check if the position is occupied
            x = rand() % game->opts.mapWidth;    // Randomize the position
            y = rand() % game->opts.mapHeight;
        }
        m->pos.x = x;
        m->pos.y = y;
        m->hp = (float) types[r].hphigh;
        m->maxhp = (float) types[r].hphigh;
        m->move = moveTowards;
        m->attack = NULL;
    }
    // printMonster(game);
}

/* Determine whether monster moves towards or away from player character.
 */
void checkIntent(Game* game)
{
    for (unsigned int i = 0; i < game->numMonsters; i++) {
        Creature* m = &game->monsters[i];
        if (m->hp <= 2) {
            m->move = moveAway;
        } else {
            m->move = moveTowards;
        }
        if (m->hp < m->maxhp)
            m->hp = m->hp + 0.1;  // heals a bit every turn
    }
}
