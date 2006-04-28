/*juste un tableau qui trie par ordre décroissant les temps d'execution en indiquant l'id*/


void tpl_task_terminated()
{	
	/* Déclarations */
 	int n=5;     /* variable pour la réecriture du tableau  */
	int i=0;     /* indice courant   */
	
	TaskType id;
	TimeType timeTask;
	GetTaskID(&id);
	
	GetTimeTask(id,&timeTask);
	
	printf("la tâche %d à mis %lu unité de temps à s'exécuter \n",id,timeTask);
	
	/* traitement du tableau de temps d'execution */
	/* tab_time[i][j] => i correspond a la ligne (suivant le temps) et j   */
	/* c'est l'id(si j=0) ou le temps d'exécution(si j=1)                  */
	for(i=0; i<5;i++){
		if (timeTask>tab_time[i][1]){
			for(n=5; n>i; n--){
				tab_time[n][1]=tab_time[n-1][1];
				tab_time[n][0]=tab_time[n-1][0];
			}

		tab_time[i][1]=timeTask;
		tab_time[i][0]=id;break;		
		}
 	}
	printf("la tache la plus longue est la tache %lu elle a durée %lu \n",tab_time[0][0],tab_time[0][1]);
 	for(i=1; i<5;i++){
 		printf("la %dème tache la plus longue est la tache %lu elle a durée %lu \n",(i+1),tab_time[i][0],tab_time[i][1]);
 	}
}