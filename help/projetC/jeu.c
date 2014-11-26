// Wargnier Pierre 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <time.h>


#define couleur(param) printf("\033[%sm",param)
int  tab[19][19];
int  piece[9];
int* fleches;
int* drakkar;
int* posinit;
int  nbrC;
int  initPiece[9];
int tabFile[19][19];
int pieceFile[9];
int* drakkarFile;

typedef enum bool bool;
enum bool{
	true = 1, false = 0
};

 typedef struct saveStruct {
	int piecRot;
	int piecMov;
} saveStruct;

typedef struct Pile_ {
	saveStruct elem[1000];
	int Nbelem;
} Pile;

Pile enr;

void initPile(){
	enr.Nbelem = 0;
}

int pilevide(){
	return enr.Nbelem == 0;
}

int pilepleine(){
	return enr.Nbelem == 1000;
}

void enregistre(int molette, int mov){
	if (pilepleine()){
		printf("\e[1;3%dm Erreur, pile pleine\n\e[m", 1);
	}
	else {
		enr.elem[enr.Nbelem].piecRot = molette;
		enr.elem[enr.Nbelem].piecMov = mov;
		enr.Nbelem++;
		nbrC++;
	}
}

typedef struct Element Element;
struct Element
{
    int tabFile[19][19];
    int* flechesFile;
	int* drakkarFile;
	int pieceFile[9];
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *first;
};
File file;
//on enregistre les drakkars et les mollettes du début
void save(){
	int i;
	for (i = 0; i < 4; ++i){
		posinit[i]=drakkar[i]; 
	}
	for (i = 0; i < 9; ++i){
		initPiece[i] = piece[i];
	}

}


// initialisation du tableau a blanc et bord et les emplacement des Drakkars noir.
void inittab(){
	int i,j;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			if((i==0) ||(i==18)||(j==0)||(j==18)){
				tab[i][j]= 1;
			}
			else{
				tab[i][j]=0;
			}
		}
	}

	for(i=3;i<14;i=i+5){
		for(j=1;j<17;j=j+5){
			tab[i][j]=1;
			tab[i+1][j]=1;
			tab[i+2][j]=1;
			tab[i][j+1]=1;
			tab[i+1][j+1]=1;
			tab[i+2][j+1]=1;
		}
	}
	for(i=1;i<17;i=i+5){
		for(j=3;j<14;j=j+5){
			tab[i][j]=1;
			tab[i][j+1]=1;
			tab[i][j+2]=1;
			tab[i+1][j]=1;
			tab[i+1][j+1]=1;
			tab[i+1][j+2]=1;
		}
	}
}


// initialisation des fleches sur le bord du tableau
void initFleches(int pos, int couleur){
	switch(pos){
		case 13:
				tab[4][0]=couleur;
			break;
		case 43:
				tab[9][0]=couleur;
			break;
		case 73:
				tab[14][0]=couleur;
			break;
		case 10:
				tab[0][4]=couleur;
			break;
		case 20:
				tab[0][9]=couleur;
			break;
		case 30:
				tab[0][14]=couleur;
			break;
		case 72:
				tab[18][4]=couleur;
			break;
		case 82:
				tab[18][9]=couleur;
			break;
		case 92:
				tab[18][14]=couleur;
			break;
		case 31:
				tab[4][18]=couleur;
			break;
		case 61:
				tab[9][18]=couleur;
			break;
		case 91:
				tab[14][18]=couleur;
			break;
	}

}

// initialisation des Drakkars
void initDrakkars(int pos, int couleur){
	int i,j;
	if(pos%2==0){
		switch(pos){
			case 10:
					i = 1;
					j = 3;
				break;
			case 20:
					i = 1;
					j = 8;
				break;
			case 30:
					i = 1;
					j = 13;
				break;
			case 12:
					i = 6;
					j = 3;
				break;
			case 22:
					i = 6;
					j = 8;
				break;
			case 32:
					i = 6;
					j = 13;
				break;
			case 42:
					i = 11;
					j = 3;
				break;
			case 52:
					i = 11;
					j = 8;
				break;
			case 62:
					i = 11;
					j = 13;
				break;
			case 72:
					i = 16;
					j = 3;
				break;
			case 82:
					i = 16;
					j = 8;
				break;
			case 92:
					i = 16;
					j = 13;
				break;
		}
		tab[i][j]=couleur;
		tab[i][j+1]=couleur;
		tab[i][j+2]=couleur;
		tab[i+1][j]=couleur;
		tab[i+1][j+1]=couleur;
		tab[i+1][j+2]=couleur;
	}
	else{
		switch(pos){
			case 13:
					i = 3;
					j = 1;
				break;
			case 11:
					i = 3;
					j = 6;
				break;
			case 21:
					i = 3;
					j = 11;
				break;
			case 31:
					i = 3;
					j = 16;
				break;
			case 43:
					i = 8;
					j = 1;
				break;
			case 41:
					i = 8;
					j = 6;
				break;
			case 51:
					i = 8;
					j = 11;
				break;
			case 61:
					i = 8;
					j = 16;
				break;
			case 73:
					i = 13;
					j = 1;
				break;
			case 71:
					i = 13;
					j = 6;
				break;
			case 81:
					i = 13;
					j = 11;
				break;
			case 91:
					i = 13;
					j = 16;
				break;
		}
		tab[i][j]=couleur;
		tab[i+1][j]=couleur;
		tab[i+2][j]=couleur;
		tab[i][j+1]=couleur;
		tab[i+1][j+1]=couleur;
		tab[i+2][j+1]=couleur;
	}
}

