#include<stdio.h>
#define MAX_STUDENTS 100
struct Student
{
    char name[20];
    int id;
    float score;
};
struct Student students[MAX_STUDENTS];
int count = 0;
void addStudent()
{
    printf("请输入学生姓名：\n");
    scanf("%s",&students[count].name);
    printf("请输入学生学号：\n");
    scanf("%d",&students[count].id);
    printf("请输入学生分数：\n");
    scanf("%f",&students[count].score);
    count++;
    printf("学生成绩添加成功!\n");
}
void displayStudents()
{
    printf("学生成绩列表：\n");
    for(int i=0;i<count;i++)
    {
        printf("姓名：%s,学号：%d,分数：%.2f\n",students[i].name,students[i].id,students[i].score);

    }
    printf("学生成绩显示成功!\n");
}
void searchStudent()
{
    int id;
    printf("请输入学生的学号：\n");
    scanf("%d",&id);
    for(int i=0;i<count;i++)
    {
        if(students[i].id == id)
        {
            printf("姓名：%s,学号：%d,分数:%.2f\n",students[i].name,students[i].id,students[i].score);
            return;
        }
    }
    printf("未找到该学生的成绩信息!\n");
}
void deleteStudent()
{
    int id;
    printf("请输入学生的学号:\n");
    scanf("%d",&id);
    for(int i=0;i<count;i++)
    {
        if(students[i].id == id)
        {
            for(int j=i;j<count-1;j++)
            {
                students[j] = students[j+1];
            }
            count--;
            printf("学生信息删除成功!\n");
            return;
        }
    }
    printf("未找到该学生的成绩信息！\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("学生成绩管理系统\n");
        printf("1.添加学生成绩\n");
        printf("2.显示学生成绩\n");
        printf("3.查询学生成绩\n");
        printf("4.删除学生成绩\n");
        printf("5.退出系统\n");
        printf("请输入你的选择:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("退出系统成功!\n");
                return 0;
            default:
                printf("无效选择，请重新输入!\n");
        }
    }
}