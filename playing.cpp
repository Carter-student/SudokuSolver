//We make a suduku solver
//Borrowing from https://hackr.io/blog/cpp-projects
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define empty_var 0
#define N 9
int spanner[N][N];
int rowBound[2];

bool possRow(std::string possible[N][N], int pRow, int valueCheck){
    int count=0;
    for (int column=0; column<N; column++){
        if (possible[pRow][column].find(std::to_string(valueCheck))!=-1){
            if (count>0){
            return false;}
            count=1;
        }
    }
    cout << "passRow";
    return true;
    }
bool possCol(std::string possible[N][N], int pCol, int valueCheck){
    int count=0;
    for (int row=0; row<N; row++){
        if (possible[row][pCol].find(std::to_string(valueCheck))!=-1){
            if (count>0){
            return false;}
            count=1;

        }
    }
    std::cout << "possCol";
    return true;
    }
bool possBox(std::string possible[N][N], int lrowBound[2], int lcolBound[2], int valueCheck){
        int count=0;
        int lrow=lrowBound[0], hrow=lrowBound[1];
        int lcol=lcolBound[0], hcol=lcolBound[1];
        for (lrow;lrow<hrow;lrow++){
        for (lcol;lcol<hcol;lcol++){
            if (possible[lrow][lcol].find(std::to_string(valueCheck))!=-1){
                if (count>0){
                return false;}
                count=1;
            }
        }

    }
    cout<< "possBox";
    return true;
}
bool emptyBox(int checkValue){
    if (checkValue== empty_var){
        return false;
    }
    return true;
}
void whatBox(int griddy[N][N], int row_col){
    int globalRows[3]={3,6,9};
    int globalCols[3]= {3,6,9};
    
    if (row_col< 3){
        rowBound[0]=0;
        rowBound[1]=3;
    } else if (row_col<6){
        rowBound[0]=3;
        rowBound[1]=6;
    } else{
        rowBound[0]=6;
        rowBound[1]=9;}
}


bool checkRow(int griddy[N][N], int pRow, int valueCheck){
    for (int column=0; column<N; column++){
        if (valueCheck==griddy[pRow][column]){
            return false;
        }
    }
    return true;
}
bool checkColumn(int griddy[N][N], int pCol, int valueCheck){
    for (int row=0; row<N; row++){
        if (valueCheck==griddy[row][pCol]){
            return false;
        }
    }
    return true;
}
bool checkBox(int griddy[N][N], int lrowBound[2], int lcolBound[2], int valueCheck){
    
    for (lrowBound[0];lrowBound[0]<lrowBound[1];lrowBound++){
        for (lcolBound[0];lcolBound[0]<lcolBound[1];lcolBound++){
            if (griddy[lrowBound[0]][lcolBound[0]]==valueCheck){
                return false;
            }
        }

    }
    return true;
}

void printSuduku(int griddy[N][N])
{
    int row=0, column=0;
    for (row; row<N;row++){
        for (column=0;column<N; column++)
        {
            std::cout << griddy[row][column] << " ";
        }
        
        std::cout << endl;
    }
}
void printSuduku2(std::string griddy[N][N])
{
    int row=0, column=0;
    for (row; row<N;row++){
        for (column=0;column<N; column++)
        {
            std::cout << griddy[row][column] << " ";
        }
        
        std::cout << endl;
    }
}
bool solvePuzzle(int griddy[N][N]){
    bool change =false;
    int row=0, column=0;
    std::string poss[N][N];
    for (row; row<N;row++){
        for (column=0;column<N; column++)
        {
            whatBox(griddy, row);
            int lrow[2];
            lrow[0]=rowBound[0];
            lrow[1]=rowBound[1];
            whatBox(griddy, column);
            int lcol[2];
            lcol[0]=rowBound[0];
            lcol[1]=rowBound[1];
            for (int i=1; i<10; i++){
                if(checkColumn(griddy,column, i) && checkRow(griddy, row, i) && checkBox(griddy, lrow, lcol, i) && !emptyBox(griddy[row][column])){
                    poss[row][column].append(std::to_string(i));
                }
            }
        }}
        for (row=0; row<N;row++){
        for (column=0;column<N; column++)
        {if (poss[row][column].length()<2 && !emptyBox(griddy[row][column]) && poss[row][column]!=""){
            int num=stoi(poss[row][column]);
            griddy[row][column]=num;
            change=true;
        }

        if (change==true){
            cout << "pre ";
            solvePuzzle(griddy);
            cout << "loop";
            return false;
        }
        for (row=0; row<N;row++){
        for (column=0;column<N; column++)
        {
            whatBox(griddy, row);
            int lrow[2];
            lrow[0]=rowBound[0];
            lrow[1]=rowBound[1];
            whatBox(griddy, column);
            int lcol[2];
            lcol[0]=rowBound[0];
            lcol[1]=rowBound[1];
            std::string hold=poss[row][column];
            if (!poss[row][column].empty()) {
                int counter=poss[row][column].length();
                for (int ii=0; ii<N; ii++){
                    
                    if (counter == ii){
                        break;
                    }
                    char hold_char=hold[ii];
                    int hold_int=std::stoi(&hold_char);
                    if (possRow(poss, row, hold_int)||possCol(poss,column, hold_int)||possBox(poss,lrow,lcol,hold_int) && griddy[row][column]!=0){
                        griddy[row][column]=hold_int;
                        solvePuzzle(griddy);
                        return false;
                    }
                    //std::cout << (holdnum) << " ";
                    
                }
            }

        }}

        }}
        cout << endl << "New" << endl;
        printSuduku(griddy);
        return false;}

int main()
{   
    /* int spanner[N][N] = {{5, 0, 0, 4, 6, 7, 3, 0, 9},
                      {9, 0, 3, 8, 1, 0, 4, 2, 7},
                      {1, 7, 4, 2, 0, 3, 0, 0, 0},
                      {2, 3, 1, 9, 7, 6, 8, 5, 4},
                      {8, 5, 7, 1, 2, 4, 0, 9, 0},
                      {4, 9, 6, 3, 0, 8, 1, 7, 2},
                      {0, 0, 0, 0, 8, 9, 2, 6, 0},
                      {7, 8, 2, 6, 4, 1, 0, 0, 5},
                      {0, 1, 0, 0, 0, 0, 7, 0, 8}}; */
    int spanner[N][N] = {{0, 0, 0, 7, 4, 8, 6, 0, 0},
                      {7, 0, 0, 0, 0, 3, 0, 1, 0},
                      {3, 0, 6, 0, 0, 5, 0, 0, 0},
                      {5, 2, 0, 8, 0, 0, 1, 4, 3},
                      {6, 0, 0, 0, 0, 0, 0, 0, 5},
                      {8, 3, 4, 0, 0, 9, 0, 7, 6},
                      {0, 0, 0, 3, 0, 0, 8, 0, 2},
                      {0, 5, 0, 4, 0, 0, 0, 0, 1},
                      {0, 0, 3, 5, 6, 2, 0, 0, 0}};
    printSuduku(spanner);
    solvePuzzle(spanner);


    return 1;
}