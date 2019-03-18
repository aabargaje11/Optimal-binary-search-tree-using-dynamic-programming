#include<iostream>
#include<bits/stdc++.h> 
#include <iomanip>
using namespace std;

struct format{
	int w;
	int c;
	int r;

};

struct format table[15][15];
int p[]={0, 3, 3, 1, 1}, q[]={2, 3, 1, 1, 1};
string binary_tree[10], word[]={"do", "if", "int", "while"};


int get_weight(int i, int j){
	return p[j] + q[j] + table[i][j-1].w;
} // end of get_weight


void get_tree(int i, int j, int index){
	
	int root;
	if((j-i)>0){

		root = table[i][j].r;
		binary_tree[index] = word[root-1];

		get_tree(i,root-1, 2*index);
		get_tree(root,j, 2*index+1);
	}
	else{
		binary_tree[index] = "---";
		
	}

}

void prerequisites_table(int length){

	for(int i=0; i<=length; i++){
		table[i][i].w = q[i];
		table[i][i].r = 0;
		table[i][i].c = 0;
	}
} // end of pre-requisites_table



int main(){

	// Step 1 : Set table for further operations.
	prerequisites_table(4);

	for(int count=1; count<=4; count++){
		int i = 0;
		int j = i + count;
		
		while( j <= 4){
			
			table[i][j].w = get_weight(i,j);	
			
			//int* ptr = get_cost(i,j);
			// calculating cost
			int k_val = 0, min = 1000;
			
			for(int k=i+1 ; k<=j ; k++){
				int val = table[i][k-1].c + table[k][j].c ;
				
				if(val < min){
					min = val;
					k_val = k;	
				}
			} // k for loop 




			table[i][j].c = table[i][j].w + min;
			table[i][j].r = k_val;
			
			i++;
			j++;

		} // end of while loop


	
	} // end of for loop



	//Print output format w,c,r


	for(int i=0;i<=4;i++){
		for(int j=0;j<=4;j++){
			cout<<setw(5)<<table[i][j].w<<","<<table[i][j].c<<","<<table[i][j].r<<"     ";
		}
		cout<<endl;
	}

	// print binary tree

	get_tree(0,4,1);
	for(int i=1;i<=7;i++){
		cout<<"location :"<<i<<"  "<<binary_tree[i]<<" "<<endl;
	}


	return 0;
}
