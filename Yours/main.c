#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char livres[100][100];
    char titles[100][100];
    char auteurs[100][100];
    float prix [100];
    int quantites[100];
    int livre_count =0;
    char title[30];
    char auteur[30];
    float prix_a ;
    int quantite;
    int choix;
    int a;
    while(a!=7){
        printf("1 pour ajouter \n");
        printf("2 pour afficher \n");
        printf("3 pour Rechercher \n");
        printf("4 pour Mettre  jour  \n");
        printf("5 pour Supprimer \n");
        printf("6 pour Afficher le nombre tota \n");
        printf("7 Quittez\n");
        printf("Entrez votre choix \n");
        scanf("%d",&choix);

    switch(choix){
        case 1: {
            printf("---------entrez le title:-------------");
            scanf("%s",titles[livre_count]);
            printf("---------entrez l'auteur:-------------");
            scanf("%s",auteurs[livre_count]);
            printf("---------entrez le Prix a:------------|");
            scanf("%f",&prix_a);
            printf("---------entrez le quantité:----------|");
            scanf("%d",&quantite);
            //kanfar9o les infos dial livre entreée par user eala ga3 tableau dans le meme index
           //titles[livre_count]= title;
            //auteurs[livre_count]= auteur;
            prix[livre_count]= prix_a;
            quantites[livre_count]= quantite;


            livre_count ++;
            break;
        }
        case 2: {
            //if(livre_count>0){

                for(int i=0;i<livre_count;i++){
                    printf("%s,%s,%f,%d \n",titles[i],auteurs[i],prix[i],quantites[i]);
            }
       // }else{
       //             printf("No livre en stock \n");
              //  }
               // break;
        }
        case 3: {
                if(livre_count>0){
                    printf("entrer le title:");
                    scanf("%s",&title);
                    int i,founded=0;
                    for (i=0;i<livre_count;i++){
                    if(strcmp(title,titles[i])==0){
                        printf("%s , %s , %f ,%d \n",titles[i],auteurs[i],prix[i],quantites[i]);
                        founded=1;
                        break;
                    }
                }if(!founded){
                            printf("no livre avec ce titre");
                }
                }else{
                    printf("No livre en stock \n");
                }
                break;
                }
        case 4: {
            if(livre_count>0){
                printf("Entrez le titre:");
                scanf("%s",&title);
                printf("Entrez nouveau quantite:");
                scanf("%d",&quantite);
                int i,updated;
                for (i=0;i<livre_count;i++){
                    if(strcmp(title,titles[i])==0){
                        quantites[i]=quantite;
                        updated=1;

                    }
                }
                if(!updated){
                    printf("no livre avec ce titre");
                }
                }else{
                    printf("No livre en stock \n");
                }
                break;
            }
        case 5: {
            if(livre_count>0){
                printf("Entrez le titre:");
                scanf("%s",title);
                int deleted=0;
                for (int i=0; i<livre_count;i++){
                    if(strcmp(title,titles[i])==0){
                        livre_count--;
                        for(int j=i; j<livre_count-1;j++){
                             strcpy(titles[j], titles[j+1]);
                             strcpy(auteurs[j], auteurs[j+1]);
                            // titles[j]= titles[j+1];
                            //auteurs[j]= auteurs[j+1];
                             prix[j]= prix[j+1];
                             quantites[j]= quantites[j+1];
                             deleted =1;
                        }
                    }
                    printf("VOTRE livre est suprimer correctement \n");
                }

                }else{
                    printf("No livre en stock \n");
                }
                break;

                }

            case 6: {
                printf("le nombre total des livres est: %d \n",livre_count);
                break;

            }

             default: {
                printf("Otion invalid \n");
                break;

             }
            case 7:
                exit(0);
}}

    return 0;
}
