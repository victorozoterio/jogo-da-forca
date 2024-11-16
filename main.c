#include <stdio.h>  // Biblioteca para funções de entrada e saída (printf, scanf)
#include <string.h> // Biblioteca para manipulação de strings (strlen, strcmp)
#include <stdlib.h> // Biblioteca para funções utilitárias (system())

// Função para desenhar a forca
void desenhaForca(int tentativas) {
    switch (tentativas) {
        case 6:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 5:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|       \n");
            printf("|       \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 4:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|   |   \n");
            printf("|       \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 3:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|  /|   \n");
            printf("|       \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 2:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|  /|\\  \n");
            printf("|       \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 1:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|  /|\\  \n");
            printf("|  /    \n");
            printf("|       \n");
            printf("========\n");
            break;
        case 0:
            printf("\n");
            printf("-----    \n");
            printf("|   |   \n");
            printf("|   O   \n");
            printf("|  /|\\  \n");
            printf("|  / \\  \n");
            printf("========\n");
            printf("GAME OVER!\n");
            break;
    }
}

// Função para limpar a tela
void limparTela() {
    #ifdef _WIN32
        system("cls");  // Para Windows
    #else
        system("clear");  // Para Linux/macOS
    #endif
}

int main() {
    char palavra[50]; // Palavra a ser adivinhada
    char letra, letrasErradas[6];
    int tamanho, tentativas = 6, erros = 0;
    char palavraAdivinhada[tamanho + 1]; // Mantém o progresso do jogador
    char letrasTentadas[26] = {0};  // Array para controlar todas as letras já tentadas

    // Solicita ao usuário que digite a palavra a ser adivinhada
    printf("Digite a palavra a ser adivinhada: ");
    scanf("%s", palavra);
    
    tamanho = strlen(palavra); // Obtém o tamanho da palavra
    
    // Inicializa a palavraAdivinhada com underscores
    for (int i = 0; i < tamanho; i++) {
        palavraAdivinhada[i] = '_';
    }
    palavraAdivinhada[tamanho] = '\0'; // Adiciona '\0' no final da string para indicar seu término.

    // Loop principal do jogo, executado enquanto o número de tentativas for maior que 0 e a palavra não estiver completamente adivinhada
    while (tentativas > 0 && strcmp(palavraAdivinhada, palavra) != 0) {
        limparTela(); // Limpa a tela a cada iteração

        // Exibe a palavra oculta e o número de tentativas restantes
        printf("\n========================\n");
        printf("     Jogo da Forca        \n");
        printf("========================\n");
        printf("\nPalavra: %s\n", palavraAdivinhada);
        printf("Tentativas restantes: %d\n", tentativas);
        desenhaForca(tentativas); // Desenha a forca de acordo com as tentativas restantes

        // Se houver letras erradas, exibe-as
        if (erros > 0) {
            printf("Letras erradas: ");
            for (int i = 0; i < erros; i++) {
                printf("%c ", letrasErradas[i]);
            }
            printf("\n");
        }

        // Solicita ao usuário que digite uma letra
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Verifica se a letra já foi tentada
        if (letrasTentadas[letra - 'a']) {
            printf("Voce ja digitou essa letra! Tente outra.\n");
            printf("Pressione Enter para continuar...");
            getchar();  // Consome o Enter (\n) deixado no buffer pelo scanf
            getchar();  // Aguarda o usuário pressionar Enter novamente para continuar
            continue;
        }

        // Marca a letra como tentada
        letrasTentadas[letra - 'a'] = 1;

        // Procura pela letra na palavra
        int acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                palavraAdivinhada[i] = letra;  // Substitui o underscore pela letra correta
                acertou = 1;
            }
        }

        // Se a letra não foi encontrada na palavra, é considerada errada
        if (!acertou) {
            printf("Letra incorreta!\n");
            letrasErradas[erros] = letra;  // Armazena a letra errada
            erros++;  // Incrementa o número de erros
            tentativas--;  // Decrementa o número de tentativas restantes
            printf("Pressione Enter para continuar...");
            getchar();  // Consome o Enter do scanf
            getchar();  // Espera por um novo Enter
        }

        // Se as tentativas chegarem a zero, o jogador perdeu
        if (tentativas == 0) {
            limparTela();
            desenhaForca(tentativas);
            printf("\nVoce perdeu! A palavra era: %s\n", palavra);
            break;
        }
    }

    // Se o jogador adivinhar a palavra corretamente
    if (strcmp(palavraAdivinhada, palavra) == 0) {
        printf("\nParabens! Voce adivinhou a palavra: %s\n", palavra);
    }

    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}
