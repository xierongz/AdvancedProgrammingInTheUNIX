*************************************************************
- ��UNIX�����߼����(������)��ѧϰ��־
- ���ߣ�л����
- �汾��V1.0
*************************************************************
<a name="0.0.1"></a>
## [0.0.1](#1.3) (2018-10-29 22:51)
# <span id="chapter1">��һ�� UNIX����֪ʶ</span>
## <span id="1.1">1.1 ����</span>
&emsp;�����͵ķ���ִ���³��򡢴��ļ������ļ�������洢���Լ���õ�ǰʱ���

## <span id="1.2">1.2 UNIX��ϵ�ṹ</span>
&emsp;��**�ں�(kernel)��** һ����������Ƽ����Ӳ����Դ���ṩ�������л�����

&emsp;��**ϵͳ����(system call)��** �ں˵Ľӿ�

&emsp;��**���ú����⣺** ��ϵͳ���ýӿ�֮�ϡ�

&emsp;��**shell��** һ�������Ӧ�ó���Ϊ��������Ӧ�ó����ṩ��һ���ӿڡ�

![](assests/chapter1/UNIXArchitecture.jpg)

## <span id="1.3">1.3 ��¼</span>
### <span id="1.��¼��">1.��¼��</span>
&emsp;���û��ڵ�¼UNIXϵͳʱ���ȼ����¼����Ȼ�������

&emsp;��ϵͳ��������ļ�(ͨ����/etc/passwd�ļ�)�в鿴��¼����

&emsp;��**�����ļ��еĵ�¼�����(��ð�ŷָ�)��** ��¼�������ܿ�������û�ID(205)��������ID(105)��ע���ֶΡ���ʼĿ¼(/home/sar)��shell����(/bin/ksh)��

    ����sar:x:205:105:Stephen Rago:/home/sar:/bin/ksh

