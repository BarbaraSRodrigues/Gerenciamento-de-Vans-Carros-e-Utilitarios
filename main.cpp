/*
 Esse projeto trabalha com listas sequenciais para o gerenciamento de carros, vans e utilitarios. E possivel remover, buscar, inserir, lista(ordenado)
 e faz uma busca onde acha os 10 valores proximos do valor digitado pelo usuario.
 
 Materia: Algoritmo e Estrutura de Dados II
 Aluna: Barbara Silveira Rodrigues
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct 
{
    string modelo;
    string marca;
    string tipo;
    int ano;
    int km;
    float potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;
    string placa;
    float valor;
}Tveiculo;

int busca(Tveiculo *bd[], int tam, string x)
{
    for(int i = 0; i < tam; i++)
    {
        if(bd[i]->placa == x)
        {
            return i; // Retorna o indice onde encontrou o veiculo
        }
    }
    return -1;
}

int remove(Tveiculo *bd[], int tam, string x)
{
    int pos;
    
    pos = busca(bd, tam, x); // pos recebe o valor retornado da chamada da funcao busca
    
    if(pos == -1) // Placa nao encontrada
    {
        cout << "Nao ha veiculo" << endl;
        return -1;
    } else { // Placa encontrada
        for(int j = pos; j < tam-1; j++) // Vai percorrer ate a pos encontrada
        {
            bd[j] = bd[j+1]; // Escreve o banco de dados novamente, escrevendo por cima da struct que sera removida 
        }
     delete(bd[j]);
        return 0;
    }    
}

Tveiculo *auxStruct(string placa) // os valores digitados pelo usuario serao armazenados para depois serem usados no insere
{
    Tveiculo *auxS = new Tveiculo;
    cout << "Digite o modelo: " << endl;
    cin >> auxS->modelo;
    cout << "Digite a marca: " << endl;
    cin >> auxS->marca;
    cout << "Digite o tipo: " << endl;
    cin >> auxS->tipo;
    cout << "Digite o ano: " << endl;
    cin >> auxS->ano;
    cout << "Digite a km: " << endl;
    cin >> auxS->km;
    cout << "Digite a potencia: " << endl;
    cin >> auxS->potencia;
    cout << "Digite o combustivel: " << endl;
    cin >> auxS->combustivel;
    cout << "Digite o cambio: " << endl;
    cin >> auxS->cambio;
    cout << "Digite a direcao: " << endl;
    cin >> auxS->direcao;
    cout << "Digite a cor: " << endl;
    cin >> auxS->cor;
    cout << "Digite as portas: " << endl;
    cin >> auxS->portas;
    cout << "Digite o valor: " << endl;
    cin >> auxS->valor;
    cout << "A placa recebida será a digitada anteriormente" << endl;
    auxS->placa = placa;
    return auxS;
}

int insere(Tveiculo *bd[], int tam)
{
    string placadup;
    int rep;
            
        if(tam < 50) 
        {
            cout << "Digite a placa do veiculo" << endl;
            cin >> placadup;
                
            rep = busca(bd, tam, placadup);
            if(rep == -1)
            {
                Tveiculo *aux = auxStruct(placadup); // aux e uma variavel Tveiculo que vai armazenar o input do usuario digitado na funcao auxStruct
                bd[tam] = aux; // A ultima posicao recebe a aux
                return 1;
            } else {
                cout << "Veiculo duplicado" << endl;
                return -1;
            }
        } else {
            cout << "lista cheia" << endl;
            return 0;
        } 
}

void imprime(Tveiculo *bd[], int tam) // Imprime todo o banco de dados 
{
    for(int i = 0; i < tam; i++)
    {
        cout << bd[i]->modelo << " ";
        cout << bd[i]->marca << " ";
        cout << bd[i]->tipo << " ";
        cout << bd[i]->ano << " ";
        cout << bd[i]->km << " ";
        cout << bd[i]->potencia << " ";
        cout << bd[i]->combustivel << " ";
        cout << bd[i]->cambio << " ";
        cout << bd[i]->direcao << " ";
        cout << bd[i]->cor << " ";
        cout << bd[i]->portas << " ";
        cout << bd[i]->placa << " ";
        cout << bd[i]->valor << endl;
    }
}

void ordenacao(Tveiculo *bd[], Tveiculo*BDOrd[], int tam)
{
    for(int i = 0; i < 50; i++)
    {
      BDOrd[i] = bd[i];  // Reescreve todo o banco de dados para uma variavel Tveiculo que vai ser ordenada  
    }
    
    Tveiculo *aux; // Variavel auxiliar que vai receber uma struct do banco de dados bd
    for(int i = 0; i < tam; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(BDOrd[j]->placa < BDOrd[i]->placa) // Placa na pos J e menor que na pos I faz a inversao
            {
                aux = BDOrd[i];
                BDOrd[i] = BDOrd[j];
                BDOrd[j] = aux;          
            }
        }
    }
    imprime(BDOrd, tam);
}

void buscaProx(Tveiculo *bd[], int tam, float valor)
{
    float A[tam], aux;
    int temp, indice[tam];
    
    for(int i = 0; i < tam; i++) // Pega todas as diferencas dos valores dos veiculos e do valor dado 
    {
        A[i] = abs(valor - bd[i]->valor);
        indice[i] = i; // Pega os indices
    }
    
    for(int i = 0; i < tam; i++) // BubbleSort para ordenar o vetor de diferencas e puxa o indice
    {
        for(int j = i+1; j < tam; j++)
        {
            if(A[j] < A[i])
            {
                aux = A[i];
                temp = indice[i];
                A[i] = A[j];
                indice[i] = indice[j];
                A[j] = aux;
                indice[j] = temp;
            }
        }
    }
    
    int a;
    
    for(int i = 0; i < 10; i++) // Imprime os valores proximos 
    {
        a = indice[i];
        cout << bd[a]->modelo << " ";
        cout << bd[a]->marca << " ";
        cout << bd[a]->tipo << " ";
        cout << bd[a]->ano << " ";
        cout << bd[a]->km << " ";
        cout << bd[a]->potencia << " ";
        cout << bd[a]->combustivel << " ";
        cout << bd[a]->cambio << " ";
        cout << bd[a]->direcao << " ";
        cout << bd[a]->cor << " ";
        cout << bd[a]->portas << " ";
        cout << bd[a]->placa << " ";
        cout << bd[a]->valor << ".00" << endl;
    }
}


int main(int argc, char** argv)
{
    ifstream myfile ("BD_Veiculos.txt"); // ifstream read input from a file // cria a var myfile
    Tveiculo *BD[50]; // BD é um vetor de ponteiro para o tipo Tveiculo
    Tveiculo *BDOrd[50]; // BDOrd vai ser o BD ordenado
    int tam = 0;
    
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            BD[tam] = new Tveiculo;
            myfile >> BD[tam]->modelo;
            myfile >> BD[tam]->marca;
            myfile >> BD[tam]->tipo;
            myfile >> BD[tam]->ano;
            myfile >> BD[tam]->km;
            myfile >> BD[tam]->potencia;
            myfile >> BD[tam]->combustivel;
            myfile >> BD[tam]->cambio;
            myfile >> BD[tam]->direcao;
            myfile >> BD[tam]->cor;
            myfile >> BD[tam]->portas;
            myfile >> BD[tam]->placa;
            myfile >> BD[tam]->valor;
            tam++; 
        }
        tam--;
        myfile.close();       
    } else {
        cout << "Nao foi possivel abrir o arquivo";
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "Gerenciador de Carros, Vans e Utilitarios" << endl;
    cout << "-----------------------------------------" << endl;
    
    int opc;
    
    do
    {
        cout << "Escolha a funcionalidade que deseja: " << endl; // Usuário escolhe qual a funcionalidade deseja
        cout << "(1) Inserir" << endl;
        cout << "(2) Busca" << endl;
        cout << "(3) Busca dos veiculos com valores proximos" << endl;
        cout << "(4) Ordenacao" << endl;
        cout << "(0) Sair" << endl;
        cin >> opc; // Input do usuário
    
        switch(opc) // Switch case para cada funcionalidade do programa 
        {
            case 1: // Inserir
            {
                int aum;
            
                aum = insere(BD, tam);
            
                if(aum == 1)
                {
                    tam++; // Como foi inserida corretamente, o tamanho aumenta
                    cout << "Veiculo inserido" << endl;
                } else {
                    cout << "Nao foi inserido" << endl;
                }
            }    
            break;

            case 2: // Buscar
            {
                string placabus; // Recebe a placa buscada
                char opc2;

                cout << "Digite a placa do carro que deseja buscar" << endl;
                cin >> placabus;
        
                int p = busca(BD, tam, placabus); // p recebe o valor de busca
        
                if(p == -1) // Busca retornou -1 (nao ha esse veiculo)
                {
                    cout << "Nao foi encontrado" << endl;
                } else {
                    cout << "Veiculo encontrado" << endl;
                    cout<<  "Deseja excluir o veiculo? (s/n)" << endl; // Opcao para excluir o veiculo
                    cin >> opc2; 
                    if(opc2 == 's') // Veiculo buscado sera excluido
                    {
                        remove(BD, tam, placabus); // Pega como parametro a placa ja digitada e buscada anteriormente
                        tam--;
                        cout << "Veiculo excluido" << endl;
                    } else if(opc2 == 'n')
                    {
                        cout << "Veiculo nao sera excluido" << endl; 
                    } else { 
                        cout << "Digito invalido" << endl;
                    }
                }
            }    
            break;

            case 3: // Busca2
            {
                float valor;
            
                cout << "Digite o valor:" << endl; // Valor onde vai pegar os valores proximos dentro do banco de dados
                cin >> valor;
                buscaProx(BD, tam, valor);
            }    
            break;

            case 4: // Ordenacao
            {    
                ordenacao(BD, BDOrd, tam); // Ordena toda a lista
            }    
            break;
        
            case 0: // Usuário deseja sair
            {    
                cout << "Obrigada por usar!" << endl;
            }
            break;  

            default: // Usuário digita algo errado
            {  
                cout << "Digito invalido, tente novamente!" << endl;
            }
            break;
        }        
    } while(opc != 0); 
                
    rename("BD_Veiculos.txt", "BD_Backup.txt"); // O antigo arquivo agora sera o backup
            
    ofstream arquivo;
    arquivo.open("BD_Veiculos.txt", ios::out);
    
    if(arquivo.is_open())
    {
        for(int i = 0; i < tam; i++)
        {
            arquivo << BD[i]->modelo << " ";
            arquivo << BD[i]->marca << " ";
            arquivo << BD[i]->tipo << " ";
            arquivo << BD[i]->ano << " ";
            arquivo << BD[i]->km << " ";
            arquivo << BD[i]->potencia << " ";
            arquivo << BD[i]->combustivel << " ";
            arquivo << BD[i]->cambio << " ";
            arquivo << BD[i]->direcao << " ";
            arquivo << BD[i]->cor << " ";
            arquivo << BD[i]->portas << " ";
            arquivo << BD[i]->placa << " ";
            arquivo << BD[i]->valor << endl;
        }
    }
    arquivo.close();
    
    // Apontando os espacos vazios para NULL
    for(int i = tam; i < 50; i++) // Percorre apenas os espacos vazios
    {
        BD[i] = NULL; // Esta apontando para NULL todos os espacos que estao vazios 
    }
    
    for(int i = 0; i < 50; i++)
    {
        delete(BD[i]);
    }
    
    
    
    
    
    return 0;
}

