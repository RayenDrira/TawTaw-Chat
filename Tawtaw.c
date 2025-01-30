#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "account.h"
#include "level2.h"
#include "Affichage.h"
#include "Message.h"

int main()
{
    int rep,rep1,rep2,rep3,option;
    compte Account,new_Account;
    int connecté;
    FILE *fichier;
    fichier=fopen("Account.txt","r");
    if (fichier==NULL){
        fichier=fopen("Account.txt","w");
    }
    fclose(fichier);
    do{
        do{
            //Welcome Menue
            BANNER();
            MENU_BIENVENUE();
            scanf("%d",&rep1);
            fgetc(stdin);
            END_PAGE();
            switch(rep1)
            {
            case 0: 
                BANNER_BYE();
                return 0;
            case 1: 
                do{
                    //page name
                    PAGE_CONNEXION();
                    //verifying if the account exists
                    if (connecté=Connection(&Account)) {
                        printf(ANSI_COLOR_YELLOW "< Identification successful. You are connected to your TAWTAW account >\n\n");
                        printf(ANSI_COLOR_RESET);
                    } else {
                        printf(ANSI_COLOR_RED "!! Login or password incorrect !!\n\n");
                        printf(ANSI_COLOR_RESET);
                        END_PAGE();
                        do{
                        MENU_SORTIR();
                        scanf("%d",&rep1);
                        }while(rep1<=0 || rep1>2);
                        fgetc(stdin);
                    }
                    END_PAGE();
                }while(connecté==0 && rep1==1);
                create_Filename(Account.Filename,Account.login);
                break;
            case 2 :
                //page name
                PAGE_NOUVEAU_COMPTE();
                create_account(&Account);

                gestion_fichier(Account);
                printf(ANSI_COLOR_YELLOW "\n< Your account has been successfully created on the 'TAWTAW' application >\n");
                printf(ANSI_COLOR_RESET);
                END_PAGE();
                break;
                case 3:
                    int nombre=count_message("Account.txt");
                    CREDITS(nombre-1);
                    break;
            default : {
                printf(ANSI_COLOR_RED " !! Valeur incorrecte !!\n");
                printf(ANSI_COLOR_RESET);
            }
            }
        }while(rep1!=1 && rep1!=0);

        do{
            //Menue officiel de l'Application
            MENU_PRINCIPAL();
            scanf("%d",&rep);
            fgetc(stdin);
            END_PAGE();
            switch(rep)
            {
            case 0 :
                break;
            case 1:
                rep=verify_password(&Account);
                printf(ANSI_COLOR_YELLOW " < Your account has been verified >\n\n");
                printf(ANSI_COLOR_RESET);
                if(rep==1){
                    do{
                    MENU_MODIFICATION();
                    scanf("%d",&option);
                    if(option>3 || option<0){
                        printf(ANSI_COLOR_RED " !! Incorrect value !!");
                        printf(ANSI_COLOR_RESET);
                    }
                    END_PAGE();
                    }while(option>3 || option<0);
                    fgetc(stdin);
                    modification(option,&Account);
                }
                break;
            case 2:
                //Page name
                PAGE_SUPPRESSION();
                rep=verify_password(&Account);
                //verification si le compte existe
                if(rep==1){
                    //suppression du compte 
                    if (Supprimer_compte(Account)==1) {
                        printf(ANSI_COLOR_YELLOW "< The account has been deleted. You are logged out of your TAWTAW account >\n");
                        printf(ANSI_COLOR_RESET);
                        rep=0;
                    } else {
                        printf(ANSI_COLOR_RED " !! Error during deletion !!\n");
                        printf(ANSI_COLOR_RESET);
                    }
                    END_PAGE();
                }
                break;
            case 3 :
                PAGE_ENVOYER_MESSAGE();
                sendMessage(Account.login,Account.Filename);
                printf(ANSI_COLOR_YELLOW " < Your Message has been sent successfully >\n");
                printf(ANSI_COLOR_RESET);
                END_PAGE();
            break;
            case 4 : 
                do{
                    MENU_VIEW_BOX();
                    scanf("%d",&rep2);
                    if(rep2>6 || rep2<0){
                        printf(ANSI_COLOR_RED "!! Incorrect value !!");
                        printf(ANSI_COLOR_RESET);
                }
                }while(rep2<0 ||rep2>6);
                fgetc(stdin);
                if(rep2!=0){
                    PAGE_VIEW_BOX();
                    viewbox(rep2,Account.Filename,Account.login);
                }
                END_PAGE();
            break;
            case 5:
                do{
                    MENU_SUPPRESSION_MESSAGE();
                    scanf("%d",&rep3);
                    if(rep3>7 || rep3<0){
                        printf(ANSI_COLOR_RED " !! Incorrect value !!");
                        printf(ANSI_COLOR_RESET);
                    }
                }while(rep3>7 || rep3<0);
                if(rep3!=0){
                    PAGE_SUPPRESSION_MESSAGE();
                    deleteMessage(Account,rep3);
                }
            break;
            default : 
                printf(ANSI_COLOR_RED " !! Incorrect value !!\n");
                printf(ANSI_COLOR_RESET);
                END_PAGE();
            }
        }while (rep!=0);
    }while(rep1!=0);
}