#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>   // extra heading for a TRULY random number generator
#include <iomanip>  //extra heading for 2d array spacing

using namespace std;

void sort_it_left(int matrix[4][4]);
void left(int matrix[4][4]);
void sort_it_right(int matrix[4][4]);
void right(int matrix[4][4]);
void sort_it_up(int matrix[4][4]);
void up(int matrix[4][4]);
void sort_it_down(int matrix[4][4]);
void down(int matrix[4][4]);
void random_generator(int matrix[4][4]);
bool check_if_possible_moves_in_direction(int matrix[4][4],string& input_direction);
bool check_all_moves(int matrix[4][4]);

int main() {

    ifstream infile;
    string infilename;
    int matrix [4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    cout<<"enter initial configuration file name: ";
    cin>>infilename;
    infile.open(infilename.c_str());

    int tmp1;


    if(!(infile.is_open())){
        cout<<"coudn't find file ;"<<endl;
        cout<<"using default configuration:"<<endl;

    matrix[3][3]=2;
            for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                    cout<<setw(6)<<matrix[i][j]<<setw(6);
                    cout<<endl;
                        }


    }
    else{
        for(int p=0;p<4;p++){
        int i=0;int j=0;
        while(infile>>tmp1){

        if(!(j==4)){
            matrix[i][j]=tmp1;
            j++;
        }
        if(j==4){
            j=0;
            i++;
        }
    }
                    for(int q=0;q<4;q++)
                    cout<<setw(6)<<
                    matrix[p][q]<<setw(6);
                    cout<<endl;
                        }
    }

    string input_direction;
    while(check_all_moves(matrix)){
            cout<<endl;
            cin>>input_direction;

                if(input_direction=="a"){

                    if(check_if_possible_moves_in_direction(matrix,input_direction)){
                    left(matrix);
                    random_generator(matrix);
                    for(int i=0;i<4;i++){

                    for(int j=0;j<4;j++)
                    cout<<matrix[i][j]<<setw(6);
                    cout<<endl;
                        }
                    }
                }

                if(input_direction=="w"){
                    if(check_if_possible_moves_in_direction(matrix,input_direction)){
                    up(matrix);
                    random_generator(matrix);
                    for(int i=0;i<4;i++){

                    for(int j=0;j<4;j++)
                    cout<<matrix[i][j]<<setw(6);
                    cout<<endl;
                            }
                    }
                }

                if(input_direction=="d"){
                   if(check_if_possible_moves_in_direction(matrix,input_direction)){
                    right(matrix);
                    random_generator(matrix);
                    for(int i=0;i<4;i++){

                    for(int j=0;j<4;j++)
                    cout<<matrix[i][j]<<setw(6);
                    cout<<endl;
            }
       }
                }
                if(input_direction=="s"){
                if(check_if_possible_moves_in_direction(matrix,input_direction)){
                down(matrix);
                random_generator(matrix);
                for(int i=0;i<4;i++){
                for(int j=0;j<4;j++)
                cout<<matrix[i][j]<<setw(6);
                cout<<endl;
        }
        }
                }


    }


cout<<"gameover";
    return 0;

}
//----------------------------------------------------------------------------------------------------------------
void sort_it_up(int matrix[4][4]){

    for(int repeat=0;repeat<4;repeat++){
    for(int j=0;j<4;j++){

        for(int i=0;i<4;i++){
                if(i<3){
            if(matrix[i][j]==0 && !(matrix[i+1][j]==0)){
                    matrix[i][j]=matrix[i+1][j];
                    matrix[i+1][j]=0;
                    }
                }
            }
        }
    }
}

void up(int matrix[4][4]){

    sort_it_up(matrix);

    for(int j=0;j<4;j++){

        for(int i=0;i<4;i++){

            if(i<3){

                if(matrix[i][j]==matrix[i+1][j]){
                    matrix[i][j]=matrix[i][j]+matrix[i+1][j];
                    matrix[i+1][j]=0;
                }
                else{

                    }
                }
            }
            sort_it_up(matrix);
        }
    }
//------------------------------------------------------------------------------------
void sort_it_left(int matrix[4][4]){

    for(int repeat=0;repeat<4;repeat++){
    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){
                if(j<3){
            if(matrix[i][j]==0 && !(matrix[i][j+1]==0)){
                    matrix[i][j]=matrix[i][j+1];
                    matrix[i][j+1]=0;
                    }
                }
            }
        }
    }
}

void left(int matrix[4][4]){
sort_it_left(matrix);
    for(int i=0;i<4;i++){

        for(int j=0;j<4;j++){

            if(j<3){

                if(matrix[i][j]==matrix[i][j+1]){
                    matrix[i][j]=matrix[i][j]+matrix[i][j+1];
                    matrix[i][j+1]=0;
                }
                else{

                    }
                }
            }
            sort_it_left(matrix);
        }
}
//---------------------------------------------------------------------------------------------------------

void sort_it_right(int matrix[4][4]){
    for(int repeat=0;repeat<4;repeat++){
    for(int i=3;i>-1;i--){

        for(int j=3;j>-1;j--){
                if(j>0){
            if(matrix[i][j]==0 && !(matrix[i][j-1]==0)){
                    matrix[i][j]=matrix[i][j-1];
                    matrix[i][j-1]=0;
                    }
                }
            }
        }
    }
}

