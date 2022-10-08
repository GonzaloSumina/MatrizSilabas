#include <iostream>
#include <time.h>
int main(){
	srand(time(NULL));
	char matriz[10][10];
	int matriz_[10][10];
	char vocales_min[]={'a','e','i','o','u'};
	char vocales_may[]={'A','E','I','O','U'};
	char random_min, random_may;
	int variable;
	int cont=0;
	int x=0, y=0;
	std::system("cls");

	for (int i=0;i<10; ++i){
		for (int j=0; j<10; ++j){
			variable=rand()%2;
			random_may=rand()%25+65;
			random_min=rand()%25+97;
			if (variable==0){
				matriz[i][j]=random_may;
				for (int x_=0; x_<5; ++x_){
					if (random_may==vocales_may[x_]){
						matriz_[i][j]=1;
						++cont;
						break;
					}
					else{
						matriz_[i][j]=0;
					}
				}
			}
			else if (variable==1){
				matriz[i][j]=random_min;
				for (int x_=0; x_<5; ++x_){
					if (random_min==vocales_min[x_]){
						matriz_[i][j]=1;
						++cont;
						break;
					}
					else{
						matriz_[i][j]=0;
					}
				}
			}
		}
	}
	int coord[cont][4];
	for (int i=0;i<10; ++i){
		for (int j=0; j<10; ++j){
			if (matriz_[i][j]==1){
				if (i>0 && i<9 && j>0 && j<9){
					if (matriz_[i-1][j-1]==0){
						coord[x][0]=i-1;
						coord[x][1]=j-1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i-1][j-1]=2;
						++x;
						continue;
					}
					else if (matriz_[i-1][j]==0){
						coord[x][0]=i-1;
						coord[x][1]=j;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i-1][j]=2;
						++x;
						continue;
					}
					else if (matriz_[i-1][j+1]==0){
						coord[x][0]=i-1;
						coord[x][1]=j+1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i-1][j+1]=2;
						++x;
						continue;
					}
					else if (matriz_[i][j+1]==0){
						coord[x][0]=i;
						coord[x][1]=j+1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i][j+1]=2;
						++x;
						continue;
					}
					else if (matriz_[i+1][j+1]==0){
						coord[x][0]=i+1;
						coord[x][1]=j+1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i+1][j+1]=2;
						++x;
						continue;
					}
					else if (matriz_[i+1][j]==0){
						coord[x][0]=i+1;
						coord[x][1]=j;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i+1][j]=2;
						++x;
						continue;
					}
					else if (matriz_[i+1][j-1]==0){
						coord[x][0]=i+1;
						coord[x][1]=j-1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i+1][j-1]=2;
						++x;
						continue;
					}
					else if (matriz_[i][j-1]==0){
						coord[x][0]=i;
						coord[x][1]=j-1;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i-1][j]=2;
						++x;
						continue;
					}
					else{
						coord[x][0]=i;
						coord[x][1]=j;
						coord[x][2]=i;
						coord[x][3]=j;
						matriz_[i][j]=2;
						++x;
						continue;
					}
				}
				else if ((i==0 && j==0)||(i==9 && j==0)||(i==0 && j==9)||(i==9 && j==9)){
					if (i==0 && j==0){
						if (matriz_[i][j+1]==0){
							coord[x][0]=i;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j+1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j]==0){
							coord[x][0]=i+1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j]=2;
							++x;
							continue;
						}
					}
					else if (i==9 && j==0){
						if (matriz_[i-1][j]==0){
							coord[x][0]=i-1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j+1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j+1]==0){
							coord[x][0]=i;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i][j+1]=2;
							++x;
							continue;
						}
					}
					else if (i==0 && j==9){
						if (matriz_[i+1][j]==0){
							coord[x][0]=i+1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j-1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j-1]==0){
							coord[x][0]=i;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
					}
					else if (i==9 && j==9){
						if (matriz_[i-1][j-1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j]==0){
							coord[x][0]=i-1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j-1]==0){
							coord[x][0]=i;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
					}
				}
				else if ((i>0 && i<9 && j==0)||(j>0 && j<9 && i==0)||(i>0 && i<9 && j==9)||(j>0 && j<9 && i==9)){
					if (i>0 && i<9 && j==0){
						if (matriz_[i-1][j]==0){
							coord[x][0]=i-1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j+1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j+1]==0){
							coord[x][0]=i;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j+1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j]==0){
							coord[x][0]=i+1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j]=2;
							++x;
							continue;
						}
					}
					else if (j>0 && j<9 && i==0){
						if (matriz_[i][j+1]==0){
							coord[x][0]=i;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j+1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j]==0){
							coord[x][0]=i+1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j-1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j-1]==0){
							coord[x][0]=i;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
					}
					else if (i>0 && i<9 && j==9){
						if (matriz_[i-1][j-1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j]==0){
							coord[x][0]=i-1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j]==0){
							coord[x][0]=i+1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i+1][j-1]==0){
							coord[x][0]=i+1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i+1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j-1]==0){
							coord[x][0]=i;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
					}
					else if (j>0 && j<9 && i==9){
						if (matriz_[i-1][j-1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j-1]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j]==0){
							coord[x][0]=i-1;
							coord[x][1]=j;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
						else if (matriz_[i-1][j+1]==0){
							coord[x][0]=i-1;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j+1]==0){
							coord[x][0]=i;
							coord[x][1]=j+1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i][j+1]=2;
							++x;
							continue;
						}
						else if (matriz_[i][j-1]==0){
							coord[x][0]=i;
							coord[x][1]=j-1;
							coord[x][2]=i;
							coord[x][3]=j;
							matriz_[i-1][j]=2;
							++x;
							continue;
						}
					}
				}
			}
			else{
				continue;
			}
		}
	}

	for (int i=0;i<10; ++i){
		std::cout<<"[ ";
		for (int j=0; j<10; ++j){
			if (matriz_[i][j]==2 || matriz_[i][j]==1){
				std::cout<<"\x1B[1;35;41m";	
				std::cout << matriz[i][j] << "\x1B[0m \t"; 
			}
			else{
				std::cout<<matriz[i][j]<<"\t";
			}
		}
		std::cout<<"] \n";
	}

	return 0;
}
