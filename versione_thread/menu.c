#include "menu.h"

// Definizione delle costanti per la dimensione della finestra di gioco
static int startx; 
static int starty;

int width = 130;  // Riduci un po' la larghezza della finestra
int height = 35;  // Riduci un po' l'altezza della finestra


// Funzione per animare la schermata di benvenuto
void animate_welcome() {
    curs_set(0);
    nodelay(stdscr, TRUE);
    setlocale(LC_ALL, "");
    
    if (!has_colors()) {
        endwin();
        fprintf(stderr, "Your terminal does not support colors.\n");
        exit(1);
    }
    
    const wchar_t *sprite[MAX_HEIGHT_WELCOME] = {

    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░      ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓██████████████▓▒░░▒▓████████▓▒░      ░▒▓████████▓▒░▒▓██████▓▒░        ",
    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░       ",
    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░       ",
    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░ ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░           ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░       ",
    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░       ",
    L"      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░                ░▒▓█▓▒░  ░▒▓█▓▒░░▒▓█▓▒░       ",
    L"       ░▒▓█████████████▓▒░░▒▓████████▓▒░▒▓████████▓▒░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░         ░▒▓█▓▒░   ░▒▓██████▓▒░        ",
    L"                                                                                                                                                      ",
    L"                                                                                                                                                      ",
    L"                             ░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓████████▓▒░▒▓███████▓▒░                              ",
    L"                             ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░                             ",
    L"                             ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░                             ",
    L"                             ░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░▒▓█▓▒▒▓███▓▒░▒▓██████▓▒░ ░▒▓███████▓▒░                              ",
    L"                             ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░                             ",
    L"                             ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░                             ",
    L"                             ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░                             ",
    L"                                                                                                                                                      ",
    L"                                                                                                                                                      ",
    L" ░▒▓███████▓▒░░▒▓████████▓▒░░▒▓███████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░▒▓██████▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓██████▓▒░░▒▓███████▓▒░  ",
    L" ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ",
    L" ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ",
    L" ░▒▓███████▓▒░░▒▓██████▓▒░  ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░░▒▓███████▓▒░░▒▓██████▓▒░░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ",
    L" ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        ░▒▓█▓▒░   ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ",
    L" ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ",
    L" ░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓██████▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░ ",                                                                                                                                                               
    };
    
    int starty = 15;
    int startx = (COLS/2) - 75;

    for (int i = 0; i < MAX_HEIGHT_WELCOME; i++) {
        mvaddwstr(starty + i, startx, sprite[i]);
        refresh();
        usleep(135000);

        // Se viene premuto un tasto, interrompi l'animazione
        if (getch() != ERR) {
            break;
        }
    }
    
    clear();
    refresh();
    
    curs_set(0);
    setlocale(LC_ALL, "C.UTF-8");
}

// Funzione per stampare il menu
void print_menu(WINDOW *menu_win, int highlight, MenuOption menu[], int n_choices) {
    int x = 1, y = 1;
    
    for (int i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            for (int j = 0; j < 5; ++j) {
                mvwprintw(menu_win, y + j, x, "%ls", menu[i].text[j]);
            }
            wattroff(menu_win, A_REVERSE);
        } else {
            for (int j = 0; j < 5; ++j) {
                mvwprintw(menu_win, y + j, x, "%ls", menu[i].text[j]);
            }
        }
        y += 7;
    }
    wrefresh(menu_win);
}


// Funzione per mostrare e gestire il menu principale
int mainMenu(Game *game) {
    init_window_position();
    WINDOW *menu_win = newwin(GAME_HEIGHT, GAME_WIDTH, starty, startx); 
    int highlight = 1;
    int choice = 0;
    int c;

    nodelay(menu_win, TRUE); 
    keypad(menu_win, TRUE);
    mvprintw(LINES - 2, 0, "Usa le frecce per muoverti; Invio per selezionare");
    refresh();

    int n_choices = sizeof(menu) / sizeof(MenuOption);
    print_menu(menu_win, highlight, menu, n_choices);

    while ((c = wgetch(menu_win)) != 0) {
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;

            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;

            case '\n':  
                choice = highlight;
                delwin(menu_win);
                return choice;
            
            default:
                break;
        }

        print_menu(menu_win, highlight, menu, n_choices);
    }
    delwin(menu_win);
    return 0; 
}

