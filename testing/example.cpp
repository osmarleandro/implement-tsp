#include <iostream>
//#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

/* Autor
   Alvaro Nayder
   http://aprendendocmais.blogspot.com.br/
*/

class grafos
{
private:
  struct dadosCidade
  {
    char nome[50];
    int marca;
  };

  dadosCidade cidade[10];
  int quantCidade;
  struct dadosMatrix
  {
    int peso;
    int marca;
  };

  dadosMatrix matrix[10][10];
  int linha, coluna;

public:
  grafos();
  ~grafos();

  void incluirVertice();
  void incluirAresta();
  void mostrarGrafo();
  void vizinhoProximo();
  void encherMatrix4();
  void encherMatrix5();
  void mostrarCidades();
  void reiniciarGrafo();
};

grafos::grafos() // contrutora
{

  quantCidade = 0;

  for (linha = 0; linha < 10; linha++)
  {
    for (coluna = 0; coluna < 10; coluna++)
    {
      matrix[linha][coluna].peso = 0;
      matrix[linha][coluna].marca = 0;
    }
  }
}

grafos::~grafos() // destrutora
{
}

void grafos::incluirVertice()
{

  fflush(stdin);
  cout << "\nDigite o Nome da Cidade : ";
  gets(cidade[quantCidade].nome);
  cidade[quantCidade].marca = 0;

  quantCidade++;

  cout << endl
       << "Cidade cadastrada com sucesso.\n\n";
}

void grafos::incluirAresta()
{

  char aux[50];
  int posVetor1, posVetor2;
  int distancia;

  if (quantCidade < 2)
  {
    cout << "\n Nao e possivel criar uma Aresta com menos de 2 vertices cadastradas.";
  }

  else
  {
    cout << "\nLista de Cidades";
    cout << "\n- - - - - - - - -";
    mostrarCidades(); //mostra as cidades, facilita escolha.
    cout << "\n- - - - - - - - -";

    fflush(stdin);
    cout << "\nDigite o nome da primeira cidade.";
    gets(aux);

    for (int i = 0; i < quantCidade; i++)
    {
      if (strcmp(aux, cidade[i].nome) == 0)
      {
        posVetor1 = i;
        break;
      }
    }

    fflush(stdin);
    cout << "\nDigite o nome da segunda cidade.";
    gets(aux);

    for (int i = 0; i < quantCidade; i++)
    {
      if (strcmp(aux, cidade[i].nome) == 0)
      {
        posVetor2 = i;
        break;
      }
    }

    cout << "\nDigite a distancia entre as vertices.";
    cin >> distancia;

    matrix[posVetor1][posVetor2].peso = distancia; //ida e volta
    matrix[posVetor1][posVetor2].marca = 0;

    matrix[posVetor2][posVetor1].peso = distancia; //marca os dois lados da matrix
    matrix[posVetor2][posVetor1].marca = 0;

    cout << "\nAresta criada com sucesso!";
  }
}

void grafos::mostrarGrafo() // linha < quant cidade testar depois
{

  int aux = 0; //remover mensagem duplicada

  for (linha = 0; linha < 10; linha++) //anda nas linhas da matrix
  {
    aux++;                                    //remover mensagem duplicada
    for (coluna = aux; coluna < 10; coluna++) //anda nas colunas da matrix
    {
      if (matrix[linha][coluna].peso != 0) //se é dif 0, logo existe.
      {
        cout << cidade[linha].nome << " ate " << cidade[coluna].nome << " com " << matrix[linha][coluna].peso << "km. ";
      }
    }
    cout << endl;
  }
}

