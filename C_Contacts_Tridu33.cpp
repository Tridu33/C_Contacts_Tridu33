

/*
********************************************************************
版本声明：
                                   ╭════════════════════════╮
                                  ║         〖课题设计：学生通讯录管理系统〗         ║
         ╭══════════════════════┤设计时间：2019.3.3 ├══════════════════╮
        ║                        ║   设计人：  2016级工业工程专业 邝伟杜Tridu³³     ║                           ║
        ║                        ╰═════════════════════════╯                           ║
      　║                                        ★    关于我的Code     ★                                        ║ 
		║   @计算机配置：windows 10 教育版 64位操作系统 内存：4G CPU ：i3--6100
		║   @运行环境：Microsoft Visual C++ 2010
		║   @设计思路：建立多个子函数，分别用来信息读取（peopple.txt）、添加、浏览、查找、删除、修改、排序、
		║               保存通讯录信息，完成通讯录的功能。
		║			    主函数采用密码，保护了通讯录数据，可以调用8个子函数，分别完成添加、显示、删除、查询记录、
		║			    修改记录、保存记录、读取记录、统计记录、退出系统等功能。
		║			    在主函数中可以以1、2、3、4、5、6、7、8、9、10、0数字键
		║			    分别可以执行某个功能模块。
		║  @扩展功能：利用system系统函数，实现对程序功能的扩展，为了方便用户和大众软件的设计方法，利用系统函数system调用windows
		║			  dos 命令实现对计算机的关机，重启，定时关机，注销等功能。
        ║ 限参考、教学与个人使用交流！请勿用于商业目的。                                                           ║ 
  　  　║--------------------------------------------------------------------------------------------------------- ║         
      　║                                              ★   @主要函数  ★                                          ║
  　    ║                              |----------------------------------------------|                            ║
	    ║    int Menu_select()              系统用户登录后的菜单												    ║
		║	  int Input(Student stu[])       添加记录函数                                                           ║
        ║    void Display(Student stu[])    浏览记录函数														    ║
		║    void Chick(Student stu[])      查找记录函数													        ║
		║	  int Delete(Student stu[])      删除记录函数													        ║
		║	  void Change(Student stu[])     修改记录函数													        ║
		║																										    ║
		║	  void WritetoText(Student stu[]) 写入文件函数															║
		║	  void Read(Student stu[])       读取文件函数															║
		║																									    	║
		║	  void Menu()                     对应int Menu_select()函数的子菜单 他调用除主函数意外的所有函数		║
		║																											║																							║
		║	  int main()                     主函数设置密码功能 调用 Menu 函数										║
		║																											║
　      ║----------------------------------------------------------------------------------------------------------║
        ║                          欢迎提出您的建议或意见，请发邮件:2055969978@qq.com                              ║
        ║----------------------------------------------------------------------------------------------------------║
    　　║                                                                                                          ║
        ║                     ╭──────────────────────────────╮                     ║
        ╰══════════┤   ★★★★★★  Tridu³³，2055969978@qq.com★★★★★★★     ├══════════╯
                              ╰───────────────────────────────╯

							  //想实现：
//保持格txt式打断文章打印功能（bat,cmd命令提示）+命令行system传入惊醒cmd操作各种功能。OK
//GUI想写个伪记事本显示功能
//有声有色有弹框msgbox""OK
//密码账户
//文件加密解密和部分账户信息隐藏自动显示一些不得了的账户。还没做好?

//心得：终于知道为什么说C语言那么多人喜欢用了，多余的双引号括号真是烦死人了，所以有人用Vimhjkl来移动！！！甚至函数式Curry化函数传参，较少括号。
结构紧凑的代码{
	Python的固定结构油然而生。
}
以前我不明白为什么Python这样规定，后面发现节省了很多没意义的打空格打花括号的时间，哪怕再小的负担也会堆垮万里长城。
因为只要是想要结构紧凑的代码，JAVA，js或者很多源码都会慢慢地写成Python的样子，而不是宽阔找不到北的C语言。
尽管这一切可以用Format实现，但是，Python在这方面的确编程风格更为紧凑
//@结构体版本

******************************************************************
*/

