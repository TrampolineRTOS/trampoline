#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "wsc.h"
#define C166 1
#define Port COM1

// Prototypes des fonctions utilisables :
void Init(void);
void init_carte (void);
int ErrorCheck(int Code);
int lecture (int *fin, FILE *pfile); // retourne la variable fin
int verification_extension(char *nomfic, int *nb_caractere); //retourne 3 si OK 
                                                             //4 si erreur


char n0 [] =  "Alarm :                     ";
char n1 [] =  "ActivateTask_NEX_1 :        ";
char n2 [] =  "ActivateTask_NEX_2 :        ";
char n3 [] =  "ActivateTask_NEX_3 :        ";
char n4 [] =  "ActivateTask_EX_1 :         ";
char n5 [] =  "ActivateTask_EX_2 :         ";
char n6 [] =  "ActivateTask_EX_3 :         ";
char n7 [] =  "ActivateTask_P>_NEX  :      ";
char n8 [] =  "ActivateTask_P>_EX  :       ";
char n9 [] =  "TerminateTask1 :            ";
char n10 [] = "TerminateTask2 :            ";
char n11 [] = "ChainTask1 :                ";
char n12 [] = "ChainTask2 :                ";
char n13 [] = "ChainTask3 :                ";
char n14 [] = "ChainTask4 :                ";
char n15 [] = "GetResource :               ";
char n16 [] = "ReleaseResource :           ";
char n17 [] = "WaitEvent1 :                ";
char n18 [] = "WaitEvent2 :                ";
char n19 [] = "SetEvent :                  ";
char n20 [] = "ClearEvent :                ";
char n21 [] = "SetRelAlarm1 :              ";
char n22 [] = "SetRelAlarm2 :              ";
char n23 [] = "SetRelAlarm3 :              ";
char n24 [] = "CancelAlarm1 :              ";
char n25 [] = "CancelAlarm2 :              ";
char n26 [] = "Alarm_SetEvent :            ";
char n27 [] = "Alarm_CallBack :            ";
char n28 [] = "Alarm_ActivateTask_EX_1 :   ";
char n29 [] = "Alarm_ActivateTask_EX_2 :   ";
char n30 [] = "Alarm_ActivateTask_EX_3 :   ";
char n31 [] = "Alarm_ActivateTask_NEX_1 :  ";
char n32 [] = "Alarm_ActivateTask_NEX_2 :  ";
char n33 [] = "Alarm_ActivateTask_NEX_3 :  ";
char n34 [] = "Alarm_ActivateTask_P>_EX :  ";
char n35 [] = "Alarm_ActivateTask_P>_NEX : ";
char n36 [] = "ActivateTask_FIFO_1 :       ";
char n37 [] = "ActivateTask_FIFO_2 :       ";
char n38 [] = "ActivateTask_FIFO_3 :       ";
char n39 [] = "ActivateTask_FIFO_4 :       ";
char n40 [] = "ActivateTask_FIFO_5 :       ";
char n41 [] = "call_function :             ";


char* tab[37] = { n0 , n1 , n2 , n3 , n4 , n5 , n6 , n7 , n8 , n9 , n10 , n11 , n12 , n13 , n14 , n15 , n16 , n17 , n18 , n19 , n20 , n21 , n22 , n23 , n24 , n25 , n26 , n27	, n28 , n29 , n30 , n31 , n32 , n33 , n34 , n35 ,/* n36 , n37 , n38 , n39 , n40 , */n41 };


char part = 0;
char cible = 0;

/* Présentation des données: commence par + ,  A : 56 us@, fini par *
 * début de l'émission, détection d'une + état = 0
 * lecture de la lettre, etat = 1
 * affichage de la valeur
 * détection d'un @, état = 0
 * détection d'une * -> fin, état = 0
*/

