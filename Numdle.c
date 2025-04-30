#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>
int main()
{
    setlocale(LC_ALL,"portuguese");
    int cod,resp,i,jogar=1,certos,c1,c2,c3,c4,r1,r2,r3,r4,dica;
    printf("\tBem-vindo ao Numdle\n");
    printf("O jogo em que você tem que tentar adivinhar a sequência secreta de numeros, entre 1000 e 9999, para vencer, em 10 tentativas.\n\n - Quando você acertar o valor, o número será mostrado.\n - Se você errar o número, porém, ele está presente na sequência secreta, o número será mostrado entre parenteses.\n - Mas se estiver completamente errado, mostrará _ (underline).\n - Na quinta rodada, uma dica irá aparecer dizendo, caso algum número estiver errado, se é par ou impar.\n");
    system("pause");
    system("cls");
    while(jogar==1)
    {
      srand(time(NULL));
      cod=rand()%9000+1000;
      c1=cod/1000;
      c2=(cod/100)%10;
      c3=(cod/10)%10;
      c4=cod%10;
      dica=0;

      for(i=1;i<=10;i++)
        {
            printf("Tentativa %d: ",i);
            scanf("%d",&resp);

            if(resp<1000 || resp>9999)
            {
                printf("\nNúmero inválido!\nDigite entre 1000 e 9999.\n\n");
                i--;
                continue;
            }
            r1=resp/1000;
            r2=(resp/100)%10;
            r3=(resp/10)%10;
            r4=resp%10;
            certos=0;
            if(r1==c1)
            {
                printf("%d ",r1);
                certos++;
            }
            else if(i>=5 && r1!=c1 && dica==0 || dica==1)
            {
                if (c1%2==0)
                {
                    printf("PAR");
                }
                else
                {
                    printf("IMPAR");
                }
                dica=1;
            }
            else if(r1==c2 && r1!=r2 || r1==c3 && r1!=r3 || r1==c4 && r1!=r4)
            {
                printf("(%d) ",r1);
            }
            else
            {
                printf(" _ ");
            }

            if(r2==c2)
            {
                printf("%d ",r2);
                certos++;
            }
            else if(i>=5 && r2!=c2 && dica==0 || dica==2)
            {
                if (c2%2==0)
                {
                    printf("PAR");
                }
                else
                {
                    printf("IMPAR");
                }
                dica=2;
            }
            else if(r2==c1 && r1!=c1 || r2==c3 && r3!=c3 || r2==c4 && r4!=c4)
            {
                printf("(%d) ",r2);
            }
            else
            {
                printf(" _ ");
            }

            if(r3==c3)
            {
                printf("%d ",r3);
                certos++;
            }
            else if(i>=5 && r3!=c3 && dica==0 || dica==3)
            {
                if (c3%2==0)
                {
                    printf("PAR");
                }
                else
                {
                    printf("IMPAR");
                }
                dica=3;
            }
            else if(r3==c1 && r1!=c1 || r3==c2 && r2!=c2 || r3==c4 && r4!=c4)
            {
                printf("(%d) ",r3);
            }
            else
            {
                printf(" _ ");
            }

            if(r4==c4)
            {
                printf("%d\n",r4);
                certos++;
            }
            else if(i>=5 && r4!=c4 && dica==0 || dica==4)
            {
                if (c4%2==0)
                {
                    printf("PAR");
                }
                else
                {
                    printf("IMPAR");
                }
                dica=4;
            }
            else if(r4==c1 && r1!=c1 || r4==c2 && r2!=c2 || r4==c3 && r3!=c3)
            {
                printf("(%d)\n",r4);
            }
            else
            {
                printf(" _ \n");
            }
        
            printf("\nVocê acertou %d digito(s) nessa tentativa!\n\n",certos);
        
            if(certos==4)
            {   
                system("cls");
                printf("Parabéns! Você acertou o código: %d na tentativa: %d!\n",cod,i);
                break;
            }
        }
        if(certos!=4)
        {
            system("cls");
            printf("Você perdeu :( O número era %d.\n",cod);
        }
        printf("\nquer jogar de novo?\n1=SIM\n0=NÃO\n: ");
        scanf("%d",&jogar);
        system("cls");
    }
    for(i=3;i>0;i--)
    {
        system("cls");
        printf("\n\t      /");
        printf("\n\t(^ ^)/");
        printf("\nBYE BYE!!!");
        usleep(500000);
        system("cls");
        printf("\n\t     \\");
        printf("\n\t(^ ^)/");
        printf("\nBYE BYE!!!");
        usleep(500000);
        system("cls");
    }
	return 0;
}
