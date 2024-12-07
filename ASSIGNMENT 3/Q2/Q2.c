#include <stdio.h>

struct Player {
	int ballScores[6];
	char PlayerName[20];
	int totalScore;
};

void playGame(struct Player *ply) {
    int Scores;
    ply->totalScore = 0;
    printf("Enter the Name : ");
    scanf("%s",ply->PlayerName);
	int Score;
	for(int i=0; i<6; i++) {
		printf("\nEnter the Score %d Ball : ",i+1);
		scanf("%d",&Score);
	
	if(Score >= 0 && Score <= 6) {
		ply->ballScores[i]=Score;
	} else {
		ply->ballScores[i]=0;
	}
	ply->totalScore +=ply->ballScores[i];
}
}

void winner(struct Player ply1,struct Player ply2) {
	if(ply1.totalScore>ply2.totalScore) {
		printf("Player 1 wins\n");
	} else if(ply1.totalScore<ply2.totalScore) {
		printf("Player 2 wins\n");
	}   else{
	     printf("It's a tie! Both players scored %d.\n", ply2.totalScore);
	}

}

void display(struct Player ply) {
    
	printf("These are the scores of %s \n",ply.PlayerName);
	for(int i=0;i<6;i++){
	    printf("%d\n",ply.ballScores[i]);
	}
	    printf("Average : %d \n",ply.totalScore/6);
	    printf("Total Score : %d ",ply.totalScore);

}
int main()
{
	struct Player ply1,ply2;
	printf("Player 1\n");
	playGame(&ply1);
	printf("Player 2\n");
	playGame(&ply2);
	display(ply1);
	display(ply2);
	winner(ply1,ply2);

	return 0;
}
