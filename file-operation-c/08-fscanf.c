#include <stdio.h>

int main(int argc, char* argv[])
{
	//文件结构体指针
	FILE* fp = NULL;
	int n_temp = 0;
	char sz_string[10] = {'\0'};
	char ch_temp = '\0';
	
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

	//从文件流中按格式读
	fscanf(fp, "%s\t%d\t%c", sz_string, &n_temp, &ch_temp);

	printf("%s,%d,%c\n", sz_string, n_temp, ch_temp);

	//关闭文件
	fclose(fp);

	return 0;
}