// C_Contacts_Tridu33.cpp : 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS  
#include "stdafx.h"//编译程序会先从当前目录中找文件，生成预编译头文件！预编译，是为了提高编译速度！
#include"stdio.h"//一般是用双引号来引用自己编写的文件，而用尖括号引用系统标准的文件。
#include<stdlib.h>//用于数值转换、内存分配以及具有其他相似任务的函数。free()
#include<conio.h>//Console Input/Output（控制台输入输出）的简写，其中定义了通过控制台进行数据输入和数据输出的函数，主要是一些用户通过按键盘产生的对应操作，比如getch()函数等等。
#include<string.h>//字符串处理
#include<dos.h>//包含了很多BIOS和DOS调用函数
#include<windows.h>
#include <ctype.h>//
char buf[100] = "";//全局变量
//以下的所有表示音符的符号均来自fl studio 14 的fl keys的标注，或许和一般钢琴的标注不一样 。 
//只有三个八度的音高频率 ，因为一般人声可以达到的频率大概都会落在这些里面 
#define C4 523
#define CZ4 554
#define D4 588
#define DZ4 623
#define E4 660
#define F4 700
#define FZ4 742
#define G4 786
#define GZ4 833
#define A4 884
#define AZ4 936
#define B4 992


 
#define C5 1046
#define CZ5 1108
#define D5 1176
#define DZ5 1246
#define E5 1320
#define F5 1400
#define FZ5 1484
#define G5 1572
#define GZ5 1666
#define A5 1768
#define AZ5 1872
#define B5 1984
 
#define C6 2092
#define CZ6 2216
#define D6 2352
#define DZ6 2492
#define E6 2640
#define F6 2800
#define FZ6 2968
#define G6 3144
#define GZ6 3332
#define A6 3536
#define AZ6 3744
#define B6 3968
#define P 125   //折合bpm==120，原bpm为105，此处取了个近似值 
 
typedef struct
{	int frequency;
	int duration;
}PU;

PU a[]={
	G6,4,E6,2,F6,1,G6,2,G6,6,
	F6,4,D6,2,E6,1,F6,2,F6,6,
};
#define LENGTH sizeof(struct student)

//-------------------------------------------------------------------------
struct student{
	char name[10];
	char sex[10];
	char tel[8][13];//电话号码13位少于8个数组，空白的不理会，以后可以进去Numbers(8,:)；定义char a[30]，如果没有初始化，从a[0]到a[29]都是'\0'，也就是数值0（强制类型转换为int就等于0）；另外你可能不明白：char a = '\0'; 表达式(int)a==0; 为true；‘\0’是字符串结束的标志，比如定义：char a[] = "hello"; 则a[5] = '\0', a[6]未知。
	char addr[30];
    char birthday[20];
};

struct student students[100];//结构体数组students，通讯录不可能超过100人，所以这样子完全符合题意。

//声明函数	

void menu();//菜单
void readtxt();//信息读取（peopple.txt）
int input();//添加
void writetxt();//保存通讯录信息（peopple.txt）
void display();//浏览
int search();	//查找
void del();//删除
void update();//修改
void sort();//排序
void exit();
void schoolsong();//
void showtxt();//
void cmd();//



//-------------------------------------------------------------------------
//

void cmd(){
	system("mode con cols=150 lines=30");
	system("color f0");
	system("title cmd命令");
    system("date /T");
    system("TIME /T");
	int i=0;
	while(1){
			char str[100]="";//防止溢出用100
			//inputInFo();//？？？？？？？？/内存溢出？C语言子函数不能调用 子函数吗？只能main函数调用子函数吗？
			memset(buf,0,100);
			if(i==0)
				i++;
			else
				printf("输入要执行的cmd命令(exit退出)\n");
			gets(buf);//fgets(buf)已经instead	//第一次为什么会不执行？		
			/*strcpy(str,buf);
			printf("%s",str);
			printf("%s",buf);*/
			//system(str);//这行不能用会引起，明明子程序能用，可能放进来子函数就不能用了，真奇怪，试试文件的方法。
			
			FILE *pFile = fopen("cmd.bat","w");//用临时文件传递参数的办法实现（网上找的）
			//inputInFo();						//我想到也可以用字符串传入的办法shutdown -s -t 3600 system(strcat(cmd,t));  char cmd[20]="shutdown -s -t ";
			if(pFile != NULL){
			fprintf(pFile,"%s",buf);
			fclose(pFile);
			system("cmd.bat");//run 
			system("del cmd.bat");//del 
			//system("pause");
			if(i==0)
				i++;
			else
				printf("执行的命令为：%s\n",buf);
			//fclose(pFile);
			char Exit[100]="exit";
			if(strcmp(buf,Exit)==0)
				break;
			else
				continue;
			}
	}

}
//-------------------------------------------------------------------------
void showtxt(){
			system("cls");
			//system("title 输入0返回主菜单");
			char c;
			//文件输入
			freopen( "show.txt", "r", stdin );//反复打开的原因reopen查查这是为什么？查看为什么输入无效，怎么才能停止？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
			while ( scanf( "%c", &c )!=EOF ){
				printf( "%c", c );
			}
			freopen("CON","r",stdin ); //https://blog.csdn.net/pqleo/article/details/23031337 卡了三天的问题原来在这儿！！！！让流回到控制台?使用freopen后如何将stdout输出流还原回屏幕？
			//break;//步进没问题，但是不知道为什么不能只执行一次，死循环
	system("pause");
	//exit(1);
}//void 加个return会死循环这一步！！！！！！！！！！
//-------------------------------------------------------------------------

