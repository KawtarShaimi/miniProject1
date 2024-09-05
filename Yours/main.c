#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char titles[100][100] , auteurs[100][100];
    float prix [100];
    int quantites[100];
    int livre_count =0 , quantite , choix , i , j, deleted = 0 , updated = 0 , founded = 0;
    char title[30] , auteur[30];
    float prix_a ;

    while(1){
        printf("1-Pour ajouter un livre \n");
        printf("2-Pour afficher un livre \n");
        printf("3-Pour Rechercher un livre par son titre \n");
        printf("4-Pour Mettre a jour la quantite d'un livre  \n");
        printf("5-Pour Supprimer un livre par son titre \n");
        printf("6-Pour Afficher le nombre total des livre \n");
        printf("7-Pour quittez \n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);

        switch(choix){
            case 1: {
                printf("Entrez le title de livre : ");
                scanf("%s",&title);
                printf("Entrez l'auteur de livre : ");
                scanf("%s",&auteur);
                printf("Entrez le prix de livre : ");
                scanf("%f",&prix_a);
                printf("Entrez le quantite de livre : ");
                scanf("%d",&quantite);
            //kanfar9o les infos dial livre entre�e par user eala ga3 tableau dans le meme index
            //makn9duch ndiru affectation string to string, kn7oto la valeur dial title f T[livre-count]
                strcpy(titles[livre_count], title);
                strcpy(auteurs[livre_count], auteur);
                prix[livre_count]= prix_a;
                quantites[livre_count]= quantite;
                livre_count ++;
                break;
            }
            case 2: {
                if(livre_count>0){
                    for(i=0;i<livre_count;i++){
                        printf("%s, %s, %.2f DH, %d \n",titles[i],auteurs[i],prix[i],quantites[i]);
                   }
                }else{
                    printf("No livre en stock \n");
                }
                break;
            }
            case 3: {
                if(livre_count>0){
                    printf("entrer le title:");
                    scanf("%s",&title);
                    for (i=0;i<livre_count;i++){
                       if(strcmp(title,titles[i])==0){
                            printf("%s, %s, %.2f DH, %d \n",titles[i],auteurs[i],prix[i],quantites[i]);
                            founded=1;
                            break;
                        }
                    }
                    if(!founded){
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
                   for (i=0; i<livre_count;i++){
                        if(strcmp(title,titles[i])==0){
                            livre_count--;
                            //j=i commençant par l'index de livre trouvé
                            for(j=i; j<livre_count;j++){
                                    /* remplacement des infos de livre supprimer par le précedent j+1 */
                                strcpy(titles[j], titles[j+1]);
                                strcpy(auteurs[j], auteurs[j+1]);
                                prix[j]= prix[j+1];
                                quantites[j]= quantites[j+1];
                            }
                            deleted =1;
                            break;
                        }
                    }
                    if(!deleted){
                        printf("no livre avec ce titre\n");
                    }else{
                        printf("Le livre est suprimer correctement \n");
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
            case 7: {
                return 0;
            }
            default: {
                printf("Cette option est invalid \n");
                break;
            }
        }
        if(livre_count == 100){
            break;
        }
    }
    return 0;
}
