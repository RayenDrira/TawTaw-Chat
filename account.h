#define MAX_LENGTH_ACC 40
typedef struct compte{
    char login[MAX_LENGTH_ACC];
    char mot_de_passe[MAX_LENGTH_ACC];
    char Filename[MAX_LENGTH_ACC+4];
}compte;

int Connection(compte *Account) ;
void create_account(compte* Account);
void modification(int,compte*);
int Supprimer_compte(compte Account);

int gestion_fichier(compte Account);
void add_line(compte *Tawtaw);
void modify_messages(compte Account,compte new_Account);
int supprimer_account(char login[]);

