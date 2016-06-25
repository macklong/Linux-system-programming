#include <stdio.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
	int n_temp = 0;

	printf("argc = %d\n", argc);
	for(n_temp = 0; n_temp < argc; ++n_temp)
	{
		printf("argv[%d] = %s\n", n_temp, argv[n_temp]);
	}

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
		n_temp = fgetc(fp);
		if (n_temp != EOF)
		{
			putchar(n_temp);
		}
	}
	putchar('\n');

	//关闭文件
	fclose(fp);

	return 0;
}
