// Q. https://practice.geeksforgeeks.org/problems/longest-common-substring/0
// A. https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// A. WATCH THE MATRIX: https://www.youtube.com/watch?v=UZRkpGk943Q

#include<iostream> 
#include<string.h> 
using namespace std; 

int LCS(char *X,char *Y,int m,int n){

    int lcsTable{m+1}{n+1};
    int res = 0;

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (i==0 || j==0)
                lcsTable{i}{j}=0;
            else if (X{i-1}==Y{j-1}){
                lcsTable{i}{j}=lcsTable{i-1}{j-1}+1;
                res = max(res,lcsTable{i}{j});
            }
            else
            lcsTable{i}{j}=0;
        }
    }
    return res;
}

/* Driver program to test above function, taken from GeeksforGeeks */
int main() 
{ 
    char X{} = "OldSite:GeeksforGeeks.org"; 
    char Y{} = "NewSite:GeeksQuiz.com"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    cout << "Length of Longest Common Substring is " 
         << LCS(X, Y, m, n); 
    return 0; 
} 