void grafos::vizinhoProximo() // o X da questão
{

  char aux[50];
  int cidadeAtual;
  int posMenor;
  int distanciaTotal = 0;
  int cidadeInicial;
  int menor;
  int quantCidadeMarcada = 1; //aqui tava 0
  int passouWhile = 0;

  cout << "\nLista de Cidades";

  cout << "\n- - - - - - - - -";

  mostrarCidades();

  cout << "\n- - - - - - - - -";

  fflush(stdin);
  cout << "\n\nDe qual cidade voce vai sair?";
  gets(aux);

  for (int i = 0; i < quantCidade; i++)
  {
    if (strcmp(aux, cidade[i].nome) == 0)
    {
      cidadeAtual = i; //local que esta a cidade, no vetor. posição tal do vetor.
      break;
    }
  }

  cidadeInicial = cidadeAtual; //utilizado para voltar na cidade inicial

  cout << "\nSaindo de " << cidade[cidadeInicial].nome << " passando por "; //mensagem(1/3)

  while (passouWhile != quantCidade) //roda 1x a cada cidade existente
  {
    passouWhile++;
    menor = 999;

    for (coluna = 0; coluna < 10; coluna++) //anda nas colunas da matrix
    {
      if (matrix[cidadeAtual][coluna].peso < menor && matrix[cidadeAtual][coluna].peso != 0 && matrix[cidadeAtual][coluna].marca != 1) //descubro o menor da linha. se for 0 ignora ele.
      {
        if (cidade[coluna].marca != 1) //testo se a menor aresta, me leva para um cidade que ja visitei.
        {
          menor = matrix[cidadeAtual][coluna].peso;
          posMenor = coluna;
        }

        else //o pulo do gato acontece aqui.
        {
          if (coluna == cidadeInicial && quantCidadeMarcada == quantCidade) //se a cidade marcada, for igual a inicial, pode. e todas as outras ja tiverem cido visitadas
          {
            menor = matrix[cidadeAtual][coluna].peso;
            posMenor = coluna;
          }
        }
      }
    }

    cout << cidade[posMenor].nome << ","; //mensagem(2/3)

    matrix[cidadeAtual][posMenor].marca = 1; //marquei aresta como visitada.                                        // aresta=estrada  //vertice = cidade
    cidade[cidadeAtual].marca = 1;           //marquei vertice como visitada

    quantCidadeMarcada++; //descobrir quantas cidades marcadas, para sair do while

    cidadeAtual = posMenor; //cidade atual recebe n° da linha da cidade que estou no momento

    distanciaTotal = distanciaTotal + menor;

  } //fecha while

  cout << " a distancia total foi: " << distanciaTotal << "."; //mensagem(3/3)

  for (coluna = 0; coluna < 10; coluna++) // retira marca de visitada da aresta (para poder rodar denovo)
  {
    for (linha = 0; linha < 10; linha++)
    {
      matrix[coluna][linha].marca = 0;
    }
  }

  for (int i = 0; i < quantCidade; i++) //retira marca das cidades visitadas (para poder rodar denovo)
  {
    cidade[i].marca = 0;
  }
}

void grafos::encherMatrix4() //metodo para facilitar teste, enche matrix com grafo completo de 4(A,B,C,D) vertices e 6 arestas(10,20,30,40,50,60)
{
  //vertices

  char aux[50];

  quantCidade = 0; //zero caso rodar 2x

  for (int i = 0; i < 4; i++)
  {
    fflush(stdin);
    cout << "\nNome da Cidade " << i + 1 << " de 4. ";
    gets(cidade[quantCidade].nome);

    cidade[quantCidade].marca = 0;
    quantCidade++;
  }

  //arestas

  matrix[0][1].peso = 10;
  matrix[0][1].marca = 0;

  matrix[1][0].peso = 10;
  matrix[1][0].marca = 0;

  matrix[0][2].peso = 20;
  matrix[0][2].marca = 0;

  matrix[2][0].peso = 20;
  matrix[2][0].marca = 0;

  matrix[0][3].peso = 30;
  matrix[0][3].marca = 0;

  matrix[3][0].peso = 30;
  matrix[3][0].marca = 0;

  matrix[1][2].peso = 40;
  matrix[1][2].marca = 0;

  matrix[2][1].peso = 40;
  matrix[2][1].marca = 0;

  matrix[1][3].peso = 50;
  matrix[1][3].marca = 0;

  matrix[3][1].peso = 50;
  matrix[3][1].marca = 0;

  matrix[2][3].peso = 60;
  matrix[2][3].marca = 0;

  matrix[3][2].peso = 60;
  matrix[3][2].marca = 0;
}

