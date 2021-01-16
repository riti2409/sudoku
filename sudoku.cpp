#include<iostream>
using namespace std;

int n;
bool canPlace(int mat[][9],int x,int y,int val){
    ///Check along row
    for(int i=0;i<n;i++){
        if(mat[x][i]==val){
            return false;
        }
    }
    ///Check along col
    for(int i=0;i<n;i++){
        if(mat[i][y]==val){
            return false;
        }
    }
    ///Check along subgrid
    int sx = (x/3)*3;
    int sy = (y/(n/3))*(n/3);

    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+(n/3);j++){
            if(mat[i][j]==val){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int mat[][9],int i,int j){
    if(i==n){
        return true;
    }
    if(j==n){
        return solveSudoku(mat,i+1,0);
    }
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1);
    }
    else{
        ///Hume fill krna
        for(int no=1;no<=n;no++){
            if(canPlace(mat,i,j,no)){
                mat[i][j] = no;
                bool solveHua = solveSudoku(mat,i,j+1);
                if(solveHua==true){
                    return true;
                }
            }

        }
        ///Backtracking
        mat[i][j]=0;
        return false;

    }
}




int main(){

		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("out.txt","w",stdout);
		#endif
        int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
        /*
           for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cin>>n;
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<n;j++)
        		cin>>mat[i][j];
        }
        solveSudoku(mat,0,0);

        //cout<<"Solved Sudoku "<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
		return 0;
}
