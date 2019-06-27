#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 20
#define MAX 38

//LISTA CONCATENATA SQUADRE

struct squadre{

    char nome[DIM];
    int punteggio;
    int golf;
    int gols;

};
typedef struct squadre tsquadre;

struct nodo{

    tsquadre nome;
    struct nodo* next;

};
typedef struct nodo tnodo;
typedef tnodo * squadra;

//LISTA CONCATENATA PARTITA

struct partite{

    char nomeSquadra1[DIM];
    char nomeSquadra2[DIM];
    int goal1;
    int goal2;

};
typedef struct partite tpartite;

struct elemento{

    tpartite information;
    struct elemento *next;

};

typedef struct elemento telemento;
typedef struct telemento * partita;

//LISTA CONTENATA GIORNATE

struct giornate{

        int k; //numer partite
        partita punt;

};
typedef struct giornate tgiornate;

struct node{

    tgiornate info;
    struct node *next

};
typedef struct node tnode;
typedef tnode * giornata;

//STRUCT CALENDARIO
 struct caldendar{

    giornata punt[MAX];

 };
 typedef struct calendar tcalendario;
 typedef tcalendario * calendario;

 //STRUCT CLASSIFICA

 struct table {

    char *nome[DIM];
    int *golf;
    int *gols;
    int *punteggio;
    int num;

 };
 typedef struct table btable;
 typedef btable * classifica;


 //Prototipi delle funzioni


squadra caricaSquadre(squadra, char*);
creaCalendario ();
void inizializzaClassifica(classifica, int, squadra[]);
void inserisci_risultati(giornata [], int , classifica);
void stampaClassifica(classifica);
void stampaGiornata(giornata);
void salvaClassifica(classifica , char *);