void menu(){

			system("cls");    //清屏
			system("mode con cols=150 lines=30");
			system("color f0");//改变控制台前景，背景颜色
			system("title 学生通信录.txt - 伪记事本");
			system("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t date /T");//显示系统当前日期
			system("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t time /T");//显示系统当前时间，\t是没有反应的
			printf("\n\n\n\n\n");
			printf("\t\t\t\t ╭════════════════════════════════════════════════╮\n");
			printf("\t\t\t\t║         〖课题设计：学生通讯录管理系统〗         ║\n");
			printf("\t ╭══════════════════════════════════┤设计时间：2019.3.3 ├═══════════════════════════════════════════════════╮\n");
			printf("\t\t\t\t║   设计人：  2016级工业工程专业 邝伟杜Tridu33     ║                                 \n");
			printf("\t\t\t\t╰ ════════════════════════════════════════════════╯                             \n");
			printf("\t║                                        ★    Menu菜单     ★                                              ║\n");
			printf("\t║---------------------------------------------------------------------------------------------------------- ║\n");


			printf("\t║---------------------------------------------------------------------------------------------------------- ║\n");
			printf("\t║                                    1.读取writetxt                                                         ║\n");
			printf("\t║                                    2.添加input                                                            ║\n");
			printf("\t║                                    3.浏览display                                                          ║\n");
			printf("\t║                                    4.查找search                                                           ║\n");
			printf("\t║                                    5.删除del                                                              ║\n");
			printf("\t║                                    6.修改update                                                           ║\n");
			printf("\t║                                    7.排序sort                                                             ║\n");
			printf("\t║                                    8.保存writetxt                                                         ║\n");
			printf("\t║                                    9.exit退出                                                             ║\n");
			printf("\t║                                    10.完整版吉林大学校歌电话铃声                                          ║\n");
			printf("\t║                                    11.Dos命令输入                                                         ║\n");
			printf("\t║                                    12.关于                                                                ║\n");
			printf("\t║\t     ╭───────────────────────────────────────────────────────────────────────────────╮              ║\n");
			printf("\t╰═══════════┤★★★★★★  欢迎提出您的建议或意见，请发邮件:2055969978@qq.com★★★★★★★  ├══════════════║\n");
			printf("\t\t    ╰────────────────────────────────────────────────────────────────────────────────╯\n\n\n\n");

			printf("\t\t\t请您选择(1-12):\t");	
}
//-------------------------------------------------------------------------
void display(){
	//printf("\n3.浏览display \n");
	FILE *fp;
	int i,j,tel_n=0,count=0;
	fp=fopen("people.txt","rb");
	while(!feof(fp)){
		if(fread(&students[count],LENGTH,1,fp)==1)
			count++;
	}
	fclose(fp);
	for(i=0;i<count;i++){//输出
			printf("\n姓名：%s\t",students[i].name);
			printf("性别：%s\t",students[i].sex);
			for(j=0;j<8;j++)
				if(strcmp(students[i].tel[j],"0")==0){//这里对比strcmp(&students[i].tel[j]
					tel_n=j;	
					break;
				}
				else
					continue;
			for(j=0;j<tel_n;j++)
				printf("%s\t",students[i].tel[j]);
			printf("住址：%s\t",students[i].addr);
			printf("生日：%s\t",students[i].birthday);


	}


};//浏览
//-------------------------------------------------------------------------

void readtxt(){
	printf("1.读取writetxt \n ");
	//这个很迷，下列每个模块都基本要实现这个功能了，单独列在这儿可能是因为我没审对题目。Word文档(可能是为了让我们在其他函数调用它，但是有细微的不一样，还是复制进去写方便些感觉)，那就象征性地表示下吧
	printf("请继续选择其他功能体验。");
	int count=0;
	//文件打开
	FILE *fp;
	if((fp=fopen("people.txt","r+"))==NULL) {//读取
		printf("\n打不开 people.txt");
		return ;
	}
	while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读取文件，结构体数组students
		count++;
	}
	fclose(fp);
	//
		if(count==0){//是否为空
			printf("\n\n通讯录是空的\n");//空文件，没记录
			fclose(fp);
			return;
		}
	display();//
};//信息读取（peopple.txt）



