#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
	int loop = 0;
	int n_temp = 0;
	int arrn_temp[10] = {0};
	char sz_temp[20] = "";

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

	//从文件流中读取指定个数的字节
	fread(&n_temp, sizeof(int), 1, fp);
	//fread(arrn_temp, sizeof(arrn_temp), 1, fp);
	fread(arrn_temp, sizeof(int), 10, fp);
	fread(sz_temp, sizeof(char), 20, fp);

	printf("%d %s\n", n_temp, sz_temp);
	for(loop = 0; loop < 10; loop++)
	{
		printf("%d ", arrn_temp[loop]);
	}
	printf("\n");
	
	//关闭文件
	fclose(fp);

	return 0;
}
