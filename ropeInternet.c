#include<stdio.h>

int readinput(int A[], int B[]){
	int i = 0, N;
	scanf("%d", &N);
	for(;i < N; i++)
		scanf("%d%d", &A[i], &B[i]);
	return N;
}

void sort(int N, int A[], int B[]){
	int i , j, temp;
	for(i = N - 1; i > 0; i--)
		for(j = 0; j < i; j++)
			if(A[j] > A[j + 1]){
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
}


int findinversion(int N, int B[]){
	int count = 0, i, j;
	for(i = 0; i < N - 1; i++)
		for(j = i + 1; j < N; j++)
			if(B[i] > B[j])
				count++;
	return count;
}

int main(){
	int T, N, i = 0;
	int A[1000], B[1000];
	char output[1000][100];
	scanf("%d", &T);
	for(; i < T; i++){
		N = readinput(A, B);
		sort(N, A, B);
		sprintf(output[i], "Case #%d: %d\n", i + 1, findinversion(N, B));
	}
	for(i = 0; i < T; i++)
		printf("%s", output[i]);
	return 0;
}