int main (int argc, char *argv[])
{
    FILE *pfile;  // fichier   
	// vérification que le benchmark se fait au moin une fois
    char reussi = 0;
	while (reussi!=1)
    {
    // Variables pour le fichier
    char nomfic[26]="                        ";// nom du fichier
    char *nom = nomfic;
    int nb_caractere;   // nombre de caractère du nom  
       
    if(argc > 1)
        {
        if (argv[2][0] == '1')
            {
            part = 1;
            }
        
        if (argv[2][0] == '2')
            {
            part = 2;
            }
        
        if (argv[3][0] == 'C')
            {
            cible = C166;
            }
        Init();
        nom = argv[1];
        
        }
    else
        {
        Init();
        printf("\n\nEntrer un nom de fichier pour enregistrer les donnees :\n\n           ");
        scanf("%20s", nomfic);
        }
        
    
    
    // vérification et modification (si besoin) de l'extension du fichier      
    if(verification_extension(nom,&nb_caractere)!= 4)
        {
                                                                                                         
        //on ouvre le fichier et verifie si on y arrive
        if(part == 2) pfile = fopen(nom, "a");
        else pfile = fopen(nom, "w");  
        
        
        if(pfile != NULL)
            {
            reussi=1;
            int i, j;
            
            if (part != 2)
            {
            for (i=0;i<37;i++)
                {
                j = 0;
                while (tab[i][j] != ' ') {fprintf(pfile,"%c",tab[i][j]);j++;}
                
                fprintf(pfile,"\t");
                }
            }            
            // Boucle qui recommence tout le benchmark. 
            char c=' ';     
            while((c!='Q') & (c!='q'))
                {
                if (part != 2)
                   {
                   // début d'une nouvelle ligne de donnée dans le fichier
                   fprintf(pfile,"\n");          
                   }
                //initialisation
                int fin = 0;
            
                //Attente du début de l'emission
                while(SioGetc(Port)!='+');
            
                // on lis les donnée tant que l'on a pas détecté une *
                while(!lecture(&fin, pfile));
            
                if (part == 0)
                { 
                // demande pour redémarrer le benchmark
                printf("\nAppuyer sur Q pour Quitter ou une autre touche pour recommencer :\n\n");
                c=getch();
                }
                else c = 'q';
                }
            // on referme le fichier
            fclose(pfile);  
            
            if (part != 1)
            {
            printf("\n\n********************************************************************************");
            printf("\n\n                               Fin du Benchmark\n\n\n");
            printf("           Les resultats sont enregistres dans le fichier ");
            for(i=0;i<nb_caractere;i++) putchar(nom[i]);
            printf("\n\n\n\n********************************************************************************\n");
            }
            }
        else printf("\n\nerreur lors de l'ouverture du fichier\n\n");
        }
    else printf("\n\nerreur sur l'extension du fichier\n\n");
    }
    // fermeture du port
    SioDone(Port);
    if(part != 1)
    {
    system("Pause");
    }
    
	return 0;
}

// Vérification des erreurs de transmission sur liaison série

int ErrorCheck(int Code)
{
    if(Code<0)
        {
            printf("ERROR %d ",Code);
	        getch();
            SioDone(Port);
            exit(1);
        }
    return Code;
}

// Initialisation du port série COM1

void Init(void)
{
    ErrorCheck(SioReset(Port,1024,1024));
    ErrorCheck(SioBaud(Port,WSC_Baud38400));
    ErrorCheck(SioParms(Port,WSC_NoParity,WSC_OneStopBit,WSC_WordLength8));
    if(part != 2)
        {
        printf("\n\n********************************************************************************");
        printf("\n\n                               Debut du Benchmark\n");
        printf("\n\n********************************************************************************");
        }
    init_carte();
}


// démarrage de la carte

