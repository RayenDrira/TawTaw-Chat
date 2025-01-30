#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "account.h"
#include "Level2.h"
#include "Message.h"
#include "Affichage.h"

//Connetion
int Connection(compte *Account) 
{
    FILE *fichier;
    char ligne[MAX_LENGTH_ACC];
    char username[MAX_LENGTH_ACC];
    char password[MAX_LENGTH_ACC];

    saisir_account(3,Account);
    fichier = fopen("Account.txt", "r");
    if (fichier == NULL) {
        printf("!! Error occurred while opening the file !!");
        exit(EXIT_FAILURE);
    }
    while (fgets(ligne, MAX_LENGTH_ACC*2+1, fichier) != NULL) 
    {
        char gcc[MAX_LENGTH_ACC];
        int j=0,i = 0;
        // Extract username
        while (ligne[i] != ':' && ligne[i] != '\n' && ligne[i] != '\0') 
        {
            username[i] = ligne[i];
            i++;
        }
        username[i] = '\0'; // Null-terminate username

            i++;

        // Extract password
        while (ligne[i] != '\n' && ligne[i] != '\0') 
        {
            password[j] = ligne[i];
            i++;
            j++;
        }
        password[j] = '\0'; // Null-terminate password

        //Hash the password to confirm its identity
        unsigned long hashedValue = hash(Account);
        sprintf(gcc, "%lu", hashedValue);
        // Verify the existance of the Accounts
        if (strcmp(Account->login, username) == 0 && strcmp(gcc, password) == 0) {
            fclose(fichier);
            return 1; // Identification succeeded
        }
    }
    fclose(fichier);
    return 0; // Identification failed
}

