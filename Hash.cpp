//--------------ͷ�ļ�����---------------// 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std; 




//-----------------��������-------------------//

typedef int Status;
typedef struct
{
	char *elem;  
	int sizeindex;          //��ǰ����
}NameTable[3000];           //һ��ʼ����������

typedef struct
{
	char *elem;    
	int sizeindex;          //���ֵĳ��� 
	int count;           //Ҫ��ѯ�Ĵ���
}HashTable[3400];           //3400��λ�õĹ�ϣ��



//-----------------��������-------------------//

void RandomName();		//�����������
Status CreateName(NameTable &name);      //��������
Status CreateHash(NameTable &name,HashTable &hash);  //������ϣ��
Status SearchHash(char aa[],HashTable &hash);   //��������
Status DishplayHashList(HashTable &hash);    //������ϣ��
void FreeHash(HashTable &hash);       //�ͷŹ�ϣ��



//-----------------�����������-------------------//

void RandomName()
{
	//���������ֵ䣬100�����ϣ�175+235�麺��ƴ��ȫ���
	string name1[100] = {"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","du","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang","lu","wei","ji","shen","fu","du","ran","niu","tong","shou","xiang","gu","yi","shen","ge","liao","zhong","ji","ju","heng","bu","geng","guang","lu","dong","ou","wo","li","shi","gong","ku","nie","zeng","hou","gai","gong","you","duan","si","liang","men","nan","men","she","kuo","ba","qian","bai","li","sheng","qing","pu"};
	string name2[175] = {"a","ai","an","ang","ao","ba","bai","ban","bang","bao","bei","ben","beng","bi","bian","biao","bie","bin","bing","bo","bu","ca","cai","can","cang","cao","ce","cen","ceng","cha","chai","chan","chang","chao","che","chen","cheng","chi","chong","chou","chu","chua","chuai","chuan","chuang","chui","chun","chuo","ci","cong","cou","cu","cuan","cui","cun","cuo","da","dai","dan","dang","dao","de","dei","den","deng","di","dia","dian","diao","die","ding","diu","dong","dou","du","duan","dui","dun","duo","e","en","eng","er","fa","fan","fang","fei","fen","feng","fiao","fo","fou","fu","ga","gai","gan","gang","gao","ge","gei","gen","geng","gong","gou","gu","gua","guai","guan","guang","gui","gun","guo","ha","hai","han","hang","hao","he","hei","hen","heng","hong","hou","hu","hua","huai","huan","huang","hui","hun","huo","ji","jia","jian","jiang","jiao","jie","jin","jing","jiong","jiu","ju","juan","jue","ka","kai","kan","kang","kao","ke","ken","keng","kong","kou","ku","kua","kuai","kuan","kuang","kui","kun","kuo","la","lai","lan","lang","lao","le","lei","leng","li","lia","lian","liang","liao"};
	string name3[235] = {"lie","lin","ling","liu","lo","long","lou","lu","luan","lun","luo","lv","lve","ma","mai","man","mang","mao","me","mei","men","meng","mi","mian","miao","mie","min","ming","miu","mo","mou","mu","na","nai","nan","nang","nao","ne","nei","nen","neng","ni","nian","niang","niao","nie","nin","ning","niu","nong","nou","nu","nuan","nun","nuo","nv","nve","o","ou","pa","pai","pan","pang","pao","pei","pen","peng","pi","pian","piao","pie","pin","ping","po","pou","pu","qi","qia","qian","qiang","qiao","qie","qin","qing","qiong","qiu","qu","quan","que","qun","ran","rang","rao","re","ren","reng","ri","rong","rou","ru","rua","ruan","rui","run","ruo","sa","sai","san","sang","sao","se","sen","seng","sha","shai","shan","shang","shao","she","shei","shen","sheng","shi","shou","shu","shua","shuai","shuan","shuang","shui","shun","shuo","si","song","sou","su","suan","sui","sun","suo","ta","tai","tan","tang","tao","te","tei","teng","ti","tian","tiao","tie","ting","tong","tou","tu","tuan","tui","tun","tuo","wa","wai","wan","wang","wei","wen","weng","wo","wu","xi","xia","xian","xiang","xiao","xie","xin","xing","xiong","xiu","xu","xuan","xue","xun","ya","yan","yang","yao","ye","yi","yin","ying","yo","yong","you","yu","yuan","yue","yun","za","zai","zan","zang","zao","ze","zei","zen","zeng","zha","zhai","zhan","zhang","zhao","zhe","zhei","zhen","zheng","zhi","zhong","zhou","zhu","zhua","zhuai","zhuan","zhuang","zhui","zhun","zhuo","zi","zong","zou","zu","zuan","zui","zun","zuo"};
	srand((unsigned)time(NULL)); //��ʼ�������������
	ofstream ofile;	//�����ĵ���
	ofile.open("d:\\name.txt");	//�½�"name.txt"����������ɵ�����
	printf("��������������������Ժ�......\n");
	//������ɵ�����
	for(int i=0;i<3000;i++)	
	{
		int j=0;
		do	//�ж������ֳ�ҪС��10
		{
			//���ȡ�� 
			int ranName1 = (rand()%99);
			int ranName2 = (rand()%174);
			int ranName3 = (rand()%234);
			string name = name1[ranName1]+name2[ranName2]+name3[ranName3];
			//�������ɵ����ֳ���
			for(j=0;name[j]!='\0';j++);
			if(j<=10)	//��������ֳ�����Ҫ��
				ofile<<name<<endl;	//������д���ļ�
		}while(j>10);	  
	}
	ofile.close(); 
	printf("\n�������������ϣ����Ŀ¼Ϊd:\\name.txt\n");
	printf("--------------------------------------------\n");
}



