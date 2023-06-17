#include<stdio.h>
#include<string.h>
int over,ball_count=1,total_balls=0,score=0,no_ball_status=0,wicket,free_on_bat=0,free_missed=0,free_on_missed=0;
char ball_status[100],extra_yes_status[100],n_b_s[100],on_bat_n_b[100],missed_n_b[100],wide_no_ball_status[100],not_free_hit_on_bat[50];
char wicket_n_b_wide[100],not_no_ball_nbs1[20],free_hit_on_bat[30],free_ball_missed[40],not_no_ball_nbs0[20];
int n_b_batsmen_runs=0,extra_runs=0,n_b_w_extra=0,not_free_hit_bat_runs=0,not_n_ball_missed_runs=0;
char not_free_wicket_on_bat[40],missed_no_ball[50],not_free_hit_missed_runs[50],striker[50],non_striker[50],temp[30],who_is_the_striker[30];
int over_count=0,i,c,ball_countable=0,run_countable=0,max_overs,previous_bowler_count,present_bowler_name[30];
char on_grease1[30],on_grease2[30],wicket_name[30],new_batsman[30],sid[30],present_bowler[30];
char select_bowler_name[30],previous_bowler[30],team1_name[30],team2_name[30],batting_order_selecting[30],innings_number[30],file_name[30];
int comming[11]={0,0,0,0,0,0,0,0,0,0,0},target,not_at_batted=0,opp_score;
FILE *fp;
struct cricket{
	char name[30];
	int ball;
	int runs;
	int balls;
	int bowler_overs_count;	int wic;
	int bowler_runs;
	int differnce_between_balls;
	char swap[30];
};
struct cricket player[10];
struct cricket player2[10];
int select_second(){
	int s_second;
	if(ball_count<total_balls){
	printf("%s=0 %s=1 %s=2 %s=3 %s=4 %s=5 %s=6 %s=7 %s=8 %s=9 %s=10",player[0].name,player[1].name,player[2].name,player[3].name,player[4].name,player[5].name,player[6].name,player[7].name,player[8].name,player[9].name,player[10].name);
	printf("\n");
	printf("Enter the  number 1 to 10 to select the new batsman:");
	scanf("%d",&s_second);
	for(i=0;i<11;i++){
		if(s_second>10){
			printf("Please enter the proper number\n");
			select_second();
		}
		else if(s_second==i){
			if(comming[i]==1){
				printf("You selected already selected batsman\n");
				select_second();
			}
			else{
				strcpy(new_batsman,player[i].name);
				comming[i]=1;
			}
		}

}
}
}
int call_the_striker(){
	if(strcmp(wicket_n_b_wide,"hit wicket")==0 || strcmp(wicket_n_b_wide,"stump")==0 || (strcmp(not_free_wicket_on_bat,"bowled")==0) || ( (strcmp(not_free_wicket_on_bat,"hit wicket")==0) || (strcmp(not_free_hit_missed_runs,"stump")==0) || (strcmp(not_free_hit_missed_runs,"bowled")==0) || (strcmp(not_free_hit_missed_runs,"hit wicket")==0) )){
	strcpy(striker,new_batsman);
    }
	else{
	printf("Who is the striker %s or %s",on_grease1,on_grease2);
	gets(striker);
	if((strcmp(striker,on_grease1)!=0) && (strcmp(striker,on_grease2)!=0) &&(strcmp(striker,new_batsman)!=0)){
		printf("Given wrong");
		call_the_striker();
	}
}
}
int call_the_wicket_name(){
	if(strcmp(wicket_n_b_wide,"hit wicket")==0 || strcmp(wicket_n_b_wide,"stump")==0 || (strcmp(not_free_wicket_on_bat,"bowled")==0) ||(strcmp(not_free_wicket_on_bat,"catch out")==0)|| (strcmp(not_free_wicket_on_bat,"hit wicket")==0) || (strcmp(not_free_hit_missed_runs,"catch out")==0)||(strcmp(not_free_hit_missed_runs,"stump")==0) || (strcmp(not_free_hit_missed_runs,"bowled")==0) || (strcmp(not_free_hit_missed_runs,"hit wicket")==0) ){
	strcpy(wicket_name,striker);
	}
	else{
	printf("Who got out %s or %s?\n",striker,non_striker);
	gets(wicket_name);
	if((strcmp(wicket_name,on_grease1)!=0) && (strcmp(wicket_name,on_grease2)!=0)){
		printf("Given wrong");
		call_the_wicket_name();
}
}
}
int it_is_wicket(){
	strcpy(on_grease1,striker);
	strcpy(on_grease2,non_striker);
	call_the_wicket_name();
	select_second();
	if(strcmp(on_grease1,wicket_name)==0){
		strcpy(on_grease1,new_batsman);
	}
	else {
		if(strcmp(on_grease2,wicket_name)==0){
			strcpy(on_grease2,new_batsman);
		}
	}
	call_the_striker();
	if(strcmp(striker,on_grease1)==0){
		strcpy(non_striker,on_grease2);
	}
	else{
		if(strcmp(striker,on_grease2)==0){
			strcpy(non_striker,on_grease1);
		}
	}
		
}
int over_striker_change(){
	strcpy(temp,striker);
	strcpy(striker,non_striker);
	strcpy(non_striker,temp);
}
int not_free_hit_missed_fun(){
	ball_countable=1;
	printf("dot ball?/byes?/leg byes?/wicket?");
	gets(missed_no_ball);
	if(strcmp(missed_no_ball,"dot ball")==0){
		score=score;
		fprintf(fp,"%s for this delivery\n",missed_no_ball);
	}
	else if(strcmp(missed_no_ball,"byes")==0){
		printf("enter the runs by byes:");
		scanf("%d",&not_n_ball_missed_runs);
		score=score+not_n_ball_missed_runs;
		fprintf(fp,"%d %s for this delivery\n",not_n_ball_missed_runs,missed_no_ball);
	}
	else if(strcmp(missed_no_ball,"leg byes")==0){
		printf("Enter the runs by leg byes:");
		scanf("%d",&not_n_ball_missed_runs);
		score=score+not_n_ball_missed_runs;
		fprintf(fp,"%d %s for this delivery\n",not_n_ball_missed_runs,missed_no_ball);
	}
	else{
		if(strcmp(missed_no_ball,"wicket")==0){
			printf("stump?/lbw?/hit wicket?/run out?/bowled?");
			gets(not_free_hit_missed_runs);
			if(strcmp(not_free_hit_missed_runs,"stump")==0){
				wicket++;
				fprintf(fp,"%s for this delivery\n",not_free_hit_missed_runs);
				it_is_wicket();
			}
			else if(strcmp(not_free_hit_missed_runs,"bowled")==0){
				wicket++;
				fprintf(fp,"%s for this delivery\n",not_free_hit_missed_runs);
				it_is_wicket();
			}
			else if(strcmp(not_free_hit_missed_runs,"hit wicket")==0){
				wicket++;
				fprintf(fp,"%s for this delivery\n",not_free_hit_missed_runs);
				it_is_wicket();
			}
			else{
				if(strcmp(not_free_hit_missed_runs,"run out")==0){
					printf("Enter the runs scored before run out:");
					scanf("%d",&not_n_ball_missed_runs);
		            score=score+not_n_ball_missed_runs;
					wicket++;
					fprintf(fp,"%s for this delivery\n",not_free_hit_missed_runs);
					it_is_wicket();
				}
			}
			
			
		}
	}
	
	
	
}
int not_free_hit_on_bat_fun(){
	ball_countable=1;
	run_countable=1;
	printf("wicket?/dot ball?/runs?/");
	gets(not_free_hit_on_bat);
	if(strcmp(not_free_hit_on_bat,"wicket")==0){
		printf("catch out?/hit wicket?/run out?/bowled");
		gets(not_free_wicket_on_bat);
		if(strcmp(not_free_wicket_on_bat,"catch out")==0){
			score=score;
			wicket++;
			fprintf(fp,"%s for this delivery\n",not_free_wicket_on_bat);
			it_is_wicket();
		}
		else if(strcmp(not_free_wicket_on_bat,"hit wicket")==0){
			score=score;
			wicket++;
			fprintf(fp,"%s for this delivery\n",not_free_wicket_on_bat);
			it_is_wicket();
	    }
	    else if(strcmp(not_free_wicket_on_bat,"run out")==0){
	    	printf("Enter the runs scored before run out:");
	    	scanf("%d",&not_free_hit_bat_runs);
	    	score=score+not_free_hit_bat_runs;
			wicket++;
			fprintf(fp,"%s for this delivery\n",not_free_wicket_on_bat);
			it_is_wicket();	
	    }
	    else{
	    	if(strcmp(not_free_wicket_on_bat,"bowled")==0){
	    		score=score;
			    wicket++;
			    fprintf(fp,"%s for this delivery\n",not_free_wicket_on_bat);
			    it_is_wicket();
			}	
		}
    }
    else if(strcmp(not_free_hit_on_bat,"dot ball")==0){
    	score=score;
    	fprintf(fp,"%s for this delivery\n",not_free_hit_on_bat);
	}
	else{
		if(strcmp(not_free_hit_on_bat,"runs")==0){
			printf("enter the runs :");
			scanf("%d",&not_free_hit_bat_runs);
			score=score+not_free_hit_bat_runs;
			fprintf(fp,"%d %s for this delivery\n",not_free_hit_bat_runs,not_free_hit_on_bat);
			
		}
	}
}
int free_hit_missed_fun(){
	ball_countable=1;
	printf("byes?/legbyes?/run out?/no run?");
	gets(free_ball_missed);
	if(strcmp(free_ball_missed,"byes")==0){
		printf("Enter the runsthrow byes:");
		scanf("%d",&free_on_missed);
		score=score+free_on_missed;
		fprintf(fp," %d %s for this delivery\n",free_on_missed,free_ball_missed);
    }
    else if(strcmp(free_ball_missed,"leg byes")==0){
		printf("Enter the runsthrow leg byes:");
		scanf("%d",&free_on_missed);
		score=score+free_on_missed;
		fprintf(fp," %d %s for this delivery\n",free_on_missed,free_ball_missed);
    }
    else if(strcmp(free_ball_missed,"run out")==0){
		printf("Enter the runs after run out:");
		scanf("%d",&free_on_missed);
		score=score+free_on_missed;
		wicket++;
		fprintf(fp,"%s for this delivery\n",free_ball_missed);
		it_is_wicket();
    }
    else{
    	if(strcmp(free_ball_missed,"no run")==0){
		    score=score;
		    fprintf(fp,"%s for this delivery\n",free_ball_missed);
	    }
	}
    
}
int free_hit_on_bat_fun(){
	ball_countable=1;
	run_countable=1;
	printf("run out?/no run?/extra runs?");
	gets(free_hit_on_bat);
	if(strcmp(free_hit_on_bat,"run out")==0){
		printf("Enter the runs already batsman taken:");
		scanf("%d",&free_on_bat);
		wicket++;
		fprintf(fp,"%s for this delivery\n",free_hit_on_bat);
		it_is_wicket();
	}
	else if(strcmp(free_hit_on_bat,"no run")==0){
		score=score;
		fprintf(fp,"%s for this delivery\n",free_hit_on_bat);
    }
    else{
    	if(strcmp(free_hit_on_bat,"extra runs")==0){
    		printf("Enter the runs:");
		    scanf("%d",&free_on_bat);
		    score=score+free_on_bat;
			fprintf(fp," %d %s for this delivery\n",free_on_bat,free_hit_on_bat);	
		}
	}
}
int extra_ball_wide_fun(){
	printf("wicket?/no runs?/extra run?");
	gets(wide_no_ball_status);
	if(strcmp(wide_no_ball_status,"wicket")==0){
		printf("run out?/hit wicket?/stump?");
		gets(wicket_n_b_wide);
		fprintf(fp,"It is wide and %s for this delivery\n",wicket_n_b_wide);
		if(strcmp(wicket_n_b_wide,"run out")==0){
			printf("Enter the runs batsmen already taken :");
						scanf("%d",&n_b_w_extra);
						score=score+n_b_w_extra;
						wicket++;
						it_is_wicket();	
						
		}
		else if(strcmp("hit wicket",wicket_n_b_wide)==0){
			wicket++;
			it_is_wicket();	
		}
		else{
			if(strcmp(wicket_n_b_wide,"stump")==0){
				score=score;
				it_is_wicket();	
			}
		}
				
	}
	else if(strcmp(wide_no_ball_status,"no run")==0){
		score=score;
		fprintf(fp,"It is wide and %s for this delivery\n",wide_no_ball_status);
	}
	else{
		if(strcmp(wide_no_ball_status,"extra run")==0){
			printf("Enter the extra runs ");
			scanf("%d",&n_b_w_extra);
			score=score+n_b_w_extra;
			fprintf(fp,"It is wide and %d %s for this delivery\n",n_b_w_extra,wide_no_ball_status);
		}
	}
}
int missed_for_no_ball_fun(){
	ball_countable=1;
	printf("byes?/leg byes?/no run?/run out?");
	gets(missed_n_b);
	if(strcmp(missed_n_b,"byes")==0){
		printf("Enter the extra runs :");
		scanf("%d",&extra_runs);
		score=score+extra_runs;
		fprintf(fp,"Missed to the bat and %d %s for this delivery",extra_runs,on_bat_n_b);
	}
	else if(strcmp(missed_n_b,"leg byes")==0){
		printf("Enter the extra runs :");
		scanf("%d",&extra_runs);
		score=score+extra_runs;
		fprintf(fp,"Missed to the bat and %d %s for this delivery",extra_runs,on_bat_n_b);
	}
	else if(strcmp(missed_n_b,"no run")==0){
		score=score;
		fprintf(fp,"Missed to the bat and %s for this delivery",on_bat_n_b);
	}
	else{
		if (strcmp(missed_n_b,"run out")){
			printf("Enter the runs batsmen already taken :");
						scanf("%d",&extra_runs);
						score=score+extra_runs;
						wicket++;
						fprintf(fp,"Missed to the bat and  %s for this delivery",on_bat_n_b);
						it_is_wicket();
		}
	}
}
int on_bat_for_no_ball_fun(){
					run_countable=1;
					ball_countable=1;
                	printf("run out?/no run?/extra runs?");
					gets(on_bat_n_b);
					if(strcmp(on_bat_n_b,"run out")==0){
						printf("Enter the runs batsmen already taken :");
						fprintf(fp,"Hit to the bat and %s for this delivery",on_bat_n_b);
						scanf("%d",&n_b_batsmen_runs);
						score=score+n_b_batsmen_runs;
						wicket++;
						it_is_wicket();
					}
					else if(strcmp(on_bat_n_b,"no run")==0){
						fprintf(fp,"Hit to the bat and %s for this delivery\n",on_bat_n_b);
						ball_count=ball_count;
					}
					else {
						if(strcmp(on_bat_n_b,"extra runs")==0){
							printf("enter the runs :");
							scanf("%d",&n_b_batsmen_runs);
							fprintf(fp,"Hit to the bat and %d %s for this delivery\n",n_b_batsmen_runs,on_bat_n_b);
							score=score+n_b_batsmen_runs;
					}
				}
			}

