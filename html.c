#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#pragma warning(disable:4996)

void main() {	
	_wsetlocale(LC_ALL, L"korean");

	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);

	int year = t->tm_year + 1900;
	int month = t->tm_mon + 1;
	int day = t->tm_mday;  
	int hour = t->tm_hour; 
	int min = t->tm_min; 
	int sec = t->tm_sec; 

	// �� 12�ڸ�
	char time[27] = "sample_";
	char yTime[5];
	char mTime[3];
	char dTime[3];
	char hTime[3];
	char nTime[3];
	char sTime[3];

	// ���� ��ȯ
	itoa(year, yTime, 10);
	itoa(month, mTime, 10);
	itoa(day, dTime, 10);
	itoa(hour, hTime, 10);
	itoa(min, nTime, 10);
	itoa(sec, sTime, 10);

	// �������� ���ڿ� ����
	char* sFileName;
	sFileName = strcat(time, yTime);
	sFileName = strcat(sFileName, mTime);
	sFileName = strcat(sFileName, dTime);
	sFileName = strcat(sFileName, hTime);
	sFileName = strcat(sFileName, nTime);
	sFileName = strcat(sFileName, sTime);
	sFileName = strcat(sFileName, ".html");
	
	// ���� ���� ��������
	printf("���� ���� �ٿ��ֱ� �� �� ENTER Ű�� �����ּ���.\n");
	printf("eDM ���� : ");
	char body[5000];
	gets_s(body, 5000);
	
	// HTML 
	char htmlStart[7000] = "<!DOCTYPE html>\
		<html>\
		<head>\
		<meta charset=\"utf-8\">\
		<title>SAMPLE</title>\
		</head>\
		<body>";
	char htmlEnd[15] = "</body></html>";
	char* html;
	html = strcat(htmlStart, body);
	html = strcat(html, htmlEnd);
	
	char ch;
	FILE *fp, *rfp;
	fp = fopen(sFileName, "w");
	//fp = fopen_s(&fp, sFileName, "wt+,ccs=UTF-8");

	if (fp == NULL) 
	{
		printf("���� ���� ����");
	}
	else
	{
		printf("%s", "��ȯ�Ϸ�\n");
	}
	setlocale(LC_ALL, ".utf8");

	fputs(html, fp);
	fclose(fp);
}