#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "account.h"
#include "Level2.h"
#include "Affichage.h"



//Account Inputs
char *create_Filename(char chaine[],char base[]){
    strcpy(chaine,base);
    strcat(chaine,".txt");
    return chaine;
}
void saisir_account(int b,compte *Account)
{   
    if(b!=2){
    printf("Enter your login: ");
    fgets(Account->login,MAX_LENGTH_ACC,stdin);
    strtok(Account->login,"\n");
    } 
    if(b!=1){
    printf("Enter your password: ");
    fgets(Account->mot_de_passe,MAX_LENGTH_ACC,stdin);
    strtok(Account->mot_de_passe,"\n");
    }
}

//Hash
unsigned long hash(compte* Tawtaw) {
    unsigned long hash = 5381;
    int c;
    char *mot_de_passe = Tawtaw->mot_de_passe;
    while ((c =*mot_de_passe++)) {
        hash = ((hash << 5) + hash) + c; // Hash * 33 + c
    }
    return hash;
}
//Control Input
int existe_login(char login[])
{
    FILE *fichier;
    char ligne[MAX_LENGTH_ACC];
    char username[MAX_LENGTH_ACC];

    fichier = fopen("Account.txt", "r");
    if (fichier == NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }

        while (fgets(ligne, MAX_LENGTH_ACC, fichier) != NULL) {
            int i = 0;
            // Extract username
            while (ligne[i] != ':' && ligne[i] != '\n') {
                username[i] = ligne[i];
                i++;
            }
            username[i] = '\0';// Null-terminate username

            // Vérifier si le login est unique
            if (strcmp(login, username) == 0) {
                fclose(fichier);
                return 1; // Login existant
            }
        }
    fclose(fichier);
    return 0; // Unique login 
}
int secure_login(char login[])
{
    if (strlen(login) < 4) {
        return 1; // False login
    }

    // Check if login contains spaces
    if (strchr(login, ' ') != NULL) {
        return 3; // False login
    }

    // Check if login contains special characters including ':'
    for (int i = 0; login[i] != '\0'; i++) {
        if (!isalnum(login[i]) || login[i] == ':') {
            return 2; // False login
        }
    }

    // If all conditions are met, return true for a valid login
    return 0;
}
int secure_mot_de_passe(char mot_de_passe[])
{
    int i,u=0,l=0,s=0,n=0;
    int len=strlen(mot_de_passe);
    if(len<8){
        return 6;
    }
    for(i=0;i<len;i++){
        if(mot_de_passe[i]==' ')
            return 1;
        if(!isalnum(mot_de_passe[i])){
            s++;
        }
        if(isupper(mot_de_passe[i])){
            u++;
        }
        if(islower(mot_de_passe[i])){
            l++;
        }
        if(isdigit(mot_de_passe[i])){
            n++;
        }
    }
    if (s == 0) 
        return 2; // Password does not contain special characters
    if (u == 0)
        return 3; // Password does not contain uppercase letters
    if (l == 0) 
        return 4; // Password does not contain lowercase letters
    if (n == 0)
        return 5; // Password does not contain numbers
    return 0;//Password secure
}
int secure_CONTENT(char content[])
{
    int i,special_operator=0;
    for(i=0;i<strlen(content);i++){
        if(content[i]==':')
            special_operator++;
    }
    if(special_operator==0){
        return 1;//Content secure
    }else { 
        return 0;//Content not secure
    } 
}

//Verifiying the user
int verify_password(compte *Account){
    compte *new_Account;
    for(int i=1;i<4;i++){
        saisir_account(2,new_Account);
        if(strcmp(new_Account->mot_de_passe,Account->mot_de_passe)!=0){
            printf(ANSI_COLOR_RED " !! The password is incorrect !!\n");
            printf(ANSI_COLOR_BLACK" *You have %d attempts left before being automatically disconnected.* \n",3-i);
            printf(ANSI_COLOR_RESET);
        }else{
            printf("\n");
            return 1;
        }
    }
    return 0;
}

