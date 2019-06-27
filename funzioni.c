#include "data.h"

/* Funzione caricaSquadre
*
* squadra p: un puntatore alla struttura squadre
*
* char *nomefile: un puntatore di tipo carattere che punta al file
*
*
* ritornerà una variabile p di tipo squadre che conterrà l'elenco di tutte le squadre
*
*
* int n
*
*/

squadra caricaSquadre(squadra p, char *nomefile, int n){

    FILE *fp;
    squadra newElem;
    tsquadre elem;

        if ((fp=fopen(nomefile, "r"))!=NULL){
            n=0;
            while (fscanf(fp, "%[^\n]", elem.nome) != EOF){
                newElem = (squadra*) malloc (sizeof(squadra));
                newElem->nome = elem;
                newElem->next = p;
                p = newElem;
                n++;
            }
        }else{

            printf("Errore nell'apertura del file\n");

        }

         fclose(fp);

    return p;

}

/* Funzione creaCalendario
*
* calendario p: un puntatore alla struttura calendario
*
*
*
*
*
* creerà 38 file vuoti, assegnando come nome di ogni file un numero progressivo partendo da 1 e arrivando a 38
*
*/

void creaCalendario (){

    int i;
    int numero_file = 38;
    FILE *p[numero_file];

        for(i = 1; i == numero_file; i++){
            char nomefile[20];
            sprintf(nomefile, "Giornata%d.txt", i);
            p[i] = fopen(nomefile, "w");
        //if((p = fopen("Giornata%d.txt", "w")) != NULL){
        //printf("Giornata%d\n", i);
        //}
  }


}

/*
*
* Funzione: inizializzaClassifica
*
* classifica p: un puntatore alla struttura classifica
*
* int n: il numero di squadre che oartecipano al campionato
*
* squadra a[]: vettore di tipo squadre che contiene appunto tutte le squdre
*
*
* Setta tutti i campi della classifica a zero cosí da inizializzarla e da poter prendere il numero di squadre che partecipano al campionato
*
*/

void inizializzaClassifica(classifica p, int n, squadra a[]){

    p->nome = (char*)malloc(n*sizeof(char));
    p->punteggio = malloc(n*sizeof(int));
    p->golf = malloc(n*sizeof(int));
    p->gols = malloc(n*sizeof(int));

        for (int i=0,i<n;i++){
            p->nome[i]= malloc(20*sizeof(char));
            strcpy(p->nome[i], a[i]->nome.nome);
            p->punteggio[i]=0;
            p->golf[i]=0;
            p->gols[i]=0;
        }
    p->num=n;
}

/*Funzione inserisci_risultati
*
* giornata[]: un vettore che conterrà le partite
*
* int n: dimensione del vettore
*
* classifica c: una variabile di tipo classifica che servirà ad aggiornare la classifica
*
*
*
*/

void inserisci_risultati(giornata a[], int n, classifica c){

    for (int i=0; i == a[n].info.k*2; i++){
        printf("%s - %s", a[n].info.punt.information.nomeSquadra1, a[n].info.punt.information.nomeSquadra2);
        printf("Inserisci il numero di goal della squadra di casa\n");
        scanf("%d", a[n].info.punt.information.goal1);
        printf("Inserisci il numero di goal della squadra in trasferta\n");
        scanf("%d", a[n].info.punt.information.goal2);
    }

    for (int i=0, i == a[n].info.k*2; i++){

        if (strcmp(c.nome, a[n].info.punt.information.nomeSquadra1)==0){
            if (a[n].info.punt.information.goal1 > a[n].info.punt.information.goal2){
                c.punteggio[i]+=3;

                }else if(a[n].info.punt.information.goal1 == a[n].info.punt.information.goal2){
                    c.punteggio[i]+=1;

        }
        c.golf+=a[n].info.punt.information.goal1;
        c.gols+=a[n].info.punt.information.goal2;
        }


        else if (strcmp(c.nome, a[n].info.punt.information.nomeSquadra2)==0){
            if(a[n].info.punt.information.goal2 > a[n].info.punt.information.goal1){
                c.punteggio[i]+=3;

                }else if(a[n].info.punt.information.goal1 == a[n].info.punt.information.goal2){
                    c.punteggio+=1;
                }

        c.golf+=a[n].info.punt.information.goal2;
        c.gols+=a[n].info.punt.information.goal1;

    }

    }

}




/*Funzione: StampaClassifica
*
* classifica p: un puntatore alla struttura classifica
*
*
*
*
* stamperà a schermo la classifica parziale
*
*/
void stampaClassifica(classifica p){

    for (int i=0; i<p.num; i++){
        printf("%s %d %d %d", p.nome, p.punteggio, p.golf, p.gols);
    }

}


/*Funzione: StampaGiornata
*
* giornata p: un puntatore alla struttura giornata
*
*
*
*
* stamperà a schermo una giornata
*
*/

void stampaGiornata(giornata p){

    for (int i=0; i<p.info.k; i++){
        print("%s %s %d %d", p->info.punt.information.nomeSquadra1,p->info.punt.information.nomeSquadra,p->info.punt.information.goal1,p->info.punt.information.goal2);
    }

}

/*
*
* Funzione: salvaClassifica
*
* classifica p: un puntatore alla struttura classifica
*
*
* salverà su file tutti i dati della struttura dati
*
*
*/

void salvaClassifica(classifica p, char *nomefile){

    FILE* fp;

    fp=fopen("classifica2.txt","w");
    /*fprintf(fp,"%s  %s  %s  %s\n","nome squadra","punteggio","goal fatti","goal subiti");*/
    for(int i=0;i<p.num;i++){
        fprintf(fp,"%s  %d  %d  %d\n",p.nome[i],p.punteggio[i],p.golf[i],p.gols[i]);
    }
}



