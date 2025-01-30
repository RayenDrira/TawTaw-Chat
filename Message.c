#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "account.h"
#include "Level2.h"
#include "Affichage.h"
#include "Message.h"

int count_message(char Filename[])
{
    FILE *fichier;
    int nmbr=1;
    char ligne[sizeof(lettre)+10];
    fichier=fopen(Filename,"r");
    while (fgets(ligne, sizeof(lettre)+10, fichier) != NULL) 
    {
        nmbr++;
    }
    fclose(fichier);
    return nmbr;
}

void deleteMessage(compte Account,int rep){
    FILE *inBOX,*temp;
    char subject[MAX_LENGTH_SUBJECT],destinataire[MAX_LENGTH_LOGIN];
    lettre message;
    int existe,secure_subject;
    int a=1,n;
    int m,j;


    inBOX=fopen(Account.Filename,"r+");
    if (inBOX == NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }

    temp=fopen("temp.txt","w");
    if (temp== NULL) {
        printf("Error occurred while opening the file");
        exit(EXIT_FAILURE);
    }
    switch (rep)
    {
    case 2:
        
        do{
            printf("Enter the subject: ");
            fgetc(stdin);
            fgets(subject,MAX_LENGTH_SUBJECT,stdin);
            strtok(subject,"\n");
            secure_subject=secure_login(subject);
            if (secure_subject==1){
                printf(ANSI_COLOR_RED " !! The subject must have at least 4 characters. !!\n");
                printf(ANSI_COLOR_RESET);
            }else if(secure_subject==2){
                printf(ANSI_COLOR_RED " !! The subject must not contain special characters !!\n");
                printf(ANSI_COLOR_RESET);
            }else if(secure_subject==3){
                printf(ANSI_COLOR_RED " !! The subject must not contain spaces !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(secure_subject!=0);
        
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF)
        { 
            message.nmbre=a;
            if (strcmp(subject,message.sujet)!=0){
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
        }
        break;
    case 3:
        
        do{
            printf("Enter the username of the other user you want to delete the conversation with: ");
            fgetc(stdin);
            fgets(destinataire,MAX_LENGTH_LOGIN,stdin);
            strtok(destinataire,"\n");
            existe=existe_login(destinataire);
            if(existe==0){
                printf(ANSI_COLOR_RED " !! The other user does not exist !!\n\n");
                printf(ANSI_COLOR_RESET);
                do{
                MENU_SORTIR();
                scanf("%d",&rep);
                }while(rep!=1 && rep!=2);
                fgetc(stdin);
                END_PAGE();
                if(rep==2){
                    rep=100;
                    break;}
            }
            
        }while(existe==0);
        if(rep==100)
            break;
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF)
        {
            message.nmbre=a;
            if (strcmp(destinataire,message.destinataire)!=0 ||strcmp(message.source,destinataire)!=0){ 
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
        }
        break;
    case 4:
        do{
            printf("Enter the number of the message you want to delete: ");
            scanf("%d",&n);
            fgetc(stdin);
            existe=count_message(Account.Filename);
            if(existe<n){
                printf(ANSI_COLOR_RED " !! The message does not exist !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(existe<n);
        
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF)
        {
            message.nmbre=a;
            if (message.nmbre!=n){ 
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
            else{
                n=0;
            }
        }
        break;
    case 5: //INBOX
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF) 
        {
            message.nmbre=a;
            if(strcmp(Account.login,message.destinataire)!=0){
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
            else{
                n=0;
            }
        }
        break;
    case 6://OUTBOX
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF) 
        {
            message.nmbre=a;
            if(strcmp(Account.login,message.source)!=0){
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
            else{
                n=0;
            }
        }
        break;
    case 7://DAY
        int j,m;
        printf("Enter the date (MONTH, DAY) \n");
        do{
            printf("Enter the month: ");
            scanf("%d",&m);
            if(m<1|| m>12){
                printf(ANSI_COLOR_RED " !! The date is incorrect. 1 < month < 12 !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(m<1|| m>12);
        do{
            printf("Enter the day:");
            scanf("%d",&j);
            fgetc(stdin);
            if( ((m==4 || m==6 ||m==9 || m==11)&&(j<1 || j>30) )||((m==2) && (j<1 || j>28)) || j<1 || j>31){
                printf(ANSI_COLOR_RED " !! The date is incorrect. 1 < day < 31 (or 30, or 28 depending on the month) !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while( ((m==4 || m==6 ||m==9 || m==11)&&(j<1 || j>30) )||((m==2) && (j<1 || j>28)) || j<1 || j>31);
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, message.source, message.destinataire, message.sujet, message.content,&message.month,&message.day,&message.hour,&message.min, &message.nmbre) != EOF)  
        {
            message.nmbre=a;
            if(m!=message.month || j!=message.day){
                fprintf(temp, MESSAGE_FORMAT_OUT, message.source, message.destinataire, message.sujet, message.content,message.month,message.day,message.hour,message.min, message.nmbre);
                a=message.nmbre+1;
            }
            else{
                n=0;
            }
        }
        break;
    }
    fclose(temp);
    fclose(inBOX);

    if(rep!=100){
        remove(Account.Filename);
        rename("temp.txt",Account.Filename);
        printf(ANSI_COLOR_YELLOW "< The message(s) has/have been successfully deleted >\n");
        printf(ANSI_COLOR_RESET);
        END_PAGE();
    }
}

void AFFICHE_MESSAGE(int  champ1,int champ6,int champ7,int champ8,int champ9,char champ2[],char champ3[],char champ4[],char champ5[]){
    printf("Message: %ld\n",champ1);
    printf("%s\t", champ2);
    printf("----> %s\n", champ3);
    printf("Subject: %s\n", champ4);
    printf("Content:%s\n", champ5);
    printf(TIME_FORMAT,champ6,champ7,champ8,champ9);
    printf("\n");
}

void viewbox(int rep,char Filename[],char login[]){
    FILE *inBOX;
    lettre inMessage;
    char subject[MAX_LENGTH_SUBJECT];
    int secure_subject,existe;

    inBOX=fopen(Filename, "r");
    inMessage.nmbre=0;

    switch (rep)
    {
    case 2:
        do{
            printf("Enter the subject: ");
            fgets(subject,MAX_LENGTH_SUBJECT,stdin);
            strtok(subject,"\n");
            secure_subject=secure_login(subject);
            if (secure_subject==1){
                printf(ANSI_COLOR_RED "\n !! The subject must have at least 4 characters !!\n");
                printf(ANSI_COLOR_RESET);
            }else if(secure_subject==2){
                printf(ANSI_COLOR_RED "\n !! The subject must not contain special characters !!\n");
                printf(ANSI_COLOR_RESET);
            }else if(secure_subject==3){
                printf(ANSI_COLOR_RED "\n !! The subject must not contain spaces !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(secure_subject!=0);
        printf("\nHere are all the messages on the subject of %s: \n\n",subject);
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            if(strcmp(subject,inMessage.sujet)==0){
                AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
            }
        }
    break;
    case 3:
        do{
            printf("Enter the username of the other user you want to view the conversation with: ");
            fgets(subject,MAX_LENGTH_LOGIN,stdin);
            strtok(subject,"\n");
            existe=existe_login(subject);
            if(existe==0){
                printf(ANSI_COLOR_RED " !! The other user does not exist !!\n");
                printf(ANSI_COLOR_RESET);
                do{
                MENU_SORTIR();
                scanf("%d",&rep);
                }while(rep!=1 && rep!=2);
                fgetc(stdin);
                END_PAGE();
                if(rep==2){
                    break;}
            }
        }while(existe==0);
        if(rep==2)
            break;
        printf("\nHere are all the messages with %s:\n\n",subject);
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            if(strcmp(subject,inMessage.destinataire)==0 || strcmp(subject,inMessage.source)==0){
                AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
            }
        }
    break;
    case 4://INBOX
        printf("\nHere are all the messages from your INBOX:\n\n");
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            if(strcmp(login,inMessage.destinataire)==0){
                AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
            }
        }
    break;
    case 5://OUTBOX
        printf("\nHere are all the messages from your OUTBOX:\n\n");
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            if(strcmp(login,inMessage.source)==0){
                AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
            }
        }
    break;
    case 6://Per Day
        int j,m;
        printf("Enter the date (MONTH, DAY) \n");
        do{
            printf("Enter the month: ");
            scanf("%d",&m);
            if(m<1|| m>12){
                printf(ANSI_COLOR_RED " !! The date is incorrect. 1 < month < 12 !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(m<1|| m>12);
        do{
            printf("Enter the day: ");
            scanf("%d",&j);
            fgetc(stdin);
            if( ((m==4 || m==6 ||m==9 || m==11)&&(j<1 || j>30) )||((m==2) && (j<1 || j>28)) || j<1 || j>31){
                printf(ANSI_COLOR_RED " !! The date is incorrect. 1 < day < 31 (or 30, or 28 depending on the month).!!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while( ((m==4 || m==6 ||m==9 || m==11)&&(j<1 || j>30) )||((m==2) && (j<1 || j>28)) || j<1 || j>31);
        printf("\nHere are all the messages from the date: %d/%d \n\n",m,j);
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            if(m==inMessage.month && j==inMessage.day){
                AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
            }
        }
    break;
    default :
        printf("\n Here are your messages :\n\n");
        while (fscanf(inBOX, MESSAGE_FORMAT_IN, inMessage.source, inMessage.destinataire, inMessage.sujet, inMessage.content,&inMessage.month,&inMessage.day,&inMessage.hour,&inMessage.min, &inMessage.nmbre) != EOF) 
        {
            AFFICHE_MESSAGE(inMessage.nmbre,inMessage.month,inMessage.day,inMessage.hour,inMessage.min,inMessage.source,inMessage.destinataire,inMessage.sujet,inMessage.content);
        }
    }
    if(rep!=2){
    printf(ANSI_COLOR_YELLOW "you have %ld total messages",inMessage.nmbre);
    printf(ANSI_COLOR_RESET);
    fclose(inBOX);
    }
}

void sendMessage(char login[],char Filename[]) {
    lettre newMessage;
    char Filename1[MAX_LENGTH_FILENAME];
    FILE *Receiver, *Sender;
    int existe,secure_subject,secure_content;
    int rep=1;
    // Copy recipient login
    strcpy(newMessage.source,login);

    // Get source (out) login
    do{
        printf("Enter your recipient: ");
        fgets(newMessage.destinataire,MAX_LENGTH_LOGIN,stdin);
        strtok(newMessage.destinataire,"\n");
        existe=existe_login(newMessage.destinataire);
        if(existe==0){
            printf(ANSI_COLOR_RED "!! The recipient does not exist !!\n");
            printf(ANSI_COLOR_RESET);
            do{
            MENU_SORTIR();
            scanf("%d",&rep);
            }while(rep!=1 && rep!=2);
            fgetc(stdin);
            END_PAGE();
            if(rep==2){
                break;}
            }
    }while(existe==0);

    if(rep!=2){// Get subject
        do{
            printf("Enter the subject: ");
            fgets(newMessage.sujet,MAX_LENGTH_SUBJECT,stdin);
            strtok(newMessage.sujet,"\n");
            secure_subject=secure_login(newMessage.sujet);
            if (secure_subject==1){
                    printf(ANSI_COLOR_RED "\n !! The subject must have at least 4 characters !!\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_subject==2){
                    printf(ANSI_COLOR_RED "\n !! The subject must not contain special characters !!\n");
                    printf(ANSI_COLOR_RESET);
                }else if(secure_subject==3){
                    printf(ANSI_COLOR_RED "\n !! The subject must not contain spaces !!\n");
                    printf(ANSI_COLOR_RESET);
                }
            }while(secure_subject!=0);
        // Get message content
        do{
            printf("Enter the content: ");
            fgets(newMessage.content, MAX_LENGTH_CONTENT, stdin);
            strtok(newMessage.content,"\n");
            secure_content=secure_CONTENT(newMessage.content);
            if(secure_content==0){
                printf(ANSI_COLOR_RED " !! The content of the message must not contain ':' !!\n");
                printf(ANSI_COLOR_RESET);
            }
        }while(secure_content==0);
        
        //Get the time 
        time_t currentTime;
        struct tm *localTime;
        currentTime= time(NULL);
        localTime =localtime(&currentTime);

        newMessage.month=(localTime->tm_mon)+1;
        newMessage.day=localTime->tm_mday;
        newMessage.hour=localTime->tm_hour;
        newMessage.min=localTime->tm_min;

        create_Filename(Filename1,newMessage.destinataire);

        //Count how many lines the file has
        newMessage.nmbre=count_message(Filename1);

        // Open the recipient's in file in append mode
        Receiver= fopen(Filename1, "a");
        if (Receiver == NULL) {
            printf("Error opening in file");
            exit(EXIT_FAILURE);
        }

        // Write the message to the recipient's in file
        fprintf(Receiver, MESSAGE_FORMAT_OUT, newMessage.source, newMessage.destinataire, newMessage.sujet, newMessage.content,newMessage.month, newMessage.day,newMessage.hour,newMessage.min, newMessage.nmbre);

        fclose(Receiver);
        if(strcmp(newMessage.destinataire,newMessage.source)!=0){
            //Count how many lines the file has
            newMessage.nmbre=count_message(Filename);

            // Open the recipient's in file in append mode
            Sender= fopen(Filename, "a");
            if (Sender == NULL) {
                printf("Error opening out file");
                exit(EXIT_FAILURE);
            }
            // Write the message to the out's in file
            fprintf(Receiver, MESSAGE_FORMAT_OUT, newMessage.source, newMessage.destinataire, newMessage.sujet, newMessage.content,newMessage.month, newMessage.day,newMessage.hour,newMessage.min, newMessage.nmbre);
            fclose(Sender);
        }
    }
}