// Funzione per mostrare e gestire il menu di selezione del livello
int levelMenu(Game *game){

    init_window_position();
    int highlight = 1;
    int choice = 0;
    int c;
    WINDOW *level_win = newwin(GAME_HEIGHT, GAME_WIDTH, starty, startx);
    keypad(level_win, TRUE);
    mvprintw(LINES - 2, 0, "Usa le frecce per muoverti; Invio per selezionare");
    refresh();
    
    
    int n_choices = sizeof(level) / sizeof(MenuOption);
    
    print_menu(level_win, highlight, level , n_choices);
    while((c = wgetch(level_win)) != 0){
        switch(c) {
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
                    highlight = 1;
                else 
                    ++highlight;
                break;
            case 10: // Tasto Invio
                choice = highlight;
                if(choice == 1){
                    wclear(level_win);
                    wrefresh(level_win);
                    delwin(level_win);
                    game->difficulty = 0; 
                    return choice; 
                }
                else if(choice == 2){
                    wclear(level_win);
                    wrefresh(level_win);
                    delwin(level_win);
                    game->difficulty = 1; 
                    return choice; 
                }
                else if(choice == 3){
                    wclear(level_win);
                    wrefresh(level_win);
                    delwin(level_win);
                    game->difficulty = 2; 
                    return choice; 
                }
                
                break;
            default:
                break;
        }
        print_menu(level_win, highlight, level, n_choices);
    }
    delwin(level_win);
    return 0; 
}

// Funzione per inizializzare la posizione della finestra
void init_window_position() {
    startx = (COLS - width) / 2;
    starty = (LINES - height) / 2;
}

// Funzione per mostrare il menu di punteggi
void displayScoreMenu(Game *game) {

    init_window_position();
    pthread_mutex_lock(&ncurses_mutex);
    WINDOW *score_win = newwin(height + 10, width, (LINES - height) / 2, (COLS - width) / 2);
    keypad(score_win, TRUE);
    
    // Carica i punteggi dal file
    FILE* file = fopen(SCORES_FILE, "rb");
    
    box(score_win, 0, 0);
    wattron(score_win, A_BOLD);
    mvwprintw(score_win, 2, (height + 70) / 2, "🏆 HIGH SCORES TABLE 🏆");
    
    if (file == NULL) {
        mvwprintw(score_win, height/2, (width - 20) / 2, "No scores yet!");
    } else {
        ScoreEntry entry;
        int y = 5;
        int count = 1;
        
        // Intestazioni della tabella
        mvwprintw(score_win, y, 5,  " RANK  ");
        mvwprintw(score_win, y, 20, " SCORE ");
        mvwprintw(score_win, y, 40, "    DATE    ");
        mvwprintw(score_win, y, 65, " DIFFICULTY ");
        y += 2;
        
        // Linea separatrice
        for (int x = 5; x < GAME_WIDTH - 45; x++) {
            mvwprintw(score_win, y - 1, x, "="); 
        }
        
        while (fread(&entry, sizeof(ScoreEntry), 1, file) == 1 && count <= MAX_SCORES) {
            const char* difficulty;
            switch(entry.difficulty) {
                case 0: difficulty = "Easy"; break;
                case 1: difficulty = "Medium"; break;
                case 2: difficulty = "Hard"; break;
                default: difficulty = "Unknown"; break;
            }
            
            mvwprintw(score_win, y, 10, "%d.", count);
            mvwprintw(score_win, y, 25, "%d", entry.score);
            mvwprintw(score_win, y, 45, "%s", entry.date);
            mvwprintw(score_win, y, 70, "%s", difficulty);
            y++;
            count++;
        }
        fclose(file);
    }
    
    // Istruzioni in fondo alla finestra
    mvwprintw(score_win, height-3, (width - 35) / 2, "Press any key to return to main menu");
    wattroff(score_win, A_BOLD);
    
    wrefresh(score_win);
    
    // Aspetta l'input dall'utente
    wgetch(score_win);
    
    // Pulisci e ritorna al menu principale
    wclear(score_win);
    wrefresh(score_win);
    delwin(score_win);
    pthread_mutex_unlock(&ncurses_mutex);
    mainMenu(game);
}

