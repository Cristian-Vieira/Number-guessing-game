#include <iostream> // Biblioteca para entrada e saída de dados
#include <cstdlib>  // Biblioteca padrão do C, contem funções utilitarias
#include <ctime>    // Biblioteca para trabalhar com tempo e gerar numeros aleatorios
#include <chrono>   // Biblioteca para manipulação de tempo
#include <thread>   // Biblioteca para usar a função sleep_for (para o atraso)
#include <limits>   // Biblioteca para manipulação de limites numericos
#include <cstdlib>  // Biblioteca para usar a função exit()

using namespace std;

const int MINIMO = 1;   // Valor mínimo para o numero aleatorio
const int MAXIMO = 100; // Valor maximo para o numero aleatorio

// Função para gerar um numero aleatorio entre MINIMO e MAXIMO
int gerarNumeroAleatorio()
{
    return rand() % (MAXIMO - MINIMO + 1) + MINIMO;
}

// Função para a jogada do usuario
void jogarUsuario(int numeroAleatorio, int &tentativasUsuario)
{
    int palpite;

    cout << "\n\nVEZ DO USUARIO ADVINHAR!!!\n\n";

    do
    {
        tentativasUsuario++;
        cout << "Adivinhe o valor que foi gerado pelo computador aleatoriamente entre "
             << MINIMO << " e " << MAXIMO << ": ";

      
        while (!(cin >> palpite))
        {
            cout << "\nEntrada invalida! Por favor, insira um valor numerico.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (palpite > numeroAleatorio)
        {
            cout << "\nO numero sorteado e menor que " << palpite << "\n\n";
        }
        else if (palpite < numeroAleatorio)
        {
            cout << "\nO numero sorteado e maior que " << palpite << "\n\n";
        }
        else
        {
            cout << "\n\nParabens! Voce acertou o numero em " << tentativasUsuario << " tentativas!\n\n";
        }
    } while (palpite != numeroAleatorio);
}

// Função para o palpite do computador
void jogarComputador(int, int &tentativasComputador)
{
    cout << "VEZ DO COMPUTADOR ADIVINHAR!!!\n\n";
    cout << "Sua vez de pensar em um numero aleatorio entre " << MINIMO << " e " << MAXIMO << "\n\n";
    cout << "Aguarde, o computador esta pensando em um palpite!!\n\n";

    this_thread::sleep_for(chrono::milliseconds(7000)); // Delay de 7 segundos

    int inicio = MINIMO, fim = MAXIMO, meio;

    while (inicio <= fim)
    {
        tentativasComputador++;
        meio = (inicio + fim) / 2;
        cout << "\n\nPalpite do computador: " << meio << "\n";
        cout << "\n\nDigite 1 caso o computador tenha acertado\n";
        cout << "Digite 2 caso o numero que voce pensou seja maior\n";
        cout << "Digite 3 caso o numero que voce pensou seja menor: ";

        int palpite;
     
        while (!(cin >> palpite) || palpite < 1 || palpite > 3)
        {
            cout << "\n\nEntrada invalida! Por favor, digite um valor entre 1 e 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (palpite == 2)
        {
            inicio = meio + 1;
        }
        else if (palpite == 3)
        {
            fim = meio - 1;
        }
        else
        {
            cout << "\n\nComputador acertou o numero em " << tentativasComputador << " tentativas!\n";
            return;
        }
    }
}

// Função para exibir o resultado do jogo
void exibirResultado(int tentativasUsuario, int tentativasComputador)
{
    cout << "\nUsuario acertou o numero em " << tentativasUsuario << " tentativas!\n";

    if (tentativasUsuario < tentativasComputador)
    {
        cout << "\nUSUARIO CAMPEAO do jogo com menos tentativas\n\n";
    }
    else if (tentativasUsuario > tentativasComputador)
    {
        cout << "\nCOMPUTADOR CAMPEAO do jogo com menos tentativas\n";
    }
    else
    {
        cout << "\nEMPATE entre usuario e computador\n";
    }
}


int main()
{
    cout << "\n\nJOGO DA ADVINHACAO";

    srand(time(NULL)); // Inicializa gerador de numeros aleatorios

    int tentativasUsuario = 0;
    int tentativasComputador = 0;

    int numeroAleatorio = gerarNumeroAleatorio();
    jogarUsuario(numeroAleatorio, tentativasUsuario);
    jogarComputador(numeroAleatorio, tentativasComputador);

    exibirResultado(tentativasUsuario, tentativasComputador);

    cout << "\nFIM DE JOGO!!!\n";

    char restartOrNot;

    cout << "\nDeseja jogar novamente? (s/n)\n";
    cin >> restartOrNot;

    if (restartOrNot == 's' || restartOrNot == 'S')
    {
        return main();
    }
    else if (restartOrNot == 'n' || restartOrNot == 'N')
    {
        exit(0);
    }
    else
    {
        exit(0);
    };
}
