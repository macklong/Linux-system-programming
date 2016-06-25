#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
	int n_temp = 100;
	int arrn_temp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char sz_temp[20] = "Test fwrite!";

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

	//向文件流中写指定个数的字节块
	fwrite(&n_temp, sizeof(int), 1, fp);
	//fwrite(arrn_temp, sizeof(arrn_temp), 1, fp);
	fwrite(arrn_temp, sizeof(int), 10, fp);
	fwrite(sz_temp, sizeof(char), 20, fp);

	//关闭文件
	fclose(fp);

	return 0;
}