int tirageNiv(){
	srand(time(NULL));
	int nb = (rand()%(3-1)+1);
	return nb;
}

// initialisation des rectangle.
void initRect(int elem, int h, int d, int b, int g, int coul){
	switch(elem){
		case 0:
			initDrakkars(g, coul);
			initDrakkars(b, coul);
		break;
		case 1:
			initDrakkars(h, coul);
			initDrakkars(g, coul);
		break;
		case 2:
			initDrakkars(h, coul);
			initDrakkars(d, coul);
		break;
		case 3:
			initDrakkars(d, coul);
			initDrakkars(b, coul);
		break;
		case 4:
			initDrakkars(h, coul);
			initDrakkars(b, coul);
		break;
		case 5:
			initDrakkars(d, coul);
			initDrakkars(g, coul);
		break;
	}
}


// initialisation du damier
void initmolette(int pos, int element){
	int i,j,x,y;
		switch(pos){
			case 2:
					i = 3; 
					j = 8; 
					initRect(element,20,21,22,11,(2+(pos%2)));
				break;
			case 4:
					i = 8;
					j = 3;
					initRect(element,12,41,42,43,(2+(pos%2)));
				break;
			case 6:
					i = 8;
					j = 13;
					initRect(element,32,61,62,51,(2+(pos%2)));
				break;
			case 8:
					i = 13;
					j = 8;
					initRect(element,52,81,82,71,(2+(pos%2)));
				break;
			case 1:
					i = 3;
					j = 3;
					initRect(element,10,11,12,13,(2+(pos%2)));
				break;
			case 3:
					i = 3;
					j = 13;
					initRect(element,30,31,32,21,(2+(pos%2)));
				break;
			case 5:
					i = 8;
					j = 8;
					initRect(element,22,51,52,41,(2+(pos%2)));
				break;
			case 7:
					i = 13;
					j = 3;
					initRect(element,42,71,72,73,(2+(pos%2)));
				break;
			case 9:
					i = 13;
					j = 13;
					initRect(element,62,91,92,81,(2+(pos%2)));
				break;
		}
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
				tab[i+x][j+y]= (2+(pos%2));
			}
		}
}


//Initialisation du tableau en fonction du fichier.
void initialisation(){
	int i,cpt;
	cpt=0;
	inittab();
	for(i=0;i<9;i++){
			cpt = cpt+1;
			initmolette(cpt,piece[i]);
	}
	cpt=0;
	while(drakkar[cpt]!=0){
		initDrakkars(drakkar[cpt],cpt+4);
		initFleches(fleches[cpt],cpt+4);
		cpt = cpt+1;
	}

}

#define BUF_SIZE 256
// Lecture du fichier de niveau.
void lectureFile(char* nomDuFichier){
	FILE* fichier = NULL;
	char buf[BUF_SIZE];
	int i;
	int cpt=0;
	int* valmol= {0};
	valmol = malloc(sizeof(int)*100);
	int val;
	size_t sz = 0;

	fichier = fopen(nomDuFichier, "r");

	if (fichier != NULL){
		while (!feof(fichier)){
			sz = fread(buf, sizeof(char), BUF_SIZE, fichier);
			for(i = 0; i < sz; ++i){
				
				if(isdigit(buf[i])){
					if(i == sz-1){
						
					}
					else{
						if (isdigit(buf[i+1])){
							val = ((int)(buf[i] - '0') * 10) + (int)(buf[i+1] - '0');
							++i;
						}
						else{
							val = (int)(buf[i] - '0');
						}
						valmol[cpt] = val;
						++cpt;
					}
				}
			}
		}

		int k = 0;
		for(i = 0;i < 9; ++i){

				piece[k]= valmol[i];
				++k;
		}
		k = 0;
		for(i = 9;i < 13; ++i){
			if(valmol[i]!=0){
				drakkar[k] = valmol[i];
			}
			++k;
		}
		
		k = 0;
		for(i = 13;i < 17; ++i){
			if(valmol[i]!=0){
				fleches[k] = valmol[i];
			}
			++k;
		}
		

        fclose(fichier);
    }
    else{
        printf("Impossible d'ouvrir le fichier \n");
        exit(0);
    }
    free(valmol);
    initialisation();
}

