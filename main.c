#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flush_in();
void buscar(char *sequencia);


int main (){
    char op; 
    char *sequencia = malloc(10*sizeof(char)); 
    
    do{
        printf("---------------------------------\n");
        printf("- Bases Nitrogenadas => A U C G -\n");
        printf("---------------------------------\n");
        printf("- Digite a sequencia: ");
        gets(sequencia);

        printf("- Buscando(%s)...", sequencia);

        buscar(sequencia);

        free(sequencia);

        printf("\nDeseja efetuar uma nova analise (s) ou (n)?\n-> ");
        flush_in();
        scanf("%c", &op);
       
        
    } while (op!='n' && op != 'N');
    
    return 0;
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void buscar(char *sequencia){
    int tam=0, a=0, b, c, d, ocAux=0, ocorrencia=0;
    
    tam = strlen(sequencia);
    
    char *sequenciaAux = malloc(10*sizeof(char));
    char *rna=malloc(10000001*sizeof(char));
    char x;

    FILE *sarsCov2;
    
    sarsCov2 = fopen("sars-cov-2-win.txt", "a+");
    do{
		x = fgetc(sarsCov2);
		if(x !='\n'){
			rna[a]=x;
			a++;
		}
	}while(x != EOF);

    fclose(sarsCov2);

    for(b=0; b<a; b++){
		for(c=0, d=b; c<tam; c++, d++){
			sequenciaAux[c] = rna[d];
		}
        for(ocAux=0, c=0;c<tam;c++){
            if(sequencia[c] == sequenciaAux[c]){
                ocAux++;
            }
            if (ocAux == tam){
                ocorrencia++;   
            }
        }
       
    }

    printf("\n- Total de ocorrencias [%s] = %i \n", sequencia, ocorrencia);
    free(rna);
    free(sequencia);
    free(sequenciaAux);
}