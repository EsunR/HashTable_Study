//--------------头文件声明---------------// 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std; 




//-----------------定义声明-------------------//

typedef int Status;
typedef struct
{
	char *elem;  
	int sizeindex;          //当前容量
}NameTable[3000];           //一开始用来存名字

typedef struct
{
	char *elem;    
	int sizeindex;          //名字的长度 
	int count;           //要查询的次数
}HashTable[3400];           //3400个位置的哈希表



//-----------------函数声明-------------------//

void RandomName();		//随机生成名字
Status CreateName(NameTable &name);      //创建名字
Status CreateHash(NameTable &name,HashTable &hash);  //创建哈希表
Status SearchHash(char aa[],HashTable &hash);   //查找名字
Status DishplayHashList(HashTable &hash);    //遍历哈希表
void FreeHash(HashTable &hash);       //释放哈希表



//-----------------随机生成名字-------------------//

void RandomName()
{
	//构建姓名字典，100组姓氏，175+235组汉语拼音全组合
	string name1[100] = {"zhao","qian","sun","li","zhou","wu","zheng","wang","feng","chen","du","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lv","shi","zhang","kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zou","yu","bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang","lu","wei","ji","shen","fu","du","ran","niu","tong","shou","xiang","gu","yi","shen","ge","liao","zhong","ji","ju","heng","bu","geng","guang","lu","dong","ou","wo","li","shi","gong","ku","nie","zeng","hou","gai","gong","you","duan","si","liang","men","nan","men","she","kuo","ba","qian","bai","li","sheng","qing","pu"};
	string name2[175] = {"a","ai","an","ang","ao","ba","bai","ban","bang","bao","bei","ben","beng","bi","bian","biao","bie","bin","bing","bo","bu","ca","cai","can","cang","cao","ce","cen","ceng","cha","chai","chan","chang","chao","che","chen","cheng","chi","chong","chou","chu","chua","chuai","chuan","chuang","chui","chun","chuo","ci","cong","cou","cu","cuan","cui","cun","cuo","da","dai","dan","dang","dao","de","dei","den","deng","di","dia","dian","diao","die","ding","diu","dong","dou","du","duan","dui","dun","duo","e","en","eng","er","fa","fan","fang","fei","fen","feng","fiao","fo","fou","fu","ga","gai","gan","gang","gao","ge","gei","gen","geng","gong","gou","gu","gua","guai","guan","guang","gui","gun","guo","ha","hai","han","hang","hao","he","hei","hen","heng","hong","hou","hu","hua","huai","huan","huang","hui","hun","huo","ji","jia","jian","jiang","jiao","jie","jin","jing","jiong","jiu","ju","juan","jue","ka","kai","kan","kang","kao","ke","ken","keng","kong","kou","ku","kua","kuai","kuan","kuang","kui","kun","kuo","la","lai","lan","lang","lao","le","lei","leng","li","lia","lian","liang","liao"};
	string name3[235] = {"lie","lin","ling","liu","lo","long","lou","lu","luan","lun","luo","lv","lve","ma","mai","man","mang","mao","me","mei","men","meng","mi","mian","miao","mie","min","ming","miu","mo","mou","mu","na","nai","nan","nang","nao","ne","nei","nen","neng","ni","nian","niang","niao","nie","nin","ning","niu","nong","nou","nu","nuan","nun","nuo","nv","nve","o","ou","pa","pai","pan","pang","pao","pei","pen","peng","pi","pian","piao","pie","pin","ping","po","pou","pu","qi","qia","qian","qiang","qiao","qie","qin","qing","qiong","qiu","qu","quan","que","qun","ran","rang","rao","re","ren","reng","ri","rong","rou","ru","rua","ruan","rui","run","ruo","sa","sai","san","sang","sao","se","sen","seng","sha","shai","shan","shang","shao","she","shei","shen","sheng","shi","shou","shu","shua","shuai","shuan","shuang","shui","shun","shuo","si","song","sou","su","suan","sui","sun","suo","ta","tai","tan","tang","tao","te","tei","teng","ti","tian","tiao","tie","ting","tong","tou","tu","tuan","tui","tun","tuo","wa","wai","wan","wang","wei","wen","weng","wo","wu","xi","xia","xian","xiang","xiao","xie","xin","xing","xiong","xiu","xu","xuan","xue","xun","ya","yan","yang","yao","ye","yi","yin","ying","yo","yong","you","yu","yuan","yue","yun","za","zai","zan","zang","zao","ze","zei","zen","zeng","zha","zhai","zhan","zhang","zhao","zhe","zhei","zhen","zheng","zhi","zhong","zhou","zhu","zhua","zhuai","zhuan","zhuang","zhui","zhun","zhuo","zi","zong","zou","zu","zuan","zui","zun","zuo"};
	srand((unsigned)time(NULL)); //初始化随机数发生器
	ofstream ofile;	//定义文档流
	ofile.open("d:\\name.txt");	//新建"name.txt"用来存放生成的名字
	printf("正在随机生成姓名，请稍后......\n");
	//随机生成的名字
	for(int i=0;i<3000;i++)	
	{
		int j=0;
		do	//判断名字字长要小于10
		{
			//随机取数 
			int ranName1 = (rand()%99);
			int ranName2 = (rand()%174);
			int ranName3 = (rand()%234);
			string name = name1[ranName1]+name2[ranName2]+name3[ranName3];
			//计算生成的名字长度
			for(j=0;name[j]!='\0';j++);
			if(j<=10)	//如果名字字长符合要求
				ofile<<name<<endl;	//将名字写入文件
		}while(j>10);	  
	}
	ofile.close(); 
	printf("\n随机姓名生成完毕，存放目录为d:\\name.txt\n");
	printf("--------------------------------------------\n");
}