int s_selecting(){
	int select;
	printf("\n%s=0 %s=1 %s=2 %s=3 %s=4 %s=5 %s=6 %s=7 %s=8 %s=9 %s=10",player[0].name,player[1].name,player[2].name,player[3].name,player[4].name,player[5].name,player[6].name,player[7].name,player[8].name,player[9].name,player[10].name);
	printf("\nenter the  number 0 to 10 to select striker: ");
	scanf("%d",&select);
	for(i=0;i<11;i++){
		if(select>10){
			printf("Please select correctly\n");
			s_selecting();
		}
		else{
			if (select==i){
			strcpy(striker,player[i].name);
			comming[i]=1;
			c=i;
		}
		}
	}
	return 0;
}
int n_s_selecting(){
	int non_s;
	printf("\n%s=0 %s=1 %s=2 %s=3 %s=4 %s=5 %s=6 %s=7 %s=8 %s=9 %s=10",player[0].name,player[1].name,player[2].name,player[3].name,player[4].name,player[5].name,player[6].name,player[7].name,player[8].name,player[9].name,player[10].name);
	printf("\n");
	printf("Enter the  number 0 to 10 to select non striker: ");
	scanf("%d",&non_s);
	for(i=0;i<11;i++){
		if(non_s>10){
			printf("Please enter the proper number\n");
			n_s_selecting();
		}
		if(non_s==c){
			printf("This player already selected as the striker plase select another player\n");
			n_s_selecting();
		}
		else {
			if (non_s==i){
			strcpy(non_striker,player[i].name);
			comming[i]=1;
			}
		}
	}
}
int bowler_select(){
	printf("Enter any bowler from these players \n%s %s %s %s %s %s %s %s %s %s %s\n",player2[0].name,player2[1].name,player2[2].name,player2[3].name,player2[4].name,player2[5].name,player2[6].name,player2[7].name,player2[8].name,player2[9].name,player2[10].name);
	if(ball_count==1){
	gets(select_bowler_name);
	gets(select_bowler_name);
    }
    else
    gets(select_bowler_name);
	for(i=0;i<11;i++){
		if(strcmp(select_bowler_name,player2[i].name)==0){
			if(ball_count<7){
				strcpy(present_bowler,(player2[i].name));
				strcpy(previous_bowler,(player2[i].name));
				player2[i].bowler_overs_count++;
			}
			else if(player2[i].bowler_overs_count==max_overs){
				printf("can't select this bowler\n");
				bowler_select();
			}
			else if(strcmp(previous_bowler,player2[i].name)!=0){
				strcpy(present_bowler,player2[i].name);
				strcpy(previous_bowler,player2[i].name);
				player2[i].bowler_overs_count++;
				}
			else{
				printf("Please select another player\n");
				bowler_select();
			}
		break;
		}
}
}

