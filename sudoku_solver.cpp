#include<bits/stdc++.h>
using namespace std;

int n,N;
int filled;

vector<vector<bool> > rows;
vector<vector<bool> > cols;
vector<vector<bool> > boxes;

vector<int> crows;

int check(vector<vector<int> > &mat) {
    int i,j,k,x;
    if(filled==(N*N))
        return 1;

    //find a cell which is unfilled
    i=0;
    while(i<N && crows[i]==N){
        i++;
    }

    j=0;

    while(j<N && mat[i][j]!=0){
        j++;
    }
   
    //calculate the box of the vacant cell (i,j)
    k=(((i/n)*n)+(j/n));

    //we got the vacant cell
    //now, try putting nums here
    for(x=1;x<=N;x++){
        if(rows[i][x]==false && cols[j][x]==false && boxes[k][x]==false){    
            //place x at cell (i,j)
            filled++;
            
            rows[i][x]=true;
            cols[j][x]=true;
            boxes[k][x]=true;
            
            crows[i]++;

            mat[i][j]=x;

            //check if solution found
            if(check(mat)) {
                return 1;
            }
            
            //unplace x from cell (i,j)
            filled--;
            
            rows[i][x]=false;
            cols[j][x]=false;
            boxes[k][x]=false;
            
            crows[i]--;

            mat[i][j]=0;
        }
    }
        
    return 0;
}

int SolveMagicSquare(vector<vector<int> > mat)
{
    int i,j,k,x;
    N=mat.size();
    n=sqrt(N);
    
    rows.resize(N,vector<bool>(N+1,false));
    cols.resize(N,vector<bool>(N+1,false));
    boxes.resize(N,vector<bool>(N+1,false));

    crows.resize(N,0);
    
    filled=0;
    
    int result=1;
    
    for(i=0;i<N && result==1;i++){
        for(j=0;j<N && result==1;j++){
            x=mat[i][j];

            if(x!=0){
                k=(((i/n)*n)+(j/n));
                if(rows[i][x]==true || cols[j][x]==true || boxes[k][x]==true){
                    result=0;
                } else {
                    rows[i][x]=true;
                    cols[j][x]=true;
                    boxes[k][x]=true;

                    crows[i]++;

                    filled++;
                }
            }
        }
    }
   
    if(result==0){
        return result;
    }
    
    //look for a solution now
    //if solution found, return 1
    //else return 0
    result=check(mat);

    return result;
}

int main() {
    int output;
    
    int N;
    cout<<"Input N (no. of rows ) ";
    cin>>N;
    
    vector< vector < int > > sudoku(N, vector<int>(N));
    cout<<"Input N*N values of sudoku"<<endl;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin>>sudoku[i][j];
        }
    }
    
    output = SolveMagicSquare(sudoku);
    
    if(output){
        cout<<"the solution is "<<endl;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<sudoku[i][j]<<"  ";
            }
            
            cout<<endl;
        }
        
    } else {
        cout<<"No solution exists for the input sudoku"<<endl;
    }
    
    return 0;
}
