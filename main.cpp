#include <iostream>
#include <cstring>

const int MaxSize = 7;
typedef struct DataType {
    char name[8];
    char sex[3];
    int age;
    int score;

    bool operator==(const DataType &data) {
        if (strcmp(name,data.name) && (age == age)) {
            return true;
        } else {
            return false;
        }
    }
} DataType;
typedef struct {
    DataType data[MaxSize];
    int length;
} SeqList;

SeqList student;

//线性表插入
SeqList InsertSeqList(SeqList L, DataType x, int i) {
    if (L.length == MaxSize) {
        printf("%s", "表已满！程序退出！");
        exit(0);
    } else if (i < 1 || i > L.length + 1) {
        printf("位置错误！");
        exit(0);
    } else {
        for (int j = L.length; j >= i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = x;
        L.length++;
    }
    return L;
}

//删除元素
SeqList DeleteSeqList(SeqList &L, int i) {
    if (L.length == MaxSize) {
        printf("%s", "表已满！程序退出！");
        exit(0);
    } else if (i < 1 || i > L.length + 1) {
        printf("位置错误！");
        exit(0);
    } else {
        for (int j = i; j < L.length; j++) {
            L.data[j - 1] = L.data[j];
        }
        L.length--;
    }
    return L;
}

//查找
int LocateSeqList(SeqList L, DataType x) {
    for (int i = 0; i < L.length; i++) {
        //C和C++都无法比较结构体是否相等，C需要一项一项比较，C++可以重载运算符bolean operator ==()
        if (L.data[i] == x) {
            return i+1;
        }
    }
    return 0;


}

int main() {


    DataType st1 = {"王涛", "男", 20, 589};
    DataType st2 = {"潘小欣", "女", 21, 580};
    DataType st3 = {"张艳", "女", 19, 568};
    DataType st4 = {"赵李军", "男", 18, 580};
    DataType st5 = {"刘勇", "男", 22, 585};

//    这种方式是错误的
//    DataType sts[]={st1,st2,st3,st4,st5};
//    SeqList student = {sts,5};

    //正确
    //SeqList student;
    student = {{st1, st2, st3, st4, st5}, 5};

    //正确
    /*SeqList student;
    student.data[0] = st1;
    student.data[1] = st2;
    student.data[2] = st3;
    student.data[3] = st4;
    student.data[4] = st5;
    student.length = 5;*/

    DataType st = {"stone", "男", 22, 585};
    SeqList L = InsertSeqList(student, st, 2);
    for (int i = 0; i < L.length; i++) {
        printf("%s%c", L.data[i].name, ',');
    }
    printf("\n*****************\n");


    DeleteSeqList(student, 1);
    for (int i = 0; i < student.length; i++) {
        printf("%s%c", student.data[i].name, ',');
    }
    printf("\n*****************\n");
    int index = LocateSeqList(student,st4);
    printf("%d",index);
    return 0;
}