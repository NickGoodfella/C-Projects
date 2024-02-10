#include <stdio.h>


#include <stdlib.h>

#define SIZE_OF_NAMES 25


struct employee
{
	int idNum;
	char* firstName;
	char* lastName;
	short age;
	int salary;
};

void fillOutEmployeeInfo(struct employee* employee, int* numEmployees)
{
	static int idNum = 1;

	for(int i = 0; i < *numEmployees; i++)
	{
		printf("Enter The Employee's First Name, Last Name, Age and Salary\n");
		scanf(" %s", employee[i].firstName); 
		scanf("%s", employee[i].lastName);
		scanf("%hd", &employee[i].age);
		scanf("%d", &employee[i].salary);	
		employee[i].idNum = idNum;
		idNum++;
	}
};

int main()
{
	int n = 2;

	struct employee * emp = malloc(sizeof(struct employee) * n);
	
	// lets allocate memory on the heap for our employee first and lastname
	for(int i = 0; i < n; i++)
	{
		emp[i].firstName = malloc(SIZE_OF_NAMES);
		emp[i].lastName = malloc(SIZE_OF_NAMES);

		if(emp[i].firstName == NULL || emp[i].lastName == NULL)
		{
			printf("The allocator failed\n");
		}
	}
	
	
	if(emp == NULL )
	{
		printf("The allocator failed\n");
		return -1;
	}
		
	fillOutEmployeeInfo(emp, &n);

	for(int i = 0; i < n; i++)
	{
		printf("Employee ID = %d\n Employee First Name = %s\n Employee Last Name = %s\n Employee Age = %hd\n Employee Salary = %d\n", emp[i].idNum, emp[i].firstName, emp[i].lastName, emp[i].age, emp[i].salary);
		free(emp[i].firstName);
		free(emp[i].lastName);
		emp[i].firstName = NULL;
		emp[i].lastName = NULL;
	}

	free(emp);
	emp = NULL;
	return 0;
}