//-----------------从建立的文本中逐个读取名字-------------------//

Status CreateName(NameTable &name)
{
	char *f;   
	int i,j;
	for(i=0;i<3000;i++)          //开辟名字，并将每个名字的长度赋值为 0； 
	{  
		name[i].elem = (char*)malloc(11*sizeof(char));  
		name[i].sizeindex=0;
	}
	
	
	//--开始抽取名字到系统中--//
char a[100000];	//定义可读取字符的最大长度
    ifstream ifile;               //定义输入文件
    ifile.open("d:\\name.txt");     //作为输入文件打开
    i=j=0;
	int m=0 ,flag=0;
	char singleName[11];
    while(ifile.get(a[i]))
	{
		if(a[i]!='\n')
		{
			singleName[j] = a[i];	//创建singleName
			j++;
		}
		else
		{
			singleName[j] = '\0';	//封锁singleName字符串
			strcpy(name[flag].elem,singleName);
			for(m=0;singleName[m]!='\0';m++)
				singleName[m] = '\0';	//逐一重置singleName
			j=0;
			flag++;
		}
		i++;
		if(flag == 3000) break; //抽取3000个名字
		
    }
	printf("\n");
    ifile.close();
	//--开始抽取完毕--//

	for(i=0;i<3000;i++)          //统计每个名字的长 度
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


//------------------哈希表1：除留余数法创建，伪随机探测再散列法解决冲突---------------------//

Status CreateHash1(NameTable &name, HashTable &hash)   //创建哈希表
{
	int i;
	int w=1;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //将哈希表里的每一 个位置都赋为空
	{     
		hash[i].elem="【null】";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//==========除留余数法创建==========//
	for(i=0;i<3000;i++)         
	{  
		for(j=0;j<name[i].sizeindex;j++)     //将每个人姓名中的 字母都加起来（即 ASCII 加起来） 
		{  
			d += name[i].elem[j];
		} 
		m = d % 3397;           //哈希函数：名字中的 字母加起来的总和除以 3337 取余，这样做可是其分布均匀  
		if(hash[m].sizeindex == 0)       //开始将名字放入到 哈希表里去  
		{ 
			hash[m].elem = (char*)malloc(11*sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 11 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里  
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = 1;        //此时查找长度为 1
		} 
		//==========伪随机探测再散列法解决冲突==========//
		else
		{ 
			while(hash[m].elem != "【null】")      //要的位置已经被占 用了，此时用伪随机函数构造，找下一个空位置，知道找到为止 
			{   
				srand(w); 
				m = rand() % 3397;
				w++;
				sum++;
			}    
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 20 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里 
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = sum + 1;      // 此时查找长度为sum + 1;
		} 
		sum = 0;           //将 sum 清零 
		d=0;            //将 d 清零
	}
	
	return 0;
}


//------------------哈希表2：伪随机数法创建，线性探测法解决冲突---------------------//

Status CreateHash2(NameTable &name, HashTable &hash)   //创建哈希表
{
	int i;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //将哈希表里的每一 个位置都赋为空
	{     
		hash[i].elem="【null】";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//----------伪随机数法创建-----------//
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
			hash[m].elem = (char*)malloc(11*sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 11 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里  
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = 1;        //此时查找长度为 1
		}
		//----------线性探测法解决冲突------------//
		else
		{
			while(hash[m].elem != "【null】")
			{
				m++;
				m = m%3397;
				sum++;
			}
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 20 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里 
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = sum + 1;      // 此时查找长度为sum + 1;
		}
		sum = 0;
		d = 0;
	}
	return 0;
}


//------------------哈希表3：平方取中法创建，二次探测再散列法解决冲突---------------------//

Status CreateHash3(NameTable &name, HashTable &hash)   //创建哈希表
{
	int i;
	int w=1;
	int m,d=0,j;
	int sum=0;
	for(i=0;i<3400;i++)          //将哈希表里的每一 个位置都赋为空
	{     
		hash[i].elem="【null】";          
		hash[i].sizeindex = 0;
		hash[i].count = 0;
	} 
	//==========平方取中法创建==========//
	for(i=0;i<3000;i++)
	{
		for(j=0;j<name[i].sizeindex;j++)
		{
			d += name[i].elem[j];
		}


		m = d*d;
		char str[10];	//用str存放平方后的关键字，为6或7位
		char str2[4];	//用str2存放处理后的关键字，为4位
		sprintf(str,"%d",m);	//先把m转化为字符串存放至str中
		for(int x=1,y=0; x!=5; x++,y++)
		{
			str2[y]=str[x];
		}
		str2[4] = '\0';		//封锁str2字符串
		sscanf(str2,"%d",&m);	//将最终的关键字存放在m中，取值范围为0~9999
		m = m%3397;
		if(hash[m].sizeindex == 0)       //开始将名字放入到 哈希表里去  
		{ 
			hash[m].elem = (char*)malloc(11*sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 11 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里  
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = 1;        //此时查找长度为 1
		} 
		//=========二次探测再散列法解决冲突========//
		else
		{
			int flag=1 , add=1 , less=1 , point = m;
			while(hash[m].elem != "【null】")
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
			hash[m].elem = (char*)malloc(11 * sizeof(char)); //开辟哈希表中的一 个位置的空间，空间大小为 20 个字符 
			strcpy(hash[m].elem,name[i].elem);    //将要插入的名字拷 贝到哈希表里 
			hash[m].sizeindex = name[i].sizeindex;   //名字的长度也赋值 到哈希表里去
			hash[m].count = sum + 1;      // 此时查找长度为sum + 1;
		}
		sum = 0;
		d = 0;
	}
	return 0;
}

//-------------将哈希表导出到d:/hash------------//

Status ExportHash(HashTable &hash , int mark)
{
	int i;
	ofstream ofile;	//定义文档流
	if(mark == 1)
	{
		ofile.open("d:\\hash1.txt");	//新建"hash1.txt"用来存放生成的名字
		printf("已创建哈希表，存放地址为:D:/hash1.txt\n");
	}
	if(mark == 2)
	{
		ofile.open("d:\\hash2.txt");	//新建"hash2.txt"用来存放生成的名字
		printf("已创建哈希表，存放地址为:D:/hash2.txt\n");
	}
	if(mark == 3)
	{
		ofile.open("d:\\hash3.txt");	//新建"hash3.txt"用来存放生成的名字
		printf("已创建哈希表，存放地址为:D:/hash3.txt\n");
	}
	ofile<<"编号      名字                查找长度"<<endl;
	for(i=0;i<3400;i++)  
	{   
		ofile<<left<<setw(10)<<i<<left<<setw(20)<<hash[i].elem<<left<<setw(10)<<hash[i].count<<endl;	//整理导出格式
	} 
	return 0;
}


//--------------查找名字(hash1)----------------//

Status SearchHash1(char aa[], HashTable &hash)
{ 
	int a,j;
	int s = 0;  
	int m = 0;
	int d = 0;
	int w=1;
	char *f;
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //用来统计待查找名 字字母个数的总和
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //用来统计待查找的 名字字母的 ASCII 的总和
	{ 
		d = aa[j] + d;
	}
	m = d % 3397;
	while(hash[m].elem != "【null】" && strcmp(aa,hash[m].elem) != 0)//根据伪随机函数，在哈希表中查找
	{ 
		srand(w); 
		m = rand()%3397; 
		w++;
	}
	if (hash[m].elem != "【null】" && strcmp(aa, hash[m].elem) == 0) //在哈希表中找到了 
	{
		a = m; 
		printf("已找到需查询的人，查找长度为%d\n",hash[m].count);  
		printf("此人在哈希表中的位置为：%d",a);   printf("\n"); 
	} 
	else             //未在哈希表中找到
	{ 
		printf("查无此人！\n");     
		printf("\n");
	}
	return 0;
}

//--------------查找名字(hash2)----------------//

Status SearchHash2(char aa[], HashTable &hash)
{ 
	int a,j;
	int s = 0;  
	int m = 0;
	int d = 0;
	char *f;
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //用来统计待查找名 字字母个数的总和
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //用来统计待查找的 名字字母的 ASCII 的总和
	{ 
		d = aa[j] + d;
	}
	srand(d); 
	m = rand()%3397; 
	while(hash[m].elem != "【null】" && strcmp(aa,hash[m].elem) != 0)//根据伪随机函数，在哈希表中查找
	{ 
		m++;
		m = m%3397;
	}
	if (hash[m].elem != "【null】" && strcmp(aa, hash[m].elem) == 0) //在哈希表中找到了 
	{
		a = m; 
		printf("已找到需查询的人，查找长度为%d\n",hash[m].count);  
		printf("此人在哈希表中的位置为：%d",a);   printf("\n"); 
	} 
	else             //未在哈希表中找到
	{ 
		printf("查无此人！\n");     
		printf("\n");
	}
	return 0;
}

//--------------查找名字(hash3)----------------//

Status SearchHash3(char aa[], HashTable &hash)
{ 
	int j;	//计数器
	int s = 0;	
	int m = 0;	//key
	int d = 0;	//ascii码
	int w=1;	//
	char *f;	//字符指针
	f = aa;
	for(j=0;*(f+j)!='\0';j++)        //用来统计待查找名 字字母个数的总和
	{ 
		s = s + 1;
	}
	for(j=0;j<s;j++)          //用来统计待查找的 名字字母的 ASCII 的总和
	{ 
		d = aa[j] + d;
	}
	m = d*d;
	char str[10];	//用str存放平方后的关键字，为6或7位
	char str2[4];	//用str2存放处理后的关键字，为4位
	sprintf(str,"%d",m);	//先把m转化为字符串存放至str中
	for(int x=1,y=0; x!=5; x++,y++)
	{
		str2[y]=str[x];
	}
	str2[4] = '\0';		//封锁str2字符串
	sscanf(str2,"%d",&m);	//将最终的关键字存放在m中，取值范围为0~9999
	m = m % 3397;
	int flag = 1 , add = 1 , less = 1 , point = m;
	while(hash[m].elem != "【null】" && strcmp(aa,hash[m].elem) != 0)
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
	if (hash[m].elem != "【null】" && strcmp(aa, hash[m].elem) == 0) //在哈希表中找到了 
	{
		printf("已找到需查询的人，查找长度为%d\n",hash[m].count);  
		printf("此人在哈希表中的位置为：%d",m);
		printf("\n"); 
	} 
	else             //未在哈希表中找到
	{ 
		printf("查无此人！\n");     
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

   RandomName();		//随机生成名字
   NameTable name;		//定义姓名
   HashTable hash;		//定义哈希表
   CreateName(name);        //建立随机姓名文件存放到“ D:\name.txt ”下

   while (1)
   {
	   n=0;
	   printf("\n--------请选择您要使用的功能--------\n");
	   puts("0.重新生成姓名文件");
	   puts("1.以【除留余数法创建，伪随机探测再散列法解决冲突】来建立哈希表");
	   puts("2.以【伪随机数法创建，线性探测法解决冲突】来建立哈希表");
	   puts("3.以【平方取中法创建，二次探测再散列法解决冲突】来建立哈希表");
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
			   puts("\n正在创建哈希表1......");
			   CreateHash1(name, hash); 
			   ExportHash(hash,m);
			   for(i=0;i<3400;i++)
			   {
				   n += hash[i].count;
			   }
			   n = n/3000;
			   printf("平均查找长度为%f\n",n);
			   printf("\n是否对该哈希表进行查找? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("请输入需查找人的名字：");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash1(aa, hash);
				   puts("");
			       printf("是否继续对该哈希表进行查找? (y/n):");
			       scanf("%s",&k);
			   }
			   break;
		   };
		   case 2:
		   {
			   puts("\n正在创建哈希表2......");
			   CreateHash2(name, hash); 
			   ExportHash(hash,m);
			   for(i=0;i<3400;i++)
			   {
				   n += hash[i].count;
			   }
			   n = n/3000;
			   printf("平均查找长度为%f\n",n);
			   printf("\n是否对该哈希表进行查找? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("请输入需查找人的名字：");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash2(aa, hash);
				   puts("");
			       printf("是否继续对该哈希表进行查找? (y/n):");
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
			   printf("平均查找长度为%f\n",n);
			   printf("\n是否对该哈希表进行查找? (y/n):");
			   scanf("%s",&k);
			   while(k == 'y')
			   {
				   printf("请输入需查找人的名字：");
			       char aa[20];
			       scanf("%s", aa);
			       SearchHash3(aa, hash);
				   puts("");
			       printf("是否继续对该哈希表进行查找? (y/n):");
			       scanf("%s",&k);
			   }
			   break;
		   };
	   }
   }
   return 0;
}