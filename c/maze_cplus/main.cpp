/*
8 8
0 1 1 1 0 1 1 1
1 0 1 0 1 0 1 0
0 1 0 0 1 1 1 1
0 1 1 1 0 0 1 1
1 0 0 1 1 0 0 0
0 1 1 0 0 1 1 0
0 1 1 0 0 0 0 0
0 1 1 1 1 0 0 0
*/
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct point{
    int x;
    int y;
};
int **Maze;     //初始化迷宫
point **Pre;    //保存任意点在路径中的前一步
point move[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};      //移动方向，横竖斜都可以，八个方向
void Create(int row,int column){

    int i,j;
    for(i=0; i<row+2; i++)
		Maze[i][0] = Maze[i][column+1] = 1;
    for(j=0; j<column+2; j++)
		Maze[0][j] = Maze[row+1][j] = 1;
    cout<<"input the maze!:\n";
    for(i=1; i<=row; i++){
        for(j=1; j<=column; j++){
            cin>>Maze[i][j];
        }
    }
}
bool MazePath(int row,int column,int x,int y){
    //判断是否有路径从入口到出口，保存该路径（队列）
    if(x == row && y == column)return true;
    queue<point> q;     //用于广度优先搜索
    point now;          //当前位置
    now.x = x;
    now.y = y;
    q.push(now);
    Maze[now.x][now.y] = -1;
    while(!q.empty()){
        now = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            if(now.x + move[i].x == row && now.y + move[i].y == column){
                Maze[now.x + move[i].x][now.y + move[i].y] = -1;
                Pre[row][column] = now;
                return true;
            }
            if(Maze[now.x + move[i].x][now.y + move[i].y] == 0){
                point temp;     //下个位置
                temp.x = now.x + move[i].x;
                temp.y = now.y + move[i].y;
                q.push(temp);
                Maze[temp.x][temp.y] = -1;
                Pre[temp.x][temp.y] = now;

            }
        }
    }
    return false;
}
void PrintPath(int row,int column){
    //输出最短路径
    point temp;         //保存位置
    stack<point> s;     //保存路径序列
    temp.x = row;
    temp.y = column;
    while(temp.x != 1 || temp.y != 1){
        s.push(temp);
        temp = Pre[temp.x][temp.y];
    }
    cout<<"(1,1)";
    while(!s.empty()){
        temp = s.top();
        cout<<"->"<<'('<<temp.x<<','<<temp.y<<')';
        s.pop();
    }
    cout<<endl;
}
int main(){

    int row;        //迷宫行数
    int column;     //迷宫列数
    cout<<"input row and column:\n";
        cin>>row>>column;
        Maze = new int*[row + 2];
        Pre = new point*[row + 2];
        for(int i=0; i<row+2; i++){
            Maze[i] = new int[column + 2];
            Pre[i] = new point[column + 2];
        }

        Create(row,column);
		if(MazePath(row,column,1,1)){
		    cout<<"find a way!"<<endl;
		    PrintPath(row,column);
		}
		else cout<<"NO way"<<endl;

    return 0;
}