//Create
void create_account(compte* Account){
    int secure,existe,secure_password;
    //Page name
    SOUS_PAGE_LOGIN();
    printf(ANSI_COLOR_BLACK " *The login must be unique, have at least 4 characters, and not contain any special characters*\n\n");
    printf(ANSI_COLOR_RESET);
    do{
        saisir_account(1,Account);
        secure=secure_login(Account->login);
        if (secure==1){
            printf(ANSI_COLOR_RED " !! The login must have at least 4 characters !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure==2){
            printf(ANSI_COLOR_RED " !! The login must not contain special characters !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure==3){
            printf(ANSI_COLOR_RED " !! The login must not contain spaces !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(existe=existe_login(Account->login)){
            printf(ANSI_COLOR_RED " !! The login must be unique !!\n");
            printf(ANSI_COLOR_RESET);
        }
    }while(secure!=0 || existe);
    END_PAGE();
    //Page name
    SOUS_PAGE_MOT_DE_PASSE();
    printf(ANSI_COLOR_BLACK " *The password must be at least 8 characters long and contain a combination of uppercase and lowercase letters, numbers, and special characters. It must not contain spaces* \n\n");
    printf(ANSI_COLOR_RESET);
    do{ 
        saisir_account(2,Account);
        secure_password=secure_mot_de_passe(Account->mot_de_passe);
        if(secure_password==1){
            printf(ANSI_COLOR_RED " !! The password must not contain spaces !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure_password==2) {
            printf(ANSI_COLOR_RED " !! The password must contain at least one special character !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure_password==3){
            printf(ANSI_COLOR_RED " !! The password must at least contain one uppercase character !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure_password==4){
            printf(ANSI_COLOR_RED " !! The password must at least contain one lowercase character !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure_password==5){
            printf(ANSI_COLOR_RED " !! The password must contain at least one number !!\n");
            printf(ANSI_COLOR_RESET);
        }else if(secure_password==6){
            printf(ANSI_COLOR_RED " !! The password must be at least 8 characters long !!\n");
            printf(ANSI_COLOR_RESET);
        }
    }while(secure_password!=0);
    END_PAGE();    
}
void modify_messages(compte Account,compte new_Account){
    FILE *inBOX,*temp;
    lettre message;
    inBOX=fopen(Account.Filename, "r");
    temp=fopen(new_Account.Filename,"w");
    while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF) 
    {
        if(strcmp(Account.login,message.source)==0){
            strcpy(message.source,new_Account.login);
        }else if(strcmp(Account.login,message.destinataire)==0){
            strcpy(message.destinataire,new_Account.login);
        }
        fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
    }
    fclose(temp);
    fclose(inBOX);
    remove(Account.Filename);

}
//modification
void modification(int option,compte* Account){
    compte new_Account;
    int secure,existe,secure_password;

    if(option!=0){
        //Page name
        PAGE_MODIFICATION();

        if(option==1 || option==3){
            //Page name
            SOUS_PAGE_LOGIN();
            printf(ANSI_COLOR_BLACK " *The new login must be unique, have at least 4 characters, and not contain any special characters* \n\n");
            printf(ANSI_COLOR_RESET);
            do{           
                saisir_account(1,&new_Account);   
                secure=secure_login(new_Account.login);
                if (secure==1){
                    printf(ANSI_COLOR_RED "\n !! The new login must have at least 4 characters  !!\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure==2){
                    printf(ANSI_COLOR_RED "\n !! The new login must not contain special characters !!\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure==3){
                    printf(ANSI_COLOR_RED "\n !! The new login must not contain spaces !!\n");
                    printf(ANSI_COLOR_RESET);
                }else if(existe=existe_login(new_Account.login)){
                    printf(ANSI_COLOR_RED " !! The new login must be unique !!\n");
                    printf(ANSI_COLOR_RESET);
                    
                }         
            }while(secure!=0 || existe);
            create_Filename(new_Account.Filename,new_Account.login);
            modify_messages(*Account,new_Account);
            strcpy(Account->Filename,new_Account.Filename);
            printf(ANSI_COLOR_YELLOW "\n< Your login has been successfully modified >\n");
            printf(ANSI_COLOR_RESET);
        }else{
                        
            //Preserving the unmodified login
            strcpy(new_Account.login,Account->login);
        }
                    
        if(option==2 || option==3)
        {
            //Making sure that the new password is secure and new
            do{
                            
            //Page name
                if(option==3){
                    END_PAGE();
                }
                SOUS_PAGE_MOT_DE_PASSE();
                printf(ANSI_COLOR_BLACK " *The new password must be at least 8 characters long and contain a combination of uppercase and lowercase letters, numbers, and special characters. It must not contain spaces.* \n\n");
                printf(ANSI_COLOR_RESET);
                saisir_account(2,&new_Account);

                secure_password=secure_mot_de_passe(new_Account.mot_de_passe);
                if(secure_password==1){
                    printf(ANSI_COLOR_RED "\n !! The new password must not contain spaces !!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_password==2) {
                    printf(ANSI_COLOR_RED "\n !! The new password must contain at least one special character !!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_password==3){
                    printf(ANSI_COLOR_RED "\n !! The new password must at least contain one uppercase character !!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_password==4){
                    printf(ANSI_COLOR_RED "\n !! The new password must at least contain one lowercase character !!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_password==5){
                    printf(ANSI_COLOR_RED "\n !! The new password must contain at least one number !!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_password==6){
                    printf(ANSI_COLOR_RED "\n !! The new password must be at least 8 characters long!!\n");
                    printf(ANSI_COLOR_BLACK "\n_________________________________________\n\n");
                    printf(ANSI_COLOR_RESET);
                }
            }while(secure_password!=0 || strcmp(new_Account.mot_de_passe,Account->mot_de_passe)==0);
            printf(ANSI_COLOR_YELLOW "\n< Your password has been modified successfully >\n");
            printf(ANSI_COLOR_RESET);
            END_PAGE();
        }else{

            //Preserving the unmodified password
            strcpy(new_Account.mot_de_passe,Account->mot_de_passe);
        }

        //Deleting The account from the users log
        supprimer_account(Account->login);

        //Readding the informations to to log
        add_line(&new_Account);

        //Daking sure that the account information is stored correctly
        strcpy(Account->login,new_Account.login);
        strcpy(Account->mot_de_passe,new_Account.mot_de_passe);
    }
}
void add_line(compte *Tawtaw)
{
    FILE *fichier;
    char Account[MAX_LENGTH_ACC*2+1];

    fichier=fopen("Account.txt","a");
    if (fichier == NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }

    unsigned long hashedValue = hash(Tawtaw);
    char hashedString[MAX_LENGTH_ACC];
    sprintf(hashedString, "%lu", hashedValue);

    strcpy(Account,Tawtaw->login);
    strcat(Account,":");
    strcat(Account,hashedString);
    strcat(Account,"\n");
    fprintf(fichier, "%s", Account);
    fclose(fichier);
}
int gestion_fichier(compte Account)
{
    FILE *nouveau_fichier;
    create_Filename(Account.Filename,Account.login);
    nouveau_fichier=fopen(Account.Filename,"w");//Creating the MessageBOX
    if (nouveau_fichier == NULL) {
        printf("Error occurred while creating the file");
        exit(EXIT_FAILURE);
    }
    fclose(nouveau_fichier);

    add_line(&Account);
    return 1;
}

//delete
int supprimer_account(char login[])
{
    FILE *fichier,*temp;
    char ligne[MAX_LENGTH_ACC];

    fichier=fopen("Account.txt","r");
    if (fichier == NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }

    temp=fopen("temp.txt","w+");
    if (temp== NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }

    while (fgets(ligne, MAX_LENGTH_ACC, fichier) != NULL) 
    {
        if (strstr(ligne, login) == NULL) 
            fputs(ligne, temp);
    }
    fclose(fichier);
    fclose(temp);

    remove("Account.txt");
    rename("temp.txt", "Account.txt");
    return 1;
    
}
int Supprimer_compte(compte Account)
{
    supprimer_account(Account.login);
    if (remove(Account.Filename) != 0) {
        printf("Error occurred while deleting the BOX file.");
        return 0; 
    }
    return 1; 
}