#include <stdio.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;

	//判断参数个数
	if (argc < 2)
	{
		printf("请输入文件名!\n");
		return 1;
	}
	
	//打开流
	fp = fopen(argv[1], "wb");
	if (NULL == fp)
	{
		printf("打开文件失败!\n");
		return 1;
	}

	//写字符到文件中
	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);

	//关闭文件
	fclose(fp);

	return 0;
}
