#include <stdio.h>
#include <string.h>

#define MAX_LEITOR 100
#define MAX_LIVROS 100

 int main()
{
char leitores[MAX_LEITOR][100];
char titulos[MAX_LIVROS][100];
char autores[MAX_LIVROS][100];
int categorias[MAX_LIVROS];
int qualidadeLeitores = 0;
int opcao;

do {
   printf("===Biblioteca Marxista de Ponta Grossa ☭==\n\n");
   printf("1 - Cadastradar Proletariado \n");
   printf("2 - Distribuição de Conhecimento \n");
   printf("3 - Cadastro de Conhecimento\n");
   printf("4 - Relatorio do dia\n");
   printf("5 - Sair\n");

   printf("\nEscolha uma opção, camarada. O conhecimento pertence ao povo!: ");
   scanf("%d", &opcao);
   
   switch (opcao) {
    case 1:
        printf("\nCadastrando Leitor...\n");
        if (qualidadeLeitores < MAX_LEITOR) {
            printf("Digite o nome do leitor: ");
            scanf("%s", leitores[qualidadeLeitores]);
            int jaCadastrado = 0;
            for (int i = 0; i < qualidadeLeitores; i++) {
                if (strcmp(leitores[i], leitores[qualidadeLeitores]) == 0) {
                    jaCadastrado = 1;
                    break;
                }
            }
            if(jaCadastrado) {
                printf("\nLeitor já cadastrado!\n");
            } else {
                qualidadeLeitores++;
                printf("\nLeitor cadastrado com sucesso!\n\n");
            }
    
        } else {
            printf("\nLimite de leitor atingido meu chapa!\n");
        }
        break;

        case 2:
        printf("\nDistribuição do Conhecimento\n");
        //parte do Ysaque
       
        break;

        case 3:
    printf("\nCadastro de Conhecimento\n");

    if (qualidadeLeitores < MAX_LIVROS) {

        printf("Digite o título do livro, camarada: ");
        scanf(" %[^\n]", titulos[qualidadeLeitores]);
        printf("Qual é o autor que você procura, camarada?: ");
        scanf(" %[^\n]", autores[qualidadeLeitores]);
        printf("Digite a categoria do livro, camarada!: ");
        scanf("%d", &categorias[qualidadeLeitores]);
        printf("\nLivro cadastrado com sucesso!\n\n");

    } else {
        printf("\nLimite de livros atingido, camarada!\n");
    }
    break;

        case 4:
        printf("\nRelatorio do dia\n");
        //parte do kelvin
        break;

        case 5:
        printf("\nAté mais, camarada! Mantenha-se lutando pelo fim do capitalismo.\n");
        break;

        default:
        printf("\nOpção invalida, tenta outra coisa camarada\n");

   }

} while(opcao != 5);



return 0;
}