//-----------------�ӽ������ı��������ȡ����-------------------//

Status CreateName(NameTable &name)
{
	char *f;   
	int i,j;
	for(i=0;i<3000;i++)          //�������֣�����ÿ�����ֵĳ��ȸ�ֵΪ 0�� 
	{  
		name[i].elem = (char*)malloc(11*sizeof(char));  
		name[i].sizeindex=0;
	}
	
	
	//--��ʼ��ȡ���ֵ�ϵͳ��--//
char a[100000];	//����ɶ�ȡ�ַ�����󳤶�
    ifstream ifile;               //���������ļ�
    ifile.open("d:\\name.txt");     //��Ϊ�����ļ���
    i=j=0;
	int m=0 ,flag=0;
	char singleName[11];
    while(ifile.get(a[i]))
	{
		if(a[i]!='\n')
		{
			singleName[j] = a[i];	//����singleName
			j++;
		}
		else
		{
			singleName[j] = '\0';	//����singleName�ַ���
			strcpy(name[flag].elem,singleName);
			for(m=0;singleName[m]!='\0';m++)
				singleName[m] = '\0';	//��һ����singleName
			j=0;
			flag++;
		}
		i++;
		if(flag == 3000) break; //��ȡ3000������
		
    }
	printf("\n");
    ifile.close();
	//--��ʼ��ȡ���--//

	for(i=0;i<3000;i++)          //ͳ��ÿ�����ֵĳ� ��
	{ 
		int s = 0; 
		f = name[i].elem;  
		for(j=0;*(f+j)!='\0';j++) 
		{   
			s = s + 1; 
		} 
		name[i].sizeindex = s; 
	}
	return 0;
}


//------------------��ϣ��1������������������α���̽����ɢ�з������ͻ---------------------//

