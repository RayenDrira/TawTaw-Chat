#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_BLACK   "\x1b[90m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\033[1;33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//banners
void BANNER();
void BANNER_BYE();

//Plus sur l'application
void CREDITS(int nombre);

//Menus
void MENU_BIENVENUE();
void MENU_SORTIR();
void MENU_PRINCIPAL();
void MENU_MODIFICATION();
void MENU_VIEW_BOX();
void MENU_SUPPRESSION_MESSAGE();

//Pages headers
void PAGE_CONNEXION();
void PAGE_NOUVEAU_COMPTE();
    void SOUS_PAGE_LOGIN();
    void SOUS_PAGE_MOT_DE_PASSE();
void PAGE_SUPPRESSION();
void PAGE_MODIFICATION();
void PAGE_ENVOYER_MESSAGE();
void PAGE_VIEW_BOX();
void PAGE_SUPPRESSION_MESSAGE();
void END_PAGE();
