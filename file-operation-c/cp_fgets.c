#include <stdio.h>

#define LENGTH		1024

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp_from = NULL;
	FILE* fp_to = NULL;
	int n_temp = 0;
	char sz_string[LENGTH] = {'\0'};

	//判断参数个数
	if (argc < 3)
	{
		printf("请输入文件名!\n");
		return 1;
	}
	
	//打开流
	fp_from = fopen(argv[1], "rb");
	fp_to = fopen(argv[2], "wb");
	if (NULL == fp_from || NULL == fp_to)
	{
		printf("打开文件失败!\n");
		return 1;
	}

	//一个字节为单位循环读取文件内容	
	while (!feof(fp_from))
	{
		if (fgets(sz_string, LENGTH, fp_from) != NULL)
		{
			fputs(sz_string, fp_to);
		}
	}

	//关闭文件
	fclose(fp_from);
	fclose(fp_to);

	return 0;
}