//création de la chaine du chemin vers le fichier d'initialisation.
void consChemin(char * niveau){
	char chemin[100] = "./Niveaux/";
	strcat(chemin, niveau);
	int niv = tirageNiv();
	char tampon[16];
	sprintf(tampon, "%d", niv);
	strcat(chemin, tampon);
	strcat(chemin, ".txt");
	printf("%s \n", chemin );
	lectureFile(chemin);

}

// Fonction permettant l'affichage du plateau de jeu
void affiche(){
	int i,j,cpt=1;
	printf("\n \n");
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			switch(tab[i][j]){
				case 0: //Blanc
					couleur("48");
					printf("  ");
					couleur("0");
				break;
				case 1://Noir
					couleur("40");
					printf("  ");
					couleur("0");
				break;
				case 2://Bleu
					if(((i==9)&&(j==4))||((i==4)&&(j==9))||((i==9)&&(j==14))||((i==14)&&(j==9))){
						printf("\e[1;%d;%dm %d\e[m", 37, 44, cpt);
						cpt = cpt+1;
					}
					else{
						couleur("44");
						printf("  ");
						couleur("0");
					}
				break;
				case 3://Bleu clair
					if(((i==4)&&(j==4))||((i==4)&&(j==14))||((i==9)&&(j==9))||((i==14)&&(j==4))||((i==14)&&(j==14))){
						printf("\e[1;%d;%dm %d\e[m",37, 46, cpt);
						cpt = cpt+1;
					}
					else{
						couleur("46");
						printf("  ");
						couleur("0");
					}
				break;
				case 4://Jaune
					couleur("43");
					printf("  ");
					couleur("0");
				break;
				case 5://Vert
					couleur("42");
					printf("  ");
					couleur("0");
				break;
				case 6://Rouge
					couleur("41");
					printf("  ");
					couleur("0");
				break;
				case 7://Violet
					couleur("45");
					printf("  ");
					couleur("0");
				break;

			}
		}
		printf("\n");
	}
	printf("\n");
}


void viderTampon(){
	char c ='a';
	while(c != '\n' && c != EOF){
		c = getchar();
	}
}

void menu(){
	char* chemin;
	chemin = malloc(sizeof(char)*1000);
	int choi;
	bool test = false;
	do{
		printf("- pour charger une partie facile pre-enregistree, tapez 1 \n- pour charger une partie moyenne pre-enregistree, tapez 2 \n- pour charger une partie difficile pre-enregistree, tapez 3 \n- pour charger une partie a partir d un fichier, tapez 4 \n- pour sortir du jeu, tapez 0\n");
		scanf("%d",&choi);
		viderTampon();
		switch(choi){
			case 1:
					consChemin("facile");
					test = true;
				break;
			case 2:
					consChemin("moyenne");
					test = true;
				break;
			case 3:
					consChemin("difficile");
					test = true;
				break;
			case 4:
				printf("Chemin complet vers le fichier d'initialisation (a partir du dossier contenant projet.c): \n");
				scanf("%s",chemin);
				viderTampon();
				lectureFile(chemin);
				test = true;// On lit le fichier en fonction de ce lien
				break;
			case 0:
				exit(0);
				break;
			default: 
				printf("\e[1;3%dm erreur, mauvaise valeur saisie\n\e[m", 1);
		}
	}while(test != true);
	save();
	free(chemin);
}

//Sauvegarde du mouvement
void save2(int mol, int mov){
	if (pilepleine()){
		printf("\e[1;3%dm Erreur, pile pleine\n\e[m", 1);
	}
	else {
		enr.elem[enr.Nbelem].piecRot = mol;
		enr.elem[enr.Nbelem].piecMov = mov;
		enr.Nbelem++;
	}
}

//Chargement de la partie tel quelle était au début
void load(){
	int i;
	for (i = 0; i < 4; ++i)
	{
		drakkar[i]= posinit[i]; 
	}
	for (i = 0; i < 9; ++i)
	{
		piece[i]=initPiece[i];
	}
	nbrC = 0;
	initPile();
}


//trouve les rectangles collés à la molette
int* coller(int mol){
	int* res;
	res = malloc(sizeof(int)*100);
	switch(mol){
			case 2:
					res[0] =20;
					res[1] =21;
					res[2] =22;
					res[3] =11;
				break;
			case 4:
					res[0] = 12;
					res[1] = 41;
					res[2] = 42;
					res[3] = 43;
				break;
			case 6:
					res[0] =32;
					res[1] =61;
					res[2] =62;
					res[3] =51;
				break;
			case 8:
					res[0] =52;
					res[1] =81;
					res[2] =82;
					res[3] =71;
				break;
			case 1:
					res[0] =10;
					res[1] =11;
					res[2] =12;
					res[3] =13;
				break;
			case 3:
					res[0] =30;
					res[1] =31;
					res[2] =32;
					res[3] =21;
				break;
			case 5:
					res[0] =22;
					res[1] =51;
					res[2] =52;
					res[3] =41;
				break;
			case 7:
					res[0] =42;
					res[1] =71;
					res[2] =72;
					res[3] =73;
				break;
			case 9:
					res[0] =62;
					res[1] =91;
					res[2] =92;
					res[3] =81;
				break;

		}
	return res;
	free(res);
}

