#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void insertionSort (int *vetor, int tam){           // Função do InsertionSort.
	int j;
	int chave;
	int i;
	for (j = 1; j < tam; j++){                      // Loop para ordenar.
		
		chave = vetor[j];
		i = j - 1;
		while (i > -1 && vetor[i] > chave){
			vetor[i+1] = vetor[i];
			i--;
		}
		vetor[i+1] = chave;
	}
}

void selectionSort( int * v, int max){              // Função do SelectionSort.
	int i,j,min,aux;
 	for (i=0; i<max; i++){                          // Loop para ordenar.
	 	min = i;
 		for (j=i+1; j< max; j++){ 
			if ( v[j]<v[min]){
 				min = j;
			}
 		}
 		aux= v[i];
 		v[i]=v[min];
 		v[min]=aux;
 	}
}

void merge (int v[], int p, int q, int r ){         // Função do Merge
	int size_aux = r - p;
	int* w = malloc (size_aux * sizeof(int)); 
	int i = p; 
	int j = q;
	int k = 0;
 	while( i < q && j < r ){                        // Loop para ordenar
		if( v[ i ] <= v[ j ] ){
 			w[ k++ ] = v[ i++ ];
 		}
 		else{
 			w[ k++ ] = v[ j++ ];
 		}
 	}
 	while ( i < q ){
		w[ k++ ] = v[ i++ ];
	}
 	while ( j < r ){
		w[ k++ ] = v[ j++ ];
	}
 	for( i = p; i < r; ++i ){
		v[ i ] = w[ i - p ];
	}
}

void mergesort (int v[], int p, int r ){            // Função do MergeSort para chamar recursivamente o Merge.
	if( p < r - 1 ){ 
		int q = ( p + r ) / 2; 
		mergesort(v, p, q );
		mergesort(v, q, r );
		merge(v, p, q, r );
 	}
}

void shellsort(int* vetor, int n){                  // Função do ShellSort.	
	int i, j;
	int h = 1;
	int x;
	do{                                             // Loop para escolher o pivô.
		h = h * 3 + 1;
	}while(h < n);
	do{                                             // Loop para ordenar.
		h /= 3;
		for(i = h; i < n; i++){	
			x = vetor[i];
			j = i - h;
			while(j >= 0 && vetor[j] > x){	
				vetor[j + h] = vetor[j];
				j -= h;
			}
			vetor[j + h] = x;
		}		
	}while(h != 1); 	
}

void heapsort(int a[], int n) {                     // Função do HeapSort.
	
	int i = n / 2, esq, dir, t;
	
	while(1) {                                      // Loop para ordenar.
		
		if (i > 0) {
			i--;
 			t = a[i];
		}else {
			n--;
			if (n == 0) return;
   			t = a[n];
			a[n] = a[0];
  		}
 		esq = i;
   		dir = i * 2 + 1;
   		
 		while (dir < n) {
  			if ((dir + 1 < n)  &&  (a[dir + 1] > a[dir]))
				dir++;
				
			if (a[dir] > t) {
 				a[esq] = a[dir];
 				esq = dir;
 				dir = esq * 2 + 1;
  			} else {
				break;
			}
		}
		a[esq] = t;
	}
}
void particao(int* elements, int esq, int dir, int *i, int *j){  // Função para criar partição do QuickSort.
     int x, w;
     *i = esq;
     *j = dir;
     x = elements[(*i + *j) / 2];
     do{
         while(x > elements[*i]) (*i)++;
         while(x < elements[*j]) (*j)--;
         if(*i <= *j){
               w = elements[*i];
               elements[*i] = elements[*j];
               elements[*j] = w;
               (*i)++;
               (*j)--;
         }
     }while(*i <= *j);
}

void ordena(int* elements, int esq, int dir){              // Função de ordenar para o quicksort.
     int i, j;
     particao(elements, esq, dir, &i, &j);
     if(esq < j){
          ordena(elements, esq, j);
     }
     if(i < dir){
          ordena(elements, i, dir);
     }     
}

double quicksort(int *elements, int n){                    // Função do QuickSort.
       ordena(elements, 0, n-1);                           // Chamar função para ordenar.
}
 
