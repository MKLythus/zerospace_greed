#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hiscore{

	char name[255];
	int score;

};

int menuselect(){
	char temp[10];
	do{
	
		system("clear");
		puts("Welcome to Zer0space: Gr33d 0.1.4 Alpha");
		printf("\n\n\n");
		puts("Press (1) to play a new game of Z:G");
		puts("Press (2) to load a game of Z:G");
		puts("Press (3) to see the high scores");
		puts("Press (4) to learn how to play Z:G");
		printf("\n\n\n");
		printf("What is your answer player-san?\t");
		fgets(temp,10,stdin);
		if(strlen(temp) > 2){
		}
		else if(temp[0] == 'q'|| temp[0] == 'Q'){
		
			return -1;
		
		}
		else if(temp[0] == '1'){
		
			return 1;
		
		
		}
		else if(temp[0] == '2'){
		
		
			return 2;
		
		}
		else if(temp[0] == '3'){
		
		
			return 3;
		
		}
		else if(temp[0]=='4'){
		
		
			return 4;
		
		}
	}
	while(1);
	return 0;
}

void genmap(char map[][53]){
	int x=0, y=0;
	for(y=0;y<24;y++){
		if(y==0 || y==23){
			for(x=0; x<52; x++){
			
				map[y][x] = ' ';				
			
			}
		}
		else{
			for(x=0; x<52; x++){
				if(x==0 || x== 51){
					map[y][x] = ' ';	
				
				
				}
				else{
					map[y][x] = '1';
				
				}
			
			}
		
		}
	}
	for(y=0; y<24;y++){
	
		map[y][52] = '\0';
	
	}
	
}

void newgame(char map[][53], int *xpos, int *ypos){

	int mapx, mapy, cursx, cursy,temp;
	
	for(mapy=1; mapy < 23; mapy++){
		for(mapx=1; mapx<51; mapx++){
			temp = rand()%9;
			switch(temp){
			
				case 0:
					map[mapy][mapx]='1';
					break;
				case 1:
					map[mapy][mapx]='2';
					break;
				case 2:
					map[mapy][mapx]='3';
					break;								
				case 3:
					map[mapy][mapx]='4';
					break;			
				case 4:
					map[mapy][mapx]='5';
					break;			
				case 5:
					map[mapy][mapx]='6';
					break;			
				case 6:
					map[mapy][mapx]='7';
					break;
				case 7:
					map[mapy][mapx]='8';
					break;
				case 8:
					map[mapy][mapx]='9';
					break;					
			}			
		
		}
	
	
	}
	cursx=(rand()%50)+1;
	cursy=(rand()%22)+1;
	*xpos=cursx;
	*ypos=cursy;
	map[cursy][cursx] = '@';
}