Status CreateHash1(NameTable &name, HashTable &hash)   //������ϣ��
{
	int i;
	int w=1;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //����ϣ�����ÿһ ��λ�ö���Ϊ��
	{     
		hash[i].elem="��null��";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//==========��������������==========//
	for(i=0;i<3000;i++)         
	{  
		for(j=0;j<name[i].sizeindex;j++)     //��ÿ���������е� ��ĸ������������ ASCII �������� 
		{  
			d += name[i].elem[j];
		} 
		m = d % 3397;           //��ϣ�����������е� ��ĸ���������ܺͳ��� 3337 ȡ�࣬������������ֲ�����  
		if(hash[m].sizeindex == 0)       //��ʼ�����ַ��뵽 ��ϣ����ȥ  
		{ 
			hash[m].elem = (char*)malloc(11*sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 11 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ����  
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = 1;        //��ʱ���ҳ���Ϊ 1
		} 
		//==========α���̽����ɢ�з������ͻ==========//
		else
		{ 
			while(hash[m].elem != "��null��")      //Ҫ��λ���Ѿ���ռ ���ˣ���ʱ��α����������죬����һ����λ�ã�֪���ҵ�Ϊֹ 
			{   
				srand(w); 
				m = rand() % 3397;
				w++;
				sum++;
			}    
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 20 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ���� 
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = sum + 1;      // ��ʱ���ҳ���Ϊsum + 1;
		} 
		sum = 0;           //�� sum ���� 
		d=0;            //�� d ����
	}
	
	return 0;
}


//------------------��ϣ��2��α�����������������̽�ⷨ�����ͻ---------------------//

Status CreateHash2(NameTable &name, HashTable &hash)   //������ϣ��
{
	int i;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //����ϣ�����ÿһ ��λ�ö���Ϊ��
	{     
		hash[i].elem="��null��";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//----------α�����������-----------//
	for(i=0;i<3000;i++)
	{
		for(j=0;j<name[i].sizeindex;j++)
		{
			d += name[i].elem[j];
		}
		srand(d); 
		m = rand()%3397;
		printf("%d\t",m);
		if(hash[m].sizeindex == 0)
		{
			hash[m].elem = (char*)malloc(11*sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 11 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ����  
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = 1;        //��ʱ���ҳ���Ϊ 1
		}
		//----------����̽�ⷨ�����ͻ------------//
		else
		{
			while(hash[m].elem != "��null��")
			{
				m++;
				m = m%3397;
				sum++;
			}
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 20 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ���� 
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = sum + 1;      // ��ʱ���ҳ���Ϊsum + 1;
		}
		sum = 0;
		d = 0;
	}
	return 0;
}


//------------------��ϣ��3��ƽ��ȡ�з�����������̽����ɢ�з������ͻ---------------------//

Status CreateHash3(NameTable &name, HashTable &hash)   //������ϣ��
{
	int i;
	int w=1;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //����ϣ�����ÿһ ��λ�ö���Ϊ��
	{     
		hash[i].elem="��null��";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//==========ƽ��ȡ�з�����==========//
	for(i=0;i<3000;i++)
	{
		for(j=0;j<name[i].sizeindex;j++)
		{
			d += name[i].elem[j];
		}


		m = d*d;
		char str[10];	//��str���ƽ����Ĺؼ��֣�Ϊ6��7λ
		char str2[4];	//��str2��Ŵ����Ĺؼ��֣�Ϊ4λ
		sprintf(str,"%d",m);	//�Ȱ�mת��Ϊ�ַ��������str��
		for(int x=1,y=0; x!=5; x++,y++)
		{
			str2[y]=str[x];
		}
		str2[4] = '\0';		//����str2�ַ���
		sscanf(str2,"%d",&m);	//�����յĹؼ��ִ����m�У�ȡֵ��ΧΪ0~9999
		m = m%3397;
		if(hash[m].sizeindex == 0)       //��ʼ�����ַ��뵽 ��ϣ����ȥ  
		{ 
			hash[m].elem = (char*)malloc(11*sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 11 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ����  
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = 1;        //��ʱ���ҳ���Ϊ 1
		} 
		//=========����̽����ɢ�з������ͻ========//
		else
		{
			int flag=1 , add=1 , less=1 , point = m;
			while(hash[m].elem != "��null��")
			{
				if(flag == 1)
				{
					m = (point+add*add)%3397;
					add++;
					flag = 0;
				}
				else
				{
					m = (point-less*less)%3397;
					less++;
					flag = 1;
				}
				if(m<0)
					m = -m;
				sum++;
			}
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //���ٹ�ϣ���е�һ ��λ�õĿռ䣬�ռ��СΪ 20 ���ַ� 
			strcpy(hash[m].elem,name[i].elem);    //��Ҫ��������ֿ� ������ϣ���� 
			hash[m].sizeindex = name[i].sizeindex;   //���ֵĳ���Ҳ��ֵ ����ϣ����ȥ
			hash[m].count = sum + 1;      // ��ʱ���ҳ���Ϊsum + 1;
		}
		sum = 0;
		d = 0;
	}
	return 0;
}

//-------------����ϣ������d:/hash------------//

Status ExportHash(HashTable &hash , int mark)
{
	int i;
	ofstream ofile;	//�����ĵ���
	if(mark == 1)
	{
		ofile.open("d:\\hash1.txt");	//�½�"hash1.txt"����������ɵ�����
		printf("�Ѵ�����ϣ����ŵ�ַΪ:D:/hash1.txt\n");
	}
	if(mark == 2)
	{
		ofile.open("d:\\hash2.txt");	//�½�"hash2.txt"����������ɵ�����
		printf("�Ѵ�����ϣ����ŵ�ַΪ:D:/hash2.txt\n");
	}
	if(mark == 3)
	{
		ofile.open("d:\\hash3.txt");	//�½�"hash3.txt"����������ɵ�����
		printf("�Ѵ�����ϣ����ŵ�ַΪ:D:/hash3.txt\n");
	}
	ofile<<"���      ����                ���ҳ���"<<endl;
	for(i=0;i<3400;i++)  
	{   
		ofile<<left<<setw(10)<<i<<left<<setw(20)<<hash[i].elem<<left<<setw(10)<<hash[i].count<<endl;	//��������ʽ
	} 
	return 0;
}


//--------------��������(hash1)----------------//

Status SearchHash1(char aa[], HashTable &hash)
{ 
	int a,j;
	int s = 0;  
	int m = 0;
	int d = 0;
	int w=1;
	char *f;
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //����ͳ�ƴ������� ����ĸ�������ܺ�
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //����ͳ�ƴ����ҵ� ������ĸ�� ASCII ���ܺ�
	{ 
		d = aa[j] + d;
	}
	m = d % 3397;
	while(hash[m].elem != "��null��" && strcmp(aa,hash[m].elem) != 0)//����α����������ڹ�ϣ���в���
	{ 
		srand(w); 
		m = rand()%3397; 
		w++;
	}
	if (hash[m].elem != "��null��" && strcmp(aa, hash[m].elem) == 0) //�ڹ�ϣ�����ҵ��� 
	{
		a = m; 
		printf("���ҵ����ѯ���ˣ����ҳ���Ϊ%d\n",hash[m].count);  
		printf("�����ڹ�ϣ���е�λ��Ϊ��%d",a);   printf("\n"); 
	} 
	else             //δ�ڹ�ϣ�����ҵ�
	{ 
		printf("���޴��ˣ�\n");     
		printf("\n");
	}
	return 0;
}

//--------------��������(hash2)----------------//

Status SearchHash2(char aa[], HashTable &hash)
{ 
	int a,j;
	int s = 0;  
	int m = 0;
	int d = 0;
	char *f;
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //����ͳ�ƴ������� ����ĸ�������ܺ�
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //����ͳ�ƴ����ҵ� ������ĸ�� ASCII ���ܺ�
	{ 
		d = aa[j] + d;
	}
	srand(d); 
	m = rand()%3397; 
	while(hash[m].elem != "��null��" && strcmp(aa,hash[m].elem) != 0)//����α����������ڹ�ϣ���в���
	{ 
		m++;
		m = m%3397;
	}
	if (hash[m].elem != "��null��" && strcmp(aa, hash[m].elem) == 0) //�ڹ�ϣ�����ҵ��� 
	{
		a = m; 
		printf("���ҵ����ѯ���ˣ����ҳ���Ϊ%d\n",hash[m].count);  
		printf("�����ڹ�ϣ���е�λ��Ϊ��%d",a);   printf("\n"); 
	} 
	else             //δ�ڹ�ϣ�����ҵ�
	{ 
		printf("���޴��ˣ�\n");     
		printf("\n");
	}
	return 0;
}

//--------------��������(hash3)----------------//

Status SearchHash3(char aa[], HashTable &hash)
{ 
	int j;	//������
	int s = 0;	
	int m = 0;	//key
	int d = 0;	//ascii��
	int w=1;	//
	char *f;	//�ַ�ָ��
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //����ͳ�ƴ������� ����ĸ�������ܺ�
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //����ͳ�ƴ����ҵ� ������ĸ�� ASCII ���ܺ�
	{ 
		d = aa[j] + d;
	}
	m = d*d;
	char str[10];	//��str���ƽ����Ĺؼ��֣�Ϊ6��7λ
	char str2[4];	//��str2��Ŵ����Ĺؼ��֣�Ϊ4λ
	sprintf(str,"%d",m);	//�Ȱ�mת��Ϊ�ַ��������str��
	for(int x=1,y=0; x!=5; x++,y++)
	{
		str2[y]=str[x];
	}
	str2[4] = '\0';		//����str2�ַ���
	sscanf(str2,"%d",&m);	//�����յĹؼ��ִ����m�У�ȡֵ��ΧΪ0~9999
	m = m % 3397;
	int flag = 1 , add = 1 , less = 1 , point = m;
	while(hash[m].elem != "��null��" && strcmp(aa,hash[m].elem) != 0)
	{
		if(flag == 1)
		{
			m = (point+add*add)%3397;
			add++;
			flag = 0;
		}
		else
		{
			m = (point-less*less)%3397;
			less++;
			flag = 1;
		}
		if(m<0)
			m = -m;
	}
	if (hash[m].elem != "��null��" && strcmp(aa, hash[m].elem) == 0) //�ڹ�ϣ�����ҵ��� 
	{
		printf("���ҵ����ѯ���ˣ����ҳ���Ϊ%d\n",hash[m].count);  
		printf("�����ڹ�ϣ���е�λ��Ϊ��%d",m);
		printf("\n"); 
	} 
	else             //δ�ڹ�ϣ�����ҵ�
	{ 
		printf("���޴��ˣ�\n");     
		printf("\n");
	}
	return 0;
}

//------------Main--------------//

int main()
{
   int i,m;
   float n = 0;
   char k;

   RandomName();		//�����������
   NameTable name;		//��������
   HashTable hash;		//�����ϣ��
   CreateName(name);        //������������ļ���ŵ��� D:\name.txt ����

   while (1)
   {
	   n=0;
	   printf("\n--------��ѡ����Ҫʹ�õĹ���--------\n");
	   puts("0.�������������ļ�");
	   puts("1.�ԡ�����������������α���̽����ɢ�з������ͻ����������ϣ��");
	   puts("2.�ԡ�α�����������������̽�ⷨ�����ͻ����������ϣ��");
	   puts("3.�ԡ�ƽ��ȡ�з�����������̽����ɢ�з������ͻ����������ϣ��");
	   scanf("%d", &m);
	   switch (m)
	   {
		   case 0:
		   {
			   RandomName();
			   CreateName(name);
			   break;
		   };
		   case 1:
		   {
			   puts("\n���ڴ�����ϣ��1......");
			   CreateHash1(name, hash); 
			   ExportHash(hash,m);
			   for(i=0;i<3400;i++)
			   {
				   n += hash[i].count;
			   }
			   n = n/3000;
			   printf("ƽ�����ҳ���Ϊ%f\n",n);
			   printf("\n�Ƿ�Ըù�ϣ����в���? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("������������˵����֣�");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash1(aa, hash);
				   puts("");
			       printf("�Ƿ�����Ըù�ϣ����в���? (y/n):");
			       scanf("%s",&k);
			   }
			   break;
		   };
		   case 2:
		   {
			   puts("\n���ڴ�����ϣ��2......");
			   CreateHash2(name, hash); 
			   ExportHash(hash,m);
			   for(i=0;i<3400;i++)
			   {
				   n += hash[i].count;
			   }
			   n = n/3000;
			   printf("ƽ�����ҳ���Ϊ%f\n",n);
			   printf("\n�Ƿ�Ըù�ϣ����в���? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("������������˵����֣�");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash2(aa, hash);
				   puts("");
			       printf("�Ƿ�����Ըù�ϣ����в���? (y/n):");
			       scanf("%s",&k);
			   }
			   break;
		   };
		   case 3:
		   {
			   CreateHash3(name, hash); 
			   ExportHash(hash,m);
			   for(i=0;i<3400;i++)
			   {
				   n += hash[i].count;
			   }
			   n = n/3000;
			   printf("ƽ�����ҳ���Ϊ%f\n",n);
			   printf("\n�Ƿ�Ըù�ϣ����в���? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("������������˵����֣�");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash3(aa, hash);
				   puts("");
			       printf("�Ƿ�����Ըù�ϣ����в���? (y/n):");
			       scanf("%s",&k);
			   }
			   break;
		   };
	   }
   }
   return 0;
}