void grafos::encherMatrix5() //metodo para facilitar teste, enche matrix com grafo completo de 5(A,B,C,D,X) vertices e 10 arestas
{
  //vertices

  char aux[50];

  quantCidade = 0; //zero caso rodar 2x

  for (int i = 0; i < 5; i++)
  {
    fflush(stdin);
    cout << "\nNome da Cidade " << i + 1 << " de 5. ";
    gets(cidade[quantCidade].nome);

    cidade[quantCidade].marca = 0;
    quantCidade++;
  }

  //arestas

  matrix[0][1].peso = 10;
  matrix[0][1].marca = 0;

  matrix[1][0].peso = 10;
  matrix[1][0].marca = 0;

  matrix[0][2].peso = 20;
  matrix[0][2].marca = 0;

  matrix[2][0].peso = 20;
  matrix[2][0].marca = 0;

  matrix[0][3].peso = 30;
  matrix[0][3].marca = 0;

  matrix[3][0].peso = 30;
  matrix[3][0].marca = 0;

  matrix[1][2].peso = 40;
  matrix[1][2].marca = 0;

  matrix[2][1].peso = 40;
  matrix[2][1].marca = 0;

  matrix[1][3].peso = 50;
  matrix[1][3].marca = 0;

  matrix[3][1].peso = 50;
  matrix[3][1].marca = 0;

  matrix[2][3].peso = 60;
  matrix[2][3].marca = 0;

  matrix[3][2].peso = 60;
  matrix[3][2].marca = 0;

  //o quinto elemento

  matrix[4][0].peso = 70;
  matrix[4][0].marca = 0;

  matrix[0][4].peso = 70;
  matrix[0][4].marca = 0;

  matrix[4][1].peso = 80;
  matrix[4][1].marca = 0;

  matrix[1][4].peso = 80;
  matrix[1][4].marca = 0;

  matrix[4][2].peso = 90;
  matrix[4][2].marca = 0;

  matrix[2][4].peso = 90;
  matrix[2][4].marca = 0;

  matrix[4][3].peso = 100;
  matrix[4][3].marca = 0;

  matrix[3][4].peso = 100;
  matrix[3][4].marca = 0;
}

void grafos::mostrarCidades()
{

  if (quantCidade == 0)
  {
    cout << "Nenhuma cidade cadastrada.";
  }
  else
  {
    for (int i = 0; i < quantCidade; i++)
    {
      cout << endl
           << cidade[i].nome;
    }
  }
}

void grafos::reiniciarGrafo()
{

  for (linha = 0; linha < 10; linha++) //zera a matrix
  {
    for (coluna = 0; coluna < 10; coluna++)
    {
      matrix[linha][coluna].peso = 0;
      matrix[linha][coluna].marca = 0;
    }
  }

  for (int i = 0; i < quantCidade; i++) //retira marca das cidades visitadas
  {
    cidade[i].marca = 0;
  }

  quantCidade = 0; //zera as cidades
}

int main()
{

  grafos obj;
  int op;

  do
  {
    system("cls");
    cout << "\n\n\t\t\t\t Trabalho de Grafos\n";
    cout << "\n1) Incluir Vertice";   // obj.incluirVertice
    cout << "\n\n2) Incluir Aresta";  //obj.incluirAresta
    cout << "\n\n3) Mostrar Grafo";   //obj.mostrarGrafo
    cout << "\n\n4) Vizinho Proximo"; //obj.vizinhoProximo
    cout << "\n\n5) Mostrar Cidades"; //obj.mostrarCidades
    cout << "\n\n6) Reiniciar Grafo"; //obj.reiniciarGrafo
    cout << "\n\n7) Sair";
    cout << "\n\n- - - - - - - - - - ";
    cout << "\n\n10) Encher Matrix - Grafo completo com 4 vertices";   //obj.encherMatrix4
    cout << "\n\n20) Encher Matrix - Grafo completo com 5 vertices\n"; //obj.encherMatrix5
    cout << "\nDigite a opcao.";
    cout << endl;

    cin >> op;

    switch (op)
    {
    case 1:
      obj.incluirVertice();
      getch();
      break;
    case 2:
      obj.incluirAresta();
      getch();
      break;
    case 3:
      obj.mostrarGrafo();
      getch();
      break;
    case 4:
      obj.vizinhoProximo();
      getch();
      break;
    case 5:
      obj.mostrarCidades();
      getch();
      break;
    case 6:
      obj.reiniciarGrafo();
      getch();
      break;
    case 10:
      obj.encherMatrix4();
      getch();
      break;
    case 20:
      obj.encherMatrix5();
      getch();
      break;

    } // fecha switch
  }   // fecha do
  while (op != 7);
} // fecha main