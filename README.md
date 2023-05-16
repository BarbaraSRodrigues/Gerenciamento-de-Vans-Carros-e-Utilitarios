# Gerenciamento-de-vans-carros-e-utilitarios
Trabalho feito em C++ para a matéria de Algoritmo e Estrutura de Dados II, onde a nota foi 90 de 100. Esse repositório está com correções feitas no código para atingir a nota máxima.


**Objetivo:** adquirir conhecimentos de manipulação de lista com alocação contínua (vetores) numa aplicação que manipula informações de veículos de um site de busca para compra e venda.

**Descrição:** o aplicativo desenvolvido no projeto deve gerenciar listas de veículos em vetores de ponteiros para registros (structs). Cada linha do arquivo de entrada ou saída deve conter informações de apenas um veículo, conforme o modelo apresentado no arquivo-texto de exemplo “BD_veículos.txt”. Uma lista geral deve ser criada seguindo a ordem apresentada no arquivo-texto, e novas listas devem ser criadas para ação quando for necessário. Além disso, também devem ser implementadas as funções de inserção e remoção de veículos na lista principal, e novas listas quando necessário. Os vetores devem ter o limite máximo de 50 elementos. Ao final da execução, os dados devem ser escritos novamente no arquivo-texto.

**Arquivo de Clientes:** conterá um número máximo de 50 linhas, onde cada linha conterá 13 campos: modelo, marca, tipo, ano, quilometragem, potência do motor, combustível, câmbio, direção, cor, número de portas, placa e valor do veículo.

**Requisitos:** o aplicativo deverá:
- apresentar um menu ao usuário com as opções de inclusão, 2 buscas e ordenação;

- inicialmente a lista deverá ser mantida na memória num vetor de ponteiros de registros (structs) na ordem de leitura do arquivo-texto;

**Operações de busca:**
- busca de algum veículo pela placa, com opção de exclusão quando o veículo for encontrado;

- busca dos 10 veículos mais próximos: o usuário deverá entrar com um valor de compra e o resultado deve ser no máximo os 10 veículos com valores mais próximos, na ordem do mais próximo até o mais distante do valor;
 
a operação de ordenação consiste em criar um segundo vetor de ponteiros de registros (structs) de 50 posições que aponta para os registros já alocados na leitura do arquivo-texto mas na ordem crescente indicados pelas placas dos veículos.