//-------------------------------------------------------------------------
int input(){
	printf("2.添加input\n ");
	int i,count=0;
	int tel_n=0;
	char ch[12];
	//文件打开
	FILE *fp;
	if((fp=fopen("people.txt","a+"))==NULL) {//顺利打开返回地址追加，若不存在新创建打开一个文件进行更新（包括输入和输出），所有输出操作都在文件末尾写入数据。重新定位操作（fseek，fsetpos，rewind）会影响下一个输入操作，但输出操作会将位置移回文件末尾。如果文件不存在，则创建该文件。
		printf("不能打开people.txt");
		return 0;
	}
	while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读文件，结构体数组students
		count++;
	}
	fclose(fp);
	//
	if(count==0)//是否为空
		printf("\n通讯录是空的\n");//空文件，没记录
	else{
		system("cls");
		//printf("display();//子函数，显示文件内容display，显示所有文件名\n");
		display();//子函数，显示文件内容display，显示所有文件名
	};
	//居然因为这一行没注释找半天if的语法错误，向前找找看！远一些bug---------------------------------------
	//
	if((fp=fopen("people.txt","wb"))==NULL)  {	//wb写成wd会死人的。只写write：为输出操作创建一个空文件。如果已存在具有相同名称的文件，则会丢弃其内容，并将该文件视为新的空文件。
		printf("地址列表中找不到，会新建一个文件\n");
		return 0;
	};
	for(i=0;i<count;i++)
		fwrite(&students[i],LENGTH,1,fp);//students[i]打错count的原因已经改正
	//
	printf("\n添加记录吗?(y/n)\n");
	scanf("%s",ch);
	while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0){
		printf("name:");
		scanf("%s",&students[count].name);
		for(i=0;i<count;i++)
			if(strcmp(students[i].name,students[count].name)==0){
				printf("记录已经存在,任意键继续");//跳转修改子函数或者删除原纪录重新写命令
				getch();
				fclose(fp);
				return 0;//关闭文件并且返回
			}
		printf("sex（男/女）:\n");
		char str2[10];
		scanf("%s",str2);//str栈过短会崩溃，13要变长20
		while(1){
			if((strcmp(str2,"男")==0)||(strcmp(str2,"女")==0))
				break;
			else
				{printf("\n请输入（男/女）:\n");scanf("%s",str2);continue;}//str栈过短会崩溃，13要变长20
		}
		strcpy(students[count].sex,str2);
		//printf("telphone:\n");
		//scanf("%s",&students[count].sex);
		printf("最多8个13位telphone:\n");//二维数组多个电话
				for(tel_n=0;tel_n<8;tel_n++){//少了这个{错误就会大错特错	
					printf("@第%d个电话号码（退出请输入0）:\n",(tel_n+1));
					//scanf("%s",students[count].tel[tel_n]);
					//上面这句输入多了12345678912345只会保存1234567892345，因为是char字符，非法电话，过长（丢弃非法部分），过短（不管），中英混合字符，，，等等号码居然也会保存而且闹笑话了，
					//所以要加检测机制，电话字符必须是数字，其他日期格式统一也是同样道理加个约束机制，只举一个例子其他同理可得。
					    char str[20];
						scanf("%s",str);//str栈过短会崩溃，13要变长20
						int flag = 1;
						for( int i = 0; i < strlen(str); i++ ){
							if( str[i] >= '0' && str[i] <='9' )
								if(i<=12)
									continue;
								else{
									flag = 0;
									break;
								}
							else{							
								flag = 0;
								break;
							 }
						 }
						if( flag == 0 ){
							printf("号码过长或只能输入纯数字!\n");//非法输入占位问题
							tel_n--;
							continue;
						}
						else{
							strcpy(students[count].tel[tel_n],str);
						 }
					if(strcmp(students[count].tel[tel_n],"0")==0)
						//
						break;
					else
						continue;
				 }
		printf("address:");
		scanf("%s",&students[count].addr);
		printf("birthday(XXXX-XX-XX):");
		scanf("%s",&students[count].birthday);//存进去数组之后写出来文件中

//--------------------部分下面基本也相同,可以写在保存函数调用，但是有些细节要调整，还不如直接写这儿直观-----------------------------
		if(fwrite(&students[count],LENGTH,1,fp)!=1){
			printf("写入失败!\n");//写入失败
			getch();
		}
		else{
			printf("%s saved\n",students[count].name);//成功写入
			count++;//这个不能直接复制到后面的update函数，i++会和他弄混乱。
		};
		printf("继续输入吗?y/n\n");
		scanf("%s;",&ch);
	}
	fclose(fp);
	printf("OK！");//这里不对，跳出来应该界面继续输入而不是卡死fixed
