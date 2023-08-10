## 基本命令和开发工具

#### 基本指令

添加用户

```c++
adduser name//新建
passwd name//设置密码..确认密码..修改密码
```

##### ls指令

```c++
展示当前路径下的文件/目录
参数：
-a 展示所有文件/目录， 包括隐藏信息
-l 展示文件的所有信息
```
##### uname -r

```
//输出内核版本信息
```

##### pwd

```
pwd //查看当前绝对路径
```

##### touch：创建普通文件

```
touch name//文件名
-a name//更新文件最近修改时间为现在
```

##### mkdir：创建目录

```
mkdir name//目录名
mkdir -p name1/name2/.. //创建多级目录
```

##### rmdir：删除空目录

```
name//删除空目录
```

##### rm：删除目录/文件

```
name//删除空目录
-r name//递归删除目录，有询问
-rf //强制删除
```

##### cd：进入指定目录

```
cd - ：回到上次目录
cd ~ ： 进入用户名录
cd / ： 回到根目录
cd . ： 进入当前目录
cd .. : 进入上级目录
```

##### 绝对路径、相对路径

~~~C++
绝对路径：相对于根目录的路径
相对路径：相对于父目录的路径
~~~

##### * ：通配符

```
一种通配结构
```

##### man ：参考手册

```
Linux指令
语言函数
```

##### copy ：拷贝

```
cp 文件 目录//将某个文件拷贝至另一个目录
cp -rf //递归拷贝， 可拷贝目录
cp 文件 新名字//备份至原目录
```

##### mv ：移动

```
mv 文件/目录 新名字//文件/目录重命名
mv 文件/目录 目录//将文件剪切到指定目录
```

##### cat ：打印文件内容，多与其他命令符合使用

```
cat 文件//打印出文件内容
tac 文件//以行为单位，逆向打印
cat < 文件名//输入重定向，从文件中读取（与cat 文件有区别）
//若不加文件名，从键盘中读取并打印
-n //显示行号
```

##### echo ：

```
echo "字符串"//打印到屏幕
echo "字符串" > 文件名//输出重定向，清空文件并写到文件中，若不存在，创建文件
echo "字符串" >> 文件名//追加重定向，写到文件中，不清空
```

代码

```
count=0; while [ $count -le 10000 ]; do echo "hello bit ${count}"; let count++; done > file.txt
```

##### 显示文本内容

###### more

```
more 文件//显示文件内容，可下翻(空格/回车)
more -n 文件//一次显示前n行，可继续翻阅
```

###### less

```
less 文件//可上下翻阅(不是鼠标滚轮上下, 好像是又打印一次)
```

###### head

默认显示前十行文本内容

```c++
-n//显示前n行
```

###### tail

默认显示后十行文本内容

```
-n//显示后n行
```

##### | ：管道

```
管道左边产生数据，通过管道"|"传给右边进行操作，可叠加
eg ：head -1010 文件 | tail -10 | head -1//打印第1000行
```

##### Linux下一切皆文件

##### date ：时间指令

```
date +%Y:%m:%d//年月日
date +%H:%M:%S//时分秒
date +%s//打印时间戳
```

##### cal ：日历指令

```
cal -月份 年份//显示某月的日历
cal -年份//显示某年
cal//默认显示前中后月份
```

##### find ：查找指定信息

```
find 搜索路径 -name 信息//(name是参数, 替换的是信息)
```

##### which ：查找指令安装路径

```
which 系统指令//在系统路径中找到指令的安装路径
```

##### whereis ：查找路径

```
whereis name//查找除了指令的路径外，所有带name的路径
```

##### alias ：起别名

```
alias 别名='原名' //需严格格式
alias 别名//查看时谁的别名
//有效期，一次登录时间
unalias 别名//删除别名
```

##### grep ： 行文本过滤，显示文件中存在指定内容的行

```c++
grep '内容' 文件//显示存在指定内容的行
-n//显示行号
-v//显示不存在指定内容的行
-i//忽略大小写
```

##### xargs ：将文本内容作为命令行参数

```
echo "-l -a -i" | ls//ls接受，但不理会
echo "-l -a -i" | xargs ls//将管道的输出结果作为命令行参数交给后边程序
```

##### zip/unzio ：压缩/解压

```
zip 压缩文件名 待压缩文件//压缩文件
zip -r 压缩目录名 待压缩目录//压缩整个目录
unzip 待解压文件//默认解压至当前文件夹
unzio 代解压文件 -d 指定路径//解压至指定路径
```

##### tar ：解压/压缩

```
tar 参数 压缩文件名 （待压缩文件/目录）
tar 参数 待解压文件 （-C 指定路径）
-czf//压缩并打包，后缀 .tgz
-xzf//解压
-v//显示压缩/解压过程
-t//显示tar压缩包的内容
-C //
```

##### bc ：计算器（浮点级）

```
quit 退出指令
```

##### uname ：查询操作系统信息

```
-a//查询体系结构
-r//查询内核版本
```

##### 常用热键

```
↑ ↓ ：历史命令
Tab键 ：自动补全命令
^C ：终止当前程序或操作
^D ：退出当前用户
^r ：搜索历史命令/输入记录
```

##### shutdown ：关机

```
-h 立即关机
-r 重新启动
-r sec 延迟sec秒关机
```

##### shell运行原理：外壳程序--指令操作/图形化界面

Linux用的外壳程序是bash

```
1.是用户和操作系统交互的中间软件层
2.可以在一定程度上，起到保护操作系统的坐拥
使用者 通过中间程序shell 和操作系统相联系
shell接受到指令后，如果安全无害，传递给操作系统
操作系统将结果交给shell，shell再反馈给用户
```

##### su ：切换用户

```
su username
输入用户密码
root切普通用户，不需要密码
```

##### 文件类型：

```
在Linux中，文件类型与后缀无关，只有属性能决定其文件类型
-:普通文件，文本，可执行程序等
d:目录
C:字符文件，键盘，显示器
l:链接文件
```

##### 文件权限：

```
r:读取，浏览
W:写入，移动，删除，创建
X:可执行，进入目录
-rwxrwxr-x：拥有者可读写执行，所属组可读写执行，其他可读执行不能写
root不受权限限制
```

##### chmod：权限操作

```
chmod更改权限：+添加权限 -删除权限 u拥有者 g所属组 o其他 a所有人
chmod u-w,g-x,o+r 文件//可多组操作 
9位字母3个为一组，有对应权限为1，没有则0，则转换成8进制，可唯一代表一个权限组合
```

##### chown：更改所有者

```
//更改文件拥有者和所属组 ---- 需要root权限 sudo
chown 更改后u 文件//更改拥有者
chgrp 更改后g 文件//更改所属组
chown 更改后u : 更改后g 目标文件//更改拥有者所属组
```

##### sudo：提升权限

```
提升某条指令的权限为root权限
```

##### 拥有者/所属组/其他

```
权限只被认证一次，从左至右依次辨别
若一个人为拥有者无对应权限，但其所属组有，则其不能对文件操作
因为权限只认证一次，为拥有者权限
```

##### 实际权限：默认权限 &（~ umask）

```
Linux默认：
目录被创建时，起始权限为777
文件被创建时，起始权限为666
umask：
umask展示的权限都不应该在最终实际权限中出现
最终实际权限 = 默认权限 & (~umask)
```

##### 粘滞位

```
若用户具有目录的写权限，则用户可以删除目录或目录内容。
如果对目录添加粘滞位，可避免目录内容被其他用户删除
chmod +t 目录//添加粘滞位//谁设置的谁取消
若目录属于你，删除目录下其他人的文件，不会被粘滞位约束
则1.root用户，2.目录所有者。可删除目录及目录所有内容
  3.文件所有者，可删除自己创建的文件
```

##### ACM时间:

![1658912909313](C:\Users\41525\AppData\Roaming\Typora\typora-user-images\1658912909313.png)

#### 重点

> - Linux下一切皆文件
> - 重定向
> - 管道文件 |
> - 权限：文件权限/用户权限

补充

> - 目录权限
> - 粘滞位
> - umask-默认权限

#### 基础开发工具

##### VIM：

**多模式的文本编辑器**

三种模式

```
1. 命令模式，默认打开模式，只辨别接受有效命令
2. 插入模式，文本编辑
3. 底行模式，一些操作
```

命令模式

```
--------转插入模式：
i：直接进入
o：新起一行进入
a：移动一位光标进入
--------移动光标：
↓↑→←：对应符合操作//hjkl（左下上右）对应箭头朝向
shift+6(^)：移动到行首
shift+4($)：移动到行尾
ctrl+g：显示行号
gg：移动到文首
shift+g(G)：文尾
n+G：移动到指定行
--------翻页
ctrl + b：往上一页
+f：往下一页
+u： 往上半页
+d：往下半页
--------以字为单位移动
//hello world!!!//目前光标位于h
w：移动到下个字的开头 //移动到w
e：移动到下个字的字尾(若不在自身字尾，需要移动到自身字尾) //移动到o，然后再e一次到d
b：移动到上个字开头（先回到自身开头）
nl：移动到光标所在行的光标后的第n个位置//3l，移动到l
--------撤销&反撤销
u：撤销
ctrl+r(R)：取消撤销
--------删除文字
x：删除光标所在字符
nx：删除光标及其后共n个字符（包括自己
shift+x(X)：删除光标所在位置前一个
nX：删除光标前共n个字符（不包过自己
dd：删除光标所在行
ndd：删除所在行及其后共n行（包括自己
--------复制&粘贴
yw：光标到字尾的字符复制到缓冲区
nyw：复制n个“字”到缓冲区
yy：复制光标所在行
nyy：复制所在行及其后共n行（包括自己
p：粘贴
npp：粘贴n次
--------替换
shift+~：大小写切换
r：单次替换，替换光标所在位置字符
shift+r(R):替换模式，替换光标所在处，ESC结束
--------更改
cw：更改光标所在字到字尾处
cnw：更改n个字
```

底行模式

```
q：退出
！：强制退出
w：保存
！+命令：在不退出vim情况下，执行Linux命令
set no/nonu：显示行号/取消显示
n+回车：跳到第n行
--------分屏
vs 文件名//另开一屏，显示新文件内容，若文件不存在，创建
```

VIM“注释”多行

> - esc进入命令模式
> - ctrl+v进入可视块模式
> - 用方向键hjkl选择注释内容
> - shift+i进入插入模式
> - 这时候会跳转到第一行注释的首部，输入注释符号
> - esc退出，完成注释

##### GCC

参数

```
gcc -o//给生成的文件重命名
-E//生成预处理之后的文件
-S//生成编译之后的文件.i
-c//生成汇编之后的文件.o
gcc //链接成可执行文件
-static//表明使用静态链接的方式形成可执行程序
```

动态/静态链接

```
静态链接:将库方法的实现,拷贝到可执行程序中,使可执行程序不依赖外部执行//使用.a静态库文件
动态链接:将库方法的地址,填入到可执行程序中,实现关联//使用.so动态库文件
gcc, g++默认使用动态链接，release版本，不能被调试，-g选项为debug版本
sudo yum install -y glibc-static //c静态库
sudo yum install -y libstdc++-static//c++静态库
```

make/makefile

```
make是一个命令, 调用makefile文件
makefile是一个文件
makefile存在两个成员: a.依赖关系, b. 依赖方法
makefile自上至下依次扫描并执行第一个依赖
make + 依赖name, 执行指定依赖关系
.PHONTY//其修饰的依赖,总是被执行,即总是会根据依赖关系,执行依赖方法
makefile可以简化命令, 使生成, 清理, 等命令变得便捷
```

##### yum

yum源的配置

~~~
阿里源
腾讯源
~~~

三板斧

```
1. 查找 
yum list | grep name//查找软件
2. 安装
yum install 软件// -y直接同意所有问题, 不需要询问 
3. 卸载
yum remove 软件
```

小软件

```
links 网站//可访问网站
```

##### git三板斧

```
git add 文件//添加代码到我们的本地仓库
git commit -m "日志信息"//日志,提交到本地仓库
git push//推送到gitee
```

##### gdp调试器

**gdb调试器是一个软件工具，需要下载**

**预处理——编译——汇编——链接**

动态/静态链接

~~~C++
动态库 .so --- 动态链接 --- 默认动态链接
静态库 .a  --- 静态链接 --- static转为静态链接
~~~

调试指令：

```
gcc/g++默认形成的可执行程序为release版本, 无法直接被调试
-g//转换成debug版本, 需要加-g选项
----=-==-=-=-=-==-=-=-=-=-=-=-==-
l n //从第n行开始显示代码
回车 //执行上一条历史命令
quit //退出gdb
r //开始调试, 若没有设置断点, 运行结束
b + 行号 //给特定行打断点
info b //查看断点
d + 断点编号 //删除指定编号的断点
p 变量 // 打印/查看变量的值
bt //查看当前的调用堆栈
n //逐过程调试
s //逐语句调试
finish//跑完当前函数就停止运行
display 变量 //设置长显示, 将某个变量一直显示值
undisplay 编号 //取消编号对应的变量的长显示
until 行号 //跳转到指定行
c //运行至下一个断点处停下来
disable 断点编号 //关闭某个断点
enable 断点编号 //打开某个断点
```

### make/makefile

## 进程概念

### 基本概念

> **进程 = 描述进程的PCB + 进程的代码和数据**
>
> **先描述再组织**

#### 操作系统

**操作系统是一种系统软件, 直接运行在硬件上的软件, 对下, 管理调用硬件资源, 对上, 提供一些系统接口供用户使用, 调用特定的硬件资源.**

**操作系统提供的接口叫做系统调用, 由于使用系统调用的要求较高, 又对系统调用进行了适度封装, 形成库, 使用库更利于使用者操作.**

**用户并不能直接与操作系统交互, 而是与一个中间程序shell外壳交互, shell外壳只会将合理的用户操作转交给操作系统, 不合理的舍弃.**

**shell外壳又会给每个用户指定一个代理程序, 来负责对应的用户操作.**

**操作系统管理硬件资源的方式, 是先描述, 再组织. 将硬件资源属性抽象到struct 中, 再用其他的数据结构方法将这些属性组织起来, 进行高效操作, 从管理硬件资源 到 管理这些数据结构**

#### 描述进程-PCB （process control block）

进程信息被放在一个叫做**进程控制块的数据结构**中，可以理解为进程属性的集合，课本上称之为PCB（process control block）。

Linux操作系统下的PCB是: task_struct

task_struct基本内容:

> - **标示符**: 描述本进程的唯一标示符，用来区别其他进程。
>
> - **状态**: 任务状态，退出代码，退出信号等。
>
> - 优先级: 相对于其他进程的优先级。
>
> - 程序计数器: 程序中即将被执行的下一条指令的地址。
>
> - 内存指针: 包括程序代码和进程相关数据的指针，还有和其他进程共享的内存块的指针
>
> - **上下文数据**: 进程执行时处理器的寄存器中的数据[休学例子，要加图CPU，寄存器]。
>
> - I／O状态信息: 包括显示的I/O请求,分配给进程的I／O设备和被进程使用的文件列表。
>
> - 记账信息: 可能包括处理器时间总和，使用的时钟数总和，时间限制，记账号等。
>     其他信息

#### 进程相关指令

##### 查看系统进程属性

1. ps

  ~~~
  ps -l //显示当前系统进程信息
  ps axj //查看所有进程
  ps axj | grep 'name' //查看指定进程
  ~~~

2. ls /proc

  ~~~
  显示系统进程文件里的信息
  ls /proc | grep '进程id'
  ls /proc/进程id //显示指定进程的属性
  ~~~

##### 查看进程id

> `pid_t getpid()`可查看当前进程id
>
> `<sys/types.h> `&&` <unistd.h>`  头文件
>
> `pid_t getppid()` 查看父进程id

> - 进程id（PID） 
> - 父进程id（PPID）

~~~c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 printf("pid: %d\n", getpid());
 printf("ppid: %d\n", getppid());
 return 0;
}
~~~



#### 杀掉进程

```
kill -9 pid//结束指定进程
```

#### fork--创建子进程

> pid_t fork() //创建子进程--头文件<unistd.h>

1. 返回值--fork() 有两个返回值!!!

    > 失败: 返回-1
    >
    > 成功: 
    >
    > - 给父进程返回子进程的pid 
    > - 给子进程返回0
    >
    > 原因: 在fork()函数内部, 具有创建子进程的逻辑代码, 在创建完成后, 就会共享代码, 所以父子进程各自执行了一个return

2. fork()之后, 代码共享

    > 可以通过父进程子进程得到的不同返回值, 执行不同的代码段

3. 父子进程的运行状态, 由操作系统调度算法负责

4. 给父进程返回子进程的pid，父进程就可以保存这个pid，标识该子进程；给子进程返回0

    > 因为子进程是在父进程中创建的，知道父进程pid，不需要额外获取。

eg:

~~~C
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 int ret = fork();
 printf("hello proc : %d!, ret: %d\n", getpid(), ret);
 sleep(1);
 return 0;
}
~~~

**fork 之后通常要用 if 进行分流**

~~~C
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
 int ret = fork();
 if(ret < 0){
 perror("fork");
 return 1;
 }
 else if(ret == 0){ //child
 printf("I am child : %d!, ret: %d\n", getpid(), ret);
 }else{ //father
 printf("I am father : %d!, ret: %d\n", getpid(), ret);
 }
 sleep(1);
 return 0;
}
~~~

#### 进程状态概述

> ps aux / ps axj 命令

##### OS状态

> **新建**: 刚创建出对应的结构体，还未分配资源。
>
> **运行**: task_struct结构体 **在 运行队列(调度队列)中排队, 就叫运行态，不一定在运行**。
>
> **阻塞**: 等待非CPU资源就绪, 就是阻塞,如IO资源。
>
> **挂起**: 当内存不足时, 操作系统会将长时间不运行的进程的代码和数据转移到的磁盘(SWAP区), 此时就是挂起态. 若挂起态进程需要运行, 首先需要将代码数据移回来。
>
> **挂起阻塞**: 阻塞时, 变为挂起态, 省空间。

##### Linux进程状态

> - "+"--代表进程为前台进程, 可以输入输出,可以被^C终止
>
>     > ./a.out &, 运行时加上&, 代表以后台进程运行, 不能被^C终止, 需要kill -9命令终
>
> - R--运行态
>
>     > 正在被执行或正在运行队列中
>
> - S--浅睡眠态(阻塞态)
>
>     > 等待某种非CPU资源完成, 也叫做可中断睡眠, 即可以强制唤醒该进程, 即使没有等到需要的资源, 也可以终止杀掉该进程
>
> - D--深睡眠态(磁盘睡眠)
>
>     > 深度睡眠, 不可被中断, 不可被唤醒, 必须得到需要的东西自己醒过来, 即使kill -9也需要进程醒来才行。[dd命令, 能演示D状态进程]
>
> - T--调试状态/暂停状态 
>
>     > kill -19 pid 可暂停某个进程
>     >
>     > kill -18 可继续某个暂停进程
>
> - X--终止状态 
>
>     > 代表该进程可以被回收清除
>
> - Z--僵尸状态 
>
>     > 进程已经退出(完成任务), 释放了所有资源, 但保留了一定的信息, 等待检测. 
>     >
>     > 产生该状态进程, 是为了让父进程/OS检查之后回收.

##### 僵尸进程

> **一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中（资源已经释放），这种进程称之为僵尸进程。**
>
> fork之后的子进程自然是和普通进程一样拥有它独立的地址空间。但是这么做效率低下，所以大部分操作系统都用到了"**写时拷贝**"来完成子进程创建，如果没有写操作，则不构造新的地址空间，只有PCB。

> - 僵死状态（Zombies）是一个比较特殊的状态。当进程退出并且父进程（使用wait()系统调用,后面讲） 没有读取到子进程退出的返回代码时就会产生僵死(尸)进程 。
> - 僵死进程会以终止状态保持在进程表中，并且会一直在等待父进程读取退出状态代码。 
> - 所以，只要子进程退出，父进程还在运行，但父进程没有读取子进程状态，子进程就进入Z状态。

eg：30秒僵尸态

~~~C
#include <stdio.h>
#include <stdlib.h>
int main()
{
 pid_t id = fork();
 if(id < 0){
 perror("fork");
 return 1;
     }
 else if(id > 0){ //parent
 printf("parent[%d] is sleeping...\n", getpid());
 sleep(30);
 }else{
 printf("child[%d] is begin Z...\n", getpid());
 sleep(5);
 exit(EXIT_SUCCESS);
 }
 return 0;
}
~~~

僵尸进程的危害

> - 进程的退出状态必须被维持下去，因为他要告诉关心它的进程（父进程），你交给我的任务，我办的怎么样了。可父进程如果一直不读取，那子进程就一直处于Z状态。 
> - 维护退出状态本身就是要用数据维护，也属于进程基本信息，所以保存在task_struct(PCB)中，换句话说，Z状态一直不退出，PCB一直都要维护。 
> - 那一个父进程创建了很多子进程，不回收子进程，就会造成内存资源的浪费。因为数据结构对象本身就要占用内存，类似C中定义一个结构体变量（对象），是要在内存的某个位置进行开辟空间。
> - 内存泄漏

##### 孤儿进程

> - 父进程如果提前退出，那么子进程后退出，进入Z之后，那该如何处理呢？ 
> - 父进程先退出，子进程就称之为“孤儿进程” 。
> - 孤儿进程被1号init进程领养，init进程回收。

**code:**

~~~C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
 pid_t id = fork();
 if(id < 0){
 perror("fork");
 return 1;
 }
 else if(id == 0){//child
 printf("I am child, pid : %d\n", getpid());
 sleep(10);
 }else{//parent
 printf("I am parent, pid: %d\n", getpid());
 sleep(3);
 exit(0);
 }
 return 0;
}
~~~

#### 进程优先级

##### 概念

> - **cpu资源**分配的先后顺序，就是指进程的优先权（priority）。
> - 优先权高的进程有优先执行权利。配置进程优先权对多任务环境linux很有用，可以改善系统性能。
> - 还可以把进程运行到指定的CPU上，这样一来，把不重要的进程安排到某个CPU，可以大大改善系统整体性能。

##### ps命令:

> 在linux或者unix系统中，用ps –l命令则会类似输出以下几个内容：
>
> - UID : 代表执行者的身份
> - PID : 代表这个进程的代号
> - PPID ：代表这个进程是由哪个进程发展衍生而来的，亦即父进程的代号
> - PRI ：代表这个进程可被执行的优先级，其值越小越早被执行
> - NI ：代表这个进程的nice值

###### PRI and NI:

> PRI也还是比较好理解的，即进程的优先级，或者通俗点说就是程序被CPU执行的先后顺序，此值越小进程的优先级别越高
>
> 那NI呢?就是我们所要说的nice值了，其表示进程可被执行的优先级的修正数值
>
> PRI值越小越快被执行，那么加入nice值后，将会使得PRI变为：PRI(new)=PRI(old)+nice, 这样，当nice值为负值的时候，那么该程序将会优先级值将变小，即其优先级会变高，则其越快被执行, 所以，调整进程优先级，在Linux下，就是调整进程nice值
>
> nice其取值范围是-20至19，一共40个级别。

###### PRI vs NI:

> 需要强调一点的是，**进程的nice值不是进程的优先级**，他们不是一个概念，但是进程nice值会影响到进程的优先级变化。
>
> 可以理解nice值是进程优先级的修正修正数据

[Linux的进程优先级 NI 和 PR - 简书 (jianshu.com)](https://www.jianshu.com/p/84b1f44706db)

##### top命令

> 用top命令更改已存在进程的nice：

```
top 
进入top后按“r”–>输入进程PID–>输入nice值 
```

##### 其他:

> - 竞争性: 系统进程数目众多，而CPU资源只有少量，甚至1个，所以进程之间是具有竞争属性的。为了高效完成任务，更合理竞争相关资源，便具有了优先级 
> - 独立性: 多进程运行，需要独享各种资源，多进程运行期间互不干扰 
> - 并行: 多个进程在多个CPU下分别，同时进行运行，这称之为并行 
> - 并发: 多个进程在一个CPU下采用进程切换的方式，在一段时间之内，让多个进程都得以推进，称之为 并发 

#### 进程切换相关

> 1. Linux系统中，进程的执行不一定是连续的，并不能一直霸占CPU资源直至进程运行完毕，很大可能是断断续续的执行。
> 2. 那么就需要记录该进程进行到哪了，和暂停运行时的数据，这就是**上下文**。
> 3. 当进程被暂时切换下来时，进程A需要带走保存在寄存器的上下文，目的为了下次再执行时，能恢复到原来的状态，继续运行。
> 4. 当进程被执行时，就会把上下文数据加载到CPU，继续上次的执行状态。
> 5. 进程切换是根据正在执行的进程的上下文执行的。
> 6.  **CPU中只有一个寄存器，但可以有多份上下文，并发执行多个进程。**

#### 环境变量

##### 概念

> 环境变量(environment variables)一般是指在操作系统中用来指定操作系统运行环境的一些参数。
>
> 如：我们在编写C/C++代码的时候，在链接的时候，从来不知道我们的所链接的动态静态库在哪里，但是照样可以链接成功，生成可执行程序，原因就是有相关环境变量帮助编译器进行查找。
>
> 环境变量通常具有某些特殊用途，还有在系统当中通常具有全局特性。

##### 常见环境变量

- PATH : 指定命令的搜索路径
- HOME : 指定用户的主工作目录(即用户登陆到Linux系统中时,默认的目录)
- SHELL : 当前Shell,它的值通常是/bin/bash。

**查看环境变量方法**

> echo $NAME //NAME:你的环境变量名称

######  测试PATH

1. 创建hello.c文件

    > ~~~c
    > #include <stdio.h>
    > int main()
    > {
    >  printf("hello world!\n");
    >  return 0;
    > }
    > ~~~
    >
    > 

2. 对比./hello执行和hello执行 

3. 为什么有些指令可以直接执行，不需要带路径，而我们的二进制程序需要带路径才能执行？

4. 将我们的程序所在路径加入环境变量PATH当中, **export PATH=$PATH:hello程序所在路径** 

5.  对比测试 

6. 还有什么方法可以不用带路径，直接就可以运行呢？

###### 测试HOME

1. 用root和普通用户，分别执行 echo $HOME ,对比差异. 
2. 执行 cd ~; pwd,对应 ~ 和 HOME 的关系

##### 相关命令

```
1. echo $name: 显示某个环境变量值
2. export name=$name:路径  : 添加一个新的环境变量
3. env: 显示所有环境变量
4. unset: 清除环境变量
5. set: 显示本地定义的shell变量和环境变量
```

##### 其他知识

###### 环境变量的组织方式

> ![image-20230305222653114](%E5%9B%BE%E7%89%87/Linux/image-20230305222653114.png)
>
> 每个程序都会收到一张环境表，环境表是一个字符指针数组，每个指针指向一个以’\0’结尾的环境字符串

###### 通过代码如何获取环境变量

- 命令行第三个参数

    ~~~C
    #include <stdio.h>
    int main(int argc, char *argv[], char *env[])
    {
     int i = 0;
     for(; env[i]; i++){
     printf("%s\n", env[i]);
     }
     return 0;
    }
    ~~~

- 通过第三方变量environ获取

    ~~~C
    #include <stdio.h>
    int main(int argc, char *argv[])
    {
     extern char **environ;
     int i = 0;
     for(; environ[i]; i++){
     printf("%s\n", environ[i]);
     }
     return 0;
    }
    ~~~

**libc中定义的全局变量environ指向环境变量表,environ没有包含在任何头文件中,所以在使用时 要用extern声明。**

###### 通过系统调用获取或设置环境变量

> - `putenv` , 后面讲解 
>
> - `getenv` , 本次讲解

~~~C
#include <stdio.h>
#include <stdlib.h>
int main()
{
 printf("%s\n", getenv("PATH"));
 return 0;
}
~~~

**常用getenv和putenv函数来访问特定的环境变量。**

###### 环境变量通常是具有全局属性的

环境变量通常具有全局属性，可以被子进程继承下去

> ~~~C
> #include <stdio.h>
> #include <stdlib.h>
> int main()
> {
> char * env = getenv("MYENV");
> if(env){
> printf("%s\n", env);
> }
> return 0;
> }
> ~~~
>
> 直接查看，发现没有结果，说明该环境变量根本不存在
>
> - 导出环境变量 `export MYENV="hello world"`
>
> - 再次运行程序，发现结果有了！说明：环境变量是可以被子进程继承下去的！想想为什么？
>
>     > C程序继承了shell的环境变量

###### 其他

> - 子进程继承
>     - 环境变量具有全局属性, 本质->可以被继承
>     - 子进程的环境变量 继承于 父进程环境变量
>     - 默认,所有的环境变量 都会被 子进程继承
>
> - 环境变量与本地变量
> - 环境变量具有全局属性，可以被继承

-------

### 进程地址空间

#### 进程地址空间抽象图

![image-20221119214917116](%E5%9B%BE%E7%89%87/Linux/image-20221119214917116.png) 

**验证**

~~~C++
分别打印局部变量，初始化全局变量，未初始化全局变量，堆区地址，main函数地址
~~~

#### 其他知识

##### makefile文件

~~~C++
hello:hello.c
    gcc -o $@ $^//$@指冒号左边的目标文件，￥^指右边的所有文件
.PHONY:clean
clean:
	rm -f hello
~~~

##### C语言拾遗：

~~~C++
malloc时，我们手动上传了变量个数，知道申请了多少字节，
但free时，仅仅上传了申请得到的地址，free是如何知道释放多少字节的
--申请空间时，会额外申请一些字节，保存申请的属性细节，即cookies，这里保存了申请信息，字节大小之类的
    
static 修饰局部变量会将变量的生命周期提升至全局生命期，作用域不变。
~~~

#### 实验--认识进程地址空间

**code1**

~~~C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int g_val = 0;
int main()
{
 pid_t id = fork();
 if(id < 0){
 perror("fork");
 return 0;
 }
 else if(id == 0){ //child
     printf("child[%d]: %d : %p\n", getpid(), g_val, &g_val);
 }else{ //parent
 printf("parent[%d]: %d : %p\n", getpid(), g_val, &g_val);
 }
 sleep(1);
 return 0;
}
~~~

输出

~~~C
//与环境相关，观察现象即可
parent[2995]: 0 : 0x80497d8
child[2996]: 0 : 0x80497d8
~~~

父进程子进程输出的变量值和地址是相同的，因为子进程按照父进程为模版，父子并没有对 量进行进行任何修改，也许是没有发生”写时拷贝“。

可是将代码稍加改动:

**code2**

~~~c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int g_val = 0;
int main()
{
 pid_t id = fork();
 if(id < 0){
 perror("fork");
 return 0;
 }
 else if(id == 0){ //child,子进程肯定先跑完，也就是子进程先修改，完成之后，父进程再读取
 g_val=100;
 printf("child[%d]: %d : %p\n", getpid(), g_val, &g_val);
 }else{ //parent
 sleep(3);
 printf("parent[%d]: %d : %p\n", getpid(), g_val, &g_val);
 }
 sleep(1);
 return 0;
}
~~~

输出

~~~c
//与环境相关，观察现象即可
child[3046]: 100 : 0x80497e8
parent[3045]: 0 : 0x80497e8
~~~

父子进程，输出地址是一致的，但是变量内容不一样！能得出如下结论:

> - 变量内容不一样，所以父子进程输出的变量绝对不是同一个变量
> - 但地址值是一样的，说明，该地址绝对不是物理地址！ 
> - 在Linux地址下，这种地址叫做 虚拟地址 
> - 我们在用C/C++语言所看到的地址，全部都是虚拟地址。
> - 物理地址，用户一概看不到，由OS统一管理

OS必须负责将 **虚拟地址 转化成 物理地址** 。

#### 进程地址空间是什么

##### 是什么

> - 历史
>
>     > 进程可直接访问物理内存，物理上更改。
>     >
>     > 缺点：若发生了野指针访问，则进程A可访问到进程B的空间，内存本身又是允许读写的，没有限制手段，非常不安全。
>
> - 现代：
>
>     > 进程只能接触到虚拟地址空间，逻辑上的更改 映射 到物理上的更改
>     >
>     > 每个进程有自己的PCB， 和对应的进程地址空间（虚拟地址空间）（0000 0000 -> ffff ffff)，进程地址空间也是一种数据结构，先描述再组织。
>     >
>     > 进程不再能访问物理内存，只能访问进程地址空间，进程地址空间通过映射机制，映射实际物理内存中。

![image-20230306103243383](%E5%9B%BE%E7%89%87/Linux/image-20230306103243383.png)

描述：

~~~C++
struct addr_room
{
    int code_start;
    int code_end;
    
    int init_start;
    int init_end;
    
    int uninit_start;
    int uninit_end;
    
    int heap_start;
    int heap_end;
    
    //......
    //......
}
~~~

```c++
进程地址空间通过页表映射到物理内存
地址空间和页表每一个进程都私有一份
页表是映射的手段，页表不同，则每个进程地址空间映射到不同的物理内存空间中
```

##### 为什么父进程子进程中fork前的全局变量地址相等，但内容不同

> - 首先， 父进程子进程的进程空间地址不是实际的物理内存地址，而是虚拟地址（线性地址），地址是进程地址空间的地址，内容是实际物理内存存储的内容
> - 子进程基本继承了父进程的所有属性，虚拟地址也继承于父进程，则**父子页表左边是相同的，右边不同**。
> - 则子进程和父进程中g_val的虚拟地址是相同的，但映射到物理内存的地址是不同的，所以地址相同，内容不同

##### 扩展--当形成的可执行文件未被加载到内存中时，内部中有地址吗？▲

> - 有，**可执行程序在编译的时候，内部中就已经有虚拟地址了**，在链接阶段时，函数调用时，就会call这些地址
> - 进程地址空间，**不仅仅是OS内部需要遵守的，编译器也要遵守**。
> - 即**编译器编译代码的时候，就已经形成了进程地址空间**：代码区，数据区，堆栈区，并且采用和linux内核一样的编制方式，给每一个变量每一行代码都进行了编址，故，**在程序编译阶段，每一个字段都有对应的虚拟地址**。
> - 程序被加载到物理内存中时，**不仅将代码+数据加载到了内存中，编译器编址得到的虚拟地址也加载进去了**，OS通过物理内存中的虚拟地址构建对应的进程地址空间，**页表通过进程地址空间的虚拟地址 和 物理内存的地址 构建映射逻辑规则**。
> - CPU读取进程地址空间的内容，通过页表映射，读到物理内存的内容得到指令，该指令内部可能存在的地址也是虚拟地址，再通过页表映射到实际物理地址。

#### 为什么要有进程地址空间

> 1. 因为**进程地址空间有效保护了物理内存**，页表中有映射关系，还有访问权限，进程地址空间和页表都是OS创建，维护的。则凡是想使用地址空间和页表进行映射和访问的操作，都在OS的监管下，对于不合法的访问和映射，OS会直接拒绝。有效保护了物理内存和数据。**OS监管**。
> 2. 因为进程地址空间和页表的存在，则磁盘数据可以加载到物理内存的任意位置，则**物理内存的分配和进程的管理不存在任何关联**，进程不再关心它的数据存在了哪里，只需要通过页表就能找到。内存管理模块 和 进程管理模块 就完成了解耦合。**解耦合**。
> 3. 因为进程地址空间的存在，则malloc等函数申请空间，得到的是进程地址空间的空间，只有真正的对物理地址空间访问的时候，才会执行内存相关管理算法，申请物理内存，构建页表映射关系。如不进行访问，则没有分配到任何字节的物理内存。这种**延迟分配策略，提高了整机的效率**。
> 4. 因为数据理论上可以加载到物理内存的任意位置，则物理内存中的几乎所有数据和代码都是乱序的。但因为页表的存在，在进程的视角来看，进程地址空间是连续的，物理地址也是“连续的”。**进程地址空间 + 页表 可以将内存分布 有序化**。**化零为整**。
> 5. 因为进程地址空间的存在， 每个进程都认为自己独占了4G内存空间，通过页表，将进程地址空间映射到了不同的物理内存，各个进程物理内存不相干，不相知。**实现独立性**。
> 6. 进程地址空间大小和实际物理内存大小不相干，前者可以大于后者

#### 什么是挂起

~~~C++
1. 加载的本质就是创建进程， 但不是必须立马把程序的所有的代码+数据加载到内存中，创建内核数据结构，构建内存映射关系。在极端情况下，只需创建内核数据结构（新建态），则理论上可以实现程序的分批加载。
2. 既然可以实现分批加载，也可以实现分批换出。将短时间内不再执行的进程的数据换出，页表右边指向磁盘地址，就实现了挂起。
~~~

## 进程控制

### fork函数

> 在linux中fork函数是非常重要的函数，它从已存在进程中创建一个新进程。新进程为子进程，而原进程为父进程。
>

~~~C++
#include <unistd.h>
pid_t fork(void);
返回值：子进程中返回0，父进程返回子进程id，出错返回-1
~~~

#### 面试题：fork创建子进程，OS都做了什么？

##### 执行流

进程调用fork，当控制转移到内核中的fork代码后，内核做：

> - **分配**新的内存块和内核数据结构给子进程 
> - 将父进程**部分**数据结构内容**拷贝**至子进程 
> - **添加**子进程到系统进程列表当中 
> - fork返回，开始调度器**调度**

**code**

~~~c++
int main( void )
{
     pid_t pid;
    
     printf("Before: pid is %d\n", getpid());
    
     if ( (pid=fork()) == -1 )
         perror("fork()"),exit(1);
    
     printf("After:pid is %d, fork return %d\n", getpid(), pid);
    
     sleep(1);
     return 0;
} 
运行结果：
[root@localhost linux]# ./a.out
Before: pid is 43676
After:pid is 43676, fork return 43677
After:pid is 43677, fork return 0
~~~

![image-20230626154238365](%E5%9B%BE%E7%89%87/Linux/image-20230626154238365.png)

这里看到了三行输出，一行before，两行after。进程43676先打印before消息，然后它又打印after。另一个after 消息有43677打印的。

注意到进程43677没有打印before，为什么呢？如下图所示

![image-20221121143340752](%E5%9B%BE%E7%89%87/Linux/image-20221121143340752.png)

**所以，fork之前父进程独立执行，fork之后，父子两个执行流分别执行。注意，fork之后，谁先执行完全由调度器决定。**

##### 扩展

![image-20221121115008120](%E5%9B%BE%E7%89%87/Linux/image-20221121115008120.png)

#### 写时拷贝

> 创建子进程，OS需要为子进程创建分配对应的内核结构，且是子进程独有的--独立性。
>
> 理论上，子进程也要有自己的代码和数据，可是大部分情况，**子进程没有加载的过程，即子进程没有自己的代码+数据。**
>
> 则**子进程只能“使用父进程的代码+数据”**
> 			代码：只能读不能写，父子共享可以支持
> 			数据：存在读写，必须分离
> 	
>
> 存储的数据可读可写，若每次创建子进程，都要拷贝父进程的数据给子进程，那么对于只需要读的子进程来说，无疑是浪费空间的。
>
> 理论上，对于 不会被子进程访问的 和 父子只会读取的数据， 不需要拷贝， 只需要拷贝父子进程需要写入的数据。
>
> 但对于OS来说，无法提前判断那些空间需要被写入，且提前拷贝的空间也可能存在空窗期。
>
> 所以，**OS选择了写时拷贝技术，对父子进程进行数据分离，在执行写入操作时，才拷贝分离数据。延迟拷贝。**

![image-20221122092638433](%E5%9B%BE%E7%89%87/Linux/image-20221122092638433.png)

#### fork常规用法

> 1. 一个父进程希望复制自己，使父子进程同时执行不同的代码段。例如，父进程等待客户端请求，生成子 进程来处理请求。
> 2. 一个进程要执行一个不同的程序。例如子进程从fork返回后，调用exec函数，进程替换。

#### fork调用失败原因

> - 系统中有太多的进程 
> - 实际用户的进程数超过了限制

### 进程终止

#### 相关知识

##### 进程终止时，操作系统做了什么

~~~
释放进程申请的相关内核数据结构和对应的数据+代码，本质上就是释放资源
~~~

##### 进程退出场景

> - 代码运行完毕，结果正确 
> - 代码运行完毕，结果不正确 
> - 代码异常终止

##### 如何终止一个进程

**正常终止**

> - 从main返回 
> - 调用exit
> -  _exit

**异常终止**

> - 手动终止：ctrl + c
> - 信号终止

#### _exit函数

##### _exit：系统接口

~~~
#include <unistd.h>
void _exit(int status);

参数：status 定义了进程的终止状态，父进程通过wait来获取该值
说明：虽然status是int，但是仅有低8位可以被父进程所用。所以_exit(-1)时，在终端执行$?发现返回值是255。

~~~

**_exit会直接终止进程，不会清空缓冲区▲▲。**

##### exit函数：库函数

~~~
#include <unistd.h>
void exit(int status);
exit在任何位置调用， 都代表终止进程。

~~~

**exit会在终止进程前，将缓冲区的内容刷新到显示器**

**exit最后也会调用_exit, 但在调用__exit之前，还做了其他工作：**

> 1. **执行**用户通过 atexit或on_exit定义的清理函数。 
> 2. **关闭**所有打开的流，所有的缓存数据均被写入 
> 3. **调用**_exit
>
> ![image-20221122111147064](%E5%9B%BE%E7%89%87/Linux/image-20221122111147064.png)
>
> code:
>
> ~~~C++
> int main()
> {
>      printf("hello");
>      exit(0);
> }
> 运行结果:
> [root@localhost linux]# ./a.out
> hello[root@localhost linux]#
> int main()
> {
>      printf("hello");
>      _exit(0);
> }
> 运行结果:
> [root@localhost linux]# ./a.out
> [root@localhost linux]# 
> 
> ~~~
>
> 

#### return

> return是一种更常见的退出进程方法。执行return n等同于执行exit(n),因为调用main的运行时函数会将main的返 回值当做 exit的参数。
>

- 其他函数的return为返回值，main函数的return，才是终止进程，返回退出码
- **echo $?** //最近一次进程的退出码
- 0值只有一个， 代表运行结果正确
- 非0值有很多， 标识不同的错误原因，根据返回的退出码，方便定位错误的原因
- **strerror(int num)**， 将错误码转换成字符串信息
- **若程序异常崩溃退出，则退出码无意义**，因为基本上执行不到return语句

#### 扩展

~~~C++
缓冲区是语言级别的缓冲区，是由语言标准库维护的
~~~

### 进程等待

#### 进程等待的必要性

> - 首先，子进程退出，父进程如果不管不顾，就**可能造成‘僵尸进程’**的问题，**进而造成内存泄漏**。
> - 另外，进程一旦变成僵尸状态，那就刀枪不入，“杀人不眨眼”的kill -9 也无能为力，因为谁也没有办法 杀死一个已经死去的进程。
> - 最后，父进程派给子进程的任务完成的如何，我们需要知道。如，子进程运行完成，结果对还是不对， 或者是否正常退出。
> - **父进程通过进程等待的方式，回收子进程资源，获取子进程退出信息。**

#### 进程等待的方法

##### wait

~~~C++
#include<sys/types.h>
#include<sys/wait.h>
pid_t wait(int*status);
~~~

> - 返回值：
>
>     > 成功返回被等待进程pid，失败返回-1。
>
> - 参数：
>
>     > 输出型参数，获取任意一个子进程的退出状态,不关心则可以设置成为NULL

##### waitpid

~~~c++
pid_ t waitpid(pid_t pid, int *status, int options);
~~~

> - 返回值：
>     	当正常返回的时候waitpid返回收集到的子进程的进程ID；
>     	如果设置了选项WNOHANG,而调用中waitpid发现没有已退出的子进程可收集,则返回0；
>     	如果调用中出错,则返回-1,这时errno会被设置成相应的值以指示错误所在；
>
> - 参数：
>
>     - pid：指定需要等待的子进程。
>
>         > Pid = -1，等待任一个子进程。与wait等效。
>         > Pid > 0 ，等待其进程ID与pid相等的子进程。
>
>     - status：输出型参数，获取子进程退出状态,不关心则可以设置成为NULL
>
>         > 宏：
>         > 	WIFEXITED(status): 若为正常终止子进程返回的状态，则为真。（宏：查看进程是否是正常退出）
>         > 	WEXITSTATUS(status): 若WIFEXITED非零，提取子进程退出码。（宏：查看进程的退出码）
>
>     - **options：决定是否一直等待。**
>
>         > WNOHANG: 若pid指定的子进程没有结束，则waitpid()函数**返回0，不予以等待**。若正常结束，则返回该子进程的ID。

- 如果**子进程已经退出**，调用wait/waitpid时，**wait/waitpid会立即返回**，并且释放资源，获得子进程退 出信息。
- 如果**在任意时刻调用wait/waitpid**，子进程存在且正常运行，**则父进程可能阻塞**。 
- 如果**不存在该子进程**，则**立即出错返回**。

![image-20221122143217827](%E5%9B%BE%E7%89%87/Linux/image-20221122143217827.png)

##### 获取子进程status

- wait和waitpid，都有一个status参数，该参数是一个输出型参数，**由操作系统填充**。 
- 如果传递**NULL，表示不关心子进程的退出状态信息**。 
- 否则，操作系统会根据该参数，将子进程的退出信息反馈给父进程。 
- status不能简单的当作整形来看待，可以当作**位图**来看待，具体细节如下图（只研究status低16比特 位）：

![image-20221122143312474](%E5%9B%BE%E7%89%87/Linux/image-20221122143312474.png)

~~~
8到15： 高8位为进程正常退出的退出码，异常退出没有作用
7：被信号所杀时使用
0到6： 低7位为子进程的终止信号，0代表正常终止，非0为异常终止
~~~

**测试代码：**

~~~C++

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
int main( void )
{
     pid_t pid;
     if ( (pid=fork()) == -1 )
     perror("fork"),exit(1);
     if ( pid == 0 )
     {
         sleep(20);
         exit(10);
     } 
     else 
     {
         int st;
         int ret = wait(&st);

         if ( ret > 0 && ( st & 0X7F ) == 0 )
         { // 正常退出
         	printf("child exit code:%d\n", (st>>8)&0XFF);
         }
         else if( ret > 0 ) 
         { // 异常退出
         	printf("sig code : %d\n", st&0X7F );
         }
     }
}
测试结果：
 [root@localhost linux]# ./a.out #等20秒退出
 child exit code:10 
 [root@localhost linux]# ./a.out #在其他终端kill掉
 sig code : 9

~~~

![image-20221122153738196](%E5%9B%BE%E7%89%87/Linux/image-20221122153738196.png)



##### 实验

- 进程的阻塞等待方式

~~~C++
int main()
{
  pid_t pid;
  pid = fork();
  if(pid < 0)
  {
      printf("%s fork error\n",__FUNCTION__);
      return 1;
  } 
  else if( pid == 0 )
  { //child
      printf("child is run, pid is : %d\n",getpid());
      sleep(5);
      exit(257);
  } 
  else
  {
      int status = 0;
      pid_t ret = waitpid(-1, &status, 0);//阻塞式等待，等待5S
      printf("this is test for wait\n");
      if( WIFEXITED(status) && ret == pid )
      {
          printf("wait child 5s success, child return code is :%d.\n",WEXITSTATUS(status));
      }
      else
      {
          printf("wait child failed, return.\n");
          return 1;
      }
  }
return 0;
}


运行结果:
child is run, pid is : 45110
this is test for wait
wait child 5s success, child return code is :1.

~~~

- 进程的非阻塞等待方式

~~~C++
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;

  pid = fork();
  if(pid < 0)
  {
      printf("%s fork error\n",__FUNCTION__);
      return 1;
  }
  else if( pid == 0 )
  { //child
      printf("child is run, pid is : %d\n",getpid());
      sleep(5);
      exit(1);
  } 
  else
  {
      int status = 0;
      pid_t ret = 0;
      do
      {
          ret = waitpid(-1, &status, WNOHANG);//非阻塞式等待
          if( ret == 0 )
          {
             printf("child is running\n");
          }
          sleep(1);
      }while(ret == 0);

      if( WIFEXITED(status) && ret == pid )
      {
         printf("wait child 5s success, child return code is :%d.\n",WEXITSTATUS(status));
      }
      else
      {
          printf("wait child failed, return.\n");
          return 1;
      }
  }
  return 0;
}

运行结果：
child is running
child is run, pid is : 2506
child is running
child is running
child is running
child is running
wait child 5s success, child return code is :1.

~~~

- 第二/三个参数都有简单明了的宏定义使用，减少了位运算计算操作。
- op选项能够自主决定进程是否需要持续等待子进程，避免父进程阻塞，可以“并发执行”多个子进程。

##### 理解

- 基于非阻塞调用的轮询检测方案可以提高父进程的效率，避免父进程因非CPU资源进入阻塞状态。
- **进程阻塞的本质，是进程阻塞在系统函数的内部**，因为系统函数属于OS才有能力决定进程的状态，阻塞在内核中，等待唤醒。



### 进程程序替换

#### 替换原理

> 用fork创建子进程后执行的是和父进程相同的程序(但有可能执行不同的代码分支)。
>
> 但实际运用时子进程往往要调用一种exec函数 以执行另一个程序。
>
> 当进程调用一种exec函数时,**该进程的用户空间代码和数据完全被新程序替换**,从新程序的启动例程开始执行。
>
> 调用exec并不创建新进程,所以调用exec前后该进程的id并未改变。
>
> ![image-20230306122350751](%E5%9B%BE%E7%89%87/Linux/image-20230306122350751.png)

> - 程序程序替换，通过特定的系统接口，**加载磁盘上的程序到已有的一个进程的进程地址空间中**。
> - 进程程序替换没有创建新进程，只是替换了原进程的数据段和代码段，保留了对应的数据结构。**替换里子，保留面子**。
> - 代表进程的是PCB，**对于OS来说，仍是同一个进程**。
> - 通过重**建页表的映射逻辑**，实现进程程序替换。
> - 程序替换从execl系统调用接口开始，直接替换为指定的替换程序，原进程程序execl后的所有代码不再执行。



#### 替换函数

##### 函数

> 其实有六种以exec开头的函数,统称exec函数:
>
> ~~~C
> #include <unistd.h>
> 
> int execl(const char *path, const char *arg, ...);
> int execlp(const char *file, const char *arg, ...);
> int execle(const char *path, const char *arg, ...,char *const envp[]);
> int execv(const char *path, char *const argv[]);
> int execvp(const char *file, char *const argv[]);
>  int execve(const char *path, char *const argv[], char *const envp[]);
> ~~~

##### 函数解释

> - 这些函数如果调用成功则加载新的程序从启动代码开始执行,不再返回。 
> - 如果调用出错则返回-1 
> - 所以exec函数只有出错的返回值而没有成功的返回值。

##### 命名理解

> - l(list) : 表示参数采用列表 
> - v(vector) : 参数用数组 
> - p(path) : 有p自动搜索环境变量PATH 
> - e(env) : 表示自己维护环境变量
>
> ![image-20230306124315076](%E5%9B%BE%E7%89%87/Linux/image-20230306124315076.png)

code：

~~~C
#include <unistd.h>
int main()
{
 char *const argv[] = {"ps", "-ef", NULL};
 char *const envp[] = {"PATH=/bin:/usr/bin", "TERM=console", NULL};
    
 execl("/bin/ps", "ps", "-ef", NULL);
 // 带p的，可以使用环境变量PATH，无需写全路径
 execlp("ps", "ps", "-ef", NULL);
 // 带e的，需要自己组装环境变量
 execle("ps", "ps", "-ef", NULL, envp);
    
 execv("/bin/ps", argv);
 // 带p的，可以使用环境变量PATH，无需写全路径
 execvp("ps", argv);
 // 带e的，需要自己组装环境变量
 execve("/bin/ps", argv, envp);
 exit(0);
}
~~~

事实上**,只有execve是真正的系统调用**,其它五个函数最终都调用 execve。

所以execve在man手册 第2节,其它函数在 man手册第3节。

这些函数之间的关系如下图所示。

![image-20230306124406870](%E5%9B%BE%E7%89%87/Linux/image-20230306124406870.png)

##### 理解

- 程序替换是一种写入操作，此时父进程，子进程的代码+数据不再相同，需要进行分离，进行写时拷贝

#### 制作简易shell

##### 原理分析

用下图的时间轴来表示事件的发生次序。其中时间从左向右。shell由标识为sh的方块代表，它随着时间的流逝从左 向右移动。shell从用户读入字符串"ls"。shell建立一个新的进程，然后在那个进程中运行ls程序并等待那个进程结束。

![image-20230306125129411](%E5%9B%BE%E7%89%87/Linux/image-20230306125129411.png)

然后shell读取新的一行输入，建立一个新的进程，在这个进程中运行程序 并等待这个进程结束。 所以要写一个shell，需要循环以下过程:

> 1. 获取命令行 
> 2. 解析命令行 
> 3. 建立一个子进程（fork）
> 4. 替换子进程（execvp）
> 5. 父进程等待子进程退出（wait）

根据这些思路，和我们前面的学的技术，就可以自己来实现一个shell了。

##### 代码实现

~~~C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#define NUM 1024
#define SIZE 32
#define SEP " "
#define INPUT_REDIR 1
#define OUTPUT_REDIR 2
#define APPEND_REDIR 3
#define NONE_REDIR 0

//保存完整的命令行字符串
char cmd_line[NUM];
//保存打散之后的命令行字符串
char *g_argv[SIZE];
//写一个环境变量的buffer，用来测试
char g_myval[64];
//保存命令的输出状态
int redir_status = NONE_REDIR;

char *CheckRedir(char *start)
{
    assert(start);
    char *end = start + strlen(start) - 1; //ls -a -l\0
    while (end >= start)
    {
        if (*end == '>')
        {
            if (*(end - 1) == '>')
            {
                redir_status = APPEND_REDIR;
                *(end - 1) = '\0';
                end++;
                break;
            }
            redir_status = OUTPUT_REDIR;
            *end = '\0';
            end++;
            break;
            //ls -a -l>myfile.txt
            //ls -a -l>>myfile.txt
        }
        else if (*end == '<')
        {
            //cat < myfile.txt,输入
            redir_status = INPUT_REDIR;
            *end = '\0';
            end++;
            break;
        }
        else
        {
            end--;
        }
    }
    if (end >= start)
    {
        return end; //要打开的文件
    }
    else
    {
        return NULL;
    }
}
// shell 运行原理 ： 通过让子进程执行命令，父进程等待&&解析命令
int main()
{
    extern char **environ;//拿取全局的环境变量

    //0. 命令行解释器，一定是一个常驻内存的进程，不退出
    while (1)
    {
        //1. 打印出提示信息 [root@localhost myshell]#
        printf("[root@我的主机 myshell]# ");
        fflush(stdout);//立即刷新
        memset(cmd_line, '\0', sizeof cmd_line);//重置数组

        //2. 获取用户的键盘输入[输入的是各种指令和选项: "ls -a -l -i"]
        // "ls -a -l>log.txt"
        // "ls -a -l>>log.txt"
        // "ls -a -l<log.txt"
        if (fgets(cmd_line, sizeof cmd_line, stdin) == NULL)//文本IO函数
        {
            continue;
        }
        cmd_line[strlen(cmd_line) - 1] = '\0';
        // 2.1: 分析是否有重定向
        //"ls -a -l>log.txt" -> "ls -a -l\0log.txt"
        //"ls -a -l -i\n\0"
        char *sep = CheckRedir(cmd_line);
        //printf("echo: %s\n", cmd_line);

        //3. 命令行字符串解析：
        //"ls -a -l -i" -> "ls" "-a" "-i"
        // export myval=105
        g_argv[0] = strtok(cmd_line, SEP); //第一次调用，要传入原始字符串
        int index = 1;
        if (strcmp(g_argv[0], "ls") == 0)
        {
            g_argv[index++] = "--color=auto";
        }
        if (strcmp(g_argv[0], "ll") == 0)
        {
            g_argv[0] = "ls";
            g_argv[index++] = "-l";
            g_argv[index++] = "--color=auto";
        }
        while (g_argv[index++] = strtok(NULL, SEP)); //第二次调用，如果还要解析原始字符串,传入NULL，则会继续返回上次的字符串解析结果
        if (strcmp(g_argv[0], "export") == 0 && g_argv[1] != NULL)
        {
            strcpy(g_myval, g_argv[1]);
            int ret = putenv(g_myval);//添加环境变量
            if (ret == 0)
                printf("%s export success\n", g_argv[1]);
            //for(int i = 0; environ[i]; i++)
            //    printf("%d: %s\n", i, environ[i]);
            continue;
        }
        if (strcmp(g_argv[0], "rm") == 0 || strcmp(g_argv[0], "rmdir") == 0)//特判rm/rmdir
        {
            printf("sorry, cant support rm and rmdir\n");
            continue;
        }

        //for debug
        //for(index = 0; g_argv[index]; index++)
        //    printf("g_argv[%d]: %s\n", index, g_argv[index]);

        //4.内置命令, 让父进程（shell）自己执行的命令，我们叫做内置命令，内建命令本质其实就是shell中的一个函数调用
        if (strcmp(g_argv[0], "cd") == 0) //not child execute, father execute
        {
            if (g_argv[1] != NULL)
                chdir(g_argv[1]); //cd path, cd .. //只影响进程内部的工作目录
            continue;
        }

        //5. fork()
        pid_t id = fork();
        if (id == 0) //child
        {
            if (sep != NULL)
            {
                int fd = -1;
                //说明命令曾经有重定向
                switch (redir_status)
                {
                case INPUT_REDIR:
                    fd = open(sep, O_RDONLY);
                    dup2(fd, 0);
                    break;
                case OUTPUT_REDIR:
                    fd = open(sep, O_WRONLY | O_TRUNC | O_CREAT, 0666);
                    dup2(fd, 1);
                    break;
                case APPEND_REDIR:
                    //TODO
                    fd = open(sep, O_WRONLY | O_APPEND | O_CREAT, 0666);
                    dup2(fd, 1);
                    break;
                default:
                    printf("bug?\n");
                    break;
                }
            }
            // printf("下面功能让子进程进行的\n");
            // printf("child, MYVAL: %s\n", getenv("MYVAL"));
            // printf("child, PATH: %s\n", getenv("PATH"));
            //cd cmd , current child path
            //execvpe(g_argv[0], g_argv, environ); // ls -a -l -i
            //不是说好的程序替换会替换代码和数据吗？？
            //环境变量相关的数据，会被替换吗？？没有！
            execvp(g_argv[0], g_argv); // ls -a -l -i
            exit(1);
        }
        //father
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if (ret > 0)
            printf("exit code: %d\n", WEXITSTATUS(status));
    }
}
~~~



![image-20221215172321803](%E5%9B%BE%E7%89%87/Linux/image-20221215172321803.png)

#### 思考

exec/exit就像call/return  

一个C程序有很多函数组成。一个函数可以调用另外一个函数，同时传递给它一些参数。被调用的函数执行一定的操作，然后返回一个值。每个函数都有他的局部变量，不同的函数通过call/return进行通信。 

这种通过参数和返回值在拥有私有数据的函数间通信的模式是结构化程序设计的基础。Linux鼓励将这种应用于程序之内的模式扩展到程序之间。如下图

![image-20230306125339442](%E5%9B%BE%E7%89%87/Linux/image-20230306125339442.png)

一个C程序可以fork/exec另一个程序，并传给它一些参数。这个被调用的程序执行一定的操作，然后通过exit(n)来 返回值。调用它的进程可以通过wait（&ret）来获取exit的返回值。

## 基础IO

### C/C++文件IO

#### C语言文件IO

写：

~~~C
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    FILE *fp = fopen("io.txt", "w");
    if(nullptr == fp)
    {
        perror("fopen");
    }

    const char *msg = "Hello C++!\n";
    int cnt = 5;
    while(cnt --)
    {
        ssize_t s = fwrite((void*)msg, strlen(msg), 1, fp); // 从ptr读， 一个元素的字节为size，读n个元素，写到fp中
    }
    
    fclose(fp);
}
~~~

读：

~~~C
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    FILE *fp = fopen("io.txt", "r");
    if(nullptr == fp)
    {
        perror("fopen");
    }
    char buff[1024];
    while(true)
    {
        ssize_t s = fread(buff, 1, strlen(msg), fp);
        if(s > 0)
        {
            buff[s] = '\0';
            printf("%s", buff);
        }

        if(feof(fp))
        {
            break;
        }
    }
    fclose(fp);

    return 0;
}

~~~

#### 输出到显示器

~~~C
#include <stdio.h>
#include <string.h>
int main()
{
     const char *msg = "hello fwrite\n";
     fwrite(msg, strlen(msg), 1, stdout);//不需要+1，'\0'是语言规定的，文件只需要保存有效数据，不需要遵守C语言的规定
     printf("hello printf\n");
     fprintf(stdout, "hello fprintf\n");
     return 0;
}
~~~

#### 总结

> - C默认会打开三个输入输出流，分别是stdin, stdout, stderr 
>
> - 仔细观察发现，这三个流的类型都是FILE*, fopen的返回值类型，即文件指针
>
> - 打开文件的方式
>
>     > - r 
>     >
>     >     > Open text file for reading. 
>     >     > The stream is positioned at the beginning of the file.
>     >
>     > - r+ 
>     >
>     >     > Open for reading and writing.
>     >     > The stream is positioned at the beginning of the file.
>     >
>     > - w 
>     >
>     >     > Truncate(缩短) file to zero length or create text file for writing.
>     >     > The stream is positioned at the beginning of the file.
>     >
>     > - w+ 
>     >
>     >     > Open for reading and writing.
>     >     > The file is created if it does not exist, otherwise it is truncated.
>     >     > The stream is positioned at the beginning of the file.
>     >
>     > - a 
>     >
>     >     > Open for appending (writing at end of file). 
>     >     > The file is created if it does not exist. 
>     >     > The stream is positioned at the end of the file.
>     >
>     > - a+ 
>     >
>     >     > Open for reading and appending (writing at end of file).
>     >     > The file is created if it does not exist. The initial file position
>     >     > for reading is at the beginning of the file, 
>     >     > but output is always appended to the end of the file.
>

![image-20230712214857372](%E5%9B%BE%E7%89%87/Linux/image-20230712214857372.png)

### 系统文件IO

#### 前言

- Linux下一切皆文件

- 首先理解：文件 = 内容 + 属性
    - 内容即文件里存放的信息数据
    - 属性，通俗的讲就是文件的基本信息，比如文件名，存储目录。**理论的说**，文件的属性是一个数据结构，里面存放了文件的各种信息
- C/C++程序执行开始，会默认打开**三个文件流**：标准输入，标准输出，标准错误，这就是我们能读到键入的信息，输出到显示器的原因。
- 文件存放在磁盘/硬件上，而对于硬件的访问与管理，是OS决定的，所以程序读写文件离不开OS的接管，printf/scanf属于库函数，那么它们一定需要去调用系统接口，向OS申请指定功能。

- 跨平台。系统接口，是根据不同系统实现的，具有不同的命名，实现细节，如果该程序就不具有跨平台性，除非你自写版本控制代码。但库函数对这些接口进行了封装，实现了版本控制，减少了学习压力，增加了程序的跨平台能力。
- 知己知彼方能百战百胜，系统接口只有一份，学习了解系统接口，才能指定语言IO到底干了什么。

#### 系统接口

> 操作文件，除了上述C接口，我们还可以采用系统接口来进行文件访问， 以代码的形式，实现和上面C接口一模一样的代码：

写

~~~C
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    umask(0); // 设置该进程的临时umask
    int fd = open("OSio.txt", O_WRONLY | O_CREAT, 0644); // 文件路径， 打开方式， umask
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    const char *msg = "Hello Osio\n";
    char buff[1024];

    int cnt = 5;
    while(cnt--)
    {
        ssize_t s = write(fd, msg, strlen(msg)); // 写到fd中， 从msg中读， 读strlen()个大小为1字节的元素
    }

    close(fd);
    return 0;
}
~~~

读：

~~~C
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    int fd = open("OSio.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while (true)
    {
        ssize_t s = read(fd, buff, strlen(msg));
        if (s > 0)
        {
            buff[s] = '\0';
            printf("%s", buff);
        }
        else
        {
            break;
        }
    }

    close(fd);
    return 0;
}
~~~

#### 接口介绍

##### open

~~~C
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);

pathname: 要打开或创建的目标文件
flags: 打开文件时，可以传入多个参数选项，用下面的一个或者多个常量进行“或”运算，构成flags。
参数:
 O_RDONLY: 只读打开
 O_WRONLY: 只写打开
 O_RDWR : 读，写打开
 这三个常量，必须指定一个且只能指定一个
 O_CREAT : 若文件不存在，则创建它。需要使用mode选项，来指明新文件的访问权限
 O_APPEND: 追加写
     返回值：
 成功：新打开的文件描述符
 失败：-1

~~~

![image-20221216150718748](%E5%9B%BE%E7%89%87/Linux/image-20221216150718748.png)

~~~
宏：O_RDONLY(只读), O_WRONDLY(读写), O_CREAT(创建文件)
第一个适用于文件已存在，只读
第二个适用于文件可能不存在，需要创建，传入权限mod，读写

umask用于屏蔽系统的umask值
~~~

##### 系统调用/库函数

> - 上面的 fopen fclose fread fwrite 都是C标准库当中的函数，我们称之为库函数（libc）。 
> - 而， open close read write lseek 都属于系统提供的接口，称之为系统调用接口
> - ![image-20230306162529499](%E5%9B%BE%E7%89%87/Linux/image-20230306162529499.png)
> - 系统调用接口和库函数的关系，一目了然。 所以，可以认为，f#系列的函数，都是对系统调用的封装，方便二次开发。

C语言库函数的形参选项，就是由系统接口open的参数组合实现的

![image-20221216150940984](%E5%9B%BE%E7%89%87/Linux/image-20221216150940984.png)

![image-20230712202640325](%E5%9B%BE%E7%89%87/Linux/image-20230712202640325.png)

~~~
C语言的w对应O_TRUNC, 清空原文件内容并写入
a对应O_APPEND, 不清空，追加到文末
~~~

## 文件知识

### 文件描述符fd

#### 引言

~~~c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("myfile1", O_RDONLY);
    if(fd1 < 0)
    {
        perror("open");
        return 1;
    }
    printf("fd1: %d\n", fd1);
    int fd2 = open("myfile2", O_RDONLY);
    if(fd2 < 0)
    {
        perror("open");
        return 1;
    }
    printf("fd2: %d\n", fd2);
    //.....
 
 close(fd1);
 close(fd1);   
 return 0;
}


fd1: 3
fd2: 4
fd3: 5
......
~~~

为什么从3开始？应该从几开始？这些数字代表什么？

**为什么有？**

- 首先我们知道C程序会默认打开三个文件流：标准输入，标准输出，标准错误。这三个文件对应的就是Linux系统下的三个文件。
- 由于三个文件流类型为FILE*，这是C语言定义的标识文件的数据结构，C接口可以根据FILE\*找到指定的文件，进行读写。
- 但我们前面说过，C接口的实现是依赖系统接口的，C标准库的FILE\*操作系统是不认识，不认可的。
- 那么，C语言的FILE\*一定包含了OS认可的标识文件的“东西”，C接口将它传给系统接口，用于查找指定文件。
- 这个“东西”就是fd，至此我们可以认为，fd就是OS用来标识文件的。

**是什么？为什么是3？**

- 我们了解了fd是OS用来标识文件的，但我们还不知道为什么打印出来的fd是从3开始的。

- Linux体系结构先描述再组织，文件作为一种资源，也需上述的组织方式。先描述，就和进程一样，文件也有描述属性的数据结构files_struct，里面包含了文件的各种信息；再组织，一个进程可以打开n个文件，对于这n个文件操作系统使用了数组结构来组织它们，如下图。

    ![image-20230307173022423](%E5%9B%BE%E7%89%87/Linux/image-20230307173022423.png)

- 又知道，C程序会默认打开三个文件流，Linux进程默认情况下也会有3个缺省打开的文件描述符fd，即标准输入0， 标准输出1， 标准错误2。

- 这个fd就是进程中管理文件的数组的下标

- 现在我门可以理解一个文件创建顺序

    > ~~~
    > fwrite()->FILE*->FILE->fd->write->task_stcuct->files*->files_struct->[fd]->file*->文件
    > 根据fwrite的参数FILE*找到C标准中的文件的数据结构FILE，拿到其中的fd
    > fwrite在内部进行系统调用，将fd传给系统接口write
    > write在某个进程的内部，通过进程的task_struct找到file*
    > 根据file*找到表files_struct,通过解引用找到文件的地址file*
    > OS通过file*找到文件
    > ~~~
    >

#### 0 & 1 & 2

> - Linux进程默认情况下会有3个缺省打开的文件描述符，分别是标准输入0， 标准输出1， 标准错误2. 
> - 0,1,2对应的物理设备一般是：键盘，显示器，显示器 

所以输入输出还可以采用如下方式：

~~~C
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
 char buf[1024];
 ssize_t s = read(0, buf, sizeof(buf));
 if(s > 0){
 buf[s] = 0;
 write(1, buf, strlen(buf));
 write(2, buf, strlen(buf));
 }
 return 0;
}
~~~

![image-20230306162821936](%E5%9B%BE%E7%89%87/Linux/image-20230306162821936.png)

而现在知道，文件描述符就是从0开始的小整数。

当我们打开文件时，操作系统在内存中要创建相应的数据结构来描述目标文件。于是就有了file结构体。表示一个已经打开的文件对象。

而进程执行open系统调用，所以必须让进程和文件关联起来。每个进程都有一个指针*files, 指向一张表files_struct,该表最重要的部分就是包涵一个指针数组，每个元素都是一个指向打开文件的指针！

所以，**本质上，文件描述符就是该数组的下标**。

所以，**只要拿着文件描述符，就可以找到对应的文件。**

#### fd分配规则

code1

~~~C
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
 int fd = open("myfile", O_RDONLY);
 if(fd < 0){
 perror("open");
 return 1;
 }
 printf("fd: %d\n", fd);
 close(fd);
 return 0;
}

~~~

发现：fd：3

关闭0或者2，再看

code2

~~~c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
 close(0);
 //close(2);
 int fd = open("myfile", O_RDONLY);
 if(fd < 0){
 perror("open");
 return 1;
 }
 printf("fd: %d\n", fd);
 close(fd);
 return 0;
}

~~~

发现是结果是： fd: 0 或者 fd 2 可见。

文件描述符的分配规则：**在files_struct数组当中，找到当前没有被使用的 最小的一个下标，作为新的文件描述符。**

#### 重定向

> 重定向就是本应该输入到01文件的内容输入到了其他文件中，更改了fd对应下标数组元素的内容
>

##### 输出重定向
![image-20230712205633227](%E5%9B%BE%E7%89%87/Linux/image-20230712205633227.png)

![image-20230712205641251](%E5%9B%BE%E7%89%87/Linux/image-20230712205641251.png)

![image-20230712205655459](%E5%9B%BE%E7%89%87/Linux/image-20230712205655459.png)

##### 输入重定向

![image-20230712210426329](%E5%9B%BE%E7%89%87/Linux/image-20230712210426329.png)

![image-20230712210436343](%E5%9B%BE%E7%89%87/Linux/image-20230712210436343.png)

##### 追加重定向

![image-20230712210706902](%E5%9B%BE%E7%89%87/Linux/image-20230712210706902.png)

![image-20230712210715128](%E5%9B%BE%E7%89%87/Linux/image-20230712210715128.png)

![image-20230712210727708](%E5%9B%BE%E7%89%87/Linux/image-20230712210727708.png)

![image-20221218173712156](%E5%9B%BE%E7%89%87/Linux/image-20221218173712156.png)

##### dup2系统调用

~~~C
#include <unistd.h>
int dup2(int oldfd, int newfd);
~~~

![image-20230306165215057](%E5%9B%BE%E7%89%87/Linux/image-20230306165215057.png)

![image-20230712212007745](%E5%9B%BE%E7%89%87/Linux/image-20230712212007745.png)

![image-20230712212018057](%E5%9B%BE%E7%89%87/Linux/image-20230712212018057.png)

![image-20230712212034035](%E5%9B%BE%E7%89%87/Linux/image-20230712212034035.png)

#### 再谈Linux下一切皆文件

![image-20230307190659765](%E5%9B%BE%E7%89%87/Linux/image-20230307190659765.png)

### 缓冲区

#### 是什么？

缓冲区就和他的名字一样，作缓冲的区域，计算机中的区域就是内存空间，所以缓冲区就是一段内存空间。

他的作用就是减少写入显示器的次数，减少IO操作，提高效率。

#### 为什么

> 缓冲区可以减少写入显示器的次数，减少IO操作，提高效率。

**分析原理：**

如果没有缓冲区，那么程序每次请求IO操作时，少至1个字符，多至n个字符，都需要系统调用，进行IO操作，IO操作非常浪费时间。我们称这种为写透模式，即程序提交了IO请求，OS立马给予回应。

写透模式中IO操作过多，有些IO并不需要立马响应，理论上可以进行延时响应。根据这个理论出现了缓冲区策略--写回模式。

**缓冲区的刷新策略：**

> 一般而言，所有的设备，都倾向于**全缓冲**，因为它可以最大程度减少IO次数，提高效率。并不是说想要每次刷新的数据多，而是这样能最简单的减少IO次数。
>
> 但对于一些特殊设备，比如显示器，不能只看重效率，还要看重体验，显示器就是**行缓冲**。

详细：

1. 立即刷新：即程序待输出数据放到缓冲区，但是会立马进行IO操作，相当于没有。
2. 行刷新/行缓冲：遇到’\n‘刷新缓冲区。
3. 满刷新/满缓冲：缓冲区满了进行刷新
4. 上面属于一般策略，还提供了特殊策略。
    - 强制刷新：用户强制刷新缓冲区
    - 进程退出：进程退出，缓冲区刷新，因为没必要存在了

#### 在哪里

~~~C
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    //C
    printf("hello printf\n");
    fprintf(stdout, "hello fprintf\n");
    const char *s = "hello fputs\n";
    fputs(s, stdout);
    
    //OS
    const char *ss = "hello write\n";
    write(1, ss, strlen(ss));
    
    fork();
    
    return 0;
}


[qlz@tianen1573 IO]$ g++ test5.cpp
[qlz@tianen1573 IO]$ ./a.out
hello printf
hello fprintf
hello fputs
hello write
[qlz@tianen1573 IO]$ ./a.out > myfile.txt
[qlz@tianen1573 IO]$ cat myfile
cat: myfile: No such file or directory
[qlz@tianen1573 IO]$ cat myfile.txt
hello write
hello printf
hello fprintf
hello fputs
hello printf
hello fprintf
hello fputs

    //再注释掉fork进行比较
~~~

> 我们可以看到，直接输出到显示器文件，和输出到文本文件，内容不同，而去掉fork之后，却是相同的，那么这一定和fork有关。
>
> 两次为不同类型的文件，也可能存在问题。而且还可以发现，C语言提供的输出了两次，OS提供的输出了一次，那么和C/OS也存在一定关系

- 向显示器刷新为行刷新，存在\n就会刷新缓冲区，向文本文件刷新为全刷新，缓冲区满或者进程结束才会刷新。
- 那么，在fork函数之前，缓冲区的内容已经刷新到显示器了，而对于文本文件，满或者进程结束才会刷新。
- fork函数之后，父子进程会拥有同样的代码+数据，那么缓冲区也应该各有一个（写时拷贝技术，可能为同一个）。
- 对于显示器：fork函数之前，缓冲区已经刷新为空了，没有内容了，fork之后，父子进程都是空缓冲区，所以我们看到有无fork都是同样的输出内容。
- 对于文本文件：fork函数之前，缓冲区内容还存在，fork函数之后，父子进程各有一个缓冲区，当进程结束后各自刷新自己的缓冲区。
- 但我们发现，只有C接口的内容才会有两份，而OS接口的内容仍然是一份。
- 那么，我们可以确定，**上述的缓冲区**和C有关，和OS无关。
- 所以我们可以认为，**我们一直谈的缓冲区是C标准库的**，或者说是计算机语言维护的，不是OS提供的。

**缓冲区并不是只有语言会提供，OS也会定义一个缓冲区，前者为用户级缓冲区，后者为内核级缓冲区。**

两者的关系为：

> 语言级别的IO函数，会将数据保存到用户级缓冲区。
>
> 根据不同的刷新策略，通过系统级别的IO接口，将用户级缓冲区的内容刷新到内核级缓冲区。
>
> 内核级缓冲区属于OS，此时就是OS来管理了。

#### 理解

> - 一般C库函数写入文件时是全缓冲的，而写入显示器是行缓冲。 
> - printf fwrite 库函数会自带缓冲区（进度条例子就可以说明），当发生重定向到普通文件时，数据的缓冲方式由行缓冲变成了全缓冲。 
> - 而我们放在缓冲区中的数据，就不会被立即刷新，甚至fork之后 也不刷新。
> - 但是进程退出之后，会统一刷新，写入文件当中。 
> - 但是fork的时候，父子数据会发生写时拷贝，所以当你父进程准备刷新的时候，子进程也就有了同样的 一份数据，随即产生两份数据。 
> - write 没有变化，说明没有所谓的缓冲。

#### 模拟实现缓冲区

~~~C++
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#include <stdlib.h>

#define NUM 1024

struct MyFILE_
{
    int fd;
    char buffer[1024];
    int end; //当前缓冲区的结尾
};
typedef struct MyFILE_ MyFILE;

MyFILE *fopen_(const char *pathname, const char *mode)
{
    assert(pathname);
    assert(mode);

    MyFILE *fp = NULL;

    if (strcmp(mode, "r") == 0)
    {
    }
    else if (strcmp(mode, "r+") == 0)
    {
    }
    else if (strcmp(mode, "w") == 0)
    {

        int fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0666);
        if (fd >= 0)
        {
            fp = (MyFILE *)malloc(sizeof(MyFILE));
            memset(fp, 0, sizeof(MyFILE));
            fp->fd = fd;
        }
    }
    else if (strcmp(mode, "w+") == 0)
    {
    }
    else if (strcmp(mode, "a") == 0)
    {
    }
    else if (strcmp(mode, "a+") == 0)
    {
    }
    else
    {
        ;
    }

    return fp;
}

//是不是应该是C标准库中的实现！
void fputs_(const char *message, MyFILE *fp)
{
    assert(message);
    assert(fp);

    strcpy(fp->buffer + fp->end, message); //abcde\0
    fp->end += strlen(message);

    //for debug
    printf("%s\n", fp->buffer);

    //暂时没有刷新, 刷新策略是谁来执行的呢？用户通过执行C标准库中的代码逻辑，来完成刷新动作
    //这里效率提高，体现在哪里呢？？因为C提供了缓冲区，那么我们就通过策略，减少了IO的执行次数(不是数据量)
    if (fp->fd == 0)
    {
        //标准输入
    }
    else if (fp->fd == 1)
    {
        //标准输出
        if (fp->buffer[fp->end - 1] == '\n')
        {
            //fprintf(stderr, "fflush: %s", fp->buffer); //2
            write(fp->fd, fp->buffer, fp->end);
            fp->end = 0;
        }
    }
    else if (fp->fd == 2)
    {
        //标准错误
    }
    else
    {
        //其他文件
    }
}

void fflush_(MyFILE *fp)
{
    assert(fp);

    if (fp->end != 0)
    {
        //暂且认为刷新了--其实是把数据写到了内核
        write(fp->fd, fp->buffer, fp->end);
        syncfs(fp->fd); //将数据写入到磁盘
        fp->end = 0;
    }
}

void fclose_(MyFILE *fp)
{
    assert(fp);
    fflush_(fp);
    close(fp->fd);
    free(fp);
}

int main()
{
    MyFILE *fp = fopen_("./log.txt", "w");
    if (fp == NULL)
    {
        printf("open file error");
        return 1;
    }

    fputs_("one: hello world", fp);

    fork();

    fclose_(fp);
}
~~~

#### fflush

https://blog.csdn.net/ShenHang_/article/details/114968557

### 标准输出与标准错误的区别

~~~C++
int main()
{
    std::cout << "hello cout" << std::endl;
    std::cerr << "hello cerr" << std::endl;
}
~~~

> - 标准输出和标准错误都是指向显示器文件，打开了"两份文件"
>
> - 如标准输入打开一份显示器文件，标准错误也打开一份显示器文件，它们都向显示器输出内容，但彼此互不干扰
>
> - 实际操作时`./myfile > stdout.txt 2>stderr.txt`，可以实现：标准输出重定向到stdout.txt，标准错误重定向到stderr.txt
>
>     > 输出重定向，默认将1文件的内容重定向的指定文件
>     >
>     > 2>stderr.txt，将2文件的内容输出到stderr.txt
>
> - `./myfile > log.txt 2>&1`
>
>     > 2>&1 : dup2(2,1);

### perror

**perror不仅打印出字符串内容，还会打印出程序退出码代表的信息**

code

~~~C++
int main()
{
    perror("hello perror");
    
    return 0;
}
~~~

## 文件系统

### 磁盘与磁盘文件

侧重点

![image-20230306205557528](%E5%9B%BE%E7%89%87/Linux/image-20230306205557528.png)

#### 磁盘的结构

##### 性质

> 掉电易失存储介质：内存
>
> 永久性存储介质：磁盘，SSD(固态硬盘)，U盘等

磁盘是外设+机械设备，那么计算机运行中，磁盘一定很“慢”，那么OS一定不会让CPU直接与磁盘交互。

##### 磁盘结构

**磁盘：**

![image-20230307213246355](%E5%9B%BE%E7%89%87/Linux/image-20230307213246355.png)

**磁盘中的一个盘片：**

![image-20230307213311869](%E5%9B%BE%E7%89%87/Linux/image-20230307213311869.png)

**扇区：**

数据库文件，本质其实就是保存在磁盘的盘片当中。也就是上面的一个个小格子中，就是我们经常所说的扇区。当 然，数据库文件很大，也很多，一定需要占据多个扇区。 

题外话：

> - 从上图可以看出来，在半径方向上，距离圆心越近，扇区越小，距离圆心越远，扇区越大
> - 那么，所有扇区都是默认512字节吗？目前是的，我们也这样认为。因为保证一个扇区多大，是由比特位密度决定的。
> - 不过最新的磁盘技术，已经慢慢的让扇区大小不同了，不过我们现在暂时不考虑。

我们在使用Linux，所看到的大部分目录或者文件，其实就是保存在硬盘当中的。(当然，有一些内存文件系统，如： proc ， sys 之类，我们不考虑)

所以，**最基本的，找到一个文件的全部，本质，就是在磁盘找到所有保存文件的扇区。** 

而我们能够定位任何一个扇区，那么便能找到所有扇区，因为查找方式是一样的。

**定位扇区：**

![image-20230307213453610](%E5%9B%BE%E7%89%87/Linux/image-20230307213453610.png)

- 柱面(磁道): 多盘磁盘，每盘都是双面，大小完全相等。那么同半径的磁道，整体上便构成了一个柱面 
- 每个盘面都有一个磁头，那么磁头和盘面的对应关系便是1对1的 
- 所以，我们只需要知道，磁头（Heads）、柱面(Cylinder)(等价于磁道)、扇区(Sector)对应的编号。即可在磁盘 上定位所要访问的扇区。这种**磁盘数据定位方式叫做 CHS** 。
- 不过实际**系统软件使用的并不是 CHS （但是硬件 是），而是 LBA** ，一种线性地址，可以想象成虚拟地址与物理地址。系统将 LBA 地址最后会转化成为 CHS ，交 给磁盘去进行数据读取。不过，我们现在不关心转化细节，知道这个东西，让我们逻辑自洽起来即可。

##### 磁盘的抽象结构

OS并不会按照CHS方式去寻址，而是将磁盘地址抽象成一种线性地址，即通过转化，用虚拟地址代表磁盘的物理地址。

系统使用的是LBA，在需要查找磁盘文件是，将LBA转换为CHS，交给磁盘。

![image-20230307220959662](%E5%9B%BE%E7%89%87/Linux/image-20230307220959662.png)

#### 磁盘的管理

> 先描述再组织

- 磁盘很大，将其分成不同大小的区域，即磁盘分区，磁盘各个分区只有大小的区别。那么对磁盘的管理--》对小分区的管理。

- 小分区依旧很大，继续对他划分，小分区划分成块，那么对分区的管理--》对块组的管理，对磁盘的管理--》对块组的管理。

- 最后只需要管理块组就可以管理整个磁盘

##### 块组结构

![image-20230307220803244](%E5%9B%BE%E7%89%87/Linux/image-20230307220803244.png)

> - Block Group：ext2文件系统会根据分区的大小划分为数个Block Group。而每个Block Group都有着相同的结构组成。
>
> - **超级块（Super Block）：存放文件系统本身的属性信息，代表的是整个文件系统。**
>
>     > 记录的信息主要有：
>     >
>     > - bolck 和 inode的总量， 
>     > - 未使用的block和inode的数量，
>     > - 一个block和inode的大小，
>     > - 最近一次挂载的时间，
>     > - 最近一次写入数据的时间，
>     > - 最近一次检验磁盘的时间等其他文件系统的相关信息。
>     > - **Super Block的信息被破坏，可以说整个 文件系统结构就被破坏了**。
>
> - Group Descriptor Table，**块组描述符**：描述块组属性信息，这个块组有多大，使用了多少，有多少inode，等等。
>
> - Block Bitmap，**块位图**：Block Bitmap中记录着Data Block中哪个数据块已经被占用，哪个数据块没有被占用 。
>
> - inode Bitmap，**inode位图**：每个bit表示一个inode是否空闲可用。 
>
> - inode Table，**indoe节点表**：存放该块组内所有文件的inode，**inode里存放文件属性**， 如 文件大小，所有者，最近修改时间等 。
>
> - Data blocks，**数据区：存放文件内容**。

##### 理论知识

- 虽然磁盘的基本单位为512字节，但是操作系统（文件系统）和磁盘进行IO交互的基本单位是4KB。
    - 512字节太小了，有可能导致IO次数增加，效率降低。
    - 如果OS在交互时根据磁盘的大小进行读取，那么磁盘大小发生改变，OS的源代码也要发生改变，耦合度高。两者各用自己的数据单位，可以解耦合
- inode，是一个大小为128字节的空间，保存的是对应文件的属性。
- BlockBitmap/inodeBitmap：两者都是用一个比特位对应一个块/inode节点，位值为1，代表已经被占用，否则表示可用。
- 一个文件“只”对应一个inode属性节点，inode编号。但是一个文件并不一定只有一个block，因为文件的内容一个block可能存放不了。
- 文件内容的查找：文件能够通过文件数组结构找到自己的inode编号，通过inode编号可以找到inode节点，节点里有一个块数组block[]，里面存放这同一个inode的块的编号，通过块的编号去datablocks可以找到指定块。当然一个inode节点里的块数组可能无法存放使用到的所有块，这时候块存储的内容可以是其他块的编号，做一个周转作用。

#### 磁盘文件

> 冯诺依曼计算机中，被打开的文件存放在内存中，而未被打开的文件存放在磁盘介质里，就是磁盘文件。
>

### 文件系统与inode

#### 理论

![image-20230308115918783](%E5%9B%BE%E7%89%87/Linux/image-20230308115918783.png)

**文件系统可以认为是块组结构中管理那一部分。**

- **inode，是一个大小为128字节的空间，保存的是对应磁盘文件的属性。**
- 一个文件“只”对应一个inode属性节点，inode编号。但是一个文件并不一定只有一个block，因为文件的内容一个block可能存放不了。
- 文件内容的查找：**文件能够在所在目录的数据块找到自己的inode编号**，通过inode编号去块组可以找到inode节点，节点里有一个数据块数组block[]，里面存放着同一个inode的数据块的编号，通过块的编号去datablocks可以找到指定数据块。
- 当然如果只靠数组下标也可能无法指向所有数据快，但可以通过一定逻辑使一些数组块中不存放信息，而存放其他数据块的编号，通过间接的方式查找其他数据块，比如另最后一个数数据块存放其他数据块的编号。这就大文件的解决方案。

#### 分区与格式化

> 分区就是根据不同要求，将磁盘分成只有大小区别的多个区域，每一个区域就是一个分区
>
> 分区后需要格式化，格式化就是向块组写入文件系统，就是系统的文件系统写到块组管理的那一部分。
>

#### inode与文件名

**inode节点里不保存文件名**

> 一个目录下可以保存多个文件，但不允许重名文件。
>
> 在LINUX，目录也是文件，也有inode，DataBlocks。
>
> 目录的DataBlock存放的是**该目录下文件名与其inode的映射关系，都具有唯一性，互为key值**。
>
> 文件权限知识：**进入目录，需要X权限，进入后创建需要W权限。**需要W权限就是因为要在目录的DataBlocks写入文件名与inode映射关系。

#### inode与fd

**不知真假**

fd是进程PCB中，保存进程已经打开的文件的文件地址的数组的**下标**，这个“打开的文件”存放在内存中。

inode是关于文件的存储的，它在文件所在的块组里，在磁盘中，记录的是“存储在磁盘上的文件”的属性，我们使用的是inode编号记录。

进程想要打开文件，就需要inode编号去磁盘上寻找指定的文件加载到内存中。

**一个文件一定有inode**，因为他需要保存在磁盘中，但**“不一定一直有fd”**，因为fd是进程为了管理“打开的文件”分配给进程使用的，文件没有被打开，没有加载的内存，进程没有使用它，也就没有分配fd。

#### 其他

> 由于inode号码与文件名分离，这种机制导致了一些Unix/Linux系统特有的现象。
>
> 　　1. 有时，文件名包含特殊字符，无法正常删除。这时，直接删除inode节点，就能起到删除文件的作用。
>
> 　　2. 移动文件或重命名文件，只是改变文件名，不影响inode号码，但所在目录的数据块内容会修改。
>
> 　　3. 打开一个文件以后，系统就以inode号码来识别这个文件，不再考虑文件名。因此，通常来说，系统无法从inode号码得知文件名。
>
> 第3点使得软件更新变得简单，可以在不关闭软件的情况下进行更新，不需要重启。因为系统通过inode号码，识别运行中的文件，不通过文件名。更新的时候，新版文件以同样的文件名，生成一个新的inode，不会影响到运行中的文件。等到下一次运行这个软件的时候，文件名就自动指向新版文件，旧版文件的inode则被回收。

### 创建/删除/查看文件，os所作所为

#### 创建

用户提供文件名。进程分配fd，my_file。文件系统分配inode编号，inode节点。目录在数据块记录映射关系。

> 1. 存储属性  内核先找到一个空闲的i节点（这里是263466）。内核把文件信息记录到其中。
> 2. 存储数据  该文件需要存储在三个磁盘块，内核找到了三个空闲块：300,500，800。将内核缓冲区的第一块数据 复制到300，下一块复制到500，以此类推。 
> 3. 记录分配情况 文件内容按顺序300,500,800存放。内核在inode上的磁盘分布区记录了上述块列表。
> 4. 添加文件名到目录 新的文件名abc。linux如何在当前的目录中记录这个文件？内核将入口（263466，abc）添加到目录文 件。文件名和inode之间的对应关系将文件名和文件的内容及属性连接起来。

**有空间创建文件失败**

> 1. inode节点还有，没有数据块了，可能能创建，不能写。
> 2. 数据块还有，没有inode节点了，直接不能创建。

#### 删除

找到inode编号，inode节点。在块组中位图置0，目录中删除映射关系。

**下载慢，删除快的原因。**

文件恢复的原理：仅置零，未覆盖。

#### 查找

**查找文件，需要在所在目录查找关联的inode**，拿着inode去磁盘寻找

**而查找目录，OS会给目录建立一个类似哈夫曼树的数据结构**，在这个数据结构中，查找目录对应的inode，在内存中寻找

### 软硬链接

#### 硬链接

> 一般情况下，文件名和inode号码是”一一对应”关系，每个inode号码对应一个文件名。但是，Unix/Linux系统允许，**多个文件名指向同一个inode号码**。
>
> 这意味着，可以用不同的文件名访问同样的内容；对文件内容进行修改，会影响到所有文件名；但是，删除一个文件名，不影响另一个文件名的访问。这种情况就被称为”硬链接”（hard link）。
>
> ln命令可以创建硬链接：
>
> **ln 源文件 目标文件**
>
> 运行上面这条命令以后，源文件与目标文件的inode号码相同，都指向同一个inode。inode信息中有一项叫做”链接数”，记录指向该inode的文件名总数，这时就会增加1。
>
> 反过来，删除一个文件名，就会使得inode节点中的”链接数”减1。当这个值减到0，表明没有文件名指向这个inode，系统就会回收这个inode号码，以及其所对应block区域。
>
> 这里顺便说一下**目录文件的”链接数”**。创建目录时，默认会生成两个目录项：”.”和”..”。前者的inode号码就是当前目录的inode号码，等同于当前目录的”硬链接”；后者的inode号码就是当前目录的父目录的inode号码，等同于父目录的”硬链接”。所以，**任何一个目录的”硬链接”总数，总是等于2加上它的子目录总数（含隐藏目录）**。

**拓展**

> 硬链接是通过索引节点进行的链接。在Linux中，多个文件指向同一个索引节点是允许的，像这样的链接就是硬链接。**硬链接只能在同一文件系统中的文件之间进行链接，不能对目录进行创建**。如果删除硬链接对应的源文件，则硬链接文件仍然存在，而且保存了原有的内容，这样可以起到防止因为误操作而错误删除文件的作用。由于硬链接是有着相同 inode 号仅文件名不同的文件，因此，删除一个硬链接文件并不影响其他有相同 inode 号的文件。



#### 软连接

> 除了硬链接以外，还有一种特殊情况。
>
> **文件A和文件B的inode号码虽然不一样，但是文件A的内容是文件B的路径。读取文件A时，系统会自动将访问者导向文件B。**因此，无论打开哪一个文件，最终读取的都是文件B。这时，文件A就称为文件B的”软链接”（soft link）或者”符号链接（symbolic link）。
>
> 这意味着，文件A依赖于文件B而存在，如果删除了文件B，打开文件A就会报错：”No such file or directory”。这是软链接与硬链接最大的不同：**文件A指向文件B的文件名，而不是文件B的inode号码，文件B的inode”链接数”不会因此发生变化。**
>
> ln -s命令可以创建软链接。
>
> **ln -s 源文文件或目录 目标文件或目录**

**拓展**

> 软链接（也叫符号链接）与硬链接不同，文件用户数据块中存放的内容是另一文件的路径名的指向。**软链接就是一个普通文件，只是数据块内容有点特殊。软链接可对文件或目录创建**。
>
> 软链接主要应用于以下两个方面：一是方便管理，例如可以把一个复杂路径下的文件链接到一个简单路径下方便用户访问；另一方面就是解决文件系统磁盘空间不足的情况。例如某个文件文件系统空间已经用完了，但是现在必须在该文件系统下创建一个新的目录并存储大量的文件，那么可以把另一个剩余空间较多的文件系统中的目录链接到该文件系统中，这样就可以很好的解决空间不足问题。删除软链接并不影响被指向的文件，但若被指向的原文件被删除，则相关软连接就变成了死链接。



#### 理解

- 软硬链接的**本质区别：是否有独立的inode**
- 软链接有独立的inode-》**软链接是一个独立的文件**。软链接的文件内容可以理解为指向的文件的路径，相当于windows的快捷方式
- 硬链接没有独立的inode，和它链接的文件共享一个inode。**创建硬链接不是真正的创建文件**，仅仅在指定目录下，建立inode和文件名的映射关系。

## 动静态库▲

### 理论

- 库的使用，可以减少开发周期，开发成本，提高软件健壮性。
- **静态库（.a）：程序在编译链接的时候把库的代码链接到可执行文件中。**程序运行的时候将不再需要静态库 。
- **动态库（.so）：程序在运行的时候才去链接动态库的代码，**多个程序共享使用库的代码。 
- **一个与动态库链接的可执行文件仅仅包含它用到的函数入口地址的一个表**，而不是外部函数所在目标文件的整个机器码 。
- 在可执行文件开始运行以前，外部函数的机器码由操作系统从磁盘上的该动态库中复制到内存中，**这个过程称为动态链接**（dynamic linking） 动态库可以在多个程序间共享，所以动态链接使得可执行文件更小，节省了磁盘空间。操作系统采用虚拟内存机制**允许物理内存中的一份动态库被要用到该库的所有进程共用**，节省了内存和磁盘空间。
- **函数库里面一定不会包含main函数**，因为一个程序只有一个main函数入口，如果库里面有main函数，那么自己写的代码就不能含有main函数，无法实现自己的逻辑。自己的main函数，可以自己决定函数的调用和一些逻辑的执行，别人的main函数，只能遵守别人的设计。

### 静态库制作/发布

#### 制作

> - 静态库就是一些.o文件经过打包后的集合，所以想要制作静态库，肯定需要一些待使用.o文件。
> - 库名字前缀规定为lib，后缀规定为.a，即一个静态库名字为 libName.a。
> - 制作命令：`ar -rc libName.a name1.o name2.o ... `。

#### 发布

> - 静态库发布，就是将需要使用的库打包至静态库目录output的子目录lib，将库里面的.o文件对应的.h文件打包至静态库目录output的子目录include。如下结构
>
>     ![image-20230310133549305](%E5%9B%BE%E7%89%87/Linux/image-20230310133549305.png)
>
> - **makefile**
>
>     ~~~makefile
>     libTest.a: myprint.o mymath.o
>     	ar -rc libTest.a mymath.o myorint.o
>     mymath.o:mymath.c
>     	gcc -c mymath.c -o mymath.o
>     myprint.o:myprint.c
>     	gcc -c myprint.c -o myprint.o
>                                                                                                                                                                                                                                     
>     .PHONY:output
>     output:
>     	mkdir -p output/lib
>     	mkdir -p output/include
>     	cp -rf *.h output/include
>     	cp -rf *.a output/lib
>                                                                                                                                                                                                                                     
>     .PHONY:clean
>     clean:
>     	rm -rf *.o libTest.a output
>     ~~~

### 静态库使用

**对于静态库，编译器在链接期间，会将程序代码+数据和静态库一起编译进进程地址空间中，同时加载到内存，都在进程地址空间的代码区。**

编译器寻找静态库，首先在指定路径下寻找，其次若没有指定路径，在系统默认路径下寻找，头文件同理。

- 系统默认路径

    > 那么就需要将我们编写的库和头文件，拷贝至系统默认路径下
    >
    > `sudo cp output/include/* /usr/include/ -rf`    `ls /usr/include/myprint.h ....`
    >
    > `sudo cp output/lib/libTest.a /lib64 -rf`    `ls /lib64/libTest.a`
    >
    > ` gcc -o test main.c -lTest`    -l库名编译时链接静态库
    >
    > 
    >
    > 还可以在默认路径下创建头文件和库的软链接，以软链接代替拷贝
    >
    > **将静态库拷贝至系统目录的缺点是：长期积累，容易造成库污染，头文件污染**

- 指定路径

    > ![image-20230310143032337](%E5%9B%BE%E7%89%87/Linux/image-20230310143032337.png)
    >
    > `gcc main.c -I ./output/include/ -L ./output/lib/ -lname`（去掉lib和后缀就是库名）

如果路径下存在同名的动态库，那么编译器默认链接动态库，链接静态库需要添加`-static`选项

`gcc main.c -I ./output/include/ -L ./output/lib/ -lname -static`

**ldd命令**可以显示可执行程序的依赖

![image-20230310143630317](%E5%9B%BE%E7%89%87/Linux/image-20230310143630317.png)

### 动态库制作/发布

#### 区别

**静态库，编译器在链接期间，会将程序代码+数据和静态库一起编译进进程地址空间中，同时加载到内存，都在进程地址空间的代码区，其他程序也链接了这个静态库，仍需要加载到内存中。**

**而动态库，是在程序运行之后，动态库再从磁盘加载到内存上，建立页表映射关系，动态库在进程地址空间的共享区，当其他程序也需要链接这个动态库时，不需要再次加载动态库，只需要建立页表映射关系即可，这就是共享库。**

两者的区别

> - **加载到内存的时间不同**，静态库在链接时，和程序代码+数据，一起加载到内存中，两者相当于一个“资源”；而动态库，是在程序进程地址空间创建好之后，才加载到内存，属于后打开的"资源"。
> - **进程地址空间位置不同**，静态库在代码区，动态库在共享区。
> - **库函数的调用不同**，调用静态库的库函数，在代码区跳转，**使用的是进程地址空间的绝对地址**；调用动态库的库函数，会跳转到共享区，因为是后加载到内存，那么映射到进程地址空间时，在每个进程的绝对地址可能是不一样的，但库函数相对于库的偏移量时明确的，则**使用的是库的起始位置+函数偏移量**，就可以找到所有库函数的地址空间。

#### 制作

> - **形成与位置无关的二进制文件 -- fPIC**
>     - gcc -fPIC -c mymath.c -o mymath.o
>     - gcc -fPIC -c myprint.c -o myprint.o
>
> - **形成与位置无关的动态库 -- shared**
>
>     `gcc -shared mymath.o myprint.o -o libTest.so`
>
> - **makefile**
>
>     ~~~makefile
>     libTest.so: myprint.o mymath.o
>     	gcc -shared mymath.o myprint.o -o libTest.so
>     mymath.o:mymath.c
>     	gcc -fPIC -c mymath.c -o mymath.o
>     myprint.o:myprint.c
>     	gcc -fPIC -c myprint.c -o myprint.o
>                                                                                                                                                                                                                                     
>     .PHONY:output
>     output:
>     	mkdir -p output/lib
>     	mkdir -p output/include
>     	cp -rf *.h output/include
>     	cp -rf *.so output/lib
>     	rm -r *.o *.so
>                                                                                                                                                                                                                                     
>     .PHONY:clean
>     clean:
>     	rm -rf *.o libTest.a output
>     ~~~
>
>     ![image-20230310153435083](%E5%9B%BE%E7%89%87/Linux/image-20230310153435083.png)
>
> 

#### 发布

> 同静态库

### 动态库使用

动态库的制作和发布，和静态库相差不大，只有指令上的区别。但在使用上，差了很多。

首先，我们知道，静态库和程序数据+代码一起编进进程地址空间，不需要额外加载。

而动态库是后加载到内存的，那么就有一个问题，OS想要把动态库打开，建立映射关系，就需要找到动态库文件，知道它的位置。

**所以，不止编译器需要知道链接了哪一个动态库，OS同样需要知道。**

介绍四个方法告诉OS

> 1. 默认路径：拷贝.so文件到系统共享库路径下，一般为`/usr/lib`
>
> 2. 指定路径：默认路径下不存在，OS会在LD_LIBRARY_PATH环境变量里遍历查找
>
>     > `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:libPath `
>     >
>     > `libPath`，是需要链接的动态库路径
>     >
>     > `$`，以添加的方式，将路径添加到环境变量中，防止覆盖写入
>     >
>     > 环境变量是局部的，属于bash，当关闭当前shell，就会消失
>     >
>     > 也可以永久写入，写入到指定配置文件中
>
> 3. ldconfig 配置/etc/ld.so.conf.d/，ldconfig更新
>
>     > sudo vim /etc/ld.so.conf
>     >
>     > 添加库路径
>     >
>     > sudo ldconfig
>     >
>     > 上面的方法可以用控制文件，将库路径添加到环境变量中
>
> 4. 给动态库创建一个软连接，放到系统默认库路径下

那么相对于静态库链接，我们**多了一步：告诉OS动态库的位置**。

**gcc指令没有区别**

**makefile**

~~~makefile
libTest.so: myprint.o mymath.o
	gcc -shared mymath.o myprint.o -o libTest.so
mymath.o:mymath.c
	gcc -fPIC -c mymath.c -o mymath.o
myprint.o:myprint.c
	gcc -fPIC -c myprint.c -o myprint.o

.PHONY:output
output:
	mkdir -p output/lib
	mkdir -p output/include
	cp -rf *.h output/include
	cp -rf *.so output/lib
	rm -r *.o *.so

.PHONY:clean
clean:
	rm -rf *.o libTest.a output
~~~



### 总结

1. 制作静态库/动态库，发布库
2. 告诉编译器库的路径
3. 动态库需要额外告诉OS库的路径
4. 链接

## VSCODE使用

- Linux

    > gcc/g++
    >
    > gdb

- vscode

    > C/C++
    >
    > CDB debug
    >
    > CodeLLDB
    >
    > Chinese
    >
    > 等

**百度**

## 进程间通信

进程间通信简称IPC（Interprocess communication），进程间通信就是在不同进程之间传播或交换信息。

### 前言

#### 进程间通信IPC的目的

> - 数据传输：一个进程需要将它的数据发送给另一个进程 
> - 资源共享：多个进程之间共享同样的资源。 
> - 通知事件：一个进程需要向另一个或一组进程发送消息，通知它（它们）发生了某种事件（如进程终止时要通知父进程）。 
> - 进程控制：有些进程希望完全控制另一个进程的执行（如Debug进程），此时控制进程希望能够拦截另 一个进程的所有陷入和异常，并能够及时知道它的状态改变。

#### 本质

> 进程间通信的本质就是，让不同的进程看到同一份资源。

由于各个运行进程之间具有独立性，这个**独立性主要体现在数据层面**，而代码逻辑层面可以私有也可以公有（例如父子进程），因此各个进程之间要实现通信是非常困难的。

各个进程之间若想实现通信，一定要借助第三方资源，这些进程就可以通过向这个第三方资源写入或是读取数据，进而实现进程之间的通信，这个第三方资源实际上就是操作系统提供的一段内存区域。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/bc9e72dfcfca4b328e3477b8a967758f-16811045361253.png)

因此，**进程间通信的本质就是，让不同的进程看到同一份资源**（内存，文件内核缓冲等）。 由于这份资源可以由操作系统中的不同模块提供，因此出现了不同的进程间通信方式

#### 进程间通信分类

> - 管道 ：Linux原生
> - System V进程间通信 ：更侧重于本地通信，多进程
> - POSIX进程间通信：更侧重于网络通信，多线程

- 管道 

    > - 匿名管道pipe 
    > - 命名管道 

- System V IPC 

    > - System V 消息队列 
    > - System V 共享内存 
    > - System V 信号量 

- POSIX IPC 

    > - 消息队列 
    > - 共享内存 
    > - 信号量 
    > - 互斥量 
    > - 条件变量 
    > - 读写锁

### 管道

#### 什么是管道

管道是Unix中最古老的进程间通信的形式。**我们把从一个进程连接到另一个进程的一个数据流称为一个“管道”。**

例如，统计我们当前使用云服务器上的登录用户个数。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16811046215567.png)

其中，who命令和wc命令都是两个程序，当它们运行起来后就变成了两个进程，who进程通过标准输出将数据打到“管道”当中，wc进程再通过标准输入从“管道”当中读取数据，至此便完成了数据的传输，进而完成数据的进一步加工处理。

![image-20230309205423007](%E5%9B%BE%E7%89%87/Linux/image-20230309205423007.png)



**特点**

> - 传输的都是“资源”。
> - 单工通信，只能单向通信。

#### 匿名管道

##### 原理

> 管道通信依靠的是Linux系统实现的，最原生，最古老的通信方式，依靠的Linux体系结构设计理念。
>
> **匿名管道用于进程间通信，且仅限于本地父子进程之间的通信**。

进程间通信的本质就是，让不同的进程看到同一份资源，使用匿名管道实现父子进程间通信的原理就是，让两个父子进程先看到同一份被打开的文件资源，然后父子进程就可以对该文件进行写入或是读取操作，进而实现父子进程间通信。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16811046867679-168110468941912.png)

注意：

- 这里父子进程看到的同一份文件资源是由操作系统来维护的，所以当父子进程对该文件进行写入操作时，该文件缓冲区当中的数据并不会进行写时拷贝。
- **管道虽然用的是文件的方案，但操作系统一定不会把进程进行通信的数据刷新到磁盘当中**，因为这样做有IO参与会降低效率，而且也没有必要，这些数据仅用于进程通信，没有保存的必要。也就是说，这种文件是一批不会把数据写到磁盘当中的文件，换句话说，磁盘文件和内存文件不一定是一一对应的，有些文件只会在内存当中存在，而不会在磁盘当中存在。

##### pipe函数

pipe函数用于创建匿名管道，pip函数的函数原型如下：

~~~C++
int pipe(int pipefd[2]);
~~~

pipe函数的参数是一个**输出型参数**，数组pipefd用于返回两个指向管道读端和写端的文件描述符：

![image-20230410133244719](%E5%9B%BE%E7%89%87/Linux/image-20230410133244719.png)

pipe函数调用成功时返回0，调用失败时返回-1。

##### 匿名管道使用

在创建匿名管道实现父子进程间通信的过程中，需要pipe函数和fork函数搭配使用，具体步骤如下：

1. 父进程调用pipe函数创建管道。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110484366414-168110484499317.png)
2. 父进程创建子进程。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110490339619-168110490488422.png)
3. 父进程关闭写端，子进程关闭读端。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110491298924-168110491454527.png)

**注意：**

1. **管道只能够进行单向通信**，因此当父进程创建完子进程后，需要确认父子进程谁读谁写，然后关闭相应的读写端。
2. 从管道写端写入的数据会被内核缓冲，直到从管道的读端被读取。

##### 从fd的角度理解

1. 父进程调用pipe函数创建管道。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110509715529-168110509838632.png)
2. 父进程创建子进程。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110510382334-168110510740237.png)
3. 父进程关闭写端，子进程关闭读端。
    ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110511618739-168110511799042.png)

例如，在以下代码当中，子进程向匿名管道当中写入10行数据，父进程从匿名管道当中将数据读出。

~~~C++
//child->write, father->read                                                                             

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int fd[2] = {0};
    if (pipe(fd) < 0)
    { //使用pipe创建匿名管道
        perror("pipe");
        return 1;
    }
    pid_t id = fork(); //使用fork创建子进程
    if (id == 0)
    {
        //child
        close(fd[0]); //子进程关闭读端
        //子进程向管道写入数据
        const char *msg = "hello father, I am child...";
        int count = 10;
        while (count--)
        {
            write(fd[1], msg, strlen(msg));
            sleep(1);
        }
        close(fd[1]); //子进程写入完毕，关闭文件
        exit(0);
    }
    //father
    close(fd[1]); //父进程关闭写端
    //父进程从管道读取数据
    char buff[64];
    while (1)
    {
        ssize_t s = read(fd[0], buff, sizeof(buff));
        if (s > 0)
        {
            buff[s] = '\0';
            printf("child send to father:%s\n", buff);
        }
        else if (s == 0)
        {
            printf("read file end\n");
            break;
        }
        else
        {
            printf("read error\n");
            break;
        }
    }
    close(fd[0]); //父进程读取完毕，关闭文件
    waitpid(id, NULL, 0);
    return 0;
}
~~~

运行结果如下：

![image-20230713105413252](%E5%9B%BE%E7%89%87/Linux/image-20230713105413252.png)

##### 管道读写规则

pipe2函数与pipe函数类似，也是用于创建匿名管道，其函数原型如下：

~~~C++
#include<fcntl.h>

int pipe2(int pipefd[2], int flags);
~~~

pipe2函数的第二个参数用于设置选项。

> 第二个参数：需要引入头文件

1. 当没有数据可读时：

    - O_NONBLOCK disable：read调用阻塞，即进程暂停执行，一直等到有数据来为止。
    - O_NONBLOCK enable：read调用返回-1，errno值为EAGAIN。
2. 当管道满的时候：
    - O_NONBLOCK disable：write调用阻塞，直到有进程读走数据。
    - O_NONBLOCK enable：write调用返回-1，errno值为EAGAIN
3. 如果所有管道写端对应的文件描述符被关闭，则read返回0。
4. 如果所有管道读端对应的文件描述符被关闭，则write操作会产生信号SIGPIPE，进而可能导致write进程退出。
5. **当要写入的数据量不大于PIPE_BUF时，Linux将保证写入的原子性。**
6. **当要写入的数据量大于PIPE_BUF时，Linux将不再保证写入的原子性。**
    ![image-20230713105737872](%E5%9B%BE%E7%89%87/Linux/image-20230713105737872.png)

##### 管道的特点

###### 管道内部自带同步与互斥机制

**我们将一次只允许一个进程(执行流)使用的资源，称为临界资源。**

管道在同一时刻只允许一个进程对其进行写入或是读取操作，因此**管道也就是一种临界资源**。

临界资源是需要被保护的，若是我们不对管道这种临界资源进行任何保护机制，那么就可能出现同一时刻有多个进程对同一管道进行操作的情况，进而导致同时读写、交叉读写以及读取到的数据不一致等问题。

为了避免这些问题，内核会对管道操作进行**同步与互斥**：

- **同步**： 两个或两个以上的进程在运行过程中协同步调，**按预定的先后次序运行**。比如，A任务的运行依赖于B任务产生的数据。
- **互斥**： 一个公共资源同一时刻只能被一个进程使用，多个进程不能同时使用公共资源。

实际上，**同步是一种更为复杂的互斥，而互斥是一种特殊的同步**。对于管道的场景来说，互斥就是两个进程不可以同时对管道进行操作，它们会相互排斥，必须等一个进程操作完毕，另一个才能操作，而**同步也是指这两个不能同时对管道进行操作，但这两个进程必须要按照某种次序来对管道进行操作。**

也就是说，**互斥具有唯一性和排它性，但互斥并不限制任务的运行顺序，而同步的任务之间则有明确的顺序关系。**

###### 管道的生命周期随进程

管道本质上是通过文件进行通信的，也就是说管道依赖于文件系统，那么**当所有打开该文件的进程都退出后，该文件也就会被释放掉，所以说管道的生命周期随进程**。

###### 管道提供的是流式服务

对于进程A写入管道当中的数据，进程B每次从管道读取的数据的多少是任意的，这种被称为流式服务，与之相对应的是数据报服务：

- **流式服务：** 数据没有明确的分割，不分一定的报文段。
- **数据报服务：** 数据有明确的分割，拿数据按报文段拿。

###### 管道是(特殊的)半双工通信

在数据通信中，数据在线路上的传送方式可以分为以下三种：

- 单工通信(Simplex Communication)：单工模式的数据传输是单向的。通信双方中，一方**固定**为发送端，另一方固定为接收端。
- 半双工通信(Half Duplex)：半双工数据传输指数据可以在一个信号载体的两个方向上传输，但是不能同时传输。
- 全双工通信(Full Duplex)：全双工通信允许数据在两个方向上同时传输，它的能力相当于两个单工通信方式的结合。全双工可以同时(瞬时)进行信号的双向传输。

管道是半双工的，数据只能向一个方向流动，需要双方同时通信时，需要建立起两个管道。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110601895749-168110602059752.png)



##### 管道读写的四种特殊情况▲

在使用管道时，可能出现以下四种特殊情况：

1. **写端进程不写，读端进程一直读**，那么此时会因为管道里面没有数据可读，对应的**读端进程会被挂起**，直到管道里面有数据后，读端进程才会被唤醒。
2. **读端进程不读，写端进程一直写**，那么当管道被写满后，对应的**写端进程会被挂起**，直到管道当中的数据被读端进程读取后，写端进程才会被唤醒。
3. **写端进程将数据写完后将写端关闭**，那么读端进程将管道当中的数据读完后，就会继续执行该进程之后的代码逻辑，**读端进程不会被挂起**。
4. **读端进程将读端关闭**，而写端进程还在一直向管道写入数据，那么操作系统会**产生SIGPIPE信号，将写端进程杀掉**。

其中前面两种情况就能够很好的说明，管道是自带同步与互斥机制的，读端进程和写端进程是有一个步调协调的过程的，不会说当管道没有数据了读端还在读取，当管道已经满了写端还在写入。读端进程读取数据的条件是管道里面有数据，写端进程写入数据的条件是管道当中还有空间，若是条件不满足，则相应的进程就会被挂起，直到条件满足后才会被再次唤醒。

第三种情况也很好理解，读端进程已经将管道当中的所有数据都读取出来了，而且此后也不会有写端再进行写入了，那么此时读端进程也就可以执行该进程的其他逻辑了，而不会被挂起。

第四种情况也不难理解，既然管道当中的数据已经没有进程会读取了，那么写端进程的写入将没有意义，因此操作系统直接将写端进程杀掉。而此时子进程代码都还没跑完就被终止了，属于异常退出，那么子进程必然收到了某种信号。

我们可以通过以下代码看看情况四中，子进程退出时究竟是收到了什么信号。
~~~C++
#include <cstdlib>
#include <cstdio>

#include <unistd.h>

#include <cstring>

#include <sys/wait.h> //
#include <sys/types.h>

int main()
{

    int fd[2] = {0};
    if (pipe(fd) < 0)
    {
        perror("pipe\n");
        return 1;
    }

    pid_t id = fork();

    if (id == 0) //子进程
    {
        close(fd[0]);

        const char *msg = "I am child, hello father\n";
        int cnt = 5;

        while (cnt--)
        {
            write(fd[1], msg, sizeof(msg));
            sleep(1);
        }

        close(fd[1]);
        exit(0);
    }

    //直接关闭文件
    close(fd[0]);
    close(fd[1]);

    int status = 0;
    waitpid(id, &status, 0);                           //关心子进程退出状态， 并阻塞等待
    printf("chile get signal : %d \n", status & 0x7f); //输出信号 -- 获取子进程status

    return 0;
}
~~~

运行结果显示，子进程退出时收到的是13号信号。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110639892054-168110640029657.png)

通过`kill -l`命令可以查看13对应的具体信号。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110641305159-168110641510062.png)

由此可知，当发生情况四时，操作系统向子进程发送的是`SIGPIPE`信号将子进程终止的。

##### 管道的大小

管道的容量是有限的，如果管道已满，那么写端将阻塞或失败，那么管道的最大容量是多少呢？

**使用man手册**

> 根据man手册，在2.6.11之前的Linux版本中，管道的最大容量与系统页面大小相同，从Linux 2.6.11往后，管道的最大容量是65536字节。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110645279164-168110645449267.png)
>
> 然后我们可以使用uname -r命令，查看自己使用的Linux版本。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110646642769-168110646834072.png)
>
> 根据man手册，我使用的是Linux 2.6.11之后的版本，因此管道的最大容量是65536字节。

**使用ulimit命令**

> 其次，我们还可以使用`ulimit -a`命令，查看当前资源限制的设定。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110649105874-168110649253477.png)
>
> 根据显示，管道的最大容量是 512 × 8 = 4096字节。

**自行测试**

> 这里发现，根据man手册得到的管道容量与使用ulimit命令得到的管道容量不同，那么此时我们可以自行进行测试。
>
> 前面说到，若是读端进程一直不读取管道当中的数据，写端进程一直向管道写入数据，当管道被写满后，写端进程就会被挂起。据此，我们可以写出以下代码来测试管道的最大容量。
>
> ~~~C++
> #include <unistd.h>
> #include <stdio.h>
> #include <stdlib.h>
> #include <sys/wait.h>
> int main()
> {
> 	int fd[2] = { 0 };
> 	if (pipe(fd) < 0){ //使用pipe创建匿名管道
> 		perror("pipe");
> 		return 1;
> 	}
> 	pid_t id = fork(); //使用fork创建子进程
> 	if (id == 0){
> 		//child 
> 		close(fd[0]); //子进程关闭读端
> 		char c = 'a';
> 		int count = 0;
> 		//子进程一直进行写入，一次写入一个字节
> 		while (1){
> 			write(fd[1], &c, 1);
> 			count++;
> 			printf("%d\n", count); //打印当前写入的字节数
> 		}
> 		close(fd[1]);
> 		exit(0);
> 	}
> 	//father
> 	close(fd[1]); //父进程关闭写端
> 
> 	//父进程不进行读取
> 
> 	waitpid(id, NULL, 0);
> 	close(fd[0]);
> 	return 0;
> }
> 
> ~~~
>
> 可以看到，在读端进程不进行读取的情况下，写端进程最多写65536字节的数据就被操作系统挂起了，也就是说，我当前Linux版本中管道的最大容量是65536字节。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110654299779.png)



##### 小结

一个进程，拥有自己的进程地址空间+页表，并且在内存打开了一些文件，前者独属于进程自己，后者是所有进程共享，都可以申请权限进行读写。管道就是依靠这个原理实现进程间通信的，具体如下：

- 父进程创建子进程，父进程的**进程地址空间会拷贝**给子进程一份，内存中的数据进行写时拷贝。
- 子进程PCB中的files_struct\*和父进程PCB中files_struct*相同，则父子进程打开的文件也相同，那么**父子进程就能打开同一份文件**。
- 父子进程就**打开了一份相同的内存中公共文件**，我们姑且把这个文件称作管道，因为还需要进行权限处理。
- 根据管道的理念：**单工通信**，若父进程拥有写权限，子进程拥有读权限。则**父进程关闭读权限，子进程关闭写权限**。
- 而且**管道文件不需要将数据刷新到磁盘中**，因为管道的数据仅仅在进程之间流通，仅仅在进程存在时有作用，没必要持久化刷新到磁盘中。

##### 其他

技巧

> 
>
> ![image-20230309220058304](%E5%9B%BE%E7%89%87/Linux/image-20230309220058304.png)
>
> 代表n被使用过，assert，仅在debug有用，release版本无用，（void）n代表在release版本使用过，防止被优化。



> snprintf：可额外构建字符串
>
> 

![image-20230309222446610](%E5%9B%BE%E7%89%87/Linux/image-20230309222446610.png)



为什么不使用全局变量通信

> 写会发生写时拷贝，父子进程的全局buffer不再指向同一块内存
>

##### 总结

> 1. 匿名管道是用来进行具有血缘关系的进程进行进程间通信的--常用父子通信
>
> 2. 父进程等一秒，子进程不等，但打印结果，子进程等了父进程，因为管道具有进程间协同功能，实现访问控制，同步
>
> 管道空，子进程不会读取，管道满，父进程不会写入
>
> 3. 管道提供的是面向流式的服通信务---面向字节流
>
> 4. 管道是基于文件的，文件的生命周期是随进程的，则管道的生命周期是随进程的，即打开管道的父子进程退出后，管道的生命就结束了。
>
> 5. 管道有人写，读的进程会等待写进程写数据，管道没人写，读的进程读完数据，read会返回0，代表文件读到了末端，读完了
>6. 管道是单向通信的，就是半双工通信的一种情况
> 
>>半双工：双向通信，同一时刻，只能有一个发，一个收
>> 全双工：双向通信，同一时刻，都可以发和收
> 
>7. 小实验性质
> 
>> ![image-20230310211213176](%E5%9B%BE%E7%89%87/Linux/image-20230310211213176.png)
> 
>> 

####  命名管道

##### 原理

**匿名管道只能用于具有共同祖先的进程（具有亲缘关系的进程）之间的通信**，通常，一个管道由一个进程创建，然后该进程调用fork，此后父子进程之间就可应用该管道。

如果要**实现两个毫不相关进程之间的通信，可以使用命名管道来做到**。

命名管道就是一种特殊类型的文件，**两个进程通过命名管道的文件名打开同一个管道文件**，此时这两个进程也就看到了同一份资源，进而就可以进行通信了。

**注意：**

1. **普通文件是很难做到通信的**，即便做到通信也无法解决一些安全问题。
2. 命名管道和匿名管道一样，都是**内存文件**，只不过**命名管道在磁盘有一个简单的映像，但这个映像的大小永远为0，因为命名管道和匿名管道都不会将通信数据刷新到磁盘当中。**

##### 简单使用

我们可以使用`mkfifo`命令创建一个命名管道。

~~~C++
[cl@VM-0-15-centos fifo]$ mkfifo fifo
~~~

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110747400390-168110747770593.png)

以看到，创建出来的文件的类型是`p`，代表该文件是命名管道文件。

使用这个命名管道文件，就能实现两个进程之间的通信了。我们在一个进程（进程A）中用shell脚本每秒向命名管道写入一个字符串，在另一个进程（进程B）当中用cat命令从命名管道当中进行读取。

现象就是当进程A启动后，进程B会每秒从命名管道中读取一个字符串打印到显示器上。这就证明了这两个毫不相关的进程可以通过命名管道进行数据传输，即通信。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168110751612295-168110751799698.png)

之前我们说过，当管道的读端进程退出后，写端进程再向管道写入数据就没有意义了，此时写端进程会被操作系统杀掉，在这里就可以很好的得到验证：当我们终止掉读端进程后，因为写端执行的循环脚本是由命令行解释器bash执行的，所以此时bash就会被操作系统杀掉，我们的云服务器也就退出了。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681107536705100.png)

##### 创建一个命名管道

在程序中创建命名管道使用mkfifo函数，mkfifo函数的函数原型如下：

~~~C++
int mkfifo(const char *pathname, mode_t mode);
~~~

mkfifo函数的第一个参数是pathname，表示要**创建的命名管道文件的相关信息**。

> - 若pathname以路径的方式给出，则将命名管道文件**创建在pathname路径下**。
> - 若pathname以文件名的方式给出，则将命名管道文件默认**创建在当前路径下**。（注意当前路径的含义）

mkfifo函数的第二个参数是mode，表示**创建命名管道文件的默认权限**。

> 例如，将mode设置为0666，则命名管道文件创建出来的权限如：prw-rw-rw-
>
> 但**实际上创建出来文件的权限值还会受到umask（文件默认掩码）的影响**，**实际创建出来文件的权限为：mode&(~umask)。**umask的默认值一般为0002，当我们设置mode值为0666时实际创建出来文件的权限为0664。
>
> 若想创建出来命名管道文件的权限值不受umask的影响，则需要在创建文件前使用`umask`函数将文件默认掩码设置为0。
>
> `umask(0); //将文件默认掩码设置为0`**这条命令是临时的，不会修改系统的umask。**

mkfifo函数的返回值。

> - 命名管道创建成功，返回0。
> - 命名管道创建失败，返回-1。

创建命名管道示例：

> 使用以下代码即可在当前路径下，创建出一个名为myfifo的命名管道。
>
> ~~~C++
> #include<cstdio>
> #include<sys/types.h>
> #include<sys/stat.h>
> 
> #define FILE_NAME "myfifo"
> 
> int main()
> {
>     umask(0);//临时变量
> 
>     if(mkfifo(FILE_NAME, 0666) < 0)
>     {
>         perror("mkfifo\n");
>         return 1;
>     }
> 
>     
> 
>     return 0;
> }
> 
> ~~~
>
> 运行代码后，命名管道myfifo就在当前路径下被创建了。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681107772385103.png)
>
> 

##### 命名管道的打开规则

1、如果当前打开操作是为读而打开FIFO时。

- O_NONBLOCK disable：阻塞直到有相应进程为写而打开该FIFO。
- O_NONBLOCK enable：立刻返回成功。

2、如果当前打开操作是为写而打开FIFO时。

- O_NONBLOCK disable：阻塞直到有相应进程为读而打开该FIFO。
- O_NONBLOCK enable：立刻返回失败，错误码为ENXIO。

##### 用命名管道实现serve&client通信

###### fflush

[fflush函数](https://blog.csdn.net/ShenHang_/article/details/114968557)

printf和cout打印函数的底层

> 和刷新策略有关：立即刷新，行刷新，满刷新
>
> 为了提高运行效率，所有的O操作不会立马执行，满足刷新策略才会进行IO动作，这样的刷新策略，可以减少IO交互。

fflush函数

> 立即刷新

###### 实现

实现服务端(server)和客户端(client)之间的通信之前，我们需要先让服务端运行起来，我们需要让服务端运行后创建一个命名管道文件，然后再以读的方式打开该命名管道文件，之后服务端就可以从该命名管道当中读取客户端发来的通信信息了。

服务端的代码如下：

~~~C++
#include "comm.hpp"


int main()
{
    umask(0);
    if(mkfifo(FILE_NAME, 0664) < 0) // 创建命名管道
    {
        perror("mkfifo");
        return 1;
    }

    int fd = open(FILE_NAME, O_RDONLY); // 读的方式打开管道
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    char buff[1024];
    while(true)
    {
        buff[0] = '\0';
        ssize_t s = read(fd, buff, sizeof(buff) - 1); // 读信息

        if(s > 0) // 正常读
        {
            buff[s] = '\0';
            cout << "client# " << buff << endl;
        }
        else if(s == 0) // 写端关闭
        {
            cout << "client quit!" << endl;
            break;
        }
        else // 读出错
        {
            cout << "read error!" << endl;
            break;
        }
    }

    close(fd);
    return 0;
}
~~~

而对于客户端来说，因为服务端运行起来后命名管道文件就已经被创建了，所以客户端只需以写的方式打开该命名管道文件，之后客户端就可以将通信信息写入到命名管道文件当中，进而实现和服务端的通信。

客户端的代码如下：

~~~C++
#include "comm.hpp"

int main()
{
    int fd = open(FILE_NAME, O_WRONLY); // 写打开
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    char buff[1024];
    while(true)
    {
        buff[0] = '\0';

        // 显示器刷新策略默认为行刷新，下面的输出语句正常清空下是在进程退出和满的是啥才会刷新(因为没有换行标识符出现)
        // 所以，需要fflush强制刷新，以满足程序需求
        cout << "Please Enter# ";
        fflush(stdout);

        ssize_t s = read(0, buff, sizeof(buff) - 1); // 从显示器读数据
        if(s > 0)
        {
            // buff[s] = '\0'; // 保存换行符
            buff[s - 1] = '\0'; // 不保存

            write(fd, buff, strlen(buff)); // 写到管道
        }
    }

    return 0;
}
~~~

对于如何让客户端和服务端使用同一个命名管道文件，这里我们可以让客户端和服务端包含同一个头文件，该头文件当中提供这个共用的命名管道文件的文件名，这样客户端和服务端就可以通过这个文件名，打开同一个命名管道文件，进而进行通信了。

共用头文件的代码如下：

~~~C++
#pragma once

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <fcntl.h>

using namespace std;

#define FILE_NAME "myfifo"
~~~

代码编写完毕后，先将服务端进程运行起来，之后我们就能在客户端看到这个已经被创建的命名管道文件。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108451274106.png)

接着再将客户端也运行起来，此时我们从客户端写入的信息被客户端写入到命名管道当中，服务端再从命名管道当中将信息读取出来打印在服务端的显示器上，该现象说明服务端是能够通过命名管道获取到客户端发来的信息的，换句话说，此时这两个进程之间是能够通信的。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108461525109.png)

当客户端和服务端运行起来时，我们还可以通过ps命令查看这两个进程的信息，可以发现这两个进程确实是两个毫不相关的进程，因为它们的PID和PPID都不相同。也就证明了，命名管道是可以实现两个毫不相关进程之间的通信的。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108475718112.png)

###### 服务端和客户端之间的退出关系

当客户端退出后，服务端将管道当中的数据读完后就再也读不到数据了，那么此时服务端也就会去执行它的其他代码了（在当前代码中是直接退出了）。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108535156115.png)

当服务端退出后，客户端写入管道的数据就不会被读取了，也就没有意义了，那么当客户端下一次再向管道写入数据时，就会收到操作系统发来的13号信号(SIGPIPE)，此时客户端就被操作系统强制杀掉了。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108544994118.png)

###### 通信是在内存当中进行的

若是我们只让客户端向管道写入数据，而服务端不从管道读取数据，那么这个管道文件的大小会不会发生变化呢？

~~~C++
//server.c
#include "comm.h"

int main()
{
	umask(0); //将文件默认掩码设置为0
	if (mkfifo(FILE_NAME, 0666) < 0){ //使用mkfifo创建命名管道文件
		perror("mkfifo");
		return 1;
	}
	int fd = open(FILE_NAME, O_RDONLY); //以读的方式打开命名管道文件
	if (fd < 0){
		perror("open");
		return 2;
	}
	while (1){
		//服务端不读取管道信息
	}
	close(fd); //通信完毕，关闭命名管道文件
	return 0;
}

~~~

可以看到，尽管服务端不读取管道当中的数据，但是管道当中的数据并没有被刷新到磁盘，使用`ll`命令看到命名管道文件的大小依旧为0，也就说明了双方进程之间的通信依旧是在内存当中进行的，和匿名管道通信是一样的。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108570179121.png)

##### 用命名管道实现派发计算任务

需要注意的是两个进程之间的通信，并不是简单的发送字符串而已，服务端是会对客户端发送过来的信息进行某些处理的。

这里我们以客户端向服务端派发计算任务为例，客户端通过管道向服务端发送双操作数的计算请求，服务端接收到客户端的信息后需要计算出相应的结果。

这里我们无需更改客户端的代码，只需改变服务端处理通信信息的逻辑即可。

~~~C++
#include "comm.hpp"

int main()
{
    umask(0); //将文件默认掩码设置为0
    if (mkfifo(FILE_NAME, 0666) < 0)
    { //使用mkfifo创建命名管道文件
        perror("mkfifo");
        return 1;
    }
    int fd = open(FILE_NAME, O_RDONLY); //打开命名管道文件
    if (fd < 0)
    {
        perror("open");
        return 2;
    }
    char msg[128];
    while (1)
    {
        msg[0] = '\0'; //每次读之前将msg清空
        //从命名管道当中读取信息
        ssize_t s = read(fd, msg, sizeof(msg) - 1);
        if (s > 0)
        {
            msg[s] = '\0'; //手动设置'\0'，便于输出
            printf("client# %s\n", msg);
            //服务端进行计算任务
            char *lable = "+-*/%";
            char *p = msg;
            int flag = 0;
            while (*p)
            {
                switch (*p)
                {
                case '+':
                    flag = 0;
                    break;
                case '-':
                    flag = 1;
                    break;
                case '*':
                    flag = 2;
                    break;
                case '/':
                    flag = 3;
                    break;
                case '%':
                    flag = 4;
                    break;
                }
                p++;
            }
            char *data1 = strtok(msg, "+-*/%"); // strtok 将msg分割成 由 ""中的一个或多个字符作为标记 的序列，第一次返回第一个序列
            char *data2 = strtok(NULL, "+-*/%");// 后续分割相同的字符串时， 第一个参数设为NULL， 说明该函数存在缓冲区
            int num1 = atoi(data1);
            int num2 = atoi(data2);
            int ret = 0;
            switch (flag)
            {
            case 0:
                ret = num1 + num2;
                break;
            case 1:
                ret = num1 - num2;
                break;
            case 2:
                ret = num1 * num2;
                break;
            case 3:
                ret = num1 / num2;
                break;
            case 4:
                ret = num1 % num2;
                break;
            }
            printf("%d %c %d = %d\n", num1, lable[flag], num2, ret); //打印计算结果
        }
        else if (s == 0)
        {
            printf("client quit!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }
    close(fd); //通信完毕，关闭命名管道文件
    return 0;
}
~~~

此时服务端接收到客户端的信息后，需要进行的处理动作就不是将其打印到显示器了，而是需要将信息经过进一步的处理，从而得到相应的结果。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108626505124.png)

##### 用命名管道实现进程遥控

比较有意思的是，我们可以通过一个进程来控制另一个进程的行为，比如我们从客户端输入命令到管道当中，再让服务端将管道当中的命令读取出来并执行。

下面我们只实现了让服务端执行不带选项的命令，若是想让服务端执行带选项的命令，可以对管道当中获取的命令进行解析处理。这里的实现非常简单，只需让服务端从管道当中读取命令后创建子进程，然后再进行进程程序替换即可。

这里也无需更改客户端的代码，只需改变服务端处理通信信息的逻辑即可。

~~~C++
#include "comm.hpp"

int main()
{
	umask(0); //将文件默认掩码设置为0
	if (mkfifo(FILE_NAME, 0666) < 0){ //使用mkfifo创建命名管道文件
		perror("mkfifo");
		return 1;
	}
	int fd = open(FILE_NAME, O_RDONLY); //以读的方式打开命名管道文件
	if (fd < 0){
		perror("open");
		return 2;
	}
	char msg[128];
	while (1){
		msg[0] = '\0'; //每次读之前将msg清空
		//从命名管道当中读取信息
		ssize_t s = read(fd, msg, sizeof(msg)-1);
		if (s > 0){
			msg[s] = '\0'; //手动设置'\0'，便于输出
			printf("client# %s\n", msg);
			if (fork() == 0){
				//child
				execlp(msg, msg, NULL); //进程程序替换 -- p：不需要带全路径，会使用环境变量的路径
				exit(1);
			}
			waitpid(-1, NULL, 0); //等待子进程
		}
		else if (s == 0){
			printf("client quit!\n");
			break;
		}
		else{
			printf("read error!\n");
			break;
		}
	}
	close(fd); //通信完毕，关闭命名管道文件
	return 0;
}
~~~

此时服务端接收到客户端的信息后，便进行进程程序替换，进而执行客户端发送过来的命令。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108656996127.png)

##### 用命名管道实现文件拷贝

这里我们再用命名管道实现一下文件的拷贝。

需要拷贝的文件是`file.txt`，该文件当中的内容如下：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108677423130.png)

我们要做的就是，让客户端将`file.txt`文件通过管道发送给服务端，在服务端创建一个`file-bat.txt`文件，并将从管道获取到的数据写入`file-bat.txt`文件当中，至此便实现了`file.txt`文件的拷贝。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108686579133.png)

其中服务端需要做的就是，创建命名管道并以读的方式打开该命名管道，再创建一个名为`file-bat.txt`的文件，之后需要做的就是将从管道当中读取到的数据写入到`file-bat.txt`文件当中即可。

服务端的代码如下：

~~~C++
#include "comm.hpp"

int main()
{
    umask(0); //将文件默认掩码设置为0
    if (mkfifo(FILE_NAME, 0666) < 0)
    { //使用mkfifo创建命名管道文件
        perror("mkfifo");
        return 1;
    }
    int fd = open(FILE_NAME, O_RDONLY); //以读的方式打开命名管道文件
    if (fd < 0)
    {
        perror("open");
        return 2;
    }
    //创建文件file-bat.txt，并以写的方式打开该文件
    int fdout = open("file-bat.txt", O_CREAT | O_WRONLY, 0666);
    if (fdout < 0)
    {
        perror("open");
        return 3;
    }
    char msg[12];
    while (true) // 若一次无法全部读取文件内容， 需要循环读取
    {
        msg[0] = '\0'; //每次读之前将msg清空
        //从命名管道当中读取信息
        ssize_t s = read(fd, msg, sizeof(msg) - 1);
        if (s > 0)
        {
            write(fdout, msg, s); //将读取到的信息写入到file-bat.txt文件当中
        }
        else if (s == 0)
        {
            printf("client quit!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }
    close(fd);    //通信完毕，关闭命名管道文件
    close(fdout); //数据写入完毕，关闭file-bat.txt文件
    return 0;
}

~~~

而客户端需要做的就是，以写的方式打开这个已经存在的命名管道文件，再以读的方式打开`file.txt`文件，之后需要做的就是将`file.txt`文件当中的数据读取出来并写入管道当中即可。

客户端的代码如下：

~~~C++
#include "comm.hpp"

int main()
{
    int fd = open(FILE_NAME, O_WRONLY); //以写的方式打开命名管道文件
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    int fdin = open("file.txt", O_RDONLY); //以读的方式打开file.txt文件
    if (fdin < 0)
    {
        perror("open");
        return 2;
    }
    char msg[12];
    while (true)
    {
        //从file.txt文件当中读取数据
        ssize_t s = read(fdin, msg, sizeof(msg));
        if (s > 0)
        {
            write(fd, msg, s); //将读取到的数据写入到命名管道当中
        }
        else if (s == 0)
        {
            printf("read end of file!\n");
            break;
        }
        else
        {
            printf("read error!\n");
            break;
        }
    }
    close(fd);   //通信完毕，关闭命名管道文件
    close(fdin); //数据读取完毕，关闭file.txt文件
    return 0;
}

~~~

共用头文件的代码和之前的一样，如下：

~~~C++
#pragma once

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <cstring>
#include <fcntl.h>

using namespace std;

#define FILE_NAME "myfifo"
~~~

编写完代码后，先运行服务端，再运行客户端，一瞬间这两个进程就相继运行结束了。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108732240136.png)

此时使用`ll`命令就可以看到，已经完成了`file.txt`文件的拷贝。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108743687139.png)

使用cat命令打印`file-bat.txt`文件当中的内容，发现和`file.txt`文件当中的内容相同，拷贝文件成功。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681108753816142.png)

##### 使用管道实现文件的拷贝有什么意义？

因为这里是使用管道在本地进行的文件拷贝，所以看似没什么意义，但我们若是将这里的管道想象成“网络”，将客户端想象成“Windows Xshell”，再将服务端想象成“centos服务器”。那我们此时实现的就是文件上传的功能，若是将方向反过来，那么实现的就是文件下载的功能。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109053671145.png)

#### 命名管道和匿名管道的区别

- 匿名管道由**pipe函数创建并打开**。
- 命名管道**由mkfifo函数创建，由open函数打开**。
- FIFO（命名管道）与pipe（匿名管道）之间唯一的区别在于它们创建与打开的方式不同，一旦这些工作完成之后，它们具有相同的语义。

#### 命令行当中的管道

现有`data.txt`文件，文件当中的内容如下：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109162695148.png)

我们可以利用管道（“|”）同时使用cat命令和grep命令，进而实现文本过滤。

~~~C++
[cl@VM-0-15-centos pipe]$ cat data.txt | grep dragon
~~~

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109182819151.png)

那么在命令行当中的管道（“|”）到底是匿名管道还是命名管道呢？

由于匿名管道只能用于有亲缘关系的进程之间的通信，而命名管道可以用于两个毫不相关的进程之间的通信，因此我们可以先看看命令行当中用管道（“|”）连接起来的各个进程之间是否具有亲缘关系。

下面通过管道（“|”）连接了三个进程，通过ps命令查看这三个进程可以发现，这三个进程的PPID是相同的，也就是说它们是由同一个父进程创建的子进程。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109211767154.png)

而它们的父进程实际上就是命令行解释器，这里为`bash`。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109223022157.png)

也就是说，由管道（“|”）连接起来的各个进程是有亲缘关系的，它们之间互为兄弟进程。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681109233722160.png)

现在我们已经知道了，若是两个进程之间采用的是命名管道，那么在磁盘上必须有一个对应的命名管道文件名，而实际上我们在使用命令的时候并不存在类似的命名管道文件名，因此命令行上的管道实际上是匿名管道。

### system V

#### 共享内存

##### 原理

共享内存可以让不同进程看到同一份资源的方式：**在物理内存当中申请一块内存空间，然后将这块内存空间分别与各个进程各自的页表之间建立映射**，再在虚拟地址空间当中开辟空间并将虚拟地址填充到各自页表的对应位置，使得虚拟地址和物理地址之间建立起对应关联起来。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681111900059163.png)

**注意：**

这里所说的开辟物理空间、建立映射等操作都是调用系统接口完成的，也就是说这些动作都由操作系统来完成。

##### 共享内存数据结构

在系统当中可能会有大量的进程在进行通信，因此系统当中就可能存在大量的共享内存，那么操作系统必然要对其进行管理，所以**共享内存除了在内存当中真正开辟空间之外，系统一定还要为共享内存维护相关的内核数据结构**。

共享内存的数据结构如下：

~~~C++
struct shmid_ds {
	struct ipc_perm     shm_perm;   /* operation perms */
	int         shm_segsz;  /* size of segment (bytes) */
	__kernel_time_t     shm_atime;  /* last attach time */
	__kernel_time_t     shm_dtime;  /* last detach time */
	__kernel_time_t     shm_ctime;  /* last change time */
	__kernel_ipc_pid_t  shm_cpid;   /* pid of creator */
	__kernel_ipc_pid_t  shm_lpid;   /* pid of last operator */
	unsigned short      shm_nattch; /* no. of current attaches */
	unsigned short      shm_unused; /* compatibility */
	void            *shm_unused2;   /* ditto - used by DIPC */
	void            *shm_unused3;   /* unused */
};

~~~

当我们申请了一块共享内存后，为了让要实现通信的进程能够看到同一个共享内存，因此每一个共享内存被申请时都有一个key值，这个**key值用于标识系统中共享内存的唯一性**。

可以看到上面共享内存数据结构的第一个成员是shm_perm，shm_perm是一个ipc_perm类型的结构体变量，每个共享内存的key值存储在shm_perm这个结构体变量当中，其中ipc_perm结构体的定义如下：

~~~C++
struct ipc_perm{
	__kernel_key_t  key;
	__kernel_uid_t  uid;
	__kernel_gid_t  gid;
	__kernel_uid_t  cuid;
	__kernel_gid_t  cgid;
	__kernel_mode_t mode;
	unsigned short  seq;
};

~~~

**记录一下：**

共享内存的数据结构`shmid_ds`和`ipc_perm`结构体分别在/usr/include/linux/shm.h和/usr/include/linux/ipc.h中定义。

##### 共享内存的建立与释放

共享内存的建立大致包括以下两个过程：

1. **在物理内存当中申请共享内存空间。**
2. **将申请到的共享内存挂接到地址空间，即建立映射关系。**

共享内存的释放大致包括以下两个过程：

1. **将共享内存与地址空间去关联，即取消映射关系。**
2. **释放共享内存空间，即将物理内存归还给系统。**

###### 共享内存的创建

创建共享内存我们需要用shmget函数，shmget函数的函数原型如下：

~~~C++
int shmget(key_t key, size_t size, int shmflg);
~~~

shmget函数的参数说明：

- 第一个参数key，表示待创建共享内存在系统当中的唯一标识。
- 第二个参数size，表示待创建共享内存的大小。
- 第三个参数shmflg，表示创建共享内存的方式。

shmget函数的返回值说明：

- shmget调用成功，返回一个有效的共享内存标识符（用户层标识符）。
- shmget调用失败，返回-1。

**注意：** 我们把**具有标定某种资源能力的东西叫做句柄**，而这里shmget函数的返回值实际上就是共享内存的句柄，这个句柄可以在用户层标识共享内存，当共享内存被创建后，我们在后续使用共享内存的相关接口时，都是需要通过这个句柄对指定共享内存进行各种操作。

**传入shmget函数的第一个参数key，需要我们使用ftok函数进行获取**

> ftok函数的函数原型如下：
>
> ```cpp
> #include <sys/types.h>
> #include <sys/ipc.h>
> 
> key_t ftok(const char *pathname, int proj_id);
> ```
>
> ftok函数的作用就是，**将一个已存在的路径名pathname和一个整数标识符proj_id转换成一个key值，称为IPC键值**，在使用shmget函数获取共享内存时，这个key值会被填充进维护共享内存的数据结构当中。**需要注意的是，pathname所指定的文件必须存在且可存取。**
>
> 注意：
>
> - 使用**ftok函数生成的key值可能会产生冲突**，此时可以对传入ftok函数的参数进行修改。
> - 需要进行通信的各个进程，在使用ftok函数获取key值时，**都需要采用同样的路径名和和整数标识符**，进而生成同一种key值，然后才能找到同一个共享资源。

**传入shmget函数的第三个参数shmflg，常用的组合方式有以下两种：**

> ![image-20230410153738413](%E5%9B%BE%E7%89%87/Linux/image-20230410153738413.png)
>
> **换句话说：**
>
> - 使用组合IPC_CREAT，一定会获得一个共享内存的句柄，但无法确认该共享内存是否是新建的共享内存。
> - 使用组合IPC_CREAT | IPC_EXCL，只有shmget函数调用成功时才会获得共享内存的句柄，并且该共享内存一定是新建的共享内存。

至此我们就可以使用ftok和shmget函数创建一块共享内存了，创建后我们可以将共享内存的key值和句柄进行打印，以便观察，代码如下：

~~~C++
#include <stdio.h>
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>
		
#define PATHNAME "/home/qlz/LINUX/Review/IPC/systemV/test1.cpp" //路径名 -- 必须是存在的合法路径
#define PROJ_ID 0x6666 //整数标识符
#define SIZE 4096 //共享内存的大小

int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
	if (key < 0){
		perror("ftok");
		return 1;
	}
	int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL); //创建新的共享内存
	if (shm < 0){
		perror("shmget");
		return 2;
	}
	printf("key: %x\n", key); //打印key值
	printf("shm: %d\n", shm); //打印句柄
	return 0;
}

~~~

该代码编写完毕运行后，我们可以看到输出的key值和句柄值：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112306801166.png)

Linux当中，我们可以使用`ipcs`命令查看有关进程间通信设施的信息。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112321054169.png)

单独使用`ipcs`命令时，会默认列出消息队列、共享内存以及信号量相关的信息，若只想查看它们之间某一个的相关信息，可以选择携带以下**选项：**

- -q：列出消息队列相关信息。
- -m：列出共享内存相关信息。
- -s：列出信号量相关信息。

例如，携带-m选项查看共享内存相关信息：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112344310172.png)

此时，根据`ipcs`命令的查看结果和我们的输出结果可以确认，共享内存已经创建成功了。

`ipcs`命令输出的每列信息的含义如下：

![image-20230410153923219](%E5%9B%BE%E7%89%87/Linux/image-20230410153923219.png)

**注意：** **key是在内核层面上保证共享内存唯一性的方式，而shmid是在用户层面上保证共享内存的唯一性，key和shmid之间的关系类似于fd和FILE*之间的的关系。**

###### 共享内存的释放

通过上面创建共享内存的实验可以发现，当我们的进程运行完毕后，申请的共享内存依旧存在，并没有被操作系统释放。实际上，管道是生命周期是随进程的，而共享内存的生命周期是随内核的，也就是说进程虽然已经退出，但是曾经创建的共享内存不会随着进程的退出而释放。

这说明，如果进程不主动删除创建的共享内存，那么共享内存就会一直存在，直到关机重启（system V IPC都是如此），同时也说明了IPC资源是由内核提供并维护的。

此时我们若是要将创建的共享内存释放，有两个方法，**一就是使用命令释放共享内存，二就是在进程通信完毕后调用释放共享内存的函数进行释放**。

**使用命令释放共享内存资源**

> 我们可以使用`ipcrm -m shmid`命令释放指定id的共享内存资源。
>
> ~~~C++
> [cl@VM-0-15-centos shm]$ ipcrm -m 8
> ~~~
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112454296175.png)
>
> **注意：** 指定删除时使用的是共享内存的用户层id，即列表当中的shmid。

**使用程序释放共享内存资源**

> 控制共享内存我们需要用shmctl函数，shmctl函数的函数原型如下：
>
> ```cpp
> int shmctl(int shmid, int cmd, struct shmid_ds *buf);
> ```
>
> shmctl函数的**参数说明：**
>
> - 第一个参数shmid，表示所控制共享内存的用户级标识符。
> - 第二个参数cmd，表示具体的控制动作。
> - 第三个参数buf，用于获取或设置所控制共享内存的数据结构。
>
> shmctl函数的**返回值说明：**
>
> - shmctl调用成功，返回0。
> - shmctl调用失败，返回-1。
>
> 其中，作为shmctl函数的第二个参数传入的常用的选项有以下三个：
>
> ![image-20230410154206125](%E5%9B%BE%E7%89%87/Linux/image-20230410154206125.png)
>
> 例如，在以下代码当中，共享内存被创建，两秒后程序自动移除共享内存，再过两秒程序就会自动退出。
>
> ~~~C++
> #include <stdio.h>
> #include <sys/types.h> 
> #include <sys/ipc.h> 
> #include <sys/shm.h> 
> #include <unistd.h>
> 		
> #define PATHNAME "/home/qlz/LINUX/Review/IPC/systemV/test1.cpp" //路径名 -- 必须是存在的合法路径
> #define PROJ_ID 0x6666 //整数标识符
> #define SIZE 4096 //共享内存的大小
> 
> int main()
> {
> 	key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
> 	if (key < 0){
> 		perror("ftok");
> 		return 1;
> 	}
> 	int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL); //创建新的共享内存
> 	if (shm < 0){
> 		perror("shmget");
> 		return 2;
> 	}
> 	printf("key: %x\n", key); //打印key值
> 	printf("shm: %d\n", shm); //打印句柄
> 
>     sleep(2);
> 
>     shmctl(shm, IPC_RMID, nullptr);
> 
>     sleep(2);
> 
> 	return 0;
> }
> 
> ~~~
>
> 我们可以在程序运行时，使用以下监控脚本时刻关注共享内存的资源分配情况：
>
> ~~~C++
> [cl@VM-0-15-centos shm]$ while :; do ipcs -m;echo "###################################";sleep 1;done
> ~~~
>
> 通过监控脚本可以确定共享内存确实创建并且成功释放了。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112566867178.png)
>
> 

##### 共享内存的关联

将共享内存连接到进程地址空间我们需要用shmat函数，shmat函数的函数原型如下：

~~~C++
void *shmat(int shmid, const void *shmaddr, int shmflg);
~~~

shmat函数的**参数说明：**

- 第一个参数shmid，表示待关联共享内存的用户级标识符（即上述的shm）。
- 第二个参数shmaddr，指定共享内存映射到进程地址空间的某一地址，通常设置为NULL，表示让内核自己决定一个合适的地址位置。
- 第三个参数shmflg，表示关联共享内存时设置的某些属性。

shmat函数的**返回值说明：**

- shmat调用成功，返回共享内存映射到进程地址空间中的起始地址。
- shmat调用失败，返回(void*)-1。

其中，作为shmat函数的第三个参数传入的常用的选项有以下三个：

![image-20230410154354761](%E5%9B%BE%E7%89%87/Linux/image-20230410154354761.png)

这时我们可以尝试使用shmat函数对共享内存进行关联。

~~~C++
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define PATHNAME "/home/cl/Linuxcode/IPC/shm/server.c" //路径名

#define PROJ_ID 0x6666 //整数标识符
#define SIZE 4096 //共享内存的大小

int main()
{
	key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
	if (key < 0){
		perror("ftok");
		return 1;
	}
	int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL); //创建新的共享内存
	if (shm < 0){
		perror("shmget");
		return 2;
	}
	printf("key: %x\n", key); //打印key值
	printf("shm: %d\n", shm); //打印句柄

	printf("attach begin!\n");
	sleep(2);
	char* mem = shmat(shm, NULL, 0); //关联共享内存
	if (mem == (void*)-1){
		perror("shmat");
		return 1;
	}
	printf("attach end!\n");
	sleep(2);
	
	shmctl(shm, IPC_RMID, NULL); //释放共享内存
	return 0;
}

~~~

代码运行后发现关联失败，主要原因是我们使用shmget函数创建共享内存时，并没有对创建的共享内存设置权限，所以创建出来的共享内存的默认权限为0，即什么权限都没有，因此server进程没有权限关联该共享内存。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112674892181.png)

我们应该在使用shmget函数创建共享内存时，在其第三个参数处设置共享内存创建后的权限，权限的设置规则与设置文件权限的规则相同。

~~~C++
int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); //创建权限为0666的共享内存

~~~

此时再运行程序，即可发现关联该共享内存的进程数由0变成了1，而共享内存的权限显示也不再是0，而是我们设置的666权限。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112696384184.png)

##### 共享内存的去关联

取消共享内存与进程地址空间之间的关联我们需要用shmdt函数，shmdt函数的函数原型如下：

~~~C++
int shmdt(const void *shmaddr);
~~~

shmdt函数的**参数说明：**

- 待去关联共享内存的起始地址，即调用shmat函数时得到的起始地址。

shmdt函数的**返回值说明：**

- shmdt调用成功，返回0。
- shmdt调用失败，返回-1。

现在我们就能够取消共享内存与进程之间的关联了。

~~~C++
#include<cstdio>

#include<unistd.h>

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define PATHNAME "/home/qlz/LINUX/IPC/systemV/test1.cc"//指定一个文件路径，并且是，存在且可以获取的文件的路径

#define PROJ_ID 0x666//id
#define SIZE 4096//共享内存大小

int main()
{
    key_t key = ftok(PATHNAME, PROJ_ID);//1. 生成key
    if(key < 0)
    {
        perror("ftok\n");
        return 2;
    }

    int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666);//2. 创建共享内存，设置权限， 并且只接受 新创建的共享内存
    if(shm < 0)
    {
        perror("shmget");
        return 2;
    }

    printf("key: %x\n", key);
    printf("shm: %x\n", shm);

    printf("attach begin!\n");
    sleep(2);

    char *memory = (char*)shmat(shm, NULL, 0);//3. 进程关联共享内存，返回的是 在mmap中的映射地址
    if(memory == (void*)-1)
    {
        shmctl(shm, IPC_RMID, NULL);//释放， 且不关心共享内存状态

        perror("shmat error\n");
        return 1;
    }

    printf("attach end!\n");
    sleep(2);



    printf("detach begin!\n");
    sleep(2);

    shmdt(memory);//4. 去关联

    printf("detach end!\n");
    sleep(2);

    shmctl(shm, IPC_RMID, NULL);//5. 释放， 且不关心共享内存状态
    sleep(2);

    return 0;
}
~~~

运行程序，通过监控即可发现该共享内存的关联数由1变为0的过程，即取消了共享内存与该进程之间的关联。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112826113187.png)

**注意：** 将共享内存段与当前进程脱离不等于删除共享内存，只是取消了当前进程与该共享内存之间的联系。

##### 用共享内存实现serve&client通信

在知道了共享内存的创建、关联、去关联以及释放后，现在可以尝试让两个进程通过共享内存进行通信了。在让两个进程进行通信之前，我们可以先测试一下这两个进程能否成功挂接到同一个共享内存上。

服务端负责创建共享内存，创建好后将共享内存和服务端进行关联，之后进入死循环，便于观察服务端是否挂接成功。

服务端代码如下：

~~~C++
#include "comm.hpp"

int main()
{
    key_t key = ftok(PATHNAME, PROJ_ID); //获取key值
    if (key < 0)
    {
        perror("ftok");
        return 1;
    }

    int shm = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); //创建新的共享内存
    if (shm < 0)
    {
        perror("shmget");
        return 2;
    }

    printf("key: %x\n", key); //打印key值
    printf("shm: %d\n", shm); //打印共享内存用户层id

    void *mem = shmat(shm, NULL, 0); //关联共享内存

    while (true)
    {
        printf("client# %s\n", (char*)mem);
        sleep(1);
    }

    shmdt(mem); //共享内存去关联

    shmctl(shm, IPC_RMID, NULL); //释放共享内存
    return 0;
}

~~~

客户端只需要直接和服务端创建的共享内存进行关联即可，之后也进入死循环，便于观察客户端是否挂接成功。

客户端代码如下：

~~~C++
#include "comm.hpp"

int main()
{
    key_t key = ftok(PATHNAME, PROJ_ID); //获取与server进程相同的key值
    if (key < 0)
    {
        perror("ftok");
        return 1;
    }
    int shm = shmget(key, SIZE, IPC_CREAT); //获取server进程创建的共享内存的用户层id
    if (shm < 0)
    {
        perror("shmget");
        return 2;
    }

    printf("key: %x\n", key); //打印key值
    printf("shm: %d\n", shm); //打印共享内存用户层id

    char *mem = (char*)shmat(shm, NULL, 0); //关联共享内存

    int i = 0;
    while (i < 26)
    {
        mem[i] = 'A' + i;
        i++;
        mem[i] = '\0';
        sleep(1);
    }

    shmdt(mem); //共享内存去关联
    return 0;
}

~~~

为了让服务端和客户端在使用ftok函数获取key值时，能够得到同一种key值，那么服务端和客户端传入ftok函数的路径名和和整数标识符必须相同，这样才能生成同一种key值，进而找到同一个共享资源进行挂接。这里我们可以将这些需要共用的信息放入一个头文件当中，服务端和客户端共用这个头文件即可。

共用头文件的代码如下：

~~~C++
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

using namespace std;

#define PATHNAME "/home/qlz/LINUX/Review/IPC/systemV/test1.cpp" //路径名 -- 必须是存在的合法路径
#define PROJ_ID 0x6666                                          //整数标识符
#define SIZE 4096                                               //共享内存的大小
~~~

先后运行服务端和客户端后，通过监控脚本可以看到服务端和客户端所关联的是同一个共享内存，共享内存关联的进程数也是2，表示服务端和客户端挂接共享内存成功。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112905127190.png)

此时我们就可以让服务端和客户端进行通信了，这里以简单的发送字符串为例。

客户端不断向共享内存写入数据：

~~~C++
//客户端不断向共享内存写入数据
int i = 0;
while (1){
	mem[i] = 'A' + i;
	i++;
	mem[i] = '\0';
	sleep(1);
}

~~~

服务端不断读取共享内存当中的数据并输出：

```cpp
//服务端不断读取共享内存当中的数据并输出
while (1){
	printf("client# %s\n", mem);
	sleep(1);
}
```

此时先运行服务端创建共享内存，当我们运行客户端时服务端就开始不断输出数据，说明服务端和客户端是能够正常通信的。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112953126193.png)

**记得通过指令关闭未关闭的共享内存！**

### 共享内存与管道进行对比

当共享内存创建好后就不再需要调用系统接口进行通信了，而管道创建好后仍需要read、write等系统接口进行通信。

实际上，**共享内存是所有进程间通信方式中最快的一种通信方式**。

我们先来看看管道通信：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112977544196.png)

从这张图可以看出，使用管道通信的方式，将一个文件从一个进程传输到另一个进程需要进行**四次拷贝操作：**

1. 服务端将信息从输入文件复制到服务端的临时缓冲区中。
2. 将服务端临时缓冲区的信息复制到管道中。
3. 客户端将信息从管道复制到客户端的缓冲区中。
4. 将客户端临时缓冲区的信息复制到输出文件中。

我们再来看看共享内存通信：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_ZHJvaWRzYW5zZmFsbGJhY2s,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681112993924199.png)

从这张图可以看出，使用共享内存进行通信，将一个文件从一个进程传输到另一个进程只需要进行两次拷贝操作：

从输入文件到共享内存。

- 从共享内存到输出文件。
- 所以共享内存是所有进程间通信方式中最快的一种通信方式，因为该通信方式需要进行的拷贝次数最少。

但是**共享内存也是有缺点的，我们知道管道是自带同步与互斥机制的，但是共享内存并没有提供任何的保护机制，包括同步与互斥。**


## 临界资源/临界区

![image-20230713185658937](%E5%9B%BE%E7%89%87/Linux/image-20230713185658937.png)

## 信号

**信号和信号量是两个不同的东西，没有关系。**

### 信号入门

#### 生活角度的信号

- 你在网上买了很多件商品，在等待不同商品快递的到来。但即便快递还没有到来，你也知道**快递到了的时候应该怎么处理快递**，也就是你能“识别快递”。
- 当快递到达目的地了，你收到了快递到来的通知，但是你不一定要马上下楼取快递，也就是说**取快递的行为并不是一定要立即执行，可以理解成在“在合适的时候去取”**。
- **在你收到快递到达的通知，再到你拿到快递期间，是有一个时间窗口的**，在这段时间内你并没有拿到快递，但是你知道快递已经到了，**本质上**是你“记住了有一个快递要去取”。
- 当你时间合适，**顺利拿到快递之后，就要开始处理快递了，而处理快递的方式有三种**：1、执行默认动作（打开快递，使用商品）2、执行自定义动作（快递是帮别人买的，你要将快递交给他）3、忽略（拿到快递后，放在一边继续做自己的事）。
- 快递到来的整个过程，对你来讲是**异步**的，你不能确定你的快递什么时候到。

#### 技术应用角度的信号

编写以下程序并运行：

~~~C++
#include <stdio.h>
#include <unistd.h>

int main()
{
	while (1){
		printf("hello signal!\n");
		sleep(1);
	}
	return 0;
}

~~~

我们知道该程序的运行结果就是死循环地进行打印，而对于死循环来说，最好的方式就是使用Ctrl+C对其进行终止。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16.png)



###### 为什么使用Ctrl+C后，该进程就终止了？

实际上当用户按Ctrl+C时，这个键盘输入**会产生一个硬中断，被操作系统获取并解释成信号**（Ctrl+C被解释成2号信号），然后操作系统将2号信号**发送给目标前台进程**，当前台进程收到2号信号后就会退出。

我们可以使用signal函数对2号信号进行捕捉，证明当我们按Ctrl+C时进程确实是收到了2号信号。使用signal函数时，我们需要传入两个参数，第一个是需要捕捉的信号编号，第二个是对捕捉信号的处理方法，该处理方法的参数是int，返回值是void。

例如，下面的代码中将2号信号进行了捕捉，当该进程运行起来后，若该进程收到了2号信号就会打印出收到信号的信号编号。

~~~C++
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
	printf("get a signal:%d\n", sig);
}

int main()
{
	signal(2, handler); //注册2号信号
	while (1){
		printf("hello signal!\n");
		sleep(1);
	}
	return 0;
}

~~~

此时当该进程收到2号信号后，就会执行我们给出的handler方法，而不会像之前一样直接退出了，因为此时我们已经将2号信号的处理方式由默认改为了自定义了。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681113692959204.png)

由此也证明了，当我们按Ctrl+C时进程确实是收到了2号信号。

注意：

- **Ctrl+C产生的信号只能发送给前台进程**。在一个命令后面加个&就可以将其放到后台运行，这样Shell就不必等待进程结束就可以接收新的命令，启动新的进程。
- **Shell可以同时运行一个前台进程和任意多个后台进程，但是只有前台进程才能接到像Ctrl+C这种控制键产生的信号**。
- 前台进程在运行过程中，用户随时可能按下Ctrl+C而产生一个信号，也就是说该进程的用户空间代码执行到任何地方都可能收到SIGINT信号而终止，所以**信号相对于进程的控制流程来说是异步的**。
- 信号是进程之间事件异步通知的一种方式，属于**软中断**。

#### **信号的发送与记录**

我们使用`kill -l`命令可以查看Linux当中的信号列表。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681113747467207.png)

其中**1\-31号信号是普通信号，34~64号信号是实时信号**，普通信号和实时信号各自都有31个，每个信号都有一个编号和一个宏定义名称：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681113772862210-1681113774444213.png)



##### 信号是如何记录的？

实际上，当一个进程接收到某种信号后，该信号是被记录在该进程的进程控制块当中的。我们都知道进程控制块本质上就是一个结构体变量，而对于信号来说我们主要就是记录某种信号是否产生，因此，我们可以用一个32位的位图来记录信号是否产生。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681113847026218.png)

其中比特位的位置代表信号的编号，而比特位的内容就代表是否收到对应信号，比如第6个比特位是1就表明收到了6号信号。

##### 信号是如何产生的？

一个进程收到信号，本质就是该进程内的信号位图被修改了，也就是该进程的数据被修改了，而只有操作系统才有资格修改进程的数据，因为操作系统是进程的管理者。也就是说，**信号的产生本质上就是操作系统直接去修改目标进程的task_struct中的信号位图**。

注意： **信号只能由操作系统发送，但信号发送的方式有多种**。

#### 信号处理常见方式概述

1. 执行该信号的**默认处理**动作。
2. 提供一个信号处理函数，要求内核在处理该信号时切换到用户态执行这个处理函数，这种方式称为**捕捉（Catch）一个信号**。
3. **忽略该信号**。

在Linux当中，我们可以通过man手册查看各个信号默认的处理动作。

~~~C++
[cl@VM-0-15-centos SIG]$ man 7 signal
~~~

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681113811239215.png)



### 产生信号

#### 通过终端按键产生信号

当面对下面的死循环程序时，我们都知道可以按Ctrl+C可以终止该进程。

~~~C++
#include <stdio.h>
#include <unistd.h>

int main()
{
	while (1){
		printf("hello signal!\n");
		sleep(1);
	}
	return 0;
}

~~~

但实际上除了按Ctrl+C之外，按Ctrl+\也可以终止该进程。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114120722221.png)

###### 按Ctrl+C终止进程和按Ctrl+\终止进程，有什么区别？

按Ctrl+C实际上是向进程发送2号信号SIGINT，而按Ctrl+\实际上是向进程发送3号信号SIGQUIT。查看这两个信号的默认处理动作，可以看到这两个信号的Action是不一样的，2号信号是Term，而3号信号是Core。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114138072224.png)

Term和Core都代表着终止进程，但是Core在终止进程的时候会进行一个动作，那就是**核心转储**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114149275227.png)

###### ##### 什么是核心转储？

**在云服务器中，核心转储是默认被关掉的**，我们可以通过**使用`ulimit -a`命令查看当前资源限制的设定**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114208568230.png)

其中，第一行显示core文件的大小为0，即表示核心转储是被关闭的。

我们**可以通过`ulimit -c size`命令来设置core文件的大小**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114218411233.png)

core文件的大小设置完毕后，就相当于将核心转储功能打开了。此时如果我们再使用Ctrl+\对进程进行终止，就会发现终止进程后会显示`core dumped`。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114230446236.png)

并且会在当前路径下生成一个core文件，该文件以一串数字为后缀，而这一串数字实际上就是**发生这一次核心转储的进程的PID**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114240917239.png)

**说明一下：** **ulimit命令改变的是Shell进程的Resource Limit**，但myproc进程的PCB是由Shell进程复制而来的，子进程继承父进程的，所以也具有和Shell进程相同的Resource Limit值。

###### 核心转储功能有什么用？

当我们的代码出错了，我们最关心的是我们的代码是什么原因出错的。如果我们的代码运行结束了，那么我们可以通过退出码来判断代码出错的原因，而如果一个代码是在运行过程中出错的，那么我们也要有办法判断代码是什么原因出错的。

当我们的程序在运行过程中崩溃了，我们一般会通过调试来进行逐步查找程序崩溃的原因。而在某些特殊情况下，我们会用到核心转储，**核心转储指的是操作系统在进程收到某些信号而终止运行时，将该进程地址空间的内容以及有关进程状态的其他信息转而存储到一个磁盘文件当中，这个磁盘文件也叫做核心转储文件，一般命名为core.pid**。

而**核心转储的目的就是为了在调试时，方便问题的定位**。

###### 如何运用核心转储进行调试？

我们用下面这段代码进行演示：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114277562242-1681114280496245.png)

很明显，该代码当中出现了除0错误，该程序运行3秒后便会崩溃。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114292834247.png)

此时我们便可以在当前目录下看到核心转储时生成的core文件。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114300574250.png)

使用**gdb对当前可执行程序进行调试**，然后直接使用`core-file core文件`命令加载core文件，即可判断出该程序在终止时收到了8号信号，并且定位到了产生该错误的具体代码。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114310011253.png)

**说明一下：** 事后用调试器检查core文件以查清错误原因，这种调试方式叫做事后调试。

###### core dump标志

还记得**进程等待函数waitpid函数的第二个参数**吗：

~~~C++
pid_t waitpid(pid_t pid, int *status, int options);
~~~

waitpid函数的第二个参数status是一个输出型参数，用于获取子进程的退出状态。status是一个整型变量，但status不能简单的当作整型来看待，status的不同比特位所代表的信息不同，具体细节如下（只关注status低16位比特位）：
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/57b5067b9b91426fac46b308dba958d9.png)

**若进程是正常终止的，那么status的次低8位就表示进程的退出状态，即退出码。若进程是被信号所杀，那么status的低7位表示终止信号，而第8位比特位是core dump标志，即进程终止时是否进行了核心转储。**
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114357368258.png)

打开Linux的核心转储功能，并编写下列代码。代码中父进程使用fork函数创建了一个子进程，子进程所执行的代码当中存在野指针问题，当子进程执行到*p = 100时，必然会被操作系统所终止并在终止时进行核心转储。此时父进程使用waitpid函数便可获取到子进程退出时的状态，根据status的第7个比特位便可得知子进程在被终止时是否进行了核心转储。

~~~C++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	if (fork() == 0){
		//child
		printf("I am running...\n");
		int *p = NULL;
		*p = 100;
		exit(0);
	}
	//father
	int status = 0;
	waitpid(-1, &status, 0);
	printf("exitCode:%d, coreDump:%d, signal:%d\n",
		(status >> 8) & 0xff, (status >> 7) & 1, status & 0x7f);
	return 0;
}

~~~

可以看到，所获取的status的第7个比特位为1，即可说明子进程在被终止时进行了核心转储。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114386970261.png)

因此，core dump标志实际上就是用于表示程序崩溃的时候是否进行了核心转储。

###### 其他组合按键？

我们可以通过以下代码，将1~31号信号全部进行捕捉，将收到信号后的默认处理动作改为打印收到信号的编号。

~~~C++
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signal)
{
	printf("get a signal:%d\n", signal);
}
int main()
{
	int signo;
	for (signo = 1; signo <= 31; signo++){
		signal(signo, handler);
	}
	while (1){
		sleep(1);
	}
	return 0;
}
~~~

此时，当我们按下组合按键Ctrl+C、Ctrl+\、Ctrl+Z后，便可以得知这些组合按键分别是向前台进程发送几号信号了。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114433996264.png)

但如果我们此时向该进程发送9号信号，该进程并不会打印收到了9号信号，而是执行收到9号信号后的默认处理动作，即被终止。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114442205267.png)

**说明：** **有些信号是不能被捕捉的，比如9号信号**。因为如果所有信号都能被捕捉的话，那么进程就可以将所有信号全部进行捕捉并将动作设置为忽略，此时该进程将无法被杀死，即便是操作系统。

#### 通过系统函数向进程发信号

当我们要使用kill命令向一个进程发送信号时，我们可以以`kill -信号名 进程ID`的形式进行发送。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114497617270.png)

也可以以`kill -信号编号 进程ID`的形式进行发送。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114507847273.png)

###### kill函数

实际上kill命令是通过调用kill函数实现的，kill函数可以给指定的进程发送指定的信号，kill函数的函数原型如下：

```cpp
int kill(pid_t pid, int sig);
```

kill函数用于向进程ID为`pid`的进程发送`sig`号信号，如果信号发送成功，则返回0，否则返回-1。

我们可以用kill函数模拟实现一个kill命令，实现逻辑如下：

~~~C++
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

void Usage(char* proc)
{
	printf("Usage: %s pid signo\n", proc);
}
int main(int argc, char* argv[])
{
	if (argc != 3){
		Usage(argv[0]);
		return 1;
	}
	pid_t pid = atoi(argv[1]);
	int signo = atoi(argv[2]);
	kill(pid, signo);
	return 0;
}
~~~

为了让生成的可执行程序在执行时不用带上路径，我们可以将当前路径导入环境变量PATH当中。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114542096276.png)

此时我们便模拟实现了一个kill命令，该命令的使用方式为`mykill 进程ID 信号编号`。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114555345279.png)

###### raise函数

**raise函数可以给当前进程发送指定信号，即自己给自己发送信号**，raise函数的函数原型如下：

```cpp
int raise(int sig);
```

raise函数用于给当前进程发送`sig`号信号，如果信号发送成功，则返回0，否则返回一个非零值。

例如，下列代码当中用raise函数每隔一秒向自己发送一个2号信号。

~~~C++
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
	printf("get a signal:%d\n", signo);
}
int main()
{
	signal(2, handler);
	while (1){
		sleep(1);
		raise(2);
	}
	return 0;
}

~~~

运行结果就是该进程每隔一秒收到一个2号信号。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114597442282.png)

###### abort函数

**abort函数可以给当前进程发送SIGABRT信号，使得当前进程异常终止**，abort函数的函数原型如下：

```cpp
void abort(void);
```

abort函数是一个无参数无返回值的函数。

例如，下列代码当中每隔一秒向当前进程发送一个SIGABRT信号。

~~~C++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
	printf("get a signal:%d\n", signo);
}
int main()
{
	signal(6, handler);
	while (1){
		sleep(1);
		abort();
	}
	return 0;
}

~~~

与之前不同的是，**虽然我们对SIGABRT信号进行了捕捉，并且在收到SIGABRT信号后执行了我们给出的自定义方法，但是当前进程依然是异常终止了。**

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114672018285.png)

**说明一下：** **abort函数的作用是异常终止进程，exit函数的作用是正常终止进程**，而abort本质是通过向当前进程发送SIGABRT信号而终止进程的，因此使**用exit函数终止进程可能会失败，但使用abort函数终止进程总是成功的**。

#### 由软件条件产生信号

###### SIGPIPE信号

SIGPIPE信号实际上就是一种由软件条件产生的信号，当进程在使用管道进行通信时，读端进程将读端关闭，而写端进程还在一直向管道写入数据，那么此时写端进程就会收到SIGPIPE信号进而被操作系统终止。

例如，下面代码当中，创建匿名管道进行父子进程之间的通信，其中父进程是读端进程，子进程是写端进程，但是一开始通信父进程就将读端关闭了，那么此时子进程在向管道写入数据时就会收到SIGPIPE信号，进而被终止。

~~~C++
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	int fd[2] = { 0 };
	if (pipe(fd) < 0){ //使用pipe创建匿名管道
		perror("pipe");
		return 1;
	}
	pid_t id = fork(); //使用fork创建子进程
	if (id == 0){
		//child
		close(fd[0]); //子进程关闭读端
		//子进程向管道写入数据
		const char* msg = "hello father, I am child...";
		int count = 10;
		while (count--){
			write(fd[1], msg, strlen(msg));
			sleep(1);
		}
		close(fd[1]); //子进程写入完毕，关闭文件
		exit(0);
	}
	//father
	close(fd[1]); //父进程关闭写端
	close(fd[0]); //父进程直接关闭读端（导致子进程被操作系统杀掉）
	int status = 0;
	waitpid(id, &status, 0);
	printf("child get signal:%d\n", status & 0x7F); //打印子进程收到的信号
	return 0;
}

~~~

运行代码后，即可发现子进程在退出时收到的是13号信号，即SIGPIPE信号。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114808679288.png)

###### SIGALRM信号

**调用alarm函数可以设定一个闹钟，也就是告诉操作系统在若干时间后发送SIGALRM信号给当前进程**，alarm函数的函数原型如下：

~~~C++
unsigned int alarm(unsigned int seconds);
~~~

alarm函数的作用就是，让**操作系统在seconds秒之后给当前进程发送SIGALRM信号**，SIGALRM信号的默认处理动作是终止进程。

alarm函数的返回值：

- 若调用alarm函数前，进程已经设置了闹钟，则返回上一个闹钟时间的剩余时间，并且本次闹钟的设置会覆盖上一次闹钟的设置。
- 如果调用alarm函数前，进程没有设置闹钟，则返回值为0。

例如，我们可以用下面的代码，测试自己的云服务器一秒时间内可以将一个变量累加到多大。

~~~C++
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
	int count = 0;
	alarm(1);
	while (1){
		count++;
		printf("count: %d\n", count);
	}
	return 0;
}

~~~

运行代码后，可以发现我当前的云服务器在一秒内可以将一个变量累加到两万左右。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114885277291.png)

但实际上我当前的云服务器在一秒内可以执行的累加次数远大于两万，那为什么上述代码运行结果比实际结果要小呢？

主要原因有两个，首先，由于我们每进行一次累加就进行了一次打印操作，而与外设之间的IO操作所需的时间要比累加操作的时间更长，其次，由于我当前使用的是云服务器，因此在累加操作后还需要将累加结果通过网络传输将服务器上的数据发送过来，因此最终显示的结果要比实际一秒内可累加的次数小得多。

为了尽可能避免上述问题，我们可以先让count变量一直执行累加操作，直到一秒后进程收到SIGALRM信号后再打印累加后的数据。

~~~C++
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count = 0;
void handler(int signo)
{
	printf("get a signal: %d\n", signo);
	printf("count: %d\n", count);
	exit(1);
}
int main()
{
	signal(SIGALRM, handler);
	alarm(1);
	while (1){
		count++;
	}
	return 0;
}

~~~

此时可以看到，count变量在一秒内被累加的次数变成了五亿多，由此也证明了，与计算机单纯的计算相比较，计算机与外设进行IO时的速度是非常慢的。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114918295294.png)

#### 由硬件异常产生信号

###### 为什么C/C++程序会崩溃？

当我们程序当中出现类似于除0、野指针、越界之类的错误时，为什么程序会崩溃？**本质上是因为**进程在运行过程中收到了操作系统发来的信号进而被终止，那操作系统是如何识别到一个进程触发了某种问题的呢？

我们知道，CPU当中有一堆的寄存器，当我们需要对两个数进行算术运算时，我们是先将这两个操作数分别放到两个寄存器当中，然后进行算术运算，并把结果写回寄存器当中。此外，CPU当中还有一组寄存器叫做状态寄存器，它可以用来标记当前指令执行结果的各种状态信息，如有无进位、有无溢出等等。而操作系统是软硬件资源的管理者，在程序运行过程中，若操作系统发现CPU内的某个状态标志位被置位，而这次置位就是因为出现了某种除0错误而导致的，那么此时操作系统就会马上识别到当前是哪个进程导致的该错误，并将所识别到的硬件错误包装成信号发送给目标进程，本质就是操作系统去直接找到这个进程的task_struct，并向该进程的位图中写入8信号，写入8号信号后这个进程就会在合适的时候被终止。

那对于下面的野指针问题，或者越界访问的问题时，操作系统又是如何识别到的呢？
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114946882297.png)

运行结果：
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114953751300.png)

首先我们必须知道的是，当我们要访问一个变量时，一定要先经过页表的映射，将虚拟地址转换成物理地址，然后才能进行相应的访问操作。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681114965439303.png)



其中**页表属于一种软件映射关系**，而**实际上在从虚拟地址到物理地址映射的时候还有一个硬件叫做MMU**，它**是一种负责处理CPU的内存访问请求的计算机硬件**，因此**映射工作不是由CPU做的，而是由MMU做的，但现在MMU已经集成到CPU当中了**。

当需要进行虚拟地址到物理地址的映射时，我们先将页表的左侧的虚拟地址导给MMU，然后MMU会计算出对应的物理地址，我们再通过这个物理地址进行相应的访问。

而MMU既然是硬件单元，那么它当然也有相应的状态信息，当我们要访问不属于我们的虚拟地址时，MMU在进行虚拟地址到物理地址的转换时就会出现错误，然后将对应的错误写入到自己的状态信息当中，这时硬件上面的信息也会立马被操作系统识别到，进而将对应进程发送SIGSEGV信号。

总结一下：

- **C/C++程序会崩溃，是因为程序当中出现的各种错误最终一定会在硬件层面上有所表现，进而会被操作系统识别到，然后操作系统就会发送相应的信号将当前的进程终止。**

### 阻塞信号

#### 信号其他相关常见概念

- **实际执行信号的处理动作，称为信号递达**（Delivery）。
- **信号从产生到递达之间的状态，称为信号未决**（pending）。
- 进程**可以选择阻塞（Block）某个信号**。
- 被**阻塞的信号产生时将保持在未决状态**，直到进程解除对此信号的阻塞，才执行递达的动作。
- 需要注意的是，**阻塞和忽略是不同的**，只要信号被阻塞就不会递达，而忽略是在递达之后的一种处理动作。

#### 在内核中的表示

信号在内核中的表示示意图如下：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681115896676306.png)

- 每个信号都有两个标志位分别表示**阻塞（block）和未决（pending）**，还有一个函数指针表示处理动作。信号产生时，内核在进程控制块中设置该信号的未决标志，直到信号递达才清除该标志。在上图中，**SIGHUP信号未阻塞也未产生过，当它递达时执行默认处理动作**。
- **SIGINT信号产生过，但正在被阻塞，所以暂时不能递达**。虽然它的处理动作是忽略，但在没有解除阻塞之前不能忽略这个信号，因为进程仍有机会在改变处理动作之后再接触阻塞。
- **SIGQUIT信号未产生过，但一旦产生SIGQUIT信号，该信号将被阻塞**，它的处理动作是用户自定义函数sighandler。如果在进程解除对某信号的阻塞之前，这种信号产生过多次，**POSIX.1允许系统递达该信号一次或多次**。Linux是这样实现的：**普通信号在递达之前产生多次只计一次，而实时信号在递达之前产生多次可以依次放在一个队列里，这里只讨论普通信号**。

总结一下：

- **在block位图中**，比特位的位置代表某一个信号，比特位的内容**代表该信号是否被阻塞。**
- **在pending位图中**，比特位的位置代表某一个信号，比特位的内容**代表是否收到该信号**。
- **handler表本质上是一个函数指针数组**，数组的下标代表某一个信号，数组的内容代表该信号递达时的处理动作，处理动作包括默认、忽略以及自定义。
- block、pending和handler这三张表的每一个位置是一一对应的。

#### sigset_t

根据信号在内核中的表示方法，每个信号的未决标志只有一个比特位，非0即1，如果不记录该信号产生了多少次，那么阻塞标志也只有一个比特位。

因此，未决和阻塞标志可以用相同的数据类型sigset_t来存储。在我当前的云服务中，sigset_t类型的定义如下：（不同操作系统实现sigset_t的方案可能不同）

~~~C++
#define _SIGSET_NWORDS (1024 / (8 * sizeof (unsigned long int)))
typedef struct
{
	unsigned long int __val[_SIGSET_NWORDS];
} __sigset_t;

typedef __sigset_t sigset_t;

~~~

**sigset_t称为信号集，这个类型可以表示每个信号的“有效”或“无效”状态。**

- **在阻塞信号集中“有效”和“无效”的含义是该信号是否被阻塞。**
- **在未决信号集中“有效”和“无效”的含义是该信号是否处于未决状态。**

**阻塞信号集也叫做当前进程的信号屏蔽字（Signal Mask）**，这里的“屏蔽”应该理解为阻塞而不是忽略。

#### 信号集操作函数

sigset_t类型对于每种信号用一个bit表示“有效”或“无效”，至于这个类型内部如何存储这些bit则依赖于系统的实现，从使用者的角度是不必关心的，使用者只能调用以下函数来操作sigset_t变量，而不应该对它的内部数据做任何解释，比如用printf直接打印sigset_t变量是没有意义的。

~~~C++
#include <signal.h>

int sigemptyset(sigset_t *set);

int sigfillset(sigset_t *set);

int sigaddset(sigset_t *set, int signum);

int sigdelset(sigset_t *set, int signum);

int sigismember(const sigset_t *set, int signum);  

~~~

函数解释：

- **sigemptyset函数：初始化set所指向的信号集，使其中所有信号的对应bit清零，表示该信号集不包含任何有效信号。**
- **sigfillset函数：初始化set所指向的信号集，使其中所有信号的对应bit置位，表示该信号集的有效信号包括系统支持的所有信号。**
- **sigaddset函数：在set所指向的信号集中添加某种有效信号。**
- **sigdelset函数：在set所指向的信号集中删除某种有效信号。**
- **sigemptyset、sigfillset、sigaddset和sigdelset函数都是成功返回0，出错返回-1。**
- **sigismember函数：判断在set所指向的信号集中是否包含某种信号，若包含则返回1，不包含则返回0，调用失败返回-1。**

**注意：** 在使用sigset_t类型的变量之前，一定要调用sigemptyset或sigfillset做初始化，使信号处于确定的状态。

例如，我们可以按照如下方式使用这些函数。

~~~C++
#include <stdio.h>
#include <signal.h>

int main()
{
	sigset_t s; //用户空间定义的变量

	sigemptyset(&s);

	sigfillset(&s);

	sigaddset(&s, SIGINT);

	sigdelset(&s, SIGINT);

	sigismember(&s, SIGINT);
	return 0;
}

~~~

**注意：** 代码中定义的sigset_t类型的变量s，与我们平常定义的变量一样都是在用户空间定义的变量，所以后面我们用信号集操作函数对变量s的操作实际上只是对用户空间的变量s做了修改，并不会影响进程的任何行为。因此，我**们还需要通过系统调用，才能将变量s的数据设置进操作系统。**

#### sigprocmask

sigprocmask函数可以用于读取或更改进程的信号屏蔽字（阻塞信号集），该函数的函数原型如下：

```cpp
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
```

**参数说明：**

- 如果oldset是非空指针，则读取进程当前的信号屏蔽字通过oldset参数传出。
- 如果set是非空指针，则更改进程的信号屏蔽字，参数how指示如何更改。
- 如果oldset和set都是非空指针，则先将原来的信号屏蔽字备份到oldset里，然后根据set和how参数更改信号屏蔽字。

假设当前的信号屏蔽字为mask，下表说明了**how参数的可选值及其含义**：

![image-20230410164252481](%E5%9B%BE%E7%89%87/Linux/image-20230410164252481.png)

**返回值说明：**

- sigprocmask函数调用成功返回0，出错返回-1。

**注意：** **如果调用sigprocmask解除了对当前若干个未决信号的阻塞，则在sigprocmask函数返回前，至少将其中一个信号递达**。

#### sigpending

sigpending函数可以用于读取进程的未决信号集，该函数的函数原型如下：

~~~C++
int sigpending(sigset_t *set);
~~~

sigpending函数读取当前进程的未决信号集，并通过set参数传出。该函数调用成功返回0，出错返回-1。

**下面我们来做一个简单的实验**

> 实验步骤如下：
>
> 1. 先用上述的函数将2号信号进行屏蔽（阻塞）。
> 2. 使用kill命令或组合按键向进程发送2号信号。
> 3. 此时2号信号会一直被阻塞，并一直处于pending（未决）状态。
> 4. 使用sigpending函数获取当前进程的pending信号集进行验证。
>
> 代码如下：
>
> ~~~C++
> #include<cstdio>
> #include<unistd.h>
> #include<signal.h>
> 
> void printPending(sigset_t *pending)
> {
>     int i = 1;
>     for(int i = 1; i <= 31; ++ i)
>     {
>         if(sigismember(pending, i))
>             printf("1 ");
>         else
>             printf("0 ");
>     }
> 
>     printf("\n");
> }
> 
> int main()
> {
>     sigset_t set, oldset;//输入型，输出型
>     sigemptyset(&set);//清空
>     sigemptyset(&oldset);
> 
>     sigaddset(&set, 2);//添加一个阻塞位
>     sigprocmask(SIG_SETMASK, &set, &oldset);//通过OS改变当前进程的信号屏蔽字
> 
>     sigset_t pending;//未决集
>     sigemptyset(&pending);//置空
> 
>     while(true)
>     {
>         sigpending(&pending);//输出型
>         printPending(&pending);//打印
>         sleep(1);
>     }
> 
> 
>     return 0;
> }
> 
> ~~~
>
> 可以看到，程序刚刚运行时，因为没有收到任何信号，所以此时该进程的pending表一直是全0，而当我们使用kill命令向该进程发送2号信号后，由于2号信号是阻塞的，因此2号信号一直处于未决状态，所以我们看到pending表中的第二个数字一直是1。
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681116255452309.png)
>
> 为了看到2号信号递达后pending表的变化，我们可以设置一段时间后，自动解除2号信号的阻塞状态，解除2号信号的阻塞状态后2号信号就会立即被递达。因为2号信号的默认处理动作是终止进程，所以为了看到2号信号递达后的pending表，我们可以将2号信号进行捕捉，让2号信号递达时执行我们所给的自定义动作。
>
> ~~~c++
> #include<cstdio>
> #include<unistd.h>
> #include<signal.h>
> 
> void printPending(sigset_t *pending)
> {
>     int i = 1;
>     for(int i = 1; i <= 31; ++ i)
>     {
>         if(sigismember(pending, i))
>             printf("1 ");
>         else
>             printf("0 ");
>     }
> 
>     printf("\n");
> }
> void handler(int sig)
> {
>     printf("handler signal : %d\n", sig);
> }
> int main()
> {
>     sigset_t set, oldset;//输入型，输出型
>     sigemptyset(&set);//清空
>     sigemptyset(&oldset);
> 
>     sigaddset(&set, 2);//添加一个阻塞位
>     sigprocmask(SIG_SETMASK, &set, &oldset);//通过OS改变当前进程的信号屏蔽字
> 
>     sigset_t pending;//未决集
>     sigemptyset(&pending);//置空
> 
>     signal(2, handler);//自定义2号信号处理函数
> 
>     int cnt = 0;
>     while(true)
>     {
>         sigpending(&pending);//输出型
>         printPending(&pending);//打印
>         sleep(1);
>         ++ cnt;
> 
>         if(20 == cnt)
>         {
>             sigprocmask(SIG_SETMASK, &oldset, NULL);
>             printf("恢复信号屏蔽字为原状态\n");
>         }
> 
>     }
> 
> 
>     return 0;
> }
> 
> ~~~
>
> 此时就可以看到，进程收到2号信号后，该信号在一段时间内处于未决状态，当解除2号信号的屏蔽后，2号信号就会立即递达，执行我们所给的自定义动作，而此时的pending表也变回了全0。
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681116288573312.png)
>
> **细节：** 在解除2号信号后，2号信号的自定义动作是在打印“恢复信号屏蔽字”之前执行的**。**
>
> **因为如果调用sigprocmask解除对当前若干个未决信号的阻塞，则在sigprocmask函数返回前，至少要将其中一个信号递达。**

### 捕捉信号

#### 内核空间与用户空间

每一个进程都有自己的进程地址空间，该进程地址空间**由内核空间和用户空间组成**：

- **用户所写的代码和数据位于用户空间**，通过用户级页表与物理内存之间建立映射关系。
- **内核空间存储的实际上是操作系统代码和数据**，通过内核级页表与物理内存之间建立映射关系。

内核级页表是一个全局的页表，它用来维护操作系统的代码与进程之间的关系。因此，**在每个进程的进程地址空间中，用户空间是属于当前进程的，每个进程看到的代码和数据是完全不同的，但内核空间所存放的都是操作系统的代码和数据，所有进程看到的都是一样的内容**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681117635769315.png)

需要注意的是，**虽然每个进程都能够看到操作系统，但并不意味着每个进程都能够随时对其进行访问**。

**如何理解进程切换？**

> 1. 在当前进程的进程地址空间中的内核空间，找到操作系统的代码和数据。
> 2. 执行操作系统的代码，将当前进程的代码和数据剥离下来，并换上另一个进程的代码和数据。
> 3.  用户态 -> 内核态 -> 用户态

**注意：** 当你**访问用户空间时你必须处于用户态**，当你**访问内核空间时你必须处于内核态**。

#### 内核态与用户态

内核态与用户态：

- 内核态通常用来执行操作系统的代码，是一种权限非常高的状态。
- 用户态是一种用来执行普通用户代码的状态，是一种受监管的普通状态。

**进程收到信号之后，并不是立即处理信号，而是在合适的时候，这里所说的合适的时候实际上就是指，从内核态切换回用户态的时候**。

> **从用户态切换为内核态**通常有如下几种情况：
>
> 1. 需要进行系统调用时。
> 2. 当前进程的时间片到了，导致进程切换。
> 3. 产生异常、中断、陷阱等。
>
> 与之相对应，从**内核态切换为用户态**有如下几种情况：
>
> 1. 系统调用返回时。
> 2. 进程切换完毕。
> 3. 异常、中断、陷阱等处理完毕。
>
> 其中，**由用户态切换为内核态我们称之为陷入内核**。每当我们需要陷入内核的时，本质上是因为我们需要执行操作系统的代码，比如系统调用函数是由操作系统实现的，我们要进行系统调用就必须先由用户态切换为内核态。

#### 内核如何实现信号的捕捉

当我们在执行主控制流程的时候，可能因为某些情况而陷入内核，当**内核处理完毕准备返回用户态时，就需要进行信号pending的检查**。（此时仍处于内核态，有权力查看当前进程的pending位图）

在查看pending位图时，**如果**发现有未决信号，**并且该信号没有被阻塞**，**那么此时就需要该信号进行处理**。

**如果待处理信号的处理动作是默认或者忽略**，则执行该信号的处理动作后清除对应的pending标志位，如果没有新的信号要递达，就直接返回用户态，从主控制流程中上次被中断的地方继续向下执行即可。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681117817851318.png)

**但如果待处理信号是自定义捕捉的**，即该信号的处理动作是由用户提供的，那么处理该信号时就需要先返回用户态执行对应的自定义处理动作，执行完后再通过特殊的系统调用sigreturn再次陷入内核并清除对应的pending标志位，如果没有新的信号要递达，就直接返回用户态，继续执行主控制流程的代码。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681117829938321.png)

**注意：** **sighandler和main函数使用不同的堆栈空间，它们之间不存在调用和被调用的关系，是两个独立的控制流程**。**但sighandler是对main执行流进行处理的执行流。**

**巧计**

> 当待处理信号是自定义捕捉时的情况比较复杂，可以借助下图进行记忆：
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681117890171324.png)
>
> 其中，该图形与直线有几个交点就代表在这期间有几次状态切换，而箭头的方向就代表着此次状态切换的方向，图形中间的圆点就代表着检查pending表。

**当识别到信号的处理动作是自定义时，能直接在内核态执行用户空间的代码吗？**

理论上来说是可以的，因为内核态是一种权限非常高的状态，但是绝**对不能这样设计**。

如果允许在内核态直接执行用户空间的代码，那么用户就可以在代码中设计一些非法操作，比如清空数据库等，虽然在用户态时没有足够的权限做到清空数据库，但是如果是在内核态时执行了这种非法代码，那么数据库就真的被清空了，因为内核态是有足够权限清空数据库的。

也就是说，不能让操作系统直接去执行用户的代码，因为操作系统无法保证用户的代码是合法代码，即**操作系统不信任任何用户**。

#### sigaction

捕捉信号除了用前面用过的signal函数之外，我们还可以使用sigaction函数对信号进行捕捉，sigaction函数的函数原型如下：

~~~C++
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
~~~

sigaction函数可以**读取和修改与指定信号相关联的处理动作**，该函数调用成功返回0，出错返回-1。

**参数说明：**

- signum代表指定信号的编号。
- 若act指针非空，则根据act修改该信号的处理动作。
- 若oldact指针非空，则通过oldact传出该信号原来的处理动作。

其中，参数act和oldact都是结构体指针变量，该结构体的定义如下：

~~~c++
struct sigaction {
	void(*sa_handler)(int);
	void(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void(*sa_restorer)(void);
};

~~~

**结构体的第一个成员sa_handler：**

> - 将sa_handler赋值为常数SIG_IGN传给sigaction函数，表示忽略信号。
> - 将sa_handler赋值为常数SIG_DFL传给sigaction函数，表示执行系统默认动作。
> - 将sa_handler赋值为一个函数指针，表示用自定义函数捕捉信号，或者说向内核注册了一个信号处理函数。
>
> **注意：** 所注册的信号处理函数的返回值为void，参数为int，通过参数可以得知当前信号的编号，这样就可以用同一个函数处理多种信号。显然这是一个回调函数，但不是被main函数调用，而是被系统所调用。

**结构体的第二个成员sa_sigaction**

> - sa_sigaction是实时信号的处理函数。

**结构体的第三个成员sa_mask：**

> 首先需要说明的是，**当某个信号的处理函数被调用，内核自动将当前信号加入进程的信号屏蔽字，当信号处理函数返回时自动恢复原来的信号屏蔽字**，这样就保证了在处理某个信号时，如果这种信号再次产生，那么它会被阻塞到当前处理结束为止。
>
> 如果在调用信号处理函数时，除了当前信号被自动屏蔽之外，还希望自动屏蔽另外一些信号，则**用sa_mask字段说明这些需要额外屏蔽的信号，当信号处理函数返回时，自动恢复原来的信号屏蔽字**。

**结构体的第四个成员sa_flags**

> sa_flags字段包含一些选项，这里直接将sa_flags设置为0即可。

**结构体的第五个成员sa_restorer：**

> 该参数没有使用。

例如，下面我们用sigaction函数对2号信号进行了捕捉，将2号信号的处理动作改为了自定义的打印动作，并在执行一次自定义动作后将2号信号的处理动作恢复为原来默认的处理动作。

> ~~~c++
>#include <stdio.h>
> #include <string.h>
>#include <unistd.h>
> #include <signal.h>
> 
> struct sigaction act, oact;
> void handler(int signo)
> {
> 	printf("get a signal:%d\n", signo);
> 	sigaction(2, &oact, NULL);
> }
> int main()
> {
> 	memset(&act, 0, sizeof(act));
> 	memset(&oact, 0, sizeof(oact));
> 
> 	act.sa_handler = handler;
> 	act.sa_flags = 0;
> 	sigemptyset(&act.sa_mask);
> 
> 	sigaction(2, &act, &oact);
> 	while (1){
> 		printf("I am a process...\n");
> 		sleep(1);
> 	}
> 	return 0;
> }
> 
> ~~~
> 
> 运行代码后，第一次向进程发送2号信号，执行我们自定义的打印动作，当我们再次向进程发送2号信号，就执行该信号的默认处理动作了，即终止进程。
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118155635327.png)



### 可重入函数

下面主函数中调用insert函数向链表中插入结点node1，某信号处理函数中也调用了insert函数向链表中插入结点node2，乍眼一看好像没什么问题。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118234488330.png)
下面我们来分析一下，对于下面这个链表。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/ccaeaefcf4d741aaab2bc0746409e8da.png)

1、首先，main函数中调用了insert函数，想将结点node1插入链表，但插入操作分为两步，刚做完第一步的时候，因为硬件中断使进程切换到内核，再次回到用户态之前检查到有信号待处理，于是切换到sighandler函数。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/159a5ef2f1024024afd1279010e08b2b.png)

2、而sighandler函数中也调用了insert函数，将结点node2插入到了链表中，插入操作完成第一步后的情况如下：
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118257856337.png)

3、当结点node2插入的两步操作都做完之后从sighandler返回内核态，此时链表的布局如下：
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118264012340.png)

4、再次回到用户态就从main函数调用的insert函数中继续往下执行，即继续进行结点node1的插入操作。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118270973343.png)



最终结果是，main函数和sighandler函数先后向链表中插入了两个结点，但最后只有node1结点真正插入到了链表中，而node2结点就再也找不到了，造成了内存泄漏。

上述例子中，各函数执行的先后顺序如下：

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681118283969346.png)

像上例这样，insert函数被不同的控制流调用（main函数和sighandler函数使用不同的堆栈空间，它们之间不存在调用与被调用的关系，是两个独立的控制流程），有可能在第一次调用还没返回时就再次进入该函数，我们将这种现象**称之为重入**。

而insert函数访问一个全局链表，有可能因为重入而造成错乱，像这样的函数我们称之为不可重入函数，反之，如果一个函数只访问自己的局部变量或参数，则称之为可重入（Reentrant）函数。

**如果一个函数符合以下条件之一则是不可重入的：**

1. 调用了malloc或free，因为malloc也是用全局链表来管理堆的。
2. 调用了标志I/O库函数，因为标准I/O库的很多实现都以不可重入的方式使用全局数据结构。

### volatile

> volatile是C语言的一个关键字，该关键字的作用是**保持内存的可见性**。

在下面的代码中，我们对2号信号进行了捕捉，当该进程收到2号信号时会将全局变量flag由0置1。也就是说，在进程收到2号信号之前，该进程会一直处于死循环状态，直到收到2号信号时将flag置1才能够正常退出。

~~~C++
#include <stdio.h>
#include <signal.h>

int flag = 0;

void handler(int signo)
{
	printf("get a signal:%d\n", signo);
	flag = 1;
}
int main()
{
	signal(2, handler);
	while (!flag);
	printf("Proc Normal Quit!\n");
	return 0;
}

~~~

运行结果如下：
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16.png)

该程序的运行过程好像都在我们的意料之中，但实际并非如此。代码中的**main函数和handler函数是两个独立的执行流**（**信号是异步的**），而while循环是在main函数当中的，在编译器编译时只能检测到在main函数中对flag变量的使用。

此时编译器检测到在main函数中并没有对flag变量做修改操作，**在编译器优化级别较高的时候，就有可能将flag设置进寄存器里面**。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816963688093.png)

此时**main函数在检测flag时只检测寄存器里面的值，而handler执行流只是将内存中flag的值置为1**了，那么此时就算进程收到2号信号也不会跳出死循环。

在**编译代码时携带`-O3`选项使得编译器的优化级别最高**，此时再运行该代码，就算向进程发生2号信号，该进程也不会终止。![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816963760616.png)

面对这种情况，我们就可以使用volatile关键字对flag变量进行修饰，告知编译器，对**flag变量的任何操作都必须真实的在内存中进行，即保持了内存的可见性**。

~~~C++
#include <stdio.h>
#include <signal.h>

volatile int flag = 0;

void handler(int signo)
{
	printf("get a signal:%d\n", signo);
	flag = 1;
}
int main()
{
	signal(2, handler);
	while (!flag);
	printf("Proc Normal Quit!\n");
	return 0;
}


~~~

此时就算我们编译代码时携带`-O3`选项，当进程收到2号信号将内存中的flag变量置1时，main函数执行流也能够检测到内存中flag变量的变化，进而跳出死循环正常退出。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816963941429.png)

### SIGCHLD信号

为了避免出现僵尸进程，父进程需要使用wait或waitpid函数等待子进程结束，父进程可以阻塞等待子进程结束，也可以非阻塞地查询的是否有子进程结束等待清理，即轮询的方式。

- 采用第一种方式，父进程阻塞就不能处理自己的工作了；
- 采用第二种方式，父进程在处理自己的工作的同时还要记得时不时地轮询一下，程序实现复杂。

其实，**子进程在终止时会给父进程发生SIGCHLD信号**，该信号的默认处理动作是忽略，父进程可以自定义SIGCHLD信号的处理动作，这样父进程就只需专心处理自己的工作，不必关心子进程了，子进程终止时会通知父进程，父进程在信号处理函数中调用wait或waitpid函数清理子进程即可。

例如，下面代码中对SIGCHLD信号进行了捕捉，并将在该信号的处理函数中调用了waitpid函数对子进程进行了清理。

~~~C++
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

void handler(int signo)
{
    printf("get a signal: %d\n", signo);
    int ret = 0;
    while ((ret = waitpid(-1, NULL, WNOHANG)) > 0) // 一次未决到递达期间， 可能多个子进程退出
    {
        printf("wait child %d success\n", ret);
    }
}
int main()
{
    signal(SIGCHLD, handler);
    if (fork() == 0)
    {
        //child
        printf("child is running, begin dead: %d\n", getpid());
        sleep(3);
        exit(1);
    }
    //father
    while (1)
        ;
    return 0;
}

~~~

注意：

- SIGCHLD属于普通信号，记录该信号的pending位只有一个，如果在同一时刻有多个子进程同时退出，那么在handler函数当中实际上只清理了一个子进程，因此在使用waitpid函数清理子进程时**需要使用while不断进行清理**。
- 使用waitpid函数时，需要设置WNOHANG选项，即非阻塞式等待，否则当所有子进程都已经清理完毕时，由于while循环，会再次调用waitpid函数，此时就会在这里阻塞住。

此时父进程就只需专心处理自己的工作，不必关心子进程了，子进程终止时父进程收到SIGCHLD信号，会自动进行该信号的自定义处理动作，进而对子进程进行清理。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169645184712.png)

事实上，**由于UNIX的历史原因，要想不产生僵尸进程还有另外一种办法**：父进程调用signal或sigaction函数**将SIGCHLD信号的处理动作设置为SIG_IGN**，这样fork出来的子进程在终止时会自动清理掉，不会产生僵尸进程，也不会通知父进程。**系统默认的忽略动作和用户用signal或sigaction函数自定义的忽略通常是没有区别的，但这是一个特列**。

**此方法对于Linux可用，但不保证在其他UNIX系统上都可用。**

例如，下面代码中调用signal函数将SIGCHLD信号的处理动作自定义为忽略。

~~~c++
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	signal(SIGCHLD, SIG_IGN);
	if (fork() == 0){
		//child
		printf("child is running, child dead: %d\n", getpid());
		sleep(3);
		exit(1);
	}
	//father
	while (1);
	return 0;
}

~~~

此时子进程在终止时会自动被清理掉，不会产生僵尸进程，也不会通知父进程。
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169648599615.png)

### 全部信号

![image-20230417095619732](%E5%9B%BE%E7%89%87/Linux/image-20230417095619732.png)

![image-20230417095631875](%E5%9B%BE%E7%89%87/Linux/image-20230417095631875.png)

## 任务管理

### 进程组概念

> 每个进程除了有一个进程ID之外，还属于一个进程组，进程组是一个或多个进程的集合。

通常，它们与同一作业相关联，可以接收来自同一终端的各种信号。每个进程组有一个唯一的进程组ID。每个进程组都可以有一个组长进程。组长进程的标识是，其进程组ID等于其进程ID。组长进程可以创建一个进程组，创建该组中的进程，然后终止。

**需要注意的是，只要在某个进程组中有一个进程存在，则该进程组就存在，这与其组长进程是否终止无关。**

### 作业概念

> Shell分前后台来控制的不是进程而是作业（Job）或者进程组（Process Group）。

一个前台作业可以由多个进程组成，一个后台作业也可以由多个进程组成，Shell可以运行一个前台作业和任意多个后台作业，这称为作业控制。

作业与进程组的区别： 

> 如果作业中的某个进程又创建了子进程，则子进程不属于作业。一旦作业运行结束，Shell就把自己提到前台，如果原来的前台进程还存在，也就是这个被创建的子进程还没有终止，那么它将自动变为后台进程组。

### 会话概念

> **会话（Session）是一个或多个进程组的集合**。

一个会话可以有一个控制终端，这通常是登录到其上的终端设备（在终端登录情况下）或伪终端设备（在网络登录情况下）。建立与控制终端连接的会话首进程被称为控制进程。一个会话中的几个进程组可被分为一个前台进程组以及一个或多个后台进程组。所以一个会话中，应该包括**控制进程（会话首进程）**，一**个前台进程组**和**任意多个后台进程组**。

例如，下面我们用同一个死循环代码生成了5个可执行程序。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169758159669.png)

我们将mytest1和mytest2放到后台运行，将mytest3、mytest4和mytest5放到前台运行。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816968412221.png)  

其中mytest1与mytest2属于同一个后台进程组，mytest3、mytest4和mytest5属于同一个前台进程组，而Shell本身属于一个单独的进程组。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169761727372.png) 

这些进程组的控制终端相同，它们同属于一个会话(SID)，当用户在控制终端输入特殊的控制键（如Ctrl+C产生SIGINT，Ctrl+\\产生SIGQUIT，Ctrl+Z产生SIGTSTP），**内核就会发送相应的信号给前台进程组中的所有进程**。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169762987775.png)

### 相关操作

#### 前台进程&后台进程

直接运行某一可执行程序，例如`./可执行程序`，此时默认将程序放到前台运行，**在前台运行的进程的状态后有一个`+`号，例如`R+`**。  ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816968412234.png)  

运行可执行程序时在后面加上&，可以指定将程序放到后台运行，例如`./可执行程序 &`，**在后台运行的进程的状态后没有`+`号**。  ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169765765278.png) 
我们将程序放到后台运行时会发现多了一行提示信息，例如上述的：

```cpp
[1] 16437
```

其中\[1\]是作业的编号，如果同时运行多个作业可以用这个编号进行区分，16437是该作业中某个进程的id（一个作业可以由多个进程组成）。

我们可以用该可执行程序同时创建四个进程放到后台运行：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816968412236.png)  

此时我们就可以将它们分别叫做当前终端下的1号作业、2号作业、3号作业和4号作业。

#### jobs、fg、bg

使用`jobs`命令，可以查看当前会话当中有哪些作业。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816968412237.png)  

**使用`fg`命令（foreground)，可以将某个作业提至前台运行**，如果该作业正在后台运行则直接提至前台运行，如果该作业处于停止状态，则给进程组的每个进程发SIGCONT信号使它继续运行并提至前台。

例如，使用`fg 1`命令将1号作业提到前台运行。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16816968412238.png)  

由于1号作业被提至前台运行，所以其运行状态也由R变成了R+

> **需要注意的是，前台进程只能有一个**，当一个进程变成前台进程后，bash会自动变为后台进程，此时bash就无法进行命令行解释了。

例如，我们将1号作业提至前台运行后，bash进程的状态后面的`+`号就没有了，也就意味着bash自动由前台进程变为了后台进程。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169769319681.png)

将一个前台进程放到后台运行可以使用Ctrl+Z，但使用Ctrl+Z后该进程就会处于停止状态（Stopped）。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122410.png)  

**使用`bg`命令，可以让某个停止的作业在后台继续运行（Running)**，本质就是给该作业的进程组的每个进程发SIGCONT信号。

例如，使用`bg 1`命令让1号作业在后台继续运行。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122411.png)

#### ps命令查看指定的选项

使用`ps`命令时携带-o选项，可以查看指定的信息。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122412.png)  

当我们用Xshell或是终端登录时，本质都是先创建一个bash进程，整体称之为一个会话（所有的命令行的进程都是bash的子进程)，所有的命令行启动的任务都是在对应的会话内运行的。

实际我们每一次登录的过程都是新建会话的过程，**同一个会话中的所有进程的SESS是相同的**。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122413.png)  

**说明一下：** ps命令是一个系统级的命令，该命令能查看所有进程的信息，例如ps axj，只不过-o选项只查看当前会话的进程信息。

## 守护进程

### 守护进程的概念

> **守护进程也称精灵进程（Daemon），是运行在后台的一种特殊进程，它独立于控制终端并且周期性地执行某种任务或等待处理某些发生的事件。**

守护进程是一种很有用的进程，Linux的大多数服务器就是用守护进程实现的，比如Internet服务器inetd，Web服务器httpd等。同时守护进程完成许多系统任务，比如作业规划进程crond等。

Linux系统启动时会启动很多系统服务进程，这些系统服务进程没有控制终端，不能直接和用户交互。**其他进程都是在用户登录或运行程序时创建，在运行结束或用户注销时终止，但系统服务进程不受用户登录注销的影响，它们一直在运行着，这种进程有一个名称叫守护进程（Daemon）。**

### 守护进程的查看

我们可以用`ps axj`命令查看系统中的进程：

+   参数a表示不仅列出当前用户的进程，也列出所有其他用户的进程。
+   参数x表示不仅列出有控制终端的进程，也列出所有无控制终端的进程。
+   参数j表示列出与作业控制相关的信息。

**凡是TPGID一栏写着-1的都是没有控制终端的进程，也就是守护进程。**  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122414.png)  

除此之外，在COMMAND一列**用\[ \]括起来的名字表示内核线程**，这些线程在内核里创建，没有用户空间代码，因此没有程序文件名和命令行，通常采用以k开头的名字，表示Kernel。

个别说明：

+   udevd负责维护/dev目录下的设备文件。
+   acpid负责电源管理。
+   syslogd负责维护/var/log下的日志文件。

可以看出，守护进程通常采用以d结尾的名字，表示Daemon。

### 守护进程的创建

#### 原生创建守护进程

守护进程的创建步骤如下：

1.  **设置文件掩码为0。**
2.  **fork后终止父进程，子进程创建新会话。**
3.  **忽略SIGCHLD信号。**
4.  **再次fork，终止父进程，保持子进程不是会话首进程，从而保证后续不会再和其他终端相关联。**
5.  **更改工作目录为根目录。**
6.  **将标准输入、标准输出、标准错误重定向到/dev/null。**

**相关说明：**

1.  将文件掩码设置为0，保证后续守护进程创建文件时，创建出来的文件的权限符合我们的预期（**想啥是啥**）。
2.  调用setsid创建新会话，**目的是让当前进程自成会话，与当前bash脱离关系**（**创建守护进程的核心**）。
3.  **调用setsid创建新会话时，要求调用进程不能是进程组组长**，但是当我们在命令行上启动多个进程协同完成某种任务时，其中第一个被创建出来的进程就是组长进程，因此我们需要fork创建子进程，让子进程调用setsid创建新会话并继续执行后续代码，而父进程我们直接让其退出即可。
4.  **守护进程不能直接和用户交互，也就没有必要再打开某个终端了，而打开一个终端需要你是会话首进程**，为了防止守护进程打开终端，我们需要再次fork创建子进程并让子进程继续执行后续代码，由于子进程不是会话首进程，也就没有能力打开其他终端了，而父进程我们直接让其退出即可。（**这是一种防御性编程，该操作不是必须的**）
5.  我们一般会将守护进程的工作目录设置为根目录，**便于让守护进程以绝对路径的形式访问某种资源**。（**该操作不是必须的**）
6.  守护进程不能直接和用户交互，也就是说守护进程已经与终端去关联了，**因此一般我们会将守护进程的标准输入、标准输出以及标准错误都重定向到`/dev/null`**，`/dev/null`是一个字符文件（设备），通常用于屏蔽/丢弃输入输出信息。（**该操作不是必须的**）

代码如下：

```cpp
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	//1、设置文件掩码为0 -- 保证文件权限符合预期
	umask(0);

	//2、fork后终止父进程，子进程创建新会话
    //此时子进程为孤儿进程，init托管
	if (fork() > 0){
		//father
		exit(0);
	}
    //创建新会话
	setsid();
    //此时子进程不是进程组组长进程，但是是会话首进程

	//3、忽略SIGCHLD信号
	signal(SIGCHLD, SIG_IGN);

	//4、再次fork，终止父进程，保持子进程不是会话首进程，从而保证后续不会再和其他终端相关联
	//（不是必须的，防御性编程）
	if (fork() > 0){
	    //father
		exit(0);
	}
    //此时子子进程既不是进程组组长进程，也不是会话首进程

	//5、更改工作目录为根目录（可选的选项）
	chdir("/");

	//6、将标准输入、标准输出、标准错误重定向到/dev/null（可选的选项）
	close(0);
	int fd = open("/dev/null", O_RDWR);
	dup2(fd, 1);
	dup2(fd, 2);
	
	while (1);
	return 0;
}
```

运行代码，用ps命令查看该进程，会发现该进程的TPGID为-1，TTY显示的是`？`，也就意味着该进程已经与终端去关联了。  
其次，我们还可以看到该进程的PID与其PGID和SID是不同的，也就是说该进程既不是组长进程也不是会话首进程。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122415.png)  

此外，我们还可以看到该进程的SID与bash进程的SID是不同的，即它们不属于同一个会话。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169772815684.png)

通过`ls /proc/进程id -al`命令，可以看到该进程的工作目录已经成功改为了根目录。 

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169773574187.png) 



通过`ls /proc/进程id/fd -al`命令，可以看到该进程的标准输入、标准输出以及标准错误也成功重定向到了`/dev/null`。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169775082190.png)

#### 调用daemon函数创建守护进程

实际当我们创建守护进程时可以**直接调用daemon接口进行创建**，daemon函数的函数原型如下：

```cpp
int daemon(int nochdir, int noclose);
```

参数说明：

+   如果参数nochdir为0，则将守护进程的工作目录改为根目录，否则不做处理。
+   如果参数noclose为0，则将守护进程的标准输入、标准输出以及标准错误重定向到`/dev/null`，否则不做处理。

调用示例：

```cpp
#include <unistd.h>

int main()
{
	daemon(0, 0);
	while (1);
	return 0;
}
```

调用daemon函数创建的守护进程与我们原生创建的守护进程差距不大，**唯一区别就是daemon函数创建出来的守护进程，既是组长进程也是会话首进程。**  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169684122519.png)  

也就是说**系统实现的daemon函数没有防止守护进程打开终端**，因此我们实现的反而比系统更加完善。

#### 模拟实现daemon函数

有了上述创建守护进程的代码，要模拟实现daemon函数就很容易了，我们只需要设置两个参数nochdir和noclose，当所给nochdir为0时，我们将守护进程的工作目录该为根目录，当所给noclose为0时，我们则将守护进程的标准输入、标准输出以及标准错误重定向到`/dev/null`即可。

代码如下：

```cpp
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void my_daemon(int nochdir, int noclose)
{
	//1、设置文件掩码为0
	umask(0);

	//2、fork后终止父进程，子进程创建新会话
	if (fork() > 0){
		//father
		exit(0);
	}
	setsid();

	//3、忽略SIGCHLD信号
	signal(SIGCHLD, SIG_IGN);

	//4、再次fork，终止父进程，保持子进程不是会话首进程，从而保证后续不会再和其他终端相关联
	//（不是必须的，防御性编程）
	if (fork() > 0){
		//father
		exit(0);
	}

	//5、更改工作目录为根目录（可选的选项）
	if (nochdir == 0){
		chdir("/");
	}

	//6、将标准输入、标准输出、标准错误重定向到/dev/null（可选的选项）
	if (noclose == 0){
		close(0);
		int fd = open("/dev/null", O_RDWR);
		dup2(fd, 1);
		dup2(fd, 2);
	}
}
int main()
{
	my_daemon(0, 0);
	while (1);
	return 0;
}
```

## 线程概念

### 什么是线程

+   在一个程序里的一个执行流就叫做线程（thread）。更准确的定义是：线程是“一个进程内部的控制序列”。
+   一切进程至少都有一个执行线程。
+   线程在进程内部运行，本质是在进程地址空间内运行。
+   在Linux系统中，在CPU眼中，看到的PCB都要比传统的进程更轻量化。
+   透过进程虚拟地址空间，可以看到进程的大部分资源，将进程资源合理分配给每个执行流，就形成了线程执行流。

需要明确的是，一个进程的创建实际上伴随着其进程控制块（task\_struct）、进程地址空间（mm\_struct）以及页表的创建，虚拟地址和物理地址就是通过页表建立映射的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707560.png)  

**每个进程都有自己独立的进程地址空间和独立的页表，也就意味着所有进程在运行时本身就具有独立性**。

但如果我们在创建“进程”时，只创建task\_struct，并要求创建出来的task\_struct和父task\_struct共享进程地址空间和页表，那么创建的结果就是下面这样的：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707561.png)  
此时我们创建的实际上就是四个线程：

+   其中**每一个线程都是当前进程里面的一个执行流，也就是我们常说的“线程是进程内部的一个执行分支”**。
+   同时我们也可以看出，线程在进程内部运行，本质就是线程在进程地址空间内运行，也就是说曾经这个**进程申请的所有资源，几乎都是被所有线程共享的**。

**注意：** 单纯从技术角度，这个是一定能实现的，因为它比创建一个原始进程所做的工作更轻量化了。

> 该如何重新理解之前的进程？

下面用蓝色方框框起来的内容，我们将这个整体叫做进程。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707562.png)  

因此，**所谓的进程并不是通过task\_struct来衡量的，除了task\_struct之外，一个进程还要有进程地址空间、文件、信号等等，合起来称之为一个进程。**

现在我们应该站在内核角度来理解进程：**承担分配系统资源的基本实体，叫做进程**。

换言之，当我们创建进程时是创建一个task\_struct、创建地址空间、维护页表，然后在物理内存当中开辟空间、构建映射，打开进程默认打开的相关文件、注册信号对应的处理方案等等。

而我们之前接触到的进程都只有一个task\_struct，也就是该进程内部只有一个执行流，即单执行流进程，反之，内部有多个执行流的进程叫做多执行流进程。

> **在Linux中，站在CPU的角度，能否识别当前调度的task\_struct是进程还是线程**？

答案是**不能，也不需要**了，因为CPU只关心一个一个的独立执行流。无论进程内部只有一个执行流还是有多个执行流，CPU都是以task\_struct为单位进行调度的。

单执行流进程被调度：  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169781259393.png)

多执行流进程被调度：  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707564.png)  

因此，CPU看到的虽说还是task\_struct，但已经比传统的进程要更轻量化了。

> **Linux下并不存在真正的多线程！而是用进程模拟的！**

操作系统中存在大量的进程，一个进程内又存在一个或多个线程，因此线程的数量一定比进程的数量多，当线程的数量足够多的时候，很明显线程的执行粒度要比进程更细。

如果一款操作系统要支持真的线程，那么就需要对这些线程进行管理。比如说创建线程、终止线程、调度线程、切换线程、给线程分配资源、释放资源以及回收资源等等，所有的这一套相比较进程都需要另起炉灶，搭建一套与进程平行的线程管理模块。

因此，如果要支持真的线程一定会提高设计操作系统的复杂程度。在Linux看来，描述线程的控制块和描述进程的控制块是类似的，因此Linux并没有重新为线程设计数据结构，而是直接复用了进程控制块，所以我们说**Linux中的所有执行流都叫做轻量级进程**。

但也有支持真的线程的操作系统，比如Windows操作系统，因此Windows操作系统系统的实现逻辑一定比Linux操作系统的实现逻辑要复杂得多。

> **既然在Linux没有真正意义的线程，那么也就绝对没有真正意义上的线程相关的系统调用！**

这很好理解，既然在Linux中都没有真正意义上的线程了，那么自然也没有真正意义上的线程相关的系统调用了。但是Linux可以提供创建轻量级进程的接口，也就是创建进程，共享空间，其中最典型的代表就是**vfork函数**。

vfork函数的功能就是创建子进程，但是父子共享空间，vfork的函数原型如下：

```cpp
pid_t vfork(void);
```

vfork函数的返回值与fork函数的返回值相同：

+   给父进程返回子进程的PID。
+   给子进程返回0。

只不过vfork函数创建出来的子进程与其父进程共享地址空间，例如在下面的代码中，父进程使用vfork函数创建子进程，子进程将全局变量g\_val由100改为了200，父进程休眠3秒后再读取到全局变量g\_val的值。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int g_val = 100;
int main()
{
	pid_t id = vfork();
	if (id == 0){
		//child
		g_val = 200;
		printf("child:PID:%d, PPID:%d, g_val:%d\n", getpid(), getppid(), g_val);
		exit(0);
	}
	//father
	sleep(3);
	printf("father:PID:%d, PPID:%d, g_val:%d\n", getpid(), getppid(), g_val);
	return 0;
}
```

可以看到，父进程读取到g\_val的值是子进程修改后的值，也就证明了vfork创建的子进程与其父进程是共享地址空间的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707565.png)

> **原生线程库pthread**

在Linux中，站在内核角度没有真正意义上线程相关的接口，但是站在用户角度，当用户想创建一个线程时更期望使用thread\_create这样类似的接口，而不是vfork函数，因此**系统为用户层提供了原生线程库pthread**。

原生线程库实际就是对轻量级进程的系统调用进行了封装，在用户层模拟实现了一套线程相关的接口。

因此对于我们来讲，在**Linux下学习线程实际上就是学习在用户层模拟实现的这一套接口，而并非操作系统的接口**。

### 二级页表▲▲

> 以32位平台为例，在32位平台下一共有2^32^个地址，也就意味着有2^32^个地址需要被映射。

如果我们所谓的页表就只是单纯的一张表，那么这张表就需要建立2^32^个虚拟地址和物理地址之间的映射关系，即这张表一共有2^32^个映射表项。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169784126896.png)

每一个表项中除了要有虚拟地址和与其映射的物理地址以外，实际还需要有一些权限相关的信息，比如我们所说的用户级页表和内核级页表，实际就是通过权限进行区分的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707567.png)  

每个应表项中存储一个物理地址和一个虚拟地址就需要8个字节，考虑到还需要包含权限相关的各种信息，这里每一个表项就按10个字节计算。  

这里一共有2^32^个表项，也就意味着存储这张页表我们需要用2^32^ \* 10个字节，也就是40GB。而在32位平台下我们的内存可能一共就只有4GB，也就是说我们根本无法存储这样的一张页表。

> **因此所谓的页表并不是单纯的一张表**。

还是以32位平台为例，其页表的映射过程如下：

1.  选择虚拟地址的前10个比特位在页目录当中进行查找，找到对应的页表。
2.  再选择虚拟地址的10个比特位在对应的页表当中进行查找，找到物理内存中对应页框的起始地址。
3.  最后将虚拟地址中剩下的12个比特位作为偏移量从对应页框的起始地址处向后进行偏移，找到物理内存中某一个对应的字节数据。

相关说明：

1.  **物理内存实际是被划分成一个个4KB大小的页框的**，而磁盘上的程序也是被划分成一个个4KB大小的页帧的，当内存和磁盘进行数据交换时也就是以4KB大小为单位进行加载和保存的。
2.  4KB实际上就是2^12^个字节，也就是说一个页框中有2^12^个字节，而访问内存的基本大小是1字节，因此一个页框中就有2^12^个地址，于是我们就可以将剩下的12个比特位作为偏移量，从页框的起始地址处开始向后进行偏移，从而找到物理内存中某一个对应字节数据。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707668.png)

![image-20230714143243719](%E5%9B%BE%E7%89%87/Linux/image-20230714143243719.png)  

这实际上就是我们所谓的二级页表，其中页目录项是一级页表，页表项是二级页表。

每一个表项还是按10字节计算，页目录和页表的表项都是2^10^个，因此一个表的大小就是2^10^ \* 10个字节，也就是10KB。而页目录有2^10^个表项也就意味着页表有2^10^个，也就是说一级页表有1张，二级页表有2^10^张，总共算下来大概就是10MB，内存消耗并不高，因此Linux中实际就是这样映射的。

上面所说的所有映射过程，都是由**MMU（MemoryManagementUnit）**这个硬件完成的，该硬件是集成在CPU内的。**页表是一种软件映射，MMU是一种硬件映射，所以计算机进行虚拟地址到物理地址的转化采用的是软硬件结合的方式。**

**注意：** **在Linux中，32位平台下用的是二级页表，而64位平台下用的是多级页表**。

> 修改常量字符串为什么会触发段错误？

当我们要修改一个字符串常量时，虚拟地址必须经过页表映射找到对应的物理内存，而在查表过程中发现其权限是只读的，此时你要对其进行修改就会在MMU内部触发硬件错误，操作系统在识别到是哪一个进程导致的之后，就会给该进程发送信号对其进行终止。

### 线程的优点

+   创建一个新线程的**代价**要比创建一个新进程小得多。
+   与进程之间的切换相比，线程之间的切换需要操作系统做的**工作**要少很多。
+   线程占用的**资源**要比进程少很多。
+   能充分利用**多处理器**的可并行数量。
+   在等待慢速IO操作结束的**同时**，程序可执行其他的计算任务。
+   **计算密集型应用**，为了能在多处理器系统上运行，将计算分解到多个线程中实现。
+   **IO密集型应用**，为了提高性能，将IO操作重叠，线程可以同时等待不同的IO操作。

> 概念说明：
>
> +   计算密集型：执行流的大部分任务，主要以计算为主。比如加密解密、大数据查找等。
> +   IO密集型：执行流的大部分任务，主要以IO为主。比如刷磁盘、访问数据库、访问网络等。

### 线程的缺点

+   **性能损失：** 一个很少被外部事件阻塞的计算密集型线程往往无法与其他线程共享同一个处理器。如果计算密集型线程的数量比可用的处理器多，那么可能会有较大的性能损失，这里的性能损失指的是增加了额外的同步和调度开销，而可用的资源不变。
+   **健壮性降低：** 编写多线程需要更全面更深入的考虑，在一个多线程程序里，因时间分配上的细微偏差或者因共享了不该共享的变量而造成不良影响的可能性是很大的，换句话说，线程之间是缺乏保护的。
+   **缺乏访问控制：** 进程是访问控制的基本粒度，在一个线程中调用某些OS函数会对整个进程造成影响。
+   **编程难度提高：** 编写与调试一个多线程程序比单线程程序困难得多。

### 线程异常

+   单个线程如果出现除零、野指针等问题导致线程崩溃，进程也会随着崩溃。
+   线程是进程的执行分支，线程出异常，就类似进程出异常，进而触发信号机制，终止进程，进程终止，该进程内的所有线程也就随即退出。

### 线程用途

+   合理的使用多线程，能提高CPU密集型程序的执行效率。
+   合理的使用多线程，能提高IO密集型程序的用户体验（如生活中我们一边写代码一边下载开发工具，就是多线程运行的一种表现）。

### Linux进程VS线程

#### 进程和线程

> **进程是承担分配系统资源的基本实体，线程是调度的基本单位。**

线程共享进程数据，但也拥有自己的一部分数据：

+   线程ID。
+   **一组寄存器**。（存储每个线程的上下文信息）
+   **栈**。（每个线程都有临时的数据，需要压栈出栈）
+   errno。（C语言提供的全局变量，每个线程都有自己的）
+   信号屏蔽字。
+   调度优先级。

#### 进程的多个线程共享

因为是在同一个地址空间，因此所谓的代码段（Text Segment）、数据段（Data Segment）都是共享的：

+   如果定义一个函数，在各线程中都可以调用。
+   如果定义一个全局变量，在各线程中都可以访问到。

除此之外，各线程还共享以下进程资源和环境：

+   文件描述符表。（进程打开一个文件后，其他线程也能够看到）
+   每种信号的处理方式。（SIG\_IGN、SIG\_DFL或者自定义的信号处理函数）
+   当前工作目录。（cwd）
+   用户ID和组ID。

#### 进程和线程的关系

进程和线程的关系如下图：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707669.png)  

在此之前我们接触到的都是具有一个线程执行流的进程，即单线程进程。

## 线程控制

### POSIX线程库

**pthread线程库是应用层的原生线程库**：

+   应用层指的是这个线程库并不是系统接口直接提供的，而是由**第三方帮我们提供**的。
+   原生指的是**大部分Linux系统都会默认带上该线程库**。
+   与线程有关的函数构成了一个完整的系列，绝大多数函数的名字都是以“pthread\_”打头的。
+   要使用这些函数库，要通过**引入头文件<pthread.h>**。
+   链接这些线程函数库时，要**使用编译器命令的“-lpthread”选项**。

错误检查：

+   传统的一些函数是，成功返回0，失败返回-1，并且对全局变量errno赋值以指示错误。
+   pthreads函数出错时不会设置全局变量errno（而大部分POSIX函数会这样做），而是将错误代码通过返回值返回。
+   pthreads同样也提供了线程内的errno变量，以支持其他使用errno的代码。
+   **对于pthreads函数的错误，建议通过返回值来判定，因为读取返回值要比读取线程内的errno变量的开销更小**。

### 线程创建

#### 创建线程的函数叫做pthread\_create

**pthread\_create函数**的函数原型如下：

```cpp
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
```

参数说明：

+   **thread：获取创建成功的线程ID**，该参数是一个输出型参数。
+   **attr：用于设置创建线程的属性**，传入NULL表示使用默认属性。
+   **start\_routine：该参数是一个函数地址，表示线程例程，即线程启动后要执行的函数**。
+   **arg：传给线程例程的参数**。

返回值说明：

+   线程创建成功返回0，失败返回错误码。

#### 让主线程创建一个新线程

当一个程序启动时，就有一个进程被操作系统创建，与此同时一个线程也立刻运行，这个线程就叫做主线程。

+   主线程是产生其他子线程的线程。
+   通常主线程必须最后完成某些执行操作，比如各种关闭动作。

下面我们让主线程调用pthread\_create函数创建一个新线程，此后新线程就会跑去执行自己的新例程，而主线程则继续执行后续代码。

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	while (1){
		printf("I am %s\n", msg);
		sleep(1);
	}
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, Routine, (void*)"thread 1");
	while (1){
		printf("I am main thread!\n");
		sleep(2);
	}
	return 0;
}
```

运行代码后可以看到，新线程每隔一秒执行一次打印操作，而主线程每隔两秒执行一次打印操作。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169789845199.png)

当我们用`ps axj`命令查看当前进程的信息时，虽然此时该进程中有两个线程，但是我们看到的进程只有一个，因为这两个线程都是属于同一个进程的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707671.png)  

**使用`ps -aL`命令，可以显示当前的轻量级进程。**

+   默认情况下，不带`-L`，看到的就是一个个的进程。
+   带`-L`就可以查看到每个进程内的多个轻量级进程。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707672.png)  

其中，**LWP（Light Weight Process)就是轻量级进程的ID**，可以看到显示的两个轻量级进程的PID是相同的，因为它们属于同一个进程。

**注意：** 在Linux中，**应用层的线程与内核的LWP是一一对应的**，实际上操作系统调度的时候采用的是LWP，而并非PID，只不过我们之前接触到的都是单线程进程，其PID和LWP是相等的，所以对于单线程进程来说，调度时采用PID和LWP是一样的。

为了进一步证明这两个线程是属于同一个进程的，我们可以让主线程和新线程在执行打印操作时，将自己的PID和PPID也进行打印。

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	while (1){
		printf("I am %s...pid: %d, ppid: %d\n", msg, getpid(), getppid());
		sleep(1);
	}
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, Routine, (void*)"thread 1");
	while (1){
		printf("I am main thread...pid: %d, ppid: %d\n", getpid(), getppid());
		sleep(2);
	}
	return 0;
}
```

可以看到主线程和新线程的PID和PPID是一样的，也就是说主线程和新线程虽然是两个执行流，但它们仍然属于同一个进程。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707673.png)

#### 让主线程创建一批新线程

上面是让主线程创建一个新线程，下面我们让主线程一次性创建五个新线程，并让创建的每一个新线程都去执行Routine函数，也就是说Routine函数会被重复进入，即该函数是会被重入的。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	while (1){
		printf("I am %s...pid: %d, ppid: %d\n", msg, getpid(), getppid());
		sleep(1);
	}
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
	}
	while (1){
		printf("I am main thread...pid: %d, ppid: %d\n", getpid(), getppid());
		sleep(2);
	}
	return 0;
}
```

运行代码，可以看到这五个新线程是创建成功的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707674.png)  

因为主线程和五个新线程都属于同一个进程，所以它们的PID和PPID也都是一样的。

此时我们再用`ps -aL`命令查看，就会看到六个轻量级进程。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707675.png)

#### 获取线程ID

常见获取线程ID的方式有两种：

+   **创建线程时通过输出型参数获得。**
+   **通过调用pthread\_self函数获得。**

**pthread\_self函数**的函数原型如下：

```cpp
pthread_t pthread_self(void);
```

调用pthread\_self函数即可获得当前线程的ID，类似于调用getpid函数获取当前进程的ID。

例如，下面代码中在每一个新线程被创建后，主线程都将通过输出型参数获取到的线程ID进行打印，此后主线程和新线程又通过调用pthread\_self函数获取到自身的线程ID进行打印。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	while (1){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
	}
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	while (1){
		 printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
		 sleep(2);
	}
	return 0;
}
```

运行代码，可以看到这两种方式获取到的线程的ID是一样的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707676.png)  

**注意：** **用pthread\_self函数获得的线程ID与内核的LWP的值是不相等的**，

- **pthread\_self函数获得的是用户级原生线程库的线程ID**，
- **LWP是内核的轻量级进程ID，它们之间是一对一的关系。**

### 线程等待

首先需要明确的是，一个线程被创建出来，这个**线程就如同进程一般，也是需要被等待的**。如果主线程不对新线程进行等待，那么这个新线程的资源也是不会被回收的。所以线程需要被等待，如果不等待会产生类似于“僵尸进程”的问题，也就是内存泄漏。

#### 等待线程的函数叫做pthread\_join

**pthread\_join函数**的函数原型如下：

```cpp
int pthread_join(pthread_t thread, void **retval);
```

参数说明：

+   thread：被等待线程的ID(用户级ID)。
+   retval：线程退出时的退出码信息。

返回值说明：

+   线程等待成功返回0，失败返回错误码。

**调用该函数的线程将挂起等待，直到ID为thread的线程终止，thread线程以不同的方法终止，通过pthread\_join得到的终止状态是不同的。**  

**总结如下：**

1.  如果thread线程通过return返回，retval所指向的单元里存放的是thread线程函数的返回值。
2.  如果thread线程被别的线程调用pthread\_cancel异常终止掉，retval所指向的单元里存放的是常数PTHREAD\_CANCELED。
3.  如果thread线程是自己调用pthread\_exit终止的，retval所指向的单元存放的是传给pthread\_exit的参数。
4.  如果对thread线程的终止状态不感兴趣，可以传NULL给retval参数。

用`grep`命令进行查找，可以发现PTHREAD\_CANCELED实际上就是头文件<pthread.h>里面的一个宏定义，它的值本质就是-1。

```cpp
[cl@VM-0-15-centos thread]$ grep -ER "PTHREAD_CANCELED" /usr/include/
```

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707677.png)  

例如，在下面的代码中我们先不关心线程的退出信息，直接将pthread\_join函数的第二次参数设置为NULL，等待线程后打印该线程的编号以及线程ID。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void *Routine(void *arg)
{
    char *msg = (char *)arg;
    int count = 0;
    while (count < 2)
    {
        printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
        sleep(1);
        count++;
    }
    return (void *)2022;
}
int main()
{
    pthread_t tid[5];
    for (int i = 0; i < 5; i++)
    {
        char *buffer = (char *)malloc(64);
        sprintf(buffer, "thread %d", i);
        pthread_create(&tid[i], NULL, Routine, buffer);
        printf("%s tid is %lu\n", buffer, tid[i]);
    }
    printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
    for (int i = 0; i < 5; i++)
    {
        void *ret = NULL;
        pthread_join(tid[i], &ret);
        printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int*)ret);
    }
    return 0;
}
```

运行代码后，可以看到主线程创建的五个新线程在进行五次打印操作后就退出了，而主线程也是成功对这五个线程进行了等待。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707678.png)  

下面我们再来看看如何获取线程退出时的退出码，为了便于查看，我们这里将线程退出时的退出码设置为某个特殊的值，并在成功等待线程后将该线程的退出码进行输出。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	return (void*)2022;
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

运行代码，此时我们就拿到了每个线程退出时的退出码信息。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707679.png)  

**注意：** **pthread\_join函数默认是以阻塞的方式进行线程等待的**。

#### 为什么线程退出时只能拿到线程的退出码？

如果我们等待的是一个进程，那么当这个进程退出时，我们可以通过wait函数或是waitpid函数的输出型参数status，获取到退出进程的退出码、退出信号以及core dump标志。

**那为什么等待线程时我们只能拿到退出线程的退出码？难道线程不会出现异常吗？**

线程在运行过程中当然也会出现异常，线程和进程一样，线程退出的情况也有三种：

1.  代码运行完毕，结果正确。
2.  代码运行完毕，结果不正确。
3.  代码异常终止。

因此我们也需要考虑线程异常终止的情况，但是pthread\_join函数无法获取到线程异常退出时的信息。因为线程是进程内的一个执行分支，如果进程中的某个线程崩溃了，那么整个进程也会因此而崩溃，此时我们根本没办法执行pthread\_join函数，因为整个进程已经退出了。

例如，我们在线程的执行例程当中制造一个除零错误，当某一个线程执行到此处时就会崩溃，进而导致整个进程崩溃。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
		int a = 1 / 0; //error
	}
	return (void*)2022;
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

运行代码，可以看到一旦某个线程崩溃了，整个进程也就跟着挂掉了，此时主线程连等待新线程的机会都没有，这也说明了**多线程的健壮性不太强**，一个进程中只要有一个线程挂掉了，那么整个进程就挂掉了。并且此时我们也不知道是由于哪一个线程崩溃导致的，我们只知道是这个进程崩溃了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707780.png)  

所以**pthread\_join函数只能获取到线程正常退出时的退出码，用于判断线程的运行结果是否正确**。

### 线程终止

如果需要只终止某个线程而不是终止整个进程，可以有三种方法：

1.  从线程函数return。
2.  线程可以自己调用pthread\_exit函数终止自己。
3.  一个线程可以调用pthread\_cancel函数终止同一进程中的另一个线程。

> 线程退出码和进程退出码一样，都是保存在pcb里的，等待被上级读取后，释放

#### return退出

**在线程中使用return代表当前线程退出，但是在main函数中使用return代表整个进程退出**，也就是说只要主线程退出了那么整个进程就退出了，此时该进程曾经申请的资源就会被释放，而其他线程会因为没有了资源，自然而然的也退出了。

例如，在下面代码中，主线程创建五个新线程后立刻进行return，那么整个进程也就退出了。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	while (1){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
	}
	return (void*)0;
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());

	return 0;
}
```

运行代码，并不能看到新线程执行的打印操作，因为主线程的退出导致整个进程退出了。(在主线程的时间片：创建五个线程，退出) ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707781.png)

#### pthread\_exit函数

pthread\_exit函数的功能就是终止线程，pthread\_exit函数的函数原型如下：

```cpp
void pthread_exit(void *retval);
```

参数说明：

+   retval：线程退出时的退出码信息。(输出型参数)

**说明一下：**

+   该函数无返回值，跟进程一样，线程结束的时候无法返回它的调用者（自身）。
+   **pthread\_exit或者return返回的指针所指向的内存单元必须是全局的或者是用malloc分配的，不能在线程函数的栈上分配，因为当其他线程得到这个返回指针时，线程函数已经退出了。**

例如，在下面代码中，我们使用pthread\_exit函数终止线程，并将线程的退出码设置为6666。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

运行代码可以看到，当线程退出时其退出码就是我们设置的6666。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707782.png)  

**注意：** exit函数的作用是终止进程，任何一个线程调用exit函数也代表的是整个进程终止。

#### pthread\_cancel函数

线程是可以被取消的，我们可以使用**pthread\_cancel函数取消某一个线程**，pthread\_cancel函数的函数原型如下：

```cpp
int pthread_cancel(pthread_t thread);
```

参数说明：

+   thread：被取消线程的ID(用户级)。

返回值说明：

+   线程取消成功返回0，失败返回错误码。

**线程是可以取消自己的**，取消成功的线程的退出码一般是-1。例如在下面的代码中，我们让线程执行一次打印操作后将自己取消。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
		pthread_cancel(pthread_self());
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

运行代码，可以看到每个线程执行一次打印操作后就退出了，其退出码不是我们设置的6666而是-1，因为我们是在线程执行pthread\_exit函数前将线程取消的。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707783.png)  

虽然线程可以自己取消自己，但一般不这样做，我们往往是用于一个线程取消另一个线程，比如主线程取消新线程。

例如，在下面代码中，我们在创建五个线程后立刻又将0、1、2、3号线程取消。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	pthread_cancel(tid[0]);
	pthread_cancel(tid[1]);
	pthread_cancel(tid[2]);
	pthread_cancel(tid[3]);
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

此时可以发现，0、1、2、3号线程退出时的退出码不是我们设置的6666，而只有未被取消的4号线程的退出码是6666，因为只有4号进程未被取消。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707784.png)  

此外，**新线程也是可以取消主线程的**，例如下面我们让每一个线程都尝试对主线程进行取消。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

pthread_t main_thread;

void* Routine(void* arg)
{
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
		pthread_cancel(main_thread);
	}
	pthread_exit((void*)6666);
}
int main()
{
	main_thread = pthread_self();
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
	for (int i = 0; i < 5; i++){
		void* ret = NULL;
		pthread_join(tid[i], &ret);
		printf("thread %d[%lu]...quit, exitcode: %d\n", i, tid[i], (int)ret);
	}
	return 0;
}
```

运行代码，同时用以下监控脚本进行实时监控。

```cpp
[cl@VM-0-15-centos threadCreate]$ while :; do ps -aL | head -1&&ps -aL | grep mythread | grep -v grep;echo "###############";s
```

可以看到一段时间后，六个线程中PID和LWP相同的线程，也就是主线程右侧显示`<defunct>`，也就意味着主线程已经被取消了，我们也就看不到后续主线程等待新线程时打印的退出码了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707785.png)  
**注意：**

1.  **当采用这种取消方式时，主线程和各个新线程之间的地位是对等的，取消一个线程，其他线程也是能够跑完的**，只不过主线程不再执行后续代码了。
2.  我们一般都是用主线程去控制新线程，这才符合我们对线程控制的基本逻辑，虽然实验表明新线程可以取消主线程，但是并不推荐该做法。

### 线程分离

+   默认情况下，新创建的线程是joinable的，线程退出后，需要对其进行pthread\_join操作，否则无法释放资源，从而造成内存泄漏。
+   但如果我们不关心线程的返回值，join也是一种负担，此时我们可以将该线程进行分离，后续当线程退出时就会自动释放线程资源。
+   **一个线程如果被分离了，这个线程依旧要使用该进程的资源，依旧在该进程内运行，甚至这个线程崩溃了一定会影响其他线程，只不过这个线程退出时不再需要主线程去join了，当这个线程退出时系统会自动回收该线程所对应的资源。**
+   可以是线程组内其他线程对目标线程进行分离，也可以是线程自己分离。
+   joinable和分离是冲突的，一个线程不能既是joinable又是分离的。
+   分离线程的函数叫做pthread\_detach

**pthread\_detach函数**的函数原型如下：

```cpp
int pthread_detach(pthread_t thread);
```

参数说明：

+   thread：被分离线程的ID。

返回值说明：

+   线程分离成功返回0，失败返回错误码。

例如，下面我们创建五个新线程后让这五个新线程将自己进行分离，那么此后主线程就不需要在对这五个新线程进行join了。

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void* Routine(void* arg)
{
	pthread_detach(pthread_self());
	char* msg = (char*)arg;
	int count = 0;
	while (count < 5){
		printf("I am %s...pid: %d, ppid: %d, tid: %lu\n", msg, getpid(), getppid(), pthread_self());
		sleep(1);
		count++;
	}
	pthread_exit((void*)6666);
}
int main()
{
	pthread_t tid[5];
	for (int i = 0; i < 5; i++){
		char* buffer = (char*)malloc(64);
		sprintf(buffer, "thread %d", i);
		pthread_create(&tid[i], NULL, Routine, buffer);
		printf("%s tid is %lu\n", buffer, tid[i]);
	}
	while (1){
		printf("I am main thread...pid: %d, ppid: %d, tid: %lu\n", getpid(), getppid(), pthread_self());
		sleep(1);
	}
	return 0;
}
```

这五个新线程在退出时，系统会自动回收对应线程的资源，不需要主线程进行join。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707786.png)

### 线程ID及进程地址空间布局

+   pthread\_create函数会产生一个线程ID，存放在第一个参数指向的地址中，该**线程ID和内核中的LWP不是一回事**。
+   内核中的LWP属于进程调度的范畴，因为线程是轻量级进程，是操作系统调度器的最小单位，所以需要一个数值来唯一表示该线程。
+   **pthread\_create函数第一个参数指向一个虚拟内存单元，该内存单元的地址即为新创建线程的线程ID**，这个ID属于NPTL线程库的范畴，线程库的后续操作就是根据该线程ID来操作线程的。
+   线程库NPTL提供的pthread\_self函数，获取的线程ID和pthread\_create函数第一个参数获取的线程ID是一样的。

**pthread\_t到底是什么类型呢？**

> 首先，Linux不提供真正的线程，只提供LWP(轻量级进程)，也就意味着操**作系统只需要对内核执行流LWP进行管理**，而供用户使用的线程接口等其他数据，应该由线程库自己来管理，因此管理线程时的“先描述，再组织”就应该在线程库里进行。
>
> **通过`ldd`命令可以看到，我们采用的线程库实际上是一个动态库**。  
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697967485102.png)
>
> 进程运行时动态库被加载到内存，然后通过页表映射到进程地址空间中的共享区，此时该进程内的所有线程都是能看到这个动态库的。  
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697980754105.png)
>
> 我们说**每个线程都有自己私有的栈**，其中**主线程采用的栈是进程地址空间中原生的栈**，**而其余线程采用的栈就是在共享区中开辟的**。除此之外，每个**线程都有自己的struct pthread，当中包含了对应线程的各种属性**；每个**线程还有自己的线程局部存储，当中包含了对应线程被切换时的上下文数据**。  
>
> 每一个新线程在共享区都有这样一块区域对其进行描述，因此我们要找到一个用户级线程只需要找到该线程内存块的起始地址，然后就可以获取到该线程的各种信息。  
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168169709707789.png)  
>
> 上面我们所用的各种线程函数，本质都是在库内部对线程属性进行的各种操作，最后将要执行的代码交给对应的内核级LWP去执行就行了，也就是说**线程数据的管理本质是在共享区的**。
>
> **pthread\_t到底是什么类型取决于实现**，但是对于Linux目前实现的NPTL线程库来说，线程ID本质就是进程地址空间共享区上的一个虚拟地址，同一个进程中所有的虚拟地址都是不同的，因此可以用它来唯一区分每一个线程。
>
> 例如，我们也可以尝试按地址的形式对获取到的线程ID进行打印。
>
> ```cpp
> #include <stdio.h>
> #include <pthread.h>
> #include <unistd.h>
> 
> void* Routine(void* arg)
> {
> 	while (1){
> 		printf("new  thread tid: %p\n", pthread_self());
> 		sleep(1);
> 	}
> }
> int main()
> {
> 	pthread_t tid;
> 	pthread_create(&tid, NULL, Routine, NULL);
> 	while (1){
> 		printf("main thread tid: %p\n", pthread_self());
> 		sleep(2);
> 	}
> 	return 0;
> }
> ```
>
> 在此之前我们可以说这个打印结果很像一个地址，但是现在我们可以说，这本质就是一个地址。  
>
> ![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698005370108.png)
>



## 线程安全

### Linux线程互斥

#### 进程线程间的互斥相关背景概念

+   **临界资源：** 多线程执行流共享的资源叫做临界资源。
+   **临界区：** 每个线程内部，访问临界资源的代码，就叫做临界区。
+   **互斥：** 任何时刻，互斥保证有且只有一个执行流进入临界区，访问临界资源，通常对临界资源起保护作用。
+   **原子性：** 不会被任何调度机制打断的操作，该操作只有两态，要么完成，要么未完成。

##### 临界资源和临界区

进程之间如果要进行通信我们需要先创建第三方资源，让不同的进程看到同一份资源，由于这份第三方资源可以由操作系统中的不同模块提供，于是进程间通信的方式有很多种。

进程间通信中的第三方资源就叫做临界资源，访问第三方资源的代码就叫做临界区。

而多线程的大部分资源都是共享的，线程之间进行通信不需要费那么大的劲去创建第三方资源。

例如，我们只需要在全局区定义一个count变量，让新线程每隔一秒对该变量加一操作，让主线程每隔一秒获取count变量的值进行打印。

```cpp
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count = 0;
void* Routine(void* arg)
{
	while (1){
		count++;
		sleep(1);
	}
	pthread_exit((void*)0);
}
int main()
{
	pthread_t tid;
	pthread_create(&tid, NULL, Routine, NULL);
	while (1){
		printf("count: %d\n", count);
		sleep(1);
	}
	pthread_join(tid, NULL);
	return 0;
}
```

运行结果如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173153.png)  

此时我们相当于实现了主线程和新线程之间的通信，其中全局变量count就叫做临界资源，因为它被多个执行流共享，而主线程中的printf和新线程中count++就叫做临界区，因为这些代码对临界资源进行了访问。

##### 互斥和原子性

在多线程情况下，如果这多个执行流都自顾自的对临界资源进行操作，那么此时就可能**导致数据不一致的问题**。解决该问题的方案就叫做互斥，互斥的作用就是，保证在任何时候有且只有一个执行流进入临界区对临界资源进行访问。

**原子性指的是不可被分割的操作，该操作不会被任何调度机制打断，该操作只有两态，要么完成，要么未完成**。

例如，下面我们模拟实现一个抢票系统，我们将记录票的剩余张数的变量定义为全局变量，主线程创建四个新线程，让这四个新线程进行抢票，当票被抢完后这四个线程自动退出。

```cpp
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int tickets = 1000;
void* TicketGrabbing(void* arg)
{
	const char* name = (char*)arg;
	while (1){
		if (tickets > 0){
			usleep(10000);
			printf("[%s] get a ticket, left: %d\n", name, --tickets);
		}
		else{
			break;
		}
	}
	printf("%s quit!\n", name);
	pthread_exit((void*)0);
}
int main()
{
	pthread_t t1, t2, t3, t4;
	pthread_create(&t1, NULL, TicketGrabbing, "thread 1");
	pthread_create(&t2, NULL, TicketGrabbing, "thread 2");
	pthread_create(&t3, NULL, TicketGrabbing, "thread 3");
	pthread_create(&t4, NULL, TicketGrabbing, "thread 4");
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	return 0;
}
```

运行结果显然不符合我们的预期，因为其中出现了剩余票数为负数的情况。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173154.png)  

该代码中记录剩余票数的变量tickets就是临界资源，因为它被多个执行流同时访问，而判断tickets是否大于0、打印剩余票数以及`--tickets`这些代码就是临界区，因为这些代码对临界资源进行了访问。

剩余票数出现负数的原因：

+   if语句判断条件为真以后，代码可以并发的切换到其他线程。
+   usleep用于模拟漫长业务的过程，在这个漫长的业务过程中，可能有很多个线程会进入该代码段。
+   `--ticket`操作本身就不是一个原子操作。

> 为什么`--ticket`不是原子操作？

我们对一个变量进行`--`，我们实际需要进行以下三个步骤：

1.  `load`：将共享变量tickets从内存加载到寄存器中。
2.  `update`：更新寄存器里面的值，执行-1操作。
3.  `store`：将新值从寄存器写回共享变量tickets的内存地址。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16.png)

`--`操作对应的汇编代码如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/6c282b06c5754ccfa051bb2b7b07fcd5.png)  

既然`--`操作需要三个步骤才能完成，那么就有可能当thread1刚把tickets的值读进CPU就被切走了，也就是从CPU上剥离下来，假设此时thread1读取到的值就是1000，而当thread1被切走时，寄存器中的1000叫做thread1的上下文信息，因此需要被保存起来，之后thread1就被挂起了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16823946947913.png)

假设此时thread2被调度了，由于thread1只进行了`--`操作的第一步，因此thread2此时看到tickets的值还是1000，而系统给thread2的时间片可能较多，导致thread2一次性执行了100次`--`才被切走，最终tickets由1000减到了900。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16823947131926.png)

此时系统再把thread1恢复上来，恢复的本质就是继续执行thread1的代码，并且要将thread1曾经的硬件上下文信息恢复出来，此时![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-16823947242249.png)

在上述过程中，thread1抢了1张票，thread2抢了100张票，而此时剩余的票数却是999，也就相当于多出了100张票。

因此对一个变量进行`--`操作并不是原子的，虽然`--tickets`看起来就是一行代码，但这行代码被编译器编译后本质上是三行汇编，相反，对一个变量进行`++`也需要对应的三个步骤，即`++`操作也不是原子操作。

#### 互斥量mutex

+   大部分情况，线程使用的数据都是局部变量，变量的地址空间在线程栈空间内，这种情况变量归属单个线程，其他线程无法获得这种变量。
+   但有时候，很多变量都需要在线程间共享，这样的变量成为共享变量，可以通过数据的共享，完成线程之间的交互。
+   多个线程并发的操作共享变量，就会带来一些问题。

要解决上述抢票系统的问题，需要**做到三点**：

+   代码必须有互斥行为：当代码进入临界区执行时，不允许其他线程进入该临界区。
+   如果多个线程同时要求执行临界区的代码，并且此时临界区没有线程在执行，那么只能允许一个线程进入该临界区。
+   如果线程不在临界区中执行，那么该线程不能阻止其他线程进入临界区。

要做到这三点，本质上就是需要一把锁，Linux上提供的这把锁叫互斥量。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173159.png)

#### 互斥量的接口

##### 初始化互斥量

**初始化互斥量的函数叫做pthread\_mutex\_init**，该函数的函数原型如下：

```cpp
int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
```

参数说明：

+   mutex：需要初始化的互斥量。
+   attr：初始化互斥量的属性，一般设置为NULL即可。

返回值说明：

+   互斥量初始化成功返回0，失败返回错误码。

**调用pthread\_mutex\_init函数初始化互斥量叫做动态分配**，除此之外，我们还可以用下面这种方式初始化互斥量，该方式叫做**静态分配：**

```cpp
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
```

##### 销毁互斥量

**销毁互斥量的函数叫做pthread\_mutex\_destroy**，该函数的函数原型如下：

```cpp
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

参数说明：

+   mutex：需要销毁的互斥量。

返回值说明：

+   互斥量销毁成功返回0，失败返回错误码。

销毁互斥量需要注意：

+   **使用`PTHREAD_MUTEX_INITIALIZER`初始化的互斥量不需要销毁**。
+   **不要销毁一个已经加锁的互斥量**。
+   **已经销毁的互斥量，要确保后面不会有线程再尝试加锁**。

##### 互斥量加锁

**互斥量加锁的函数叫做pthread\_mutex\_lock**，该函数的函数原型如下：

```cpp
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

参数说明：

+   mutex：需要加锁的互斥量。

返回值说明：

+   互斥量加锁成功返回0，失败返回错误码。

调用`pthread_mutex_lock`时，可能会遇到以下情况：

1.  互斥量处于未锁状态，该函数会将互斥量锁定，同时返回成功。
2.  发起函数调用时，其他线程已经锁定互斥量，或者存在其他线程同时申请互斥量，但没有竞争到互斥量，那么`pthread_mutex_lock`调用会**陷入阻塞**（执行流被挂起），等待互斥量解锁。

##### 互斥量解锁

**互斥量解锁的函数叫做pthread\_mutex\_unlock**，该函数的函数原型如下：

```cpp
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

参数说明：

+   mutex：需要解锁的互斥量。

返回值说明：

+   互斥量解锁成功返回0，失败返回错误码。

##### 使用示例：

例如，我们在上述的抢票系统中引入互斥量，每一个线程要进入临界区之前都必须先申请锁，只有申请到锁的线程才可以进入临界区对临界资源进行访问，并且当线程出临界区的时候需要释放锁，这样才能让其余要进入临界区的线程继续竞争锁。

```cpp
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int tickets = 1000;
pthread_mutex_t mutex;
void *TicketGrabbing(void *arg)
{
    const char *name = (char *)arg;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (tickets > 0)
        {
            usleep(100);
            printf("[%s] get a ticket, left: %d\n", name, --tickets);
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    printf("%s quit!\n", name);
    pthread_exit((void *)0);
}
int main()
{
    pthread_mutex_init(&mutex, NULL); // 初始化锁

    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, TicketGrabbing, (void*)"thread 1");
    pthread_create(&t2, NULL, TicketGrabbing, (void*)"thread 2");
    pthread_create(&t3, NULL, TicketGrabbing, (void*)"thread 3");
    pthread_create(&t4, NULL, TicketGrabbing, (void*)"thread 4");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&mutex); // 销毁锁
    return 0;
}
```

运行代码，此时在抢票过程中就不会出现票数剩余为负数的情况了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173160.png)  
**注意：**

+   **在大部分情况下，加锁本身都是有损于性能的事**，它让多执行流由并行执行变为了串行执行，这几乎是不可避免的。
+   我们应该在合适的位置进行加锁和解锁，这样能尽可能减少加锁带来的性能开销成本。
+   进行临界资源的保护，是所有执行流都应该遵守的标准，这时程序员在编码时需要注意的。

#### 互斥量实现原理探究

##### 加锁后的原子性体现在哪里？

引入互斥量后，当一个线程申请到锁进入临界区时，在其他线程看来该线程只有两种状态，要么没有申请锁(拿到锁了)，要么锁已经释放了，因为只有这两种状态对其他线程才是有意义的。

例如，图中线程1进入临界区后，在线程2、3、4看来，线程1要么没有申请锁，要么线程1已经将锁释放了，因为只有这两种状态对线程2、3、4才是有意义的，当线程2、3、4检测到其他状态时也就被阻塞了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173161.png)  

此时对于线程2、3、4而言，它们就认为线程1的整个操作过程是原子的。

##### 临界区内的线程可能进行线程切换吗？

临界区内的线程完全可能进行线程切换，但即便该线程被切走，其他线程也无法进入临界区进行资源访问，因为此时该线程是拿着锁被切走的，锁没有被释放也就意味着其他线程无法申请到锁，也就无法进入临界区进行资源访问了。

其他想进入该临界区进行资源访问的线程，必须等该线程执行完临界区的代码并释放锁之后，才能申请锁，申请到锁之后才能进入临界区。

##### 锁是否需要被保护？

我们说被多个执行流共享的资源叫做临界资源，访问临界资源的代码叫做临界区。所有的线程在进入临界区之前都必须竞争式的申请锁，因此锁也是被多个执行流共享的资源，也就是说锁本身就是临界资源。

既然锁是临界资源，那么锁就必须被保护起来，但锁本身就是用来保护临界资源的，那锁又由谁来保护的呢？

**锁实际上是自己保护自己的，我们只需要保证申请锁的过程是原子的，那么锁就是安全的**。

##### 如何保证申请锁的过程是原子的？

+   上面我们已经说明了`--`和`++`操作不是原子操作，可能会导致数据不一致问题。
+   **为了实现互斥锁操作，大多数体系结构都提供了swap或exchange指令**，该指令的作用就是把寄存器和内存单元的数据相交换。
+   **由于只有一条指令，保证了原子性**，即使是多处理器平台，访问内存的总线周期也有先后，一个处理器上的交换指令执行时，另一个处理器的交换指令只能等待总线周期。

> 操作系统的工作原理：
>
> +   操作系统一旦启动成功后就是一个**死循环**。
> +   时钟是计算机中的一个硬件，时钟每隔一段时间会向操作系统发起一个**时钟中断**，操作系统就会根据时钟中断去执行中断向量表。
> +   **中断向量表本质上就是一个函数表**，比如刷磁盘的函数、检测网卡的函数以及刷新数据的函数等等。
> +   计算机不断向操作系统发起时钟中断，操作系统就根据时钟中断，不断地去切换执行对应的代码。
> +   CPU有多个，但总线只有一套。CPU和内存都是计算机中的硬件，这两个硬件之间要进行数据交互一定是用线连接起来的，其中我们把CPU和内存连接的线叫做系统总线，把内存和外设连接起来的线叫做IO总线。
> +   系统总线只有一套，有的时候CPU访问内存是想从内存中读取指令，有的时候是想从内存读取数据，所以总线是被不同的操作种类共享的。计算机是通过总线周期来区分此时总线当中传输的是哪种资源的。

下面我们来看看lock和unlock的伪代码：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173162.png)  

我们可以认为mutex的初始值为1，al是计算机中的一个寄存器，当线程申请锁时，需要执行以下步骤：

1.  先将al寄存器中的值清0。该动作可以被多个线程同时执行，因为每个线程都有自己的一组寄存器（上下文信息），执行该动作本质上是将自己的al寄存器清0。
2.  然后交换al寄存器和mutex中的值。**xchgb是体系结构提供的交换指令**，该指令可以完成原子性地寄存器和内存单元之间数据的交换。
3.  最后判断al寄存器中的值是否大于0。若大于0则申请锁成功，此时就可以进入临界区访问对应的临界资源；否则申请锁失败需要被挂起等待，直到锁被释放后再次竞争申请锁。

例如，此时内存中mutex的值为1，线程申请锁时先将al寄存器中的值清0，然后将al寄存器中的值与内存中mutex的值进行交换。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173163.png)  

交换完成后检测该线程的al寄存器中的值为1，则该线程申请锁成功，可以进入临界区对临界资源进行访问。

而此后的线程若是再申请锁，与内存中的mutex交换得到的值就是0了，此时该线程申请锁失败，需要被挂起等待，直到锁被释放后再次竞争申请锁。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173164.png)  

当线程释放锁时，需要执行以下步骤：

1.  将内存中的mutex置回1。使得下一个申请锁的线程在执行交换指令后能够得到1，形象地说就是“将锁的钥匙放回去”。
2.  唤醒等待Mutex的线程。唤醒这些因为申请锁失败而被挂起的线程，让它们继续竞争申请锁。

**注意：**

+   在申请锁时本质上就是哪一个线程先执行了交换指令，那么该线程就申请锁成功，因为此时该线程的al寄存器中的值就是1了。而交换指令就只是一条汇编指令，一个线程要么执行了交换指令，要么没有执行交换指令，所以**申请锁的过程是原子的**。
+   在线程释放锁时没有将当前线程al寄存器中的值清0，这不会造成影响，因为每次线程在申请锁时都会先将自己al寄存器中的值清0，再执行交换指令。
+   **CPU内的寄存器不是被所有的线程共享的，每个线程都有自己的一组寄存器**，但内存中的数据是各个线程共享的。申请锁实际就是，把内存中的mutex通过交换指令，原子性的交换到自己的al寄存器中。

### 可重入VS线程安全

#### 概念

+   **线程安全：** 多个线程并发同一段代码时，不会出现不同的结果。常见对全局变量或者静态变量进行操作，并且没有锁保护的情况下，会出现线程安全问题。
+   **重入：** 同一个函数被不同的执行流调用，当前一个流程还没有执行完，就有其他的执行流再次进入，我们称之为重入。一个函数在重入的情况下，运行结果不会出现任何不同或者任何问题，则该函数被称为可重入函数，否则是不可重入函数。

**注意：** 线程安全讨论的是线程执行代码时是否安全，重入讨论的是函数被重入进入。

#### 常见的线程不安全的情况

+   不保护共享变量的函数。

+   函数状态随着被调用，状态发生变化的函数。

+   返回指向静态变量指针的函数。

+   调用线程不安全函数的函数。

#### 常见的线程安全的情况

+   每个线程对全局变量或者静态变量只有读取的权限，而没有写入的权限，一般来说这些线程是安全的。
+   类或者接口对于线程来说都是原子操作。
+   多个线程之间的切换**不会导致该接口的执行结果存在二义性**。

#### 常见的不可重入的情况

+   调用了malloc/free函数，因为malloc函数是用全局链表来管理堆的。
+   调用了标准I/O库函数，标准I/O可以的很多实现都是以不可重入的方式使用全局数据结构。
+   可重入函数体内使用了静态的数据结构。

#### 常见的可重入的情况

+   不使用全局变量或静态变量。
+   不使用malloc或者new开辟出的空间。
+   不调用不可重入函数。
+   不返回静态或全局数据，所有数据都由函数的调用者提供。
+   使用本地数据，或者通过制作全局数据的本地拷贝来保护全局数据。

#### 可重入与线程安全联系

+   函数是可重入的，那就是线程安全的。
+   函数是不可重入的，那就不能由多个线程使用，有可能引发线程安全问题。
+   如果一个函数中有全局变量，那么这个函数既不是线程安全也不是可重入的。

#### 可重入与线程安全区别

+   **可重入函数是线程安全函数的一种**。
+   线程安全不一定是可重入的，而可重入函数则一定是线程安全的。
+   如果对临界资源的访问加上锁，则这个函数是线程安全的，但如果这个重入函数的锁还未释放则会产生死锁，因此是不可重入的。

### 常见锁概念

#### 死锁

+   死锁是指在一组进程中的各个进程均占有不会释放的资源，但因互相申请被其他进程所占用不会释放的资源而处于的一种永久等待状态。

##### 单执行流可能产生死锁吗？

**单执行流也有可能产生死锁，如果某一执行流连续申请了两次锁，那么此时该执行流就会被挂起。**因为该执行流第一次申请锁的时候是申请成功的，但第二次申请锁时因为该锁已经被申请过了，于是申请失败导致被挂起直到该锁被释放时才会被唤醒，但是这个锁本来就在自己手上，自己现在处于被挂起的状态根本没有机会释放锁，所以该执行流将永远不会被唤醒，此时该执行流也就处于一种死锁的状态。

例如，在下面的代码中我们让主线程创建的新线程连续申请了两次锁。

```cpp
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
void* Routine(void* arg)
{
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex);
	
	pthread_exit((void*)0);
}
int main()
{
	pthread_t tid;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&tid, NULL, Routine, NULL);
	
	pthread_join(tid, NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}
```

运行代码，此时该程序实际就处于一种被挂起的状态。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173165.png)  

用`ps`命令查看该进程时可以看到，该进程当前的状态是`Sl+`，其中的`l`实际上就是lock的意思，表示该进程当前处于一种死锁的状态。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-168240322390812.png)

##### 什么叫做阻塞？

> **等待非CPU资源就绪, 就是阻塞,如IO资源。**

进程运行时是被CPU调度的，换句话说进程在调度时是需要用到CPU资源的，每个CPU都有一个运行等待队列（runqueue），CPU在运行时就是从该队列中获取进程进行调度的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367173167.png)  

在运行等待队列中的进程本质上就是在等待CPU资源，实际上不止是等待CPU资源如此，等待其他资源也是如此，比如锁的资源、磁盘的资源、网卡的资源等等，它们都有各自对应的资源等待队列。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16.png)

例如，当某一个进程在被CPU调度时，该进程需要用到锁的资源，但是此时锁的资源正在被其他进程使用：

> +   那么此时该进程的状态就会由R状态变为某种阻塞状态，比如S状态。并且该进程会被移出运行等待队列，被链接到等待锁的资源的资源等待队列，而CPU则继续调度运行等待队列中的下一个进程。
> +   此后若还有进程需要用到这一个锁的资源，那么这些进程也都会被移出运行等待队列，依次链接到这个锁的资源等待队列当中。
> +   直到使用锁的进程已经使用完毕，也就是锁的资源已经就绪，此时就会从锁的资源等待队列中唤醒一个进程，将该进程的状态由S状态改为R状态，并将其重新链接到运行等待队列，等到CPU再次调度该进程时，该进程就可以使用到锁的资源了。

**总结一下：**

+   站在操作系统的角度，进程等待某种资源，就是将当前进程的task\_struct放入对应的等待队列，这种情况可以称之为当前进程被挂起等待了。
+   站在用户角度，当进程等待某种资源时，用户看到的就是自己的进程卡住不动了，我们一般称之为应用阻塞了。
+   这里所说的**资源可以是硬件资源也可以是软件资源**，锁本质就是一种软件资源，当我们申请锁时，锁当前可能并没有就绪，可能正在被其他线程所占用，此时当其他线程再来申请锁时，就会被放到这个锁的资源等待队列当中。

#### 死锁的四个必要条件

+   **互斥条件：** 一个资源每次只能被一个执行流使用。
+   **请求与保持条件：** 一个执行流因请求资源而阻塞时，对已获得的资源保持不放。
+   **不剥夺条件：** 一个执行流已获得的资源，在未使用完之前，不能强行剥夺。
+   **循环等待条件：** 若干执行流之间形成一种头尾相接的循环等待资源的关系。

**注意：** 这是死锁的四个必要条件，也就是说**只有同时满足了这四个条件才可能产生死锁**。

#### 避免死锁

+   破坏死锁的四个必要条件。
+   加锁顺序一致。
+   避免锁未释放的场景。
+   资源一次性分配。

除此之外，还有一些避免死锁的算法，比如**死锁检测算法和银行家算法**。

### Linux线程同步

#### 同步概念与竞态条件

> **同步：** 在保证数据安全的前提下，让**线程能够按照某种特定的顺序访问临界资源，从而有效避免饥饿问题，这就叫做同步**。  
>
> **竞态条件：** **因为时序问题，而导致程序异常，我们称之为竞态条件**。

+   首先需要明确的是，单纯的加锁是会存在某些问题的，如果个别线程的竞争力特别强，每次都能够申请到锁，但申请到锁之后什么也不做，所以在我们看来这个线程就一直在申请锁和释放锁，这就可能**导致其他线程长时间竞争不到锁，引起饥饿问题**。
+   单纯的加锁是没有错的，它能够保证在同一时间只有一个线程进入临界区，但它**没有高效的让每一个线程使用这份临界资源**。
+   现在我们增加一个规则，当一个线程释放锁后，这个线程不能立马再次申请锁，该线程必须排到这个锁的资源等待队列的最后。
+   增加这个规则之后，下一个获取到锁的资源的线程就一定是在资源等待队列首部的线程，如果有十个线程，此时我们就能够让这十个线程按照某种次序进行临界资源的访问。

例如，现在有两个线程访问一块临界区，一个线程往临界区写入数据，另一个线程从临界区读取数据，但负责数据写入的线程的竞争力特别强，该线程每次都能竞争到锁，那么此时该线程就一直在执行写入操作，直到临界区被写满，此后该线程就一直在进行申请锁和释放锁。而负责数据读取的线程由于竞争力太弱，每次都申请不到锁，因此无法进行数据的读取，引入同步后该问题就能很好的解决。

#### 条件变量

> **条件变量是利用线程间共享的全局变量进行同步的一种机制，条件变量是用来描述某种资源是否就绪的一种数据化描述**。
>
> **条件变量不是为了保护临界区资源的，而是合理使用临界区资源的。**

条件变量主要包括两个动作：

+   一个线程等待 条件变量的条件成立 而被**挂起**。
+   另一个线程 使条件成立后 **唤醒**等待的线程。

条件变量通常需要配合互斥锁一起使用。

#### 条件变量函数

##### 初始化条件变量

初始化条件变量的函数叫做**pthread\_cond\_init**，该函数的函数原型如下：

```cpp
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);
```

参数说明：

+   cond：需要初始化的条件变量。
+   attr：初始化条件变量的属性，一般设置为NULL即可。

返回值说明：

+   条件变量初始化成功返回0，失败返回错误码。

调用pthread\_cond\_init函数初始化条件变量叫做**动态分配**，除此之外，我们还可以用下面这种方式初始化条件变量，该方式叫做**静态分配**：

```cpp
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
```

##### 销毁条件变量

销毁条件变量的函数叫做**pthread\_cond\_destroy**，该函数的函数原型如下：

```cpp
int pthread_cond_destroy(pthread_cond_t *cond);
```

参数说明：

+   cond：需要销毁的条件变量。

返回值说明：

+   条件变量销毁成功返回0，失败返回错误码。

销毁条件变量需要注意：

+   使用`PTHREAD_COND_INITIALIZER`初始化的条件变量不需要销毁。

##### 等待条件变量满足

等待条件变量满足的函数叫做**pthread\_cond\_wait**，该函数的函数原型如下：

```cpp
int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
```

参数说明：

+   **cond：需要等待的条件变量。**
+   **mutex：当前线程所处临界区对应的互斥锁。**

返回值说明：

+   函数调用成功返回0，失败返回错误码。

##### 唤醒等待

唤醒等待的函数有以下两个：

```cpp
int pthread_cond_broadcast(pthread_cond_t *cond);
int pthread_cond_signal(pthread_cond_t *cond);
```

区别：

+   **pthread\_cond\_signal函数用于唤醒等待队列中首个线程。**
+   **pthread\_cond\_broadcast函数用于唤醒等待队列中的全部线程。**

参数说明：

+   cond：唤醒在cond条件变量下等待的线程。

返回值说明：

+   函数调用成功返回0，失败返回错误码。

##### 使用示例：

例如，下面我们用主线程创建三个新线程，让主线程控制这三个新线程活动。这三个新线程创建后都在条件变量下进行等待，直到主线程检测到键盘有输入时才唤醒一个等待线程，如此进行下去。

```cpp
#include <cstdio>
#include <pthread.h>
#include <iostream>

pthread_mutex_t _g_mtx;
pthread_cond_t _g_cond;

void *Routine(void *arg)
{
    pthread_detach(pthread_self());

    std::cout << (char *)arg << "run..." << std::endl;

    while (1)
    {
        pthread_mutex_lock(&_g_mtx); //加锁进入临界区

        //是否满足
        pthread_cond_wait(&_g_cond, &_g_mtx); //条件变量，一定要在加锁解锁中间等待

        std::cout << (char *)arg << "runing..." << std::endl;

        pthread_mutex_unlock(&_g_mtx); //解锁出临界区
    }
}

int main()
{

    pthread_mutex_init(&_g_mtx, NULL);
    pthread_cond_init(&_g_cond, NULL);

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, Routine, (void *)"thread 1");
    pthread_create(&t2, NULL, Routine, (void *)"thread 2");
    pthread_create(&t3, NULL, Routine, (void *)"thread 3");

    while (true)
    {
        getchar(); // 手动阻塞在IO
        pthread_cond_signal(&_g_cond);
    }

    pthread_mutex_destroy(&_g_mtx);
    pthread_cond_destroy(&_g_cond);

    return 0;
}
```

此时我们会发现唤醒这三个线程时具有明显的顺序性，根本原因是当这若干个线程启动时默认都会在该条件变量下去等待，而我们每次都唤醒的是在当前条件变量下等待的头部线程，当该线程执行完打印操作后会继续排到等待队列的尾部进行wait，所以我们能够看到一个周转的现象。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367174169.png)  

如果我们想每次唤醒都将在该条件变量下等待的所有线程进行唤醒，可以将代码中的`pthread_cond_signal`函数改为`pthread_cond_broadcast`函数。

此时我们每一次唤醒都会将所有在该条件变量下等待的线程进行唤醒，也就是每次都将这三个线程唤醒。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681697367174170.png)  
**小贴士：** C++源文件的后缀可以是`.cpp`、`.cc`、`.cxx`。

#### 为什么pthread\_cond\_wait需要互斥量

+ 条件等待是线程间同步的一种手段，如果只有一个线程，条件不满足，一直等下去都不会满足，所以必须要有一个线程通过某些操作，改变共享变量，使原先不满足的条件变得满足，并且友好的通知等待在条件变量上的线程。

+ 条件不会无缘无故的突然变得满足了，必然会牵扯到共享数据的变化，所以一定要用互斥锁来保护，没有互斥锁就无法安全的获取和修改共享数据。

+ **当线程进入临界区时需要先加锁，然后判断内部资源的情况，若不满足当前线程的执行条件，则需要在该条件变量下进行等待，但此时该线程是拿着锁被挂起的，也就意味着这个锁再也不会被释放了，此时就会发生死锁问题。**

+ **所以在调用`pthread_cond_wait`函数时，还需要将对应的互斥锁传入，此时当线程因为某些条件不满足需要在该条件变量下进行等待时，就会自动释放该互斥锁。**

+ 当该线程被唤醒时，该线程会接着执行临界区内的代码，此时便要求该线程必须立马获得对应的互斥锁，因此当某一个线程被唤醒时，实际会自动获得对应的互斥锁。


**总结一下：**

+   等待的时候往往是在临界区内等待的，当该线程进入等待的时候，互斥锁会自动释放，而当该线程被唤醒时，又会自动获得对应的互斥锁。
+   条件变量需要配合互斥锁使用，其中条件变量是用来完成同步的，而互斥锁是用来完成互斥的。
+   `pthread_cond_wait`函数有两个功能，一就是让线程在特定的条件变量下等待，二就是让线程释放对应的互斥锁。
+   **互斥量决定线程能否进入临界区，条件变量判断资源是否就绪(进入临界区了，但资源不一定就绪)**。
+   **使用条件变量之前，线程阻塞在临界区外部**，且靠线程能力竞争锁，进入临界区后，若资源不就绪，就会一直等待，循环判断是否就绪。
+   **使用条件变量之后，线程阻塞在临界区内部**，线程竞争锁，进入临界区，若资源不就绪，会释放锁并重新阻塞在条件变量队列，由外界唤醒，加锁后工作，且线程是同步的。
+   **条件变量解决饥饿问题。**
+   等待一定要在加锁解锁之间等待。

> 错误的设计

你可能会想：当我们上锁后进入临界区，如果发现条件不满足，那我们先解锁，然后在该条件变量下进行等待不就行了。

```cpp
//错误的设计
pthread_mutex_lock(&mutex);
while (condition_is_false){
	pthread_mutex_unlock(&mutex);
	//解锁之后，等待之前，条件可能已经满足，信号已经发出，但是该信号可能被错过
	pthread_cond_wait(&cond);
	pthread_mutex_lock(&mutex);
}
pthread_mutex_unlock(&mutex);
```

但这是不可行的，因为**解锁和等待不是原子操作**，调用解锁之后，在调用`pthread_cond_wait`函数之前，如果已经有其他线程获取到互斥量，发现此时条件满足，于是发送了信号，那么此时`pthread_cond_wait`函数将错过这个信号，最终可能会导致线程永远不会被唤醒，因此解锁和等待必须是一个原子操作。

而实际进入`pthread_cond_wait`函数后，会先判断条件变量是否等于0，若等于0则说明不满足，此时会先将对应的互斥锁解锁，直到`pthread_cond_wait`函数返回时再将条件变量改为1，并将对应的互斥锁加锁。

#### 条件变量使用规范

等待条件变量的代码

```cpp
pthread_mutex_lock(&mutex);//加锁
while (条件为假)
	pthread_cond_wait(&cond, &mutex);//保证被唤醒后，至少再判断一次(假唤醒)
修改条件
pthread_mutex_unlock(&mutex);//解锁
```

唤醒等待线程的代码

```cpp
pthread_mutex_lock(&mutex);
设置条件为真
pthread_cond_signal(&cond);
pthread_mutex_unlock(&mutex);
```

​                       

## 生产者消费者模型

### 生产者消费者模型的概念

> **生产者消费者模式就是通过一个容器来解决生产者和消费者的强耦合问题。**

生产者和消费者彼此之间不直接通讯，而通过这个容器来通讯，所以生产者生产完数据之后不用等待消费者处理，直接将生产的数据放到这个容器当中，消费者也不用找生产者要数据，而是直接从这个容器里取数据，这个容器就相当于一个缓冲区，平衡了生产者和消费者的处理能力，这个容器实际上就是用来给生产者和消费者**解耦**的。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242209.png)

### 生产者消费者模型的特点

生产者消费者模型是多线程同步与互斥的一个经典场景，其特点如下：

+   **三种关系：** 生产者和生产者（互斥关系）、消费者和消费者（互斥关系）、生产者和消费者（互斥关系、同步关系）。
+   **两种角色：** 生产者和消费者。（通常由进程或线程承担）
+   **一个交易场所：** 通常指的是内存中的一段缓冲区。（可以自己通过某种方式组织起来）

我们用代码编写生产者消费者模型的时候，本质就是对这三个特点进行维护。

> **生产者和生产者、消费者和消费者、生产者和消费者，它们之间为什么会存在互斥关系？**

介于生产者和消费者之间的容器可能会被多个执行流同时访问，因此我们需要将该临界资源用互斥锁保护起来。

其中，所有的生产者和消费者都会竞争式的申请锁，因此生产者和生产者、消费者和消费者、生产者和消费者之间都存在互斥关系。

> **生产者和消费者之间为什么会存在同步关系？**

+   如果让生产者一直生产，那么当生产者生产的数据将容器塞满后，生产者再生产数据就会生产失败。
+   反之，让消费者一直消费，那么当容器当中的数据被消费完后，消费者再进行消费就会消费失败。

虽然这样不会造成任何数据不一致的问题，但是这样会引起另一方的饥饿问题，是非常低效的。我们应该让生产者和消费者访问该容器时具有一定的顺序性，比如让生产者先生产，然后再让消费者进行消费。

**注意：** **互斥关系保证的是数据的正确性，而同步关系是为了让多线程之间协同起来**。

### 生产者消费者模型优点

+   **解耦。**
+   **支持并发。**
+   **支持忙闲不均。**

如果我们在主函数中调用某一函数，那么我们必须等该函数体执行完后才继续执行主函数的后续代码，因此**函数调用本质上是一种紧耦合**。

对应到生产者消费者模型中，函数传参实际上就是生产者生产的过程，而执行函数体实际上就是消费者消费的过程，但生产者只负责生产数据，消费者只负责消费数据，在消费者消费期间生产者可以同时进行生产，因此**生产者消费者模型本质是一种松耦合**。

### 基于BlockingQueue的生产者消费者模型

#### 基于阻塞队列的生产者消费者模型

> 在多线程编程中，阻塞队列（Blocking Queue）是一种常用于实现生产者和消费者模型的数据结构。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242210.png)  

其与普通的队列的区别在于：

+   当队列为空时，从队列获取元素的操作将会被阻塞，直到队列中放入了元素。
+   当队列满时，往队列里存放元素的操作会被阻塞，直到有元素从队列中取出。

**知识联系：** 看到以上阻塞队列的描述，我们很容易想到的就是管道，而阻塞队列最典型的应用场景实际上就是管道的实现。

#### 模拟实现基于阻塞队列的生产消费模型

为了方便理解，下面我们以单生产者、单消费者为例进行实现。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242211.png)  

其中的BlockQueue就是生产者消费者模型当中的交易场所，我们可以用C++STL库当中的queue进行实现。

```cpp
#include <iostream>
#include <pthread.h>
#include <queue>
#include <unistd.h>

#define NUM 5

template<class T>
class BlockQueue
{
private:
	bool IsFull()
	{
		return _q.size() == _cap;
	}
	bool IsEmpty()
	{
		return _q.empty();
	}
public:
	BlockQueue(int cap = NUM)
		: _cap(cap)
	{
		pthread_mutex_init(&_mutex, nullptr);
		pthread_cond_init(&_full, nullptr);
		pthread_cond_init(&_empty, nullptr);
	}
	~BlockQueue()
	{
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_full);
		pthread_cond_destroy(&_empty);
	}
	//向阻塞队列插入数据（生产者调用）
	void Push(const T& data)
	{
		pthread_mutex_lock(&_mutex);
		while (IsFull()){
			//不能进行生产，直到阻塞队列可以容纳新的数据
			pthread_cond_wait(&_full, &_mutex);
		}
		_q.push(data);
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_empty); //唤醒在empty条件变量下等待的消费者线程
	}
	//从阻塞队列获取数据（消费者调用）
	void Pop(T& data)
	{
		pthread_mutex_lock(&_mutex);
		while (IsEmpty()){
			//不能进行消费，直到阻塞队列有新的数据
			pthread_cond_wait(&_empty, &_mutex);
		}
		data = _q.front();
		_q.pop();
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_full); //唤醒在full条件变量下等待的生产者线程
	}
private:
	std::queue<T> _q; //阻塞队列
	int _cap; //阻塞队列最大容器数据个数
	pthread_mutex_t _mutex;
	pthread_cond_t _full;
	pthread_cond_t _empty;
};
```

**相关说明：**

+   由于我们实现的是单生产者、单消费者的生产者消费者模型，因此我们不需要维护生产者和生产者之间的关系，也不需要维护消费者和消费者之间的关系，我们只需要维护生产者和消费者之间的同步与互斥关系即可。
+   将BlockingQueue当中存储的数据模板化，方便以后需要时进行复用。
+   这里设置BlockingQueue存储数据的上限为5，当阻塞队列中存储了五组数据时生产者就不能进行生产了，此时生产者就应该被阻塞。
+   阻塞队列是会被生产者和消费者同时访问的临界资源，因此我们需要用一把互斥锁将其保护起来。
+   生产者线程要向阻塞队列当中Push数据，前提是阻塞队列里面有空间，若阻塞队列已经满了，那么此时该生产者线程就需要进行等待，直到阻塞队列中有空间时再将其唤醒。
+   消费者线程要从阻塞队列当中Pop数据，前提是阻塞队列里面有数据，若阻塞队列为空，那么此时该消费者线程就需要进行等待，直到阻塞队列中有新的数据时再将其唤醒。
+   因此在这里我们需要用到两个条件变量，一个条件变量用来描述队列为空，另一个条件变量用来描述队列已满。当阻塞队列满了的时候，要进行生产的生产者线程就应该在full条件变量下进行等待；当阻塞队列为空的时候，要进行消费的消费者线程就应该在empty条件变量下进行等待。
+   不论是生产者线程还是消费者线程，它们都是先申请到锁进入临界区后再判断是否满足生产或消费条件的，如果对应条件不满足，那么对应线程就会被挂起。但此时该线程是拿着锁的，为了避免死锁问题，在调用`pthread_cond_wait`函数时就需要传入当前线程手中的互斥锁，此时当该线程被挂起时就会自动释放手中的互斥锁，而当该线程被唤醒时又会自动获取到该互斥锁。
+   当生产者生产完一个数据后，意味着阻塞队列当中至少有一个数据，而此时可能有消费者线程正在empty条件变量下进行等待，因此当生产者生产完数据后需要唤醒在empty条件变量下等待的消费者线程。
+   同样的，当消费者消费完一个数据后，意味着阻塞队列当中至少有一个空间，而此时可能有生产者线程正在full条件变量下进行等待，因此当消费者消费完数据后需要唤醒在full条件变量下等待的生产者线程。

**判断是否满足生产消费条件时不能用if，而应该用while**：

+   `pthread_cond_wait`函数是让当前执行流进行等待的函数，是函数就意味着有可能调用失败，调用失败后该执行流就会继续往后执行。
+   其次，在多消费者的情况下，当生产者生产了一个数据后如果使用`pthread_cond_broadcast`函数唤醒消费者，就会一次性唤醒多个消费者，但待消费的数据只有一个，此时其他消费者就被伪唤醒了。
+   为了避免出现上述情况，我们就要让线程被唤醒后再次进行判断，确认是否真的满足生产消费条件，因此这里必须要用while进行判断。

在主函数中我们就只需要创建一个生产者线程和一个消费者线程，让生产者线程不断生产数据，让消费者线程不断消费数据。

```cpp
#include "BlockQueue.hpp"

void* Producer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//生产者不断进行生产
	while (true){
		sleep(1);
		int data = rand() % 100 + 1;
		bq->Push(data); //生产数据
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//消费者不断进行消费
	while (true){
		sleep(1);
		int data = 0;
		bq->Pop(data); //消费数据
		std::cout << "Consumer: " << data << std::endl;
	}
}
int main()
{
	srand((unsigned int)time(nullptr));
	pthread_t producer, consumer;
	BlockQueue<int>* bq = new BlockQueue<int>;
	//创建生产者线程和消费者线程
	pthread_create(&producer, nullptr, Producer, bq);
	pthread_create(&consumer, nullptr, Consumer, bq);

	//join生产者线程和消费者线程
	pthread_join(producer, nullptr);
	pthread_join(consumer, nullptr);
	delete bq
	return 0;
}
```

**相关说明：**

+   阻塞队列要让生产者线程向队列中Push数据，让消费者线程从队列中Pop数据，因此这个阻塞队列必须要让这两个线程同时看到，所以我们在创建生产者线程和消费者线程时，需要将该阻塞队列作为线程执行例程的参数进行传入。
+   代码中生产者生产数据就是将获取到的随机数Push到阻塞队列，而消费者消费数据就是从阻塞队列Pop数据，为了便于观察，我们可以将生产者生产的数据和消费者消费的数据进行打印输出。

#### 其他

> 生产者消费者步调一致

由于代码中生产者是每隔一秒生产一个数据，而消费者是每隔一秒消费一个数据，因此运行代码后我们可以看到生产者和消费者的执行步调是一致的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242212.png)  

**小贴士：** 以`.hpp`为后缀的文件也是头文件，该头文件同时包含类的定义与实现，调用者只需include该hpp文件即可。因为开源项目一般不需要进行保护，所以在开源项目中用的比较多。

> 生产者生产的快，消费者消费的慢

我们可以让生产者不停的进行生产，而消费者每隔一秒进行消费。

```cpp
void* Producer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//生产者不断进行生产
	while (true){
		int data = rand() % 100 + 1;
		bq->Push(data); //生产数据
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//消费者不断进行消费
	while (true){
		sleep(1);
		int data = 0;
		bq->Pop(data); //消费数据
		std::cout << "Consumer: " << data << std::endl;
	}
}
```

此时由于生产者生产的很快，运行代码后一瞬间生产者就将阻塞队列打满了，此时生产者想要再进行生产就只能在full条件变量下进行等待，直到消费者消费完一个数据后，生产者才会被唤醒进而继续进行生产，生产者生产完一个数据后又会进行等待，因此后续生产者和消费者的步调又变成一致的了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242213.png)

> 生产者生产的慢，消费者消费的快

当然，我们也可以让生产者每隔一秒进行生产，而消费者不停的进行消费。

```cpp
void* Producer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//生产者不断进行生产
	while (true){
		sleep(1);
		int data = rand() % 100 + 1;
		bq->Push(data); //生产数据
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	BlockQueue<int>* bq = (BlockQueue<int>*)arg;
	//消费者不断进行消费
	while (true){
		int data = 0;
		bq->Pop(data); //消费数据
		std::cout << "Consumer: " << data << std::endl;
	}
}
```

虽然消费者消费的很快，但一开始阻塞队列中是没有数据的，因此消费者只能在empty条件变量下进行等待，直到生产者生产完一个数据后，消费者才会被唤醒进而进行消费，消费者消费完这一个数据后又会进行等待，因此生产者和消费者的步调就是一致的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242214.png)

> 满足某一条件时再唤醒对应的生产者或消费者

我们也可以当阻塞队列当中存储的数据大于队列容量的一半时，再唤醒消费者线程进行消费；当阻塞队列当中存储的数据小于队列容器的一半时，再唤醒生产者线程进行生产。

```cpp
//向阻塞队列插入数据（生产者调用）
void Push(const T& data)
{
	pthread_mutex_lock(&_mutex);
	while (IsFull()){
		//不能进行生产，直到阻塞队列可以容纳新的数据
		pthread_cond_wait(&_full, &_mutex);
	}
	_q.push(data);
	if (_q.size() >= _cap / 2){
		pthread_cond_signal(&_empty); //唤醒在empty条件变量下等待的消费者线程
	}
	pthread_mutex_unlock(&_mutex);
}
//从阻塞队列获取数据（消费者调用）
void Pop(T& data)
{
	pthread_mutex_lock(&_mutex);
	while (IsEmpty()){
		//不能进行消费，直到阻塞队列有新的数据
		pthread_cond_wait(&_empty, &_mutex);
	}
	data = _q.front();
	_q.pop();
	if (_q.size() <= _cap / 2){
		pthread_cond_signal(&_full); //唤醒在full条件变量下等待的生产者线程
	}
	pthread_mutex_unlock(&_mutex);
}
```

我们仍然让生产者生产的快，消费者消费的慢。运行代码后生产者还是一瞬间将阻塞队列打满后进行等待，但此时不是消费者消费一个数据就唤醒生产者线程，而是当阻塞队列当中的数据小于队列容器的一半时，才会唤醒生产者线程进行生产。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242215.png)

> 基于计算任务的生产者消费者模型

当然，实际使用生产者消费者模型时可不是简单的让生产者生产一个数字让消费者进行打印而已，我们这样做只是为了测试代码的正确性。  

由于我们将BlockingQueue当中存储的数据进行了模板化，此时就可以让BlockingQueue当中存储其他类型的数据。

例如，我们想要实现一个基于计算任务的生产者消费者模型，此时我们只需要定义一个Task类，这个类当中需要包含一个Run成员函数，该函数代表着我们想让消费者如何处理拿到的数据。

```cpp
#pragma once
#include <iostream>

class Task
{
public:
	Task(int x = 0, int y = 0, int op = 0)
		: _x(x), _y(y), _op(op)
	{}
	~Task()
	{}
	void Run()
	{
		int result = 0;
		switch (_op)
		{
		case '+':
			result = _x + _y;
			break;
		case '-':
			result = _x - _y;
			break;
		case '*':
			result = _x * _y;
			break;
		case '/':
			if (_y == 0){
				std::cout << "Warning: div zero!" << std::endl;
				result = -1;
			}
			else{
				result = _x / _y;
			}
			break;
		case '%':
			if (_y == 0){
				std::cout << "Warning: mod zero!" << std::endl;
				result = -1;
			}
			else{
				result = _x % _y;
			}
			break;
		default:
			std::cout << "error operation!" << std::endl;
			break;
		}
		std::cout << _x << _op << _y << "=" << result << std::endl;
	}
private:
	int _x;
	int _y;
	char _op;
};
```

此时生产者放入阻塞队列的数据就是一个Task对象，而消费者从阻塞队列拿到Task对象后，就可以用该对象调用Run成员函数进行数据处理。

```cpp
void* Producer(void* arg)
{
	BlockQueue<Task>* bq = (BlockQueue<Task>*)arg;
	const char* arr = "+-*/%";
	//生产者不断进行生产
	while (true){
		int x = rand() % 100;
		int y = rand() % 100;
		char op = arr[rand() % 5];
		Task t(x, y, op);
		bq->Push(t); //生产数据
		std::cout << "producer task done" << std::endl;
	}
}
void* Consumer(void* arg)
{
	BlockQueue<Task>* bq = (BlockQueue<Task>*)arg;
	//消费者不断进行消费
	while (true){
		sleep(1);
		Task t;
		bq->Pop(t); //消费数据
		t.Run(); //处理数据
	}
}
```

运行代码，当阻塞队列被生产者打满后消费者被唤醒，此时消费者在消费数据时执行的就是计算任务，当阻塞队列当中的数据被消费到低于一定阈值后又会唤醒生产者进行生产。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698127242216.png)  
也就是说，此后我们想让生产者消费者模型处理某一种任务时，就只需要提供对应的Task类，然后让该Task类提供一个对应的Run成员函数告诉我们应该如何处理这个任务即可。



## POSIX信号量

### 信号量的原理

+   我们将可能会被多个执行流同时访问的资源叫做临界资源，临界资源需要进行保护否则会出现数据不一致等问题。
+   **当我们仅用一个互斥锁对临界资源进行保护时，相当于我们将这块临界资源看作一个整体，同一时刻只允许一个执行流对这块临界资源进行访问。**
+   但实际我们**可以将这块临界资源再分割为多个区域**，当多个执行流需要访问临界资源时，如果这些执行流访问的是临界资源的不同区域，那么我们可以让这些执行流同时访问临界资源的不同区域，此时不会出现数据不一致等问题。

### 信号量的概念

> **信号量（信号灯）本质是一个计数器，是描述临界资源中资源数目的计数器，信号量能够更细粒度的对临界资源进行管理。**

每个执行流在进入临界区之前都应该先申请信号量，申请成功就有了操作特定的临界资源的权限，当操作完毕后就应该释放信号量。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457233.png)  

信号量的PV操作：

+   P操作：我们将申请信号量称为P操作，申请信号量的本质就是申请获得临界资源中某块资源的使用权限，当申请成功时临界资源中资源的数目应该减一，因此P操作的本质就是让计数器减一。
+   V操作：我们将释放信号量称为V操作，释放信号量的本质就是归还临界资源中某块资源的使用权限，当释放成功时临界资源中资源的数目就应该加一，因此V操作的本质就是让计数器加一。

> PV操作必须是原子操作

多个执行流为了访问临界资源会竞争式的申请信号量，因此信号量是会被多个执行流同时访问的，也就是说信号量本质也是临界资源。

但信号量本质就是用于保护临界资源的，我们不可能再用信号量去保护信号量，所以信号量的PV操作必须是原子操作。

**注意：** 内存当中变量的`++`、`--`操作并不是原子操作，因此信号量不可能只是简单的对一个全局变量进行`++`、`--`操作。

如何实现PV原子性：[linux - 信号量的pv操作是怎么保证原子性的？](https://segmentfault.com/q/1010000021303210)

> 申请信号量失败被挂起等待

当执行流在申请信号量时，可能此时信号量的值为0，也就是说信号量描述的临界资源已经全部被申请了，此时该执行流就应该在该信号量的等待队列当中进行等待，直到有信号量被释放时再被唤醒。

**注意：** 信号量的本质是计数器，但不意味着只有计数器，信号量还包括一个等待队列。

### 信号量函数

#### 初始化信号量

初始化信号量的函数叫**做sem\_init**，该函数的函数原型如下：

```cpp
int sem_init(sem_t *sem, int pshared, unsigned int value);
```

参数说明：

+   sem：需要初始化的信号量。
+   pshared：传入0值表示线程间共享，传入非零值表示进程间共享。
+   value：信号量的初始值（计数器的初始值）。

返回值说明：

+   初始化信号量成功返回0，失败返回-1。

**注意：** POSIX信号量和System V信号量作用相同，都是用于同步操作，达到无冲突的访问共享资源目的，但POSIX信号量可以用于线程间同步。

##### 销毁信号量

销毁信号量的函数叫做sem\_destroy，该函数的函数原型如下：

```cpp
int sem_destroy(sem_t *sem);
```

参数说明：

+   sem：需要销毁的信号量。

返回值说明：

+   销毁信号量成功返回0，失败返回-1。

##### 等待信号量（申请信号量）

等待信号量的函数叫做sem\_wait，该函数的函数原型如下：

```cpp
int sem_wait(sem_t *sem);
```

参数说明：

+   sem：需要等待的信号量。

返回值说明：

+   等待信号量成功返回0，信号量的值减一。
+   等待信号量失败返回-1，信号量的值保持不变。

##### 发布信号量（释放信号量）

发布信号量的函数叫做sem\_post，该函数的函数原型如下：

```cpp
int sem_post(sem_t *sem);
```

参数说明：

+   sem：需要发布的信号量。

返回值说明：

+   发布信号量成功返回0，信号量的值加一。
+   发布信号量失败返回-1，信号量的值保持不变。

### 二元信号量模拟实现互斥功能

> 信号量本质是一个计数器，如果将信号量的初始值设置为1，那么此时该信号量叫做二元信号量。

信号量的初始值为1，说明信号量所描述的临界资源只有一份，此时信号量的作用基本等价于互斥锁。

例如，下面我们实现一个多线程抢票系统，其中我们用二元信号量模拟实现多线程互斥。

我们在主线程当中创建四个新线程，让这四个新线程执行抢票逻辑，并且每次抢完票后打印输出此时剩余的票数，其中我们用全局变量tickets记录当前剩余的票数，此时tickets是会被多个执行流同时访问的临界资源，在下面的代码中我们并没有对tickets进行任何保护操作。

```cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>

int tickets = 2000;
void* TicketGrabbing(void* arg)
{
	std::string name = (char*)arg;
	while (true){
		if (tickets > 0){
			usleep(1000);
			std::cout << name << " get a ticket, tickets left: " << --tickets << std::endl;
		}
		else{
			break;
		}
	}
	std::cout << name << " quit..." << std::endl;
	pthread_exit((void*)0);
}

int main()
{
	pthread_t tid1, tid2, tid3, tid4;
	pthread_create(&tid1, nullptr, TicketGrabbing, (void*)"thread 1");
	pthread_create(&tid2, nullptr, TicketGrabbing, (void*)"thread 2");
	pthread_create(&tid3, nullptr, TicketGrabbing, (void*)"thread 3");
	pthread_create(&tid4, nullptr, TicketGrabbing, (void*)"thread 4");
	
	pthread_join(tid1, nullptr);
	pthread_join(tid2, nullptr);
	pthread_join(tid3, nullptr);
	pthread_join(tid4, nullptr);
	return 0;
}
```

运行代码后可以看到，线程打印输出剩余票数时出现了票数剩余为负数的情况，这是不符合我们预期的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457234.png)  

下面我们在抢票逻辑当中加入二元信号量，让每个线程在访问全局变量tickets之前先申请信号量，访问完毕后再释放信号量，此时二元信号量就达到了互斥的效果。

```cpp
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

class Sem
{
public:
    Sem()
    {
    }
    Sem(int num)
    {
        sem_init(&_sem, 0, num);
    }
    ~Sem()
    {
        sem_destroy(&_sem);
    }

    void P()
    {
        sem_wait(&_sem);
    }
    void V()
    {
        sem_post(&_sem);
    }

private:
    sem_t _sem;
};

Sem sem(1);//二元信号量，等价于互斥锁
int tickets = 2000;

void *TicketGrabbing(void *arg)
{
    std::string name = (char *)arg;

    while (true)
    {
        sem.P();
        if (tickets > 0)
        {
            usleep(100);
            std::cout << name << "get a ticket, tickets left: " << --tickets << std::endl;
            sem.V();
        }
        else
        {
            sem.V();
            break;
        }
    }
    //现象， 某个线程一直能抢到票
    //二元信号量相当于互斥锁，且没有同步操作，
    //所以很大概率上，一个线程在执行完V操作时，仍在它的时间片，就仍能申请到信号量

    std::cout << name << "quit..." << std::endl;
    return (void *)0;
}

int main()
{
    pthread_t t1, t2, t3, t4;
    pthread_create(&t1, NULL, TicketGrabbing, (void *)"thread 1");
    pthread_create(&t2, NULL, TicketGrabbing, (void *)"thread 2");
    pthread_create(&t3, NULL, TicketGrabbing, (void *)"thread 3");
    pthread_create(&t4, NULL, TicketGrabbing, (void *)"thread 4");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}
```

运行代码后就不会出现剩余票数为负的情况了，因为此时同一时刻只会有一个执行流对全局变量tickets进行访问，不会出现数据不一致的问题。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457235.png)

### 基于环形队列的生产消费模型

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457236.png)

#### 空间资源和数据资源

> 生产者关注的是空间资源，消费者关注的是数据资源

对于生产者和消费者来说，它们关注的资源是不同的：

+   生产者关注的是环形队列当中是否有空间（blank），只要有空间生产者就可以进行生产。
+   消费者关注的是环形队列当中是否有数据（data），只要有数据消费者就可以进行消费。

> blank\_sem和data\_sem的初始值设置

现在我们用信号量来描述环形队列当中的空间资源（blank\_sem）和数据资源（data\_sem），在我们初始信号量时给它们设置的初始值是不同的：

+   blank\_sem的初始值我们应该设置为环形队列的容量，因为刚开始时环形队列当中全是空间。
+   data\_sem的初始值我们应该设置为0，因为刚开始时环形队列当中没有数据。

#### 生产者和消费者申请和释放资源

> 生产者申请空间资源，释放数据资源

对于生产者来说，生产者每次生产数据前都需要先申请blank\_sem：

+   如果blank\_sem的值不为0，则信号量申请成功，此时生产者可以进行生产操作。
+   如果blank\_sem的值为0，则信号量申请失败，此时生产者需要在blank\_sem的等待队列下进行阻塞等待，直到环形队列当中有新的空间后再被唤醒。

当生产者生产完数据后，应该释放data\_sem：

+   虽然生产者在进行生产前是对blank\_sem进行的P操作，但是当生产者生产完数据，应该对data\_sem进行V操作而不是blank\_sem。
+   生产者在生产数据前申请到的是`blank位置`，当生产者生产完数据后，该位置当中存储的是生产者生产的数据，在该数据被消费者消费之前，该位置不再是`blank位置`，而应该是`data位置`。
+   当生产者生产完数据后，意味着环形队列当中多了一个`data位置`，因此我们应该对data\_sem进行V操作。

> 消费者申请数据资源，释放空间资源

对于消费者来说，消费者每次消费数据前都需要先申请data\_sem：

+   如果data\_sem的值不为0，则信号量申请成功，此时消费者可以进行消费操作。
+   如果data\_sem的值为0，则信号量申请失败，此时消费者需要在data\_sem的等待队列下进行阻塞等待，直到环形队列当中有新的数据后再被唤醒。

当消费者消费完数据后，应该释放blank\_sem：

+   虽然消费者在进行消费前是对data\_sem进行的P操作，但是当消费者消费完数据，应该对blank\_sem进行V操作而不是data\_sem。
+   消费者在消费数据前申请到的是`data位置`，当消费者消费完数据后，该位置当中的数据已经被消费过了，再次被消费就没有意义了，为了让生产者后续可以在该位置生产新的数据，我们应该将该位置算作`blank位置`，而不是`data位置`。
+   当消费者消费完数据后，意味着环形队列当中多了一个`blank位置`，因此我们应该对blank\_sem进行V操作。

#### 必须遵守的两个规则

在基于环形队列的生产者和消费者模型当中，生产者和消费者必须遵守如下两个规则。

> **第一个规则：生产者和消费者不能对同一个位置进行访问。**

生产者和消费者在访问环形队列时：

+   如果生产者和消费者访问的是环形队列当中的同一个位置，那么此时生产者和消费者就相当于同时对这一块临界资源进行了访问，这当然是不允许的。
+   而如果生产者和消费者访问的是环形队列当中的不同位置，那么此时生产者和消费者是可以同时进行生产和消费的，此时不会出现数据不一致等问题。

如下图：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457237.png)

> **第二个规则：无论是生产者还是消费者，都不应该将对方套一个圈以上。**

+   生产者从消费者的位置开始一直按顺时针方向进行生产，如果生产者生产的速度比消费者消费的速度快，那么当生产者绕着消费者生产了一圈数据后再次遇到消费者，此时生产者就不应该再继续生产了，因为再生产就会覆盖还未被消费者消费的数据。
+   同理，消费者从生产者的位置开始一直按顺时针方向进行消费，如果消费者消费的速度比生产者生产的速度快，那么当消费者绕着生产者消费了一圈数据后再次遇到生产者，此时消费者就不应该再继续消费了，因为再消费就会消费到缓冲区中保存的废弃数据。

如下图：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672457238.png)

#### 代码实现

其中的RingQueue就是生产者消费者模型当中的交易场所，我们可以用C++STL库当中的vector进行实现。

```cpp
#pragma once

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <vector>

#define NUM 8

template<class T>
class RingQueue
{
private:
	//P操作
	void P(sem_t& s)
	{
		sem_wait(&s);
	}
	//V操作
	void V(sem_t& s)
	{
	    sem_post(&s);
	}
public:
	RingQueue(int cap = NUM)
		: _cap(cap), _p_pos(0), _c_pos(0)
	{
		_q.resize(_cap);
		sem_init(&_blank_sem, 0, _cap); //blank_sem初始值设置为环形队列的容量
		sem_init(&_data_sem, 0, 0); //data_sem初始值设置为0
	}
	~RingQueue()
	{
	sem_destroy(&_blank_sem);
	sem_destroy(&_data_sem);
	}
	//向环形队列插入数据（生产者调用）
	void Push(const T& data)
	{
		P(_blank_sem); //生产者关注空间资源
		_q[_p_pos] = data;
		V(_data_sem); //生产

		//更新下一次生产的位置
		_p_pos++;
		_p_pos %= _cap;
	}
	//从环形队列获取数据（消费者调用）
	void Pop(T& data)
	{
		P(_data_sem); //消费者关注数据资源
		data = _q[_c_pos];
		V(_blank_sem);

		//更新下一次消费的位置
		_c_pos++;
		_c_pos %= _cap;
	}
private:
	std::vector<T> _q; //环形队列
	int _cap; //环形队列的容量上限
	int _p_pos; //生产位置
	int _c_pos; //消费位置
	sem_t _blank_sem; //描述空间资源
	sem_t _data_sem; //描述数据资源
};
```

**相关说明：**

+   当不设置环形队列的大小时，我们默认将环形队列的容量上限设置为8。
+   代码中的RingQueue是用vector实现的，生产者每次生产的数据放到vector下标为p\_pos的位置，消费者每次消费的数据来源于vector下标为c\_pos的位置。
+   生产者每次生产数据后p\_pos都会进行++，标记下一次生产数据的存放位置，++后的下标会与环形队列的容量进行取模运算，实现“环形”的效果。
+   消费者每次消费数据后c\_pos都会进行++，标记下一次消费数据的来源位置，++后的下标会与环形队列的容量进行取模运算，实现“环形”的效果。
+   p\_pos只会由生产者线程进行更新，c\_pos只会由消费者线程进行更新，对这两个变量访问时不需要进行保护，因此代码中将p\_pos和c\_pos的更新放到了V操作之后，就是为了尽量减少临界区的代码。

为了方便理解，我们这里实现单生产者、单消费者的生产者消费者模型。于是在主函数我们就只需要创建一个生产者线程和一个消费者线程，生产者线程不断生产数据放入环形队列，消费者线程不断从环形队列里取出数据进行消费。

```cpp
#include "RingQueue.hpp"

void* Producer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		sleep(1);
		int data = rand() % 100 + 1;
		rq->Push(data);
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		sleep(1);
		int data = 0;
		rq->Pop(data);
		std::cout << "Consumer: " << data << std::endl;
	}
}
int main()
{
	srand((unsigned int)time(nullptr));
	pthread_t producer, consumer;
	RingQueue<int>* rq = new RingQueue<int>;
	pthread_create(&producer, nullptr, Producer, rq);
	pthread_create(&consumer, nullptr, Consumer, rq);
	
	pthread_join(producer, nullptr);
	pthread_join(consumer, nullptr);
	delete rq;
	return 0;
}
```

**相关说明：**

+   环形队列要让生产者线程向队列中Push数据，让消费者线程从队列中Pop数据，因此这个环形队列必须要让这两个线程同时看到，所以我们在创建生产者线程和消费者线程时，需要将环形队列作为线程执行例程的参数进行传入。
+   代码中生产者生产数据就是将获取到的随机数Push到环形队列，而消费者就是从环形队列Pop数据，为了便于观察，我们可以将生产者生产的数据和消费者消费的数据进行打印输出。

#### 其他

> 生产者消费者步调一致

由于代码中生产者是每隔一秒生产一个数据，而消费者是每隔一秒消费一个数据，因此运行代码后我们可以看到生产者和消费者的执行步调是一致的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672458239.png)

> 生产者生产的快，消费者消费的慢

我们可以让生产者不停的进行生产，而消费者每隔一秒进行消费。

```cpp
void* Producer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		int data = rand() % 100 + 1;
		rq->Push(data);
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		sleep(1);
		int data = 0;
		rq->Pop(data);
		std::cout << "Consumer: " << data << std::endl;
	}
}
```

此时由于生产者生产的很快，运行代码后一瞬间生产者就将环形队列打满了，此时生产者想要再进行生产，但空间资源已经为0了，于是生产者只能在blank\_sem的等待队列下进行阻塞等待，直到由消费者消费完一个数据后对blank\_sem进行了V操作，生产者才会被唤醒进而继续进行生产。

但由于生产者的生产速度很快，生产者生产完一个数据后又会进行等待，因此后续生产者和消费者的步调又变成一致的了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672458240.png)

> 生产者生产的慢，消费者消费的快

当然我们也可以让生产者每隔一秒进行生产，而消费者不停的进行消费。

```cpp
void* Producer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		sleep(1);
		int data = rand() % 100 + 1;
		rq->Push(data);
		std::cout << "Producer: " << data << std::endl;
	}
}
void* Consumer(void* arg)
{
	RingQueue<int>* rq = (RingQueue<int>*)arg;
	while (true){
		int data = 0;
		rq->Pop(data);
		std::cout << "Consumer: " << data << std::endl;
	}
}
```

虽然消费者消费的很快，但一开始环形队列当中的数据资源为0，因此消费者只能在data\_sem的等待队列下进行阻塞等待，直到生产者生产完一个数据后对data\_sem进行了V操作，消费者才会被唤醒进而进行消费。

但由于消费者的消费速度很快，消费者消费完一个数据后又会进行等待，因此后续生产者和消费者的步调又变成一致的了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698672458241.png)

#### 信号量保护环形队列的原理

> 在blank\_sem和data\_sem两个信号量的保护后，该环形队列中不可能会出现数据不一致的问题。

因为只有当生产者和消费者指向同一个位置并访问时，才会导致数据不一致的问题，而此时生产者和消费者在对环形队列进行写入或读取数据时，只有两种情况会指向同一个位置：

+   环形队列为空时。
+   环形队列为满时。

但是在这两种情况下，生产者和消费者不会同时对环形队列进行访问：

+   当环形队列为空的时，消费者一定不能进行消费，因为此时数据资源为0。
+   当环形队列为满的时，生产者一定不能进行生产，因为此时空间资源为0。

也就是说，当环形队列为空和满时，我们已经通过信号量保证了生产者和消费者的串行化过程。而除了这两种情况之外，生产者和消费者指向的都不是同一个位置，因此该环形队列当中不可能会出现数据不一致的问题。并且大部分情况下生产者和消费者指向并不是同一个位置，因此大部分情况下该环形队列可以让生产者和消费者并发的执行

![线程同步+互斥+信号量](%E5%9B%BE%E7%89%87/Linux/%E7%BA%BF%E7%A8%8B%E5%90%8C%E6%AD%A5+%E4%BA%92%E6%96%A5+%E4%BF%A1%E5%8F%B7%E9%87%8F.png)



## Linux线程池

### 线程池的概念

> 线程池是一种线程使用模式。

线程过多会带来调度开销，进而影响缓存局部和整体性能，而线程池维护着多个线程，等待着监督管理者分配可并发执行的任务。

### 线程池的优点

+   线程池避免了在处理短时间任务时创建与销毁线程的代价。
+   线程池不仅能够保证内核充分利用，还能防止过分调度。

**注意：** 线程池中可用线程的数量应该取决于可用的并发处理器、处理器内核、内存、网络sockets等的数量。

### 线程池的应用场景

线程池常见的应用场景如下：

1.  需要大量的线程来完成任务，且完成任务的时间比较短。
2.  对性能要求苛刻的应用，比如要求服务器迅速响应客户请求。
3.  接受突发性的大量请求，但不至于使服务器因此产生大量线程的应用。

相关解释：

+   像Web服务器完成网页请求这样的任务，使用线程池技术是非常合适的。因为**单个任务小，而任务数量巨大**，你可以想象一个热门网站的点击次数。
+   **对于长时间的任务，比如Telnet连接请求，线程池的优点就不明显了**。因为Telnet会话时间比线程的创建时间大多了。
+   **突发性大量客户请求**，在没有线程池的情况下，将产生大量线程，虽然理论上大部分操作系统线程数目最大值不是问题，但短时间内产生大量线程可能使内存到达极限，出现错误。

### 线程池的实现

[**ThreadPool**]([LINUX/ThreadPool at main · tianen1573/LINUX (github.com)](https://github.com/tianen1573/LINUX/tree/main/ThreadPool))

下面我们实现一个简单的线程池，线程池中提供了一个任务队列，以及若干个线程（多线程）。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698853283260.png)

+   线程池中的多个线程负责从任务队列当中拿任务，并将拿到的任务进行处理。
+   线程池对外提供一个Push接口，用于让外部线程能够将任务Push到任务队列当中。

线程池的代码如下：

```cpp
#pragma once

#include <iostream>
#include <unistd.h>
#include <queue>
#include <pthread.h>

#define NUM 5

//线程池
template<class T>
class ThreadPool
{
private:
	bool IsEmpty()
	{
		return _task_queue.size() == 0;
	}
	void LockQueue()
	{
		pthread_mutex_lock(&_mutex);
	}
	void UnLockQueue()
	{
		pthread_mutex_unlock(&_mutex);
	}
	void Wait()
	{
		pthread_cond_wait(&_cond, &_mutex);
	}
	void WakeUp()
	{
		pthread_cond_signal(&_cond);
	}
public:
	ThreadPool(int num = NUM)
		: _thread_num(num)
	{
		pthread_mutex_init(&_mutex, nullptr);
		pthread_cond_init(&_cond, nullptr);
	}
	~ThreadPool()
	{
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond);
	}
	//线程池中线程的执行例程
	static void* Routine(void* arg)
	{
		pthread_detach(pthread_self());
		ThreadPool* self = (ThreadPool*)arg;
		//不断从任务队列获取任务进行处理
		while (true){
			self->LockQueue();
			while (self->IsEmpty()){
				self->Wait();
			}
			T task;
			self->Pop(task);
			self->UnLockQueue();
			
			task.Run(); //处理任务
		}
	}
	void ThreadPoolInit()
	{
		pthread_t tid;
		for (int i = 0; i < _thread_num; i++){
			pthread_create(&tid, nullptr, Routine, this); //注意参数传入this指针
		}
	}
	//往任务队列塞任务（主线程调用）
	void Push(const T& task)
	{
		LockQueue();
		_task_queue.push(task);
		UnLockQueue();
		WakeUp();
	}
	//从任务队列获取任务（线程池中的线程调用）
	void Pop(T& task)
	{
		task = _task_queue.front();
		_task_queue.pop();
	}
private:
	std::queue<T> _task_queue; //任务队列
	int _thread_num; //线程池中线程的数量
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
};
```

> 为什么线程池中需要有互斥锁和条件变量？

线程池中的任务队列是会被多个执行流同时访问的临界资源，因此我们需要引入互斥锁对任务队列进行保护。

线程池当中的线程要从任务队列里拿任务，前提条件是任务队列中必须要有任务，因此线程池当中的线程在拿任务之前，需要先判断任务队列当中是否有任务，若此时任务队列为空，那么该线程应该进行等待，直到任务队列中有任务时再将其唤醒，因此我们需要引入条件变量。

当外部线程向任务队列中Push一个任务后，此时可能有线程正处于等待状态，因此在新增任务后需要唤醒在条件变量下等待的线程。

**注意：**

+   当某线程被唤醒时，其可能是被异常或是伪唤醒，或者是一些广播类的唤醒线程操作而导致所有线程被唤醒，使得在被唤醒的若干线程中，只有个别线程能拿到任务。此时应该让被唤醒的线程再次判断是否满足被唤醒条件，所以在判断任务队列是否为空时，应该使用while进行判断，而不是if。
+   `pthread_cond_broadcast`函数的作用是唤醒条件变量下的所有线程，而外部可能只Push了一个任务，我们却把全部在等待的线程都唤醒了，此时这些线程就都会去任务队列获取任务，但最终只有一个线程能得到任务。一瞬间唤醒大量的线程可能会导致系统震荡，这叫做惊群效应。因此在唤醒线程时最好使用`pthread_cond_signal`函数唤醒正在等待的一个线程即可。
+   当线程从任务队列中拿到任务后，该任务就已经属于当前线程了，与其他线程已经没有关系了，因此应该在解锁之后再进行处理任务，而不是在解锁之前进行。因为处理任务的过程可能会耗费一定的时间，所以我们不要将其放到临界区当中。
+   如果将处理任务的过程放到临界区当中，那么当某一线程从任务队列拿到任务后，其他线程还需要等待该线程将任务处理完后，才有机会进入临界区。此时虽然是线程池，但最终我们可能并没有让多线程并行的执行起来。

> 为什么线程池中的线程执行例程需要设置为静态方法？

使用pthread\_create函数创建线程时，需要为创建的线程传入一个Routine（执行例程），该Routine只有一个参数类型为`void*`的参数，以及返回类型为`void*`的返回值。

而此时Routine作为类的成员函数，该函数的第一个参数是隐藏的this指针，因此这里的Routine函数，虽然看起来只有一个参数，而实际上它有两个参数，此时直接将该Routine函数作为创建线程时的执行例程是不行的，无法通过编译。

静态成员函数属于类，而不属于某个对象，也就是说静态成员函数是没有隐藏的this指针的，因此我们需要将Routine设置为静态方法，此时Routine函数才真正只有一个参数类型为`void*`的参数。

但是在静态成员函数内部无法调用非静态成员函数，而我们需要在Routine函数当中调用该类的某些非静态成员函数，比如Pop。因此我们需要在创建线程时，向Routine函数传入的当前对象的this指针，此时我们就能够通过该this指针在Routine函数内部调用非静态成员函数了。

> 任务类型的设计

我们将线程池进行了模板化，因此线程池当中存储的任务类型可以是任意的，但无论该任务是什么类型的，在该任务类当中都必须包含一个Run方法，当我们处理该类型的任务时只需调用该Run方法即可。

例如，下面我们实现一个计算任务类：

```cpp
#pragma once

#include <iostream>

//任务类
class Task
{
public:
	Task(int x = 0, int y = 0, char op = 0)
		: _x(x), _y(y), _op(op)
	{}
	~Task()
	{}

	//处理任务的方法
	void Run()
	{
		int result = 0;
		switch (_op)
		{
		case '+':
			result = _x + _y;
			break;
		case '-':
			result = _x - _y;
			break;
		case '*':
			result = _x * _y;
			break;
		case '/':
			if (_y == 0){
				std::cerr << "Error: div zero!" << std::endl;
				return;
			}
			else{
				result = _x / _y;
			}
			break;
		case '%':
			if (_y == 0){
				std::cerr << "Error: mod zero!" << std::endl;
				return;
			}
			else{
				result = _x % _y;
			}
			break;
		default:
			std::cerr << "operation error!" << std::endl;
			return;
		}
		std::cout << "thread[" << pthread_self() << "]:" << _x << _op << _y << "=" << result << std::endl;
	}
private:
	int _x;
	int _y;
	char _op;
};
```

此时线程池内的线程不断从任务队列拿出任务进行处理，而它们并不需要关心这些任务是哪来的，它们只需要拿到任务后执行对应的Run方法即可。

> 主线程逻辑

主线程就负责不断向任务队列当中Push任务就行了，此后线程池当中的线程会从任务队列当中获取到这些任务并进行处理。

```cpp
#include "Task.hpp"
#include "ThreadPool.hpp"

int main()
{
	srand((unsigned int)time(nullptr));
	ThreadPool<Task>* tp = new ThreadPool<Task>; //线程池
	tp->ThreadPoolInit(); //初始化线程池当中的线程
	const char* op = "+-*/%";
	//不断往任务队列塞计算任务
	while (true){
		sleep(1);
		int x = rand() % 100;
		int y = rand() % 100;
		int index = rand() % 5;
		Task task(x, y, op[index]);
		tp->Push(task);
	}
	return 0;
}
```

运行代码后一瞬间就有六个线程，其中一个是主线程，另外五个是线程池内处理任务的线程。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16.png)

并且我们会发现这五个线程在处理时会呈现出一定的顺序性，因为主线程是每秒Push一个任务，这五个线程只会有一个线程获取到该任务，其他线程都会在等待队列中进行等待，当该线程处理完任务后就会因为任务队列为空而排到等待队列的最后，当主线程再次Push一个任务后会唤醒等待队列首部的一个线程，这个线程处理完任务后又会排到等待队列的最后，因此这五个线程在处理任务时会呈现出一定的顺序性。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAMjAyMWRyYWdvbg==,size_20,color_FFFFFF,t_70,g_se,x_16-1681698853283262.png)  

**注意：** 此后我们如果想让线程池处理其他不同的任务请求时，我们只需要提供一个任务类，在该任务类当中提供对应的任务处理方法就行了。

## Linux高级IO

### IO的基本概念

#### 什么是IO？

I/O（input/output）也就是输入和输出，在著名的冯诺依曼体系结构当中，将数据从输入设备拷贝到内存就叫做输入，将数据从内存拷贝到输出设备就叫做输出。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/8dd31a5659db4b1fba52ddcf38a70699.png)

+   对文件进行的读写操作本质就是一种IO，文件IO对应的外设就是磁盘。
+   对网络进行的读写操作本质也是一种IO，网络IO对应的外设就是网卡。

#### OS如何得知外设当中有数据可读取？

输入就是操作系统将数据从外设拷贝到内存的过程，操作系统一定要通过某种方法得知特定外设上是否有数据就绪。

+   并不是操作系统想要从外设读取数据时外设上就一定有数据。比如用户正在访问某台服务器，当用户的请求报文发出后就需要等待从网卡当中读取服务器发来的响应数据，但此时对方服务器可能还没有收到我们发出的请求报文，或是正在对我们的请求报文进行数据分析，也有可能服务器发来的响应数据还在网络中路由。
+   但操作系统不会主动去检测外设上是否有数据就绪，这种做法一定会降低操作系统的工作效率，因为大部分情况下外设当中都是没有数据的，因此操作系统所做的大部分检测工作其实都是徒劳的。
+   操作系统实际采用的是中断的方式来得知外设上是否有数据就绪的，当某个外设上面有数据就绪时，该外设就会向CPU当中的中断控制器发送中断信号，中断控制器再根据产生的中断信号的优先级按顺序发送给CPU。
+   每一个中断信号都有一个对应的中断处理程序，存储中断信号和中断处理程序映射关系的表叫做中断向量表，当CPU收到某个中断信号时就会自动停止正在运行的程序，然后根据该中断向量表执行该中断信号对应的中断处理程序，处理完毕后再返回原被暂停的程序继续运行。

需要注意的是，CPU不直接和外设打交道指的是在数据层面上，而外设其实是可以直接将某些控制信号发送给CPU当中的某些控制器的。

#### OS如何处理从网卡中读取到的数据包？

操作系统任何时刻都可能会收到大量的数据包，因此操作系统必须将这些数据包管理起来。所谓的管理就是“先描述，再组织”，在内核当中有一个结构叫做sk\_buff，该结构就是用来管理和控制接收或发送数据包的信息的。

为了说明sk\_buff的作用，下面给出一个简化版的sk\_buff结构：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/6cafce3e98764110ab1d8226fd4a70e0.png)  

当操作系统从网卡当中读取到一个数据包后，会将该数据依次交给链路层、网络层、传输层、应用层进行解包和分用，最终将数据包中的数据交给了上层用户，那对应到这个sk\_buff结构来说具体是如何进行数据包的解包和分用的呢？

+   当操作系统从网卡中读取到一个数据包后，就会定义出一个sk\_buff结构，然后用sk\_buff结构当中的data指针指向这个读取到的数据包，并将定义出来的这个sk\_buff结构与其他sk\_buff结构以双链表的形式组织起来，此时操作系统对各个数据包的管理就变成了对双链表的增删查改等操作。
+   接下来我们需要将读取上来的数据包交给最底层的链路层处理，进行链路层的解包和分用，此时就是让sk\_buff结构当中的mac\_header指针指向最初的数据包，然后向后读取链路层的报头，剩下的就是需要交给网络层处理的有效载荷了，此时便完成了链路层的解包，。
+   这时链路层就需要将有效载荷向上交付给网络层进行解包和分用了，这里所说的向上交付只是形象的说法，实际向上交付并不是要将数据从链路层的缓冲区拷贝到网络层的缓冲区，我们只需要让sk\_buff结构当中的network\_header指针，指向数据包中链路层报头之后的数据即可，然后继续向后读取网络层的报头，便完成了网络层的解包。
+   紧接着就是传输层对数据进行处理了，同样的道理，让sk\_buff结构当中的transport\_header指针，指向数据包中网络层报头之后的数据，然后继续向后读取传输层的报头，便完成了传输层的解包。
+   传输层解包后就可以根据具体使用的传输层协议，对应将剩下的数据拷贝到TCP或UDP的接收缓冲区供用户读取即可

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/105c9559a61d472f80ee844c29e7b7c4.png)  

发送数据时对数据进行封装也是同样的道理，就是依次在数据前面拷贝上对应的报头，最后再将数据发送出去（UDP）或拷贝到发送缓冲区（TCP)即可。也就是说，数据包在进行封装和解包的过程中，本质数据的存储位置是没有发生变化的，我们实际只是在用不同的指针对数据进行操作而已。

但内核中的sk\_buff并不像上面那样简单：

+   一方面，为了保证高效的网络报文处理效率，这就要求sk\_buff的结构也必须是高效的。
+   另一方面，sk\_buff结构需要被内核协议中的各个协议共同使用，因此sk\_buff必须能够兼容所有的网络协议。

因此sk\_buff结构实际是非常复杂的，在我的云服务器中sk\_buff结构的定义如下：

```cpp
struct sk_buff {
#ifdef __GENKSYMS__
	/* These two members must be first. */
	struct sk_buff          *next;
	struct sk_buff          *prev;
	ktime_t         tstamp;
#else
	union {
		struct {
			/* These two members must be first. */
			struct sk_buff          *next;
			struct sk_buff          *prev;

			union {
				ktime_t         tstamp;
				struct skb_mstamp skb_mstamp;
				__RH_KABI_CHECK_SIZE_ALIGN(ktime_t a,
				struct skb_mstamp b);
			};
		};
		struct rb_node  rbnode; /* used in netem, ip4 defrag, and tcp stack */
	};
#endif
	struct sock             *sk;
	struct net_device       *dev;

	/*
	* This is the control buffer. It is free to use for every
	* layer. Please put your private variables there. If you
	* want to keep them across layers you have to do a skb_clone()
	* first. This is owned by whoever has the skb queued ATM.
	*/
	char                    cb[48] __aligned(8);

	unsigned long           _skb_refdst;
#ifdef CONFIG_XFRM
	struct  sec_path        *sp;
#endif
	unsigned int            len,
		data_len;
	__u16                   mac_len,
		hdr_len;
	union {
		__wsum          csum;
		struct {
			__u16   csum_start;
			__u16   csum_offset;
		};
	};
	__u32                   priority;
	kmemcheck_bitfield_begin(flags1);
	__u8                    RH_KABI_RENAME(local_df, ignore_df) :1,
	cloned : 1,
		 ip_summed : 2,
				 nohdr : 1,
					 nfctinfo : 3;
	__u8                    pkt_type : 3,
	fclone : 2,
		 ipvs_property : 1,
					 peeked : 1,
						  nf_trace : 1;
	kmemcheck_bitfield_end(flags1);
	__be16                  protocol;

	void(*destructor)(struct sk_buff *skb);
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
	struct nf_conntrack     *nfct;
#endif
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
	struct nf_bridge_info   *nf_bridge;
#endif

	/* fields enclosed in headers_start/headers_end are copied
	* using a single memcpy() in __copy_skb_header()
	*/
	/* private: */
	RH_KABI_EXTEND(__u32    headers_start[0])
		/* public: */

		int                     skb_iif;

	RH_KABI_REPLACE(__u32   rxhash,
		__u32   hash)

		__be16                  vlan_proto;
	__u16                   vlan_tci;

#ifdef CONFIG_NET_SCHED
	__u16                   tc_index;       /* traffic control index */
#ifdef CONFIG_NET_CLS_ACT
	__u16                   tc_verd;        /* traffic control verdict */
#endif
#endif

	__u16                   queue_mapping;
	kmemcheck_bitfield_begin(flags2);
#ifdef CONFIG_IPV6_NDISC_NODETYPE
	__u8                    ndisc_nodetype : 2;
#endif
	__u8                    pfmemalloc : 1;
	__u8                    ooo_okay : 1;
	__u8                    RH_KABI_RENAME(l4_rxhash, l4_hash) :1;
	__u8                    wifi_acked_valid : 1;
	__u8                    wifi_acked : 1;
	__u8                    no_fcs : 1;
	__u8                    head_frag : 1;
	/* Indicates the inner headers are valid in the skbuff. */
	__u8                    encapsulation : 1;
	RH_KABI_EXTEND(__u8                     encap_hdr_csum : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_complete_sw : 1)
		RH_KABI_EXTEND(__u8                     xmit_more : 1)
		RH_KABI_EXTEND(__u8                     inner_protocol_type : 1)
		RH_KABI_EXTEND(__u8                     remcsum_offload : 1)
		/* 0/2 bit hole (depending on ndisc_nodetype presence) */
		kmemcheck_bitfield_end(flags2);

#if defined CONFIG_NET_DMA_RH_KABI || defined CONFIG_NET_RX_BUSY_POLL || defined CONFIG_XPS
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	union {
		__be16          inner_protocol;
		__u8            inner_ipproto;
	};
#endif

	__u16                   inner_transport_header;
	__u16                   inner_network_header;
	__u16                   inner_mac_header;
	__u16                   transport_header;
	__u16                   network_header;
	__u16                   mac_header;

	RH_KABI_EXTEND(kmemcheck_bitfield_begin(flags3))
		RH_KABI_EXTEND(__u8     csum_level : 2)
		RH_KABI_EXTEND(__u8     rh_csum_pad : 1)
		RH_KABI_EXTEND(__u8     rh_csum_bad_unused : 1) /* one bit hole */
		RH_KABI_EXTEND(__u8     offload_fwd_mark : 1)
		RH_KABI_EXTEND(__u8     sw_hash : 1)
		RH_KABI_EXTEND(__u8     csum_not_inet : 1)
		RH_KABI_EXTEND(__u8     dst_pending_confirm : 1)
		RH_KABI_EXTEND(__u8     offload_mr_fwd_mark : 1)
		/* 7 bit hole */
		RH_KABI_EXTEND(kmemcheck_bitfield_end(flags3))

		/* private: */
		RH_KABI_EXTEND(__u32    headers_end[0])
		/* public: */

		/* RHEL SPECIFIC
		*
		* The following padding has been inserted before ABI freeze to
		* allow extending the structure while preserve ABI. Feel free
		* to replace reserved slots with required structure field
		* additions of your backport, eventually moving the replaced slot
		* before headers_end, if it need to be copied by __copy_skb_header()
		*/
		u32                     rh_reserved1;
	u32                     rh_reserved2;
	u32                     rh_reserved3;
	u32                     rh_reserved4;
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	kmemcheck_bitfield_begin(flags1);
	__u8                    RH_KABI_RENAME(local_df, ignore_df) :1,
	cloned : 1,
		 ip_summed : 2,
				 nohdr : 1,
					 nfctinfo : 3;
	__u8                    pkt_type : 3,
	fclone : 2,
		 ipvs_property : 1,
					 peeked : 1,
						  nf_trace : 1;
	kmemcheck_bitfield_end(flags1);
	__be16                  protocol;

	void(*destructor)(struct sk_buff *skb);
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
	struct nf_conntrack     *nfct;
#endif
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
	struct nf_bridge_info   *nf_bridge;
#endif

	/* fields enclosed in headers_start/headers_end are copied
	* using a single memcpy() in __copy_skb_header()
	*/
	/* private: */
	/* private: */
	RH_KABI_EXTEND(__u32    headers_start[0])
		/* public: */

		int                     skb_iif;

	RH_KABI_REPLACE(__u32   rxhash,
		__u32   hash)


		__be16                  vlan_proto;
	__u16                   vlan_tci;

#ifdef CONFIG_NET_SCHED
	__u16                   tc_index;       /* traffic control index */
#ifdef CONFIG_NET_CLS_ACT
	__u16                   tc_verd;        /* traffic control verdict */
#endif
#endif

	__u16                   queue_mapping;
	kmemcheck_bitfield_begin(flags2);
#ifdef CONFIG_IPV6_NDISC_NODETYPE
	__u8                    ndisc_nodetype : 2;
#endif
	__u8                    pfmemalloc : 1;
	__u8                    ooo_okay : 1;
	__u8                    RH_KABI_RENAME(l4_rxhash, l4_hash) :1;
	__u8                    wifi_acked_valid : 1;
	__u8                    wifi_acked : 1;
	__u8                    no_fcs : 1;
	__u8                    head_frag : 1;
	/* Indicates the inner headers are valid in the skbuff. */
	__u8                    encapsulation : 1;
	RH_KABI_EXTEND(__u8                     encap_hdr_csum : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_valid : 1)
		RH_KABI_EXTEND(__u8                     csum_complete_sw : 1)
		RH_KABI_EXTEND(__u8                     xmit_more : 1)
		RH_KABI_EXTEND(__u8                     inner_protocol_type : 1)
		RH_KABI_EXTEND(__u8                     remcsum_offload : 1)
		/* 0/2 bit hole (depending on ndisc_nodetype presence) */
		kmemcheck_bitfield_end(flags2);

#if defined CONFIG_NET_DMA_RH_KABI || defined CONFIG_NET_RX_BUSY_POLL || defined CONFIG_XPS
	union {
		unsigned int    napi_id;
		RH_KABI_EXTEND(unsigned int     sender_cpu)
			RH_KABI_DEPRECATE(dma_cookie_t, dma_cookie)
	};
#endif
#ifdef CONFIG_NETWORK_SECMARK
	__u32                   secmark;
#endif
	union {
		__u32           mark;
		__u32           dropcount;
		__u32           reserved_tailroom;
	};

#ifdef __GENKSYMS__
	__be16                  inner_protocol;
#else
	union {
		__be16          inner_protocol;
		__u8            inner_ipproto;
	};
#endif

	__u16                   inner_transport_header;
	__u16                   inner_network_header;
	__u16                   inner_mac_header;
	__u16                   transport_header;
	__u16                   network_header;
	__u16                   mac_header;

	RH_KABI_EXTEND(kmemcheck_bitfield_begin(flags3))
		RH_KABI_EXTEND(__u8     csum_level : 2)
		RH_KABI_EXTEND(__u8     rh_csum_pad : 1)
		RH_KABI_EXTEND(__u8     rh_csum_bad_unused : 1) /* one bit hole */
		RH_KABI_EXTEND(__u8     offload_fwd_mark : 1)
		RH_KABI_EXTEND(__u8     sw_hash : 1)
		RH_KABI_EXTEND(__u8     csum_not_inet : 1)
		RH_KABI_EXTEND(__u8     dst_pending_confirm : 1)
		RH_KABI_EXTEND(__u8     offload_mr_fwd_mark : 1)
		/* 7 bit hole */
		RH_KABI_EXTEND(kmemcheck_bitfield_end(flags3))

		/* private: */
		RH_KABI_EXTEND(__u32    headers_end[0])
		/* public: */

		/* RHEL SPECIFIC
		*
		* The following padding has been inserted before ABI freeze to
		* allow extending the structure while preserve ABI. Feel free
		* to replace reserved slots with required structure field
		* additions of your backport, eventually moving the replaced slot
		* before headers_end, if it need to be copied by __copy_skb_header()
		*/
		u32                     rh_reserved1;
	u32                     rh_reserved2;
	u32                     rh_reserved3;
	u32                     rh_reserved4;

	/* These elements must be at the end, see alloc_skb() for details.  */
	sk_buff_data_t          tail;
	sk_buff_data_t          end;
	unsigned char           *head,
		*data;
	unsigned int            truesize;
	atomic_t                users;
};
```

#### 什么是高效的IO？

IO主要分为两步：

+   第一步是等，即等待IO条件就绪。
+   第二步是拷贝，也就是当IO条件就绪后将数据拷贝到内存或外设。

任何IO的过程，都包含“等”和“拷贝”这两个步骤，但在实际的应用场景中“等”消耗的时间往往比“拷贝”消耗的时间多，因此要让IO变得高效，最核心的办法就是尽量减少“等”的时间。

### 钓鱼五人组

IO的过程其实和钓鱼是非常类似的。

+   钓鱼的过程同样分为“等”和“拷贝”两个步骤，只不过这里的“等”指的是等鱼上钩，“拷贝”指的是当鱼上钩后将鱼从河里“拷贝”到我们的鱼桶当中。
+   IO时“等”消耗的时间往往比“拷贝”消耗的时间多，钓鱼也恰好符合这个特点，钓鱼时我们大部分时间都在等鱼上钩，而当鱼上钩后只需要一瞬间就能将鱼“拷贝”上来。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/e813f968d4ca4272ab7033c1bad946a3.png)  
在谈论高效的IO之前，我们先来看看什么样的钓鱼方式才是高效的。

下面给出五个人的钓鱼方式：

+   张三：拿了1个鱼竿，将鱼钩抛入水中后就死死的盯着浮漂，什么也不做，当有鱼上钩后就挥动鱼竿将鱼钓上来。
+   李四：拿了1个鱼竿，将鱼钩抛入水中后就去做其他事情，然后定期观察浮漂，如果有鱼上钩则挥动鱼竿将鱼钓上来，否则继续去做其他事情。
+   王五：拿了1个鱼竿，将鱼钩抛入水中后在鱼竿顶部绑一个铃铛，然后就去做其他事情，如果铃铛响了就挥动鱼竿将鱼钓上来，否则就根本不管鱼竿。
+   赵六：拿了100个鱼竿，将100个鱼竿抛入水中后就定期观察这100个鱼竿的浮漂，如果某个鱼竿有鱼上钩则挥动对应的鱼竿将鱼钓上来。
+   田七：田七是一个有钱的老板，他给了自己的司机一个桶、一个电话、一个鱼竿，让司机去钓鱼，当鱼桶装满的时候再打电话告诉田七来拿鱼，而田七自己则开车去做其他事情去了。

> 张三、李四、王五的钓鱼效率是否一样？为什么？

张三、李四、王五的钓鱼效率本质上是一样的。

+   首先他们的钓鱼方式都是一样的，都是先等鱼上钩，然后再将鱼钓上来。
+   其次，因为他们每个人都是拿的一根鱼竿，当河里有鱼来咬鱼钩时，这条鱼咬哪一个鱼钩的概率都是相等的。

因此张三、李四、王五他们三个人的钓鱼的效率是一样的，他们只是等鱼上钩的方式不同而已，张三是死等，李四是定期检测浮漂，而王五是通过铃铛来判断是否有鱼上钩。

需要注意的是，这里问的是他们的钓鱼效率是否是一样的，而不是问他们整体谁做的事最多，如果说整体做事情的量的话，那一定是王五做得最多，李四次之，张三最少。

> 张三、李四、王五它们三个人分别和赵六比较，谁的钓鱼效率更高？

赵六毫无疑问是这四个人当中钓鱼效率最高的，因为赵六同时在等多个鱼竿上有鱼上钩，因此在单位时间内，赵六的鱼竿有鱼上钩的概率是最大的。

+   为了方便计算，我们假设赵六拿了97个鱼竿，加上张三、李四、王五的鱼竿一共就有100个鱼竿。
+   当河里有鱼来咬鱼钩时，这条鱼咬张三、李四、王五的鱼钩的概率都是百分之一，而咬赵六的鱼钩的概率就是百分之九十七。
+   因此在单位时间内，赵六的鱼竿上有鱼的概率是张三、李四、王五的97倍。

而高效的钓鱼就是要减少单位时间内“等”的时间，增加“拷贝”的时间，所以说赵六的钓鱼效率是这四个人当中最高的。

赵六的钓鱼效率之所以高，是因为赵六一次等待多个鱼竿上的鱼上钩，此时就可以将“等”的时间进行重叠。

> 如何看待田七的这种钓鱼方式？

田七让自己的司机帮自己钓鱼，自己开车去做其他事情去了，此时这个司机具体怎么钓鱼已经不重要了，他可以模仿张三、李四、王五、赵六任何一个人的钓鱼方式进行钓鱼。

最重要的是田七本人并没有参与整个钓鱼的过程，他只是发起了钓鱼的任务，而真正钓鱼的是司机，田七在司机钓鱼期间可能在做任何其他事情，如果将钓鱼看作是一种IO的话，那田七的这种钓鱼方式就叫做异步IO。

而对于张三、李四、王五、赵六来说，他们都需要自己等鱼上钩，当鱼上钩后又需要自己把鱼从河里钓上来，对应到IO当中就是需要自己进行数据的拷贝，因此他们四个人的钓鱼方式都叫做同步IO。

> 五种IO模型

实际这五个人的钓鱼方式分别对应的就是**五种IO模型**。

+   张三这种死等的钓鱼方式对应就是**阻塞IO**。
+   李四这种定时检测是否有鱼上钩的方式就是**非阻塞IO**。
+   王五这种通过设置铃铛得知事件是否就绪的方式就是**信号驱动IO**。
+   王五这种一次等待多个鱼竿上有鱼的钓鱼方式就是**IO多路转接**。
+   田七这种让别人帮自己钓鱼的钓鱼方式就是**异步IO**。

通过这里的钓鱼例子我们可以看到，**阻塞IO、非阻塞IO和信号驱动IO本质上是不能提高IO的效率的**，**但非阻塞IO和信号驱动IO能提高整体做事的效率**。

其中，这个钓鱼场景中的各个事物都能与IO当中的相关概念对应起来，比如这里钓鱼的河对应就是内核，这里的每一个人都是进程或线程，鱼竿对应的就是文件描述符或套接字，装鱼的桶对应的就是用户缓冲区。

### 五种IO模型

#### 阻塞IO

阻塞IO就是在内核将数据准备好之前，系统调用会一直等待。

图示如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/eff905b4df774709ac5c41defbc015ec.png)  

阻塞IO是最常见的IO模型，所有的套接字，默认都是阻塞方式。

+   比如当调用recvfrom函数从某个套接字上读取数据时，可能底层数据还没有准备好，此时就需要等待数据就绪，当数据就绪后再将数据从内核拷贝到用户空间，最后recvfrom函数才会返回。
+   在recvfrom函数等待数据就绪期间，在用户看来该进程或线程就阻塞住了，本质就是操作系统将该进程或线程的状态设置为了某种非R状态，然后将其放入等待队列当中，当数据就绪后操作系统再将其从等待队列当中唤醒，然后该进程或线程再将数据从内核拷贝到用户空间。

以阻塞方式进行IO操作的进程或线程，在“等”和“拷贝”期间都不会返回，在用户看来就像是阻塞住了，因此我们称之为阻塞IO。

#### 非阻塞IO

非阻塞IO就是，如果内核还未将数据准备好，系统调用仍然会直接返回，并且返回EWOULDBLOCK错误码。

图示如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/df348811807d479e8b24b3d4623a54db.png)  

非阻塞IO往往需要程序员以循环的方式反复尝试读写文件描述符，这个过程称为轮询，这对CPU来说是较大的浪费，一般只有特定场景下才使用。

+   比如当调用recvfrom函数以非阻塞方式从某个套接字上读取数据时，如果底层数据还没有准备好，那么recvfrom函数会立马错误返回，而不会让该进程或线程进行阻塞等待。
+   因为没有读取的数据，因此该进程或线程后续还需要继续调用recvfrom函数，检测底层数据是否就绪，如果没有就绪则继续错误返回，直到某次检测到底层数据就绪后，再将数据从内核拷贝到用户空间然后进行成功返回。
+   每次调用recvfrom函数读取数据时，就算底层数据没有就绪，recvfrom函数也会立马返回，在用户看来该进程或线程就没有被阻塞住，因此我们称之为非阻塞IO。

阻塞IO和非阻塞IO的区别在于，阻塞IO当数据没有就绪时，后续检测数据是否就绪的工作是由操作系统发起的，而非阻塞IO当数据没有就绪时，后续检测数据是否就绪的工作是由用户发起的。

#### 信号驱动IO

信号驱动IO就是当内核将数据准备好的时候，使用SIGIO信号通知应用程序进行IO操作。

图示如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/61c0bfc00e8c4c3791e07751ca5c29e4.png)  

当底层数据就绪的时候会向当前进程或线程递交SIGIO信号，因此可以通过signal或sigaction函数将SIGIO的信号处理程序自定义为需要进行的IO操作，当底层数据就绪时就会自动执行对应的IO操作。

+   比如我们需要调用recvfrom函数从某个套接字上读取数据，那么就可以将该操作定义为SIGIO的信号处理程序。
+   当底层数据就绪时，操作系统就会递交SIGIO信号，此时就会自动执行我们定义的信号处理程序，进程将数据从内核拷贝到用户空间。

信号的产生是异步的，但信号驱动IO是同步IO的一种。

+   我们说信号的产生异步的，因为信号在任何时刻都可能产生。
+   但信号驱动IO是同步IO的一种，因为当底层数据就绪时，当前进程或线程需要停下正在做的事情，转而进行数据的拷贝操作，因此当前进程或线程仍然需要参与IO过程。

判断一个IO过程是同步的还是异步的，本质就是看当前进程或线程是否需要参与IO过程，如果要参与那就是同步IO，否则就是异步IO。

#### IO多路转接

IO多路转接也叫做IO多路复用，能够同时等待多个文件描述符的就绪状态。

图示如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/f1f2c73e90454e7c914f0981c04db652.png)  

IO多路转接的思想：

+   因为IO过程分为“等”和“拷贝”两个步骤，因此我们使用的recvfrom等接口的底层实际上都做了两件事，第一件事就是当数据不就绪时需要等，第二件事就是当数据就绪后需要进行拷贝。
+   虽然recvfrom等接口也有“等”的能力，但这些接口一次只能“等”一个文件描述符上的数据或空间就绪，这样IO效率太低了。
+   因此系统为我们提供了三组接口，分别叫做select、poll和epoll，这些接口的核心工作就是“等”，我们可以将所有“等”的工作都交给这些多路转接接口。
+   因为这些多路转接接口是一次“等”多个文件描述符的，因此能够将“等”的时间进行重叠，当数据就绪后再调用对应的recvfrom等函数进行数据的拷贝，此时这些函数就能够直接进行拷贝，而不需要进行“等”操作了。

IO多路转接就像现实生活中的黄牛一样，只不过IO多路转接更像是帮人排队的黄牛，因为多路转接接口实际并没有帮我们进行数据拷贝的操作。这些排队黄牛可以一次帮多个人排队，此时就将多个人排队的时间进行了重叠。

#### 异步IO

异步IO就是由内核在数据拷贝完成时，通知应用程序。

图示如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/d0804dbecf77486c80c906ea79759fb6.png)

+   进行异步IO需要调用一些异步IO的接口，异步IO接口调用后会立马返回，因为异步IO不需要你进行“等”和“拷贝”的操作，这两个动作都由操作系统来完成，你要做的只是发起IO。
+   当IO完成后操作系统会通知应用程序，因此进行异步IO的进程或线程并不参与IO的所有细节。

### 高级IO重要概念

#### 同步通信 VS 异步通信

同步和异步关注的是消息通信机制。

+   所谓同步，就是在发出一个调用时，在没有得到结果之前，该调用就不返回，但是一旦调用返回，就得到返回值了；换句话说，就是由调用者主动等待这个调用的结果。
+   异步则是相反，调用在发出之后，这个调用就直接返回了，所以没有返回结果；换句话说，当一个异步过程调用发出后，调用者不会立刻得到结果；而是在调用发出后，被调用者通过状态、通知来通知调用者，或通过回调函数处理这个调用。

> 为什么非阻塞IO在没有得到结果之前就返回了？

+   IO是分为“等”和“拷贝”两步的，当调用recvfrom进行非阻塞IO时，如果数据没有就绪，那么调用会直接返回，此时这个调用返回时并没有完成一个完整的IO过程，即便调用返回了那也是属于错误的返回。
+   因此该进程或线程后续还需要继续调用recvfrom，轮询检测数据是否就绪，当数据就绪后最后再把数据从内核拷贝到用户空间，这才是一次完整的IO过程。

因此，在进行非阻塞IO时，在没有得到结果之前，虽然这个调用会返回，但后续还需要继续进行轮询检测，因此可以理解成调用还没有返回，而只有当某次轮询检测到数据就绪，并且完成数据拷贝后才认为该调用返回了。

> 同步通信 VS 同步与互斥

在多进程和多线程当中有同步与互斥的概念，但是这里的同步通信和进程或线程之间的同步是**完全不相干**的概念。

+   进程/线程同步指的是，在保证数据安全的前提下，让进程/线程能够按照某种特定的顺序访问临界资源，从而有效避免饥饿问题，谈论的是进程/线程间的一种工作关系。
+   而同步IO指的是进程/线程与操作系统之间的关系，谈论的是进程/线程是否需要主动参与IO过程。

因此当看到“同步”这个词的时候，一定要先明确这个同步是同步通信的同步，还是同步与互斥的同步。

#### 阻塞 VS 非阻塞

阻塞和非阻塞关注的是程序在等待调用结果（消息、返回值）时的状态。

+   阻塞调用是指调用结果返回之前，当前线程会被挂起，调用线程只有在得到结果之后才会返回。
+   非阻塞调用指在不能立刻得到结果之前，该调用不会阻塞当前线程。

#### 其他高级IO

非阻塞IO，记录锁，系统V流机制，I/O多路转接（也叫I/O多路复用），readv和writev函数以及存储映射IO（mmap），这些统称为高级IO。

### 阻塞IO

系统中大部分的接口都是阻塞式接口，比如我们可以用read函数从标准输入当中读取数据。

```cpp
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	char buffer[1024];
	while (true){
		ssize_t size = read(0, buffer, sizeof(buffer)-1);
		if (size < 0){
			std::cerr << "read error" << std::endl;
			break;
		}
		buffer[size] = '\0';
		std::cout << "echo# " << buffer << std::endl;
	}
	return 0;
}
```

程序运行后，如果我们不进行输入操作，此时该进程就会阻塞住，根本原因就是因为此时底层数据不就绪，因此read函数需要进行阻塞等待。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/f19a62123ff1406bbd1be77a4c1c216d.png)  

一旦我们进行了输入操作，此时read函数就会检测到底层数据就绪，然后立马将数据读取到从内核拷贝到我们传入的buffer数组当中，并且将读取到的数据输出到显示器上面，最后我们就看到了我们输入的字符串。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/664615ea8c484fd49f1d1f954f7dad72-1681699856094194.png)

**说明一下：**

+   C++当中的cin和C语言当中的scanf也可以读取从键盘输入的字符，但是cin和scanf会提供用户缓冲区，为了避免这些因素的干扰，因此这里选择使用read函数进行读取。

### 非阻塞IO

**打开文件时默认都是以阻塞的方式打开的**，如果要以非阻塞的方式打开某个文件，需要在**使用open函数打开文件时携带`O_NONBLOCK`或`O_NDELAY`选项**，此时就能够以非阻塞的方式打开文件。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/df1f86e07c09436783bd92a52f308e40.png)  

这是在打开文件时设置非阻塞的方式，如果要**将已经打开的某个文件或套接字设置为非阻塞，此时就需要用到fcntl函数**。

> fcntl函数

fcntl函数的函数原型如下：

```cpp
int fcntl(int fd, int cmd, ... /* arg */);
```

参数说明：

+   fd：已经打开的文件描述符。
+   cmd：需要进行的操作。
+   …：可变参数，传入的cmd值不同，后面追加的参数也不同。

**fcntl函数常用的5种功能与其对应的cmd取值**如下：

+   复制一个现有的描述符（cmd=F\_DUPFD）。
+   获得/设置文件描述符标记（cmd=F\_GETFD或F\_SETFD）。
+   获得/设置文件状态标记（cmd=F\_GETFL或F\_SETFL）。
+   获得/设置异步I/O所有权（cmd=F\_GETOWN或F\_SETOWN）。
+   获得/设置记录锁（cmd=F\_GETLK, F\_SETLK或F\_SETLKW）。

返回值说明：

+   如果函数调用成功，则返回值取决于具体进行的操作。
+   如果函数调用失败，则返回-1，同时错误码会被设置。

> 实现SetNonBlock函数

我们可以定义一个函数，该函数就用于将指定的文件描述符设置为非阻塞状态。

+   先调用fcntl函数获取该文件描述符对应的文件状态标记（这是一个位图），此时调用fcntl函数时传入的cmd值为`F_GETFL`。
+   在获取到的文件状态标记上添加非阻塞标记`O_NONBLOCK`，再次调用fcntl函数对文件状态标记进行设置，此时调用fcntl函数时传入的cmd值为`F_SETFL`。

代码如下：

```cpp
bool SetNonBlock(int fd)
{
	int fl = fcntl(fd, F_GETFL);//获取原始的状态
	if (fl < 0){
		std::cerr << "fcntl error" << std::endl;
		return false;
	}
	fcntl(fd, F_SETFL, fl | O_NONBLOCK);//增加非阻塞状态，并替代原来的文件状态
	return true;
}
```

此时就将该文件描述符设置为了非阻塞状态。

> 以非阻塞轮询方式读取标准输入

此时在调用read函数读取标准输入之前，调用SetNonBlock函数将0号文件描述符设置为非阻塞就行了。

代码如下：

```cpp
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <cstring>
#include <cerrno>
bool SetNonBlock(int fd)
{
	int fl = fcntl(fd, F_GETFL);
	if (fl < 0){
		std::cerr << "fcntl error" << std::endl;
		return false;
	}
	fcntl(fd, F_SETFL, fl | O_NONBLOCK);
	return true;
}
int main()
{
	SetNonBlock(0);
	char buffer[1024];
	while (true){
		ssize_t size = read(0, buffer, sizeof(buffer)-1);
		if (size < 0){
			if (errno == EAGAIN || errno == EWOULDBLOCK){ //底层数据没有就绪
				std::cout << strerror(errno) << std::endl;
				sleep(1);
				continue;
			}
			else if (errno == EINTR){ //在读取数据之前被信号中断
				std::cout << strerror(errno) << std::endl;
				sleep(1);
				continue;
			}
			else{
				std::cerr << "read error" << std::endl;
				break;
			}
		}
		buffer[size] = '\0';
		std::cout << "echo# " << buffer << std::endl;
	}
	return 0;
}
```

需要注意的是，当read函数以非阻塞方式读取标准输入时，如果底层数据不就绪，那么read函数就会立即返回，但当底层数据不就绪时，read函数是以出错的形式返回的，此时的错误码会被设置为`EAGAIN`或`EWOULDBLOCK`。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/22e5d7f3c3b24ba6883e998cce231205.png)  

因此在以非阻塞方式读取数据时，如果调用read函数时得到的返回值是-1，此时还需要通过错误码进一步进行判断，如果错误码的值是`EAGAIN`或`EWOULDBLOCK`，说明本次调用read函数出错是因为底层数据还没有就绪，因此后续还应该继续调用read函数进行轮询检测数据是否就绪，当数据继续时再进行数据的读取。

此外，**调用read函数在读取到数据之前可能会被其他信号中断**，此时read函数也会以出错的形式返回，此时的错误码会被设置为`EINTR`，此时应该重新执行read函数进行数据的读取。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/60125161542748f2b5f35e2d333ec83d.png)  

因此在以非阻塞的方式读取数据时，如果调用read函数读取到的返回值为-1，此时并不应该直接认为read函数在底层读取数据时出错了，而应该继续判断错误码，如果错误码的值为`EAGAIN`、`EWOULDBLOCK`或`EINTR`则应该继续调用read函数再次进行读取。

运行代码后，当我们没有输入数据时，程序就会不断调用read函数检测底层数据是否就绪。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/c1fec3f43bce4ee5824b7e208630af0c.png)  

一旦我们进行了输入操作，此时read函数就会在轮询检测时检测到，紧接着立马将数据读取到从内核拷贝到我们传入的buffer数组当中，并且将读取到的数据输出到显示器上面。  

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/b63bac64b1e64eeca735a0f9393e404f-1681699884941197.png)



### mmap

## I/O多路转接之select

### select初识

select是系统提供的一个多路转接接口。

+   select系统调用可以让我们的程序同时监视多个文件描述符的上的事件是否就绪。
+   select的核心工作就是等，当监视的多个文件描述符中有一个或多个事件就绪时，select才会成功返回并将对应文件描述符的就绪事件告知调用者。

### select函数

> select函数

select函数的函数原型如下：

```cpp
int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
```

参数说明：

+   nfds：需要监视的文件描述符中，最大的文件描述符值+1。
+   readfds：输入输出型参数，调用时用户告知内核需要监视哪些文件描述符的读事件是否就绪，返回时内核告知用户哪些文件描述符的读事件已经就绪。
+   writefds：输入输出型参数，调用时用户告知内核需要监视哪些文件描述符的写事件是否就绪，返回时内核告知用户哪些文件描述符的写事件已经就绪。
+   exceptfds：输入输出型参数，调用时用户告知内核需要监视哪些文件描述符的异常事件是否就绪，返回时内核告知用户哪些文件描述符的异常事件已经就绪。
+   timeout：输入输出型参数，调用时由用户设置select的等待时间，返回时表示timeout的剩余时间。

参数timeout的取值：

+   NULL/nullptr：select调用后进行阻塞等待，直到被监视的某个文件描述符上的某个事件就绪。
+   0：selec调用后t进行非阻塞等待，无论被监视的文件描述符上的事件是否就绪，select检测后都会立即返回。
+   特定的时间值：select调用后在指定的时间内进行阻塞等待，如果被监视的文件描述符上一直没有事件就绪，则在该时间后，select进行超时返回；如果该事件内有准备好的文件，则返回时表示剩余的时间。

返回值说明：

+   如果函数调用成功，则返回有事件就绪的文件描述符个数。
+   如果timeout时间耗尽，则返回0。
+   如果函数调用失败，则返回-1，同时错误码会被设置。

select调用失败时，错误码可能被设置为：

+   `EBADF`：文件描述符为无效的或该文件已关闭。
+   `EINTR`：此调用被信号所中断。
+   `EINVAL`：参数nfds为负值。
+   `ENOMEM`：核心内存不足。

> fd\_set结构

fd\_set结构与sigset\_t结构类似，fd\_set本质也是一个位图，用位图中对应的位来表示要监视的文件描述符。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/9a73bf0987e04266b8d49ee6ceff309d-16828454115613.png)![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/6d109275d5494385bf7c52c612631eb8-1681699909021202.png)  

调用select函数之前就需要用fd\_set结构定义出对应的文件描述符集，然后将需要监视的文件描述符添加到文件描述符集当中，这个添加的过程本质就是在进行位操作，但是这个位操作不需要用户自己进行，系统提供了一组专门的接口，用于对fd\_set类型的位图进行各种操作。

如下：

```cpp
void FD_CLR(int fd, fd_set *set);      //用来清除描述词组set中相关fd的位
int  FD_ISSET(int fd, fd_set *set);    //用来测试描述词组set中相关fd的位是否为真
void FD_SET(int fd, fd_set *set);      //用来设置描述词组set中相关fd的位
void FD_ZERO(fd_set *set);             //用来清除描述词组set的全部位
```

> timeval结构

传入select函数的最后一个参数timeout，就是一个指向timeval结构的指针，timeval结构用于描述一段时间长度，该结构当中包含两个成员，其中tv\_sec表示的是秒，tv\_usec表示的是微秒。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/05a49203265b4e35be83f236f19f5624-1681699909021203.png)

### socket就绪条件

> 读就绪

+   socket内核中，接收缓冲区中的字节数，大于等于低水位标记`SO_RCVLOWAT`，此时可以无阻塞的读取该文件描述符，并且返回值大于0。
+   socket TCP通信中，对端关闭连接，此时对该socket读，则返回0。
+   监听的socket上有新的连接请求。
+   socket上有未处理的错误。

> 写就绪

+   socket内核中，发送缓冲区中的可用字节数，大于等于低水位标记`SO_SNDLOWAT`，此时可以无阻塞的写，并且返回值大于0。
+   socket的写操作被关闭（close或者shutdown），对一个写操作被关闭的socket进行写操作，会触发SIGPIPE信号。
+   socket使用非阻塞connect连接成功或失败之后。
+   socket上有未读取的错误。

> 异常就绪

+   socket上收到带外数据。

```cpp
注：带外数据和TCP的紧急模式相关，TCP报头当中的URG标志位和16位紧急指针搭配使用，就能够发送/接收带外数据。
```

### select基本工作流程

如果我们要实现一个简单的select服务器，该服务器要做的就是读取客户端发来的数据并进行打印，那么这个select服务器的工作流程应该是这样的：

+   先初始化服务器，完成套接字的创建、绑定和监听。
+   定义一个fd\_array数组用于保存监听套接字和已经与客户端建立连接的套接字，刚开始时就将监听套接字添加到fd\_array数组当中。
+   然后服务器开始循环调用select函数，检测读事件是否就绪，如果就绪则执行对应的操作。
+   每次调用select函数之前，都需要定义一个读文件描述符集readfds，并将fd\_array当中的文件描述符依次设置进readfds当中，表示让select帮我们监视这些文件描述符的读事件是否就绪。
+   当select检测到数据就绪时会将读事件就绪的文件描述符设置进readfds当中，此时我们就能够得知哪些文件描述符的读事件就绪了，并对这些文件描述符进行对应的操作。
+   如果读事件就绪的是监听套接字，则调用accept函数从底层全连接队列获取已经建立好的连接，并将该连接对应的套接字添加到fd\_array数组当中。
+   如果读事件就绪的是与客户端建立连接的套接字，则调用read函数读取客户端发来的数据并进行打印输出。
+   当然，服务器与客户端建立连接的套接字读事件就绪，也可能是因为客户端将连接关闭了，此时服务器应该调用close关闭该套接字，并将该套接字从fd\_array数组当中清除，因为下一次不需要再监视该文件描述符的读事件了。

**说明一下：**

+   因为传入select函数的readfds、writefds和exceptfds都是输入输出型参数，当select函数返回时这些参数当中的值已经被修改了，因此每次调用select函数时都需要对其进行重新设置，timeout也是类似的道理。
+   因为每次调用select函数之前都需要对readfds进行重新设置，所以需要定义一个fd\_array数组保存与客户端已经建立的若干连接和监听套接字，实际fd\_array数组当中的文件描述符就是需要让select监视读事件的文件描述符。
+   我们的select服务器只是读取客户端发来的数据，因此只需要让select帮我们监视特定文件描述符的读事件，如果要同时让select帮我们监视特定文件描述符的读事件和写事件，则需要分别定义readfds和writefds，并定义两个数组分别保存需要被监视读事件和写事件的文件描述符，便于每次调用select函数前对readfds和writefds进行重新设置。
+   服务器刚开始运行时，fd\_array数组当中只有监听套接字，因此select第一次调用时只需要监视监听套接字的读事件是否就绪，但每次调用accept获取到新连接后，都会将新连接对应的套接字添加到fd\_array当中，因此后续select调用时就需要监视监听套接字和若干连接套接字的读事件是否就绪。
+   由于调用select时还需要传入被监视的文件描述符中最大文件描述符值+1，因此每次在遍历fd\_array对readfds进行重新设置时，还需要记录最大文件描述符值。

这其中还有很多细节，下面我们就来实现这样一个select服务器。

### select服务器

> Socket类

首先我们可以编写一个Socket类，对套接字相关的接口进行一定程度的封装，为了让外部能够直接调用Socket类当中封装的函数，于是将这些函数定义成了静态成员函数。

代码如下：

```cpp
#pragma once

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>

class Socket{
public:
	//创建套接字
	static int SocketCreate()
	{
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0){
			std::cerr << "socket error" << std::endl;
			exit(2);
		}
		//设置端口复用
		int opt = 1;
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		return sock;
	}
	//绑定
	static void SocketBind(int sock, int port)
	{
		struct sockaddr_in local;
		memset(&local, 0, sizeof(local));
		local.sin_family = AF_INET;
		local.sin_port = htons(port);
		local.sin_addr.s_addr = INADDR_ANY;
		
		socklen_t len = sizeof(local);

		if (bind(sock, (struct sockaddr*)&local, len) < 0){
			std::cerr << "bind error" << std::endl;
			exit(3);
		}
	}
	//监听
	static void SocketListen(int sock, int backlog)
	{
		if (listen(sock, backlog) < 0){
			std::cerr << "listen error" << std::endl;
			exit(4);
		}
	}
};
```

> SelectServer类

现在编写SelectServer类，因为我当前使用的是云服务器，所以编写的select服务器在绑定时不需要显示绑定IP地址，直接将IP地址设置为`INADDR_ANY`就行了，所以类当中只包含监听套接字和端口号两个成员变量。

+   在构造SelectServer对象时，需要指明select服务器的端口号，当然也可以在初始化select服务器的时候指明。
+   在初始化select服务器的时候调用Socket类当中的函数，依次进行套接字的创建、绑定和监听即可。
+   在析构函数中可以选择调用close函数将监听套接字进行关闭，但实际也可以不进行该动作，因为服务器运行后一般是不退出的。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <sys/select.h>

#define BACK_LOG 5

class SelectServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	SelectServer(int port)
		: _port(port)
	{}
	void InitSelectServer()
	{
		_listen_sock = Socket::SocketCreate();
		Socket::SocketBind(_listen_sock, _port);
		Socket::SocketListen(_listen_sock, BACK_LOG);
	}
	~SelectServer()
	{
		if (_listen_sock >= 0){
			close(_listen_sock);
		}
	}
};
```

> 运行服务器

服务器初始化完毕后就应该周期性的执行某种动作了，而select服务器要做的就是不断调用select函数，当事件就绪时对应执行某种动作即可。

+   首先，在select服务器开始死循环调用select函数之前，需要先定义一个fd\_array数组，先把数组中所有的位置初始化为无效，并将监听套接字添加到该数组当中，fd\_array数组当中保存的就是需要被select监视读事件是否就绪的文件描述符。
+   此后，select服务器就不断调用select函数监视读事件是否就绪，每次调用select函数之前都需要重新设置readfds，具体设置过程就是遍历fd\_array数组，将fd\_array数组当中的文件描述符添加到readfds当中，并同时记录最大的文件描述符值maxfd，因为后续调用select函数时需要将maxfd+1作为第一个参数传入。
+   当select函数返回后，如果返回值为0，则说明timeout时间耗尽，此时直接准备进行下一次select调用即可。如果select的返回值为-1，则说明select调用失败，此时也让服务器准备进行下一次select调用，但实际应该进一步判断错误码，根据错误码来判断是否应该继续调用select函数。
+   如果select的返回值大于0，则说明select函数调用成功，此时已经有文件描述符的读事件就绪，接下来就应该对就绪事件进行处理。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <sys/select.h>

#define BACK_LOG 5
#define NUM 1024
#define DFL_FD - 1

class SelectServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	void Run()
	{
		fd_set readfds; //读文件描述符集
		int fd_array[NUM]; //保存需要被监视读事件是否就绪的文件描述符
		ClearFdArray(fd_array, NUM, DFL_FD); //将数组中的所有位置设置为无效
		fd_array[0] = _listen_sock; //将监听套接字添加到fd_array数组中的第0个位置
		for (;;){
			FD_ZERO(&readfds); //清空readfds
			//将fd_array数组当中的文件描述符添加到readfds当中，并记录最大的文件描述符
			int maxfd = DFL_FD;
			for (int i = 0; i < NUM; i++){
				if (fd_array[i] == DFL_FD) //跳过无效的位置
					continue;
				FD_SET(fd_array[i], &readfds); //将有效位置的文件描述符添加到readfds当中
				if (fd_array[i] > maxfd) //更新最大文件描述符
					maxfd = fd_array[i];
			}
			switch (select(maxfd + 1, &readfds, nullptr, nullptr, nullptr)){
				case 0:
					std::cout<<"timeout..."<<std::endl;
					break;
				case -1:
					std::cerr << "select error" << std::endl;
					break;
				default:
					//正常的事件处理
					std::cout<<"有事件发生..."<<std::endl;
					//HandlerEvent(readfds, fd_array, NUM);
					break;
			}//end switch
		}//end for
	}
private:
	void ClearFdArray(int fd_array[], int num, int default_fd)
	{
		for (int i = 0; i < num; i++){
			fd_array[i] = default_fd;
		}
	}
};
```

**说明一下：** 为了测试timeout不同取值时的不同效果，当有事件就绪时这里先只打印一句提示语句。

> timeout测试

在运行服务器时需要先实例化一个SelectServer类对象，对select服务器进行初始化后就可以调用Run成员函数运行服务器了。

代码如下：

```cpp
#include "select_server.hpp"
#include <string>

static void Usage(std::string proc)
{
	std::cerr << "Usage: " << proc << " port" << std::endl;
}
int main(int argc, char* argv[])
{
	if (argc != 2){
		Usage(argv[0]);
		exit(1);
	}
	int port = atoi(argv[1]);

	SelectServer* svr = new SelectServer(port);
	svr->InitSelectServer();
	svr->Run();
	
	return 0;
}
```

由于当前服务器调用select函数时直接将timeout设置为了nullptr，因此select函数调用后会进行阻塞等待。而服务器在第一次调用select函数时只让select监视监听套接字的读事件，所以运行服务器后如果没有客户端发来连接请求，那么读事件就不会就绪，而服务器则会一直在第一次调用的select函数中进行阻塞等待。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/1fbf8740fae948249cf2be4cfbff84ff-1681699909021200.png)  
当我们借助telnet工具向select服务器发起连接请求后，select函数就会立马检测到监听套接字的读事件就绪，此时select函数便会成功返回，并将我们设置的提示语句进行打印输出，因为当前程序并没有对就绪事件进行处理，此后每次select函数一调用就会检测到读事件就绪并成功返回，因此会看到屏幕不断打印输出提示语句。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/07099f9369ce4322afa4aaef2e524931-1681699976434225.png)
如果服务器在调用select函数时将timeout的值设置为0，那么select函数调用后就会进行非阻塞等待，无论被监视的文件描述符上的事件是否就绪，select检测后都会立即返回。

此时如果select监视的文件描述符上有事件就绪，那么select函数的返回值就是大于0的，如果select监视的文件描述符上没有事件就绪，那么select的返回值就是等于0的。

```cpp
struct timeval timeout = { 0, 0 }; //每隔0秒timeout一次
switch (select(maxfd + 1, &readfds, nullptr, nullptr, &timeout)){
	case 0:
		std::cout << "timeout..." << std::endl;
		break;
	case -1:
		std::cerr << "select error" << std::endl;                                   
		break;
	default:
		//正常的事件处理                                                          
		std::cout << "有事件发生..." << std::endl;
		//HandlerEvent(readfds, fd_array, NUM);                                   
		break;
}
```

运行服务器后如果没有客户端发来连接请求，那么select服务器就会一直调用select函数进行轮询检测，但每次检测时读事件都不就绪，因此每次select函数的返回值都是0，因此就会不断打印“timeout…”提示语句。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/03c819ab7147424695feed120f8756e1-1681699909021206.png)  
当有客户端发来连接请求后，select在某次轮询检测时就会检测到监听套接字的读事件就绪，此时select函数便会成功返回，并将我们设置的提示语句进行打印输出。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/07099f9369ce4322afa4aaef2e524931-1681699994764228.png) 
如果服务器在调用select函数时将timeout的值设置为特定的时间值，比如我们这里将timeout的值设置为5秒，那么select函数调用后的5秒内会进行阻塞等待，如果5秒后依旧没有读事件就绪，那么select函数将会进行超时返回。

我们可以将select函数超时返回和成功返回时timeout的值进行打印，以验证timeout是一个输入输出型参数。

```cpp
struct timeval timeout = { 5, 0 }; //每隔5秒timeout一次
switch (select(maxfd + 1, &readfds, nullptr, nullptr, &timeout)){
case 0:
	std::cout << "timeout: " << timeout.tv_sec << std::endl;
	break;
case -1:
	std::cerr << "select error" << std::endl;
	break;
default:
	//正常的事件处理                                                          
	std::cout << "有事件发生... timeout: " << timeout.tv_sec << std::endl;
	//HandlerEvent(readfds, fd_array, NUM);                                   
	break;
}
```

运行服务器后如果没有客户端发来连接请求，那么每次select函数调用5秒后都会进行超时返回，并且每次打印输出timeout的值都是0，也就意味着timeout的时间是被耗尽了的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/62c54fb95fe542a0abbcfbd1721fb4c4-1681699909021205.png)  

当有客户端发来连接请求后，在某次调用select函数时就会检测到监听套接字的读事件就绪，此时select函数便会成功返回，并将我们设置的提示语句进行打印输出。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/84e45460a8484c76b1b14d279f7d643c-1681700016839231.png)  

因为当前程序并没有对就绪事件进行处理，因此在第一次select检测到读事件就绪后，之后每次select函数一调用就会检测到读事件就绪并成功返回，因此会看到屏幕不断打印输出提示语句，并且后续打印输出timeout的值都是4，表示本次select检测到读事件就绪时timeout的剩余时间为4秒。

因为timeout和readfds、writefds与exceptfds一样，它们都是输入输出型参数，因此如果要使用timeout参数，那么在每次调用select函数之前也都需要对timeout的值进行重新设置。

> 事件处理

当select检测到有文件描述符的读事件就绪并成功返回后，接下来就应该对就绪事件进行处理了，这里编写一个HandlerEvent函数，当读事件就绪后就调用该函数进行事件处理。

+   在进行事件处理时需要遍历fd\_array数组当中的文件描述符，依次判断各个文件描述符对应的读事件是否就绪，如果就绪则需要进行事件处理。
+   当一个文件描述符的读事件就绪后，还需要进一步判断该文件描述符是否是监听套接字，如果是监听套接字的读事件就绪，那么就应该调用accept函数将底层的连接获取上来。但是光光调用accept将连接获取上来还不够，为了下一次调用select函数时能够让select帮我们监视新连接的读事件是否就绪，在连接获取上来后还应该将该连接对应的文件描述符添加到fd\_array数组当中，这样在下一次调用select函数前对readfds重新设置时就能将该文件描述符添加进去了。
+   如果是与客户端建立的连接对应的读事件就绪，那么就应该调用read函数读取客户端发来的数据，如果读取成功则将读到的数据在服务器端进行打印。如果调用read函数读取失败或者客户端关闭了连接，那么select服务器也应该调用close函数关闭对应的连接，但此时光光关闭连接也是不够的，还应该将该连接对应的文件描述符从fd\_array数组当中清除，否则后续调用的select函数还会帮我们监视该连接的读事件是否就绪，但实际已经不需要了。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <sys/select.h>

#define BACK_LOG 5
#define NUM 1024
#define DFL_FD - 1

class SelectServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	void HandlerEvent(const fd_set& readfds, int fd_array[], int num)
	{
		for (int i = 0; i < num; i++){
			if (fd_array[i] == DFL_FD){ //跳过无效的位置
				continue;
			}
			if (fd_array[i] == _listen_sock&&FD_ISSET(fd_array[i], &readfds)){ //连接事件就绪
				//获取连接
				struct sockaddr_in peer;
				memset(&peer, 0, sizeof(peer));
				socklen_t len = sizeof(peer);
				int sock = accept(_listen_sock, (struct sockaddr*)&peer, &len);
				if (sock < 0){ //获取连接失败
					std::cerr << "accept error" << std::endl;
					continue;
				}
				std::string peer_ip = inet_ntoa(peer.sin_addr);
				int peer_port = ntohs(peer.sin_port);
				std::cout << "get a new link[" << peer_ip << ":" << peer_port << "]" << std::endl;

				if (!SetFdArray(fd_array, num, sock)){ //将获取到的套接字添加到fd_array当中
					close(sock);
					std::cout << "select server is full, close fd: " << sock << std::endl;
				}
			}
			else if (FD_ISSET(fd_array[i], &readfds)){ //读事件就绪
				char buffer[1024];
				ssize_t size = read(fd_array[i], buffer, sizeof(buffer)-1);
				if (size > 0){ //读取成功
					buffer[size] = '\0';
					std::cout << "echo# " << buffer << std::endl;
				}
				else if (size == 0){ //对端连接关闭
					std::cout << "client quit" << std::endl;
					close(fd_array[i]);
					fd_array[i] = DFL_FD; //将该文件描述符从fd_array中清除
				}
				else{
					std::cerr << "read error" << std::endl;
					close(fd_array[i]);
					fd_array[i] = DFL_FD; //将该文件描述符从fd_array中清除
				}
			}
		}
	}
private:
	bool SetFdArray(int fd_array[], int num, int fd)
	{
		for (int i = 0; i <num; i++){
			if (fd_array[i] == DFL_FD){ //该位置没有被使用
				fd_array[i] = fd;
				return true;
			}
		}
		return false; //fd_array数组已满
	}
};
```

**说明一下：**

+   当调用accept函数从底层获取上来连接后，不能立即调用read函数读取该连接当中的数据，因为此时新连接当中的数据可能并没有就绪，如果直接调用read函数可能需要进行阻塞等待，我们应该将这个等待过程交给select函数来完成，因此在获取完连接后直接将该连接对应的文件描述符添加到fd\_array数组当中就行了，当该连接的读事件就绪时select函数会告知我们，那个时候我们再进行数据读取就不会被阻塞住了。
+   添加文件描述符到fd\_array数组当中，本质就是遍历fd\_array数组，找到一个没有被使用的位置将该文件描述符添加进去即可。但有可能fd\_array数组中全部的位置都已经被占用了，那么文件描述符就会添加失败，此时就只能将刚刚获取上来的连接对应的套接字进行关闭，因为此时服务器已经没有能力处理这个连接了。

> select服务器测试

至此select服务器编写完毕，重新编译后运行服务器，并用telnet工具连接我们的服务器，此时通过telnet向服务器发送的数据就能够被服务器读到并且打印输出了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/b8ce70df5a4e4e279fbe46c3b2f610e9-1681699909021208.png)  
此外，虽然当前的select服务器是一个单进程的服务器，但它却可以同时为多个客户端提供服务，根本原因就是因为select函数调用后会告知select服务器是哪个客户端对应的连接事件就绪了，此时select服务器就可以读取对应客户端发来的数据，读取完后又会调用select函数等待某个客户端连接的读事件就绪。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/17632c4e40124afc90db8ae68d7dabf1-1681700034064234.png) 
当服务器检测到客户端退出后，也会关闭对应的连接，并将对应的套接字从fd\_array数组当中清除。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/e2ce0b30bac046f78ea11999462888d8-1681700041753237.png)

> 存在的一些问题

当前的select服务器实际还存在一些问题：

+   服务器没有对客户端发进行响应。select服务器如果要向客户端发送数据，不能直接调用write函数，因为调用write函数时实际也分为“等”和“拷贝”两步，我们也应该将“等”的这个过程交给select函数，因此在每次调用select函数之前，除了需要重新设置readfds还需要重新设置writefds，并且还需要一个数组来保存需要被监视写事件是否就绪的文件描述符，当某一文件描述符的写事件就绪时我们才能够调用write函数向客户端发送数据。
+   没有定制协议。代码中读取数据时并没有按照某种规则进行读取，此时就可能造成粘包问题，根本原因就是因为我们没有定制协议，比如HTTP协议规定在读取底层数据时读取到空行就表明读完了一个HTTP报头，此时再根据HTTP报头当中的Content-Length属性得知正文的长度，最终就能够读取到一个完整的HTTP报文，HTTP协议通过这种方式就避免了粘包问题。
+   没有对应的输入输出缓冲区。代码中直接将读取的数据存储到了字符数组buffer当中，这是不严谨的，因为本次数据读取可能并没有读取到一个完整的报文，此时服务器就不能进行数据的分析处理，应该将读取到的数据存储到一个输入缓冲区当中，当读取到一个完整的报文后再让服务器进行处理。此外，如果服务器要能够对客户端进行响应，那么服务器的响应数据也不应该直接调用write函数发送给客户端，应该先存储到一个输出缓冲区当中，因为响应数据可能很庞大，无法一次发送完毕，可能需要进行分批发送。

### select的优点

+   可以同时等待多个文件描述符，并且只负责等待，实际的IO操作由accept、read、write等接口来完成，这些接口在进行IO操作时不会被阻塞。
+   select同时等待多个文件描述符，因此可以将“等”的时间重叠，提高了IO的效率。

当然，这也是所有多路转接接口的优点。

### select的缺点

+   每次调用select，都需要手动设置fd集合，从接口使用角度来说也非常不便。
+   每次调用select，都需要把fd集合从用户态拷贝到内核态，这个开销在fd很多时会很大。
+   同时每次调用select都需要在内核遍历传递进来的所有fd，这个开销在fd很多时也很大。
+   select可监控的文件描述符数量太少。

> select可监控的文件描述符个数

调用select函数时传入的readfds、writefds以及exceptfds都是fd\_set结构的，fd\_set结构本质是一个位图，它用每一个比特位来标记一个文件描述符，因此select可监控的文件描述符个数是取决于fd\_set类型的比特位个数的。

我们可以通过以下代码来看看fd\_set类型有多少个比特位。

```cpp
#include <iostream>
#include <sys/types.h>

int main()
{
	std::cout << sizeof(fd_set)* 8 << std::endl;
	return 0;
}
```

运行代码后可以看到，其实select可监控的文件描述符个数就是1024个。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/0912c0f06d5a43d3a8b72250b2297c19-1681699909022210.png)  
因此我们实现的select服务器当中将fd\_array数组的大小设置为1024是足够的，因为readfds当中最多就只能添加1024个文件描述符，但不同环境下fd\_set的大小可能是不同的，并且fd\_set的大小也是可以调整的（涉及重新编译内核），因此之前select服务器当中对NUM的宏定义正确写法应该是这样的。

```cpp
#define NUM (sizeof(fd_set)*8)
```

> 一个进程能打开的文件描述符个数

进程控制块task\_struct当中有一个files指针，该指针指向一个struct files\_struct结构，进程的文件描述符表fd\_array就存储在该结构当中，其中文件描述符表fd\_array的大小定义为`NR_OPEN_DEFAULT`，`NR_OPEN_DEFAULT`的值实际就是32。

但并不意味着一个进程最多只能打开32个文件描述符，进程能打开的文件描述符个数实际是可以扩展的，比如我当前使用的云服务器默认就是把进程能打开的文件描述符设置得很高的，通过`ulimit -a`命令就可以看到进程能打开的文件描述符上限。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/9bdf13c5cdae4b5097c7d414c89765b8.png)  
因此select可监控的文件描述符个数太少是一个很大的问题，比如select可监控的文件描述符个数是1024，除去其中的一个监听套接字，那么select服务器最多只能连接1023个客户端。

### select的适用场景

多路转接接口select、poll和epoll，需要在一定的场景下使用，如果场景选择的不适宜，可能会适得其反。

+   多路转接接口一般适用于多连接，且多连接中只有少部分连接比较活跃。因为少量连接比较活跃，也就意味着几乎所有的连接在进行IO操作时，都需要花费大量时间来等待事件就绪，此时使用多路转接接口就可以将这些等的事件进行重叠，提高IO效率。
+   对于多连接中大部分连接都很活跃的场景，其实并不适合使用多路转接。因为每个连接都很活跃，也就意味着任何时刻每个连接上的事件基本都是就绪的，此时根本不需要动用多路转接接口来帮我们进行等待，毕竟使用多路转接接口也是需要花费系统的时间和空间资源的。

多连接中只有少量连接是比较活跃的，比如聊天工具，我们登录QQ后大部分时间其实是没有聊天的，此时服务器端不可能调用一个read函数阻塞等待读事件就绪。

多连接中大部分连接都很活跃，比如企业当中进行数据备份时，两台服务器之间不断在交互数据，这时的连接是特别活跃的，几乎不需要等的过程，也就没必要使用多路转接接口了。



## I/O多路转接之poll

### poll初识

poll也是系统提供的一个多路转接接口。

+   poll系统调用也可以让我们的程序同时监视多个文件描述符上的事件是否就绪，和select的定位是一样的，适用场景也是一样的。

### poll函数

> poll函数

poll函数的函数原型如下：

```cpp
#include<poll.h>
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
```

参数说明：

+   fds：一个poll函数监视的结构列表，每一个元素包含三部分内容：文件描述符、监视的事件集合、就绪的事件集合。
+   nfds：表示fds数组的长度。
+   timeout：表示poll函数的超时时间，单位是毫秒（ms）。

参数timeout的取值：

+   \-1：poll调用后进行阻塞等待，直到被监视的某个文件描述符上的某个事件就绪。
+   0：poll调用后进行非阻塞等待，无论被监视的文件描述符上的事件是否就绪，poll检测后都会立即返回。
+   特定的时间值：poll调用后在指定的时间内进行阻塞等待，如果被监视的文件描述符上一直没有事件就绪，则在该时间后poll进行超时返回。

返回值说明：

+   如果函数调用成功，则返回有事件就绪的文件描述符个数。
+   如果timeout时间耗尽，则返回0。
+   如果函数调用失败，则返回-1，同时错误码会被设置。

poll调用失败时，错误码可能被设置为：

+   `EFAULT`：fds数组不包含在调用程序的地址空间中。
+   `EINTR`：此调用被信号所中断。
+   `EINVAL`：nfds值超过RLIMIT\_NOFILE值。
+   `ENOMEM`：核心内存不足。

> struct pollfd结构

**struct pollfd结构**当中包含三个成员：

+   fd：特定的文件描述符，若设置为负值则忽略events字段并且revents字段返回0。
+   events：需要监视该文件描述符上的哪些事件。
+   revents：poll函数返回时告知用户该文件描述符上的哪些事件已经就绪。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/60fb8e020b654f6cade8a1dc98299846.png)  
events和revents的取值：

| 事件       | 描述                                                        | 是否可作为输入 | 是否可作为输出 |
| ---------- | ----------------------------------------------------------- | -------------- | -------------- |
| POLLIN     | 数据（包括普通数据和优先数据）可读                          | 是             | 是             |
| POLLRDNORM | 普通数据可读                                                | 是             | 是             |
| POLLRDBAND | 优先级带数据可读（Linux不支持）                             | 是             | 是             |
| POLLPRI    | 高优先级数据可读，比如TCP带外数据                           | 是             | 是             |
| POLLOUT    | 数据（包括普通数据和优先数据）可写                          | 是             | 是             |
| POLLWRNORM | 普通数据可写                                                | 是             | 是             |
| POLLWRBAND | 优先级带数据可写                                            | 是             | 是             |
| POLLRDHUP  | TCP连接被对方关闭，或者对方关闭了写操作，它由GNU引入        | 是             | 是             |
| POLLERR    | 错误                                                        | 否             | 是             |
| POLLHUP    | 挂起。比如管道的写端被关闭后，读端描述符上将收到POLLHUP事件 | 否             | 是             |
| POLLNVAL   | 文件描述符没有打开                                          | 否             | 是             |

这些取值实际都是以宏的方式进行定义的，它们的二进制序列当中有且只有一个比特位是1，且为1的比特位是各不相同的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/1d74d4cda93a45ee87f47ff92c498919.png)

+   因此在调用poll函数之前，可以通过或运算符将要监视的事件添加到events成员当中。
+   在poll函数返回后，可以通过与运算符检测revents成员中是否包含特定事件，以得知对应文件描述符的特定事件是否就绪。

### poll服务器

poll的工作流程和select是基本类似的，这里我们也实现一个简单poll服务器，该服务器也只是读取客户端发来的数据并进行打印。

> PollServer类

PollServer类当中也只需要包含监听套接字和端口号两个成员变量，在poll服务器绑定时直接将IP地址设置为INADDR\_ANY尽即可。

+   在构造PollServer对象时，需要指明poll服务器的端口号，当然也可以在初始化poll服务器的时候指明。
+   在初始化poll服务器的时候调用Socket类当中的函数，依次进行套接字的创建、绑定和监听即可，这里的Socket类和之前实现的一模一样。
+   在析构函数中可以选择调用close函数将监听套接字进行关闭，但实际也可以不进行该动作，因为服务器运行后一般是不退出的。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <poll.h>

#define BACK_LOG 5

class PollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	PollServer(int port)
		: _port(port)
	{}
	void InitPollServer()
	{
		_listen_sock = Socket::SocketCreate();
		Socket::SocketBind(_listen_sock, _port);
		Socket::SocketListen(_listen_sock, BACK_LOG);
	}
	~PollServer()
	{
		if (_listen_sock >= 0){
			close(_listen_sock);
		}
	}
};
```

> 运行服务器

服务器初始化完毕后就可以开始运行了，而poll服务器要做的就是不断调用poll函数，当事件就绪时对应执行某种动作即可。

+   首先，在poll服务器开始死循环调用poll函数之前，需要定义一个fds数组，该数组当中的每个位置都是一个struct pollfd结构，后续调用poll函数时会作为参数进行传入。先将fds数组当中每个位置初始化为无效，并将监听套接字添加到fds数组当中，表示服务器刚开始运行时只需要监视监听套接字的读事件。
+   此后，poll服务器就不断调用poll函数监视读事件是否就绪。如果poll函数的返回值大于0，则说明poll函数调用成功，此时已经有文件描述符的读事件就绪，接下来就应该对就绪事件进行处理。如果poll函数的返回值等于0，则说明timeout时间耗尽，此时直接准备进行下一次poll调用即可。如果poll函数的返回值为-1，则说明poll调用失败，此时也让服务器准备进行下一次poll调用，但实际应该进一步判断错误码，根据错误码来判断是否应该继续调用poll函数。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <poll.h>

#define BACK_LOG 5
#define NUM 1024
#define DFL_FD - 1

class PollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	void Run()
	{
		struct pollfd fds[NUM];
		ClearPollfds(fds, NUM, DFL_FD); //清空数组中的所有位置
		SetPollfds(fds, NUM, _listen_sock); //将监听套接字添加到数组中，并关心其读事件
		for (;;){
			switch (poll(fds, NUM, -1)){
			case 0:
				std::cout << "timeout..." << std::endl;
				break;
			case -1:
				std::cerr << "poll error" << std::endl;
				break;
			default:
				//正常的事件处理
				//std::cout<<"有事件发生..."<<std::endl;
				HandlerEvent(fds, NUM);
				break;
			}
		}
	}
private:
	void ClearPollfds(struct pollfd fds[], int num, int default_fd)
	{
		for (int i = 0; i < num; i++){
			fds[i].fd = default_fd;
			fds[i].events = 0;
			fds[i].revents = 0;
		}
	}
	bool SetPollfds(struct pollfd fds[], int num, int fd)
	{
		for (int i = 0; i < num; i++){
			if (fds[i].fd == DFL_FD){ //该位置没有被使用
				fds[i].fd = fd;
				fds[i].events |= POLLIN; //添加读事件到events当中
				return true;
			}
		}
		return false; //fds数组已满
	}
};
```

> 事件处理

当poll检测到有文件描述符的读事件就绪，就会在其对应的struct pollfd结构中的revents成员中添加读事件并返回，接下来poll服务器就应该对就绪事件进行处理了，事件处理过程如下：

+   首先遍历fds数组中的每个struct pollfd结构，如果该结构当中的fd有效，且revents当中包含读事件，则说明该文件描述符的读事件就绪，接下来就需要进一步判断该文件描述符是监听套接字还是与客户端建立的套接字。
+   如果是监听套接字的读事件就绪，则调用accept函数将底层建立好的连接获取上来，并将获取到的套接字添加到fds数组当中，表示下一次调用poll函数时需要监视该套接字的读事件。
+   如果是与客户端建立的连接对应的读事件就绪，则调用read函数读取客户端发来的数据，并将读取到的数据在服务器端进行打印。
+   如果在调用read函数时发现客户端将连接关闭或read函数调用失败，则poll服务器也直接关闭对应的连接，并将该连接对应的文件描述符从fds数组当中清除，表示下一次调用poll函数时无需再监视该套接字的读事件。

代码如下：

```cpp
#pragma once

#include "socket.hpp"
#include <poll.h>

#define BACK_LOG 5
#define NUM 1024
#define DFL_FD - 1

class PollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
public:
	void HandlerEvent(struct pollfd fds[], int num)
	{
		for (int i = 0; i < num; i++){
			if (fds[i].fd == DFL_FD){ //跳过无效的位置
				continue;
			}
			if (fds[i].fd == _listen_sock&&fds[i].revents&POLLIN){ //连接事件就绪
				struct sockaddr_in peer;
				memset(&peer, 0, sizeof(peer));
				socklen_t len = sizeof(peer);
				int sock = accept(_listen_sock, (struct sockaddr*)&peer, &len);
				if (sock < 0){ //获取连接失败
					std::cerr << "accept error" << std::endl;
					continue;
				}
				std::string peer_ip = inet_ntoa(peer.sin_addr);
				int peer_port = ntohs(peer.sin_port);
				std::cout << "get a new link[" << peer_ip << ":" << peer_port << "]" << std::endl;
				
				if (!SetPollfds(fds, NUM, sock)){ //将获取到的套接字添加到fds数组中，并关心其读事件
					close(sock);
					std::cout << "poll server is full, close fd: " << sock << std::endl;
				}
			}
			else if (fds[i].revents&POLLIN){ //读事件就绪
				char buffer[1024];
				ssize_t size = read(fds[i].fd, buffer, sizeof(buffer)-1);
				if (size > 0){ //读取成功
					buffer[size] = '\0';
					std::cout << "echo# " << buffer << std::endl;
				}
				else if (size == 0){ //对端连接关闭
					std::cout << "client quit" << std::endl;
					close(fds[i].fd);
					UnSetPollfds(fds, i); //将该文件描述符从fds数组中清除
				}
				else{
					std::cerr << "read error" << std::endl;
					close(fds[i].fd);
					UnSetPollfds(fds, i); //将该文件描述符从fds数组中清除
				}
			}
		}
	}
private:
	bool SetPollfds(struct pollfd fds[], int num, int fd)
	{
		for (int i = 0; i < num; i++){
			if (fds[i].fd == DFL_FD){ //该位置没有被使用
				fds[i].fd = fd;
				fds[i].events |= POLLIN; //添加读事件到events当中
				return true;
			}
		}
		return false; //fds数组已满
	}
	void UnSetPollfds(struct pollfd fds[], int pos)
	{
		fds[pos].fd = DFL_FD;
		fds[pos].events = 0;
		fds[pos].revents = 0;
	}
};
```

**说明一下：**

+   因为这里将fds数组的大小是固定设置的，因此在将新获取连接对应的文件描述符添加到fds数组时，可能会因为fds数组已满而添加失败，这时poll服务器只能将刚刚获取上来的连接对应的套接字进行关闭。

> poll服务器测试

运行poll服务器时也需要先实例化出一个PollServer对象，对poll服务器进行初始化后就可以运行服务器了。

代码如下：

```cpp
#include "poll_server.hpp"
#include <string>

static void Usage(std::string proc)
{
	std::cerr << "Usage: " << proc << " port" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 2){
		Usage(argv[0]);
		exit(1);
	}
	int port = atoi(argv[1]);
	PollServer* svr = new PollServer(port);
	svr->InitPollServer();
	svr->Run();
	
	return 0;
}
```

因为我们编写的poll服务器在调用poll函数时，将timeout的值设置成了-1，因此运行服务器后如果没有客户端发来连接请求，那么服务器就会在调用poll函数后进行阻塞等待。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/173a6f03090b423bbd8fd801af0f6a01-1681700117728249.png)当我们用telnet工具连接poll服务器后，poll服务器调用的poll函数在检测到监听套接字的读事件就绪后就会调用accept获取建立好的连接，并打印输出客户端的IP和端口号，此时客户端发来的数据也能够成功被poll服务器收到并进行打印输出。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/9c4f5cfd396747bfa1deeed8612e0b44-1681700087132241.png)  
此外，poll服务器也是一个单进程服务器，但是它也可以同时为多个客户端提供服务。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/9e6ac1b75787493d8fcfe9c46c131004-1681700125217252.png)当服务器端检测到客户端退出后，也会关闭对应的连接，并将对应的套接字从fds数组当中清除。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/e92d932693484eafb8047c3e0a4fb494-1681700131442255.png)

### poll的优点

+   struct pollfd结构当中包含了events和revents，相当于将select的输入输出型参数进行分离，因此在每次调用poll之前，不需要像select一样重新对参数进行设置。
+   poll可监控的文件描述符数量没有限制。
+   当然，poll也可以同时等待多个文件描述符，能够提高IO的效率。

**说明一下：**

+   虽然代码中将fds数组的元素个数定义为1024，但fds数组的大小是可以继续增大的，poll函数能够帮你监视多少个文件描述符是由传入poll函数的第二个参数决定的。
+   而fd\_set类型只有1024个比特位，因此select函数最多只能监视1024个文件描述符。

### poll的缺点

+   和select函数一样，当poll返回后，需要遍历fds数组来获取就绪的文件描述符。
+   每次调用poll，都需要把大量的struct pollfd结构从用户态拷贝到内核态，这个开销也会随着poll监视的文件描述符数目的增多而增大。
+   同时每次调用poll都需要在内核遍历传递进来的所有fd，这个开销在fd很多时也很大。



## I/O多路转接之epoll

### epoll初识

epoll也是系统提供的一个多路转接接口。

+   epoll系统调用也可以让我们的程序同时监视多个文件描述符上的事件是否就绪，与select和poll的定位是一样的，适用场景也相同。
+   epoll在命名上比poll多了一个e，这个e可以理解成是extend，epoll就是为了同时处理大量文件描述符而改进的poll。
+   epoll在2.5.44内核中被引进，它几乎具备了select和poll的所有优点，被公认为Linux2.6下性能最好的多路I/O就绪通知方法。

### epoll的相关系统调用

epoll有三个相关的系统调用，分别是epoll\_create、epoll\_ctl和epoll\_wait。

> epoll\_create函数

epoll\_create函数用于创建一个epoll模型，该函数的函数原型如下：

```cpp
int epoll_create(int size);
```

参数说明：

+   size：自从Linux2.6.8之后，size参数是被忽略的，但size的值必须设置为大于0的值。

返回值说明：

+   epoll模型创建成功返回其对应的文件描述符，否则返回-1，同时错误码会被设置。

**注意：** 当不再使用时，必须调用close函数关闭epoll模型对应的文件描述符，当所有引用epoll实例的文件描述符都已关闭时，内核将销毁该实例并释放相关资源。

> epoll\_ctl函数

epoll\_ctl函数用于向指定的epoll模型中注册事件，该函数的函数原型如下：

```cpp
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
```

参数说明：

+   epfd：指定的epoll模型。
+   op：表示具体的动作，用三个宏来表示。
+   fd：需要监视的文件描述符。
+   event：需要监视该文件描述符上的哪些事件。

第二个参数op的取值有以下三种：

+   `EPOLL_CTL_ADD`：注册新的文件描述符到指定的epoll模型中。
+   `EPOLL_CTL_MOD`：修改已经注册的文件描述符的监听事件。
+   `EPOLL_CTL_DEL`：从epoll模型中删除指定的文件描述符。

返回值说明：

+   函数调用成功返回0，调用失败返回-1，同时错误码会被设置。

第四个参数对应的struct epoll\_event结构如下：  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/2ae44bc55ab84a368a4fba05adbabb71.png)  
struct epoll\_event结构中有两个成员，第一个成员events表示的是需要监视的事件，第二个成员data是一个联合体结构，一般选择使用该结构当中的fd，表示需要监听的文件描述符。

events的常用取值如下：

+   `EPOLLIN`：表示对应的文件描述符可以读（包括对端SOCKET正常关闭）。
+   `EPOLLOUT`：表示对应的文件描述符可以写。
+   `EPOLLPRI`：表示对应的文件描述符有紧急的数据可读（这里应该表示有带外数据到来）。
+   `EPOLLERR`：表示对应的文件描述符发送错误。
+   `EPOLLHUP`：表示对应的文件描述符被挂断，即对端将文件描述符关闭了。
+   `EPOLLET`：将epoll的工作方式设置为边缘触发（Edge Triggered）模式。
+   `EPOLLONESHOT`：只监听一次事件，当监听完这次事件之后，如果还需要继续监听该文件描述符的话，需要重新将该文件描述符添加到epoll模型中。

这些取值实际也是以宏的方式进行定义的，它们的二进制序列当中有且只有一个比特位是1，且为1的比特位是各不相同的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/21d412ab52324b3fae7c23f6b396d59e.png)

> epoll\_wait函数

epoll\_ctl函数用于收集监视的事件中已经就绪的事件，该函数的函数原型如下：

```cpp
int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
```

参数说明：

+   epfd：指定的epoll模型。
+   events：内核会将已经就绪的事件拷贝到events数组当中（events不能是空指针，内核只负责将就绪事件拷贝到该数组中，不会帮我们在用户态中分配内存）。
+   maxevents：events数组中的元素个数，该值不能大于创建epoll模型时传入的size值。
+   timeout：表示epoll\_wait函数的超时时间，单位是毫秒（ms）。

参数timeout的取值：

+   \-1：epoll\_wait调用后进行阻塞等待，直到被监视的某个文件描述符上的某个事件就绪。
+   0：epoll\_wait调用后进行非阻塞等待，无论被监视的文件描述符上的事件是否就绪，epoll\_wait检测后都会立即返回。
+   特定的时间值：epoll\_wait调用后在直到的时间内进行阻塞等待，如果被监视的文件描述符上一直没有事件就绪，则在该时间后epoll\_wait进行超时返回。

返回值说明：

+   如果函数调用成功，则返回有事件就绪的文件描述符个数。
+   如果timeout时间耗尽，则返回0。
+   如果函数调用失败，则返回-1，同时错误码会被设置。

epoll\_wait调用失败时，错误码可能被设置为：

+   `EBADF`：传入的epoll模型对应的文件描述符无效。
+   `EFAULT`：events指向的数组空间无法通过写入权限访问。
+   `EINTR`：此调用被信号所中断。
+   `EINVAL`：epfd不是一个epoll模型对应的文件描述符，或传入的maxevents值小于等于0。

### epoll工作原理

> 红黑树和就绪队列

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/8dbb3e7f37d9441ea301c3601bdcfbba.png)  

当某一进程调用epoll\_create函数时，Linux内核会创建一个eventpoll结构体，也就是我们所说的epoll模型，eventpoll结构体当中的成员rbr和rdlist与epoll的使用方式密切相关。

```cpp
struct eventpoll{
	...
	//红黑树的根节点，这棵树中存储着所有添加到epoll中的需要监视的事件
	struct rb_root rbr;
	//就绪队列中则存放着将要通过epoll_wait返回给用户的满足条件的事件
	struct list_head rdlist;
	...
}
```

+   epoll模型当中的红黑树本质就是告诉内核，需要监视哪些文件描述符上的哪些事件，调用epll\_ctl函数实际就是在对这颗红黑树进行对应的增删改操作。
+   epoll模型当中的就绪队列本质就是告诉内核，哪些文件描述符上的哪些事件已经就绪了，调用epoll\_wait函数实际就是在从就绪队列当中获取已经就绪的事件。

在epoll中，对于每一个事件都会有一个对应的epitem结构体，红黑树和就绪队列当中的节点分别是基于epitem结构中的rbn成员和rdllink成员的，epitem结构当中的成员ffd记录的是指定的文件描述符值，event成员记录的就是该文件描述符对应的事件。

```cpp
struct epitem{
	struct rb_node rbn; //红黑树节点
	struct list_head rdllink; //双向链表节点
	struct epoll_filefd ffd; //事件句柄信息
	struct eventpoll *ep; //指向其所属的eventpoll对象
	struct epoll_event event; //期待发生的事件类型
}
```

+   对于epitem结构当中rbn成员来说，ffd与event的含义是，需要监视ffd上的event事件是否就绪。
+   对于epitem结构当中的rdlink成员来说，ffd与event的含义是，ffd上的event事件已经就绪了。

**说明一下：**

+   红黑树是一种二叉搜索树，因此必须有键值key，而这里的文件描述符就天然的可以作为红黑树的key值。
+   调用epoll\_ctl向红黑树当中新增节点时，如果设置了`EPOLLONESHOT`选项，当监听完这次事件后，如果还需要继续监听该文件描述符则需要重新将其添加到epoll模型中，本质就是当设置了`EPOLLONESHOT`选项的事件就绪时，操作系统会自动将其从红黑树当中删除。
+   而如果调用epoll\_ctl向红黑树当中新增节点时没有设置`EPOLLONESHOT`，那么该节点插入红黑树后就会一直存在，除非用户调用epoll\_ctl将该节点从红黑树当中删除。

> 回调机制

所有添加到红黑树当中的事件，都会与设备（网卡）驱动程序建立回调方法，这个回调方法在内核中叫ep\_poll\_callback。

+   对于select和poll来说，操作系统在监视多个文件描述符上的事件是否就绪时，需要让操作系统主动对这多个文件描述符进行轮询检测，这一定会增加操作系统的负担。
+   而对于epoll来说，操作系统不需要主动进行事件的检测，当红黑树中监视的事件就绪时，会自动调用对应的回调方法，将就绪的事件添加到就绪队列当中。
+   当用户调用epoll\_wait函数获取就绪事件时，只需要关注底层就绪队列是否为空，如果不为空则将就绪队列当中的就绪事件拷贝给用户即可。

采用回调机制最大的好处，就是不再需要操作系统主动对就绪事件进行检测了，当事件就绪时会自动调用对应的回调函数进行处理。

**说明一下：**

+   只有添加到红黑树当中的事件才会与底层建立回调方法，因此只有当红黑树当中对应的事件就绪时，才会执行对应的回调方法将其添加到就绪队列当中。
+   当不断有监视的事件就绪时，会不断调用回调方法向就绪队列当中插入节点，而上层也会不断调用epoll\_wait函数从就绪队列当中获取节点，这是典型的生产者消费者模型。
+   由于就绪队列可能会被多个执行流同时访问，因此必须要使用互斥锁对其进行保护，eventpoll结构当中的lock和mtx就是用于保护临界资源的，因此epoll本身是线程安全的。
+   eventpoll结构当中的wq（wait queue）就是等待队列，当多个执行流想要同时访问同一个epoll模型时，就需要在该等待队列下进行等待。

> epoll三部曲

总结一下，epoll的使用过程就是三部曲：

+   **调用epoll\_create创建一个epoll模型。**
+   **调用epoll\_ctl，将要监控的文件描述符进行注册。**
+   **调用epoll\_wait，等待文件描述符就绪。**

### epoll服务器

[epoll简单实现]([LINUX/IOPLUS/epoll at main · tianen1573/LINUX · GitHub](https://github.com/tianen1573/LINUX/tree/main/IOPLUS/epoll))

为了简单演示一下epoll的使用方式，这里我们也实现一个简单的epoll服务器，该服务器也只是读取客户端发来的数据并进行打印。

> EpollServer类

EpollServer类当中除了需要包含监听套接字和端口号两个成员变量之外，最好将epoll模型对应的文件描述符也作为一个成员变量。

+   在构造EpollServer对象时，需要指明epoll服务器的端口号，当然也可以在初始化epoll服务器的时候指明。
+   在初始化epoll服务器的时候调用Socket类当中的函数，依次进行套接字的创建、绑定和监听，此外epoll模型的创建可以在服务器初始化的时候进行。
+   在析构函数中调用close函数，将监听套接字和epoll模型对应的文件描述符进行关闭。

代码如下：

```cpp
#include "socket.hpp"
#include <sys/epoll.h>

#define BACK_LOG 5
#define SIZE 256

class EpollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
	int _epfd; //epoll模型
public:
	EpollServer(int port)
		: _port(port)
	{}
	void InitEpollServer()
	{
		_listen_sock = Socket::SocketCreate();
		Socket::SocketBind(_listen_sock, _port);
		Socket::SocketListen(_listen_sock, BACK_LOG);
		
		//创建epoll模型
		_epfd = epoll_create(SIZE);
		if (_epfd < 0){
			std::cerr << "epoll_create error" << std::endl;
			exit(5);
		}
	}
	~EpollServer()
	{
		if (_listen_sock >= 0){
			close(_listen_sock);
		}
		if (_epfd >= 0){
			close(_epfd);
		}
	}
};
```

> 运行服务器

服务器初始化完毕后就可以开始运行了，而epoll服务器要做的就是不断调用epoll\_wait函数，从就绪队列当中获取就绪事件进行处理即可。

+   首先，在epoll服务器开始死循环调用epoll\_wait函数之前，需要先调用epoll\_ctl将监听套接字添加到epoll模型当中，表示服务器刚开始运行时只需要监视监听套接字的读事件。
+   此后，epoll服务器就不断调用epoll\_wait函数监视读事件是否就绪。如果epoll\_wait函数的返回值大于0，则说明已经有文件描述符的读事件就绪，并且此时的返回值代表的就是有事件就绪的文件描述符个数，接下来就应该对就绪事件进行处理。
+   如果epoll\_wait函数的返回值等于0，则说明timeout时间耗尽，此时直接准备进行下一次epoll\_wait调用即可。如果epoll\_wait函数的返回值为-1，此时也让服务器准备进行下一次epoll\_wait调用，但实际应该进一步判断错误码，根据错误码来判断是否应该继续调用epoll\_wait函数。

代码如下：

```cpp
#include "socket.hpp"
#include <sys/epoll.h>

#define BACK_LOG 5
#define SIZE 256
#define MAX_NUM 64

class EpollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
	int _epfd; //epoll模型
public:
	void Run()
	{
		AddEvent(_listen_sock, EPOLLIN); //将监听套接字添加到epoll模型中，并关心其读事件
		for (;;){
			struct epoll_event revs[MAX_NUM];
			int num = epoll_wait(_epfd, revs, MAX_NUM, -1);
			if (num < 0){
				std::cerr << "epoll_wait error" << std::endl;
				continue;
			}
			else if (num == 0){
				std::cout << "timeout..." << std::endl;
				continue;
			}
			else{
				//正常的事件处理
				//std::cout<<"有事件发生..."<<std::endl;
				HandlerEvent(revs, num);
			}
		}
	}
private:
	void AddEvent(int sock, uint32_t event)
	{
		struct epoll_event ev;
		ev.events = event;
		ev.data.fd = sock;
		
		epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev);
	}
};
```

**说明一下：**

+   默认情况下，只要底层有就绪事件没有处理，epoll也会一直通知用户，也就是调用epoll\_wait会一直成功返回，并将就绪的事件拷贝到我们传入的数组当中。
+   需要注意的是，所谓的事件处理并不是调用epoll\_wait将底层就绪队列中的就绪事件拷贝到用户层，比如当这里的读事件就绪后，我们应该调用accept获取底层建立好的连接，或调用recv读取客户端发来的数据，这才算是将读事件处理了。
+   如果我们仅仅是调用epoll\_wait将底层就绪队列当中的事件拷贝到应用层，那么这些就绪事件实际并没有被处理掉，底层注册的回调函数会被再次调用，将就绪的事件重新添加到就绪队列当中，本质原因就是我们实际并没有对底层就绪的数据进行读取。

> 事件处理

如果底层就绪队列当中有就绪事件，那么调用epoll\_wait函数时就会将底层就绪队列中的事件拷贝到用户提供的revs数组当中，接下来epoll服务器就应该对就绪事件进行处理了，事件处理过程如下：

+   根据调用epoll\_wait时得到的返回值，来判断操作系统向revs数组中拷贝了多少个struct epoll\_event结构，进而对这些文件描述符上的事件进行处理。
+   对于每一个拷贝上来的struct epoll\_event结构，如果该结构当中的events当中包含读事件，则说明该文件描述符对应的读事件就绪，但接下来还需要进一步判断该文件描述符是监听套接字还是与客户端建立的套接字。
+   如果是监听套接字的读事件就绪，则调用accept函数将底层建立好的连接获取上来，并调用epoll\_ctl函数将获取到的套接字添加到epoll模型当中，表示下一次调用epoll\_wait函数时需要监视该套接字的读事件。
+   如果是与客户端建立的连接对应的读事件就绪，则调用recv函数读取客户端发来的数据，并将读取到的数据在服务器端进行打印。
+   如果在调用recv函数时发现客户端将连接关闭或recv函数调用失败，则epoll服务器也直接关闭对应的连接，并调用epoll\_ctl函数将该连接对应的文件描述符从epoll模型中删除，表示下一次调用epoll\_wait函数时无需再监视该套接字的读事件。

代码如下：

```cpp
#include "socket.hpp"
#include <sys/epoll.h>

#define BACK_LOG 5
#define SIZE 256
#define MAX_NUM 64

class EpollServer{
private:
	int _listen_sock; //监听套接字
	int _port; //端口号
	int _epfd; //epoll模型
public:
	void HandlerEvent(struct epoll_event revs[], int num)
	{
		for (int i = 0; i < num; i++){
			int fd = revs[i].data.fd; //就绪的文件描述符
			if (fd == _listen_sock&&revs[i].events&EPOLLIN){ //连接事件就绪
				struct sockaddr_in peer;
				memset(&peer, 0, sizeof(peer));
				socklen_t len = sizeof(peer);
				int sock = accept(_listen_sock, (struct sockaddr*)&peer, &len);
				if (sock < 0){ //获取连接失败
					std::cerr << "accept error" << std::endl;
					continue;
				}
				std::string peer_ip = inet_ntoa(peer.sin_addr);
				int peer_port = ntohs(peer.sin_port);
				std::cout << "get a new link[" << peer_ip << ":" << peer_port << "]" << std::endl;
				
				AddEvent(sock, EPOLLIN); //将获取到的套接字添加到epoll模型中，并关心其读事件
			}
			else if (revs[i].events&EPOLLIN){ //读事件就绪
				char buffer[64];
				ssize_t size = recv(fd, buffer, sizeof(buffer)-1, 0);
				if (size > 0){ //读取成功
					buffer[size] = '\0';
					std::cout << "echo# " << buffer << std::endl;
				}
				else if (size == 0){ //对端连接关闭
					std::cout << "client quit" << std::endl;
					close(fd);
					DelEvent(fd); //将文件描述符从epoll模型中删除
				}
				else{
					std::cerr << "recv error" << std::endl;
					close(fd);
					DelEvent(fd); //将文件描述符从epoll模型中删除
				}
			}
		}
	}
private:
	void AddEvent(int sock, uint32_t event)
	{
		struct epoll_event ev;
		ev.events = event;
		ev.data.fd = sock;
		
		epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev);
	}
	void DelEvent(int sock)
	{
		epoll_ctl(_epfd, EPOLL_CTL_DEL, sock, nullptr);
	}
};
```

> epoll服务器测试

运行epoll服务器时需要先实例化出一个EpollServer对象，对epoll服务器进行初始化后就可以运行服务器了。

代码如下：

```cpp
#include "epoll_server.hpp"
#include <string>

static void Usage(std::string proc)
{
	std::cout << "Usage: " << proc << " port" << std::endl;
}
int main(int argc, char* argv[])
{
	if (argc != 2){
		Usage(argv[0]);
		exit(1);
	}
	int port = atoi(argv[1]);

	EpollServer* svr = new EpollServer(port);
	svr->InitEpollServer();
	svr->Run();
	
	return 0;
}
```

因为编写epoll服务器在调用epoll\_wait函数时，我们将timeout的值设置成了-1，因此运行服务器后如果没有客户端发来连接请求，那么服务器就会在调用epoll\_wait函数后进行阻塞等待。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/58441814537d48729a1e0dfe4a74d28a-1681700215922272.png) 
当我们用telnet工具连接epoll服务器后，epoll服务器调用的epoll\_wait函数在检测到监听套接字的读事件就绪后就会调用accept获取建立好的连接，并打印输出客户端的IP和端口号，此时客户端发来的数据也能够成功被epoll服务器收到并进行打印输出。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/81a0a7790bd54fb0865381111eaf647e-1681700167860258.png)  
此外，我们这里编写的也是一个单进程的epoll服务器，但是它可以同时为多个客户端提供服务。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/fb7ffb3c2d074476b2b944f975985a21-1681700230268275.png) 
我们可以用`ls /proc/PID/fd`命令，查看当前epoll服务器的文件描述符的使用情况。其中文件描述符0、1、2是默认打开的，分别对应的是标准输入、标准输出和标准错误，3号文件描述符对应的是监听套接字，4号文件描述符对应的是服务器创建的epoll模型，5号和6号文件描述符对应的分别是正在访问服务器的两个客户端。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/c267f4130e8c4e1b9d57d44d3d997df4-1681700243363278.png) 
当服务器端检测到客户端退出后，也会关闭对应的连接，此时epoll服务器对应的5号和6号文件描述符就关闭了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/63361c3c02124c04aa9494781aa60db3-1681700251621281.png)

### epoll的优点

+   接口使用方便：虽然拆分成了三个函数，但是反而使用起来更方便高效。
+   数据拷贝轻量：只在新增监视事件的时候调用epoll\_ctl将数据从用户拷贝到内核，而select和poll每次都需要重新将需要监视的事件从用户拷贝到内核。此外，调用epoll\_wait获取就绪事件时，只会拷贝就绪的事件，不会进行不必要的拷贝操作。
+   事件回调机制：避免操作系统主动轮询检测事件就绪，而是采用回调函数的方式，将就绪的文件描述符结构加入到就绪队列中。调用epoll\_wait时直接访问就绪队列就知道哪些文件描述符已经就绪，检测是否有文件描述符就绪的时间复杂度是 O ( 1 ) O(1) O(1)，因为本质只需要判断就绪队列是否为空即可。
+   没有数量限制：监视的文件描述符数目无上限，只要内存允许，就可以一直向红黑树当中新增节点。

**注意：**

+   有人说epoll中使用了内存映射机制，内核可以直接将底层就绪队列通过mmap的方式映射到用户态，此时用户就可以直接读取到内核中就绪队列当中的数据，避免了内存拷贝的额外性能开销。
+   这种说法是错误的，实际操作系统并没有做任何映射机制，因为操作系统是不相信任何人的，操作系统不会让用户进程直接访问到内核的数据的，用户只能通过系统调用来获取内核的数据。
+   因此用户要获取内核当中的数据，势必还是需要将内核的数据拷贝到用户空间。

> 与select和poll的不同之处

+   在使用select和poll时，都需要借助第三方数组来维护历史上的文件描述符以及需要监视的事件，这个第三方数组是由用户自己维护的，对该数组的增删改操作都需要用户自己来进行。
+   而使用epoll时，不需要用户自己维护所谓的第三方数组，epoll底层的红黑树就充当了这个第三方数组的功能，并且该红黑树的增删改操作都是由内核维护的，用户只需要调用epoll\_ctl让内核对该红黑树进行对应的操作即可。
+   在使用多路转接接口时，数据流都有两个方向，一个是用户告知内核，一个是内核告知用户。select和poll将这两件事情都交给了同一个函数来完成，而epoll在接口层面上就将这两件事进行了分离，epoll通过调用epoll\_ctl完成用户告知内核，通过调用epoll\_wait完成内核告知用户。

### epoll工作方式

epoll有两种工作方式，分别是水平触发工作模式和边缘触发工作模式。

> 水平触发（LT，Level Triggered）

+   只要底层有事件就绪，epoll就会一直通知用户。
+   就像数字电路当中的高电平触发一样，只要一直处于高电平，则会一直触发。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/b5d68a623e534d29b2157acea6e05ffc.png)  

epoll默认状态下就是LT工作模式。

+   由于在LT工作模式下，只要底层有事件就绪就会一直通知用户，因此当epoll检测到底层读事件就绪时，可以不立即进行处理，或者只处理一部分，因为只要底层数据没有处理完，下一次epoll还会通知用户事件就绪。
+   select和poll其实就是工作是LT模式下的。
+   支持阻塞读写和非阻塞读写。

> 边缘触发（ET，Edge Triggered）

+   只有底层就绪事件数量由无到有或由有到多发生变化的时候，epoll才会通知用户。
+   就像数字电路当中的上升沿触发一样，只有当电平由低变高的那一瞬间才会触发。

![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/0511566fcc15496db9d514e6b509fedc.png)  

如果要将epoll改为ET工作模式，则需要在添加事件时设置`EPOLLET`选项。

+   由于在ET工作模式下，只有底层就绪事件无到有或由有到多发生变化的时候才会通知用户，因此当epoll检测到底层读事件就绪时，必须立即进行处理，而且必须全部处理完毕，因为有可能此后底层再也没有事件就绪，那么epoll就再也不会通知用户进行事件处理，此时没有处理完的数据就相当于丢失了。
+   ET工作模式下epoll通知用户的次数一般比LT少，因此ET的性能一般比LT性能更高，Nginx就是默认采用ET模式使用epoll的。
+   只支持非阻塞的读写。

> ET工作模式下应该如何进行读写

因为在ET工作模式下，只有底层就绪事件无到有或由有到多发生变化的时候才会通知用户，这就**倒逼用户当读事件就绪时必须一次性将数据全部读取完毕，当写事件就绪时必须一次性将发送缓冲区写满，否则可能再也没有机会进行读写了。**

因此读数据时**必须循环调用**recv函数进行读取，写数据时必须循环调用send函数进行写入。

+   当底层读事件就绪时，循环调用recv函数进行读取，直到某次调用recv读取时，实际读取到的字节数小于期望读取的字节数，则说明本次底层数据已经读取完毕了。
+   但有可能最后一次调用recv读取时，刚好实际读取的字节数和期望读取的字节数相等，但此时底层数据也恰好读取完毕了，如果我们再调用recv函数进行读取，那么recv就会因为底层没有数据而被阻塞住。
+   而这里的阻塞是非常严重的，就比如我们这里写的服务器都是单进程的服务器，如果recv被阻塞住，并且此后该数据再也不就绪，那么就相当于我们的服务器挂掉了，因此在ET工作模式下循环调用recv函数进行读取时，必须将对应的文件描述符设置为非阻塞状态。
+   调用send函数写数据时也是同样的道理，需要循环调用send函数进行数据的写入，并且必须将对应的文件描述符设置为非阻塞状态。

**强调：** **ET工作模式下，recv和send操作的文件描述符必须设置为非阻塞状态，这是必须的，不是可选的**。

### 对比LT和ET

+   在ET模式下，一个文件描述符就绪之后，用户不会反复收到通知，看起来比LT更高效，**但如果在LT模式下能够做到每次都将就绪的文件描述符立即全部处理，不让操作系统反复通知用户的话，其实LT和ET的性能也是一样的**。
+   此外，ET的编程难度比LT更高。

![image-20230503145651024](%E5%9B%BE%E7%89%87/Linux/image-20230503145651024.png)

## Reactor模式

### Reactor模式的定义

[ Reactor 模式（单 Reactor 单线程、单 Reactor 多线程、主从 Reactor 多线程)](https://blog.csdn.net/Woo_home/article/details/106119218)

Reactor反应器模式，也叫做分发者模式或通知者模式，是一种将就绪事件派发给对应服务处理程序的事件设计模式。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/951abb25ee82475d9ebf3ad6a7f29696.png)

### Reactor模式的角色构成

Reactor主要由以下五个角色构成：

| 角色                                             | 解释                                                         |
| ------------------------------------------------ | ------------------------------------------------------------ |
| Handle（句柄）                                   | 用于标识不同的事件，本质就是一个文件描述符。                 |
| Sychronous Event Demultiplexer（同步事件分离器） | 本质就是一个系统调用，用于等待事件的发生。对于Linux来说，同步事件分离器指的就是I/O多路复用，比如select、poll、epoll等。 |
| Event Handler（事件处理器）                      | 由多个回调方法构成，这些回调方法构成了与应用相关的对于某个事件的处理反馈。 |
| Concrete Event Handler（具体事件处理器）         | 事件处理器中各个回调方法的具体实现。                         |
| Initiation Dispatcher（初始分发器）              | 初始分发器实际上就是Reactor角色，初始分发器会通过同步事件分离器来等待事件的发生，当对应事件就绪时就调用事件处理器，最后调用对应的回调方法来处理这个事件。 |

### Reactor模式的工作流程

Reactor模式的工作流程如下：

1.  当应用向初始分发器注册具体事件处理器时，应用会标识出该事件处理器希望初始分发器在某个事件发生时向其通知，该事件与Handle关联。
2.  初始分发器会要求每个事件处理器向其传递内部的Handle，该Handle向操作系统标识了事件处理器。
3.  当所有的事件处理器注册完毕后，应用会启动初始分发器的事件循环，这时初始分发器会将每个事件处理器的Handle合并起来，并使用同步事件分离器等待这些事件的发生。
4.  当某个事件处理器的Handle变为Ready状态时，同步事件分离器会通知初始分发器。
5.  初始分发器会将Ready状态的Handle作为key，来寻找其对应的事件处理器。
6.  初始分发器会调用其对应事件处理器当中对应的回调方法来响应该事件。

## epoll ET服务器（Reactor模式）

如果在此之前没有了解过Reactor模式，相信在看了Reactor模式的工作流程后一定是一头雾水，下面我们实现一个Reactor模式下的epoll ET服务器，来感受一下Reactor模式。

### 设计思路

> epoll ET服务器

在epoll ET服务器中，我们需要处理如下几种事件：

+   读事件：如果是监听套接字的读事件就绪则调用accept函数获取底层的连接，如果是其他套接字的读事件就绪则调用recv函数读取客户端发来的数据。
+   写事件：写事件就绪则将待发送的数据写入到发送缓冲区当中。
+   异常事件：当某个套接字的异常事件就绪时我们不做过多处理，直接关闭该套接字。

当epoll ET服务器监测到某一事件就绪后，就会将该事件交给对应的服务处理程序进行处理。

> Reactor模式的五个角色

在这个epoll ET服务器中，Reactor模式中的五个角色对应如下：

+   句柄：文件描述符。
+   同步事件分离器：I/O多路复用epoll。
+   事件处理器：包括读回调、写回调和异常回调。
+   具体事件处理器：读回调、写回调和异常回调的具体实现。
+   初始分发器：Reactor类当中的Dispatcher函数。

Dispatcher函数要做的就是调用epoll\_wait函数等待事件发生，当有事件发生后就将就绪的事件派发给对应的服务处理程序即可。

> EventItem类

+   在Reactor的工作流程中说到，在注册事件处理器时需要将其与Handle关联，本质上就是需要将读回调、写回调和异常回调与某个文件描述符关联起来。
+   这样做的目的就是为了当某个文件描述符上的事件就绪时可以找到其对应的各种回调函数，进而执行对应的回调方法来处理该事件。

所以我们可以设计一个EventItem类，该类当中的成员就包括一个文件描述符，以及该文件描述符对应的各种回调函数，此外还有一些其他成员，后面实现的时候再做详细论述。

> Reactor类

+   在Reactor的工作流程中说到，当所有事件处理器注册完毕后，会使用同步事件分离器等待这些事件发生，当某个事件处理器的Handle变为Ready状态时，同步事件分离器会通知初始分发器，然后初始分发器会将Ready状态的Handle作为key来寻找其对应的事件处理器，并调用该事件处理器中对应的回调方法来响应该事件。
+   本质就是当事件注册完毕后，会调用epoll\_wait函数来等待这些事件发生，当某个事件就绪时epoll\_wait函数会告知调用方，然后调用方就根据就绪的文件描述符来找到其对应的各种回调函数，并调用对应的回调函数进行事件处理。

对此我们可以设计一个Reactor类。

+   该类当中有一个成员函数叫做Dispatcher，这个函数就是所谓的初始分发器，在该函数内部会调用epoll\_wait函数等待事件的发生，当事件发生后会告知Dispatcher已经就绪的事件。
+   当事件就绪后需要根据就绪的文件描述符来找到其对应的各种回调函数，由于我们会将每个文件描述符及其对应的各种回调都封装到一个EventItem结构当中，所以实际我们就是需要根据文件描述符找到其对应的EventItem结构。
+   我们可以使用C++ STL当中的unordered\_map，来建立各个文件描述符与其对应的EventItem结构之间的映射，这个unordered\_map可以作为Reactor类的一个成员变量，当需要找某个文件描述符的EventItem结构时就可以通过该成员变量找到。
+   当然，Reactor类当中还需要提供成员函数AddEvent和DelEvent，用于向Dispatcher当中注册和删除事件。

此外，在Reactor类当中还有一些其他成员，后面实现的时候再做详细论述。

> epoll ET服务器的工作流程

这个epoll ET服务器在Reactor模式下的工作流程如下：

+   首先epoll ET服务器需要进行套接字的创建、绑定和监听。
+   然后定义一个Reactor对象并初始化，初始化时要做的就是创建epoll模型。
+   紧接着需要为监听套接字创建对应的EventItem结构，并调用Reactor类中提供的AddEvent函数将监听套接字添加到epoll模型中，并建立监听套接字与其对应的EventItem结构之间的映射关系。
+   之后就可以不断调用Reactor类中的Dispatcher函数进行事件派发。

在事件处理过程中，会不断向Dispatcher当中新增或删除事件，而每个事件就绪时都会自动调用其对应的回调函数进行处理，所以我们要做的就是不断调用Dispatcher函数进行事件派发即可。

### EventItem结构

EventItem结构中除了包含文件描述符和其对应的读回调、写回调和异常回调之外，还包含一个输入缓冲区inbuffer、一个输出缓冲区outbuffer以及一个回指指针R。

+   当某个文件描述符的读事件就绪时，我们会调用recv函数读取客户端发来的数据，但我们并不能保证我们读取到了一个完整的报文，因此需要将读取到的数据暂时存放到该文件描述符对应的inbuffer当中，当inbuffer当中可以分离出一个完整的报文后再将其分离出来进行数据处理，这里的inbuffer本质就是用来解决粘包问题的。
+   当处理完一个报文请求后，需要将响应数据发送给客户端，但我们并不能保证底层TCP的发送缓冲区中有足够的空间供我们写入，因此需要将要发送的数据暂时存放到该文件描述符对应的outbuffer当中，当底层TCP的发送缓冲区中有空间，即写事件就绪时，再依次发送outbuffer当中的数据。
+   EventItem结构当中设置回指指针R，便于快速找到我们定义的Reactor对象，因为后续我们需要根据EventItem结构找到这个Reactor对象。比如当连接事件就绪时，需要调用Reactor类当中的AddEvent函数将其添加到Dispatcher当中。

此外，EventItem结构当中需要提供一个管理回调的成员函数，便于外部对EventItem结构当中的各种回调进行设置。

代码如下：

```cpp
typedef int(*callback_t)(EventItem*);

class EventItem{
public:
	int _sock; //文件描述符
	Reactor* _R; //回指指针

	callback_t _recv_handler; //读回调
	callback_t _send_handler; //写回调
	callback_t _error_handler; //异常回调

	std::string _inbuffer; //输入缓冲区
	std::string _outbuffer; //输出缓冲区
public:
	EventItem()
		: _sock(-1)
		, _R(nullptr)
		, _recv_handler(nullptr)
		, _send_handler(nullptr)
		, _error_handler(nullptr)
	{}
	//管理回调
	void ManageCallbacks(callback_t recv_handler, callback_t send_handler, callback_t error_handler)
	{
		_recv_handler = recv_handler;
		_send_handler = send_handler;
		_error_handler = error_handler;
	}
	~EventItem()
	{}
};
```

### Reactor类

在Reactor类当中有一个unordered\_map成员，用于建立文件描述符和与其对应的EventItem结构之间的映射，还有一个epfd成员，该成员是epoll模型对应的文件描述符。

+   在初始化Reactor对象的时候就可以调用epoll\_create函数创建epoll模型，并将该epoll模型对应的文件描述符用epfd成员记录下来，便于后续使用。
+   Reactor对象在析构的时候，需要调用close函数将该epoll模型进行关闭。

代码如下：

```cpp
#define SIZE 256

class Reactor{
private:
	int _epfd; //epoll模型
	std::unordered_map<int, EventItem> _event_items; //建立sock与EventItem结构的映射
public:
	Reactor()
		: _epfd(-1)
	{}
	void InitReactor()
	{
		//创建epoll模型
		_epfd = epoll_create(SIZE);
		if (_epfd < 0){
			std::cerr << "epoll_create error" << std::endl;
			exit(5);
		}
	}
	~Reactor()
	{
		if (_epfd >= 0){
			close(_epfd);
		}
	}
};
```

#### Dispatcher函数（事件分派器）

Reactor类当中的Dispatcher函数就是之前所说的初始分发器，这里我们更形象的将其称之为事件分派器。

+   事件分派器要做的就是调用epoll\_wait函数等待事件发生。
+   当某个文件描述符上的事件发生后，先通过unordered\_map找到该文件描述符对应的EventItem结构，然后调用EventItem结构当中对应的回调函数对该事件进行处理即可。

代码如下：

```cpp
#define MAX_NUM 64

class Reactor{
private:
	int _epfd; //epoll模型
	std::unordered_map<int, EventItem> _event_items; //建立sock与EventItem结构的映射
public:
	//事件分派器
	void Dispatcher(int timeout)
	{
		struct epoll_event revs[MAX_NUM];
		int num = epoll_wait(_epfd, revs, MAX_NUM, timeout);
		for (int i = 0; i < num; i++){
			int sock = revs[i].data.fd; //就绪的文件描述符
			if ((revs[i].events&EPOLLERR) || (revs[i].events&EPOLLHUP)){ //异常事件就绪（优先处理）
				if (_event_items[sock]._error_handler)
					_event_items[sock]._error_handler(&_event_items[sock]); //调用异常回调
			}
			if (revs[i].events&EPOLLIN){ //读事件就绪
				if (_event_items[sock]._recv_handler)
					_event_items[sock]._recv_handler(&_event_items[sock]); //调用读回调
			}
			if (revs[i].events&EPOLLOUT){ //写事件就绪
				if (_event_items[sock]._send_handler)
					_event_items[sock]._send_handler(&_event_items[sock]); //调用写回调
			}
		}
	}
};
```

**说明一下：**

+   这里没有用switch或if语句对epoll\_wait函数的返回值进行判断，而是借用for循环对其返回值进行了判断。
+   如果epoll\_wait的返回值为-1则说明epoll\_wait函数调用失败，此时不会进入到for循环内部进行事件处理。
+   如果epoll\_wait的返回值为0则说明epoll\_wait函数超时返回，此时也不会进入到for循环内部进行事件处理。
+   如果epoll\_wait的返回值大于0则说明epoll\_wait函数调用成功，此时才会进入到for循环内部调用对应的回调函数对事件进行处理。
+   事件处理时最好先对异常事件进行处理，因此代码中将异常事件的判断放在了最前面。

#### AddEvent函数

Reactor类当中的AddEvent函数是用于进行事件注册的。

+   在注册事件时需要传入一个文件描述符和一个事件集合，表示需要监视哪个文件描述符上的哪些事件。
+   还需要传入该文件描述符对应的EventItem结构，表示当该文件描述符上的事件就绪后应该执行的回调方法。
+   在AddEvent函数内部要做的就是，调用epoll\_ctl函数将该文件描述符及其对应的事件集合注册到epoll模型当中，然后建立该文件描述符与其对应的EventItem结构的映射关系。

代码如下：

```cpp
class Reactor{
private:
	int _epfd; //epoll模型
	std::unordered_map<int, EventItem> _event_items; //建立sock与EventItem结构的映射
public:
	void AddEvent(int sock, uint32_t event, const EventItem& item)
	{
		struct epoll_event ev;
		ev.data.fd = sock;
		ev.events = event;
		
		if (epoll_ctl(_epfd, EPOLL_CTL_ADD, sock, &ev) < 0){ //将该文件描述符添加到epoll模型当中
			std::cerr << "epoll_ctl add error, fd: " << sock << std::endl;
		}
		else{
			//建立sock与EventItem结构的映射关系
			_event_items.insert({ sock, item });
			std::cout << "添加: " << sock << " 到epoll模型中，成功" << std::endl;
		}
	}
};
```

#### DelEvent函数

Reactor类当中的DelEvent函数是用于进行事件删除的。

+   在删除事件时只需要传入一个文件描述符即可。
+   在DelEvent函数内部要做的就是，调用epoll\_ctl函数将该文件描述符从epoll模型中删除，并取消该文件描述符与其对应的EventItem结构的映射关系。

代码如下：

```cpp
class Reactor{
private:
	int _epfd; //epoll模型
	std::unordered_map<int, EventItem> _event_items; //建立sock与EventItem结构的映射
public:
	void DelEvent(int sock)
	{
		if (epoll_ctl(_epfd, EPOLL_CTL_DEL, sock, nullptr) < 0){ //将该文件描述符从epoll模型中删除
			std::cerr << "epoll_ctl del error, fd: " << sock << std::endl;
		}
		else{
			//取消sock与EventItem结构的映射关系
			_event_items.erase(sock);
			std::cout << "从epoll模型中删除: " << sock << "，成功" << std::endl;
		}
	}
};
```

#### EnableReadWrite函数

Reactor类当中的EnableReadWrite函数，用于使能或使能某个文件描述符的读写事件。

+   调用EnableReadWrite函数时需要传入一个文件描述符，表示需要设置的是哪个文件描述符对应的事件。
+   还需要传入两个bool值，分别表示需要使能还是使能读写事件。
+   EnableReadWrite函数内部会调用epoll\_ctl函数修改将该文件描述符的监听事件。

代码如下：

```cpp
class Reactor{
private:
	int _epfd; //epoll模型
	std::unordered_map<int, EventItem> _event_items; //建立sock与EventItem结构的映射
public:
	void EnableReadWrite(int sock, bool read, bool write){
		struct epoll_event ev;
		ev.data.fd = sock;
		ev.events = (read ? EPOLLIN : 0) | (write ? EPOLLOUT : 0) | EPOLLET;
		if (epoll_ctl(_epfd, EPOLL_CTL_MOD, sock, &ev) < 0){ //修改该文件描述符所需要监视的事件
			std::cerr << "epoll_ctl mod error, fd: " << sock << std::endl;
		}
	}
};
```

### 回调函数

下面我们就可以实现一些回调函数，这里主要实现四个回调函数。

+   accepter：当连接事件到来时可以调用该回调函数获取底层建立好的连接。
+   recver：当读事件就绪时可以调用该回调函数读取客户端发来的数据并进行处理。
+   sender：当写事件就绪时可以调用该回调函数向客户端发送响应数据。
+   errorer：当异常事件就绪时可以调用该函数将对应的文件描述符进行关闭。

当我们为某个文件描述符创建EventItem结构时，就可以调用EventItem类提供的ManageCallbacks函数，将这些回调函数到EventItem结构当中。

+   我们会将监听套接字对应的EventItem结构当中的recv\_handler设置为accepter，因为监听套接字的读事件就绪就意味着连接事件就绪了，而监听套接字一般只关心读事件，因此监听套接字对应的send\_handler和error\_handler可以设置为nullptr。
+   当Dispatcher监测到监听套接字的读事件就绪时，会调用监听套接字对应的EventItem结构当中的recv\_handler回调，此时就会调用accepter回调获取底层建立好的连接。
+   而对于与客户端建立连接的套接字，我们会将其对应的EventItem结构当中的recv\_handler、send\_handler和error\_handler分别设置为这里的recver、sender和error。
+   当Dispatcher监测到这些套接字的事件就绪时，就会调用其对应的EventItem结构当中对应的回调函数，也就是这里的recver、sender和error。

#### accepter回调

accepter回调用于处理连接事件，其工作流程如下：

1.  调用accept函数获取底层建立好的连接。
2.  将获取到的套接字设置为非阻塞，并为其创建EventItem结构，填充EventItem结构当中的各个字段，并注册该套接字相关的回调方法。
3.  将该套接字及其对应需要关心的事件注册到Dispatcher当中。

下一次Dispatcher在进行事件派发时就会帮我们关注该套接字对应的事件，当事件就绪时就会执行该套接字对应的EventItem结构中对应的回调方法。

代码如下：

```cpp
int accepter(EventItem* item)
{
	while (true){
		struct sockaddr_in peer;
		memset(&peer, 0, sizeof(peer));
		socklen_t len = sizeof(peer);
		int sock = accept(item->_sock, (struct sockaddr*)&peer, &len);
		if (sock < 0){
			if (errno == EAGAIN || errno == EWOULDBLOCK){ //并没有读取出错，只是底层没有连接了
				return 0;
			}
			else if (errno == EINTR){ //读取的过程被信号中断了
				continue;
			}
			else{ //获取连接失败
				std::cerr << "accept error" << std::endl;
				return -1;
			}
		}
		SetNonBlock(sock); //将该套接字设置为非阻塞
		//构建EventItem结构
		EventItem sock_item;
		sock_item._sock = sock;
		sock_item._R = item->_R;
		sock_item.ManageCallbacks(recver, sender, errorer); //注册回调方法
		
		Reactor* R = item->_R;
		R->AddEvent(sock, EPOLLIN | EPOLLET, sock_item); //将该套接字及其对应的事件注册到Dispatcher中
	}
	return 0;
}
```

需要注意的是，因为这里实现的ET模式下的epoll服务器，因此在获取底层连接时需要循环调用accept函数进行读取，并且监听套接字必须设置为非阻塞。

+   因为ET模式下只有当底层建立的连接从无到有或是从有到多时才会通知上层，如果没有一次性将底层建立好的连接全部获取，并且此后再也没有建立好的连接，那么底层没有读取完的连接就相当于丢失了，所以需要循环多次调用accept函数获取底层建立好的连接。
+   循环调用accept函数也就意味着，当底层连接全部被获取后再调用accept函数，此时就会因为底层已经没有连接了而被阻塞住，因此需要将监听套接字设置为非阻塞，这样当底层没有连接时accept就会返回，而不会被阻塞住。

accept获取到的新的套接字也需要设置为非阻塞，就是为了避免将来循环调用recv、send等函数时被阻塞。

> 设置文件描述符为非阻塞

设置文件描述符为非阻塞时，需要先调用fcntl函数获取该文件描述符对应的文件状态标记，然后在该文件状态标记的基础上添加非阻塞标记`O_NONBLOCK`，最后调用fcntl函数对该文件描述符的状态标记进行设置即可。

代码如下：

```cpp
//设置文件描述符为非阻塞
bool SetNonBlock(int sock)
{
	int fl = fcntl(sock, F_GETFL);
	if (fl < 0){
		std::cerr << "fcntl error" << std::endl;
		return false;
	}
	fcntl(sock, F_SETFL, fl | O_NONBLOCK);
	return true;
}
```

监听套接字设置为非阻塞后，当底层连接不就绪时，accept函数会以出错的形式返回，因此当调用accept函数的返回值小于0时，需要继续判断错误码。

+   如果错误码为`EAGAIN`或`EWOULDBLOCK`，说明本次出错返回是因为底层已经没有可获取的连接了，此时底层连接全部获取完毕，这时我们可以返回0，表示本次accepter调用成功。
+   如果错误码为`EINTR`，说明本次调用accept函数获取底层连接时被信号中断了，这时还应该继续调用accept函数进行获取。
+   除此之外，才说明accept函数是真正调用失败了，这时我们可以返回-1，表示本次accepter调用失败。

> accept、recv和send等IO系统调用为什么会被信号中断？

IO系统调用函数出错返回并且将错误码设置为`EINTR`，表明本次在进行数据读取或数据写入之前被信号中断了，也就是说IO系统调用在陷入内核，但并没有返回用户态的时候内核跑去处理其他信号了。

+   在内核态返回用户态之前会检查信号的pending位图，也就是未决信号集，如果pending位图中有未处理的信号，那么内核就会对该信号进行处理。
+   但IO系统调用函数在进行IO操作之前就被信号中断了，这实际上是一个特例，因为IO过程分为“等”和“拷贝”两个步骤，而一般“等”的过程比较漫长，而在这个过程中我们的执行流其实是处于闲置的状态的，因此在“等”的过程中如果有信号产生，内核就会立即进行信号的处理。

> 写事件是按需打开的

这里调用accept获取上来的套接字在添加到Dispatcher中时，只添加了`EOPLLIN`和`EPOLLET`事件，也就是说只让epoll帮我们关心该套接字的读事件。

+   这里之所以没有添加写事件，是因为当前我们并没有要发送的数据，因此没有必要让epoll帮我们关心写事件。
+   一般读事件是经常会被设置的，而写事件则是按序打开的，只有当我们有数据要发送时才会将写事件打开，并且在数据全部写入完毕后又会立即将写事件关闭。

#### recver回调

recver回调用于处理读事件，其工作流程如下：

1.  循环调用recv函数读取数据，并将读取到的数据添加到该套接字对应EventItem结构的inbuffer当中。
2.  对inbuffer当中的数据进行切割，将完整的报文切割出来，剩余的留在inbuffer当中。
3.  对切割出来的完整报文进行反序列化。
4.  业务处理。
5.  业务处理后形成响应报文。
6.  将响应报头添加到对应EventItem结构的outbuffer当中，并打开写事件。

下一次Dispatcher在进行事件派发时就会帮我们关注该套接字的写事件，当写事件就绪时就会执行该套接字对应的EventItem结构中写回调方法，进而将outbuffer中的响应数据发送给客户端。

代码如下：

```cpp
int recver(EventItem* item)
{
	if (item->_sock < 0) //该文件描述符已经被关闭
		return -1;
	//1、数据读取
	if (recver_helper(item->_sock, &(item->_inbuffer)) < 0){ //读取失败
		item->_error_handler(item);
		return -1;
	}

	//2、报文切割
	std::vector<std::string> datagrams;
	StringUtil::Split(item->_inbuffer, &datagrams, "X");

	for (auto s : datagrams){
		//3、反序列化
		struct data d;
		StringUtil::Deserialize(s, &d._x, &d._y, &d._op);

		//4、业务处理
		int result = 0;
		switch (d._op)
		{
			case '+':
				result = d._x + d._y;
				break;
			case '-':
				result = d._x - d._y;
				break;
			case '*':
				result = d._x * d._y;
				break;
			case '/':
				if (d._y == 0){
					std::cerr << "Error: div zero!" << std::endl;
					continue; //继续处理下一个报文
				}
				else{
					result = d._x / d._y;
				}
				break;
			case '%':
				if (d._y == 0){
					std::cerr << "Error: mod zero!" << std::endl;
					continue; //继续处理下一个报文
				}
				else{
					result = d._x % d._y;
				}
				break;
			default:
				std::cerr << "operation error!" << std::endl;
				continue; //继续处理下一个报文
		}

		//5、形成响应报文
		std::string response;
		response += std::to_string(d._x);
		response += d._op;
		response += std::to_string(d._y);
		response += "=";
		response += std::to_string(result);
		response += "X"; //报文与报文之间的分隔符
		
		//6、将响应报文添加到outbuffer中
		item->_outbuffer += response;
		if (!item->_outbuffer.empty())
			item->_R->EnableReadWrite(item->_sock, true, true); //打开写事件
	}
	return 0;
}
```

> 一、数据读取

我们可以将循环调用recv函数读取数据的过程封装成一个recver\_helper函数。

+   recver\_helper函数要做的就是循环调用recv函数将读取到的数据添加到inbuffer当中。
+   当recv函数的返回值小于0时同样需要进一步判断错误码，如果错误码为`EAGAIN`或`EWOULDBLOCK`则说明底层数据读取完毕了，如果错误码为`EINTR`则说明读取过程被信号中断了，此时还需要继续调用recv函数进行读取，否则就是读取出错了。
+   当读取出错时直接调用该套接字对应的error\_handler回调，最终就会调用到下面将要实现的errorer回调，在我们会在errorer回调当中将该套接字进行关闭。

代码如下：

```cpp
int recver_helper(int sock, std::string* out)
{
	while (true){
		char buffer[128];
		ssize_t size = recv(sock, buffer, sizeof(buffer)-1, 0);
		if (size < 0){
			if (errno == EAGAIN || errno == EWOULDBLOCK){ //数据读取完毕
				return 0;
			}
			else if (errno == EINTR){ //被信号中断，继续尝试读取
				continue;
			}
			else{ //读取出错
				return -1;
			}
		}
		else if (size == 0){ //对端连接关闭
			return -1;
		}
		//读取成功
		buffer[size] = '\0';
		*out += buffer; //将读取到的数据添加到该套接字对应EventItem结构的inbuffer中
	}
}
```

> 二、报文切割

报文切割本质就是为了防止粘包问题，而粘包问题实际是涉及到协议定制的。

+   因为我们需要根据协议知道如何将各个报文进行分离，比如UDP分离报文采用的就是定长报头+自描述字段。
+   我们的目的是演示整个数据处理的过程，为了简单起见就不进行过于复杂的协议定制了，这里我们就以“X”作为各个报文之间的分隔符，每个报文的最后都会以一个“X”作为报文结束的标志。
+   因此现在要做的就是以“X”作为分隔符对inbuffer当中的字符串进行切割，这里将这个过程封装成一个Split函数并放到一个StringUtil工具类当中。
+   Split函数要做的就是对inbuffer当中的字符串进行切割，将切割出来的一个个报文放到vector当中，对于最后无法切出完整报文的数据就留在inbuffer当中即可。

代码如下：

```cpp
class StringUtil{
public:
	static void Split(std::string& in, std::vector<std::string>* out, std::string sep)
	{
		int start = 0;
		size_t pos = in.find(sep, start);
		while (pos != std::string::npos){
			out->push_back(in.substr(start, pos - start));
			start = pos + sep.size();
			pos = in.find(sep, start);
		}
		in = in.substr(start);
	}
};
```

> 三、反序列化

在数据发送之前需要进行序列化encode，接收到数据之后需要对数据进行反序列化decode。

+   序列化就是将对象的状态信息转换为可以存储或传输的形式（字节序列）的过程。
+   反序列化就是把字节序列恢复为原对象的过程。

实际反序列化也是与协议定制相关的，假设这里的epoll服务器向客户端提供的就是计算服务，客户端向服务器发来的都是需要服务器计算的计算表达式，因此可以用一个结构体来描述这样一个计算表达式，结构体当中包含两个操作数x和y，以及一个操作符op。

```cpp
struct data{
	int _x;
	int _y;
	char _op;
};
```

此时这里所谓的反序列化就是将一个计算表达式转换成这样一个结构体，

+   因此现在要做的就是将形如“1+2”这样的计算表达式转换成一个结构体，该结构体当中的x成员的值就是1，y的值就是2，op的值就是‘+’，这里将这个过程封装成一个Deserialize函数并放到StringUtil工具类当中。
+   Deserialize函数要做的工作其实也很简单，就是在传入的字符串当中找到操作符op，此时操作符左边的就是操作数x，右边的就是操作数y。

代码如下：

```cpp
class StringUtil{
public:
	static void Deserialize(std::string& in, int* x, int* y, char* op)
	{
		size_t pos = 0;
		for (pos = 0; pos < in.size(); pos++){
			if (in[pos] == '+' || in[pos] == '-' || in[pos] == '*' || in[pos] == '/' || in[pos] == '%')
				break;
		}
		if (pos < in.size()){
			std::string left = in.substr(0, pos);
			std::string right = in.substr(pos + 1);

			*x = atoi(left.c_str());
			*y = atoi(right.c_str());
			*op = in[pos];
		}
		else{
			*op = -1;
		}
	}
};
```

**说明一下：** 实际在做项目时不需要我们自己进行序列化和反序列化，我们一般会直接用JSON或XML这样的序列化反序列化工具。

> 四、业务处理

业务处理就是服务器拿到客户端发来的数据后，对数据进行数据分析，最终拿到客户端想要的资源。

+   我们这里要做的业务处理非常简单，就是用反序列化后的数据进行数据计算，此时得到的计算结果就是客户端想要的。

> 五、形成响应报文

在业务处理后我们已经拿到了客户端想要的数据，现在我们要做的就是形成响应报文，由于我们这里规定每个报文都以“X”作为报文结束的标志，因此在形成响应报文的时候，就需要在每一个计算结果后面都添加上一个“X”，表示这是之前某一个请求报文的响应报文，因为协议制定后就需要双方遵守。

> 六、将响应报文添加到outbuffer中

响应报文构建完后需要将其添加到该套接字对应的outbuffer中，并打开该套接字的写事件，此后当写事件就绪时就会将outbuffer当中的数据发送出去。

#### sender回调

sender回调用于处理写事件，其工作流程如下：

1.  循环调用send函数发送数据，并将发送出去的数据从该套接字对应EventItem结构的outbuffer中删除。
2.  如果循环调用send函数后该套接字对应的outbuffer当中的数据被全部发送，此时就需要将该套接字对应的写事件关闭，因为已经没有要发送的数据了，如果outbuffer当中的数据还有剩余，那么该套接字对应的写事件就应该继续打开。

代码如下：

```cpp
int sender(EventItem* item)
{
	if (item->_sock < 0) //该文件描述符已经被关闭
		return -1;

	int ret = sender_helper(item->_sock, item->_outbuffer);
	if (ret == 0){ //全部发送成功，不再关心写事件
		item->_R->EnableReadWrite(item->_sock, true, false);
	}
	else if (ret == 1){ //没有发送完毕，还需要继续关心写事件
		item->_R->EnableReadWrite(item->_sock, true, true);
	}
	else{ //写入出错
		item->_error_handler(item);
	}
	return 0;
}
```

我们可以将循环调用send函数发送数据的过程封装成一个sender\_helper函数。

+   sender\_helper函数要做的就是循环调用send函数将outbuffer中的数据发送出去。
+   当send函数的返回值小于0时也需要进一步判断错误码，如果错误码为`EAGAIN`或`EWOULDBLOCK`则说明底层TCP发送缓冲区已经被写满了，这时需要将已经发送的数据从outbuffer中移除。
+   如果错误码为`EINTR`则说明发送过程被信号中断了，此时还需要继续调用send函数进行发送，否则就是发送出错了。
+   当发送出错时也直接调用该套接字对应的error\_handler回调，最终就会调用到下面将要实现的errorer回调，在我们会在errorer回调当中将该套接字进行关闭。
+   如果最终outbuffer当中的数据全部发送成功，则将outbuffer清空即可。

代码如下：

```cpp
int sender_helper(int sock, std::string& in)
{
	size_t total = 0; //累加已经发送的字节数
	while (true){
		ssize_t size = send(sock, in.c_str() + total, in.size() - total, 0);
		if (size < 0){
			if (errno == EAGAIN || errno == EWOULDBLOCK){ //底层发送缓冲区已经没有空间了
				in.erase(0, total); //将已经发送的数据移出outbuffer
				return 1; //缓冲区写满，没写完
			}
			else if (errno == EINTR){ //被信号中断，继续尝试写入
				continue;
			}
			else{ //写入出错
				return -1;
			}
		}
		total += size;
		if (total >= in.size()){
			in.clear(); //清空outbuffer
			return 0; //全部写入完毕
		}
	}
}
```

#### errorer回调

errorer回调用于处理异常事件。

+   对于异常事件就绪的套接字我们这里不做其他过多的处理，简单的调用close函数将该套接字关闭即可。
+   但是在关闭该套接字之前，需要先调用DelEvent函数将该套接字从epoll模型中删除，并取消该套接字与其对应的EventItem结构的映射关系。
+   由于在Dispatcher当中是先处理的异常事件，为了避免该套接字被关闭后继续进行读写操作，然后因为读写操作失败再次调用errorer回调重复关闭该文件描述符，因此在关闭该套接字后将其EventItem当中的文件描述符值设置为-1。
+   在调用recver和sender回调执行读写操作之前，都会判断该EventItem结构当中的文件描述符值是否有效，如果无效则不会进行后续操作。

代码如下：

```cpp
int errorer(EventItem* item)
{
	item->_R->DelEvent(item->_sock); //将该文件描述符从epoll模型中删除，并取消该文件描述符与其EventItem结构的映射关系
	close(item->_sock); //关闭该文件描述符

	item->_sock = -1; //防止关闭后继续执行读写回调
	return 0;
}
```

### 套接字相关

这里可以编写一个Socket类，对套接字相关的接口进行一定程度的封装，为了让外部能够直接调用Socket类当中封装的函数，于是将这些函数定义成了静态成员函数。

代码如下：

```cpp
class Socket{
public:
	//创建套接字
	static int SocketCreate()
	{
		int sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock < 0){
			std::cerr << "socket error" << std::endl;
			exit(2);
		}
		//设置端口复用
		int opt = 1;
		setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		return sock;
	}
	//绑定
	static void SocketBind(int sock, int port)
	{
		struct sockaddr_in local;
		memset(&local, 0, sizeof(local));
		local.sin_family = AF_INET;
		local.sin_port = htons(port);
		local.sin_addr.s_addr = INADDR_ANY;
		
		socklen_t len = sizeof(local);

		if (bind(sock, (struct sockaddr*)&local, len) < 0){
			std::cerr << "bind error" << std::endl;
			exit(3);
		}
	}
	//监听
	static void SocketListen(int sock, int backlog)
	{
		if (listen(sock, backlog) < 0){
			std::cerr << "listen error" << std::endl;
			exit(4);
		}
	}
};
```

### 运行epoll ET服务器

运行我们的epoll ET服务器的步骤如下：

+   首先需要进行的就是套接字的创建、绑定和监听，因为是ET模式下的epoll服务器，因此监听套接字创建出来后需要将其设置为非阻塞。
+   然后就可以实例化一个Reactor对象，并对其进行初始化，也就是创建epoll模型。
+   紧接着需要为监听套接字定义一个EventItem结构，填充EventItem结构当中的各个字段，并将accepter回调设置为监听套接字的读回调方法。
+   然后调用AddEvent函数将监听套接字及其需要关系的事件添加到Dispatcher当中，该过程包括将监听套接字注册到epoll模型中，以及建立监听套接字与其对应EventItem结构的映射。
+   最后就可以循环调用Reactor类当中的Dispatcher函数进行事件派发了。

代码如下：

```cpp
#include "app_interface.hpp"
#include "reactor.hpp"
#include "socket.hpp"
#include "util.hpp"
#include <string>

#define BACK_LOG 5

static void Usage(std::string proc)
{
	std::cout << "Usage: " << proc << " port" << std::endl;
}
int main(int argc, char* argv[])
{
	if (argc != 2){
		Usage(argv[0]);
		exit(1);
	}
	int port = atoi(argv[1]);

	//服务器监听套接字的创建、绑定和监听
	int listen_sock = Socket::SocketCreate();
	SetNonBlock(listen_sock); //将监听套接字设置为非阻塞
	Socket::SocketBind(listen_sock, port);
	Socket::SocketListen(listen_sock, BACK_LOG);
	
	//创建Reactor，并初始化
	Reactor R;
	R.InitReactor();

	//创建监听套接字对应的EventItem结构            
	EventItem item;
	item._sock = listen_sock;
	item._R = &R;
	item.ManageCallbacks(accepter, nullptr, nullptr); //监听套接字只需要关心读事件
	
	//将监听套接字托管给Dispatcher
	R.AddEvent(listen_sock, EPOLLIN | EPOLLET, item);
	
	//循环进行事件派发
	int timeout = 1000;
	while (true){
		R.Dispatcher(timeout);
	}
	return 0;
}
```

运行服务器后可以看到3号文件描述符被添加到了epoll模型中，这里的3号文件描述符其实就是监听套接字。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/455d9e9dcd0c4e8a8a66b283c322a8ce.png)  
当客户端连接服务器后，在服务器端会显示5号文件描述符被添加到了epoll模型当中，因为4号文件描述符已经被epoll模型使用了。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/a3cce58b64f2469785fdef3a40548c4e-1681700784840295.png)
此时客户端就可以向服务器发送一些简单计算任务，这些计算任务之间用“X”隔开，服务器收到计算请求并处理后就会将计算结果发送给客户端，这些计算结果之间也是用“X”隔开的。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/d1e1e76cedd4405f86e7cf0ec19ccf43-1681700793313298.png)
此外，由于使用了多路转接技术，虽然当前的epoll服务器是一个单进程的服务器，但它却可以同时为多个客户端提供服务。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/5ddf1eda16ff436b8104d268b6bfb5e7-1681700801450301.png)当客户端退出后服务器端也会将对应的文件描述符从epoll模型中删除。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/6d30c23eb6b6444cbb93676b272b8a5f-1681700814056304.png)

### 接入线程池

> 单进程epoll服务器存在的问题

因为当前的epoll服务器的业务处理逻辑比较简单，所以单进程的epoll服务器看起来没什么压力，但如果服务器的业务处理逻辑比较复杂，那么某些客户端发来的数据请求就可能长时间得不到响应，因为这时epoll服务器需要花费大量时间进行业务处理，而在这个过程中服务器无法为其他客户端提供服务。

> 解决思路

可以在当前服务器的基础上接入线程池，当recver回调读取完数据并完成报文的切割和反序列化后，就可以将其构建成一个任务然后放到线程池的任务队列中，然后服务器就可以继续进行事件派发，而不需要将时间耗费到业务处理上面，而放到任务队列当中的任务，则由线程池当中的若干个线程进行处理。

> 接入线程池

线程池的代码如下：

```cpp
#pragma once

#include <iostream>
#include <unistd.h>
#include <queue>
#include <pthread.h>

#define NUM 5

 //线程池
template<class T>
class ThreadPool
{
public:
	//提供一个全局访问点
	static ThreadPool* GetInstance()
	{
		return &_sInst;
	}
private:
	bool IsEmpty()
	{
		return _task_queue.size() == 0;
	}
	void LockQueue()
	{
		pthread_mutex_lock(&_mutex);
	}
	void UnLockQueue()
	{
		pthread_mutex_unlock(&_mutex);
	}
	void Wait()
	{
		pthread_cond_wait(&_cond, &_mutex);
	}
	void WakeUp()
	{
		pthread_cond_signal(&_cond);
	}
public:
	~ThreadPool()
	{
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond);
	}
	//线程池中线程的执行例程
	static void* Routine(void* arg)
	{
		pthread_detach(pthread_self());
		ThreadPool* self = (ThreadPool*)arg;
		//不断从任务队列获取任务进行处理
		while (true){
			self->LockQueue();
			while (self->IsEmpty()){
				self->Wait();
			}
			T task;
			self->Pop(task);
			self->UnLockQueue();

			task.Run(); //处理任务
		}
	}
	void ThreadPoolInit()
	{
		pthread_t tid;
		for (int i = 0; i < _thread_num; i++){
			pthread_create(&tid, nullptr, Routine, this); //注意参数传入this指针
		}
	}
	//往任务队列塞任务（主线程调用）
	void Push(const T& task)
	{
		LockQueue();
		_task_queue.push(task);
		UnLockQueue();
		WakeUp();
	}
	//从任务队列获取任务（线程池中的线程调用）
	void Pop(T& task)
	{
		task = _task_queue.front();
		_task_queue.pop();
	}
private:
	ThreadPool(int num = NUM) //构造函数私有
		: _thread_num(num)
	{
		pthread_mutex_init(&_mutex, nullptr);
		pthread_cond_init(&_cond, nullptr);
	}
	ThreadPool(const ThreadPool&) = delete; //防拷贝

	std::queue<T> _task_queue; //任务队列
	int _thread_num; //线程池中线程的数量
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;

	static ThreadPool<T> _sInst;
};

template<class T>
ThreadPool<T> ThreadPool<T>::_sInst;
```

在服务器开始进行事件派发之前需要对线程池进行初始化：

```cpp
//初始化线程池
ThreadPool<Task>::GetInstance()->ThreadPoolInit();
```

> 设计任务类

线程池有了之后需要定义出一个任务类，该任务类当中需要提供一个Run方法，这个Run方法就是线程池中的若干线程池从任务队列当中拿到任务后会执行的方法。

+   在任务类中包含两个成员变量，成员变量d就是反序列化后用于进行业务处理的数据，成员变量item就是该套接字的EventItem结构，因为数据处理完后需要将形成的响应报文添加到该套接字对应outbuffer当中。
+   Run方法中处理数据的逻辑与之前的一样，只是现在将那部分代码放到了Run方法中。

代码如下：

```cpp
#pragma once

#include <iostream>
#include "reactor.hpp"
#include "comm.hpp"

//任务类
class Task
{
private:
	struct data _d;
	EventItem* _item;
public:
	Task(struct data d, EventItem* item)
		: _d(d), _item(item)
	{}
	Task() //提供默认构造
	{}
	~Task()
	{}
	//处理任务的方法
	void Run()
	{
		//4、业务处理
		int result = 0;
		switch (_d._op)
		{
		case '+':
			result = _d._x + _d._y;
			break;
		case '-':
			result = _d._x - _d._y;
			break;
		case '*':
			result = _d._x * _d._y;
			break;
		case '/':
			if (_d._y == 0){
				std::cerr << "Error: div zero!" << std::endl;
				return;
			}
			else{
				result = _d._x / _d._y;
			}
			break;
		case '%':
			if (_d._y == 0){
				std::cerr << "Error: mod zero!" << std::endl;
				return;
			}
			else{
				result = _d._x % _d._y;
			}
			break;
		default:
			std::cerr << "operation error!" << std::endl;
			return;
		}
		std::cout << "thread[" << pthread_self() << "]:" << _d._x << _d._op << _d._y << "=" << result << std::endl;

		//5、形成响应报文
		std::string response;
		response += std::to_string(_d._x);
		response += _d._op;
		response += std::to_string(_d._y);
		response += "=";
		response += std::to_string(result);
		response += "X"; //报文与报文之间的分隔符
		
		//6、将响应报文添加到outbuffer中
		_item->_outbuffer += response;
		if (!_item->_outbuffer.empty())
			_item->_R->EnableReadWrite(_item->_sock, true, true); //打开写事件
	}
};
```

此时recver回调函数中在读取数据、报文切割、反序列化后就可以构建出一个任务对象，然后将该任务放到任务队列当中就行了。

```cpp
int recver(EventItem* item)
{
	if (item->_sock < 0) //该文件描述符已经被关闭
		return -1;

	//1、数据读取
	if (recver_helper(item->_sock, &(item->_inbuffer)) < 0){ //读取失败
		item->_error_handler(item);
		return -1;
	}

	//2、报文切割
	std::vector<std::string> datagrams;
	StringUtil::Split(item->_inbuffer, &datagrams, "X");

	for (auto s : datagrams){
		//3、反序列化
		struct data d;
		StringUtil::Deserialize(s, &d._x, &d._y, &d._op);

		Task t(d, item); //构建任务
		ThreadPool<Task>::GetInstance()->Push(t); //将任务push到线程池的任务队列中
	}
	return 0;
}
```

至此线程池便接入完毕了，由于我们在任务被处理后将处理对应任务线程的ID进行了打印，因此现在客户端向服务器发送的计算请求在被处理后，可以在服务器端看到处理该任务的线程的ID。  
![在这里插入图片描述](%E5%9B%BE%E7%89%87/Linux/790afab1c764495181ce604288b4be3a.png)