void preenche (int *vetor, int tam){                       // Função para criar Vetores.
	int i, valor;
	char opcao;
	fflush(stdin);
	printf("Digite:\nr: randomico\nc: crescente\nd: decrescente\n");
	fflush(stdin);	 
    scanf("%c", &opcao);	 
	fflush(stdin);	
	if(opcao == 'r'){                                      // Criar vetor Randomico.
		for(i = 0; i < tam; i++){	 
			vetor[i] = rand()%100000;
		}
	}
	else {
		if(opcao == 'c'){                                  // Criar vetor crescente.
		    valor = rand()%100000;  
		    for(i = 0; i < tam; i++){
		      	vetor[i] = valor++;			   		
			} 
		}
		else {
			if(opcao == 'd'){                              // Criar vetor Decrescente.
		     	valor = rand()%100000; 
		      	for(i = 0; i < tam; i++){			  
					vetor[i] = valor--;
			   	}
		    }
		   	else{                                          // Se não existe a opção preenche crescente.
		       printf("Opcao invalida.\nVetor preenchido em ordem crescente.\n");
		       valor = rand()%100000;  
			   for(i = 0; i < tam; i++){
			      vetor[i] = valor++;
			   } 
		   	}
		}
	}
}

void imprmir (int *vetor, int tam){                               // Função para printar vetor na tela.
	int i;
	for (i = 0; i < tam; i++){
		printf("%d\n", vetor[i]);
	}
	printf("\n");
}