int movement(char map[][53], int *xpos, int *ypos, char command){
	int movesnum=0;
	int i = 0;
	char stringed[2] = "x";
	switch(command){
	
		case 'y':
			if(map[(*ypos)-1][(*xpos)-1] == ' '){
			
				return 0;
			}
			else{
				stringed[0]=map[(*ypos)-1][(*xpos)-1];
				movesnum = atoi(stringed);
			}
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)-i][(*xpos)-i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)-i][(*xpos)-i] = ' ';
			
			}
			*ypos=(*ypos)-i+1;
			*xpos=(*xpos)-i+1;
			map[*ypos][*xpos]='@';
			return movesnum;		
		case 'u':
			if(map[(*ypos)-1][(*xpos)+1] == ' '){
			
				return 0;
			}
			else{
				stringed[0]=map[(*ypos)-1][(*xpos)+1];
				movesnum = atoi(stringed);
			}			
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)-i][(*xpos)+i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)-i][(*xpos)+i] = ' ';
			
			}
			*ypos=(*ypos)-i+1;
			*xpos=(*xpos)+i-1;
			map[*ypos][*xpos]='@';
			return movesnum;		
		case 'h':
			if(map[(*ypos)][(*xpos)-1] == ' '){
			
				return 0;
			}
			else{
				stringed[0]=map[(*ypos)][(*xpos)-1];
				movesnum = atoi(stringed);
			}
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)][(*xpos)-i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)][(*xpos)-i] = ' ';
			
			}
			*ypos=(*ypos);
			*xpos=(*xpos)-i+1;
			map[*ypos][*xpos]='@';
			return movesnum;		
			
		case 'j':
			if(map[(*ypos)+1][(*xpos)] == ' '){
			
				return 0;
			}
			else{
				stringed[0]=map[(*ypos)+1][(*xpos)];
				movesnum = atoi(stringed);
			}
				
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)+i][(*xpos)] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)+i][(*xpos)] = ' ';
			
			}
			*ypos=(*ypos)+i-1;
			*xpos=(*xpos);
			map[*ypos][*xpos]='@';
			return movesnum;		
			
		case 'k':
			if(map[(*ypos)-1][(*xpos)] == ' '){
			
				return 0;
			}
			else{
				stringed[0] = map[(*ypos)-1][(*xpos)];
				movesnum = atoi(stringed);
			}			
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)-i][(*xpos)] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)-i][(*xpos)] = ' ';
			
			}
			*ypos=(*ypos)-i+1;
			*xpos=(*xpos);
			map[*ypos][*xpos]='@';
			return movesnum;		
			
		case 'l':
			if(map[(*ypos)][(*xpos)+1] == ' '){
			
				return 0;
			}
			else{
				stringed[0] = map[(*ypos)][(*xpos)+1];
				movesnum = atoi(stringed);
			}			
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)][(*xpos)+i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)][(*xpos)+i] = ' ';
			
			}
			*ypos=(*ypos);
			*xpos=(*xpos)+i-1;
			map[*ypos][*xpos]='@';
			return movesnum;		
			
		case 'b':
			if(map[(*ypos)+1][(*xpos)-1] == ' '){
			
				return 0;
			}
			else{
				stringed[0]=map[(*ypos)+1][(*xpos)-1];
				movesnum = atoi(stringed);
			}			
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)+i][(*xpos)-i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)+i][(*xpos)-i] = ' ';
			
			}
			*ypos=(*ypos)+i-1;
			*xpos=(*xpos)-i+1;
			map[*ypos][*xpos]='@';
			return movesnum;		
			
		case 'n':
			if(map[(*ypos)+1][(*xpos)+1] == ' '){
			
				return 0;
			}
			else{	
				stringed[0]=map[(*ypos)+1][(*xpos)+1];
				movesnum = atoi(stringed);
			}			
			for(i=1; (movesnum-i) >-1;i++){
				if(map[(*ypos)+i][(*xpos)+i] == ' '){
				
					return 0;
				
				}		
			}
			for(i=0; (movesnum-i) >-1; i++){
			
				map[(*ypos)+i][(*xpos)+i] = ' ';
			
			}
			*ypos=(*ypos)+i-1;
			*xpos=(*xpos)+i-1;
			map[*ypos][*xpos]='@';
			return movesnum;		
			
	}	
	
	return 0;
}
int checkmoves(char map[][53], int *xpos, int *ypos){
	int i = 0;

	char stringed[2] = "x";	
	int movesnum=0;
	int hasspace = 0;
//
	stringed[0]=map[(*ypos)+1][(*xpos)+1];
	movesnum = atoi(stringed);
	
	if(movesnum == 0){
	
		hasspace++;
	
	}
						
	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)+i][(*xpos)+i] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	if(hasspace==0){
		return 0;
	}
	
	
	stringed[0]=map[(*ypos)+1][(*xpos)];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)+i][(*xpos)] == ' '){
			hasspace++;	
			break;
				
		}		
	}	
	
	if(hasspace == 1){
	
		return 0;
	
	}
	
	stringed[0]=map[(*ypos)+1][(*xpos)-1];
	movesnum = atoi(stringed);
						

	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)+i][(*xpos)-i] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	
	if(hasspace == 2){
	
		return 0;
	
	}
	stringed[0]=map[(*ypos)][(*xpos)+1];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)][(*xpos)+i] == ' '){
			hasspace++;	
			break;
				
		}		
	}

	if(hasspace == 3){
	
		return 0;
	
	}
	stringed[0]=map[(*ypos)][(*xpos)-1];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)][(*xpos)-i] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	if(hasspace == 4){
	
		return 0;
	
	}
	stringed[0]=map[(*ypos)-1][(*xpos)+1];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)-1][(*xpos)+i] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	
	if(hasspace == 5){
	
	return 0;
	
	}
	stringed[0]=map[(*ypos)-1][(*xpos)];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)-i][(*xpos)] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	
	if(hasspace == 6){
	
	return 0;
	
	}
	stringed[0]=map[(*ypos)-1][(*xpos)-1];
	movesnum = atoi(stringed);
						
	if(movesnum == 0){
	
		hasspace++;
	
	}

	for(i=1; (movesnum-i) >-1;i++){
		if(map[(*ypos)-i][(*xpos)-i] == ' '){
			hasspace++;	
			break;
				
		}		
	}
	
	if(hasspace == 7){
	
		return 0;
	
	}
	
	return 1;
