#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
void reverse_string(char* str, int s, int e)
{
	char temp = 0;

	if (s < e)
	{
		temp = str[s];
		str[s] = str[e];
		str[e] = temp;
		reverse_string(str, s + 1, e - 1);
	}
	/*
	char c;
	if(s < e){
		c = str[s];
		str[s] = str[e];
		str[e] = c;
		reverse_string(str, s + 1, e - 1);
	}
	return;
	*/
	/* ¹Ýº¹¹®
	char temp;
	int i, j =e;
	for( ; s<= e; e--){
		temp = str[i];
		str[i] = str[j];
		str[j--] = temp;
		}
	*/
}

int main(void)
{
	char str[100]; 

	printf("Enter any string:"); 
	scanf("%s", str); 

	reverse_string(str, 0, strlen(str) - 1); 
	printf("\nReversed String is: %s", str); 
	
	return 0;
}