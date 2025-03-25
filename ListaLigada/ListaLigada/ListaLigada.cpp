
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* aux = primeiro; //verifica se já tem o valor
	while (aux->prox != NULL) {
		if (aux->valor == novo->valor) {
			cout << "Elemento " << novo->valor << " ja existe na lista, digite outo elemento. \n";
			free(novo); // libera a memória para o novo nó
			return;
		}
		aux = aux->prox;
	}

	if (primeiro == NULL) //se a lista estivar vazia, insere novo elemento como primeiro
	{
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro; // procura o final da lista
		while (aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}


void buscarElemento()
{
	int valor;
	cout << "Digite um valor a ser buscado: ";
	cin >> valor;

	NO* resultado = posicaoElemento(valor);

	if (resultado != NULL)
	{
		cout << "Elemento " << valor << " encontrado. \n";
		return;
	}

	else
	{
		cout << "Elemento " << valor << " nao encontrado. \n";
		return;
	}

}


void excluirElemento()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia! Nao ha elementos para excluir. \n";
		return;
	}

	int valor;
	cout << "Digite o valor a ser excluido: ";
	cin >> valor;

	NO* aux = posicaoElemento(valor);
	NO* anterior = NULL;

	while (aux != NULL && aux->valor != valor) // busca elemento
	{
		anterior = aux;
		aux = aux->prox;
	}

	if (aux == NULL) // nao encontrado
	{
		cout << "Elemento " << valor << " nao encontrado. \n";
		return;
	}

	if (anterior == NULL)
	{
		primeiro = aux->prox; //atualiza o primeiro nó
	}

	else
	{
		anterior->prox = aux->prox; //remove o nó
	}

	free(aux); //libera memória
	cout << "Elemento " << valor << " excluido com sucesso. \n";
	return;
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}