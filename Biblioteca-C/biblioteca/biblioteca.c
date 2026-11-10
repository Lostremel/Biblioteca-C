#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LEITOR 100
#define MAX_LIVROS 100

int main()
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    char leitores[MAX_LEITOR][100];
    char titulos[MAX_LIVROS][100];
    char autores[MAX_LIVROS][100];
    int categorias[MAX_LIVROS];
    int quantidadeLeitores = 0;
    int quantidadeLivros = 0;
    int opcao;

    do {
        printf("=== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ===\n\n");
        printf("1 - Cadastrar leitor\n");
        printf("2 - Registrar empréstimo\n");
        printf("3 - Cadastrar livro\n");
        printf("4 - Emitir relatório\n");
        printf("5 - Sair\n");

        printf("\nSelecione uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Cadastro de Leitor ---\n");
                if (quantidadeLeitores < MAX_LEITOR) {
                    printf("Digite o nome do leitor: ");
                    scanf(" %99[^\n]", leitores[quantidadeLeitores]);

                    int jaCadastrado = 0;
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        if (strcmp(leitores[i], leitores[quantidadeLeitores]) == 0) {
                            jaCadastrado = 1;
                            break;
                        }
                    }

                    if (jaCadastrado) {
                        printf("\nLeitor já cadastrado.\n\n");
                    } else {
                        quantidadeLeitores++;
                        printf("\nLeitor cadastrado com sucesso.\n\n");
                    }
                } else {
                    printf("\nLimite máximo de leitores atingido.\n\n");
                }
                break;

            case 2:
                printf("\n--- Registro de Empréstimo ---\n");
                if (quantidadeLeitores == 0) {
                    printf("Nenhum leitor cadastrado. Cadastre um leitor antes de registrar um empréstimo.\n\n");
                } else if (quantidadeLivros == 0) {
                    printf("Nenhum livro cadastrado no acervo. Cadastre um livro antes de registrar um empréstimo.\n\n");
                } else {
                    int idLeitor, idLivro;

                    printf("\n--- Seleção do Leitor ---\n");
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        printf("[%d] %s\n", i + 1, leitores[i]);
                    }
                    printf("Digite o número correspondente ao leitor: ");
                    scanf("%d", &idLeitor);

                    printf("\n--- Seleção do Livro ---\n");
                    for (int i = 0; i < quantidadeLivros; i++) {
                        printf("[%d] %s (Autor: %s)\n", i + 1, titulos[i], autores[i]);
                    }
                    printf("Digite o número correspondente ao livro: ");
                    scanf("%d", &idLivro);

                    if (idLeitor >= 1 && idLeitor <= quantidadeLeitores &&
                        idLivro >= 1 && idLivro <= quantidadeLivros) {
                        printf("\n[SUCESSO] Empréstimo registrado: o livro \"%s\" foi associado ao leitor %s.\n\n",
                               titulos[idLivro - 1], leitores[idLeitor - 1]);
                    } else {
                        printf("\nOpção de leitor ou livro inválida.\n\n");
                    }
                }
                break;

            case 3:
                printf("\n--- Cadastro de Livro ---\n");

                if (quantidadeLivros < MAX_LIVROS) {
                    printf("Digite o título do livro: ");
                    scanf(" %99[^\n]", titulos[quantidadeLivros]);

                    printf("Digite o nome do autor: ");
                    scanf(" %99[^\n]", autores[quantidadeLivros]);

                    printf("Digite o código da categoria: ");
                    scanf("%d", &categorias[quantidadeLivros]);

                    quantidadeLivros++;
                    printf("\nLivro cadastrado com sucesso.\n\n");
                } else {
                    printf("\nLimite máximo de livros atingido.\n\n");
                }
                break;

            case 4: {
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                char data[20];
                strftime(data, sizeof(data), "%d/%m/%Y", &tm);

                printf("========================================\n");
                printf("       RELATÓRIO DA BIBLIOTECA\n");
                printf("       Data: %s\n", data);
                printf("========================================\n\n");

                printf("Leitores cadastrados: %d\n", quantidadeLeitores);
                if (quantidadeLeitores > 0) {
                    for (int i = 0; i < quantidadeLeitores; i++) {
                        printf(" - %s\n", leitores[i]);
                    }
                }

                printf("\nObras cadastradas no acervo: %d\n", quantidadeLivros);
                if (quantidadeLivros > 0) {
                    for (int i = 0; i < quantidadeLivros; i++) {
                        printf(" - %s (Autor: %s | Categoria: %d)\n",
                               titulos[i], autores[i], categorias[i]);
                    }
                }
                printf("\n");
                break;
            }

            case 5:
                printf("\nEncerrando o sistema. Até a próxima!\n");
                break;

            default:
                printf("\nOpção inválida. Selecione uma opção entre 1 e 5.\n\n");
        }

    } while (opcao != 5);

    return 0;
}
