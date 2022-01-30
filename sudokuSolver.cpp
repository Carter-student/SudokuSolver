//We make a suduku solver
//Borrowing from https://hackr.io/blog/cpp-projects
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;
#define empty_var 0
#define N 9
int griddy[N][N];

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
    //cout << "passRow";
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
   // std::cout << "possCol";
    return true;
    }
bool possBox(std::string possible[N][N], int lrowBound[2], int lcolBound[2], int valueCheck){
    int check_counter=1;
    int rowStart; rowStart=lrowBound[0];
    int colStart; colStart=lcolBound[0];
    int count=0;
    for (int row = 0;row<3;row++){
        for (int column =0;column<3;column++){
            int positionR=row+rowStart; int positionC=column+colStart;
            if (possible[positionR][positionC].find(std::to_string(valueCheck))!=-1){
                if (count>0){
                return false;}
                count=1;
            }
        }

    }
    //cout<< "possBox";
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
    int check_counter=1;
    for (int column=0; column<N; column++){
        if (valueCheck==griddy[pRow][column]){
            if  (check_counter==1){
            return false;}
            else {check_counter=1;}
        }
    }
    return true;
}
bool checkColumn(int griddy[N][N], int pCol, int valueCheck){
    int check_counter=1;
    for (int row=0; row<N; row++){
        if (valueCheck==griddy[row][pCol]){
            if (check_counter==1){
            return false;}
            else{check_counter=1;}
        }
    }
    return true;
}
bool checkBox(int griddy[N][N], int lrowBound[2], int lcolBound[2], int valueCheck){
    int check_counter=1;
    int rowStart; rowStart=lrowBound[0];
    int colStart; colStart=lcolBound[0];
    for (int row=0; row<3; row++){
        for (int column=0; column<3; column++){
            int positionR=row+rowStart; int positionC=column+colStart;
            if (griddy[positionR][positionC]==valueCheck){
                if (check_counter==1){
                return false;}
                else{check_counter=1;}
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
bool isEmpty(std::string emptyGuy){
    return !emptyGuy.empty();
}
std::string reductionLogic(int griddy[N][N]){
    std::string passString;
    std::string poss[N][N];
            bool changes=false;
            for (int row=0; row<N; row++){
                for (int column=0;column<N; column++){
                    whatBox(griddy, row);
                    int lrow[2];
                    lrow[0]=rowBound[0]; lrow[1]= rowBound[1];
                    whatBox(griddy, column);
                    int lcol[2];
                    lcol[0]=rowBound[0]; lcol[1]= rowBound[1];
                    for (int value=1; value<10; value++){
                        if (!emptyBox(griddy[row][column]) && checkBox(griddy, lrow, lcol, value) && checkRow(griddy, row, value) && checkColumn(griddy, column, value)){
                            poss[row][column].append(to_string(value));
                            }
                        }
                    if (poss[row][column].length()==1){
                       
                        passString.append(to_string(row));
                        passString.append(to_string(column));
                        passString.append(poss[row][column]);
                        changes=true;

                    }
                }
            }
    return passString;
}
std::string destructiveLogic(int griddy[N][N]){
    std::string passString;
    std::string poss[N][N];
            bool changes=false;
            for (int row=0; row<N; row++){
                for (int column=0;column<N; column++){
                    whatBox(griddy, row);
                    int lrow[2];
                    lrow[0]=rowBound[0]; lrow[1]= rowBound[1];
                    whatBox(griddy, column);
                    int lcol[2];
                    lcol[0]=rowBound[0]; lcol[1]= rowBound[1];
                    for (int value=1; value<10; value++){
                        if (!emptyBox(griddy[row][column]) && checkBox(griddy, lrow, lcol, value) && checkRow(griddy, row, value) && checkColumn(griddy, column, value)){
                            poss[row][column].append(to_string(value));}}
                    if (emptyBox(griddy[row][column])){
                        poss[row][column]=to_string(griddy[row][column]);}}}
        for (int row=0; row<N; row++){
                for (int column=0;column<N; column++){
                    whatBox(griddy, row);
                    int lrow[2];
                    lrow[0]=rowBound[0]; lrow[1]= rowBound[1];
                    whatBox(griddy, column);
                    int lcol[2];
                    lcol[0]=rowBound[0]; lcol[1]= rowBound[1];
                    if (poss[row][column].length()>1){
                        int counter=poss[row][column].length();
                        for (int ii=0; ii<N; ii++){
                            if (counter==ii){break;}
                            char cvalue= poss[row][column][ii];
                            int ivalue= stoi(&cvalue);
                            if(possRow(poss, row, ivalue) || possCol(poss, column, ivalue) || possBox(poss,lrow,lcol,ivalue) ){//fix possBox
                                passString.append(to_string(row));
                                passString.append(to_string(column));
                                passString.append(to_string(ivalue));
                                changes= true;}}}}}
    return passString;
}
bool solvePuzzle(int griddy[N][N]){
    // add another outer loop
    bool bigChanges = true;
    int bigCounter=0;
    
    bool changes = true;
    while (bigChanges)
    {
    bigCounter++;
    while (changes){
        int new_row; int new_column; int new_value;
        std::string returned_String;
        returned_String=reductionLogic(griddy);
        if (returned_String.length()>0){// we need to be more efficient and do a loop here
        std::string new_row; new_row+=returned_String[0]; int new_rowi=stoi(new_row);
        std::string new_col; new_col+=returned_String[1]; int new_coli=stoi(new_col);
        std::string new_value; new_value+=returned_String[2]; int new_valuei=stoi(new_value);
        griddy[new_rowi][new_coli]=new_valuei;
        bigCounter=0;
        }
        else{break;}}
    changes= true;
    while(changes){
        std::string returned_String;
        returned_String=destructiveLogic(griddy);
        if(returned_String.length()>0){
        std::string new_row; new_row+=returned_String[0]; int new_rowi=stoi(new_row);
        std::string new_col; new_col+=returned_String[1]; int new_coli=stoi(new_col);
        std::string new_value; new_value+=returned_String[2]; int new_valuei=stoi(new_value);
        griddy[new_rowi][new_coli]=new_valuei;
        bigCounter=0;
        }else{break;}
      
    }// end of while loop
      if (bigCounter>2){//we changed this from 1
            bigChanges=false;}
    }
    cout << endl << "new" << endl;
    printSuduku(griddy);
    return true;
}

int main()
{  
    /* int griddy[N][N] = {{5, 0, 0, 4, 6, 7, 3, 0, 9},
                      {9, 0, 3, 8, 1, 0, 4, 2, 7},
                      {1, 7, 4, 2, 0, 3, 0, 0, 0},
                      {2, 3, 1, 9, 7, 6, 8, 5, 4},
                      {8, 5, 7, 1, 2, 4, 0, 9, 0},
                      {4, 9, 6, 3, 0, 8, 1, 7, 2},
                      {0, 0, 0, 0, 8, 9, 2, 6, 0},
                      {7, 8, 2, 6, 4, 1, 0, 0, 5},
                      {0, 1, 0, 0, 0, 0, 7, 0, 8}}; */
    /*int griddy[N][N] = {{0, 0, 0, 7, 4, 8, 6, 0, 0},
                      {7, 0, 0, 0, 0, 3, 0, 1, 0},
                      {3, 0, 6, 0, 0, 5, 0, 0, 0},
                      {5, 2, 0, 8, 0, 0, 1, 4, 3},
                      {6, 0, 0, 0, 0, 0, 0, 0, 5},
                      {8, 3, 4, 0, 0, 9, 0, 7, 6},
                      {0, 0, 0, 3, 0, 0, 8, 0, 2},
                      {0, 5, 0, 4, 0, 0, 0, 0, 1},
                      {0, 0, 3, 5, 6, 2, 0, 0, 0}};*/
    int griddy[N][N] = { {0, 0, 0, 0, 3, 0, 0, 9, 0}, 
         {0, 3, 1, 0, 0, 9, 0, 0, 0}, 
         {9, 0, 0, 4, 6, 5, 0, 3, 0}, 
         {0, 0, 0, 0, 0, 7, 4, 0, 0}, 
         {7, 9, 0, 0, 0, 0, 0, 1, 5}, 
         {0, 0, 2, 8, 0, 0, 0, 0, 0},  
         {0, 7, 0, 5, 4, 3, 0, 0, 8}, 
         {0, 0, 0, 7, 0, 0, 9, 5, 0},  
         {0, 4, 0, 0, 8, 0, 0, 0, 0} };
    cout << endl;
    printSuduku(griddy);
    solvePuzzle(griddy);


    return 1;
}