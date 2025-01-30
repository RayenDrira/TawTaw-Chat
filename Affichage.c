#include <stdio.h>
#include "Affichage.h"

void MENU_PRINCIPAL(){
    printf(ANSI_COLOR_BLACK "\n\nAPPLICATION MENU\n");
    printf("________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("What would you like to do?\n"
    "\t1: Modify your account\n"
    "\t2: Delete your account\n"
    "\t3: Send a message\n"
    "\t4: Check your Messages\n"
    "\t5: Delete message(s)\n"
    "\t0: Logout\n");
    printf(" --> ");
} 
void MENU_BIENVENUE(){
    printf(ANSI_COLOR_BLACK "MENU\n");
    printf(ANSI_COLOR_BLACK "________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("What would you like to do?\n"
    "\t1: Log in\n"
    "\t2: Create an account\n"
    "\t3: Learn more about the Application\n"
    "\t0: Quit the application\n");
    printf(" --> ");
}
void MENU_SORTIR(){
    printf(ANSI_COLOR_BLACK "MENU EXIT\n");
    printf(ANSI_COLOR_BLACK "________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("Do you want to exit?\n"
    "\t1: No\n"
    "\t2: Yes\n");
    printf(" --> ");
} 
void MENU_MODIFICATION(){
    printf(ANSI_COLOR_BLACK "ACCOUNT MODIFICATION MENU\n");
    printf(ANSI_COLOR_BLACK "________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("What would you like to do?\n"
    "\t1: Modify the login\n"
    "\t2: Modify the password\n"
    "\t3: Modify both\n"
    "\t0: Quit\n");
    printf(" --> ");
} 
void MENU_VIEW_BOX(){
    printf(ANSI_COLOR_BLACK "MESSAGE VIEW FILTER MENU\n");
    printf(ANSI_COLOR_BLACK "________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("What would you like to do?\n"
    "\t1: View all my messages\n"
    "\t2: View only messages on a single subject\n"
    "\t3: View only messages with a single user\n"
    "\t4: View my INBOX\n"
    "\t5: View my OUTBOX\n"
    "\t6: View by day\n"
    "\t0: Quit\n");
    printf(" --> ");
}
void MENU_SUPPRESSION_MESSAGE(){
    printf(ANSI_COLOR_BLACK "MESSAGE DELETE FILTER MENU\n");
    printf(ANSI_COLOR_BLACK "________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
    printf("What would you like to do?\n"
    "\t1: Delete all my messages\n"
    "\t2: Delete only messages on a single subject\n"
    "\t3: Delete only messages with a single user\n"
    "\t4: Delete only a single message\n"
    "\t5: Delete my INBOX\n"
    "\t6: Delete my OUTBOX\n"
    "\t7: Delete by day\n"
    "\t0: Quit\n");
    printf(" --> ");

}
void PAGE_CONNEXION(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tCONNECTION");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_NOUVEAU_COMPTE(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tNEW ACCOUNT\n");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void SOUS_PAGE_LOGIN(){
    printf(ANSI_COLOR_BLUE  "\tLOGIN");
    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void SOUS_PAGE_MOT_DE_PASSE(){
    printf(ANSI_COLOR_BLUE  "\tPASSWORD");
    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_MODIFICATION(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tACCOUNT MODIFICATION");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_SUPPRESSION(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tACCOUNT DELETION");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_ENVOYER_MESSAGE(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tSEND MESSAGE");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_VIEW_BOX(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tVIEW MESSAGES");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void PAGE_SUPPRESSION_MESSAGE(){
    printf(ANSI_COLOR_BLACK "\n\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\tMESSAGE(S) DELETION");
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void END_PAGE(){
    printf(ANSI_COLOR_BLACK "\n________________________________________________________________________________________________\n\n");
    printf(ANSI_COLOR_RESET);
}
void BANNER() {

    printf(ANSI_COLOR_BLACK " ______________________________________________________________________________________________ \n");
    printf(ANSI_COLOR_BLACK "|                                                                                              |\n|");
    printf(ANSI_COLOR_RED   " TTTTTTTT      AA       W        WWW        W  TTTTTTTT      AA       W        WWW        W   ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "    TT        A  A       W       W W       W      TT        A  A       W       W W       W    ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "    TT       A    A       W     W   W     W       TT       A    A       W     W   W     W     ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "    TT      AAAAAAAA       W   W     W   W        TT      AAAAAAAA       W   W     W   W      ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "    TT     AA      AA       W W       W W         TT     AA      AA       W W       W W       ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "    TT    AA        AA       W         W          TT    AA        AA       W         W        ");
    printf(ANSI_COLOR_BLACK "|\n");
    printf(ANSI_COLOR_BLACK "|______________________________________________________________________________________________|\n");
    printf(ANSI_COLOR_RESET);
    printf("\n"); 

    printf(ANSI_COLOR_BLUE   "              W      WWW      W  EEEEE  Ll      CCCC   OOOO    M     M   EEEEE              \n");
    printf(ANSI_COLOR_BLUE   "               W     W W     W   E      Ll     C      O    O   MM   MM   E                  \n");
    printf(ANSI_COLOR_BLUE   "                W   W   W   W    EEEE   Ll    C      O      O  M M M M   EEEE               \n");
    printf(ANSI_COLOR_BLUE   "                 W W     W W     E      Ll     C      O    O   M  M  M   E                  \n");
    printf(ANSI_COLOR_BLUE   "                  W       W      EEEEE  LLLLL   CCCC   OOOO    M     M   EEEEE              \n");
    printf(ANSI_COLOR_BLUE   "     \n");
    printf(ANSI_COLOR_RESET);

}
void BANNER_BYE(){
    printf("\n");
    printf(ANSI_COLOR_BLACK " ______________________________________________________________________________________________ \n");
    printf(ANSI_COLOR_BLACK "|                                                                                              |\n|");
    printf(ANSI_COLOR_RED   "                        BBBB   YY    YY  EEEEE  BBBB   YY    YY  EEEEE                        ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "                        B   B   Y    Y   E      B   B   Y    Y   E                            ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "                        BBBB     YYYY    EEEE   BBBB     YYYY    EEEE                         ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "                        B   B     YY     E      B   B     YY     E                            ");
    printf(ANSI_COLOR_BLACK "|\n|");
    printf(ANSI_COLOR_RED   "                        BBBB      YY     EEEEE  BBBB      YY     EEEEE                        ");
    printf(ANSI_COLOR_BLACK "|\n");
    printf(ANSI_COLOR_BLACK "|______________________________________________________________________________________________|\n");
    printf(ANSI_COLOR_RED   "     \n");
    printf(ANSI_COLOR_RESET);
}
void CREDITS(int nombre){
    printf("\n");
    printf(ANSI_COLOR_BLACK  " ______________________________________________________________________________________________ \n");
    printf(ANSI_COLOR_BLACK  "|");
    printf(ANSI_COLOR_YELLOW "A.Y :  2023-2024                                                                    ISITcom   ");
    printf(ANSI_COLOR_BLACK  "|\n");
    printf(ANSI_COLOR_BLACK  "|                                                                                              |\n");
    printf(ANSI_COLOR_BLACK  "|");
    printf(ANSI_COLOR_RED    "                                  PROJECT ATELIER PROGRAMMATION                               ");
    printf(ANSI_COLOR_BLACK  "|\n");
    printf(ANSI_COLOR_BLACK  "|                                                                                              |\n");
    printf(ANSI_COLOR_BLACK  "|                                                                                              |\n");
    printf(ANSI_COLOR_BLACK  "|                                                                                              |\n");
    printf(ANSI_COLOR_BLACK  "|______________________________________________________________________________________________|\n");
    printf(ANSI_COLOR_RED    "     \n");
    printf(ANSI_COLOR_BLACK  " ______________________________________________________________________________________________ \n");
    printf(ANSI_COLOR_BLACK  "|                                                                                              |\n|");
    printf(ANSI_COLOR_RED    "                                 Messaging Application  \"TAWTAW\"                              ");
    printf(ANSI_COLOR_BLACK  "|\n|                                                                                              |\n|");
    printf(ANSI_COLOR_BLACK  "                                                                                              |\n|");
    printf(ANSI_COLOR_YELLOW "Designed and Coded by:  Rayen DRIRA                                                           ");
    printf(ANSI_COLOR_BLACK  "|\n|");
    printf(ANSI_COLOR_YELLOW "Class: 1-IoT-1                                                                                ");
    printf(ANSI_COLOR_BLACK  "|\n|");
    printf(ANSI_COLOR_YELLOW "First launched on 28/04/2024                                                                  ");
    printf(ANSI_COLOR_BLACK  "|\n|");
    printf(ANSI_COLOR_YELLOW "Last updated on 03/05/2024                                                                    ");
    printf(ANSI_COLOR_BLACK  "|\n|");
    printf(ANSI_COLOR_YELLOW "Number of Accounts: %d                                                                         ",nombre);
    printf(ANSI_COLOR_BLACK  "|\n|                                                                                              |\n");
    printf(ANSI_COLOR_BLACK  "|______________________________________________________________________________________________|\n");
}