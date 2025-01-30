#define MAX_LENGTH_LOGIN 20
#define MAX_LENGTH_SUBJECT 40
#define MAX_LENGTH_FILENAME 24
#define MAX_LENGTH_CONTENT 500

#define MESSAGE_FORMAT_OUT "(%s:%s:%s:%s:%02d,%02d,%02d,%02d:%ld)\n"
#define MESSAGE_FORMAT_IN "(%[^:]:%[^:]:%[^:]:%[^:]:%02d,%02d,%02d,%02d:%ld)\n"
#define TIME_FORMAT  "sent at\t%02d/%02d\t%02d:%02d\n"

typedef struct lettre {
    long int nmbre;
    char source[MAX_LENGTH_LOGIN];
    char destinataire[MAX_LENGTH_LOGIN];
    char sujet[MAX_LENGTH_SUBJECT];
    char content[MAX_LENGTH_CONTENT];
    int month;
    int day;
    int hour;
    int min;
}lettre;

void sendMessage(char login[],char Filename[]);
void viewbox(int rep,char Filename[],char login[]);
int count_message(char Filename[]);
void AFFICHE_MESSAGE(int  champ1,int champ6,int champ7,int champ8,int champ9,char champ2[],char champ3[],char champ4[],char champ5[]);
void deleteMessage(compte Account,int rep);