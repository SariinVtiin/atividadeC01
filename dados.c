#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
    FILE *arquivocsv, *arquivo_saida;
    arquivocsv = fopen("DadosEntrada.csv", "r");
    arquivo_saida = fopen("Saida.csv", "w"); // Abre um arquivo para escrita

    int i = 1;
    int status;
    float media;
    char aprovado[] = "Aprovado";
    char reprovado[] = "Reprovado";
    int primeiraLinha = 1; // Flag para indicar se estamos na primeira linha

	// Variáveis para armazenar os campos
    char nome[256];
    char telefone[256];
    char curso[256];
    float nota1, nota2;

    if (arquivocsv == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1; // Termina o programa com código de erro
    }

    if (arquivo_saida == NULL) {
        printf("Erro ao criar arquivo de saída\n");
        return 1; // Termina o programa com código de erro
    }

    char linha[256]; // Um buffer para armazenar cada linha lida

    while (fgets(linha, sizeof(linha), arquivocsv) != NULL) {
        if (primeiraLinha) {
            primeiraLinha = 0; // Ignora a primeira linha
            continue;
        }

        // Usamos strtok para dividir a linha em campos usando vírgula como delimitador
        char *token = strtok(linha, ",");
    

        // Começamos a atribuir os valores aos campos
        if (token != NULL) {
            strcpy(nome, token);
            token = strtok(NULL, ",");
        }

        if (token != NULL) {
            strcpy(telefone, token);
            token = strtok(NULL, ",");
        }

        if (token != NULL) {
            strcpy(curso, token);
            token = strtok(NULL, ",");
        }

        if (token != NULL) {
            nota1 = atof(token);
            token = strtok(NULL, ",");
        }

        if (token != NULL) {
            nota2 = atof(token);
        }
        
        if (token != NULL){
        	
        	media = (nota1 + nota2)/2;
        	
        	if(media >= 7) {
        		status = aprovado;
			} else {
				status = reprovado;
			}
		}

		/* APENAS PARA TESTE 
        printf(" %d: %s ", i, nome);
        printf(" %0.2f ", media);
        printf(" %s \n", status);
        */
        
        // Escreve os dados no arquivo de saída em formato CSV
        fprintf(arquivo_saida, "%s,%0.2f,%s\n", nome, media, status);
        
        
        i++;
    }

    fclose(arquivocsv);
    fclose(arquivo_saida);

    printf("Arquivo criado com sucesso!");

    return 0;
}
