// hansan.c (�ѻ� ����)
#include <stdio.h>

#define CMD_RELOAD		0x01 // Bit 0 - ���� �غ�	0000 0001
#define CMD_FIRE		0x02 // Bit 1 - ���� ���	0000 0010
#define CMD_CHARGE		0x04 // Bit 2 - ���� ����	0000 0100
#define CMD_HOLD		0x08 // Bit 3 - ���� �غ�	0000 1000
#define CMD_CRANE_FORM	0x10 // Bit 4 - ������ ����	0001 0000
#define CMD_EVAC		0x20 // Bit 5 - �λ� �ļ�	0010 0000
#define CMD_DAMAGE		0x40 // Bit 6 - ���� ���	0100 0000
#define CMD_CHASE		0x80 // Bit 7 - �߰� ����	1000 0000


// Toggle ��� ON
unsigned char CommandOn(unsigned char fleet, unsigned char bit) {
	if (bit < 8)
		fleet |= (0x01 << bit);
	return fleet;
}

// Toggle ��� OFF
unsigned char CommandOff(unsigned char fleet, unsigned char bit) {
	if (bit < 8)
		fleet &= ~(0x01 << bit);
	return fleet;
}

// ���� ǥ��
void showStatus(unsigned char fleet) {
	printf("\n[���� �Լ� ����] HEX: %02X | BIN: ", fleet);
	for (int i = 8; i >= 0; i--) {
		printf("%d", (fleet >> i) & 1);
	}
	printf("\n");

	if (fleet & CMD_RELOAD)		printf("���� �غ� �Ϸ�\n");
	if (fleet & CMD_FIRE)		printf("���� ��� Ȱ��\n");
	if (fleet & CMD_CHARGE)		printf("���� ���� ����\n");
	if (fleet & CMD_HOLD)		printf("���� �غ� ��\n");
	if (fleet & CMD_CRANE_FORM)	printf("������ ���� ����\n");
	if (fleet & CMD_EVAC)		printf("�λ� �ļ�\n");
	if (fleet & CMD_DAMAGE)		printf("�Լ� ���� �߻�!\n");
	if (fleet & CMD_CHASE)		printf("�߰� ����!\n");
	if (fleet == 0)				printf("��� �Լ� ��� ����\n");
}

void printMenu(void) {
	printf("\n=== �̼����� �ѻ� ����! ===\n");
	printf("1. Toggle ���� �غ�\n");
	printf("2. Toggle ���� ���\n");
	printf("3. Toggle ���� ����\n");
	printf("4. Toggle ���� �غ�\n");
	printf("5. Toggle ������ ����\n");
	printf("6. Toggle �λ� �ļ�\n");
	printf("7. Toggle ���� ���\n");
	printf("8. Toggle �߰� ����\n");
	printf("9. Reset ALL (�ʱ�ȭ)\n");
	printf("10. Inspection (�ѹ��� ����)\n");
	printf("11. Full Attack Mode (���� ����)\n");
	printf("12. Exit\n");
	printf("��� ���� (1~12): ");
}

int main(void) {
	unsigned char fleet = 0;
	int choice;

	while (1) {
		printMenu(); // ���߿�
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			if (fleet & CMD_RELOAD) {
				fleet = CommandOff(fleet, 0);
				printf("���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 0);
				printf("�� �Լ�, ǥ�� �����϶�!\n");
			}
			break;
		case 2:
			if (fleet & CMD_FIRE) {
				fleet = CommandOff(fleet, 1);
				printf("���� ����! ���� ������!\n");
			}
			else {
				fleet = CommandOn(fleet, 1);
				printf("���� �϶�! ���� ���� ����!\n");
			}
			break;
		case 3:
			if (fleet & CMD_CHARGE) {
				fleet = CommandOff(fleet, 2);
				printf("���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 2);
				printf("�� �Լ� ���� ���� ����!\n");
			}
			break;
		case 4:
			if (fleet & CMD_HOLD) {
				fleet = CommandOff(fleet, 3);
				printf("���� ��� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 3);
				printf("���� �غ�, �� ������ ����!\n");
			}
			break;
		case 5:
			if (fleet & CMD_CRANE_FORM) {
				fleet = CommandOff(fleet, 4);
				printf("������ ���� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 4);
				printf("������ ���� ����!\n");
			}
			break;
		case 6:
			if (fleet & CMD_EVAC) {
				fleet = CommandOff(fleet, 5);
				printf("�λ� �ļ� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 5);
				printf("�λ� �ļ� ����!\n");
			}
			break;
		case 7:
			if (fleet & CMD_DAMAGE) {
				fleet = CommandOff(fleet, 6);
				printf("���� ��� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 6);
				printf("�Լ� ���� �߻� ���!\n");
			}
			break;
		case 8:
			if (fleet & CMD_CHASE) {
				fleet = CommandOff(fleet, 7);
				printf("�߰� ����!\n");
			}
			else {
				fleet = CommandOn(fleet, 7);
				printf("�߰� ����!\n");
			}
			break;
		case 9:
			fleet = 0;
			printf("��� �Լ� ���� �ʱ�ȭ �Ϸ�!\n");
			break;
		case 10:
			printf("�ѹ��� ����: ���� ��� �Լ� ���� Ȯ��!\n");
			break;
		case 11:
			fleet = 0x7F; // ��� ��Ʈ ON
			printf("���� ���� ���! ��� ��� Ȱ��!\n");
			break;
		case 12:
			printf("���α׷� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �Է��Դϴ�! (1~12)����!\n");
		} // switch()

		showStatus(fleet);

	} // while()

	return 0;
}