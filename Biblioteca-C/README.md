# Sistema de Gerenciamento de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C para demonstrar conceitos fundamentais de programação estruturada, manipulação de vetores, estruturas de repetição, estruturas condicionais, funções da biblioteca padrão e interação com o usuário por meio do terminal.

O sistema apresenta uma versão inicial de um gerenciamento de biblioteca, permitindo cadastrar leitores, cadastrar livros, registrar uma associação de empréstimo e emitir um relatório do acervo. A proposta foi organizada com uma interface textual objetiva e adequada para apresentação acadêmica.

---

## Objetivo do projeto

Desenvolver uma aplicação de console capaz de organizar informações básicas de uma biblioteca durante a execução do programa. O projeto foi estruturado para exercitar os seguintes conteúdos:

- declaração e utilização de variáveis;
- vetores de caracteres e vetores numéricos;
- entrada e saída de dados com `scanf` e `printf`;
- estruturas de repetição com `do...while` e `for`;
- seleção de opções com `switch...case`;
- comparação de textos com `strcmp`;
- manipulação de data e hora com `time.h`;
- validação de opções informadas pelo usuário;
- organização de um menu interativo;
- compilação e execução de um programa em C.

---

## Funcionalidades implementadas

### 1. Cadastro de leitores

O sistema permite cadastrar até **100 leitores**. Para cada leitor, é armazenado seu nome em um vetor de strings.

Durante o cadastro:

- o nome do leitor é solicitado pelo terminal;
- o programa verifica se o mesmo nome já foi cadastrado;
- leitores duplicados não são adicionados;
- o usuário é informado quando o cadastro é concluído;
- o sistema informa quando o limite máximo é atingido.

### 2. Cadastro de livros

O sistema permite cadastrar até **100 livros**. Para cada obra, são armazenados:

- título;
- autor;
- código numérico da categoria.

O cadastro é realizado diretamente pelo menu principal. O programa verifica se ainda existe espaço disponível no vetor de livros antes de incluir uma nova obra.

### 3. Registro de empréstimo

A opção de empréstimo permite selecionar um leitor e um livro já cadastrados. O sistema:

1. verifica se existe pelo menos um leitor;
2. verifica se existe pelo menos um livro;
3. lista os leitores disponíveis;
4. lista os livros disponíveis com seus autores;
5. solicita os índices escolhidos;
6. valida se os índices estão dentro dos limites;
7. exibe uma mensagem confirmando a associação entre leitor e livro.

> **Limitação atual:** o registro de empréstimo é demonstrativo. O código valida a seleção e exibe a confirmação, mas não mantém uma lista permanente de empréstimos, não controla disponibilidade de exemplares e não registra data de devolução.

### 4. Relatório da biblioteca

A opção de relatório exibe:

- a data atual do sistema;
- a quantidade de leitores cadastrados;
- a lista de leitores;
- a quantidade de livros cadastrados;
- a lista de livros;
- o autor de cada obra;
- o código de categoria informado para cada livro.

O relatório é montado com os dados disponíveis na memória durante a execução.

### 5. Encerramento e validação de menu

A opção **Sair** encerra o laço principal do programa. Caso o usuário informe uma opção diferente de 1 a 5, o sistema exibe uma mensagem de opção inválida e retorna ao menu.

---

## Estrutura do projeto

```text
Biblioteca-C-main/
├── README.md
└── biblioteca/
    └── biblioteca.c
```

O arquivo `biblioteca.c` concentra a implementação do sistema. A estrutura foi mantida simples e adequada ao objetivo didático do projeto.

---

## Estruturas de dados utilizadas

O programa utiliza vetores com limites fixos:

```c
#define MAX_LEITOR 100
#define MAX_LIVROS 100
```

Os dados são organizados da seguinte forma:

```c
char leitores[MAX_LEITOR][100];
char titulos[MAX_LIVROS][100];
char autores[MAX_LIVROS][100];
int categorias[MAX_LIVROS];
```

A quantidade de registros atuais é controlada por duas variáveis inteiras:

```c
int quantidadeLeitores = 0;
int quantidadeLivros = 0;
```

Cada novo registro é inserido na posição correspondente à quantidade atual e, em seguida, o contador é incrementado.

---

## Fluxo de funcionamento

Ao iniciar, o programa apresenta o menu principal:

```text
=== SISTEMA DE GERENCIAMENTO DE BIBLIOTECA ===

1 - Cadastrar leitor
2 - Registrar empréstimo
3 - Cadastrar livro
4 - Emitir relatório
5 - Sair
```

O menu é executado dentro de um laço `do...while`, garantindo que o usuário possa realizar diversas operações antes de encerrar o programa.