//
}

void storescores(struct hiscore list[], FILE *fp){
	char charray[60];
	char number[10];
	char buff[50];
	int i;
	int j;
//	int k;
	int othercounter;
	int counter=0;
	struct hiscore tempstruct;
	for(i=0; i<10;i++){
		fgets(charray,60,fp);
		for(counter=0; charray[counter]!= '\t'; counter++){
			number[counter]=charray[counter];
					
		
		}
		number[counter]='\0';
		list[i].score= atoi(number);
		for(counter+=1, othercounter=0; charray[counter] != '\n'; counter++, othercounter++){
			buff[othercounter]=charray[counter];
			
		
		
		}	
		buff[othercounter]='\0';
		strcpy(list[i].name, buff);
	}
	for(i=1, j=i;i<=10;i++, j=i){
		while(j>0 && list[j-1].score > list[j].score){
			tempstruct = list[j];
			list[j] = list[j-1];
			list[j-1]=tempstruct;
		
			j--;
		}
	
	
	}


}
void writescores(struct hiscore *list, FILE *fp, int nameloc){
	int i;
	char nameput[30];
	fgets(nameput,30,stdin);
	nameput[strlen(nameput)-1]='\0';
	strcpy(list[nameloc].name,nameput);
	for(i=10; i!= 0; i--){
	
		fprintf(fp,"%d\t%s\n", list[i].score, list[i].name);
	
	}

}

void showscores(struct hiscore *list){
	int i;
	for(i=10; i>0; i--){
		printf("%d\t%s\n", list[i].score, list[i].name);
	
	
	}



}

void savemap(char map[][53], int currentscore, int *xpos, int *ypos){

	FILE *fileloc;
	char filename[30];
	int mapx, mapy;
	
	puts("Save where?");
	fgets(filename,30,stdin);
	filename[strlen(filename)-1]='\0';
	fileloc=fopen(filename, "w+");
	fprintf(fileloc,"%d\t%d\t%d\n", currentscore, *xpos, *ypos);
	for(mapy=1; mapy <= 22; mapy++){
		for(mapx=1; mapx <= 50; mapx++){
		
			fputc(map[mapy][mapx], fileloc);
		
		}
		fputc('\n', fileloc);
	
	}
	fclose(fileloc);
}


