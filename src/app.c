#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define SDL_WINDOW_WIDTH 900
#define SDL_WINDOW_HEIGHT 900
#define DEFAULT_STEP_RATE_IN_MILLISECONDS 500

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    Uint64 last_step;
    int running;
    int MillisPerStep;
    Board* game_board;
} AppState;

static void set_rect_xy_(SDL_FRect *r, short x, short y, short cellSize)
{
    r->x = (float)(x * cellSize);
    r->y = (float)(y * cellSize);
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    AppState *as = (AppState *)appstate;
    const Uint64 now = SDL_GetTicks();
    SDL_FRect r;

    while ((now - as->last_step) >= as->MillisPerStep) {
        as->last_step += as->MillisPerStep;
        if(as->running) {
            printf("%d\n", (*as->game_board->state)[7]);
        };
        printf("running\n");
    }

    int gridSize = as->game_board->gridSize;
    //printf("%d\n", gridSize);
    int cellSize = 900/gridSize;
    r.w = r.h = cellSize;
    SDL_SetRenderDrawColor(as->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(as->renderer);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            set_rect_xy_(&r, j, i, cellSize);
            SDL_SetRenderDrawColor(as->renderer, 20 * i, 20 * j, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(as->renderer, &r);
        }
    }
    SDL_RenderPresent(as->renderer);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    size_t i;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return SDL_APP_FAILURE;
    }

    AppState *as = SDL_calloc(1, sizeof(AppState));
    if (!as) {
        return SDL_APP_FAILURE;
    }

    Board* firstboard = calloc(1, sizeof(Board));
    firstboard->gridSize = 9;
    _Init_Board(&firstboard);
    as->game_board = firstboard;
    printf("this : %d\n", (*as->game_board->state)[7]);
    as->MillisPerStep = DEFAULT_STEP_RATE_IN_MILLISECONDS;
    as->running = 1;
    *appstate = as;
    printf("here : %d\n", (((AppState *) *appstate)->game_board->state[0]));
    firstboard = 0;

    if (!SDL_CreateWindowAndRenderer("first test", SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, 0, &as->window, &as->renderer)) {
        return SDL_APP_FAILURE;
    }

    as->last_step = SDL_GetTicks();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    default:
        break;
    }
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (appstate != NULL) {
        AppState *as = (AppState *)appstate;
        SDL_DestroyRenderer(as->renderer);
        SDL_DestroyWindow(as->window);
        SDL_free(as);
    }
}