return 0;
};//添加










//-------------------------------------------------------------------------
int search(){
	int i,count=0;
	int j=0;
	int flag=0;
	int tel_n=0;
	char ch[12],name[15];
	//文件打开
	FILE *fp;
	if((fp=fopen("people.txt","rb"))==NULL) {//读取
		printf("打不开 people.txt");
		return 0;
	}
	while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读取文件，结构体数组students
		count++;
	}
	fclose(fp);
	//
		if(count==0){//是否为空
			printf("通讯录是空的\n");//空文件，没记录
			fclose(fp);
			return 0;
		}
		display();//-------------------------上述部分基本都一样----------------------------------
		printf("\n4.查找search  \n");
		printf("请输入姓名查找(找不到则不做任何反应):\n");
		//其他数据项大同小异，只写这个算了
		scanf("%s",&name);
		for(i=0;i<count;i++){
			if(strcmp(name,students[i].name)==0){
				printf("报告madam，已经找到这条“死鬼”的记录，是否显示具体信息(y/n)");
				scanf("%s",&ch);//对数组来说a数组首元素的地址和&a都指向数组的首地址，这两个地址值上来说一样。scanf("%s",ch);
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0){
					printf("name是:\t\t");
					printf("%s\n",students[i].name);
					printf("sex是%s\n",students[i].sex);
					printf("电话号码如下：\n");
					//printf("地址是%d\n",strcmp(&students[i].tel[j],"0"));//error C2664: “strcmp”: 不能将参数 1 从“char (*)[13]”转换为“const char *”
					for(j=0;j<8;j++){
						if(students[i].tel[j][0]=='0')//!=才对有检查半天if(students[i].tel[3][0]=='0')printf("Tridu第4个位置的首字母结束符号\n");
						//if(strcmp(&students[i].tel[j][0],'0')!=0)//!=才对，==不对！！这里教会我用步进调试错误和看局部变量来学习数据结构！！！不能用来比较字符串//students[i].tel[i][j]改成&students[i].tel[i][j]，string你这里应该定义的是 char str1;strcmp 方法要的是 指针型 类型不符合//https://blog.csdn.net/sinat_31586167/article/details/48844899
						flag=j;
						else
							continue;
					};
					for(j=0;j<flag;j++){
					printf("第%d个号码是：%s\n",j+1,students[i].tel[j]);
					};
					printf("地址是%s\n",students[i].addr);
					printf("生日是%s\n",students[i].birthday);
			      }
				else
					printf("好的，您只是想知道有没有他电话号码而暂时不想打给他吧？OK。任意键继续");
					system("pause");
			 }
				//else
				//这两句不会被执行，要做到找不到就提出来
				//continue;
		}
return 0;
};	//查找


//-------------------------------------------------------------------------

