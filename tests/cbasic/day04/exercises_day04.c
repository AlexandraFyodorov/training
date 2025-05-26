#include <stdio.h> /* scanf , printf */
#include <stdlib.h> /* abs */
#include <string.h> /* strlen */

struct person
{
	char name[30];
	int id;
	int age;
	int education;
};

typedef struct complexNumber
{
	int real;
	int img;
}complex;

struct book
{
	char author[30];
	int year;
	char* publications;
	char* text;
};


int ArrayAllocate(int size)
{
	int i;
	int *arr = (int*)malloc(sizeof(int) * size);
    

    if (arr == NULL)
    {
        printf("Allocation Failed");
        return 0;/* false */
    }
    
    printf("Inpun %d values to array please.\n", size);
    
    for (i = 0; i < size; i++)
    {
    	scanf("%d", &arr[i]);
	}
        
    printf("New array: ");
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ", arr[i]);
	}
	
	free(arr);
	printf("\n");
	return 1; /* true */
}

void Person()
{
	struct person p;
	struct person* p_Ptr = &p;
	
	printf("Enter name:");
	scanf("%s", p.name);
	printf("Enter id:");
	scanf("%d",&p.id);
	printf("Enter age:");
	scanf("%d",&p.age);
	printf("Enter education:");
	scanf("%d",&p.education);
	
	printf("\nPerson data:\n");
	
	printf("\n name: %s\n id: %d\n age: %d\n education: %d\n",p_Ptr->name, p_Ptr->id, p_Ptr->age, p_Ptr->education);
}

char* MyStr(const char* src)
{
	int length = strlen(src);
	char* cpy_src = (char*)malloc(sizeof(char) * length);
	char* tmp = cpy_src;
	
	while(*src != '\0')
	{
		*tmp = *src;
		tmp++;
		src++;
	}
	
	return cpy_src;
}

complex AddComplexNumber(complex a, complex b)
{
	complex add;

    add.real = a.real + b.real;
    add.img = a.img + b.img;

    return add;
}

complex MultiComplexNumber(complex a, complex b)
{
	complex multi;
	int prod1 = a.real * b.real;
    int prod2 = a.img * b.img;
    int prod3 = a.real * b.real + a.real * b.img + a.img * b.img + a.img * b.real;

    // Real Part
    multi.real = prod1 - prod2;

    // Imaginary Part
    multi.img = prod3 - (prod1 + prod2);
    
    /*
		=> (a + bi)*(c + di) 
		=> a(c + di) + b*i(c + di) 
		=> a*c + ad*i + b*c*i + b*d*i*i 
		=> (a*c - b*d) + (a*d + b*c)*i   
    */
    return multi;
}

int main()
{
	complex a, b, sum, multi;
	//const char* src = "Hello Luna";
	
	//Person();
	/*ArrayAllocate(6);
	printf("New string: %s\n", MyStr(src));
	*/
	
	printf("Enter first complex number:\n");
	printf("real = ");
	scanf("%d",&a.real);
	printf("imaginary = ");
	scanf("%d",&a.img);
	printf("Enter second complex number:\n");
	printf("real = ");
	scanf("%d",&b.real);
	printf("imaginary = ");
	scanf("%d",&b.img);
	
	sum = AddComplexNumber(a,b);
	printf("sum = %d + %di\n", sum.real, sum.img);
	
	multi = MultiComplexNumber(a,b);
	printf("multi = %d + %di\n", multi.real, multi.img);
	return 0;	
}
