#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    
    char teamName1[20];
    char teamName[10][20];
    int teamInfo[10][5];
    int teamPoint1;
    int inputInt;
//for 1st input-------------------------------------    
    int pointBeraber;
    int pointGalip;
    int pointYenilgi;
    int pointToplam;
//2nd---------------------------------------------------    
    int pointsOfTeams[10];
    int maxim=-100;
    int minim1=100;
    int minim2=100;
    int maxTeamName;
    int minTeamName1;
    int minTeamName2;
    int maxteam2;
    int minteam2_2;
    int z=0;
    int retDeger;
    int k;
    int y;
    
    bool avDefiner =false;
    bool a;
    bool avDefinerAz= false;
//4th-------------------------------------------------    
    int inputGir;
    char comp[5];
    char findChar[20];
    char supporting[20];
    char endElement[20];
    char *ret;
    char ReverseStr[10][20];
    char revFind[20];
 	
    
    /* In this project, user will add 10x6 matrix with this order:
	besiktas 12 2 3 30 5
    fenerbahce 13 2 3 39 5
    galatasaray -5 2 3 28 6
	fener -5 2 3 28 5
	kasýmpasa -10 4 3 32 5
	kabatas 6 7 3 2 5
	g 5 3 3 30 5
	h 13 9 3 30 3
	i 12 2 3 30 5
	j 12 2 3 30 5*/
	
	/* 
	1st column : Team name, 
	2nd column : Number of wins, 
	3rd column : Number of loses
	4th column : Number of draws
	5th column : Goals scored
	6th column : Goals conceded
	*/
 
  
  for(int i=0;i<10;i++){
  scanf("%s",teamName[i]);
  for(int j =0;j<5;j++){
      
  scanf(" %d", &teamInfo[i][j]);
  
  }
  }
  
  for(int i=0;i<10;i++){
      pointGalip = teamInfo[i][0]*3;
      pointYenilgi= teamInfo[i][1]*-1;
      pointBeraber= teamInfo[i][2]*1;
      pointsOfTeams[i]= pointBeraber+pointYenilgi+pointGalip;
  }
  printf("\n");
  printf("You can see the team names and points in this table.\n");
  for(int i=0;i<10;i++){
  	printf("%s", teamName[i]);
  	printf("  ");
  	printf("%d\n", pointsOfTeams[i]);

  }
  printf("\n");
  printf("Enter an input between 1-5.\n 1- Questioning team by team name\n 2- Who is the champion?\n 3- Which team is relegated? \n 4- General inquiry\n 5- Quit the program. \n");
  
	
  loop:
  inputInt= 10;
  
  scanf(" %d", &inputInt);
 // 1. durum ----------------------------------------------------------------------------
  if(inputInt==1){
  	 printf("Enter a team name: ");
  	 
     scanf(" %s", teamName1);
     for(int i=0;i<5;i++){
        if(strcmp(teamName[i],teamName1)==0){
            teamPoint1=i;
            
            break;
        }
     }
     
    pointToplam= pointsOfTeams[teamPoint1];
    
     printf("Total point: ");
     printf("%d\n", pointToplam);
     goto loop;
     
     }
// 2. durum -----------------------------------------------------------------------------     

     else if(inputInt==2){
           for(int i=0;i<10;i++){
         	 
                if(maxim<pointsOfTeams[i]){
                 maxim = pointsOfTeams[i];
                 maxTeamName = i;
               }
        
             
         }
            for(int i=0;i<10;i++){
             	if(i==maxTeamName){
             		i++;
				 }
				 else if(maxim==pointsOfTeams[i]){
				 	maxteam2= i;
				 	avDefiner =true;
				 	
				 }
			 }
		  if(avDefiner==true){
		  	if((teamInfo[maxTeamName][3]-teamInfo[maxTeamName][4]) > (teamInfo[maxteam2][3]-teamInfo[maxteam2][4])){
		  		printf("Team which has the highest point:  ");
		  		printf(" %s\n", teamName[maxTeamName]);
		  		goto loop;
			  }
			  else{
			  	printf("Team which has the highest point:  ");
			  	printf(" %s\n", teamName[maxteam2]);
			  	goto loop;
			  	
			  }
		  	
		  }
		  else{
		  	printf("Team which has the highest point:  ");
		  	printf(" %s\n", teamName[maxTeamName]);
		  	goto loop;
		  }
         // PUAN EÞÝTLÝÐÝ DURUMUNU YAZ
         
     }
     