int main(){
	printf("Enter the text file name to store the all the score data :");
    gets(file_name);
    fp=fopen(file_name,"w");
	printf("first innings?/second innings? ");
	gets(innings_number);
	fprintf(fp,"%s\n",innings_number);
	printf("Enter the name of the batting team :");
	gets(team1_name);
	printf("Enter the players of %s team\n",team1_name);
	//gets(sid);
	for(i=0;i<11;i++){
		printf("%d)",i+1);
		gets(sid);
        strcpy((player[i].name),sid);
	}
	printf("Enter the name of the bowling team :");
	gets(team2_name);
	printf("Enter the players of %s team\n",team2_name);
	for(i=0;i<11;i++){
		printf("%d)",i+1);
		gets(sid);
    strcpy((player2[i].name),sid);
	}
	printf("Enter the overs in the match :");
    scanf("%d",&over);
    fprintf(fp,"%d total overs\n",over);
    if (over<=2){
    	max_overs=1;
    }
    else{
	printf("Enter the maximum overs a bolwer can bowl:");
	scanf("%d",&max_overs);
	fprintf(fp,"maximum overs for a bowler is %d\n",max_overs);
    };
    printf("\n");
	fprintf(fp,"\n");
	printf("%s players\n",team1_name);
	fprintf(fp,"%s players\n",team1_name);
	for(i=0;i<11;i++){
		printf("%d). %s\n",i+1,(player[i].name));
		fprintf(fp,"%d). %s\n",i+1,(player[i].name));
	}
	printf("\n");
	fprintf(fp,"\n");
	printf("%s players\n",team2_name);
	fprintf(fp,"%s players\n",team2_name);
    for(i=0;i<11;i++){
		printf("%d). %s\n",i+1,(player2[i].name));
		fprintf(fp,"%d). %s\n",i+1,(player2[i].name));
	}
	printf("\n");
	fprintf(fp,"\n");
	printf("Select the stricker and non striker from the playing of %s ",team1_name);
	s_selecting();
	n_s_selecting();
	printf("\n%s striker",striker);
	printf("\n%s non strikern\n",non_striker);
	strcpy(on_grease1,striker);
    strcpy(on_grease2,non_striker);
    bowler_select();
    fprintf(fp,"present bowler is %s\n",present_bowler);
    total_balls=over*6;
    if(strcmp(innings_number,"first innings")==0){
	while(ball_count<=total_balls && wicket<=9){
		printf("Is it extra ball?");
		gets(ball_status);
		if(strcmp("yes",ball_status)==0){
			printf("no ball?/wide?/dead ball?");
			gets(extra_yes_status);
			if(strcmp(extra_yes_status,"no ball")==0){
				no_ball_status=1;
				score++;
				fprintf(fp,"no ball\n");
				printf("on bat?/missed?");
				gets(n_b_s);
				if(strcmp(n_b_s,"on bat")==0){
					on_bat_for_no_ball_fun();
				}
				else {
					if(strcmp(n_b_s,"missed")==0){
					missed_for_no_ball_fun();	
					}
				}
			}
			else if(strcmp(extra_yes_status,"wide")==0){
				extra_ball_wide_fun();
				score++;
			}
			else {
			if(strcmp(extra_yes_status,"dead ball")==0){
				score=score;
			}	
		}
	    }
		else{
			if(strcmp("no",ball_status)==0){
				ball_count++;
				if(no_ball_status==1){
					fprintf(fp,"It is free hit delivery\n");
					printf("on bat?/missed?");
					gets(not_no_ball_nbs1);
					if(strcmp(not_no_ball_nbs1,"on bat")==0){
						fprintf(fp,"ball hit the bat\n");
						free_hit_on_bat_fun();	
					}
					else{
						if(strcmp(not_no_ball_nbs1,"missed")==0){
							fprintf(fp,"ball missed to the bat\n");
							free_hit_missed_fun();
						}
					}
					no_ball_status=0;		
			    }
				else{
					if(no_ball_status==0){
						printf("on bat?/missed?");
					    gets(not_no_ball_nbs0);
					    if(strcmp(not_no_ball_nbs0,"on bat")==0){
					    	fprintf(fp,"ball hit the bat\n");
						    not_free_hit_on_bat_fun();
					    }
					    else{
					    	if(strcmp(not_no_ball_nbs0,"missed")==0){
					    		fprintf(fp,"ball missed to the bat\n");
					    	not_free_hit_missed_fun();
					    		   
							}
						}
				    }              				    
				}	
			}
		}
		if(ball_countable==1){
		for(i=0;i<11;i++){
			if(strcmp(striker,player[i].name)==0){
				(player[i].balls)++;
				break;
			}
		}
		}
		if(run_countable==1){
			for(i=0;i<11;i++){
				if(strcmp(striker,player[i].name)==0){
					if(n_b_batsmen_runs>0){
						player[i].runs=(player[i].runs)+(n_b_batsmen_runs);
						break;
					}
					else if(free_on_bat>0){
						player[i].runs=(player[i].runs)+(free_on_bat);
						break;
					}
					else{
						player[i].runs=(player[i].runs)+(not_free_hit_bat_runs);
						break;
					}
				}
			}
		}
		//new
		
		if(n_b_batsmen_runs>0 || extra_runs>0 || n_b_w_extra>0 || free_on_missed>0 || not_free_hit_missed_runs>0 || not_n_ball_missed_runs>0 ){
	if( ((not_n_ball_missed_runs)%2!=0 ) || (n_b_batsmen_runs)%2!=0 || extra_runs%2!=0 ||n_b_w_extra%2!=0 ||free_on_missed%2!=0 || not_free_hit_bat_runs%2!=0 ||not_n_ball_missed_runs%2!=0){
		char t[30];
		strcpy(t,striker);
		strcpy(striker,non_striker);
		strcpy(non_striker,t);
		}
	    }
		for(i=0;i<11;i++){
			if(strcmp(present_bowler,player2[i].name)==0){
				if(strcmp(ball_status,"yes")==0){
					player2[i].bowler_runs++;
			        if((strcmp(missed_n_b,"byes")==0 || strcmp(missed_n_b,"leg byes")==0 )){	
			        score=score;
					}
					else if(n_b_w_extra>0){
						player2[i].bowler_runs=player2[i].bowler_runs+n_b_w_extra;
					}
					else if(n_b_batsmen_runs>0){
						player2[i].bowler_runs=player2[i].bowler_runs+n_b_batsmen_runs;
					}
					else{
						if(extra_runs>0){
							player2[i].bowler_runs=player2[i].bowler_runs+extra_runs;
						}
					}
					if(strcmp(wide_no_ball_status,"wicket")==0){
						if(strcmp(wicket_n_b_wide,"stump")==0 || strcmp(wicket_n_b_wide,"hit wicket")==0){
							player2[i].wic++;
						}
					}
				}
				else{
					if((strcmp(ball_status,"no")==0)){
						if(strcmp(free_ball_missed,"byes")==0 || strcmp(free_ball_missed,"leg byes")==0 || strcmp(missed_no_ball,"byes")==0 || strcmp(missed_no_ball,"leg byes")==0 )
						score=score;
						else {
							if(free_on_bat>0 || free_on_missed>0 || not_free_hit_bat_runs>0 || not_n_ball_missed_runs>0){
								player2[i].bowler_runs=(player2[i].bowler_runs)+free_on_bat;
								player2[i].bowler_runs=player2[i].bowler_runs+free_on_missed;
								player2[i].bowler_runs=player2[i].bowler_runs+not_free_hit_bat_runs;
								player2[i].bowler_runs=player2[i].bowler_runs+not_n_ball_missed_runs;
							}
						}
					}
					if(strcmp(not_free_hit_on_bat,"wicket")==0){
						if(strcmp(not_free_wicket_on_bat,"catch out")==0 || (strcmp(not_free_wicket_on_bat,"bowled")==0 || (strcmp(not_free_wicket_on_bat,"hit wicket")==0))){
							player2[i].wic++;
						}
					}
					else if(strcmp(missed_no_ball,"wicket")==0){
						if(strcmp(not_free_hit_missed_runs,"hit wicket")==0 || strcmp(not_free_hit_missed_runs,"lbw")==0 || strcmp(not_free_hit_missed_runs,"stump")==0 || strcmp(not_free_hit_missed_runs,"bowled")==0){
							player2[i].wic++;
						}
					}
					else{
						printf("");
					}
				}
			}
		}	
		if((ball_count-1)%6==0 && ball_count!=1){
			over_count++;
			printf("After %d over the score is %d and wickets is %d\n ",over_count,score,wicket);
			fprintf(fp,"After %d over the score is %d and wickets is %d\n ",over_count,score,wicket);
		    char t[30];
			strcpy(t,striker);
			strcpy(striker,non_striker);
			strcpy(non_striker,t);
			if(ball_count<total_balls){
			printf("%s =striker and %s =non striker\n",striker,non_striker); 
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker); 
		    }
			if(over_count!=over){
			bowler_select();
			fprintf(fp,"present bowler is %s\n",present_bowler);
		}
   		}
		else{
		if(ball_count<6){
			printf("By 0.%d over the score is %d and wicket is %d\n",(ball_count-1),score,wicket);
			printf("%s =striker and %s =non striker\n",striker,non_striker);
			fprintf(fp,"By 0.%d over the score is %d and wicket is %d\n",(ball_count-1),score,wicket);
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker);
		}
		else{
			printf("By %d.%d over the score is %d and wicket is %d\n",over_count,(ball_count-1)%6,score,wicket);
			printf("%s =striker and %s =non striker\n",striker,non_striker);
			fprintf(fp,"By %d.%d over the score is %d and wicket is %d\n",over_count,(ball_count-1)%6,score,wicket);
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker);
		}
	    }
		strcpy(free_ball_missed,"");
		strcpy(missed_no_ball,"");
		strcpy(missed_n_b,"");
		run_countable=0;
	    ball_countable=0;
		n_b_batsmen_runs=0; 
		extra_runs=0;
		n_b_w_extra=0;
		free_on_missed=0;
		not_free_hit_bat_runs=0;
		not_n_ball_missed_runs=0;
		target=score+1;
		}
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		printf("Batting stats\n");
		fprintf(fp,"Batting stats\n");
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		for(i=0;i<11;i++){
			if(comming[i]==1){
			    printf("%s %d(%d)\n",player[i].name,player[i].runs,player[i].balls);
				fprintf(fp,"%s %d(%d)\n",player[i].name,player[i].runs,player[i].balls);
				strcpy(player[i].name,"");	
				}
	   }
		for(i=0;i<11;i++){
			if(comming[i]==0){
			if(not_at_batted==0){
				not_at_batted=1;
				printf("not at batted\n");
				fprintf(fp,"not at batted\n");
			}
			printf("%s\n",player[i].name);
			fprintf(fp,"%s\n",player[i].name);
		}
		}
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		printf("bowling status\n");
		fprintf(fp,"bowling status\n");
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		for(i=0;i<11;i++){
			if(player2[i].bowler_overs_count>0){
				printf("%s %d-%d(%d)\n",player2[i].name,player2[i].wic,player2[i].bowler_runs,player2[i].bowler_overs_count);
				fprintf(fp,"%s %d-%d(%d)\n",player2[i].name,player2[i].wic,player2[i].bowler_runs,player2[i].bowler_overs_count);
			}
		}
		printf("Target is %d for %s",target,team2_name);
		fprintf(fp,"Target is %d for %s",target,team2_name);				
    }
    else if(strcmp("second innings",innings_number)==0){
    	fp=fopen(file_name,"a");
    	printf("Enter the score of %s team:",team2_name);
    	scanf("%d",&opp_score);
    	fprintf(fp,"%s need to chase %d",team1_name,opp_score+1);
    	while(ball_count<=total_balls && wicket<=9){
		printf("Is it extra ball?");
		gets(ball_status);
		if(strcmp("yes",ball_status)==0){
			printf("no ball?/wide?/dead ball?");
			gets(extra_yes_status);
			if(strcmp(extra_yes_status,"no ball")==0){
				no_ball_status=1;
				fprintf(fp,"no ball!...\n");
				score++;
				fprintf(fp,"It is a no ball\n");
				printf("on bat?/missed?");
				gets(n_b_s);
				if(strcmp(n_b_s,"on bat")==0){
					on_bat_for_no_ball_fun();
				}
				else {
					if(strcmp(n_b_s,"missed")==0){
					missed_for_no_ball_fun();	
					}
				}
			}
			else if(strcmp(extra_yes_status,"wide")==0){
				fprintf(fp,"wide ball..\n");
				extra_ball_wide_fun();
				score++;
			}
			else {
			if(strcmp(extra_yes_status,"dead ball")==0){
				score=score;
				fprintf(fp,"dead ball...\n");
			}	
		}
	    }
		else{
			if(strcmp("no",ball_status)==0){
				ball_count++;
				if(no_ball_status==1){
					fprintf(fp,"It is free hit and");
					printf("on bat?/missed?");
					gets(not_no_ball_nbs1);
					if(strcmp(not_no_ball_nbs1,"on bat")==0){
						fprintf(fp,"Hit to the bat\n");
						free_hit_on_bat_fun();	
					}
					else{
						if(strcmp(not_no_ball_nbs1,"missed")==0){
							fprintf(fp,"missed the bat\n");
							free_hit_missed_fun();
						}
					}
					no_ball_status=0;		
			    }
				else{
					if(no_ball_status==0){
						printf("on bat?/missed?");
					    gets(not_no_ball_nbs0);
					    if(strcmp(not_no_ball_nbs0,"on bat")==0){
					    	fprintf(fp,"Hit to the bat\n");
						    not_free_hit_on_bat_fun();
					    }
					    else{
					    	if(strcmp(not_no_ball_nbs0,"missed")==0){
					    	fprintf(fp,"ball missed  the bat\n");
					    	not_free_hit_missed_fun();	   
							}
						}
				    }              				    
				}	
			}
		}
		if(ball_countable==1){
		for(i=0;i<11;i++){
			if(strcmp(striker,player[i].name)==0){
				(player[i].balls)++;
				break;
			}
		}
	}
		if(run_countable==1){
			for(i=0;i<11;i++){
				if(strcmp(striker,player[i].name)==0){
					if(n_b_batsmen_runs>0){
						player[i].runs=(player[i].runs)+(n_b_batsmen_runs);
						break;
					}
					else if(free_on_bat>0){
						player[i].runs=(player[i].runs)+(free_on_bat);
						break;
					}
					else{
						if(not_free_hit_bat_runs>0){
						player[i].runs=(player[i].runs)+(not_free_hit_bat_runs);
						break;
					}
					}
				}
			}
		}
		if(n_b_batsmen_runs>0 || extra_runs>0 || n_b_w_extra>0 || free_on_missed>0 || not_free_hit_missed_runs>0 || not_n_ball_missed_runs>0 ){
	if( ((not_n_ball_missed_runs)%2!=0 ) || (n_b_batsmen_runs)%2!=0 || extra_runs%2!=0 ||n_b_w_extra%2!=0 ||free_on_missed%2!=0 || not_free_hit_bat_runs%2!=0 ||not_n_ball_missed_runs%2!=0){
		char t[30];
		strcpy(t,striker);
		strcpy(striker,non_striker);
		strcpy(non_striker,t);
		}
	    }
		for(i=0;i<11;i++){
			if(strcmp(present_bowler,player2[i].name)==0){
				if(strcmp(ball_status,"yes")==0){
					player2[i].bowler_runs=player2[i].bowler_runs+1;
			        if((strcmp(missed_n_b,"byes")==0 || strcmp(missed_n_b,"leg byes")==0 )){	
			        score=score;
					}
					else if(n_b_w_extra>0){
						player2[i].bowler_runs=player2[i].bowler_runs+n_b_w_extra;
					}
					else if(n_b_batsmen_runs>0){
						player2[i].bowler_runs=player2[i].bowler_runs+n_b_batsmen_runs;
					}
					else{
						if(extra_runs>0){
							player2[i].bowler_runs=player2[i].bowler_runs+extra_runs;
						}
					}
					if(strcmp(wide_no_ball_status,"wicket")==0){
						if(strcmp(wicket_n_b_wide,"stump")==0 || strcmp(wicket_n_b_wide,"hit wicket")==0){
							player2[i].wic++;
						}
					}
				}
				else{
					if((strcmp(ball_status,"no")==0)){
						if(strcmp(free_ball_missed,"byes")==0 || strcmp(free_ball_missed,"leg byes")==0 || strcmp(missed_no_ball,"byes")==0 || strcmp(missed_no_ball,"leg byes")==0 )
						score=score;
						else {
							if(free_on_bat>0 || free_on_missed>0 || not_free_hit_bat_runs>0 || not_n_ball_missed_runs>0){
								player2[i].bowler_runs=(player2[i].bowler_runs)+free_on_bat;
								player2[i].bowler_runs=player2[i].bowler_runs+free_on_missed;
								player2[i].bowler_runs=player2[i].bowler_runs+not_free_hit_bat_runs;
								player2[i].bowler_runs=player2[i].bowler_runs+not_n_ball_missed_runs;
							}
						}
					}
					if(strcmp(not_free_hit_on_bat,"wicket")==0){
						if(strcmp(not_free_wicket_on_bat,"catch out")==0 || (strcmp(not_free_wicket_on_bat,"bowled")==0 || (strcmp(not_free_wicket_on_bat,"hit wicket")==0))){
							player2[i].wic++;
						}
					}
					else if(strcmp(missed_no_ball,"wicket")==0){
						if(strcmp(not_free_hit_missed_runs,"hit wicket")==0 || strcmp(not_free_hit_missed_runs,"lbw")==0 || strcmp(not_free_hit_missed_runs,"stump")==0 || strcmp(not_free_hit_missed_runs,"bowled")==0){
							player2[i].wic++;
						}
					}
					else{
						printf("");
					}
				}
			}
		}	
		if((ball_count-1)%6==0 && ball_count!=1){
			over_count++;
			printf("After %d over the score is %d and wickets is %d\n ",over_count,score,wicket);
			fprintf(fp,"After %d over the score is %d and wickets is %d\n ",over_count,score,wicket);
		    char t[30];
			strcpy(t,striker);
			strcpy(striker,non_striker);
			strcpy(non_striker,t);
			if(ball_count<total_balls){	
			printf("%s =striker and %s =non striker\n",striker,non_striker); 
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker); 
		    }
			if(over_count!=over){
			bowler_select();
		}
   		}
		else{
		if(ball_count<6){	
			printf("By 0.%d ball the score is %d and wicket is %d\n",(ball_count-1),score,wicket);
			printf("%s =striker and %s =non striker\n",striker,non_striker);
			fprintf(fp,"By 0.%d ball the score is %d and wicket is %d\n",(ball_count-1),score,wicket);
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker);
	    }
	    else{
	    	printf("By 0.%d ball the score is %d and wicket is %d\n",(ball_count-1)%6,score,wicket);
			printf("%s =striker and %s =non striker\n",striker,non_striker);
			fprintf(fp,"By 0.%d ball the score is %d and wicket is %d\n",(ball_count-1)%6,score,wicket);
			fprintf(fp,"%s =striker and %s =non striker\n",striker,non_striker);
		}
		}
		strcpy(free_ball_missed,"");
		strcpy(missed_no_ball,"");
		strcpy(missed_n_b,"");
		run_countable=0;
	    ball_countable=0;
		n_b_batsmen_runs=0; 
		extra_runs=0;
		n_b_w_extra=0;
		free_on_missed=0;
		not_free_hit_bat_runs=0;
		not_n_ball_missed_runs=0;
		if(opp_score>score && wicket==10){
			printf("\n");
			printf("Match results\n");
			printf(" %s won by %d runs\n",team2_name,opp_score-score);
			fprintf(fp,"\n");
			fprintf(fp,"Match results\n");
			fprintf(fp," %s won by %d runs\n",team2_name,opp_score-score);
			break;
		}
		if(opp_score<score){
			printf("\n");
			printf("Match results\n");
			printf("%s won by %d wickets\n",team1_name,10-wicket);
			fprintf(fp,"\n");
			fprintf(fp,"Match results\n");
			fprintf(fp,"?%s won by %d wickets\n",team1_name,10-wicket);
			break;
		}
		}
		if(score<opp_score){
			printf("\n");
			printf("Match results\n");
			printf("%s team won by %d runs\n",team2_name,opp_score-score);
			fprintf(fp,"\n");
			fprintf(fp,"Match results\n");
			fprintf(fp,"%s team won by %d runs\n",team2_name,opp_score-score);
		}
		if(score==opp_score){
			printf("\n");
			printf("Match results\n");
			printf("Match tied\n");
			fprintf(fp,"\n");
			fprintf(fp,"Match results\n");
			fprintf(fp,"Match tied\n");
		}
		printf("-------------------------------\n");
		printf("Batting status\n");
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		fprintf(fp,"Batting stats\n");
		fprintf(fp,"-------------------------------\n");
		for(i=0;i<11;i++){
			if(comming[i]==1){
				printf("%s %d(%d)\n",player[i].name,player[i].runs,player[i].balls);
				fprintf(fp,"%s %d(%d)\n",player[i].name,player[i].runs,player[i].balls);
				strcpy(player[i].name,"");
			}
		}
		for(i=0;i<11;i++){
			if(comming[i]==0){
			if(not_at_batted==0){
				not_at_batted=1;
				printf("not at batted\n");
				fprintf(fp,"not at batted\n");
			}
			printf("%s\n",player[i].name);
			fprintf(fp,"%s\n",player[i].name);
		}
		}
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		printf("bowling status\n");
		fprintf(fp,"bowling status\n");
		printf("-------------------------------\n");
		fprintf(fp,"-------------------------------\n");
		for(i=0;i<11;i++){
			if(player2[i].bowler_overs_count>0){
				printf("%s %d-%d(%d)\n",player2[i].name,player2[i].wic,player2[i].bowler_runs,player2[i].bowler_overs_count);
				fprintf(fp,"%s %d-%d(%d)\n",player2[i].name,player2[i].wic,player2[i].bowler_runs,player2[i].bowler_overs_count);
			}
		}
	}
fclose(fp);
}