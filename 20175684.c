#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct birthday {
	int year;
	int month;
	int day;
};

struct phoneNumber {
	char first[4];
	char second[5];
	char third[5];
};

struct person {
	char name[20];
	struct birthday birthday;
	char gender[5];
	char address[30];
	struct phoneNumber phoneNumber;
};

void getInfo(struct person * people);
void printPersonArray(struct person * people);
void sortByName(struct person * people);
void sortByBirthday(struct person * people);

int main() {
	struct person people[10];
	getInfo(people);

	
	printPersonArray(people);
	printf("\n");

	sortByName(people);
	printPersonArray(people);
	printf("\n");

	sortByBirthday(people);
	printPersonArray(people);

	return 0;
}

void getInfo(struct person * people) {
	for (int i = 0; i < 7; i++) {
		printf("%d번째 사람의 이름 입력(ex - 옥재현) >> ", i + 1);
		scanf("%s", people[i].name);
		printf("%d번째 사람이 태어난 연도(ex - 1999) 입력 >> ", i + 1);
		scanf("%d", &people[i].birthday.year);
		printf("%d번째 사람이 태어난 달 입력(ex - 1) >> ", i + 1);
		scanf("%d", &people[i].birthday.month);
		printf("%d번째 사람이 태어난 일 입력(ex - 1) >> ", i + 1);
		scanf("%d", &people[i].birthday.day);
		printf("%d번째 사람의 성별(ex - 남자) 입력 >> ", i + 1);
		scanf("%s", people[i].gender);
		printf("%d번째 사람의 주소(ex - 서울특별시 동작구 흑석동) 입력 >> ", i + 1);
		scanf("%s", people[i].address);
		printf("%d번째 사람의 전화번호 앞 3자리(ex - 010) 입력 >> ", i + 1);
		scanf("%s", people[i].phoneNumber.first);
		printf("%d번째 사람의 전화번호 중간 4자리(ex - 1234) 입력 >> ", i + 1);
		scanf("%s", people[i].phoneNumber.second);
		printf("%d번째 사람의 전화번호 뒤 4자리(ex - 5678) 입력 >> ", i + 1);
		scanf("%s", people[i].phoneNumber.third);
	}
}

void printPersonArray(struct person * people) {
	printf("%s%16s%15s%9s%36s\n", "이름", "생년월일", "성별", "주소", "전화번호");
	for (int i = 0; i < 7; i++) {
		printf("%s%10d년%d월%d일%10s%30s%10s-%s-%s\n", people[i].name, people[i].birthday.year, people[i].birthday.month, people[i].birthday.day, people[i].gender, people[i].address, people[i].phoneNumber.first, people[i].phoneNumber.second, people[i].phoneNumber.third);
	}
}

void sortByName(struct person * people) {
	for (int i = 0; i < 6; i++) {
		if (strcmp(people[i].name, people[i + 1].name) > 0) {
			struct person temp;
			temp = people[i];
			people[i] = people[i + 1];
			people[i + 1] = temp;
			i = 0;
		}
	}
}

void sortByBirthday(struct person * people) {
	for (int i = 0; i < 6; i++) {
		if (people[i].birthday.year > people[i + 1].birthday.year) {
			struct person temp;
			temp = people[i];
			people[i] = people[i + 1];
			people[i + 1] = temp;
			i = 0;
		}
		else if (people[i].birthday.year == people[i + 1].birthday.year) {
			if (people[i].birthday.month > people[i + 1].birthday.month) {
				struct person temp;
				temp = people[i];
				people[i] = people[i + 1];
				people[i + 1] = temp;
				i = 0;
			}
			else if (people[i].birthday.month == people[i + 1].birthday.month) {
				if (people[i].birthday.day > people[i + 1].birthday.day) {
					struct person temp;
					temp = people[i];
					people[i] = people[i + 1];
					people[i + 1] = temp;
					i = 0;
				}
			}
		}
	}
}