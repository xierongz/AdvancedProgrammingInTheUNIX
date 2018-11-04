*************************************************************
- 《UNIX环境高级编程(第三版)》学习日志
- 作者：谢荣桢
- 版本：V1.0
*************************************************************
<a name="0.0.1"></a>
## [0.0.1](#1.3) (2018-10-29 22:51)
# <span id="chapter1">第一章 UNIX基础知识</span>
## <span id="1.1">1.1 引言</span>
&emsp;　典型的服务：执行新程序、打开文件、读文件、分配存储区以及获得当前时间等

## <span id="1.2">1.2 UNIX体系结构</span>
&emsp;　**内核(kernel)：** 一种软件，控制计算机硬件资源，提供程序运行环境。

&emsp;　**系统调用(system call)：** 内核的接口

&emsp;　**公用函数库：** 在系统调用接口之上。

&emsp;　**shell：** 一个特殊的应用程序，为运行其他应用程序提供了一个接口。

![](assests/chapter1/UNIXArchitecture.jpg)

## <span id="1.3">1.3 登录</span>
### <span id="1.登录名">1.登录名</span>
&emsp;　用户在登录UNIX系统时，先键入登录名，然后键入口令。

&emsp;　系统在其口令文件(通常在/etc/passwd文件)中查看登录名。

&emsp;　**口令文件中的登录项组成(用冒号分隔)：** 登录名、加密口令、数字用户ID(205)、数字组ID(105)、注释字段、起始目录(/home/sar)、shell程序(/bin/ksh)。

    例：sar:x:205:105:Stephen Rago:/home/sar:/bin/ksh

