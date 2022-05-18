#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {
	int ch, count = 1;
	FILE* fp;
	if ((fp = fopen(argv[2], "r")) == NULL) {
		printf("文件 %s 打开失败，请检查文件名是否输入正确！", argv[2]);
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C") == 0) {
		count = 0;
		while ((ch = getc(fp)) != EOF) {
			count++;
		}
		printf("字符数 共计%d个\n", count);
	}
	else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-W") == 0) {
		while ((ch = getc(fp)) != EOF) {
			if ((ch == ' ') || (ch == ',')) {
				count++;
			}
		}
		printf("单词数 共计%d个\n", count);
	}
	else {
		printf("请输入有效的命令！");
	}
	fclose(fp);
	return 0;
}