ע��Ŀǰ���е�ϵͳ�ѽ����ܿ����Ƶ���һ���ļ���[(������)](#chapter6)

### <span id="2.shell">2.shell</sapn>
&emsp;��shell��һ�������н���������ȡ�û����룬Ȼ��ִ�����

&emsp;�������ĵ�shell��Bourne shell��Bourne-again shell��C shell��Korn shell��TENEX C shell��

&emsp;��ϵͳ�ӿ����ļ�����Ӧ�û�*��¼������һ���ֶ�*(bin/ksh)���˽⵽Ӧ��Ϊ�õ�¼�û�ִ����һ��shell��

<a name="0.0.2"></a>
## [0.0.2](#1.5) (2018-10-30 21:51)
## <span id="1.4">1.4 �ļ���Ŀ¼</sapn>
### <span id="1.�ļ�ϵͳ">1.�ļ�ϵͳ</sapn>
&emsp;��UNIX�ļ�ϵͳʱĿ¼���ļ���һ�ֲ�νṹ�����ж���������ǳ�Ϊ **��(root)** ��Ŀ¼����������һ���ַ�"/"��

&emsp;��**Ŀ¼(directory)** ��һ������Ŀ¼����ļ���

&emsp;�����߼��ϣ�������Ϊÿ��Ŀ¼�����һ���ļ�����ͬʱ������˵�����ļ����Ե���Ϣ��

&emsp;��**�ļ����ԣ�** �ļ�����(��ͨ�ļ�����Ŀ¼��)���ļ���С���ļ������ߡ��ļ�Ȩ��(�����û��ܷ���ʸ��ļ�)���ļ������޸�ʱ�䡣

&emsp;��stat��fstat�������ذ��������ļ����Ե�һ����Ϣ�ṹ���ļ��������[������](#chapter4)

### <span id="2.�ļ���">2.�ļ���(filename)</sapn>

&emsp;��ֻ��б��(/)�Ϳ��ַ����ܳ������ļ����С�

&emsp;��**б�ߣ�** �ָ�����·�����ĸ��ļ���

&emsp;��**���ַ���** ������ֹһ��·������

### <span id="3.·����">3.·����</span>

&emsp;��**·����(pathname)��** ��б�߷ָ���һ�������ļ�����ɵ�����(Ҳ����б�߿�ͷ)

&emsp;��**����·����(absolute pathname)��** ��б�߿�ͷ��·�����ơ�

&emsp;��**���·����(relative pathname)��** ָ������ڵ�ǰĿ¼���ļ�(����б�߿�ͷ)��

&emsp;�����⣺[myls.c](����/chapter1/myls.c)

&emsp;��**ϸ�ڣ�**
- apue.h��������ĳЩ��׼ϵͳͷ�ļ�����������ೣ��������ԭ��
- dirent.h��ʹ��opendir��readdir�ĺ���ԭ�ͣ��Լ�dirent�ṹ�Ķ���
- main����������ʹ����ISO C��׼[(�ڶ���)](#chapter2)��ʹ�õķ��
- �����ȡ�����еĵ�һ������argv[1]��ΪҪ�г������Ŀ¼���Ŀ¼����[������](#chapter7)˵��main���������Լ������ȡ�����в����ͻ���������
- ���ڸ��ֲ�ͬ��UNIXϵͳĿ¼���ʵ�ʸ�ʽ��һ��������ʹ�ú���opendir��readdir��closedir��Ŀ¼���д���
- opendir��������ָ��DIR�ṹ��ָ�룬����ָ�봫�͸�readdir������
- readdir����һ��ָ��dirent�ṹ��ָ�룬����Ŀ¼������Ŀ¼��ɶ�ʱ�򷵻�nullָ�롣
- ��dirent�ṹ��ȡ����ֻ��ÿ��Ŀ¼�������(d_name)��ʹ�ø����֣��ɵ���stat����[(4.2��)](#4.2)�Ի�ø��ļ����������ԡ�
- ��������������Ա�ĺ����Դ�����д���err_sys��err_quit��[1.7������������](#1.7)��
- ���������ʱ���Բ���0���ú���eixt����ʾ����������[8.5��](#8.5)��˵��һ��������λ������ִ�е���һ�������exit״̬��

### <span id="4.����Ŀ¼">4.����Ŀ¼(working directory)</span>
&emsp;���������·�������ӹ���Ŀ¼��ʼ���͡�������chdir���������乤��Ŀ¼��

### <span id="5.��ʼĿ¼">5.��ʼĿ¼(home directory)</span>
&emsp;����¼ʱ������Ŀ¼����Ϊ��ʼĿ¼������ʼĿ¼�ӿ����ļ�[(1.3��)](#1.3)����Ӧ�û��ĵ�¼����ȡ�á�

## <span id="1.5">1.5 ��������</span>
### <span id="1.�ļ�������">1.�ļ�������(file descriptor)</span>

&emsp;��һ����С�ķǸ��������ں����Ա�ʶһ���ض��������ڷ��ʵ��ļ���

&emsp;�����ں˴�һ�������ļ��򴴽�һ�����ļ�ʱ��������һ���ļ���������

&emsp;���ڶ���д�ļ�ʱ������ʹ������ļ���������

### <span id="2.��׼���롢��׼����ͱ�׼����">2.��׼���롢��׼����ͱ�׼����</span>
&emsp;��ÿ������һ���³���ʱ�����е�shell��Ϊ��������ļ���������**��׼����(standard input)����׼���(standard output)����׼����(standard error)**��

&emsp;�������shell���ṩһ�ַ�����ʹ�����κ�һ����������3���������������¶���ĳ���ļ���

&emsp;������ls > file.list

    ִ��ls������׼������¶�����Ϊfile.list���ļ���
    ������ʵ���е������������file.list(�粻����file.list������file.list)

### <span id="3.���������I/O">3.���������I/O</span>

&emsp;������open��read��write��lseek�Լ�close�ṩ�˲��������I/O��

&emsp;������[mycat.c](����/chapter1/mycat.c)

- ͷ�ļ�<unistd.h>(apue.h�����˴�ͷ�ļ�)����������STDIN_FILENO��STDOUT_FILENO��POSIX��׼[(�ڶ���)](#chapter2)��һ���֡�ͷ�ļ�<unistd.h>�����˺ܶ�UNIXϵͳ����ĺ���ԭ�͡�
- STDIN_FILENO��STDOUT_FILENOָ���˱�׼����ͱ�׼������ļ�����������POSIX��׼�У����ǵ�ֵ�ֱ���0��1.
- [3.9��](#3.9)����ϸ����BUFFSIZE������˵�����ĸ��ֲ�ֵͬ�����Ӱ������Ч�ʡ�����BUFFSIZEֵ��Σ�mycat.c���ܸ�����һUNIX��ͨ�ļ���
- read�������ض�ȡ���ֽ�������ֵ����Ҫд���ֽ�����
- ./a.out > data ��׼����Ϊ�նˣ���׼����ض������ļ�data����׼����Ҳ���նˡ������û�����ĸ��и��Ƶ�data�������ļ�������(ͨ����Ctrl+D)���������ơ�
- ./a.out < infile > outfile ����Ϊinfile�ļ������ݸ��Ƶ�outfile�ļ�(��infile�����ڣ��ᱨ��)
- [������](#chapter3)����ϸ˵�����������I/O������


### <span id="4.��׼I/O">4.��׼I/O</span>
&emsp;����׼I/OΪ���������I/O�����ṩ��һ��������Ľӿڡ�

&emsp;��[5.4��](#5.4)����׼I/O�������ṩ���Ƹÿ���ʹ�õĻ�����ĺ�����

&emsp;������[getcputc.c](����/chapter1/getcputc.c)  ([5.8��](#5.8)����ϸ˵���ó���)

<a name="0.0.3"></a>
## [0.0.3](#1.6) (2018-10-31 22:51)

## <span id="1.6">1.6 ����ͽ���</span>
### <span id="1.����">1.����(program)</sapn>
&emsp;��һ���洢�ڴ�����ĳ��Ŀ¼�еĿ�ִ���ļ���

&emsp;���ں�ʹ��exec����[(8.10��)](#8.10)(7��exec����֮һ)������������ڴ棬��ִ�г���

### <span id="2.���̺ͽ���ID">2.���̺ͽ���ID</span>
&emsp;��**����(process)��** �����ִ��ʵ����ĳЩ��������������(task)��ʾ���ڱ�ִ�еĳ���

&emsp;��**����ID(process ID)��** UNIXϵͳȷ��ÿ�����̶���Ψһ�����ֱ�ʶ��������ID����һ���Ǹ�����������[hello.c](����/chapter1/hello.c) ͨ��getpid�����õ�hello.c�Ľ���ID��

### <span id="3.���̿���">3.���̿���</span>
&emsp;�����������ڽ��̿��Ƶ���Ҫ������fork��exec��waitpid��

&emsp;��ʵ����[shell1.c](����/chapter1/shell1.c) ����ӱ�׼�����ȡ���Ȼ��ִ����Щ���

- �ñ�׼I/O����fgets�ӱ�׼����һ�ζ�ȡһ�С��������ļ�������(ͨ����Ctrl+D)��Ϊ�еĵ�һ���ַ�ʱ��fgets����һ��NULLָ�룬������ֹ��[��ʮ����](#chapter18)��˵������������ն��ַ�(�ļ��������˸��ַ������в�����)���Լ���θı����ǡ�
- ��Ϊfgets���ص�ÿһ�ж��Ի��з���ֹ������һ��null�ֽڣ������strlen�����ַ����ĳ��ȣ�Ȼ����һ��null�ֽ��滻���з���**��Ϊexeclp����Ҫ��Ĳ�������null������**
- ����fork����һ���½��̡�fork�Ը�����(���ý���)�����µ��ӽ��̵Ľ���ID(һ���Ǹ�����)�����ӽ��̷���0��
- ���ӽ����У�����execlp��ִ�дӱ�׼�������������UNIXϵͳ�У�fork��exec���������ĺ�����ϲ���(spawn)һ���½��̡�[�ڰ���](#chapter8)��ϸ˵����
- �ӽ��̵���execlpִ���³����ļ�����������ϣ���ȴ��ӽ�����ֹ������waitpidʵ�֣�����Ϊָ��Ҫ�ȴ��Ľ���(��pid�������ӽ���ID)��waitpid�����ӽ��̵���ֹ״̬(status����)��
- �ó��������Ҫ�����ǲ�������ִ�е�����ݲ�����

### <span id="4.�̺߳��߳�ID">4.�̺߳��߳�ID</span>

&emsp;��ͨ��һ������ֻ��һ�������߳�(thread)����ĳһʱ��ִ�е�һ�����ָ�

&emsp;��һ�������ڵ������̹߳���ͬһ����ַ�ռ䡢�ļ���������ջ�Լ��������ص����ԡ����߳��ڷ��ʹ�������ʱ��Ҫ��ȡͬ����ʩ�Ա��ⲻһ���ԡ�

&emsp;���߳�Ҳ��ID��ʶ���߳�IDֻ���������Ľ����������á�

&emsp;�������̵߳ĺ�������ƽ��̵ĺ������ƣ���[��ʮ����](#chapter12)˵������ģ�ͺ��߳�ģ�͵Ľ�����

<a name="0.0.4"></a>
## [0.0.4](#1.7) (2018-11-01 22:49)

## <span id="1.7">1.7 ������</span>

&emsp;����UNIXϵͳ��������ʱ��ͨ���᷵��һ����ֵ������Щ�������ڳ�����ʹ����һ��Լ�������磺����nullָ�롣

&emsp;���ļ�<errno.h>������errno�Լ����Ը������ĸ��ֳ�����

&emsp;��POSIX[(�ڶ���)](#chapter2)��ISO C[(�ڶ���)](#chapter2)��errno����Ϊһ�����ţ�����չΪһ�����޸ĵ�������ֵ(Ivalue)��

&emsp;��errno������һ�����������ŵ�������Ҳ������һ�����س�����ָ��ĺ�����

&emsp;����֧���̵߳Ļ����У�����̹߳�����̵�ַ�ռ䣬ÿ���̶߳����������Լ��ľֲ�errno�Ա���һ���̸߳�����һ���̡߳�

&emsp;��**errno�Ĺ���**

1. ���û�г���,��ֵ���ᱻ���������
*��ˣ����������ķ���ֵָ������ʱ���ż����ֵ��*
2. �κκ��������Ὣerrnoֵ����Ϊ0��������<errno.h>�ж�������г�������Ϊ0��

&emsp;��**C��׼�����������������ڴ�ӡ������Ϣ��**

1. strerror������ *errnum*(ͨ����errno)ӳ��Ϊһ��������Ϣ�ַ��������ҷ��ش��ַ�����ָ�롣
```C
#include <string.h>
char *strerror(int errnum);    
```

2. perror��������errno�ĵ�ǰֵ���ڱ�׼�����ϲ���һ��������Ϣ��Ȼ�󷵻�
```C
#include <stdio.h>
void perror(const char *msg);   
```
*�����������msgָ����ַ�����Ȼ����һ��ð�ţ�һ���ո񣬽����Ƕ�Ӧ��errnoֵ�ĳ�����Ϣ�������һ�����з���*

3. ����[testerror.c](����/chapter1/testerror.c)
*ע�⣺���ǽ�������(argv[0],��ֵ��./a.out)��Ϊ�������ݸ�perror��
ʹ�����ַ������ڳ�������Ϊ�ܵ���һ����ִ�У����磺*
```C
prog1 < inputfile | prog2 | prog3 > outputfile
```
*���ܷ���3�������е���һ��������һ���ض��ĳ�����Ϣ��*

#### ����ָ�

�ɽ���<errno.h>�ж���ĸ��ֳ���ֳ����ࣺ

1. �����Ե�
*�޷�ִ�лָ���������������������û���Ļ�ϴ�ӡ��һ��������Ϣ���߽�һ��������Ϣд����־�ļ��У�Ȼ���˳���*
2. �������Ե�
*���¿��Խ����Ƶؽ��д���������������Գ���ʱ��ʱ��(�磺��Դ��ȱ)
����Դ�йصķ������Գ��������EAGAIN��ENFILE��ENOBUFS��ENOLCK��ENOSPC��EWOULDBLACK����ʱENOMEMҲ�Ƿ������Գ���
��EBUSYָ��������Դ����ʹ��ʱ��Ҳ�ɽ�����Ϊ�������Գ�����
��EINTR�ж�һ������ϵͳ����ʱ��Ҳ����Ϊ�������Գ�����([10.5��](#10.5)��ϸ˵��)*

<a name="0.0.5"></a>
## [0.0.5](#1.11) (2018-11-04 13:49)

## <span id="1.8">1.8 �û���ʶ</span>
### 1. �û�ID(user ID)

&emsp;�������ļ���¼���е��û�ID��һ����ֵ����ϵͳ��ʶ������ͬ���û���

&emsp;���û�IDΪ0���û�Ϊ **���û�(root)** �� **�����û�(superuser)**��

### 2. ��ID(group ID)

&emsp;��**��ID��** ��ϵͳ����Ա��ָ���û���¼��ʱ����ġ�

&emsp;���鱻���ڽ������û����ϵ���Ŀ������ȥ�����ֻ�������ͬ��ĸ�����Ա֮�乲����Դ��[4.5��](#4.5)���ܿ���ͨ�������ļ���Ȩ��ʹ�������г�Ա���ܷ��ʸ��ļ����������û����ܷ��ʡ�

&emsp;�����ļ�������ӳ��Ϊ��ֵ����ID�����ļ�ͨ����/etc/group��

&emsp;������[uidgid.c](����/chapter1/uidgid.c)

### 3. ������ID(supplementary group ID)
&emsp;����¼ʱ�����ļ�/etc/group��Ѱ�����и��û���Ϊ���Ա��ǰ16����¼��Ϳ��Եõ����û��ĸ�����ID��

&emsp;��[�ڶ���](#chapter2)��˵����POSIXҪ��ϵͳ����Ӧ֧��8�������飬ʵ���ϴ����ϵͳ����֧��16�������顣

## <span id="1.9">1.9 �ź�(signal)</span>

&emsp;���ź�����֪ͨ���̷�����ĳ�������

&emsp;��**������3�ִ����źŵķ�ʽ��**

    (1). �����źţ�
            ��Щ�źű�ʾӲ���쳣�����磺����0����ʽ��̵�ַ�ռ�����Ĵ洢��Ԫ�ȣ���Ϊ��Щ�쳣�����ĺ����ȷ�������Բ��Ƽ�ʹ�����ִ���ʽ��
    (2). ��ϵͳĬ�Ϸ�ʽ����
            ���ڳ���Ϊ0��ϵͳĬ�Ϸ�ʽ����ֹ�ý��̡�
    (3). �ṩһ���������źŷ����ǵ��øú������ⱻ��Ϊ��׽���źš�
            ͨ���ṩ�Ա�ĺ��������Ǿ���֪��ʲôʱ��������źţ����������ķ�ʽ��������

&emsp;��**�����źţ�**

    (1).�ն˼��̲����ź�
        �жϼ�(interrupt key)��Delete�� �� Ctrl+C
        �˳���(quit key)��Ctrl+\
    (2).����kill����
        ��һ�������е��ô˺����Ϳ�����һ�����̷���һ���źš�
        ���ƣ�����һ�����̷����ź�ʱ���������Ǹ����̵������߻����ǳ����û���

&emsp;������[shell2.c](����/chapter1/shell2.c)

&emsp;�����ô˳���Ȼ�����жϼ�����ִ�д˳���Ľ�����ֹ��

&emsp;��ԭ�򣺶��ڴ��ź�(SIGINT)��ϵͳĬ�϶�������ֹ���̡��ý���û�и���ϵͳ�ں�Ӧ����δ�����źţ�����ϵͳ��Ĭ�Ϸ�ʽ��ֹ�ý��̡�

## <span id="1.10">1.10 ʱ��ֵ</span>

&emsp;��**UNIXϵͳ��ʱ��ֵ��**

    (1).����ʱ�䡣
            ��ֵ����Э������ʱ(Coordinated Universal Time, UTC)����1970��1��1�� 00:00:00����ض�ʱ�������������������ۼ�ֵ��
            ϵͳ������������time_t���ڱ�������ʱ��ֵ��
    (2)������ʱ�䡣Ҳ��ΪCPUʱ�䡣
            ���Զ�������ʹ�õ�CPU��Դ������ʱ����ʱ�ӵδ���㡣
            ϵͳ������������clock_t��������ʱ��ֵ
            [2.5.4��](#2.5.4)˵�������sysconf�����õ�ÿ���ʱ�ӵδ�����

&emsp;��**������һ�����̵�ִ��ʱ��ʱ[(��3.9��)](#3.9)��UNIXϵͳΪһ������ά����3������ʱ��ֵ��**

    - ʱ��ʱ��
        �ֳ�Ϊ *ǽ��ʱ��ʱ��(wall clock time)*���ǽ������е�ʱ����������ֵ��ϵͳ��ͬʱ���еĽ������йء�
        �����ᵽʱ��ʱ��ʱ��������ϵͳ��û�������ʱ���ж�����
    - �û�CPUʱ��
        ��ִ���û�ָ�����õ�ʱ������
    - ϵͳCPUʱ�䡣
        ��Ϊ�ý���ִ���ں˳�����������ʱ�䡣
&emsp;��[8.17��](#8.17)��˵��һ�����н������ȡ����3��ʱ�䡣����ʱ������ڵ�һ��˵����[6.10��](#6.10)

## <span id="1.11">1.11 ϵͳ���úͿ⺯��</span>

&emsp;�����еĲ���ϵͳ���ṩ���ַ������ڵ㣬�д˳������ں����������Щ��ڵ㱻��Ϊ *ϵͳ����(system call)*��

&emsp;��UNIX��ʹ�õļ�����Ϊÿ��ϵͳ�����ڱ�׼C��������һ��������ͬ���ֵĺ���

&emsp;�������滻�⺯��������ϵͳ����ͨ���ǲ��ܱ��滻�ġ�

&emsp;�������ں��е�ϵͳ���÷���һ��ռ�����̣���ι���õ�ַ�ռ�ȡ���ڽ��̡�
    �⺯��malloc�����û���ι�����һ�ռ䡣

&emsp;��ϵͳ���úͿ⺯���Ĳ��
        ϵͳ����ͨ���ṩһ����С�ӿڣ����⺯��ͨ���ṩ�Ƚϸ��ӵĹ��ܡ�
        �������������I/O����[(��������)](#chapter3)�ͱ�׼I/O����[(��������)](#chapter5)��
            [8.13��](#8.13)��˵��system������һ��ʵ�֣���ʹ�û����Ľ��̿���ϵͳ���á�
            [10.18��](#10.18)��ǿ����һʵ������ȷ�ش����źš�

# <span id="chapter2">�ڶ��� UNIX��׼��ʵ��</span>

## <span id="2.1">2.1 ����</span>

## <span id="2.2">2.2 UNIX��׼��</span>

### <span id="2.2.1">2.2.1 ISO C</span>

<center>ͼ2-1 ISO C��׼�����ͷ�ļ�</center>

|    ͷ�ļ�    | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |              ˵��              |
|:------------:|:-----------:|:-----------:|:---------------:|:----------:|:------------------------------:|
|  <assest.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          ��֤�������          |
| <complex.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |        ������������֧��        |
|  <ctype.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |       �ַ������ӳ��֧��       |
|  <errno.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |     ������[(1.7��)](#1.7)      |
|   <fenv.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            ���㻷��            |
|  <float.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         ���㳣��������         |
| <inttypes.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          ���͸�ʽ�任          |
|  <iso646.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    ��ֵ����ϵ��һԪ��������    |
|  <limits.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    ʵ�ֳ���[(2.5��)](#2.5)     |
|  <locale.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |      ���ػ������ض���      |
|   <math.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    ��ѧ��������������������    |
|  <setjmp.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |  �Ǿֲ�goto[(7.10��)](#7.10)   |
|  <signal.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |   �ź�[(��ʮ��)](#chapter10)   |
|  <stdarg.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         �ɱ䳤�Ȳ�����         |
| <stdbool.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          �������ͺ�ֵ          |
|  <stddef.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            ��׼����            |
|  <stdint.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |              ����              |
|  <stdio.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   | ��׼I/O��[(������)](#chapter5) |
|  <stdlib.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            ʹ�ú���            |
|  <string.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           �ַ�������           |
|  <tgmath.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |         ͨ��������ѧ��         |
|   <time.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |  ʱ�������[(6.10��)](#6.10)   |
|  <wchar.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    ����Ķ��ֽںͿ��ַ�֧��    |
|  <wctype.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |      ���ַ������ӳ��֧��      |


<a name="0.0.6"></a>
## [0.0.6](#2.2.2) (2018-11-05 22:33)

### <span id="2.2.2">2.2.2 IEEE POSIX</span>

POSIX:Portable Operating System Interface

<center>ͼ2-2 POSIX��׼����ı����ͷ�ļ�</center>

|     ͷ�ļ�      | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |                         ˵��                         |
|:---------------:|:-----------:|:-----------:|:---------------:|:----------:|:----------------------------------------------------:|
|     <aio.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                       �첽I/O                        |
|    <cpio.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                      cpio�鵵ֵ                      |
|   <dirent.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |               Ŀ¼��[(4.22��)](#4.22)                |
|    <dlfcn.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                       ��̬����                       |
|    <fcntl.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |              �ļ�����[(3.14��)](#3.14)               |
|   <fnmatch.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                    �ļ���ƥ������                    |
|    <glob.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                 ·����ģʽƥ��������                 |
|     <grp.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                ���ļ�[(6.4��)](#6.4)                 |
|    <iconv.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                  ���뼯�任ʹ�ó���                  |
|  <langinfo.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                     ������Ϣ����                     |
|  <monetary.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                    ���������뺯��                    |
|    <netdb.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                    �������ݿ����                    |
|  <nl_types.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                        ��Ϣ��                        |
|    <poll.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            ͶƱ����[(14.4.2��)](#14.4.2)             |
|   <pthread.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   | �߳�([��ʮһ��](#chapter11)��[��ʮ����](#chapter12)) |
|     <pwd.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |               �����ļ�[(6.2��)](#6.2)                |
|    <regex.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                      ������ʽ                      |
|    <sched.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                       ִ�е���                       |
|  <semaphore.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                        �ź���                        |
|   <strings.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                      �ַ�������                      |
|     <tar.h>     |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                      tar�鵵ֵ                       |
|   <termios.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           �ն�I/O[(��ʮ����)](#chapter18)            |
|   <unistd.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                       ���ų���                       |
|   <wordexp.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                      ����������                      |
|  <arpa/inet.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          ����������[(��ʮ����)](#chapter16)          |
|   <net/if.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |        �׽��ֱ��ؽӿ�[(��ʮ����)](#chapter16)        |
| <netinet/in.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            ��������ַ��[(16.3��)](#16.3)             |
| <netinet/tcp.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                   �������Э�鶨��                   |
|  <sys/mman.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                     �洢��������                     |
| <sys/select.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           select����[(14.4.1��)](#14.4.1)            |
| <sys/socket.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          �׽��ֽӿ�[(��ʮ����)](#chapter16)          |
|  <sys/stat.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |            �ļ�״̬[(������)](#chapter4)             |
| <sys/statvfs.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                     �ļ�ϵͳ��Ϣ                     |
|  <sys/times.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |              ����ʱ��[(8.17��)](#8.17)               |
|  <sys/types.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           ����ϵͳ��������[(2.8��)](#2.8)            |
|   <sys/un.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          UNIX���׽��ֶ���[(17.2��)](#17.2)           |
| <sys/utsname.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |                ϵͳ��[(6.9��)](#6.9)                 |
|  <sys/wait.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |               ���̿���[(8.6��)](#8.6)                |

<a name="0.0.7"></a>
## [0.0.7](#2.2.2) (2018-11-07 23:37)


<center>ͼ2-3 POSIX��׼�����XSI��ѡͷ�ļ�</center>

|      ͷ�ļ�      | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |               ˵��                |
|:----------------:|:-----------:|:-----------:|:---------------:|:----------:|:---------------------------------:|
|    <fmtmsg.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |           ��Ϣ��ʾ�ṹ            |
|     <ftw.h>      |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    �ļ�������[(4.22��)](#4.22)    |
|    <libgen.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |          ·����������           |
|     <ndbm.h>     |   &radic;   |             |     &radic;     |  &radic;   |            ���ݿ����             |
|    <search.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |              ������               |
|    <syslog.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   | ϵͳ������־��¼[(13.4��)](#13.4) |
|    <utmpx.h>     |             |   &radic;   |     &radic;     |  &radic;   |          �û��˻����ݿ�           |
|   <sys/ipc.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |       IPC[(15.6��)](#15.6)        |
|   <sys/msg.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |   XSI��Ϣ����[(15.7��)](#15.7)    |
| <sys/resource.h> |   &radic;   |   &radic;   |     &radic;     |  &radic;   |     ��Դ����[(7.11��)](#7.11)     |
|   <sys/sem.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |    XSI�ź���[(15.8��)](#15.8)     |
|   <sys/shm.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |   XSI����洢[(15.9��)](#15.9)    |
|   <sys/time.h>   |   &radic;   |   &radic;   |     &radic;     |  &radic;   |             ʱ������              |
|   <sys/uio.h>    |   &radic;   |   &radic;   |     &radic;     |  &radic;   |   ʸ��I/O����[(14.6��)](#14.6)    |


<center>ͼ2-4 POSIX��׼����Ŀ�ѡͷ�ļ�</center>

|   ͷ�ļ�   | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 | ˵��          |
|:----------:|:-----------:|:-----------:|:---------------:|:----------:| ------------- |
| <mqueue.h> |   &radic;   |   &radic;   |                 |  &radic;   | ��Ϣ����      |
| <spawn.h>  |   &radic;   |   &radic;   |     &radic;     |  &radic;   | ʵʱspawn�ӿ� |

<a name="0.0.8"></a>
## [0.0.8](#2.2.2) (2018-11-08 22:14)

<center>ͼ2-5 POSIX.1 ��ѡ�ӿ����ѡ����</center>

| ѡ���� | SUSǿ�Ƶ� |             ���ų���              |              ˵��              |
|:------:|:---------:|:---------------------------------:|:------------------------------:|
|  ADV   |           |       _POSIX_ADVISORY_INFO        |        ��������Ϣ(ʵʱ)        |
|  CPT   |           |          _POSIX_CPUTIME           |     ����CPUʱ��ʱ��(ʵʱ)      |
|  FSC   |  &radic;  |           _POSIX_FSYNC            |            �ļ�ͬ��            |
|  IP6   |           |            _POSIX_IPV6            |            IPv6�ӿ�            |
|   ML   |           |          _POSIX_MEMLOCK           |      ���̴洢������(ʵʱ)      |
|  MLR   |           |       _POSIX_MEMLOCK_RANGE        |       �洢�������(ʵʱ)       |
|  MON   |           |      _POSIX_MONOTONIC_CLOCK       |         ����ʱ��(ʵʱ)         |
|  MSG   |           |      _POSIX_MESSAGE_PASSING       |         ��Ϣ����(ʵʱ)         |
|   MX   |           |         __STDC_IEC_559__          |        IEC60559����ѡ��        |
|  PIO   |           |      _POSIX__PRIORITIZED_IO       |         ������������         |
|   PS   |           |  _POSIX__PRIORITIZED_SCHEDULING   |         ���̵���(ʵʱ)         |
|  RPI   |           | _POSIX_THREAD_ROBUST_PRIO_INHERIT |  ��׳�Ļ���������Ȩ�̳�(ʵʱ)  |
|  RPP   |           | _POSIX_THREAD_ROBUST_PRIO_PROTECT |  ��׳�Ļ���������Ȩ����(ʵʱ)  |
|   RS   |           |        _POSIX_RAW_SOCKETS         |           ԭʼ�׽���           |
|  SHM   |           |   _POSIX_SHARED_MEMORY_OBJECTS    |       ����洢����(ʵʱ)       |
|  SIO   |           |      _POSIX_SYNCHRONIZED_IO       |      ͬ����������(ͬʱ)      |
|  SPN   |           |           _POSIX_SPAWN            |           ����(ʵʱ)           |
|   SS   |           |      _POSIX_SPORADIC_SERVER       |     �������Է�����(ʵʱ)     |
|  TCT   |           |       _POSIX_THREAD_CPUTIME       |     �߳�CPUʱ��ʱ��(ʵʱ)      |
|  TPI   |           |    _POSIX_THREAD_PRIO_INHERIT     | �ǽ�׳�Ļ���������Ȩ�̳�(ʵʱ) |
|  TPP   |           |    _POSIX_THREAD_PRIO_PROTECT     | �ǽ�׳�Ļ���������Ȩ����(ʵʱ) |
|  TPS   |           | _POSIX_THREAD_PRIORITY_SCHEDULING |       �߳�ִ�е���(ʵʱ)       |
|  TSA   |  &radic;  |   _POSIX_THREAD_ATTR_STACKADDR    |         �߳�ջ��ַ����         |
|  TSH   |  &radic;  |   _POSIX_THREAD_PROCESS_SHARED    |        �߳̽��̹���ͬ��        |
|  TSP   |           |   _POSIX_THREAD_SPORADIC_SERVER   |     �߳����Է�����(ʵʱ)     |
|  TSS   |  &radic;  |   _POSIX_THREAD_ATTR_STACKSIZE    |         �߳�ջ��������         |
|  TYM   |           |    _POSIX_TYPED_MEMORY_OBJECTS    |       ���ʹ洢����(ʵʱ)       |
|  XSI   |  &radic;  |            _XOPEN_UNIX            |         X/Open����ӿ�         |


POSIX.1 û�а��������û�(superuser)�����ĸ����֮�Թ��ƶ�ĳЩ����Ҫ��"�ʵ�������Ȩ"��


### <span id="2.2.3">2.2.3 Single UNIX Speification</span>

**Single UNIX Speification(SUS,��һUNIX�淶)** ��POSIX.1��׼��һ��������������һЩ���ӽӿ���չ��POSIX.1�淶�ṩ�Ĺ��ܡ�

POSIX.1�е� **X/Openϵͳ�ӿ�(X/Open System Interface,XSI)** ѡ�������˿�ѡ�Ľӿڣ�Ҳ��������ѭ **XSI(XSI conforming)** ��ʵ�ֱ���֧��POSIX.1����Щ��ѡ���֡�
����֧�ֵĲ��ְ����� **�ļ�ͬ�����߳�ջ��ַ�ͳ������ԡ��߳̽��̹���ͬ���Լ�_XOPEN_UNIX���ų�����**
��ѡ�ӿڷ�Ϊ����ѡ����(option group):
- **���ܣ�** �ɷ��ų���_XOPEN_CRYPE��ǡ�
- **ʵʱ��** �ɷ��ų���_XOPEN_REALTIME��ǡ�
- **�߼�ʵʱ��**
- **ʵʱ�̣߳�** �ɷ��ų���_XOPEN_REALTIME_THREADS��ǡ�
- **�߼�ʵʱ�̡߳�**

### <span id="2.2.4">2.2.4 FIPS</span>

FIPS������� **������Ϣ�����׼(Fedral Information Processing Standard)��**

<a name="0.0.9"></a>
## [0.0.9](#2.3) (2018-11-09 23:44)

## <span id="2.3">2.3 UNIX ϵͳʵ��</span>

UNIX��������֧
- AT&T��֧���Ӵ�������ϵͳ���ϵͳ��(����ΪUNIXϵͳ��������ð汾)
- ���ݴ�ѧ��������У��֧���Ӵ�����4.xBSDʵ�֡�
- ��AT&T����ʵ���ҵļ����ѧ�о����Ĳ��Ͽ�����UNIX�о��汾���Ӵ�����UNIX��ʱϵͳ��8�桢��9�棬��ֹ��1990��ĵ�10�档

<a name="0.0.10"></a>
## [0.0.10](#2.3) (2018-11-11 12:34)
### <span id="2.3.1">2.3.1 SVR4</span>

**SVR4(UNIX System V Release 4):** ������ϵͳ�Ĺ��ܺϲ�����һ��һ�µĲ���ϵͳ�У�AT&T UNIXϵͳV 3.2��(SVR3.2)��Sun Microsystems��˾��SunOS����ϵͳ�����ݴ�ѧ��������У��4.3BSD�Լ�΢���Xenixϵͳ��

### <span id="2.3.2">2.3.2 4.4BSD</span>

**BSD(Berkeley Software Distribution)**

### <span id="2.3.3">2.3.3 FreeBSD</span>

FreeBSD����4.4BSD-Lite����ϵͳ��

### <span id="2.3.4">2.3.4 Linux</span>

Linux��һ���ṩ������UNIX�ķḻ��̻����Ĳ���ϵͳ����GNU�������֤��ָ���£�Linux�����ʹ�õ�

### <span id="2.3.5">2.3.5 Mac OS X</span>

### <span id="2.3.6">2.3.6 Solaris</span>

Solaris����Sun Microsystems(��ΪOracle)������UNIXϵͳ�汾��

### <span id="2.3.7">2.3.7 ����UNIXϵͳ</span>

- AIX��IBM���UNIXϵͳ
- HP-UX��HP���UNIXϵͳ
- IRIX��Silicon Graphics���UNIXϵͳ
- Unix Ware��SVR4������UNIXϵͳ������SCO����

## <span id="2.4">2.4 ��׼��ʵ�ֵĹ�ϵ</span>

## <span id="2.5">2.5 ����</span>

**�����������͵������Ǳ���ģ�**

- ����ʱ����(���������͵����ֵ��ʲô��)
- ����ʱ����(�����ļ����ж��ٸ��ַ���)

����ʱ���ƿ���ͷ�ļ��ж��塣
����ʱ������Ҫ����̵���һ�������������ֵ��

ĳЩ������һ��������ʵ�����ǹ̶��ģ�������һ��ʵ����������Ǳ䶯�ġ�(�����ļ���������ַ���)
����������⣬�ṩһ��3�����ƣ�

- **����ʱ����(ͷ�ļ�)**
- **���ļ���Ŀ¼�޹ص�����ʱ����(sysconf����)**
- **���ļ���Ŀ¼�йص�����ʱ����(pathconf��fpathconf����)**

### <span id="2.5.1">2.5.1 ISO C����</span>
ISO C��������б���ʱ���ƶ�����ͷ�ļ�<limits.h>��(��ͼ2.-6)

<center>ͼ2-6 <limits.h>�ж��������ֵ��С</center>

|    ����    |                ˵��                |       �ɽ��ܵ���Сֵ       |           ����ֵ            |
|:----------:|:----------------------------------:|:--------------------------:|:---------------------------:|
|  CHAR_BIT  |             char��λ��             |             8              |              8              |
|  CHAR_MAX  |            char�����ֵ            |           (����)           |             127             |
|  CHAR_MIN  |            char����Сֵ            |           (����)           |            -128             |
| SCHAR_MAX  |        signed char�����ֵ         |            127             |             127             |
| SCHAR_MIN  |        signed char����Сֵ         |            -127            |            -128             |
| UCHAR_MAIX |       unsigned char�����ֵ        |            255             |             255             |
|  INT_MAX   |            int�����ֵ             |           32 767           |        2 147 483 647        |
|  INT_MIN   |            int����Сֵ             |          -32 767           |       -2 147 483 648        |
|  UINT_MAX  |        unsigned int�����ֵ        |           65 535           |        4 294 967 295        |
|  SHRT_MAX  |           short�����ֵ            |           32 767           |           32 767            |
|  SHRT_MIN  |           short����Сֵ            |          -32 767           |           -32 768           |
| USHRT_MAX  |       unsigned short�����ֵ       |           65 535           |           65 535            |
|  LONG_MAX  |            long�����ֵ            |       2 147 483 647        |        2 147 483 647        |
|  LONG_MIN  |            long����Сֵ            |       -2 147 483 647       |       -2 147 483 647        |
| ULONG_MAX  |       unsigned long�����ֵ        |       4 294 967 295        |        4 294 967 295        |
| LLONG_MAX  |         long long�����ֵ          | 9 223 372 036 854 775 807  |  9 223 372 036 854 775 807  |
| LLONG_MIN  |         long long����Сֵ          | -9 223 372 036 854 775 807 | - 9 223 372 036 854 775 807 |
| ULLONG_MAX |     unsigned long long�����ֵ     | 18 446 744 073 709 551 614 | 18 446 744 073 709 551 614  |
| MB_LEN_MAX | ��һ�����ֽ��ַ������е�����ֽ��� |             1              |              6              |

<center>ͼ2-7 �ڸ���ƽ̨��ISO������</center>

| ����         | FreeBSD 8.0 | Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10 |
|:------------ | -----------:| -----------:| ---------------:| ----------:|
| FOPEN_MAX    |          20 |          16 |              20 |         20 |
| TMP_MAX      | 308 915 776 |     238 328 |     308 915 776 |     17 576 |
| FILENAME_MAX |        1024 |        4096 |            1024 |       1024 |

### <span id="2.5.2">2.5.2 POSIX����</span>

��POSIX.1�ӿ��йص����ƺͳ���

- **��ֵ���ƣ�** LONG_BIT��SSIZE_MAX��WORD_BIT��
- **��Сֵ��** ͼ2-8�е�25��������
- **���ֵ��**  \_POSIX_CLOCKRES_MIN
- **����ʱ�������ӵ�ֵ��** CHARCLASS_NAME_MAX��COLL_WEIGHTS_MAX��LINE_MAX��NGROUPS_MAX��RE_DUP_MAX��
- **����ʱ����ֵ(���ܲ�ȷ��)��** ͼ2-9�е�17������(����[12.2��](#12.2)�н��ܵ�4��������[14.5��](#14.5)�н��ܵ�3������)��
- **��������ֵ��** NL_ARGMAX��NL_MSGMAX��NL_SETMAX��NL_TEXTMAX��
- **·�����ɱ�ֵ��** FILESIZEBITS��LINK_MAX��MAX_CANON��MAX_INPUT��NAME_MAX��PATH_MAX��PIPE_BUF��SYMLINK_MAX��
[2.5.4��](#2.5.4)��˵��sysconf��pathconf��fpathconf������

<center>ͼ2-8 <limits.h>�е�POSIX.1��Сֵ</center>

| ����                  | ˵������С�ɽ���ֵ                                                              |     ֵ |
|:--------------------- |:------------------------------------------------------------------------------- | ------:|
| _POSIX_ARG_MAX        | exec�����Ĳ�������                                                              |  4 096 |
| _POSIX_CHILD_MAX      | ÿ��ʵ���û�ID���ӽ�����                                                        |     25 |
| _POSIX_DELAYTIMER_MAX | ��ʱ����������д���                                                          |     32 |
| _POSIX_HOST_NAME_MAX  | gethostname�������ص�����������                                                 |    255 |
| _POSIX_LINK_MAX       | ��һ���ļ���������                                                              |      8 |
| _POSIX_LOGIN_NAME_MAX | ��¼���ĳ���                                                                    |      9 |
| _POSIX_MAX_CANON      | �ն˹淶������е��ֽ���                                                        |    255 |
| _POSIX_MAX_INPUT      | �ն�������еĿ��ÿռ�                                                          |    255 |
| _POSIX_HOST_NAME_MAX  | �ļ����е��ֽ�������������null�ֽ�                                              |     14 |
| _POSIX_NGROUPS_MAX    | ÿ������ͬʱ��ӵ���ID��                                                        |      8 |
| _POSIX_OPEN_MAX       | ÿ�����̵Ĵ��ļ���                                                            |     20 |
| _POSIX_PATH_MAX       | ·�����е��ֽ�����������ֹnull�ֽ�                                              |    256 |
| _POSIX_PIPE_BUF       | ��ԭ�ӵ�д��һ���ܵ��е��ֽ���                                                  |    512 |
| _POSIX_RE_DUP_MAX     | ��ʹ�ü����ʾ��\{m,n\}ʱ��regexec��regcomp��������Ļ���������ʽ�ظ��������� |    255 |
| _POSIX_RTSIG_MAX      | ΪӦ��Ԥ����ʵʱ�źű�Ÿ���                                                    |      8 |
| _POSIX_SEM_NSEMS_MAX  | һ�����̿���ͬʱʹ�õ��ź�������                                                |    256 |
| _POSIX_SEM_VALUE_MAX  | �ź����ɳ��е�ֵ                                                                | 32 767 |
| _POSIX_SIGQUEUE_MAX   | һ�����̿ɷ��ͺ͹����Ƭ���źŵĸ���                                            |     32 |
| _POSIX_SSIZE_MAX      | �ܴ���ssize_t�����е�ֵ                                                         | 32 767 |
| _POSIX_STREAM_MAX     | һ��������ͬʱ�򿪵ı�׼I/O����                                                 |      8 |
| _POSIX_SYMLINK_MAX    | ���������е��ֽ���                                                              |    255 |
| _POSIX_SYMLOOP_MAX    | �ڽ���·����ʱ���ɱ����ķ���������                                              |      8 |
| _POSIX_TIMER_MAX | ÿ�����̵Ķ�ʱ����Ŀ                                                            |     32 |
| _POSIX_TTY_NAME_MAX   | �ն��豸�����ȣ�������ֹnull�ֽ�                                                |      9 |
| _POSIX_TZNAME_MAX     | ʱ�����ֽ���                                                                    |      6 |

<center>ͼ2-9 <limits.h>�е�POSIX.1����ʱ����ֵ</center>

| ����           | ˵��                                    | ��С�ɽ���ֵ          |
|:-------------- |:--------------------------------------- |:--------------------- |
| ARG_MAX        | exec������Ĳ�����󳤶�                | _POSIX_ARG_MAX        |
| ATEXIT_MAX     | ����atexit�����Ǽǵ����������        | 32                    |
| CHILD_MAX      | ÿ��ʵ���û�ID���ӽ���������          | _POSIX_CHILD_MAX      |
| DELAYTIMER_MAX | ��ʱ����󳬶����д���                  | _POSIX_DELAYTIMER_MAX |
| HOST_NAME_MAX  | gethostname���ص�����������             | _POSIX_HOST_NAME_MAX  |
| LOGIN_NAME_MAX | ��¼����󳤶�                          | _POSIX_LOGIN_NAME_MAX |
| OPEN_MAX       | �����½��ļ������������ֵ+1            | _POSIX_OPEN_MAX       |
| PAGESIZE       | ϵͳ�ڴ�ҳ��С(���ֽ�Ϊ��λ)            | 1                     |
| RTSIG_MAX      | ΪӦ�ó���Ԥ����ʵʱ�ź�������        | _POSIX_RTSIG_MAX      |
| SEM_NSEMS_MAX  | һ�����̿�ʹ�õ��ź���������          | _POSIX_SEM_NSEMS_MAX  |
| SEM_VALUE_MAX  | �ź��������ֵ                          | _POSIX_SEM_VALUE_MAX  |
| SIGQUEUE_MAX   | һ�����̿��Ŷ��źŵ�������            | _POSIX_SIGQUEUE_MAX   |
| STREAM_MAX     | һ������һ�οɴ򿪵ı�׼I/O���������� | _POSIX_STREAM_MAX     |
| SYMLOOP_MAX    | ·�����������пɷ��ʵķ���������        | _POSIX_SYMLOOP_MAX    |
| TIMER_MAX      | һ�����̵Ķ�ʱ��������                | _POSIX_TIMER_MAX      |
| TTY_NAME_MAX   | �ն��豸�����ȣ����а�����ֹ��null�ֽ�  | _POSIX_TTY_NAME_MAX   |
| TZNAME_MAX     | ʱ�������ֽ���                          | _POSIX_TZNAME_MAX     |


### <span id="2.5.3">2.5.3 XSI����</span>

**XSI�����˴���ʵ�����Ƶļ���������**
- ��Сֵ��ͼ2-10���г���5��������
- ����ʱ����ֵ(���ܲ�ȷ��)��IOV_MAX��PAGE_SIZE��

<center>ͼ2-10 <limits.h>�е�XSI��Сֵ</center>

| ����            | ˵��                                   | ��С�ɽ���ֵ | ����ֵ |
|:--------------- |:-------------------------------------- | ------------:| ------:|
| NL_LANGMAX      | ��LANG��������������ֽ���             |           14 |     14 |
| NZERO           | Ĭ�Ͻ������ȼ�                         |           20 |     20 |
| _XOPEN_IOV_MAX  | readv��writev��ʹ�õ����iovec�ṹ���� |           16 |     16 |
| _XOPEN_NAME_MAX | �ļ����е��ֽ���                       |          255 |    255 |
| _XOPEN_PATH_MAX | ·�����е��ֽ���                       |         1024 |   1024 |

### <span id="2.5.4">2.5.4 ����sysconf��pathconf��fpathconf</span>

```C
#include <unistd.h>

long sysconf(int name);
long pathconf(const char *pathname, int name);
long fpathconf(int fd, int name);
```
**���к�������ֵ�����ɹ���������Ӧֵ������������-1(����)**
�������������Ĳ���ǣ�**һ����·������Ϊ���������һ����ȡ�ļ���������Ϊ������**

������3��������ͬ�ķ���ֵ��

- *���name����������һ�����ʵĳ�������3�����������أ�����errno��ΪEINVAL��
    ͼ2-11��ͼ2-12�ĵ����и������������������н�Ҫ�漰�����Ƴ�����*
- *��Щname�᷵��һ������ֵ(����ֵ$\ge$0)������ʾ��ֵ�ǲ�ȷ���ġ���ȷ����ֵͨ������-1�����֣������ı�errno��ֵ��*
- *_SC_CLK_TCK�ķ���ֵ��ÿ���ʱ�ӵδ���������times�����ķ���ֵ([8.17��](#8.17))��*

����pathconf�Ĳ���pathname��fpathconf�Ĳ���fd�кܶ����ơ���������������κ�һ�����ƣ�������δ����ġ�

- *_PCMAX_CANON��_PC_MAX_INPUT���õ��ļ��������ն��ļ���*
- *_PC_LINK_MAX��_PC_TIMESTAMP_RESOLUTION���õ��ļ��������ļ���Ŀ¼�������Ŀ¼���򷵻�ֵ����Ŀ¼������������Ŀ¼�ڵ��ļ����*
- *_PC_FILESIZEBITS��_PC_NAME_MAX���õ��ļ�������Ŀ¼������ֵ���ڸ�Ŀ¼�е��ļ�����*
- *_PC_PATH_MAX���õ��ļ�������Ŀ¼����ָ����Ŀ¼�ǹ���Ŀ¼ʱ������ֵ�����·��������󳤶�(���ⲻ��������Ҫ֪����һ������·������ʵ����󳤶ȣ�[2.5.5��](#2.5.5)���ٴλص���һ����)��*
- *_PC_PIPE_BUF���õ��ļ������ǹܵ���FIFO��Ŀ¼���ڹܵ���FIFO����£�����ֵ�Ƕ������õĹܵ���FIFO������ֵ������Ŀ¼������ֵ�Ƕ��ڸ�Ŀ¼�д�������һFIFO������ֵ��*
- *_PC_SYMLINK_MAX���õ��ļ�������Ŀ¼������ֵ�Ǹ�Ŀ¼�з������ӿɰ����ַ�������󳤶ȡ�*

<center>ͼ2-11 ��sysconf�����Ƽ�name����</center>

| ������           | ˵��                                                                                      | name����             |
|:---------------- |:----------------------------------------------------------------------------------------- |:-------------------- |
| ARG_MAX          | exec������Ĳ�����󳤶�(�ֽ�)                                                            | _SC_ARG_MAX          |
| ATEXIT_MAX       | ����atexit�����Ǽǵ����������                                                          | _SC_ATEXIT_MAX       |
| CHILD_MAX        | ÿ��ʵ���û�ID������ӽ�����                                                              | _SC_CHILD_MAX        |
| ʱ�ӵδ�/��      | ÿ��ʱ�ӵδ���                                                                            | _SC_CLK_TCK          |
| COLL_WEIGHTS_MAX | �ڱ��ض����ļ��п��Ը���LC_COLLATE˳��ؼ���������Ȩ����                                | _SC_COLL_WEIGHTS_MAX |
| DELAYTIMER_MAX   | ��ʱ����������д���                                                                    | _SC_DELAYTIMER_MAX   |
| HOST_NAME_MAX    | gethostname�������ص���������󳤶�                                                       | _SC_HOST_NAME_MAX    |
| IOV_MAX          | readv��writev����ʹ������iovec�ṹ�ĸ���                                                | _SC_IOV_MAX          |
| LINE_MAX         | ʹ�ó��������е���󳤶�                                                                  | _SC_LINE_MAX         |
| LOGIN_NAME_MAX   | ��¼������󳤶�                                                                          | _SC_LOGIN_NAME_MAX   |
| NGROUPS_MAX      | ÿ������ͬʱ��ӵ���������ID��                                                          | _SC_NGROUPS_MAX      |
| OPEN_MAX         | ÿ�����������ļ���                                                                    | _SC_OPEN_MAX         |
| PAGESIZE         | ϵͳ�洢ҳ����(�ֽ���)                                                                    | _SC_PAGESIZE         |
| PAGE_SIZE        | ϵͳ�洢ҳ����(�ֽ���)                                                                    | _SC_ARG_MAXPAGE_SIZE |
| RE_DUP_MAX       | ��ʹ�ü����ʾ��\{m,n\}ʱ��regexec��regcomp��������Ļ���������ʽ�ظ���������           | _SC_RE_DUP_MAX       |
| RTSIG_MAX        | ΪӦ�ó���Ԥ����ʵʱ�źŵ�������                                                        | _SC_RTSIG_MAX        |
| SEM_NSEMS_MAX    | һ�����̿�ʹ�õ��ź���������                                                            | _SC_SEM_NSEMS_MAX    |
| SEM_VALUE_MAX    | �ź��������ֵ                                                                            | _SC_SEM_VALUE_MAX    |
| SIGQUEUE_MAX     | һ�����̿�һ�����̿��Ŷ��źŵ�������                                                    | _SC_SIGQUEUE_MAX     |
| STREAM_MAX       | һ��_SCSTREAM_MAX�������������ʱ�̱�׼I/O������������������壬������FOPEN_MAX����ֵͬ | _SC_STREAM_MAX       |
| SYMLOOP_MAX      | �ڽ���·����ʱ���ɱ����ķ���������                                                        | _SC_SYMLOOP_MAX      |
| TIMER_MAX        | ÿ�����̵����ʱ������                                                                  | _SC_TIMER_MAX        |
| TTY_NAME_MAX     | �ն��豸�����ȣ�������ֹnull�ֽ�                                                          | _SC_TTY_NAME_MAX     |
| TZNAME_MAX       | ʱ�����е�����ֽ���                                                                      | _SC_TZNAME_MAX       |

<center>ͼ2-12 ��pathconf��fpathconf�����Ƽ�name����</center>

| ������                      | ˵��                                                                    | name����                 |
|:--------------------------- |:----------------------------------------------------------------------- |:------------------------ |
| FILESIZEBITS                | �Դ���������ֵ��ʾ��ָ��Ŀ¼���������ͨ�ļ���󳤶��������Сλ(bit)�� | _PC_FILESIZEBITS         |
| LINK_MAX                    | �ļ����Ӽ��������ֵ                                                    | _PC_LINK_MAX             |
| MAX_CANON                   | �ն˹淶������е�����ֽ���                                            | _PC_MAX_CANON            |
| MAX_INPUT                   | �ն�������п��ÿռ���ֽ���                                            | _PC_MAX_INPUT            |
| NAME_MAX                    | �ļ���������ֽ���(��������ֹnull�ֽ�)                                  | _PC_NAME_MAX             |
| PATH_MAX                    | ���·����������ֽ�����������ֹnull�ֽ�                                | _PC_PATH_MAX             |
| PIPE_BUF                    | ��ԭ�ӵ�д���ܵ�������ֽ���                                            | _PC_PIPE_BUF             |
| _POSIX_TIMESTAMP_RESOLUTION | �ļ�ʱ��������뾫��                                                    | _PC_TIMESTAMP_RESOLUTION |
| SYMLINK_MAX                 | �������ӵ��ֽ���                                                        | _PC_SYMLINK_MAX          |

����[makeconf.awk](����/chapter2//standards/makeopt.awk)����ӡ��pathconf��sysconf���ŵ�ֵ��
    [conf.c.modified](����/chapter2//standards/conf.c.modified)����awk������C���򣬴�ӡ������Щ���ƣ�������δ�������Ƶ������

<center>ͼ2-15 �������Ƶ�ʵ��</center>

| ����               | FreeBSD 8.0 |   Linux 3.2.0 | Mac OS X 10.6.8 | Solaris 10(UFS�ļ�ϵͳ) | Solaris 10(:�ļ�ϵͳ) |
|:------------------ | -----------:| -------------:| ---------------:| -----------------------:| ---------------------:|
| ARG_MAX            |     262 144 |     2 097 152 |         262 144 |               2 096 640 |             2 096 640 |
| ATEXIT_MAX         |          32 | 2 147 483 647 |   2 147 483 647 |                  ������ |                ������ |
| CHARCLASS_NAME_MAX |      �޷��� |         2 048 |              14 |                      14 |                    14 |
| CHILD_MAX          |       1 760 |        47 211 |             266 |                   8 021 |                 8 021 |
| ʱ�ӵδ�/��        |         128 |           100 |             100 |                     100 |                   100 |
| COLL_WEIGHTS_MAX   |           0 |           255 |               2 |                      10 |                    10 |
| FILESIZEBITS       |          64 |            64 |              64 |                      41 |                ��֧�� |
| HOST_NAME_MAX      |         255 |            64 |             255 |                     255 |                   255 |
| IOV_MAX            |       1 024 |         1 024 |           1 024 |                      16 |                    16 |
| LINE_MAX           |       2 048 |         2 048 |           2 048 |                   2 048 |                 2 048 |
| LINK_MAX           |      32 767 |        65 000 |          32 767 |                  32 767 |                     1 |
| LOGIN_NAME_MAX     |          17 |           256 |             255 |                       9 |                     9 |
| MAX_CANON          |         255 |           255 |           1 024 |                     256 |                   256 |
| MAX_INPUT          |         255 |           255 |           1 024 |                     512 |                   512 |
| NAME_MAX           |         255 |           255 |             255 |                     255 |                     8 |
| NGROUPS_MAX        |       1 023 |        65 536 |              16 |                      16 |                    16 |
| OPEN_MAX           |       3 520 |         1 024 |             256 |                     256 |                   256 |
| PAGESIZE           |       4 096 |         4 096 |           4 096 |                   8 192 |                 8 192 |
| PAGE_SIZE          |       4 096 |         4 096 |           4 096 |                   8 192 |                 8 192 |
| PATH_MAX           |       1 024 |         4 096 |           1 024 |                   1 024 |                 1 024 |
| PIPE_BUF           |         512 |         4 096 |             512 |                   5 120 |                 5 120 |
| RE_DUP_MAX         |         255 |        32 767 |             255 |                     255 |                   255 |
| STREAM_MAX         |       3 520 |            16 |              20 |                     256 |                   256 |
| SYMLINK_MAX        |       1 024 |        ������ |             255 |                   1 024 |                 1 024 |
| SYMLOOP_MAX        |          32 |        ������ |              32 |                      20 |                    20 |
| TTY_NAME_MAX       |         255 |            32 |             255 |                     128 |                   128 |
| TZNAME_MAX         |         255 |             6 |             255 |                  ������ |                ������ |

### <span id="2.5.5">2.5.5 ��ȷ��������ʱ����</span>