void del(){
		int flag=0;
		printf("5.删除del\n ");
		int i,j,count=0;
		char ch[12],name[15];
		//文件打开
		FILE *fp;
		if((fp=fopen("people.txt","rb"))==NULL) {//读取
			printf("打不开 people.txt");
			return ;
		}
		while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
			if(fread(&students[count],LENGTH,1,fp)==1)//一一读取文件，结构体数组students
			count++;
		}
		fclose(fp);
		//
		if(count==0){//是否为空
			printf("通讯录是空的\n");//空文件，没记录
			fclose(fp);
			return;
		}
		display();//-------------------------上述部分基本都一样----------------------------------
		printf("\n请输入要删除的姓名:\n");
		//其他数据项大同小异，只写这个算了
		scanf("%s",&name);
		for(i=0;i<count;i++){
			if(strcmp(name,students[i].name)==0){
				//printf("是否删除具体信息(y/n)");
				//scanf("%s",&ch);
				strcpy(ch, "Y");//想了想，上面两行这个功能有点多余，n时也要跳出
				if(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)
					for(j=i;j<count;j++)
						students[j]=students[j+1];
				count--;//这里的可空格位置很重要，代表不再for上的思考思路
				if((fp=fopen("people.txt","wb"))==NULL){
					printf("不能打开文件");
					return;
				}
				for(j=0;j<count;j++)
					if(fwrite(&students[j],LENGTH,1,fp)!=1){
						printf("不能保存");
						getch();
					}
				fclose(fp);
				printf("成功删除！\n");
				display();
				return;

			}
		}
		printf("你怕不是在逗我，找不到该联系人信息。\n");
		display();
		

};//删除
//-------------------------------------------------------------------------
void update(){
printf("6.修改update\n ");
	int i,j,tel_n,count=0;
	char name[15];
	//文件打开
	FILE *fp;
	if((fp=fopen("people.txt","r+"))==NULL) {//读取
		printf("打不开 people.txt");
		return ;
	}
	while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读取文件，结构体数组students
		count++;
	}
	fclose(fp);
	//
	if(count==0){//是否为空
		printf("通讯录是空的\n");//空文件，没记录
		fclose(fp);
		return;
	}
	display();//
	printf("\n请输入要修改的联系人的名字:\t\t");
	scanf("%s",&name);//死机C语言程序，https://zhidao.baidu.com/question/981987125670820219.html 这样写书上说危险，会死机！这是为什么？？char *str；scanf(“％s”,str)；求解释为什么危险？？？
	for(i=0;i<count;i++){
		if(strcmp(name,students[i].name)==0){//匹配上的姓名？如果有两个同名同性？
			printf("请输入修改后的联系人的名字:\t\t");
			scanf("%s",&students[i].name);//scanf("%s\n",students[i].name);我居然写成这样也不报错就是运行不了，幸好发现早
			printf("性别(男/女):\n");
			char str2[10];
			scanf("%s",str2);//str栈过短会崩溃，13要变长20
			while(1){
				if((strcmp(str2,"男")==0)||(strcmp(str2,"女")==0))
					break;
				else
					{printf("\n请输入（男/女）:\n");scanf("%s",str2);continue;}//str栈过短会崩溃，13要变长20
			}
			strcpy(students[i].sex,str2);
			printf("电话号码");
			printf("最多8个13位telphone:\n");//二维数组多个电话
			for(tel_n=0;tel_n<8;tel_n++){//，循环写入电话号码。少了这个{错误就会大错特错	
				printf("@第%d个电话号码（退出请输入0）:\n",(tel_n+1));
					
				//scanf("%s",students[count].tel[tel_n]);
				//上面这句输入多了12345678912345只会保存1234567892345，因为是char字符，非法电话，过长（丢弃非法部分），过短（不管），中英混合字符，，，等等号码居然也会保存而且闹笑话了，
				//所以要加检测机制，电话字符必须是数字，其他日期格式统一也是同样道理加个约束机制，只举一个例子其他同理可得。
					char str[20];
					scanf("%s",str);//str栈过短会崩溃，13要变长20
					int flag = 1;
					for( int k = 0; k < strlen(str); k++ ){//是否数字字符串
						if( str[k] >= '0' && str[k] <='9' )
							if(k<=12)
								continue;
							else{
								flag = 0;
								break;
								}
							else{							
							flag = 0;
							break;
							}
					}
					if( flag == 0 ){
							printf("号码过长或只能输入纯数字!\n");//非法输入占位问题
							tel_n--;
							continue;
					}
					else{
						strcpy(students[i].tel[tel_n],str);//i	
					if(strcmp(students[i].tel[tel_n],"0")==0)//i
							break;
					else
							continue;
					}
			}//for循环的写入电话号码

				printf("地址:\n");
				//fflush(stdin);//？？？？？？？？？？？？？？？清空输入缓存.在上一次使用scanf后没有清空输入缓存, 这样你再次使用scanf的时候函数就可能会认为你已经输入过了. 改进的办法很简单, 就是在scanf语句之前使用fflush();
				//scanf_s("%s",students[i].addr);//scanf_s("%s",&students[i].addr;)这句运行就死机不知道为什么https://ask.csdn.net/questions/326768
				char str4[30];
				scanf("%s",str4);
				strcpy(students[i].addr,str4);
				printf("生日:\n");
				//scanf_s("%s",&students[i].birthday);
				char str5[20];
				scanf("%s",str5);
				strcpy(students[i].addr,str5);
		}//if的
//跳过上面的输入的原因是？

	}//for
		if((fp=fopen("people.txt","wb"))==NULL)  {	//wb写成wd会死人的。只 写write：为输出操作创建一个空文件。如果已存在具有相同名称的文件，则会丢弃其内容，并将该文件视为新的空文件。
			printf("找不到，会新建一个文件\n");
			return;
		};
		for(j=0;j<count;j++)
			if(fwrite(&students[j],LENGTH,1,fp)!=1){
				printf("can not save the record!\n");//写入失败
				getch();
			}
			//else{
			//	printf("%s saved\n",name);//成功写入
			//	i次，没意义++;//写成count++死循环
			//	display();
			//};会执行count
		fclose(fp);
		return;
			
		//printf("没您想要的人，可以扣2添加记录！");
	};////for修改,？有空有心情补充修改后名字是否相同，姓名代号等长度地址是否乱填



//-------------------------------------------------------------------------

