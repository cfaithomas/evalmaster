#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int mastersuite[4]; //suite mystère
char testresults[4]; //aide suite des symboles
int playersuite[4]; //proposition du joueur
int nbcoups=0; // compteur de coups
void computeMasterSuite(); //génère le nombre mystère 9999 max
void testbienplace(); //test les chiffres bien placés
void testmalplace(); //tes les chiffres présents mails mal placés
void afficheresultat(); //affiche les symboles
void  proposersuite(); //permet au joueur de proposer sa suite
bool  testgagne(); //test si gagné
void initestresult(); //rempli la suite d'aide avec les symboles par défaut XXXX
bool gagne=false; //flag de situation de jeu

void computeMasterSuite() {

    int r = rand()%9999+1;
    int c=3;
    while (r != 0)
    {
        mastersuite[c] = r % 10;
        r /= 10;
        c--;
    }

}

void testbienplace() {

    for(int j=0;j<4;j++)
    {

            if (playersuite[j] == mastersuite[j])
            {
                testresults[j] = '*';

            }

    }


}

void testmalplace() {
    for(int j=0;j<4;j++)
    {
        if(testresults[j]=='X') {
            for (int i = 0; i < 4; i++) {
                if (playersuite[j] == mastersuite[i]) {
                    testresults[j] = '-';
                    break;
                }
            }

        }
    }
}
void afficheMastersuite()
{
    for(int i=0;i<4;i++)
    {
        printf("%d",mastersuite[i]);
    }
    printf("\n");

}

void afficheresultat()
{
    for(int i=0;i<4;i++)
    {
        printf("%c",testresults[i]);
    }
    printf("\n");

}

void initestresult() {

    for(int i=0;i<4;i++)
    {
        testresults[i]='X';
    }

}

void proposerSuite()
{
    int choix=0;
    printf("Veuillez saisir une suite de 4 chiffres max\n");
    scanf("%d",&choix);
    int c=3;
    while (choix != 0)
    {
        playersuite[c] = choix % 10;
        choix /= 10;
        c--;
    }

}

void testgagner()
{
    if(testresults[0]=='*'&&testresults[1]=='*'&&testresults[2]=='*'&&testresults[3]=='*')
    {
        gagne=true;

    }
}



int main() {
    srand(time(NULL));
    computeMasterSuite();
    printf("Calcul de la master suite\n");
    //afficheMastersuite();
    while(nbcoups!=12&&!gagne)
    {

        initestresult();
        proposerSuite();

        testbienplace();
        testmalplace();
        testgagner();
        afficheresultat();
        nbcoups++;
    }
    if(gagne)
    {
        printf("Vous avez gagné\n");
    }
    else{
        printf("Vous avez perdu\n");
        printf("le nombre était %d %d %d %d",mastersuite[0],mastersuite [1],mastersuite[2],mastersuite[3]);
    }


    return 0;
}