//Donne la couleur du rectangle.
int color(int rec){
	switch(rec){
		case 10:
				return (tab[1][3]);
			break;
		case 11:
				return (tab[3][6]);
			break;
		case 12:
				return (tab[6][3]);
			break;
		case 13:
				return (tab[3][1]);
			break;
		case 20:
				return (tab[1][8]);
			break;
		case 21:
				return (tab[3][11]);
			break;
		case 22:
				return (tab[6][8]);
			break;
		case 30:
				return (tab[1][13]);
			break;
		case 31:
				return (tab[3][16]);
			break;
		case 32:
				return (tab[6][13]);
			break;
		case 41:
				return (tab[8][6]);
			break;
		case 42:
				return (tab[11][3]);
			break;
		case 43:
				return (tab[8][1]);
			break;
		case 51:
				return (tab[8][11]);
			break;
		case 52:
				return (tab[11][8]);
			break;
		case 61:
				return (tab[8][16]);
			break;
		case 62:
				return (tab[11][13]);
			break;
		case 71:
				return (tab[13][6]);
			break;
		case 72:
				return (tab[16][3]);
			break;
		case 73:
				return (tab[13][1]);
			break;
		case 81:
				return (tab[13][11]);
			break;
		case 82:
				return (tab[16][8]);
			break;
		case 91:
				return (tab[13][16]);
			break;
		case 92:
				return (tab[16][13]);
			break;
		default: 
				return 1;
	}
}

//test le mouvement de la molette
bool testmove(int mol){
	int i,cpt=0;
	bool isbat = false;
	int* test;
	test = malloc(sizeof(int)*100);
	test = coller(mol);
	for(i=0;i<4;i++){
		if(color(test[i])>3){
			isbat = true;
			cpt =cpt +1;
		}
		else{
			if(mol % 2 == 0){
				if((color(test[i])==1)||(color(test[i])==2)){
					cpt = cpt +1;
				}
			}
			else{
				if((color(test[i])==1)||(color(test[i])==3)){
					cpt = cpt +1;
				}
			}
		}
	}
	if((cpt == 4)&&(isbat == true)){
		return true;
	}
	else{
		return false;
	}
}

// test si il y a victoire ou non
bool victoire(){
 	bool win = false;
 	int i,cpt=0;
 	for (i = 0; i < 4; ++i){
 		if(fleches[i]==drakkar[i]){
 			cpt = cpt + 1;
 		}
 	}
 	if(cpt == 4){
 		win = true;
 	}
 	return win;
 }

 //trouve la position du drakkar.
 int* wherePos(int* pv){
 	int* pos;
 	pos = malloc(sizeof(int)*100);
 	int i,j, cpt =0;
 	for(i = 0; i < 4; i++){
 		for(j=0;j<4;j++){
 			if (pv[i]==drakkar[j]){
 				pos[cpt] = pv[i];
 				cpt = cpt +1;
 			}
 		}
 	}
 	return pos;
 }

//fai bouger les drakkars.
 void moveDrak(int mol, int mouv){
 	int i,j,k,pos,newpos;
 	int* test;
 	test = malloc(sizeof(int)*100);
	test = coller(mol);
	int* test2;
	test2 = malloc(sizeof(int)*100);
	test2 = wherePos(test);
	for(i=0;i<4;i++){
		for(j=0;j<sizeof(test2);j++){
			if(test[i]== test2[j]){
				pos = test[i];
				newpos = test[i+mouv];
				switch(i+mouv){
		 			case 4:
		 				newpos = test[0];
		 				break;
		 			case -1:
		 				newpos = test[3];
		 				break;
		 		}
		 		for(k=0; k<4; k++){
					if(drakkar[k]==pos){
						drakkar[k]= newpos;
					}
				}
			}
		}
	}
	free(test);
	free(test2);
 }

//fait bouger les molettes
bool move(int mol, int mouv){
 	if(testmove(mol)){
 		switch(piece[mol-1]){
 			case 5:
 				piece[mol-1]=4;
 				break;
 			case 4:
 				piece[mol-1]=5;
 				break;
 			case 3:
 				piece[mol-1]=piece[mol-1]+(mouv);
 				if(piece[mol-1]==4){
 					piece[mol-1]= 0;
 				}
 				break;
 			case 2:
 				piece[mol-1]=piece[mol-1]+(mouv);
 				break;
 			case 1:
 				piece[mol-1]=piece[mol-1]+(mouv);
 				break;
 			case 0:
 				piece[mol-1]=piece[mol-1]+(mouv);
 				if(piece[mol-1]==(-1)){
 					piece[mol-1]= 3;
 				}
 				break;
 		}
 		moveDrak(mol, mouv);
 		nbrC = nbrC +1;
 		return true;
 	}
 	else{
 		printf("\e[1;3%dm erreur, Impossible de tourner la molette\n\e[m", 1);
 		return false;
 	}
 }