int loadgame(char map[][53], int currentscore, int *xpos, int *ypos){
	int i, j;
	char filename[30];
	//	char holder;
	FILE *fp;
	
	do{
		system("clear");
		puts("Name of file to load?");
		fgets(filename,30,stdin);
		filename[strlen(filename)-1]='\0';
		if(strcmp("q", filename)==0) return -1;
	}
	while((fp=fopen(filename, "r"))==NULL);
	
	fscanf(fp,"%d\t%d\t%d\n", &currentscore, xpos, ypos);
	for(i=1; i<=22; i++){
		for(j=1;j <= 50; j++){
			map[i][j]=fgetc(fp);
		
		}
		fgetc(fp);	
	}
	
	fclose(fp);
	return currentscore;
}
int main(){

	int menuselection;
	int cursorx;
	int cursory;
	int *cursorpx=&cursorx;
	int *cursorpy=&cursory;
	int testy;
	char inputbuff[30];
	char menubuff[255];
	int currentscore=1;
	int err=0;
	int tempscore;
	struct hiscore list[11];
	FILE *fp;
	srand(time(NULL));
	char map[24][53]; // there will be 2 extra height and width as a 'border' --see documentation
	while(1){
		menuselection=menuselect();
		if(menuselection == -1){
	
			return 0;
		
		}
		if(menuselection == 1){
	
			genmap(map);
			newgame(map, cursorpx, cursorpy);			
			
			currentscore = 1;
			break;
		}
		if(menuselection == 2){
			genmap(map);
			currentscore= loadgame(map, currentscore ,cursorpx, cursorpy);	
			if(currentscore==-1) return 0;
			else break;
		}
		if(menuselection ==	3){
			int x;
			fp=fopen("highscores.txt", "r");
			strcpy(list[10].name, "");
			list[10].score=0;
			storescores(list,fp);
			fclose(fp);
			system("clear");
			puts("Scoreboard");
			for(x=10;x!=0;x--){
				printf("%d\t%s\n", list[x].score, list[x].name);
			
			
			}
			puts("");
			puts("Press anything to continue");
			fgets(menubuff,255,stdin);
		}
		if(menuselection == 4){
			system("clear");
			puts("You are a 1337 H4xx0r by the name of 0. One day, you decide to go hack Tfos Orcim's servers. The session ends badly, and now you, the 1337 H4xx0r, must attempt to escape the clutches of the server's Waterwall(made by Tfos Orcim of course) through your h4xx0r 5K1LLZ");
			puts("Commands:");
			puts("y for Upleft, u for Upright");
			puts("h for Left, l for Right");
			puts("j for Down, k for Up");
			puts("n for Downleft, m for Downright");
			puts("Press q/Q anytime ingame to quit, 'save' to save");
			puts("");
			puts("Press anything to continue");
			fgets(menubuff,255,stdin);
		}
	}
	while(1){
			system("clear");
			for(testy=0; testy < 24; testy++){
	
				puts(map[testy]);
				
			}
			if(checkmoves(map, cursorpx, cursorpy) == 1){
				int cfscorearray;
				printf("No moves left. Game over player-san. Your score is %d\n", currentscore);
				strcpy(list[10].name, "");
				list[10].score=currentscore;
				fp=fopen("highscores.txt", "r");
				storescores(list, fp);
				fclose(fp);
				for(cfscorearray=10; cfscorearray != 0; cfscorearray--){
					if(strcmp(list[cfscorearray].name, "")==0){
						puts("Congratulations! High Score! Enter name!");
						fp=fopen("highscores.txt", "w");
						writescores(list, fp, cfscorearray);
						fclose(fp);
						break;
					}
				
					
				}
				system("clear");
				puts("Scoreboard");
				showscores(list);
				return 0;
			}
			printf("Score: %d\t Enter command in lowercase: Q or q can be used though\n", currentscore);	
			if(err==1){
				
				puts("Invalid command");
			
			}

			if(err==2){
				puts("Bad move");
			
			
			}
			fgets(inputbuff, 30, stdin);
			if(strcmp("save\n",inputbuff)==0){
			
				savemap(map, currentscore, cursorpx, cursorpy);
				return 0;
			
			}
			if(strlen(inputbuff) > 2){
				err=1;
				continue;
			}
			
			else if(inputbuff[0] == 'q'|| inputbuff[0] == 'Q'){
			
				return 1;
			}
			else if(inputbuff[0]== 'y' ||inputbuff[0]== 'u' ||
			inputbuff[0]== 'h' ||inputbuff[0]== 'j' ||inputbuff[0]== 'k' ||
			inputbuff[0]== 'b' ||inputbuff[0]== 'l' ||inputbuff[0]== 'n'){
				tempscore= movement(map,cursorpx, cursorpy, inputbuff[0]);	
				currentscore += tempscore;
				if(tempscore == 0) err=2;	
				else err=0;
			}
			else{
				err=1;
				continue;
			
			}
		}
	
	//printf("%d, %d\n", cursorx, cursory);
	//printf("%d, %d\n", *cursorpx, *cursorpy);

	return 0;

}
