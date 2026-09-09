#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LEITOR 100
#define MAX_LIVROS 100

int main()
{
    system("chcp 65001 > nul");
    char leitores[MAX_LEITOR][100];
    char titulos[MAX_LIVROS][100];
    char autores[MAX_LIVROS][100];
    int categorias[MAX_LIVROS];
    int quantidadeLeitores = 0;
    int quantidadeLivros = 0;
    int opcao;

    do {
        printf("=== Biblioteca Marxista de Ponta Grossa [☭] ===\n\n");
        printf("1 - Cadastrar Proletariado \n");
        printf("2 - Distribuição de Conhecimento \n");
        printf("3 - Cadastro de Conhecimento\n");
        printf("4 - Relatorio do dia\n");
        printf("5 - Sair\n");

        printf("\nEscolha uma opção, camarada. O conhecimento pertence ao povo!: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                // parte leo
                printf("\nCadastrando Leitor...\n");
                if (quantidadeLeitores < MAX_LEITOR) {
                    printf("Digite o nome do leitor: ");
                    scanf(" %[^\n]", leitores[quantidadeLeitores]);
                    
                    int jaCadastrado = 0;
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        if (strcmp(leitores[i], leitores[quantidadeLeitores]) == 0) {
                            jaCadastrado = 1;
                            break;
                        }
                    }
                    
                    if (jaCadastrado) {
                        printf("\nLeitor já cadastrado!\n\n");
                    } else {
                        quantidadeLeitores++;
                        printf("\nLeitor cadastrado com sucesso!\n\n");
                    }
                } else {
                    printf("\nLimite de leitor atingido meu chapa!\n\n");
                }
                break;

            case 2:
                // parte ysaque
                printf("\n--- Distribuição do Conhecimento ---\n");
                if (quantidadeLeitores == 0) {
                    printf("Nenhum camarada cadastrado ainda! Cadastre um camarada primeiro.\n\n");
                } else if (quantidadeLivros == 0) {
                    printf("Nenhum livro cadastrado ainda no acervo!\n\n");
                } else {
                    int idLeitor, idLivro;

                    printf("\n--- Selecione o Camarada (Leitor) ---\n");
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        printf("[%d] %s\n", i + 1, leitores[i]);
                    }
                    printf("Digite o número correspondente ao leitor: ");
                    scanf("%d", &idLeitor);

                    printf("\n--- Selecione o Conhecimento (Livro) ---\n");
                    for (int i = 0; i < quantidadeLivros; i++) {
                        printf("[%d] %s (Autor: %s)\n", i + 1, titulos[i], autores[i]);
                    }
                    printf("Digite o número correspondente ao livro: ");
                    scanf("%d", &idLivro);

                    if (idLeitor >= 1 && idLeitor <= quantidadeLeitores && idLivro >= 1 && idLivro <= quantidadeLivros) {
                        printf("\n[SUCESSO] O livro \"%s\" foi distribuído para o camarada %s!\n\n",
                               titulos[idLivro - 1], leitores[idLeitor - 1]);
                    } else {
                        printf("\nOpção inválida de leitor ou livro selecionada!\n\n");
                    }
                }
                break;

            case 3:
                // parte roger
                printf("\nCadastro de Conhecimento\n");

                if (quantidadeLivros < MAX_LIVROS) {
                    printf("Digite o título do livro, camarada: ");
                    scanf(" %[^\n]", titulos[quantidadeLivros]);

                    printf("Qual é o autor que você procura, camarada?: ");
                    scanf(" %[^\n]", autores[quantidadeLivros]);

                    printf("Digite a categoria do livro, camarada!: ");
                    scanf("%d", &categorias[quantidadeLivros]);

                    quantidadeLivros++;
                    printf("\nLivro cadastrado com sucesso!\n\n");
                } else {
                    printf("\nLimite de livros atingido, camarada!\n\n");
                }
                break;

            case 4: {
                // Parte do Kelvin 
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                char data[11];
                sprintf(data, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

                printf("========================================\n");
                printf("       RELATORIO DIARIO DA BIBLIOTECA\n");
                printf("       Data: %s\n", data);
                printf("========================================\n\n");

                printf("Leitores (Camaradas) cadastrados: %d\n", quantidadeLeitores);
                if (quantidadeLeitores > 0) {
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        printf(" - %s\n", leitores[i]);
                    }
                }

                printf("\nObras no acervo: %d\n", quantidadeLivros);
                if (quantidadeLivros > 0) {
                    for (int i = 0; i < quantidadeLivros; i++) {
                        printf(" - %s (Autor: %s)\n", titulos[i], autores[i]);
                    }
                }
                printf("\n");
                break;
            }

            case 5:
                printf("\nAté mais, camarada! Mantenha-se lutando pelo fim do capitalismo.\n");
                break;

            default:
                printf("\nOpção inválida, tenta outra coisa camarada\n\n");
        }

    } while (opcao != 5);

    return 0;
}