注：目前所有的系统已将加密口令移到另一个文件中[(第六章)](#chapter6)

### <span id="2.shell">2.shell</sapn>
&emsp;　shell是一个命令行解释器，读取用户输入，然后执行命令。

&emsp;　常见的的shell：Bourne shell、Bourne-again shell、C shell、Korn shell、TENEX C shell。

&emsp;　系统从口令文件中相应用户*登录项的最后一个字段*(bin/ksh)中了解到应该为该登录用户执行哪一个shell。

<a name="0.0.2"></a>
## [0.0.2](#1.5) (2018-10-30 21:51)
## <span id="1.4">1.4 文件和目录</sapn>
### <span id="1.文件系统">1.文件系统</sapn>
&emsp;　UNIX文件系统时目录和文件的一种层次结构，所有东西的起点是称为 **根(root)** 的目录，其名称是一个字符"/"。

&emsp;　**目录(directory)** 是一个包含目录项的文件。

&emsp;　在逻辑上，可以认为每个目录项都包含一个文件名，同时还包含说明该文件属性的信息。

&emsp;　**文件属性：** 文件类型(普通文件还是目录等)、文件大小、文件所有者、文件权限(其他用户能否访问该文件)、文件最后的修改时间。

&emsp;　stat和fstat函数返回包含所有文件属性的一个信息结构。文件属性详见[第四章](#chapter4)

### <span id="2.文件名">2.文件名(filename)</sapn>

&emsp;　只有斜线(/)和空字符不能出现在文件名中。

&emsp;　**斜线：** 分隔构成路径名的各文件名

&emsp;　**空字符：** 用来终止一个路径名。

### <span id="3.路径名">3.路径名</span>

&emsp;　**路径名(pathname)：** 有斜线分隔的一个或多个文件名组成的序列(也可以斜线开头)

&emsp;　**绝对路径名(absolute pathname)：** 以斜线开头的路径名称。

&emsp;　**相对路径名(relative pathname)：** 指向相对于当前目录的文件(不以斜线开头)。

&emsp;　例题：[myls.c](例题/chapter1/myls.c)

&emsp;　**细节：**
- apue.h：包含了某些标准系统头文件，定义了许多常量及函数原型
- dirent.h：使用opendir和readdir的函数原型，以及dirent结构的定义
- main函数的声明使用了ISO C标准[(第二章)](#chapter2)所使用的风格。
- 程序获取命令行的第一个参数argv[1]作为要列出其各个目录项的目录名。[第七章](#chapter7)说明main函数调用以及程序存取命令行参数和环境变量。
- 由于各种不同的UNIX系统目录项的实际格式不一样，所以使用函数opendir、readdir和closedir对目录进行处理
- opendir函数返回指向DIR结构的指针，将该指针传送给readdir函数。
- readdir返回一个指向dirent结构的指针，而当目录中已无目录项可读时则返回null指针。
- 在dirent结构中取出的只是每个目录项的名字(d_name)。使用该名字，可调用stat函数[(4.2节)](#4.2)以获得该文件的所有属性。
- 程序调用了两个自编的函数对错误进行处理：err_sys和err_quit。[1.7节叙述出错处理](#1.7)。
- 当程序结束时，以参数0调用函数eixt。表示正常结束。[8.5节](#8.5)将说明一个程序如何获得它所执行的另一个程序的exit状态。

### <span id="4.工作目录">4.工作目录(working directory)</span>
&emsp;　所有相对路径名都从工作目录开始解释。进程用chdir函数更改其工作目录。

### <span id="5.起始目录">5.起始目录(home directory)</span>
&emsp;　登录时，工作目录设置为起始目录，该起始目录从口令文件[(1.3节)](#1.3)中相应用户的登录项中取得。

## <span id="1.5">1.5 输入和输出</span>
### <span id="1.文件描述符">1.文件描述符(file descriptor)</span>

&emsp;　一个很小的非负整数，内核用以标识一个特定进程正在访问的文件。

&emsp;　当内核打开一个现有文件或创建一个新文件时，都返回一个文件描述符。

&emsp;　在读、写文件时，可以使用这个文件描述符。

### <span id="2.标准输入、标准输出和标准错误">2.标准输入、标准输出和标准错误</span>
&emsp;　每当运行一个新程序时，所有的shell都为其打开三个文件描述符：**标准输入(standard input)、标准输出(standard output)、标准错误(standard error)**。

&emsp;　大多数shell都提供一种方法，使其中任何一个或所有这3个描述符都能重新定向到某个文件。

&emsp;　例：ls > file.list

    执行ls命令，其标准输出重新定向到名为file.list的文件。
    即运行实例中的命令，结果输出到file.list(如不存在file.list，生成file.list)

### <span id="3.不带缓冲的I/O">3.不带缓冲的I/O</span>

&emsp;　函数open、read、write、lseek以及close提供了不带缓冲的I/O。

&emsp;　例：[mycat.c](例题/chapter1/mycat.c)

- 头文件<unistd.h>(apue.h包含了此头文件)及两个常量STDIN_FILENO和STDOUT_FILENO是POSIX标准[(第二章)](#chapter2)的一部分。头文件<unistd.h>包含了很多UNIX系统服务的函数原型。
- STDIN_FILENO和STDOUT_FILENO指定了标准输入和标准输出的文件描述符。在POSIX标准中，它们的值分别是0和1.
- [3.9节](#3.9)将详细讨论BUFFSIZE常量，说明它的各种不同值将如何影响程序的效率。不管BUFFSIZE值如何，mycat.c总能复制任一UNIX普通文件。
- read函数返回读取的字节数，此值用作要写的字节数。
- ./a.out > data 标准输入为终端，标准输出重定向至文件data，标准错误也是终端。程序将用户键入的各行复制到data，键入文件结束符(通常是Ctrl+D)，结束复制。
- ./a.out < infile > outfile 将名为infile文件的内容复制到outfile文件(若infile不存在，会报错)
- [第三章](#chapter3)将详细说明不到缓冲的I/O函数。


### <span id="4.标准I/O">4.标准I/O</span>
&emsp;　标准I/O为不带缓冲的I/O函数提供了一个带缓冲的接口。

&emsp;　[5.4节](#5.4)：标准I/O函数库提供控制该库所使用的缓冲风格的函数。

&emsp;　例：[getcputc.c](例题/chapter1/getcputc.c)  ([5.8节](#5.8)将详细说明该程序。)

<a name="0.0.3"></a>
## [0.0.3](#1.6) (2018-10-31 22:51)

## <span id="1.6">1.6 程序和进程</span>
### <span id="1.程序">1.程序(program)</sapn>
&emsp;　一个存储在磁盘上某个目录中的可执行文件。

&emsp;　内核使用exec函数[(8.10节)](#8.10)(7个exec函数之一)，将程序读入内存，并执行程序。

### <span id="2.进程和进程ID">2.进程和进程ID</span>
&emsp;　**进程(process)：** 程序的执行实例。某些操作程序用任务(task)表示正在被执行的程序。

&emsp;　**进程ID(process ID)：** UNIX系统确保每个进程都有唯一的数字标识符。进程ID总是一个非负整数。例：[hello.c](例题/chapter1/hello.c) 通过getpid函数得到hello.c的进程ID。

### <span id="3.进程控制">3.进程控制</span>
&emsp;　有三个用于进程控制的主要函数：fork、exec和waitpid。

&emsp;　实例：[shell1.c](例题/chapter1/shell1.c) 程序从标准输入读取命令，然后执行这些命令。

- 用标准I/O函数fgets从标准输入一次读取一行。当键入文件结束符(通常是Ctrl+D)作为行的第一个字符时，fgets返回一个NULL指针，进程终止。[第十八章](#chapter18)将说明所有特殊的终端字符(文件结束、退格字符、整行擦除等)，以及如何改变它们。
- 因为fgets返回的每一行都以换行符终止，后随一个null字节，因此用strlen计算字符串的长度，然后用一个null字节替换换行符。**因为execlp函数要求的参数是以null结束。**
- 调用fork创建一个新进程。fork对父进程(调用进程)返回新的子进程的进程ID(一个非负整数)，对子进程返回0。
- 在子进程中，调用execlp以执行从标准输入读入的命令。在UNIX系统中，fork和exec两个独立的函数组合产生(spawn)一个新进程。[第八章](#chapter8)详细说明。
- 子进程调用execlp执行新程序文件，而父进程希望等待子进程终止，调用waitpid实现，参数为指定要等待的进程(即pid参数是子进程ID)。waitpid返回子进程的终止状态(status变量)。
- 该程序的最主要限制是不能向所执行的命令传递参数。

### <span id="4.线程和线程ID">4.线程和线程ID</span>

&emsp;　通常一个进程只有一个控制线程(thread)——某一时刻执行的一组机器指令。

&emsp;　一个进程内的所有线程共享同一个地址空间、文件描述符、栈以及与进程相关的属性。各线程在访问共享数据时需要采取同步措施以避免不一致性。

&emsp;　线程也用ID标识。线程ID只在它所属的进程内起作用。

&emsp;　控制线程的函数与控制进程的函数类似，在[第十二章](#chapter12)说明进程模型和线程模型的交互。

<a name="0.0.4"></a>
## [0.0.4](#1.7) (2018-11-01 22:49)

## <span id="1.7">1.7 出错处理</span>

&emsp;　当UNIX系统函数出错时，通常会返回一个负值，而有些函数对于出错则使用另一种约定，例如：返回null指针。

&emsp;　文件<errno.h>定义了errno以及可以赋予它的各种常量。

&emsp;　POSIX[(第二章)](#chapter2)和ISO C[(第二章)](#chapter2)将errno定义为一个符号，它扩展为一个可修改的整型左值(Ivalue)。

&emsp;　errno可以是一个包含出错编号的整数，也可以是一个返回出错编号指针的函数。

&emsp;　在支持线程的环境中，多个线程共享进程地址空间，每个线程都有属于它自己的局部errno以避免一个线程干扰另一个线程。

&emsp;　**errno的规则：**

1. 如果没有出错,其值不会被例程清除。
*因此，仅当函数的返回值指明出错时，才检查其值。*
2. 任何函数都不会将errno值设置为0，而且在<errno.h>中定义的所有常量都不为0。

&emsp;　**C标准定义两个函数，由于打印出错信息。**

1. strerror函数将 *errnum*(通常是errno)映射为一个出错消息字符串，并且返回此字符串的指针。
```C
#include <string.h>
char *strerror(int errnum);    
```

2. perror函数基于errno的当前值，在标准错误上产生一条出错消息，然后返回
```C
#include <stdio.h>
void perror(const char *msg);   
```
*它首先输出有msg指向的字符串，然后是一个冒号，一个空格，接着是对应于errno值的出错消息，最后是一个换行符。*

3. 例：[testerror.c](例题/chapter1/testerror.c)
*注意：我们将程序名(argv[0],其值是./a.out)作为参数传递给perror。
使用这种方法，在程序中作为管道的一部分执行，例如：*
```C
prog1 < inputfile | prog2 | prog3 > outputfile
```
*就能分清3个程序中的哪一个产生了一条特定的出错消息。*

#### 出错恢复

可将在<errno.h>中定义的各种出错分成两类：

1. 致命性的
*无法执行恢复动作。最多能做的是在用户屏幕上打印出一条出错消息或者将一条出错消息写入日志文件中，然后退出。*
2. 非致命性的
*有事可以较妥善地进行处理。大多数非致命性出错时暂时的(如：资源短缺)
与资源有关的非致命性出错包括：EAGAIN、ENFILE、ENOBUFS、ENOLCK、ENOSPC、EWOULDBLACK，有时ENOMEM也是非致命性出错。
当EBUSY指明共享资源正在使用时，也可将它作为非致命性出错处理。
当EINTR中断一个慢速系统调用时，也可作为非致命性出错处理([10.5节](#10.5)详细说明)*

<a name="0.0.5"></a>
## [0.0.5](#1.11) (2018-11-04 13:49)

## <span id="1.8">1.8 用户标识</span>
### 1. 用户ID(user ID)

&emsp;　口令文件登录项中的用户ID是一个数值，向系统标识各个不同的用户。

&emsp;　用户ID为0的用户为 **根用户(root)** 或 **超级用户(superuser)**。

### 2. 组ID(group ID)

&emsp;　**组ID：** 由系统管理员在指定用户登录名时分配的。

&emsp;　组被用于将若干用户集合到项目或部门中去。这种机制允许同组的各个成员之间共享资源。[4.5节](#4.5)介绍可以通过设置文件的权限使组内所有成员都能访问该文件，而组外用户不能访问。

&emsp;　组文件将组名映射为数值的组ID。组文件通常是/etc/group。

&emsp;　例：[uidgid.c](例题/chapter1/uidgid.c)

### 3. 附属组ID(supplementary group ID)
&emsp;　登录时，读文件/etc/group，寻找列有该用户作为其成员的前16个记录项就可以得到该用户的附属组ID。

&emsp;　[第二章](#chapter2)将说明，POSIX要求系统至少应支持8个附属组，实际上大多数系统至少支持16个附属组。

## <span id="1.9">1.9 信号(signal)</span>

&emsp;　信号用于通知进程发生了某种情况。

&emsp;　**进程有3种处理信号的方式：**

    (1). 忽略信号：
            有些信号表示硬件异常，例如：除以0或访问进程地址空间以外的存储单元等，因为这些异常产生的后果不确定，所以不推荐使用这种处理方式。
    (2). 按系统默认方式处理。
            对于除数为0，系统默认方式是终止该进程。
    (3). 提供一个函数，信号发生是调用该函数，这被称为捕捉该信号。
            通过提供自编的函数，我们就能知道什么时候产生了信号，并按期望的方式处理它。

&emsp;　**产生信号：**

    (1).终端键盘产生信号
        中断键(interrupt key)：Delete键 或 Ctrl+C
        退出键(quit key)：Ctrl+\
    (2).调用kill函数
        在一个进程中调用此函数就可向另一个进程发送一个信号。
        限制：当向一个进程发送信号时，必须是那个进程的所有者或者是超级用户。

&emsp;　例：[shell2.c](例题/chapter1/shell2.c)

&emsp;　调用此程序，然后按下中断键，则执行此程序的进程终止。

&emsp;　原因：对于此信号(SIGINT)的系统默认动作是终止进程。该进程没有告诉系统内核应该如何处理此信号，所以系统按默认方式终止该进程。

## <span id="1.10">1.10 时间值</span>

&emsp;　**UNIX系统的时间值：**

    (1).日历时间。
            该值是自协调世界时(Coordinated Universal Time, UTC)——1970年1月1日 00:00:00这个特定时间以来所经过的秒数累计值。
            系统基本数据类型time_t用于保存这种时间值。
    (2)。进程时间。也称为CPU时间。
            用以度量进程使用的CPU资源。进程时间以时钟滴答计算。
            系统基本数据类型clock_t保存这种时间值
            [2.5.4节](#2.5.4)说明如何用sysconf函数得到每秒的时钟滴答数。

&emsp;　**但度量一个进程的执行时间时[(见3.9节)](#3.9)，UNIX系统为一个进程维护了3个进程时间值：**

    - 时钟时间
        又称为 *墙上时钟时间(wall clock time)*，是进程运行的时间总量，其值与系统中同时运行的进程数有关。
        本书提到时钟时间时，都是在系统中没有其他活动时进行度量的
    - 用户CPU时间
        是执行用户指令所用的时间量。
    - 系统CPU时间。
        是为该进程执行内核程序所经历的时间。
&emsp;　[8.17节](#8.17)将说明一个运行进程如何取得这3个时间。关于时间和日期的一般说明见[6.10节](#6.10)

## <span id="1.11">1.11 系统调用和库函数</span>

&emsp;　所有的操作系统都提供多种服务的入口点，有此程序向内核请求服务。这些入口点被称为 *系统调用(system call)*。

&emsp;　UNIX所使用的技术是为每个系统调用在标准C库中设置一个具有相同名字的函数

&emsp;　可以替换库函数，但是系统调用通常是不能被替换的。

&emsp;　例：内核中的系统调用分配一块空间给进程，如何管理该地址空间取决于进程。
    库函数malloc则在用户层次管理这一空间。

&emsp;　系统调用和库函数的差别：
        系统调用通常提供一种最小接口，而库函数通常提供比较复杂的功能。
        例：不带缓冲的I/O函数[(见第三章)](#chapter3)和标准I/O函数[(见第五章)](#chapter5)。
            [8.13节](#8.13)将说明system函数的一种实现，它使用基本的进程控制系统调用。
            [10.18节](#10.18)将强化这一实例以正确地处理信号。

# <span id="chapter2">第二章 UNIX标准及实现</span>

## <span id="2.1">2.1 引言</span>

## <span id="2.2">2.2 UNIX标准化</span>

### <span id="2.2.1">2.2.1 ISO C</span>

<center>图2-1 ISO C标准定义的头文件</center>

|    头文件    | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |              说明              |
|:------------:|:-----------:|:-----------:|:---------------:|:----------:|:------------------------------:|
|  <assest.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          验证程序断言          |
| <complex.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |        复数算术运算支持        |
|  <ctype.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |       字符分类和映射支持       |
|  <errno.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |     出错码[(1.7节)](#1.7)      |
|   <fenv.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            浮点环境            |
|  <float.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         浮点常量及特性         |
| <inttypes.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          整型格式变换          |
|  <iso646.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    赋值、关系及一元操作符宏    |
|  <limits.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    实现常量[(2.5节)](#2.5)     |
|  <locale.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |      本地化类别及相关定义      |
|   <math.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    数学函数、类型声明及常量    |
|  <setjmp.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |  非局部goto[(7.10节)](#7.10)   |
|  <signal.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |   信号[(第十章)](#chapter10)   |
|  <stdarg.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         可变长度参数表         |
| <stdbool.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          布尔类型和值          |
|  <stddef.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            标准定义            |
|  <stdint.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |              整型              |
|  <stdio.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   | 标准I/O库[(第五章)](#chapter5) |
|  <stdlib.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            使用函数            |
|  <string.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           字符串操作           |
|  <tgmath.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         通用类型数学宏         |
|   <time.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |  时间和日期[(6.10节)](#6.10)   |
|  <wchar.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    扩充的多字节和宽字符支持    |
|  <wctype.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |      宽字符分类和映射支持      |
