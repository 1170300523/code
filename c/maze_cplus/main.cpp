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
int **Maze;     //��ʼ���Թ�
point **Pre;    //�����������·���е�ǰһ��
point move[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};      //�ƶ����򣬺���б�����ԣ��˸�����
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
    //�ж��Ƿ���·������ڵ����ڣ������·�������У�
    if(x == row && y == column)return true;
    queue<point> q;     //���ڹ����������
    point now;          //��ǰλ��
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
                point temp;     //�¸�λ��
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
    //������·��
    point temp;         //����λ��
    stack<point> s;     //����·������
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

    int row;        //�Թ�����
    int column;     //�Թ�����
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
