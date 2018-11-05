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
		printf("%d��° ����� �̸� �Է�(ex - ������) >> ", i + 1);
		scanf("%s", people[i].name);
		printf("%d��° ����� �¾ ����(ex - 1999) �Է� >> ", i + 1);
		scanf("%d", &people[i].birthday.year);
		printf("%d��° ����� �¾ �� �Է�(ex - 1) >> ", i + 1);
		scanf("%d", &people[i].birthday.month);
		printf("%d��° ����� �¾ �� �Է�(ex - 1) >> ", i + 1);
		scanf("%d", &people[i].birthday.day);
		printf("%d��° ����� ����(ex - ����) �Է� >> ", i + 1);
		scanf("%s", people[i].gender);
		printf("%d��° ����� �ּ�(ex - ����Ư���� ���۱� �漮��) �Է� >> ", i + 1);
		scanf("%s", people[i].address);
		printf("%d��° ����� ��ȭ��ȣ �� 3�ڸ�(ex - 010) �Է� >> ", i + 1);
		scanf("%s", people[i].phoneNumber.first);
		printf("%d��° ����� ��ȭ��ȣ �߰� 4�ڸ�(ex - 1234) �Է� >> ", i + 1);
		scanf("%s", people[i].phoneNumber.second);
		printf("%d��° ����� ��ȭ��ȣ �� 4�ڸ�(ex - 5678) �Է� >> ", i + 1);
		scanf("%s", people[i].phoneNumber.third);
	}
}

void printPersonArray(struct person * people) {
	printf("%s%16s%15s%9s%36s\n", "�̸�", "�������", "����", "�ּ�", "��ȭ��ȣ");
	for (int i = 0; i < 7; i++) {
		printf("%s%10d��%d��%d��%10s%30s%10s-%s-%s\n", people[i].name, people[i].birthday.year, people[i].birthday.month, people[i].birthday.day, people[i].gender, people[i].address, people[i].phoneNumber.first, people[i].phoneNumber.second, people[i].phoneNumber.third);
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