//On recharge le mouvement précédent
void load2(){
	int mol, mouv;
	if (pilevide()) {
		printf("\e[1;3%dm Erreur, Vous ne pouvez plus revenir en arriere\n\e[m", 1);
	}
	else {
		enr.Nbelem--;
		mol = enr.elem[enr.Nbelem].piecRot;
		mouv = enr.elem[enr.Nbelem].piecMov;
		move(mol,(-(mouv)));
		nbrC = nbrC - 2;
	}
}


//identifie le sens voulu;
void sensRota(int mol){
	char sens;
	bool test = false, test2 = false;
	int mov;
	do{
		printf("- o pour le sens anti-horaire\n- p pour le sens horaire \n");
		scanf("%c", &sens);
		viderTampon();
		switch(sens){
			case 'o' :
					mov = -1;
					test2 =move(mol, mov);
					test = true;
				break;
			case 'p' :
					mov = +1;
					test2= move(mol, mov);
					test = true;
				break;
			default :
				printf("\e[1;3%dm la valeur saisie est intraitable\n\e[m", 1);
		}
	}while(test != true);
	if(test2==true){
		save2(mol, mov);
	}

}

//initialise le tableau
void initFile(){
	int i,j;

for(i=3;i<14;i=i+5){
	for(j=1;j<17;j=j+5){
		tabFile[i][j]=1;
		tabFile[i+1][j]=1;
		tabFile[i+2][j]=1;
		tabFile[i][j+1]=1;
		tabFile[i+1][j+1]=1;
		tabFile[i+2][j+1]=1;
	}
}
	for(i=1;i<17;i=i+5){
		for(j=3;j<14;j=j+5){
			tabFile[i][j]=1;
			tabFile[i][j+1]=1;
			tabFile[i][j+2]=1;
			tabFile[i+1][j]=1;
			tabFile[i+1][j+1]=1;
			tabFile[i+1][j+2]=1;
		}
	}
}

// initialisation des Drakkars
void initDrake2( int pos, int couleur){
	int i,j;
	if(pos%2==0){
		switch(pos){
			case 10:
					i = 1;
					j = 3;
				break;
			case 20:
					i = 1;
					j = 8;
				break;
			case 30:
					i = 1;
					j = 13;
				break;
			case 12:
					i = 6;
					j = 3;
				break;
			case 22:
					i = 6;
					j = 8;
				break;
			case 32:
					i = 6;
					j = 13;
				break;
			case 42:
					i = 11;
					j = 3;
				break;
			case 52:
					i = 11;
					j = 8;
				break;
			case 62:
					i = 11;
					j = 13;
				break;
			case 72:
					i = 16;
					j = 3;
				break;
			case 82:
					i = 16;
					j = 8;
				break;
			case 92:
					i = 16;
					j = 13;
				break;
		}
		tabFile[i][j]=couleur;
		tabFile[i][j+1]=couleur;
		tabFile[i][j+2]=couleur;
		tabFile[i+1][j]=couleur;
		tabFile[i+1][j+1]=couleur;
		tabFile[i+1][j+2]=couleur;
	}
	else{
		switch(pos){
			case 13:
					i = 3;
					j = 1;
				break;
			case 11:
					i = 3;
					j = 6;
				break;
			case 21:
					i = 3;
					j = 11;
				break;
			case 31:
					i = 3;
					j = 16;
				break;
			case 43:
					i = 8;
					j = 1;
				break;
			case 41:
					i = 8;
					j = 6;
				break;
			case 51:
					i = 8;
					j = 11;
				break;
			case 61:
					i = 8;
					j = 16;
				break;
			case 73:
					i = 13;
					j = 1;
				break;
			case 71:
					i = 13;
					j = 6;
				break;
			case 81:
					i = 13;
					j = 11;
				break;
			case 91:
					i = 13;
					j = 16;
				break;
		}
		tabFile[i][j]=couleur;
		tabFile[i+1][j]=couleur;
		tabFile[i+2][j]=couleur;
		tabFile[i][j+1]=couleur;
		tabFile[i+1][j+1]=couleur;
		tabFile[i+2][j+1]=couleur;
	}
}

// détermination des rectangles de couleurs en fonction des pièces
void touche( int elem, int h, int d, int b, int g, int coul){

	switch(elem){
		case 0:
			initDrake2(g, coul);
			initDrake2(b, coul);
		break;
		case 1:
			initDrake2(h, coul);
			initDrake2(g, coul);
		break;
		case 2:
			initDrake2(h, coul);
			initDrake2(d, coul);
		break;
		case 3:
			initDrake2(d, coul);
			initDrake2(b, coul);
		break;
		case 4:
			initDrake2(h, coul);
			initDrake2(b, coul);
		break;
		case 5:
			initDrake2(d, coul);
			initDrake2(g, coul);
		break;
	}
}