void right(int matrix[4][4]){

        sort_it_right(matrix);

        for(int i=3;i>-1;i--){

        for(int j=3;j>-1;j--){

            if(j>0){

                if(matrix[i][j]==matrix[i][j-1]){
                    matrix[i][j]=matrix[i][j]+matrix[i][j-1];
                    matrix[i][j-1]=0;
                }
                else{

                    }
                }
            }
            sort_it_right(matrix);
        }
}
//-----------------------------------------------------------------------------------------------------------------------------------
void sort_it_down(int matrix[4][4]){
    for(int repeat=0;repeat<4;repeat++){
    for(int j=3;j>-1;j--){

        for(int i=3;i>-1;i--){
                if(i>0){
            if(matrix[i][j]==0 && !(matrix[i-1][j]==0)){
                    matrix[i][j]=matrix[i-1][j];
                    matrix[i-1][j]=0;
                    }
                }
            }
        }
    }
}

void down(int matrix[4][4]){
        sort_it_down(matrix);
       for(int j=3;j>-1;j--){

        for(int i=3;i>-1;i--){

            if(i>0){

                if(matrix[i][j]==matrix[i-1][j]){
                    matrix[i][j]=matrix[i][j]+matrix[i-1][j];
                    matrix[i-1][j]=0;
                }
                else{

                    }
                }
            }
            sort_it_down(matrix);
        }

}
//---------------------------------------------------------------------------------------------------------------------
void random_generator(int matrix[4][4]){
    int counter=0;
    int i;
    int j;
    vector<int>checker;
    for(int p=0;p<4;p++){
        for(int q=0;q<4;q++){
            if(matrix[p][q]==0){
                checker.push_back(1);
            }
        }
    }
    srand(time(0));
    if(!(checker.size()==0)){
    while(counter==0){

        i=rand()%4;
        j=rand()%4;

        if(matrix[i][j]==0){
            matrix[i][j]=2;
            counter=1;
        }
    }
    }
    checker.clear();
}
//----------------------------------------------------------------------------------------------------------------------
bool check_if_possible_moves_in_direction(int matrix[4][4],string& input_direction){
    vector<int> checker;

    if(input_direction=="a"){

        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
                if(j<3){
            if(matrix[i][j]==matrix[i][j+1] && !(matrix[i][j]==0 && matrix[i][j+1]==0)){
                  checker.push_back(1);
                    }
                    else if(matrix[i][j]==0 && !(matrix[i][j+1]==0)){
                        checker.push_back(1);
                    }
                }
            }
        }
    }

      else if(input_direction=="w"){

         for(int j=0;j<4;j++){

        for(int i=0;i<4;i++){

            if(i<3){

                if(matrix[i][j]==matrix[i+1][j] && !(matrix[i][j]==0 && matrix[i+1][j]==0)){
                        checker.push_back(1);
                }
                else if(matrix[i][j]==0 && !(matrix[i+1][j]==0)){
                        checker.push_back(1);
                }
        }
        }
        }
      }
    else if(input_direction=="d"){

        for(int i=3;i>-1;i--){

        for(int j=3;j>-1;j--){
                if(j>0){
            if(matrix[i][j]==matrix[i][j-1] && !(matrix[i][j]==0 && matrix[i][j-1]==0)){
                    checker.push_back(1);
                    }
                    else if(matrix[i][j]==0 && !(matrix[i][j-1]==0)){
                        checker.push_back(1);
                    }

                }
            }
        }
    }

    else if(input_direction=="s"){

         for(int j=3;j>-1;j--){

        for(int i=3;i>-1;i--){
                if(i>0){
            if(matrix[i][j]==matrix[i-1][j] && !(matrix[i][j]==0 && matrix[i-1][j]==0)){
                   checker.push_back(1);
                    }
                    else if(matrix[i][j]==0 && !(matrix[i-1][j]==0)){
                        checker.push_back(1);
                    }

                }
            }
        }
    }

    if(!(checker.size()==0)){
            checker.clear();
        return true;
    }
    else{ checker.clear();
        return false;
}
}
//-----------------------------------------------------------------------------------------------------------------
bool check_all_moves(int matrix[4][4]){

        for(int p=0;p<4;p++){
        for(int q=0;q<4;q++){
            if(matrix[p][q]==0){

               return true;
            }
        }
    }

        for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
                if(j<3){
            if(matrix[i][j]==matrix[i][j+1]){

                   return true;
                    }
                }
            }
        }
        for(int j=0;j<4;j++){

        for(int i=0;i<4;i++){

            if(i<3){

                if(matrix[i][j]==matrix[i+1][j]){
                  return true;
                }
        }
        }
        }
        for(int i=3;i>-1;i--){

        for(int j=3;j>-1;j--){
                if(j>0){
            if(matrix[i][j]==matrix[i][j-1] ){
                   return true;
                    }
                }
            }
        }

        for(int j=3;j>-1;j--){

        for(int i=3;i>-1;i--){
                if(i>0){
            if(matrix[i][j]==matrix[i-1][j]){
                    return true;
                    }
                }
            }
        }
        return false;
}