int main (){
	srand(time(NULL));
	int *vet, tamanhoIntancia, op, i, opcao;
	char entrada[101], saida[101], arquivotempo[101];
	clock_t tempo;
	FILE *pFile;
	do{                                                           // Loop para menu.
	   printf("MENU\n1- Vetor\n2- Arquivo\n3- Sair\n");
	   scanf("%d", &op);
	   switch (op){                                               // Switch case para opção de algoritmo de ordenação.
	      case 1:                                                 // Case 1 apenas mostra vetor e imprimi.
	         do{
	    	    printf("1-InsertionSort\n2-SelectionSort\n3-MergeSort\n4-ShellSort\n5-HeapSort\n6-QuickSort\n7-Sair\n");
		    	scanf("%d", &opcao);
		    	switch (opcao){
		    	   case 1:
		    	      printf("Digite o tamanho da instancia: ");
		         	  scanf ("%d", &tamanhoIntancia);
					  vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					  if(vet == NULL){
			      	     printf("Nao ha memoria suficiente.\n");
			      	     exit (1);
			   		  }
			   		  else{
			      	     preenche (vet, tamanhoIntancia);
			      		 printf("Sequencia criada:\n");
			      		 imprmir (vet, tamanhoIntancia);
			      		 tempo = clock();
						 insertionSort (vet, tamanhoIntancia);
						 tempo =clock()-tempo; 
			      		 printf("Sequencia ordenada:\n");
			      		 imprmir (vet, tamanhoIntancia);
			      		 printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		  }
			   		  break;
					case 2:
		         		printf("Digite o tamanho da instancia: \n");
				        scanf ("%d", &tamanhoIntancia);
					    vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					    if(vet == NULL)
			   		    {
			      		    printf("Nao ha memoria suficiente\n");
			      		    exit (1);
			   		    }
			   		    else
			   		    {
			      		    preenche (vet, tamanhoIntancia);
			      		    printf("Sequencia criada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    tempo = clock();
							selectionSort (vet, tamanhoIntancia);
							tempo =clock()-tempo; 
			      		    printf("Sequencia ordenada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		    }
			   		    break;
			   		case 3:
			   			printf("Digite o tamanho da instancia: \n");
				        scanf ("%d", &tamanhoIntancia);
					    vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					    if(vet == NULL)
			   		    {
			      		    printf("Nao ha memoria suficiente.\n");
			      		    exit (1);
			   		    }
			   		    else
			   		    {
			      		    preenche (vet, tamanhoIntancia);
			      		    printf("Sequencia criada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    tempo = clock();
							mergesort (vet, 0, tamanhoIntancia);
							tempo =clock()-tempo; 
			      		    printf("Sequencia ordenada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		    }
                    break;
 		            case 4:
   			   			printf("Digite o tamanho da instancia: \n");
				        scanf ("%d", &tamanhoIntancia);
					    vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					    if(vet == NULL)
			   		    {
			      		    printf("Nao ha memoria suficiente.\n");
			      		    exit (1);
			   		    }
			   		    else
			   		    {
			      		    preenche (vet, tamanhoIntancia);
			      		    printf("Sequencia criada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    tempo = clock();
							shellsort (vet, tamanhoIntancia);
							tempo =clock()-tempo; 
			      		    printf("Sequencia ordenada:\n");
			      		    imprmir (vet, tamanhoIntancia);
			      		    printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		    }
                    break;
                    case 5:
                          printf("Digite o tamanho da instancia: ");
		         	      scanf ("%d", &tamanhoIntancia);
					      vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					      if(vet == NULL){
			      	             printf("Nao ha memoria suficiente.\n");
			      	             exit (1);
   		                  }
			   		      else{
			      	           preenche (vet, tamanhoIntancia);
			      		       printf("Sequencia criada:\n");
			      		       imprmir (vet, tamanhoIntancia);
			      		       tempo = clock();
						       heapsort (vet, tamanhoIntancia-1);
						       tempo =clock()-tempo; 
			      		       printf("Sequencia ordenada:\n");
			      		       imprmir (vet, tamanhoIntancia);
                               printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		      }
                          break;
                    case 6:
       		    	      printf("Digite o tamanho da instancia: ");
		         	      scanf ("%d", &tamanhoIntancia);
					      vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					      if(vet == NULL){
                              printf("Nao ha memoria suficiente.\n");
                              exit (1);
			   		      }
			   		      else{
			      	           preenche (vet, tamanhoIntancia);
			      		       printf("Sequencia criada:\n");
			      		       imprmir (vet, tamanhoIntancia);
			      		       tempo = clock();
						       quicksort (vet, tamanhoIntancia);
						       tempo =clock()-tempo; 
			      		       printf("Sequencia ordenada:\n");
			      		       imprmir (vet, tamanhoIntancia);
	      		               printf("Tempo da execucao ate o momento: %f \n", ((float)tempo)/CLOCKS_PER_SEC);
			   		     }
                         break;      
   		 	        case 7:
  		 		         exit(1);
  		 		         break;	
					default:
                         printf("Opcao Invalida.\n");
					
				}			   		 	
	   		 }while (opcao != 7);
   		     break;
   	      case 2:                                                  // Case 2 ordena e grava no arquivo.
			do{
				
				printf("1-InsertionSort\n2-SelectionSort\n3-MergeSort\n4-ShellSort\n5-HeapSort\n6-QuickSort\n7-Sair\n");
		    	scanf("%d", &opcao);
				
				switch(opcao){
					case 1:
						 printf("Digite o tamanho da instancia: \n");
				         scanf ("%d", &tamanhoIntancia);
					     vet = (int *) malloc (tamanhoIntancia * sizeof (int));
					     printf("Digite o nome da entrada:\n");
						 scanf("%s",entrada);
						 strcat(entrada,".txt");
						 printf("Digite o nome da saida:\n");
						 scanf("%s", saida);
						 strcat(saida,".txt");
						 printf("Digite o nome da tempo:\n");
						 scanf("%s", arquivotempo);
						 strcat(arquivotempo,".txt");
					     if(vet == NULL)
			   		     {
			      		    printf("Nao ha memoria suficiente.\n");
			      		    exit (1);
			   		     }
			   		     else
			   		     {
			      		    preenche (vet, tamanhoIntancia);
			      		
			      		    pFile = fopen(entrada,"w");
							while(pFile == NULL)
							{
								printf("Erro na criacao do arquivo.\n");
								exit(1);
							}
							fprintf(pFile, "%d\n", tamanhoIntancia);
							for(i = 0; i < tamanhoIntancia; i++)
							{
								fprintf(pFile, "%d\n", vet[i]);
							}
							fclose(pFile);
							printf("A sequencia foi salva com sucesso.\n");
							
							pFile = fopen(entrada,"r");
							fscanf(pFile, "%d", &tamanhoIntancia);
							for(i = 0; i < tamanhoIntancia; i++)
							{
								fprintf(pFile, "%d", &vet[i]);
							}
							fclose(pFile);
							
							tempo = clock();
							insertionSort (vet, tamanhoIntancia);
							tempo =clock()-tempo;
							
							pFile = fopen(saida,"w");
							while(pFile == NULL)
							{
								printf("Erro na criacao do arquivo.");
								exit(1);
							}
							fprintf(pFile, "%d\n", tamanhoIntancia);
							for(i = 0; i < tamanhoIntancia; i++)
							{
								fprintf(pFile, "%d\n", vet[i]);
							}
							fclose(pFile);
							printf("A sequencia ordenada foi salva com sucesso.\n");
							
			      		    ((float)tempo)/CLOCKS_PER_SEC;
							
							pFile = fopen(arquivotempo,"w");
							while(pFile == NULL)
							{
								printf("Erro na criacao do arquivo.\n");
								exit(1);
							}
							fprintf(pFile, "%.20f",((float)tempo)/CLOCKS_PER_SEC);
							fclose(pFile);
							printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
      		 			}
      		 			break;
      		 			case 2:
							 printf("Digite o tamanho da instancia: \n");
					         scanf ("%d", &tamanhoIntancia);
						     vet = (int *) malloc (tamanhoIntancia * sizeof (int));
						     printf("Digite o nome da entrada:\n");
							 scanf("%s",entrada);
							 strcat(entrada,".txt");
							 printf("Digite o nome da saida:\n");
							 scanf("%s", saida);
							 strcat(saida,".txt");
							 printf("Digite o nome da tempo:\n");
							 scanf("%s", arquivotempo);
							 strcat(arquivotempo,".txt");
						     if(vet == NULL)
				   		     {
				      		    printf("Nao ha memoria suficiente.\n");
				      		    exit (1);
				   		     }
				   		     else
				   		     {
				      		    preenche (vet, tamanhoIntancia);
				      		
				      		    pFile = fopen(entrada,"w");
								while(pFile == NULL)
								{
									printf("Erro na criacao do arquivo.\n");
									exit(1);
								}
								fprintf(pFile, "%d\n\n", tamanhoIntancia);
								for(i = 0; i < tamanhoIntancia; i++)
								{
									fprintf(pFile, "%d\n", vet[i]);
								}
								fclose(pFile);
								printf("A sequencia foi salva com sucesso.\n");
								
								pFile = fopen(entrada,"r");
								fscanf(pFile, "%d", &tamanhoIntancia);
								for(i = 0; i < tamanhoIntancia; i++)
								{
									fprintf(pFile, "%d", &vet[i]);
								}
								fclose(pFile);
								
								tempo = clock();
								selectionSort (vet, tamanhoIntancia);
								tempo =clock()-tempo;
								
								pFile = fopen(saida,"w");
								while(pFile == NULL)
								{
									printf("Erro na criacao do arquivo.\n");
									exit(1);
								}
								fprintf(pFile, "%d\n", tamanhoIntancia);
								for(i = 0; i < tamanhoIntancia; i++)
								{
									fprintf(pFile, "%d\n", vet[i]);
								}
								fclose(pFile);
								printf("A sequencia ordenada foi salva com sucesso.\n");
								
				      		    ((float)tempo)/CLOCKS_PER_SEC;
								
								pFile = fopen(arquivotempo,"w");
								while(pFile == NULL)
								{
									printf("Erro na criacao do arquivo.\n");
									exit(1);
								}
								fprintf(pFile, "%f",((float)tempo)/CLOCKS_PER_SEC);
								fclose(pFile);
								printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
	      		 			}
	      		 			break;
	      		 			case 3:
								 printf("Digite o tamanho da instancia: \n");
						         scanf ("%d", &tamanhoIntancia);
							     vet = (int *) malloc (tamanhoIntancia * sizeof (int));
							     printf("Digite o nome da entrada:\n");
								 scanf("%s",entrada);
								 strcat(entrada,".txt");
								 printf("Digite o nome da saida:\n");
								 scanf("%s", saida);
								 strcat(saida,".txt");
								 printf("Digite o nome da tempo:\n");
								 scanf("%s", arquivotempo);
								 strcat(arquivotempo,".txt");
							     if(vet == NULL)
					   		     {
					      		    printf("Nao ha memoria suficiente.\n");
					      		    exit (1);
					   		     }
					   		     else
					   		     {
					      		    preenche (vet, tamanhoIntancia);
					      		
					      		    pFile = fopen(entrada,"w");
									while(pFile == NULL)
									{
										printf("Erro na criacao do arquivo.\n");
										exit(1);
									}
									fprintf(pFile, "%d\n", tamanhoIntancia);
									for(i = 0; i < tamanhoIntancia; i++)
									{
										fprintf(pFile, "%d\n", vet[i]);
									}
									fclose(pFile);
									printf("\nA sequencia foi salva com sucesso.\n");
									
									pFile = fopen(entrada,"r");
									fscanf(pFile, "%d", &tamanhoIntancia);
									for(i = 0; i < tamanhoIntancia; i++)
									{
										fprintf(pFile, "%d", &vet[i]);
									}
									fclose(pFile);
									
									tempo = clock();
									mergesort (vet, 0, tamanhoIntancia);
									tempo =clock()-tempo;
									
									pFile = fopen(saida,"w");
									while(pFile == NULL)
									{
										printf("Erro na criacao do arquivo.\n");
										exit(1);
									}
									fprintf(pFile, "%d\n", tamanhoIntancia);
									for(i = 0; i < tamanhoIntancia; i++)
									{
										fprintf(pFile, "%d\n", vet[i]);
									}
									fclose(pFile);
									printf("A sequencia ordenada foi salva com sucesso.\n");
									
					      		    ((float)tempo)/CLOCKS_PER_SEC;
									
									pFile = fopen(arquivotempo,"w");
									while(pFile == NULL)
									{
										printf("Erro na criacao do arquivo.\n");
										exit(1);
									}
									fprintf(pFile, "%f",((float)tempo)/CLOCKS_PER_SEC);
									fclose(pFile);
									printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
		      		 			}
		      		 			break;
		      		 			case 4:
      							     printf("Digite o tamanho da instancia: \n");
					                 scanf ("%d", &tamanhoIntancia);
						             vet = (int *) malloc (tamanhoIntancia * sizeof (int));
						             printf("Digite o nome da entrada:\n");
							         scanf("%s",entrada);
							         strcat(entrada,".txt");
							         printf("Digite o nome da saida:\n");
							         scanf("%s", saida);
							         strcat(saida,".txt");
							         printf("Digite o nome da tempo:\n");
							         scanf("%s", arquivotempo);
							         strcat(arquivotempo,".txt");
						             if(vet == NULL)
				   		             {
    		                              printf("Nao ha memoria suficiente.\n");
   		                                  exit (1);
				   		             }
				   		             else
				   		             {       
				      		              preenche (vet, tamanhoIntancia);
				      		
				      		              pFile = fopen(entrada,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
								          }
								          fprintf(pFile, "%d\n\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
						                       fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia foi salva com sucesso.\n");
								
								          pFile = fopen(entrada,"r");
								          fscanf(pFile, "%d", &tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d", &vet[i]);
								          }
								          fclose(pFile);
								
								          tempo = clock();
								          shellsort (vet, tamanhoIntancia);
								          tempo =clock()-tempo;
								
								          pFile = fopen(saida,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
                                          }
								          fprintf(pFile, "%d\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia ordenada foi salva com sucesso.\n");
								
				      		              ((float)tempo)/CLOCKS_PER_SEC;
								
								          pFile = fopen(arquivotempo,"w");
								          while(pFile == NULL)
								          {
									            printf("Erro na criacao do arquivo.\n");
									            exit(1);
								          }
								          fprintf(pFile, "%f",((float)tempo)/CLOCKS_PER_SEC);
								          fclose(pFile);
								          printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
                                     }
 			                         break;
                             case 5:
						             printf("Digite o tamanho da instancia: \n");
					                 scanf ("%d", &tamanhoIntancia);
						             vet = (int *) malloc (tamanhoIntancia * sizeof (int));
						             printf("Digite o nome da entrada:\n");
							         scanf("%s",entrada);
							         strcat(entrada,".txt");
							         printf("Digite o nome da saida:\n");
							         scanf("%s", saida);
							         strcat(saida,".txt");
							         printf("Digite o nome da tempo:\n");
							         scanf("%s", arquivotempo);
							         strcat(arquivotempo,".txt");
						             if(vet == NULL)
				   		             {
    		                              printf("Nao ha memoria suficiente.\n");
   		                                  exit (1);
				   		             }
				   		             else
				   		             {       
				      		              preenche (vet, tamanhoIntancia);
				      		
				      		              pFile = fopen(entrada,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
								          }
								          fprintf(pFile, "%d\n\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
						                       fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia foi salva com sucesso.\n");
								
								          pFile = fopen(entrada,"r");
								          fscanf(pFile, "%d", &tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d", &vet[i]);
								          }
								          fclose(pFile);
								
								          tempo = clock();
								          heapsort (vet, tamanhoIntancia-1);
								          tempo =clock()-tempo;
								
								          pFile = fopen(saida,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
                                          }
								          fprintf(pFile, "%d\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia ordenada foi salva com sucesso.\n");
								
				      		              ((float)tempo)/CLOCKS_PER_SEC;
								
								          pFile = fopen(arquivotempo,"w");
								          while(pFile == NULL)
								          {
									            printf("Erro na criacao do arquivo.\n");
									            exit(1);
								          }
								          fprintf(pFile, "%f",((float)tempo)/CLOCKS_PER_SEC);
								          fclose(pFile);
								          printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
                                     }
                                     break;
                               case 6:
                                     printf("Digite o tamanho da instancia: \n");
					                 scanf ("%d", &tamanhoIntancia);
						             vet = (int *) malloc (tamanhoIntancia * sizeof (int));
						             printf("Digite o nome da entrada:\n");
							         scanf("%s",entrada);
							         strcat(entrada,".txt");
							         printf("Digite o nome da saida:\n");
							         scanf("%s", saida);
							         strcat(saida,".txt");
							         printf("Digite o nome da tempo:\n");
							         scanf("%s", arquivotempo);
							         strcat(arquivotempo,".txt");
						             if(vet == NULL)
				   		             {
    		                              printf("Nao ha memoria suficiente.\n");
   		                                  exit (1);
				   		             }
				   		             else
				   		             {       
				      		              preenche (vet, tamanhoIntancia);
				      		
				      		              pFile = fopen(entrada,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
								          }
								          fprintf(pFile, "%d\n\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
						                       fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia foi salva com sucesso.\n");
								
								          pFile = fopen(entrada,"r");
								          fscanf(pFile, "%d", &tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d", &vet[i]);
								          }
								          fclose(pFile);
								
								          tempo = clock();
								          quicksort (vet, tamanhoIntancia-1);
								          tempo =clock()-tempo;
								
								          pFile = fopen(saida,"w");
								          while(pFile == NULL)
								          {
                                               printf("Erro na criacao do arquivo.\n");
									           exit(1);
                                          }
								          fprintf(pFile, "%d\n", tamanhoIntancia);
								          for(i = 0; i < tamanhoIntancia; i++)
								          {
									           fprintf(pFile, "%d\n", vet[i]);
								          }
								          fclose(pFile);
								          printf("A sequencia ordenada foi salva com sucesso.\n");
								
				      		              ((float)tempo)/CLOCKS_PER_SEC;
								
								          pFile = fopen(arquivotempo,"w");
								          while(pFile == NULL)
								          {
									            printf("Erro na criacao do arquivo.\n");
									            exit(1);
								          }
								          fprintf(pFile, "%f",((float)tempo)/CLOCKS_PER_SEC);
								          fclose(pFile);
								          printf("O tempo de execucao ate o momento foi salvo com sucesso.\n");
                                     }
                                     break;
		      		 			     case 7:
		      		 				      exit(1);
		      		 				      break;
      		 			             default:
	         						         printf("Opcao Invalida.\n");
		      		 				
				}
					
			}while(opcao != 7);
   	         break;
          case 3:
             exit (1);
             break;
	      default:
	         printf("Opcao Invalida.\n");
	   }
	   
	}while (op != 3);
	
   
   free (vet);
   getch ();
   return 0;
}
