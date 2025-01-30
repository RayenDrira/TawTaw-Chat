void saisir_account(int b,compte* Account);
char *create_Filename(char chaine[],char base[]);

unsigned long hash(compte *Tawtaw);

int existe_login(char login[]);
int secure_login(char login[]);
int secure_mot_de_passe(char mot_de_passe[]);
int secure_CONTENT(char mot_de_passe[]);

int verify_password(compte *Account);