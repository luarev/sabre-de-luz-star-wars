#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

void desligarSabre(const char* personagem, const char* cor, int corCodigo) {
    printf("\n\nPressione ENTER para desligar o sabre de %s...\n", personagem);
    getchar();
    PlaySound(NULL, 0, 0);
    PlaySound(TEXT("sabreOff.wav"), NULL, SND_FILENAME | SND_ASYNC);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, corCodigo);

    for (int i = 9; i >= 0; i--) {
        system("cls");
        for (int j = 0; j < i; j++) {
            printf("                |\n");
        }
        SetConsoleTextAttribute(hConsole, 7);
        printf("                |\n");
        printf("                |\n");
        printf("                |\n");
        Sleep(80);
    }

    printf("\nSabre de %s desligado.\n", personagem);
    PlaySound(NULL, 0, 0);
}

void imprimirCabo(const char* tipoSabre, HANDLE hConsole, int corCodigo) {
    if (strcmp(tipoSabre, "cruz") == 0) {
        printf("             ");
        SetConsoleTextAttribute(hConsole, corCodigo);
        printf("===");
        SetConsoleTextAttribute(hConsole, 7);
        printf("|");
        SetConsoleTextAttribute(hConsole, corCodigo);
        printf("===\n");
        SetConsoleTextAttribute(hConsole, 7);
        printf("                |\n");
        printf("                |\n");
    } else if (strcmp(tipoSabre, "duplo") == 0) {
        printf("                |\n                |\n                |\n");
    } else if (strcmp(tipoSabre, "duplo_lateral") == 0) {
        printf("            |       |\n            |       |\n            |       |\n");
    } else {
        printf("                |\n                |\n                |\n");
    }
}

void ativarSabre(const char* personagem, const char* cor, int corCodigo, const char* lado, const char* tipoSabre) {
    system("cls");
    printf("+==========================================+\n");
    printf("|        STAR WARS - SABRE DE LUZ          |\n");
    printf("+==========================================+\n");
    printf("| Personagem: %-30s|\n", personagem);
    printf("| Cor: %-36s|\n", cor);
    printf("| Lado da Forca: %-26s|\n", lado);
    printf("+==========================================+\n\n");
    Sleep(500);

    PlaySound(TEXT("sabreOn.wav"), NULL, SND_FILENAME | SND_ASYNC);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, corCodigo);

    int delay = 60;
    if (strcmp(tipoSabre, "curto") == 0) {
        for (int i = 0; i < 6; i++) {
            printf("                |\n");
            Sleep(delay);
        }
        SetConsoleTextAttribute(hConsole, 7);
        imprimirCabo(tipoSabre, hConsole, corCodigo);

    } else if (strcmp(tipoSabre, "cruz") == 0) {
        for (int i = 0; i < 8; i++) {
            printf("                |\n");
            Sleep(delay);
        }
        SetConsoleTextAttribute(hConsole, 7);
        imprimirCabo(tipoSabre, hConsole, corCodigo);

    } else if (strcmp(tipoSabre, "duplo") == 0) {
        for (int i = 0; i < 10; i++) {
            printf("                |\n");
            Sleep(delay);
        }
        SetConsoleTextAttribute(hConsole, 7);
        imprimirCabo(tipoSabre, hConsole, corCodigo);
        SetConsoleTextAttribute(hConsole, corCodigo);
        for (int i = 0; i < 10; i++) {
            printf("                |\n");
            Sleep(delay);
        }

    } else if (strcmp(tipoSabre, "duplo_lateral") == 0) {
        for (int i = 0; i < 10; i++) {
            printf("            |       |\n");
            Sleep(delay);
        }
        SetConsoleTextAttribute(hConsole, 7);
        imprimirCabo(tipoSabre, hConsole, corCodigo);

    } else {
        for (int i = 0; i < 10; i++) {
            printf("                |\n");
            Sleep(delay);
        }
        SetConsoleTextAttribute(hConsole, 7);
        imprimirCabo(tipoSabre, hConsole, corCodigo);
    }

    PlaySound(TEXT("sabreHum.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    printf("\nSabre de %s ativado!\n", personagem);
    getchar();
    desligarSabre(personagem, cor, corCodigo);
}

int main() {
    int escolha;

    while (1) {
        system("cls");
        printf("=== Simulador de Sabres de Luz - Star Wars ===\n");
        printf("Escolha seu personagem:\n");
        printf(" 0. Sair\n");
        printf(" 1.  Yoda\n");
        printf(" 2.  Anakin Skywalker\n");
        printf(" 3.  Qui-Gon Jinn\n");
        printf(" 4.  Obi-Wan Kenobi\n");
        printf(" 5.  Luke Skywalker\n");
        printf(" 6.  Mace Windu\n");
        printf(" 7.  Rey\n");
        printf(" 8.  Darth Vader\n");
        printf(" 9.  Conde Dookan\n");
        printf("10.  Darth Maul\n");
        printf("11.  Darth Sidious\n");
        printf("12.  Kylo Ren\n");
        printf("13.  Ahsoka Tano\n");
        printf("14.  Asajj Ventress\n");
        printf("15.  Kit Fisto\n");
        printf("16.  Cal Kestis\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha);
        getchar();

        if (escolha == 0) {
            printf("\nEncerrando o simulador. Que a Forca esteja com voce!\n");
            break;
        }

        switch (escolha) {
            case 1:  ativarSabre("Yoda", "verde", 10, "Jedi", "curto"); break;
            case 2:  ativarSabre("Anakin Skywalker", "azul", 9, "Jedi", "padrao"); break;
            case 3:  ativarSabre("Qui-Gon Jinn", "verde", 10, "Jedi", "padrao"); break;
            case 4:  ativarSabre("Obi-Wan Kenobi", "azul", 9, "Jedi", "padrao"); break;
            case 5:  ativarSabre("Luke Skywalker", "verde", 10, "Jedi", "padrao"); break;
            case 6:  ativarSabre("Mace Windu", "roxo", 13, "Jedi", "padrao"); break;
            case 7:  ativarSabre("Rey", "amarelo", 14, "Jedi", "padrao"); break;
            case 8:  ativarSabre("Darth Vader", "vermelho", 12, "Sith", "padrao"); break;
            case 9:  ativarSabre("Conde Dookan", "vermelho", 12, "Sith", "padrao"); break;
            case 10: ativarSabre("Darth Maul", "vermelho", 12, "Sith", "duplo"); break;
            case 11: ativarSabre("Darth Sidious", "vermelho", 12, "Sith", "padrao"); break;
            case 12: ativarSabre("Kylo Ren", "vermelho", 12, "Sith", "cruz"); break;
            case 13: ativarSabre("Ahsoka Tano", "branco", 15, "Neutro", "padrao"); break;
            case 14: ativarSabre("Asajj Ventress", "vermelho", 12, "Neutro", "duplo_lateral"); break;
            case 15: ativarSabre("Kit Fisto", "verde", 10, "Jedi", "padrao"); break;
            case 16: ativarSabre("Cal Kestis", "azul", 9, "Jedi", "padrao"); break;
            default:
                printf("Escolha invalida. Pressione ENTER para tentar novamente...\n");
                getchar();
        }
    }

    return 0;
}
