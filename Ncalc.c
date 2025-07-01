#include <linux/limits.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        //Inicializando e montando os dados
        typedef struct
        {
            char *name;
            int acertos;
            int erros;
            int valor;
        }
        compenent;
        compenent materia[argc - 1];

        for (int i= 0; i < argc; i++)
        {
            //Configuração de nome
            //materia[i].name = malloc(sizeof(char) * 16);
            materia[i].name = argv[i+1];
            // Numerais
            materia[i].acertos = 0;
            materia[i].erros = 0;
            materia[i].valor = 0;
        }
        //Perguntando e amazenando
        for (int i = 0; i < argc - 1; i++)
        {
            printf("Correct answers for %s subject: ", materia[i].name);
            scanf("%i", &materia[i].acertos);
            printf("Wrong answers for %s subject: ", materia[i].name);
            scanf("%i", &materia[i].erros);
            printf("\n");
        }
        for (int i = 0; i < argc - 1; i++)
        {
            materia[i].valor = (materia[i].acertos + materia[i].erros);
        }
        //Cálculo
        int total[2]= {0,0}; //0 pelo todo e 1 pelo total de acertos
        for (int i = 0; i < argc -1; i++)
        {
            total[0] += materia[i].valor;
            total[1] += materia[i].acertos;
        }
        //Resultado final
        printf("        --[Yield]--\n\n");
        for (int i = 0; i < argc - 1; i++)
        {
            printf("    %s: %i%%\n", materia[i].name, (100*materia[i].acertos)/materia[i].valor);
        }

        printf("    All: %i%%\n", (total[1]*100)/total[0]);

        //Eggs
        if ((total[1]*100)/total[0] > 50) printf("\n Proud of mom!! :3 \n");
        if ((total[1]*100)/total[0] < 50) printf("\n Please, don't punch me mom T-T \n");

        return 1;
    }
    else
    {
        printf("More entries needed... \n");
        return 0;
    }
}