void sort(){
	printf("7.排序sort \n");
	FILE *fp;
	struct student t;
	int i=0,j=0,count=0;
	//文件打开
	if((fp=fopen("people.txt","r+"))==NULL) {
		printf("不能打开people.txt");
		return;
	}
	while(!feof(fp))//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读文件，结构体数组students
		count++;
	fclose(fp);
	//
	if(count==0)//是否为空
		printf("通讯录是空的\n");//空文件，没记录
	else{
		system("cls");
		//printf("display();//子函数，显示文件内容display，显示所有文件名\n");
		display();//子函数，显示文件内容display，显示所有文件名
	}
	for(i=0;i<count-1;i++)
		for(j=i+1;j<count;j++)//脑子被狗吃了，i++死循环
			if(strcmp(students[i].name,students[j].name)>0){//冒泡排序,ACIL码，相等0；i>j返回正数，<返回负数
				t=students[i];
				students[i]=students[j];
				students[j]=t;
			};
	if((fp=fopen("people.txt","wb"))==NULL){  
		//		fopen 返回	0x5c47f4f8 {_ptr=0x00000000 <错误的指针> _cnt=0 _base=0x00000000 <错误的指针> ...}	_iobuf *
		printf("地址列表中找不到，会新建一个文件\n");
		return;
	};
	for(i=0;i<count;i++)
		if(fwrite(&students[i],LENGTH,1,fp)!=1){//不是students[count]
			printf("不能成功保存!\n");//写入失败
			getch();
		}
	fclose(fp);
	printf("\nSaved!\n");
	display();
};//排序

//-------------------------------------------------------------------------

void writetxt(){
	printf("8.保存writetxt成功！\n修改删除添加，每个模块都要用这个写入功能，既然Word里面有要求这个模块就在菜单列出来吧。\n\n");
		int count=0;
	//文件打开
	FILE *fp;
	if((fp=fopen("people.txt","r+"))==NULL) {//读取
		printf("\n打不开 people.txt");
		return ;
	}
	while(!feof(fp)){//EOF结束标志，是文件检测流上的文件结束符，如果文件结束，则返回非0值，否则返回0（即，文件结束符：返回非0值，文件未结束，返回0值），文件结束符只能被clearerr()清除
		if(fread(&students[count],LENGTH,1,fp)==1)//一一读取文件，结构体数组students
		count++;
	}
	fclose(fp);
	//
		if(count==0){//是否为空
			printf("通讯录是空的\n");//空文件，没记录
			fclose(fp);
			return;
		}
	display();//
};//保存通讯录信息（people.txt）

//-------------------------------------------------------------------------

