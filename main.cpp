#include <iostream>
#include <time.h>
int main(){
	srand(time(NULL));
	char matriz[10][10];
	int matriz_[10][10];
	char vocales_min[]={'a','e','i','o','u'};
	//char consonantes_min[]={'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l','m','n','p','q','r','s','t','v','w','x','y','z'};
	char vocales_may[]={'A','E','I','O','U'};
	//char consonantes_may[]={'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
	char random_min, random_may;
	int variable;
	int cont=0;
	int x=0, y=0;

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
				else if ((i==0 && j==0)||(i==9 && j==0))
			}
			else{
				continue;
			}
		}
	}

	for (int i=0;i<10; ++i){
		std::cout<<"[ ";
		for (int j=0; j<10; ++j){
			std::cout<<matriz[i][j]<<"\t";
		}
		std::cout<<"] \n";
	}

	for (int i=0;i<10; ++i){
		std::cout<<"[ ";
		for (int j=0; j<10; ++j){
			std::cout<<matriz_[i][j]<<"\t";
		}
		std::cout<<"] \n";
	}
	for (int i=0;i<cont; ++i){
		std::cout<<"[ ";
		for (int j=0; j<4; ++j){
			std::cout<<coord[i][j]<<"\t";
		}
		std::cout<<"] \n";
	}

	return 0;
}