// initialisation du damier
void initDamier2( int pos, int elem){
	int i,j,x,y;
		switch(pos){
			case 2:
					i = 3; // 3 +(pos-1 / 3)*5
					j = 8; // 3 +(pos-1 % 3)*5
					touche(elem,20,21,22,11,(2+(pos%2)));
				break;
			case 4:
					i = 8;
					j = 3;
					touche(elem,12,41,42,43,(2+(pos%2)));
				break;
			case 6:
					i = 8;
					j = 13;
					touche(elem,32,61,62,51,(2+(pos%2)));
				break;
			case 8:
					i = 13;
					j = 8;
					touche(elem,52,81,82,71,(2+(pos%2)));
				break;
			case 1:
					i = 3;
					j = 3;
					touche(elem,10,11,12,13,(2+(pos%2)));
				break;
			case 3:
					i = 3;
					j = 13;
					touche(elem,30,31,32,21,(2+(pos%2)));
				break;
			case 5:
					i = 8;
					j = 8;
					touche(elem,22,51,52,41,(2+(pos%2)));
				break;
			case 7:
					i = 13;
					j = 3;
					touche(elem,42,71,72,73,(2+(pos%2)));
				break;
			case 9:
					i = 13;
					j = 13;
					touche(elem,62,91,92,81,(2+(pos%2)));
				break;
		}
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
				tabFile[i+x][j+y]= (2+(pos%2));
			}
		}
}

// creation et rassemblement des elements de jeu
void tabCreat(){
	int i,cpt = 0;
	initFile();

	for(i=0;i<9;i++){
			cpt = cpt+1;
			initDamier2(cpt,pieceFile[i]);
	}
	cpt=0;
	while(drakkarFile[cpt]!=0){
		initDrake2(drakkarFile[cpt],cpt+4);
		cpt = cpt+1;
	}

}

//gestion des mouvements des pièces
void move2(int piece, int mouv){

 		switch(pieceFile[piece-1]){
 			case 5:
 				pieceFile[piece-1]=4;
 				break;
 			case 4:
 				pieceFile[piece-1]=5;
 				break;
 			case 3:
 				pieceFile[piece-1]=pieceFile[piece-1]+(mouv);
 				if(pieceFile[piece-1]==4){
 					pieceFile[piece-1]= 0;
 				}
 				break;
 			case 2:
 				pieceFile[piece-1]=pieceFile[piece-1]+(mouv);
 				break;
 			case 1:
 				pieceFile[piece-1]=pieceFile[piece-1]+(mouv);
 				break;
 			case 0:
 				pieceFile[piece-1]=pieceFile[piece-1]+(mouv);
 				if(pieceFile[piece-1]==(-1)){
 					pieceFile[piece-1]= 3;
 				}
 				break;
 		}
 }


//on retour la couleur du rectangle dans le tableau de l'element de la file.
int DetCol(int r){
	switch(r){
		case 10:
				return (tabFile[1][3]);
			break;
		case 11:
				return (tabFile[3][6]);
			break;
		case 12:
				return (tabFile[6][3]);
			break;
		case 13:
				return (tabFile[3][1]);
			break;
		case 20:
				return (tabFile[1][8]);
			break;
		case 21:
				return (tabFile[3][11]);
			break;
		case 22:
				return (tabFile[6][8]);
			break;
		case 30:
				return (tabFile[1][13]);
			break;
		case 31:
				return (tabFile[3][16]);
			break;
		case 32:
				return (tabFile[6][13]);
			break;
		case 41:
				return (tabFile[8][6]);
			break;
		case 42:
				return (tabFile[11][3]);
			break;
		case 43:
				return (tabFile[8][1]);
			break;
		case 51:
				return (tabFile[8][11]);
			break;
		case 52:
				return (tabFile[11][8]);
			break;
		case 61:
				return (tabFile[8][16]);
			break;
		case 62:
				return (tabFile[11][13]);
			break;
		case 71:
				return (tabFile[13][6]);
			break;
		case 72:
				return (tabFile[16][3]);
			break;
		case 73:
				return (tabFile[13][1]);
			break;
		case 81:
				return (tabFile[13][11]);
			break;
		case 82:
				return (tabFile[16][8]);
			break;
		case 91:
				return (tabFile[13][16]);
			break;
		case 92:
				return (tabFile[16][13]);
			break;
		default: 
				return 1;
	}
}


