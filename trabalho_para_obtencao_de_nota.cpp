/*
Aluno: Hebert Spitzer    RA:N956585
Curso: Analise e Desenvolvimento de sistemas
2ºsemestre
Unip Alphaville
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

//declarando as structs
typedef struct {
	int dia, mes, ano;
}Validade;

typedef struct {
	char SKU[20];
	char nome[35];
	float valor;
	float peso;
	int quantidadeDisponivel;
	Validade validade;
}Produto;

//declarando as funções
void CriaCadastroProduto();
void ListaProdutos();

int main(){
	//configurando para aceitar virgula no float
	setlocale(LC_NUMERIC, "pt_BR");
	
	//configurando para imprimir acentos
    setlocale(LC_ALL, "Portuguese");
    
    //declaração da variavel que seleciona a opção do menu
    int select;
    
    printf("\nsistema para cadastrar e consultar produtos \n\n\n");
    
	//Menu de seleção
	do{
 	    printf("1 - Adicionar um produto\n");
   		printf("2 - Consultar produtos\n");
   		printf("0 - Sair do sistema\n");

    	printf("Digite o numero da opção desejada:");
    	scanf("%d",&select);
    	
    	switch (select)
    	{
    	case 1:
    		//Chamando a função CriaCadastroProduto
    		system("cls");
    		CriaCadastroProduto();
        	break;
    	case 2:
    		//Chamando a função ListaClientes
    		system("cls");
    		ListaProdutos();
        	break;
    	default:
        	break;
    	}
    	
    	//verificando existe opção para o numero digitado 
    	if(select < 0 || select > 2){
    		system("cls");
        	printf("\n\n*********O número da opção não e valido*********\n\n\n");
	    	}
	//fechando o programa apenas se o seletor for igual a 0
	}while (select != 0);
	
	system("cls");
	printf("Sistema feito pelo aluno\nHebert Spitzer   RA:N956585\ncurso: Analise e desenvolvimento de sistemas\n2ºsemestre\nUnip Alphaville");
}


void CriaCadastroProduto() {
	
	//abrindo ou criando o arquivo txt e verificando se foi aberto corretamente
	FILE *farq = fopen("produtos.txt", "a");
	if(farq == NULL){
		exit(0);
	}
	
	//declaração das variaveis que serão utilizadas
	Produto tproduto;
	Validade tvalidade;
	char tstring[35];
	
	//entrada do SKU do produto
	printf("Digite o SKU do produto: ");
	scanf( "%19s", tproduto.SKU);
	fflush(stdin);
	system("cls");
	
	//entrada do nome do produto
	printf("Digite o nome do produto: ");
	fgets(tproduto.nome, sizeof(tproduto.nome), stdin);
	fflush(stdin);
	system("cls");
	
	//tratamento do nome do produto alterando o espaço por "_" e salvando em outra string
	for(int i = 0; i < 35; i++) {
        if (tproduto.nome[i] == ' '){
        	tstring[i] = '_';
		}else if(tproduto.nome[i] == '\n'){
        	tstring[i] = '\0';
        }else{
        	tstring[i] = tproduto.nome[i];
		}
    }
	
	//entrada do valor do produto
	do{
	printf("Digite o valor do produto: ");
	scanf( "%f", &tproduto.valor);
	fflush(stdin);
	system("cls");
	if(tproduto.valor < 0) {
		printf("\n\n**********Valor invalido, certifique que esta digitando o valor corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tproduto.valor < 0);

	//entrada do peso do produto
	do{
	printf("Digite o peso do produto em kilos: ");
	scanf( "%f", &tproduto.peso);
	fflush(stdin);
	system("cls");
	if(tproduto.peso < 0) {
		printf("\n\n**********Valor invalido, certifique que esta digitando o peso corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tproduto.peso < 0);
	
	//entrada da quantidade de produtos disponiveis
	do{
	printf("Digite a quantidade disponivel do produto: ");
	scanf( "%d", &tproduto.quantidadeDisponivel);
	fflush(stdin);
	system("cls");
	if(tproduto.quantidadeDisponivel < 0) {
		printf("\n\n**********Valor invalido, certifique que esta digitando a quantidade corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tproduto.quantidadeDisponivel < 0);

	//entrada do dia de vencimento
	do{
	printf("Digite o dia de vencimento: ");
	scanf( "%d", &tvalidade.dia);
	fflush(stdin);
	system("cls");
	if(tvalidade.dia < 1 || tvalidade.dia > 31) {
		printf("\n\n**********Valor invalido, certifique que esta digitando o dia corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tvalidade.dia > 31 || tvalidade.dia < 1);
	
	//entrada do mes de vencimento
	do{
	printf("Digite o mes de vencimento: ");
	scanf( "%d", &tvalidade.mes);
	fflush(stdin);
	system("cls");
	if(tvalidade.mes < 1 || tvalidade.mes > 12) {
		printf("\n\n**********Valor invalido, certifique que esta digitando o mes corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tvalidade.mes > 12 || tvalidade.mes < 1);
	
	//entrada do ano de vencimento
	do{
	printf("Digite o ano de vencimento: ");
	scanf( "%d", &tvalidade.ano);
	fflush(stdin);
	system("cls");
	if(tvalidade.ano < 2022) {
		printf("\n\n**********Pelo ano informado o produto esta vencido e não é possivel cadastrar produtos vencidos, certifique que esta digitando o ano corretamente**********\n\n DIGITE NOVAMENTE\n");
	}
	}while(tvalidade.ano < 2022);
	
	//imprimindo as infos do produto
	printf("\n\n\t------Produto adicionado com sucesso------\n");
	printf("SKU: %s\n",tproduto.SKU);
	printf("Nome: %s",tproduto.nome);
	printf("Valor: R$%.2f\n",tproduto.valor);
	printf("Peso: %.3fkg\n",tproduto.peso);
	printf("Quantidade disponivel: %d\n",tproduto.quantidadeDisponivel);
	printf("Validade: %d/%d/%d",tvalidade.dia, tvalidade.mes, tvalidade.ano);
	printf("\n\t-------------------------------------------\n\n\n");
	
	//salvando as infos do produto no arquivo txt e fechando o arquivo
	fprintf(farq, "\n%s %s %f %f %d %d %d %d", tproduto.SKU, tstring, tproduto.valor, tproduto.peso, tproduto.quantidadeDisponivel, tvalidade.dia, tvalidade.mes, tvalidade.ano);
	fclose(farq);
}

void ListaProdutos(){
	//abrindo ou criando o arquivo txt e verificando se foi aberto corretamente
	FILE *farq = fopen("produtos.txt", "r+b");
	if(farq == NULL){
		exit(0);
	}
	
	//posicionando no inicio do arquivo txt
	fseek(farq, 0, SEEK_SET);
	
	//lendo todas as infos do arquivo até chegar ao fim do arquivo
	while(!feof(farq)){
		//declaração da variaveis que serão utilizadas
		Produto tproduto;
		Validade tvalidade;
		char tstring[35];
		
		//lendo o arquivo e salvando em um var do tipo Produto
		fscanf(farq, "%s %s %f %f %d %d %d %d", tproduto.SKU, tproduto.nome, &tproduto.valor, &tproduto.peso, &tproduto.quantidadeDisponivel, &tvalidade.dia, &tvalidade.mes, &tvalidade.ano);
		
		//tratando o nome do produto, trocando o "_" por espaço
		for(int i = 0; i < 35; i++) {
        if (tproduto.nome[i] == '_'){
        	tstring[i] = ' ';
		}else{
        	tstring[i] = tproduto.nome[i];
		}
    	}
		
		//imprimindo as infos do produto
		printf("\n--------------------------------\n");
		printf("SKU: %s\n",tproduto.SKU);
		printf("Nome: %s\n",tstring);
		printf("Valor: R$%.2f\n",tproduto.valor);
		printf("Peso: %.3fkg\n",tproduto.peso);
		printf("Quantidade disponivel: %d\n",tproduto.quantidadeDisponivel);
		printf("Validade: %d/%d/%d\n\n\n",tvalidade.dia, tvalidade.mes, tvalidade.ano);
	}
	//fechando o arquivo
	fclose(farq);
}