// 3. durum --------------------------------------------------------------------------   

     else if (inputInt==3){
        for(int i=0;i<10;i++){
             if(minim1>pointsOfTeams[i]){
                 minim1 = pointsOfTeams[i];
                 minTeamName1 =i;
                 
                 
                 
             }
             
         }
     
         //burayý kontrol et--------------------
         for(int i=0;i<10;i++){
         	 if(minTeamName1 ==i ){
         	 	i++;
         	 
		}
             else if(minim2>pointsOfTeams[i]){
                 minim2 = pointsOfTeams[i];
                 minTeamName2 =i;
                 
             }
            
     
         }
         for(int i=0;i<10;i++){
             	if(i==minTeamName2||i==minTeamName1){
             		i++;
				 }
				 else if(minim2==pointsOfTeams[i]){
				 	
				 	minteam2_2 = i;
				 	avDefiner =true;
				 	
				 }
			 }
		  if(avDefinerAz==true){
		  	if((teamInfo[minteam2_2][3]-teamInfo[minteam2_2][4]) > (teamInfo[minTeamName2][3]-teamInfo[minTeamName2][4])){
		  		printf(" %s", teamName[minTeamName2]);
		  		goto loop;
			  }
			  else{
			  	printf(" %s", teamName[minteam2_2]);
			  	goto loop;
			  }
		  	
		  }
		  else{
		  	printf(" %s\n", teamName[minTeamName1]);
		  	printf(" %s\n", teamName[minTeamName2]);
		  	goto loop;
		  	
		  }
   
     }
// 4. durum---------------------------------------------------------------------------------------------

        else if (inputInt==4){
            scanf(" %s %s",teamName1, comp );
      		if(strcmp(teamName1,"takim")==0){
      			scanf(" %s", findChar );
      		}
      		else	{
      			scanf(" %d",&inputGir );
			  }
			  
            if(strlen(findChar)>1){
						
                    	
                    		for(int j = 0; findChar[j] != '\0'; j++)
    						{
       						 k = j;
       						 y = j;
   							}
                    			
    						for(int z = 0; z <= y; z++)
    						{
    						
       						revFind[z] = findChar[k];
       						k--;

							}
							
							
						}
  
            
            
            if(strcmp(teamName1,"agol")==0){
                for(int i =0;i<10;i++){
                    if(strcmp(comp,"<")==0){
                        
                            if(teamInfo[i][3]<inputGir){
                                printf("%s\n", teamName[i]);
                                
                            }
                     }
                    else if(strcmp(comp,">")==0){
                        
                            if(teamInfo[i][3]>inputGir){
                                printf("%s\n", teamName[i]);
                                
                            }
                    }
                    else if(strcmp(comp,"=")==0){
                       
                            if(teamInfo[i][3]==inputGir){
                                printf("%s\n", teamName[i]);
                                
                            }
                    }   
                
                }       
             goto loop;
            }
            if(strcmp(teamName1,"puan")==0){
                for(int i =0;i<10;i++){
                    if(strcmp(comp,"<")==0){
                        
                            if(pointsOfTeams[i]<inputGir){
                                printf("%s\n", teamName[i]);
                               
                            }
                     }
                    else if(strcmp(comp,">")==0){
                        
                            if(pointsOfTeams[i]>inputGir){
                                printf("%s\n", teamName[i]);
                               
                            }
                    }
                    else if(strcmp(comp,"=")==0){
                       
                            if(pointsOfTeams[i]==inputGir){
                                printf("%s\n", teamName[i]);
                                
                            }
                    }   
                
                }       
            goto loop;
            }
            if(strcmp(teamName1,"ygol")==0){ 
            for(int i =0;i<10;i++){
                    if(strcmp(comp,"<")==0){
                        
                            if(teamInfo[i][4]<inputGir){
                                printf("%s\n", teamName[i]);
                                 
                            }
                     }
                    else if(strcmp(comp,">")==0){
                        
                            if(teamInfo[i][4]>inputGir){
                                printf("%s\n", teamName[i]);
                            	
                            }
                    }
                    else if(strcmp(comp,"=")==0){
                        
                            if(teamInfo[i][4]==inputGir){
                                printf("%s\n", teamName[i]);
                                
                            }
                    }   
                
                }   
				goto loop;    
        }
        
        
        if(strcmp(teamName1,"takim")==0){// OLMAMA DURUMUNA BAKMADIN
		   for(int i =0;i<10;i++){
                    if(strcmp(comp,"<")==0){
                    	if(strlen(findChar)<=strlen(teamName[i])){
						
                        strncpy(supporting,teamName[i],strlen(findChar));
                        
                        supporting[strlen(findChar)] = '\0';
                        
                        
                        if(strcmp(supporting,findChar)==0){
                        	printf("%s\n", teamName[i]);
                            if(i==9){
							
                            
                        }
                       }
                     
				}
                 }
                 
                    else if(strcmp(comp,">")==0){
                    
						
                    	
                    		for(int j = 0; teamName[i][j] != '\0'; j++)
    						{
       						 k = j;
       						 y = j;
   							}
   							
                    			
    						for(int z = 0; z <= y; z++)
    						{
    						
       						ReverseStr[i][z] = teamName[i][k];
       						k--;

							}
							if(strlen(findChar)<=strlen(teamName[i])){
						
                        strncpy(supporting,ReverseStr[i],strlen(findChar));
                        
                        supporting[strlen(findChar)] = '\0';
                        printf("%s", supporting);
                        
                        
                        if(strcmp(supporting,revFind)==0){
                        	printf("%s\n", teamName[i]);
                       
                       
				}
							
							
						}

      }
                  
                    else if(strcmp(comp,"=")==0){
                    	printf("'=' can not be used in this part ");
                       
                    }   
                    
                    }    
                goto loop;
                
                }
			}
        
                  else if (inputInt==5){
        	return 0;
		}
        }
    

    
            
            
      
    
 
 
       