//On regarde si la pièce peut bouger
bool testMove2(int mol, int tab[19][19] ){
	tab = malloc(sizeof(int)*1000);
	int i,cpt=0;
	bool isbat = false;
	int* test;
	test = malloc(sizeof(int)*100);
	test = coller(mol);
	for(i=0;i<4;i++){
		if(DetCol(test[i])>3){
			isbat = true;
			cpt =cpt +1;
		}
		else{
			if(mol % 2 == 0){
				if((DetCol(test[i])==1)||(DetCol(test[i])==2)){
					cpt = cpt +1;
				}
			}
			else{
				if((DetCol(test[i])==1)||(DetCol(test[i])==3)){
					cpt = cpt +1;
				}
			}
		}
	}
	if((cpt == 4)&&(isbat == true)){
		return true;
	}
	else{
		return false;
	}
}


// Permet de savoir si l'on gagne ou non.
bool IsWin2(int* f, int* d){
 	bool w = false;
 	int i,cpt=0;
 	for (i = 0; i < 4; ++i){
 		if(f[i]==d[i]){
 			cpt = cpt + 1;
 		}
 	}
 	if(cpt == 4){
 		w = true;
 	}
 	return w;
 }


 //Permet de connaitre les positions d'un drakkar dans la file
 int* posDrake2(int* v, int* d){
 	d = malloc(sizeof(int)*100);
 	int* pos;
 	pos = malloc(sizeof(int)*100);
 	int i,j, cpt =0;
 	for(i = 0; i < 4; i++){
 		for(j=0;j<4;j++){
 			if (v[i]==d[j]){
 				pos[cpt] = v[i];
 				cpt = cpt +1;
 			}
 		}
 	}
 	free(d);
 	return pos;
 }

//Fait bouger les drakkars
 void moveDrake2(int mol, int mouv){
 	int i,j,k,pos,newpos;
 	int* test;
 	test = malloc(sizeof(int)*100);
	test = coller(mol);
	int* test2;
	test2 = malloc(sizeof(int)*100);
	test2 = posDrake2(test, drakkarFile);
	for(i=0;i<4;i++){
		for(j=0;j<sizeof(test2);j++){
			if(test[i]== test2[j]){
				pos = test[i];
				newpos = test[i+mouv];
				switch(i+mouv){
		 			case 4:
		 				newpos = test[0];
		 				break;
		 			case -1:
		 				newpos = test[3];
		 				break;
		 		}
		 		for(k=0; k<4; k++){
					if(drakkarFile[k]==pos){
						drakkarFile[k]= newpos;
					}
				}
			}
		}
	}
	free(test);
	free(test2);

 }

void creatFile(File *f){
	int i,j;
	Element *new = malloc(sizeof(*new));
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			new->tabFile[i][j] = tab[i][j];
		}
	}
	for(i=0;i<9;i++){
		new->pieceFile[i] = piece[i];
	}
	new->flechesFile = fleches;
	new->drakkarFile = drakkar;
    new->suivant = NULL;

	if(f -> first == NULL){
		f->first = new;
	}

}

void parcour(File *f){
	int i,j;
    if (f == NULL){
        exit(1);
    }

    if (f->first != NULL){
        Element *elementDefile = f->first;

       for(i=0;i<19;i++){
			for(j=0;j<19;j++){
				tab[i][j] = elementDefile->tabFile[i][j];
			}
		}
		for(i=0;i<9;i++){
			piece[i] = elementDefile->pieceFile[i];
		}
		fleches = elementDefile->flechesFile ;
		drakkar = elementDefile->drakkarFile ;
        f->first = elementDefile->suivant;
        free(elementDefile);
        affiche();
    }

}

