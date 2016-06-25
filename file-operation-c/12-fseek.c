#include <stdio.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
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

	
	//写字符到文件中
	fseek(fp, -12, SEEK_END);
//	fread(&n_temp, sizeof(int), 1, fp);
	//fwrite(arrn_temp, sizeof(arrn_temp), 1, fp);
//	fread(arrn_temp, sizeof(int), 10, fp);
	fread(sz_temp, sizeof(char), 20, fp);

	printf("%s\n", sz_temp);
	
	//关闭文件
	fclose(fp);

	return 0;
}
