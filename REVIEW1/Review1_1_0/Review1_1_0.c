#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
void print_reverse(char *str, int end) 
{
	int i, j, temp = 0;

	for (i = 0; i < end / 2; i++) {
		temp = str[i];
		str[i] = str[end - i];
		str[end - i] = temp;
	}
	/*
	if(end < 0)
		return;
	printf("%c", str[end]);
	print_reverse(str, end-1);  // end-- => 무한반복(기존값 전달됨)
	                            // --end OK(자기자신 먼저 감소 후 전달됨)
	*/

	printf("%s\n", str);
} 
int main()
{
	char str[100]; 

	printf("Enter any string:"); 
	scanf("%s", str); 

	printf("Reversed String is: "); 
	print_reverse(str, strlen(str) - 1); // str과 마지막 인덱스를 매개변수로 
	return 0; 
}