void ajoutElem(File *file, int* flech, int* drakkar, int piec[9]){
	int i, j;
	drakkar = malloc(sizeof(int)*100);
	piec = malloc(sizeof(int)*100);
	flech = malloc(sizeof(int)*100);
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			nouveau->tabFile[i][j] = tabFile[i][j];
		}
	}
	for(i=0;i<9;i++){
		nouveau->pieceFile[i] = piec[i];
	}
	nouveau->flechesFile = flech;
	nouveau->drakkarFile = drakkar;
    nouveau->suivant = NULL;

    if (file->first != NULL){

        Element *elementActuel = file->first;
        while (elementActuel->suivant != NULL){
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else{ 
        file->first = nouveau;
    }

	free(drakkar);
	free(piec);
	free(flech);
}


bool Resolution(int tableau[19][19], int* flech, int* drakkar, int piec[9]){
	int i,j;
	for(i=0;i<19;i++){
		for(j=0;j<19;j++){
			tabFile[i][j] = tableau[i][j];
		}
	}
	drakkarFile = drakkar;
	for(i=0;i<9;i++){
		pieceFile[i] = piec[i];
	}
	if(IsWin2(flech, drakkar)){

		return true;
	}
	for(i = 1; i < 10; i++){
		if(testMove2(i,tabFile)){
			moveDrake2(i, +1);
			move2(i, +1);
			tabCreat();
			
			ajoutElem(&file, flech, drakkarFile, pieceFile);
			printf("la piece %d peut bouger \n",i );
		}
	}
	return false;
}

void creatReal(){
	drakkarFile = malloc(sizeof(int)*100);
	creatFile(&file);
	

	Resolution(tab, fleches, drakkar, piece);
}

void menuSolution(){
	int choi, cpt= 0;
	printf("- Choisir le nombre(s) d'étape(s) a visualiser \n");
	scanf("%d", &choi);
	viderTampon();
	creatReal();
	printf("Début de la Solution :\n");
	while(cpt != choi){
		parcour(&file);
		cpt = cpt +1;
	}
	printf("Fin de la Solution\n\n");


}

int menu4(){
	bool ok = false;
	int choi;
	do{
	printf("- pour continuer la partie, tapez 1\n- pour visualiser la suite de la solution pour cette partie, tapez 2\n- pour changer de partie, tapez 11\n- pour sortir du jeu, tapez 0 \n");
	scanf("%d", &choi);
	viderTampon();
	
		switch(choi){
			case 1:
					ok = true;
				break;
			case 2:
					menuSolution();
				break;
			case 11:
					return 11;
					ok = true;
				break;
			case 0:
					exit(0);
				break;
			default:
				printf("\e[1;3%dm erreur, mauvaise valeur saisie\n\e[m", 1);
			}
	}while(ok != true);
	return 1;
}

void Rota2(int molette){
	char sens;
	bool ok = false, ok2 = false;
	int mov;
	do{
		printf("- o pour le sens anti-horaire\n- p pour le sens horaire \n");
		scanf("%c", &sens);
		viderTampon();
		switch(sens){
			case 'o' :
					mov = -1;
					ok2 =move(molette, mov);
					ok = true;
				break;
			case 'p' :
					mov = +1;
					ok2= move(molette, mov);
					ok = true;
				break;
			default :
				printf("\e[1;3%dm erreur, mauvaise valeur saisie\n\e[m", 1);
		}
	}while(ok != true);
	if(ok2==true){
		enregistre(molette, mov);
	}

}

int menu2(){
	int choi;
	bool test = false;
	do{
		printf("- indiquer le numero de la molette a tourner \n- pour visualiser une solution, tapez 13\n- pour recommencer cette partie, tapez 10 \n- pour changer de partie, tapez 11 \n- pour sortir du jeu, tapez 0 \n");
		scanf("%d", &choi);
		viderTampon();
		if((choi>0)&&(choi<10)){
				sensRota(choi);
				test =true;
		}
		else{
			switch(choi){
			case 10:
					load();
					nbrC = 0;
					test=true;
				break;
			case 11:
					return 11;
					test=true;
				break;
			case 13:
					menuSolution();
					int retourmenu4 = menu4();
					if(retourmenu4 == 11){
						return 11;
					}
					test = true;
				break;
			case 0:
					exit(0);
				break;
			default:
				printf("\e[1;3%dm La valeur choisit est intraitable\n\e[m", 1);
			}
		}
	}while(test != true);
	return 1;
}

int menu3(){
	int choi,res= 1;
	bool test = false;
	do{
		printf("- indiquer le numéro de la molette à tourner \n- pour visualiser une solution, tapez 13\n- pour recommencer cette partie, tapez 10 \n- pour changer de partie, tapez 11 \n- pour revenir d'un coup en arrière, tapez 12\n- pour sortir du jeu, tapez 0 \n");
		scanf("%d", &choi);
		viderTampon();
		if((choi>0)&&(choi<10)){
			sensRota(choi);
			test =true;
		}
		else{
			switch(choi){
			case 10:
					load();
					nbrC = 0;
					test =true;
				break;
			case 11:
					test =true;
					res = 11;
				break;
			case 12:
					load2();
					test =true;
				break;
			case 13:
					menuSolution();
					int retourmenu4 = menu4();
					if(retourmenu4 == 11){
						return 11;
					}
					test = true;
				break;
			case 0:
					exit(0);
				break;
			default:
				printf("\e[1;3%dm erreur, mauvaise valeur saisie\n\e[m", 1);
			}
		}
	}while(test != true);
	return res;
}

//Remise à zéro
void reInit(){
	int i;
	for(i=0;i<4;i++){
		fleches[i]=0;
		drakkar[i]=0;
	}
}



int main(){
	int res, res1;
	bool testVic = false;
	system("clear");
	initPile();
	drakkar = malloc(sizeof(int)*100);
	posinit = malloc(sizeof(int)*100);
	fleches = malloc(sizeof(int)*100);
	while(testVic!=true){
		do{
		nbrC = 0;
		reInit();
		menu();
		affiche();
		res1 = menu2();
		}while(res1 == 11);
		initialisation();
		affiche();
		do{
		res = menu3();
		initialisation();
		affiche();
		testVic = victoire();
		}while((testVic == false)&&(res !=11));
	}
	printf("Victoire en %d coups ! \n", nbrC);
	free(fleches);
	free(drakkar);
	return 1;
}