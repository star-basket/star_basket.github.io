#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 26

int hang(char ans[]);

int main(){

  char conte = '\0';
    while(conte != 'n'){
  conte = '\0';
  char ans[20]; 
  hang(ans);
  int arraysize = 0;
  arraysize = strlen(ans);

  char re_ans[arraysize];
  for(int i=0;i<=arraysize;i++){
    re_ans[i] = '-';
    if(i==arraysize){
      re_ans[i] = '\0';
      break;
    }
  }

  char str[MAX]={'\0'};
  char key = '\0';
  int count = 0;
  int flag = 0;
  int corect = 0;
  
  for(int limit = 7;limit>0;limit--){
   flag = 0;

    printf("�P��:%s\n",re_ans);
    printf("�g��ꂽ����:%s\n",str);
    printf("�c���:%d\n",limit);
    printf("��������͂��Ă�������:");
    key =  getchar();
    rewind(stdin);
    printf("%c\n",key);

    for(int i=0;i<arraysize;i++){
      if(ans[i]==key){
	re_ans[i] = key;
    if(flag == 0){
    flag = 1;
    limit++;
    }
      }
    }

    int j=0;
    //�d�Ȃ蔻��
    for(j=0;j<count;j++){
    if(str[j] == key){
	printf("���̕����͎g���Ă��܂�\n");
  limit++;
     if(flag==1){
        limit--;
    }
	break;
      }
    }
    if(j == count){
    str[count] = key;
    count++;
    }
     if(strcmp(ans,re_ans)==0){
        limit = 0;
    printf("�����ł�\n�����܂���? Y/N\n");
    conte = getchar();
    rewind(stdin);
   }
  }
  if(conte=='\0'){
  printf("�c�O�@������ %s �ł���\n",ans);
  printf("�����܂���? Y/N\n");
    conte = getchar();
    rewind(stdin);
  }
    }
  return 0;   
}

int hang(char ans[]){
  char line[20];
  FILE *fp;
  fp = fopen("words","r");
  
  srand((unsigned)time(NULL));

  while(1){
    int num = rand() % 235881 + 1;
  for(int i=0;i<num;i++){
    if (fgets(line, sizeof(line), fp) == NULL) {
      printf("�t�@�C���̓ǂݍ��݂Ɏ��s���܂���");
      fclose(fp);
      return 1;
    }
  }
  int l_count = 0;
  l_count = strlen(line);
  if(l_count > 6){
    break;
  }
  }
  int dan;
  dan = line[0] - 'A';
  if(dan < 26){
    dan = dan + 'a';
    line[0] = dan;
  }
  char *temp = strchr(line, '\n');
    if(temp != NULL) {
        *temp = '\0';
    }
    strcpy(ans,line);
    fclose(fp);

    return 0;
}