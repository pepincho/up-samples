#include <iostream>
#include <malloc.h>

int main()
{
	// �������� � ������������� �� ����� � malloc/free
	int *pArr1 = (int*)malloc(10 * sizeof(int));

	if (pArr1)
		std::cout << pArr1[0] << std::endl;
	else
		std::cerr << "Allocation failed! (errno " << errno << ")\n";

	free(pArr1);


	// �������� � ������������� �� ����� � calloc/free
	// ������� �� ������
	int *pArr2 = (int*)calloc(10, sizeof(int));

	if (pArr2)
		std::cout << pArr2[0] << std::endl;
	else
		std::cerr << "Allocation failed! (errno " << errno << ")\n";

	free(pArr2);


	// ��������������� � realloc
	int *p = (int*) malloc(0);

	int *q = (int*) realloc(p, 10 * sizeof(int)); // ����������

	if (q != NULL)
	{
		// ��� ����������������� � ���� �������, q ���� ��� ����� �����
		// ������ �� ������� p, ������ ��� ���� �� �� ������ �� ���� ����� � �������.
		p = q;
	}
	else
	{
		// ��� ��������� ����� NULL, ����������������� �� � ���� �������,
		// �� ������� ���������� � � ����� ��������� � p ��� ��� ���� ��� ����.
		std::cerr << "Reallocation failed! (errno " << errno << ")\n";
		
		// ��������� �� ��������...
	}

	realloc(p, 2 * sizeof(int)); // ���������

	free(p);

	return 0;
}