void schoolsong(){
		//以下谱子，正是《吉林大学校歌》的一段C++程序乐曲部分
PU t[]={E6,4,C6,2,D6,1,E6,2,E6,6,
	F6,4,D6,3,E6,1,F6,2,F6,6,
	G6,2,E6,1,F6,2,G6,4,G6,2,F6,6,
	E6,8,D6,4,G6,4,
	C6,8,G5,8,
	E5,4,F5,4,G5,8,
	F5,4,D5,2,E5,2,F5,4,A5,4,
	G5,16,
	C6,6,D6,2,E6,4,C6,2,C6,2,
	G5,4,G5,2,F6,1,E5,4,G5,4,
	D5,4,D5,2,E5,2,F5,4,A5,4,
	A5,16,
	G5,4,C6,2,D6,1,E6,8,
	E6,4,D6,2,C6,2,A5,6,A5,2,
	A5,4,F6,4,F6,4,E6,2,D6,2,
	E6,16,
	A5,4,A5,4,D6,4,D6,2,D6,1,
	E6,4,F6,4,G6,4,C6,1,C6,1,
	D6,4,C6,2,C6,1,B5,4,A5,4,
	G5,16,

	G6,4,E6,2,F6,1,G6,2,G6,6,
	F6,4,D6,2,E6,1,F6,2,F6,6,
	E6,4,C6,2,D6,1,E6,2,E6,2,E6,2,A5,2,
	A5,4,B5,2,C6,2,E6,4,D6,2,D6,1,
	D6,2,E6,2,D6,16,

	G6,4,E6,2,F6,1,G6,2,G6,6,
	F6,4,D6,2,E6,1,F6,2,F6,6,
	E6,4,C6,2,D6,1,E6,2,E6,2,E6,2,A5,2,
	A5,4,B5,2,C6,2,E6,4,D6,2,D6,1,
	D6,2,D6,2,G6,16,

	G6,2,G6,2,F6,8,E6,24,
	D6,2,E6,6,E6,8,
	C6,32,
};
    int i;
    //结构体数组的长度sizeof(t)/sizeof(PU)得到，总结构体数组大小 / 单个结构体大小
    for (i=0; i<sizeof(t)/sizeof(PU); i++)
        Beep(t[i].frequency,t[i].duration*P);
};//bell beep music吉林大学校歌C语言版铃声
/*本人精通面向佛系的编程语言，有空交流

                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
               佛祖保佑         永无BUG
*/
///////////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[]){
	int c;
	int flag1;
    char name[20]="JLU";
    char person[20];
	char ch[7];
	int i,n;
	system("color 0f");//改变控制台前景，背景颜色
	system("title 学生通信录");

			char uerInputData[2][100]={"欢迎使用学生通讯录管理系统。","通讯录电话铃声"};
			int welcome=0;
			while(1){
					FILE *pFile = fopen("voice.vbs","w");//msgbox"自"//CreateObject("SAPI.SpVoice").Speak"能"//CreatObject("SAPI.SpVoice").Speak+"User_Input";
					fprintf(pFile,"CreateObject(\"SAPI.SpVoice\").Speak\"%s\"",uerInputData[welcome++]);//fprintf(pFile,"msgbox(\"%s\")",uerInputData[i++]);//main(1)函数外只能定义全局变量或者对象，而不能执行语句及调用函数。//cmd system
					fclose(pFile);
					system("voice.vbs");//run vbs
					system("del voice.vbs");//del vbs
					if(welcome<2)
						continue;
					else 
						break;
			}
			//通讯录电话铃声 
			int j;
			//结构体数组的长度sizeof(t)/sizeof(PU)得到，总结构体数组大小 / 单个结构体大小
			for (j=0; j<sizeof(a)/sizeof(PU); j++)
			Beep(a[j].frequency,a[j].duration*P);	

	HANDLE hOut;  

    //  获取输出流的句柄
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);    
	printf("\t\t");
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_RED |        // 前景色_红色
                            FOREGROUND_INTENSITY |  // 前景色_加强
                            BACKGROUND_BLUE );      // 背景色_蓝色
	//设置文字红色，背景蓝色  
	printf (" **********通讯录管理系统！**********\n\n");
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_RED |    // 前景色_红色
                            FOREGROUND_GREEN |  // 前景色_绿色
                            FOREGROUND_BLUE );  // 前景色_蓝色
	//三原色改回白色
    printf("\t\t\t\t");
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_BLUE |       // 前景色_蓝色
                            FOREGROUND_INTENSITY |  // 前景色_加强
                            COMMON_LVB_UNDERSCORE); // 添加下划线
	//文字蓝色，再加个下划线  
	printf ("用 户 登 录 \n\n");
    SetConsoleTextAttribute(hOut,  
                            FOREGROUND_RED |    // 前景色_红色
                            FOREGROUND_GREEN |  // 前景色_绿色
                            FOREGROUND_BLUE );  // 前景色_蓝色
	//三原色改回白色
    printf("\t\t\t username:");
    gets(person);
    flag1=strcmp(person,name);
    printf("\t\t\t password:");
	for(i=0;i<3;i++){
		for(n=0;n<6;n++){
			ch[n] = getch();
			printf("*");
		}
		printf("\n");
		ch[n] = '\0';
		if(0 == strcmp(ch,"201612")){
			menu();
			scanf_s("%d",&c);
			printf("%d",&c);
			while(c){
					switch(c){
						case 1: readtxt(); break;
						case 2: input(); break;
						case 3: display(); break;
						case 4: search(); break;
						case 5: del(); break;
						case 6: update(); break;
						case 7: sort(); break;
						case 8: writetxt(); break;
						case 9: return 0;
						case 10: schoolsong(); break;
						case 11: cmd();break;
						case 12: showtxt();break;
						default:  printf("该编号的新功能有待开发中..."); break;
						}; 		
					_getch();//会等待你按下任意键，再继续执行下面的语句
					menu();
					scanf_s("%d",&c);//可以换成scanf_s("%d",&n);'scanf': This function or variable may be unsafe. 		
			};
		}
        else{
            printf("密码错误,请重新输入\n");
        }
	}
	if(i==3){
        printf("你输入的错误的密码次数达到上限，系统自动退出！请联系管理员！");
		system("pause");
        exit(1);
    }
return 0;
}


    ///////////   //                                       //    //
       //        //                                       //   //
      //        ////////     ////////      /////////     //  //        //////
     //        //     //    //     //     //      //    /////        //     
    //        //     //    //     //     //      //    //  //          ////
   //        //     //    //     //     //      //    //     //            //
  //        //     //     ///////////  //      //    //        //   //////
/////////////////////////////////////////////////////////////////////////////////////////////
	  

