#include<iostream>
#include<cstdio>
using namespace std;
class Helper{
	private:
		char **Maze;
		int **Flag;
		int X,Y;
		int Count;
	public:
		Helper(int x,int y){
			int i;
			X=x;
			Y=y;
			Maze=new char*[X+2];
			Flag=new int*[X+2];
			i=0;
			while(i<(X+2)){
				Maze[i]=new char[Y+2];
				Flag[i]=new int[Y+2];
				i++;
			}
			Count=2;
		}
		void getMaze(){
			int i,j;
			i=1;
			while(i<(X+1)){
				scanf("%s",&Maze[i][1]);
				j=1;
				while(j<(Y+1)){
					if(Maze[i][j]=='.'){
						Flag[i][j]=0;
					}
					else{
						Flag[i][j]=1;
					}
					j++;
				}
				i++;
			}
			i=0;
			while(i<(Y+2)){
				Maze[0][i]='.';
				Maze[X+1][i]='.';
				Flag[0][i]=0;
				Flag[X+1][i]=0;
				i++;
			}
			i=0;
			while(i<(X+2)){
				Maze[i][0]='.';
				Maze[i][Y+1]='.';
				Flag[i][0]=0;
				Flag[i][Y+1]=0;
				i++;
			}
		}
		int findIslands(){
			int i,j;
			i=1;
			while(i<=X){
				j=1;
				while(j<=Y){
					if(Maze[i][j]=='#' && Flag[i][j]==1){
						setMaze(i,j);
						++Count;
					}
					j++;
				}
				i++;
			}
			return Count-2;
		}
		void setMaze(int x,int y){
			Flag[x][y]=Count;
			if(Maze[x-1][y-1]=='#' && Flag[x-1][y-1]==1){
				setMaze(x-1,y-1);
			}
			if(Maze[x-1][y]=='#' && Flag[x-1][y]==1){
				setMaze(x-1,y);
			}
			if(Maze[x-1][y+1]=='#' && Flag[x-1][y+1]==1){
				setMaze(x-1,y+1);
			}
			if(Maze[x][y+1]=='#' && Flag[x][y+1]==1){
				setMaze(x,y+1);
			}
			if(Maze[x+1][y+1]=='#' && Flag[x+1][y+1]==1){
				setMaze(x+1,y+1);
			}
			if(Maze[x+1][y]=='#' && Flag[x+1][y]==1){
				setMaze(x+1,y);
			}
			if(Maze[x+1][y-1]=='#' && Flag[x+1][y-1]==1){
				setMaze(x+1,y-1);
			}
			if(Maze[x][y-1]=='#' && Flag[x][y-1]==1){
				setMaze(x,y-1);
			}
		}
};
int main(){
	int T;
	int x,y;
	scanf("%d",&T);
	while(T>0){
		scanf("%d %d",&x,&y);
		Helper ob(x,y);
		ob.getMaze();
		printf("%d\n",ob.findIslands());
		//ob.display();
		T--;
	}
	return 0;
}