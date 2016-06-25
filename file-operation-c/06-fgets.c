#include <stdio.h>

#define LENGTH		1024

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
	char sz_string[LENGTH] = {'\0'};

	//判断参数个数
	if (argc < 2)
	{
		printf("请输入文件名!\n");
		return 1;
	}
	
	//打开流
	fp = fopen(argv[1], "rb");
	if (NULL == fp)
	{
		printf("打开文件失败!\n");
		return 1;
	}

	//一个字节为单位循环读取文件内容	
	while (!feof(fp))
	{
		if (fgets(sz_string, LENGTH, fp) != NULL)
		{
			printf("%s", sz_string);
		}
	}
	putchar('\n');

	//关闭文件
	fclose(fp);

	return 0;
}
