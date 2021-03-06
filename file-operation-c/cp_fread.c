#include <stdio.h>

#define LENGTH		1024

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp_from = NULL;
	FILE* fp_to = NULL;
	size_t n_temp = 0;
	char sz_temp[LENGTH] = {'\0'};

	//判断参数个数
	if (argc < 3)
	{
		printf("请输入文件名!\n");
		return 1;
	}
	
	//打开流
	fp_from = fopen(argv[1], "rb");
	if (NULL == fp_from)
	{
		printf("打开文件失败!\n");
		return 1;
	}
	fp_to = fopen(argv[2], "wb");
	if (NULL == fp_to)
	{
		printf("打开文件失败!\n");
		return 1;
	}

	//一个字节为单位循环读取文件内容	
	while (!feof(fp_from))
	{
		n_temp = fread(sz_temp, sizeof(char), LENGTH, fp_from);

		fwrite(sz_temp, sizeof(char), n_temp, fp_to);
	}

	//关闭文件
	fclose(fp_from);
	fclose(fp_to);	

	return 0;
}
