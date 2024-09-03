#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Integrantes:
//Daniel Negrao de Carvalho DRE 117252017
//Vinicios Chan Guimaraes DRE 123594778
//Matheus Goulart Lourenço DRE 124037054
//Fabricia Nicomedes DRE 


typedef struct prod{ int codigo; char nome[50]; int quantidade; float preco;} 
Produto;

Produto estoque[100];
int poslivre=0;

int buscar(void){
    char nome[50];
    printf("\n"); 
    printf("Digite o nome:");
    scanf("%s", &nome);
    for (int i=0;i<poslivre;i++){
        if(strcmp(estoque[i].nome,nome)==0){
            printf("\n");
            printf("Item %s ", estoque[i].nome);
            printf("Preço %f ", estoque[i].preco);
            printf("Quantidade %d ", estoque[i].quantidade);
            printf("Código %d ", estoque[i].codigo);
            printf("\n");
        }
        else{
            printf("\nItem não encontrado\n");
            return 1;
        }
    }
    return 0;
}

int excluir(void){
    char nome[50];
    printf("\n"); 
    printf("Digite o nome:");
    scanf("%s", &nome);
    for (int i=0;i<poslivre;i++){
        if(strcmp(estoque[i].nome,nome)==0){
           estoque[i]=estoque[poslivre];
           poslivre--;
           printf("\n");
           printf("item excluído\n");
        }
        else{
            printf("\nItem não encontrado\n");
            return 1;
        }
    }
    return 0;
}

Produto inserir(void){
    int codigoOk=0;
    Produto item;
    printf("\n");
    printf("Digite o nome:");
    scanf("%s", &item.nome);
    
    while(codigoOk==0){
        codigoOk=1;
        printf("Digite Código:");
        scanf("%d", &item.codigo);
        for (int i=0;i<poslivre;i++){
            if(estoque[i].codigo==item.codigo){
                printf("\n");
                printf("Código já cadastrado. Por favor repita o processo.\n");
                codigoOk=0;
            }
        }
    }
    printf("Digite a quantidade:");
    scanf("%d", &item.quantidade);
    printf("Digite a preço:");
    scanf("%f", &item.preco);
    printf("\n");
  
    
    return item; 
}

int listar(void){
    
    int i=0;
    for (i=0;i<poslivre;i++){
        printf("\n");
        printf("Item %s ", estoque[i].nome);
        printf("Preço %f ", estoque[i].preco);
        printf("Quantidade %d ", estoque[i].quantidade);
        printf("Código %d ", estoque[i].codigo);
        printf("\n");
    }
    return 0;
}

int main(void){
    int opcao=0;
    while(opcao!=5){
        

        printf("\n=== Menu de opcoes ===\n");
        printf("1.Inserir produto\n");
        printf("2.Listar produtos\n");
        printf("3.Buscar produto\n");
        printf("4.excluir produto\n");
        printf("5.sair\n");

        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
           
            estoque[poslivre]=inserir();
            poslivre++;
            printf("item inserido!");

            break;
        
            case 2:

            listar();

            break;
        
            case 3:

            buscar();

            break;

            case 4:

            excluir();
            

            break;
        
            case 5:

            break;

            break;
        
            default:
            
            break;
        }
    }
    
    return 0;
}

