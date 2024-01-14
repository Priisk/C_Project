#include <stdio.h>
#include <ctype.h>

// Fonction pour chiffrer ou déchiffrer un caractère selon le chiffrement de César
char Cesar(char character, int shift) {
    if (isalpha(character)) {
        char base = islower(character) ? 'a' : 'A';
        return (character - base + shift) % 26 + base;
    }
    return character;
}

// Fonction pour chiffrer un message
void encryptMessage(char *message, int shift) {
    while (*message) {
        *message = Cesar(*message, shift);
        message++;
    }
}

// Fonction pour déchiffrer un message
void decryptMessage(char *message, int shift) {
    // Le déchiffrement avec un décalage de 'x' est équivalent à un chiffrement avec un décalage de 26 - 'x'
    encryptMessage(message, 26 - shift);
}

int main() {
    char message[1000];
    int shift;
    int choice;

    while (1) {
        // Saisir le message
        printf("Entrez le message : ");
        fgets(message, sizeof(message), stdin);

        // Demander à l'utilisateur s'il veut chiffrer (1), déchiffrer (2), ou quitter (0)
        printf("Choisissez l'option :\n");
        printf("1. Chiffrer\n");
        printf("2. Dechiffrer\n");
        printf("0. Quitter\n");
        scanf("%d", &choice);
        getchar();  

        if (choice == 0) {
            printf("Programme termine.\n");
            break;
        }

        // Saisir le décalage
        printf("Entrez le decalage : ");
        scanf("%d", &shift);
        getchar();  

        // Chiffrer, déchiffrer ou quitter en fonction du choix de l'utilisateur
        if (choice == 1) {
            encryptMessage(message, shift);
            printf("Message chiffre : %s\n", message);
        } else if (choice == 2) {
            decryptMessage(message, shift);
            printf("Message dechiffre : %s\n", message);
        } else {
            printf("Option invalide. Programme terminé.\n");
            break;
        }
    }

    return 0;
}