void init_carte (void)
{ 
     if (cible == C166)
     {              
         int y = 0;
         /*mise en run de la carte*/
         SioPutc(Port,0x00);
         while(y==0){y = SioRxQue(Port);if(y>0)  {putchar(SioGetc(Port));}}
         
         
         if(part != 2)
             {
             SioPutc(Port,0x06);
             SioPutc(Port,0x00);
             SioPutc(Port,0x08);
             SioPutc(Port,0xD6);
             SioPutc(Port,0xFF);
             SioPutc(Port,0xFF);
             SioPutc(Port,0xFF);
             SioPutc(Port,0x1F);
             y=0;
             while(y==0){y = SioRxQue(Port); if(y>0){SioGetc(Port);}}
             }
             
         else
             {
             SioPutc(Port,0x06);
             SioPutc(Port,0x00);
             SioPutc(Port,0x0A);
             SioPutc(Port,0x58);
             SioPutc(Port,0xFF);
             SioPutc(Port,0xFF);
             SioPutc(Port,0xFF);
             SioPutc(Port,0x9B);
             y=0;
             while(y==0){y = SioRxQue(Port); if(y>0){SioGetc(Port);}}
             }
        
    SioPutc(Port,0x11);
    
    SioPutc(Port,0x11);
    
    SioPutc(Port,0x11);
    
    SioPutc(Port,0x11);
    }   
}


int lecture (int *fin, FILE *pfile)
{
    // initialisation des variables
    int etat=0;
    int lu='a';
    int i = 0;
    
    // boucle pour une ligne de donnée, A : 56 us@
    while((lu!='@')&(*fin != 1))
        {
                          
        // on regarde s'il y a un caractère d'arrivé
        i = SioRxQue(Port);
        if(i>0)  {
                 
            // on récupère le caractère
            lu=SioGetc(Port);
            
            // les données se divisent en deux parties:
            //     - la lettre, état 0
            //     - la valeur, état 1       
            switch(etat)
                {
                        
                case 0:
                     if (lu == '*') {*fin=1; putchar('\n');break;} 
                     
                     if(lu == ':') etat = 1;
                     else
                         {
                         if(lu >= 'A')
                             {
                                  
                             if((lu-'A') != 0) fprintf(pfile,"\t");
                             
                             putchar('\n');
                                
                             if((lu-'A') < 42)
                                 {
                                 for (i=0;i<=28;i++) putchar(tab[lu-'A'][i]);
                                 }
                             else
                                 {
                                 printf("Function n%d :              ",lu-'A');
                                 }
                             }
                         }
                     break;
                              
                case 1:
                     if(lu == '@') {etat = 0; putchar('\n');}
                     else 
                         {
                         if(lu==0xB5){putchar('u');} // le µ n'est pas reconnu
                         else{
                             putchar(lu); // affichage du caractère
                             if((lu >= '0') & (lu<='9')) fprintf(pfile,"%c",lu);
                             }
                         }
                     break; 
                }
            }
    }
    return(*fin);
}


int verification_extension (char *nomfic, int *nb_caractere)
{
    int z = 0;
    
    *nb_caractere = 0;
    
    while (z < 3)
      {
        if(nomfic[*nb_caractere] == '.')
            {
            z=1;
            }
        else
          {
          if((((nomfic[*nb_caractere] >= 'A') & (nomfic[*nb_caractere] <= 'Z')) | ((nomfic[*nb_caractere] >= 'a') & (nomfic[*nb_caractere] <= 'z'))) & (z==1))z=2;
          else
              {
              if(z == 1)z=4;
              else
                  {
                  if((z == 2) & ((*nb_caractere == 20) |(nomfic[*nb_caractere]))) z=3;
                  else
                      {
                      if((nomfic[*nb_caractere] == ' ')&(z==0))
                          {
                          nomfic[(*nb_caractere)-1]='.';
                          nomfic[*nb_caractere]='c';
                          nomfic[(*nb_caractere)+1]='s';
                          nomfic[(*nb_caractere)+2]='v';
                          *nb_caractere +=2; 
                          z=3;
                          }
                      } 
                  }
              }
          }
      (*nb_caractere)++;
      }
      return (z);
}