A opção escolhida é armazenada na variável `opcao` e processada por uma estrutura `switch`. Cada `case` representa uma operação do sistema.

---

## Requisitos

Para compilar o projeto, é necessário possuir um compilador C compatível, como:

- GCC;
- MinGW/MSYS2 no Windows;
- Clang;
- Visual Studio com suporte a C.

O projeto utiliza recursos da biblioteca padrão do C:

- `stdio.h` para entrada e saída;
- `string.h` para comparação de strings;
- `time.h` para obtenção da data atual;
- `stdlib.h` para funções gerais do sistema.

---

## Compilação no Linux ou macOS

No terminal, acesse a pasta que contém o arquivo-fonte:

```bash
cd biblioteca
gcc -std=c11 -Wall -Wextra -pedantic biblioteca.c -o Biblioteca
```

Para executar:

```bash
./Biblioteca
```

---

## Compilação no Windows

Com GCC/MinGW instalado, abra o Prompt de Comando ou PowerShell na pasta do projeto e execute:

```bash
gcc -std=c11 -Wall -Wextra -pedantic biblioteca.c -o Biblioteca.exe
```

Depois, execute:

```powershell
.\Biblioteca.exe
```

Também é possível abrir o executável pelo Explorador de Arquivos.

---

## Exemplo de utilização

Uma sequência de teste pode ser realizada da seguinte maneira:

1. selecione `1` e cadastre um leitor;
2. selecione `3` e cadastre um livro, informando título, autor e categoria;
3. selecione `2` e escolha o leitor e o livro pelos números apresentados;
4. selecione `4` para visualizar o relatório;
5. selecione `5` para encerrar.

Exemplo de cadastro:

```text
Digite o nome do leitor: Ana Souza

Leitor cadastrado com sucesso.
```

```text
Digite o título do livro: Introdução à Programação
Digite o nome do autor: Autor Exemplo
Digite o código da categoria: 1

Livro cadastrado com sucesso.
```

---

## Validações existentes

O programa possui as seguintes validações:

- impede o cadastro de leitores repetidos pelo nome;
- limita o cadastro a 100 leitores;
- limita o cadastro a 100 livros;
- impede o registro de empréstimo quando não há leitores cadastrados;
- impede o registro de empréstimo quando não há livros cadastrados;
- valida os números escolhidos para leitor e livro;
- informa opções inválidas no menu principal;
- limita a leitura de nomes, títulos e autores a 99 caracteres, preservando espaço para o terminador da string;
- gera a data do relatório a partir do relógio do sistema.

---

## Limitações conhecidas

Este projeto representa uma versão introdutória e acadêmica. Portanto, os dados são mantidos somente em memória e são perdidos quando o programa é encerrado.

Funcionalidades que ainda não fazem parte da implementação atual:

- persistência em arquivos ou banco de dados;
- autenticação de usuários;
- cadastro de funcionários;
- controle de quantidade de exemplares;
- bloqueio de empréstimo de livro já emprestado;
- histórico de empréstimos;
- registro de data de retirada e devolução;
- cálculo de multas;
- alteração ou exclusão de leitores e livros;
- pesquisa por título, autor ou categoria;
- relatórios exportados para arquivo;
- interface gráfica;
- cadastro textual das categorias, que atualmente são representadas por códigos numéricos.

Essas limitações são compatíveis com o escopo atual de um projeto introdutório de programação estruturada e podem orientar futuras versões.

---

## Possíveis evoluções

Como continuação do projeto, podem ser implementadas as seguintes melhorias:

1. criar funções separadas para cada operação do menu;
2. substituir os vetores fixos por estruturas `struct` para representar leitores, livros e empréstimos;
3. armazenar os dados em arquivos `.txt` ou binários;
4. adicionar edição e exclusão de registros;
5. controlar o status de cada exemplar;
6. registrar datas de empréstimo e devolução;
7. criar busca por título, autor e categoria;
8. implementar relatórios de empréstimos ativos e devolvidos;
9. separar o projeto em arquivos `.h` e `.c`;
10. desenvolver uma interface gráfica ou uma API para ampliar o acesso ao sistema.

---

## Considerações acadêmicas

O projeto demonstra a aplicação prática de conceitos fundamentais da linguagem C em um problema de domínio conhecido. A escolha de uma biblioteca como cenário facilita a compreensão de entidades, operações e regras básicas, além de permitir a evolução gradual da solução.

A implementação atual prioriza clareza e funcionamento do fluxo principal. O código pode servir como base para trabalhos posteriores envolvendo modularização, estruturas compostas, persistência de dados e desenvolvimento de sistemas mais completos.

---

## Autoria

Projeto acadêmico desenvolvido para fins educacionais.
