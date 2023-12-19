#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

#define Max 10000

using namespace std;
/*---��С��������---*/
class Tree{
private:
    int **map;                            //��ͼ
    int num;                              //�ڵ���Ŀ
    vector <pair <string, int> > name;	  //�ڵ����Ͷ�Ӧ�����
    vector <pair<int, int> > ans;         //��С����������
public:
    Tree() :map(NULL),num(0){}            //Ĭ�Ϲ��캯��
    ~Tree();                              //��������

    void A_InputName();                   //����ڵ�����
    void B_InputMap();                    //�����ͼ
    void C_buildTree();                   //������С������
    void D_print();                       //��ӡ��С������
};
/*---��������---*/
Tree::~Tree(){
    if (map != NULL)
        delete[] map;
}
/*---����ڵ�����---*/
void Tree::A_InputName(){
    if (!ans.empty()){
        cout << "��������С���������Ƿ�������" << endl << endl;
        return;
    }
    if (map != NULL){
        cout << "�����ɵ�ͼ�� �Ƿ�������" << endl << endl;
        return;
    }
    string temp;
    cout << "�����붥��ĸ���:";
    cin >> num;
    cout << "���������붥�������:" << endl;

    for (int i = 0; i < num; i++){
        cin >> temp;
        name.push_back(make_pair(temp, i));
    }
    cout << endl;
}
/*---�����ͼ---*/
void Tree::B_InputMap(){
    if (!ans.empty()){
        cout << "��������С���������Ƿ�������" << endl << endl;
        return;
    }
    if (num == 1){
        cout << "�Ƿ����и�����" << endl << endl;
        return;
    }

    map = new int*[num];
    for (int i = 0; i < num; i++)
        map[i] = new int[num];

    for (int i = 0; i < num - 1; i++){
        cout << "��������������������ľ��룬�����ھ���������-1: ";
        map[i][i] = 0;
        for (int k = i + 1; k < num; k++){
            cout << name[i].first << " ";
            cout << name[k].first << " ";
            cin >> map[i][k];
            if (map[i][k] == -1)
                map[i][k] = Max;
            if (k != num -1)
                cout << "��������������������ľ��룬�����ھ���������-1: ";
        }
    }

    for (int i = 0; i < num; i++){
        for (int k = 0; k < i; k++){
            map[i][k] = map[k][i];
        }
    }
    cout << endl;
}
/*---������С������---*/
void Tree::C_buildTree(){
    ans.clear();
    vector <pair <string, int> > store;
    pair <int, int> Min;
    string tempname;
    priority_queue < int, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > que;
    int min;
    int flag = 0;
    cout << "��������ʼ���㣺";
    cin >> tempname;
    for (int i = 0; i < name.size(); i++){
        if (tempname == name[i].first){
            store.push_back(name[i]);
            break;
        }
    }
    while (store.size() < num){
        min = 100000;
        //����
        for (int i = 0; i < store.size(); i++){
            for (int k = 0; k < num; k++){
                if (k == store[i].second)
                    continue;
                que.push(make_pair(map[store[i].second][k], make_pair(store[i].second, k)));
            }
        }
        //����
        for (int i = 0; i < name.size(); i++){
            if (que.top().second.second == name[i].second){
                store.push_back(name[i]);
                ans.push_back(make_pair(que.top().second.first, que.top().second.second));
            }
        }
        while (!que.empty())
            que.pop();
    }
    cout << "����Prim��С��������" << endl << endl;
}
/*---��ӡ��С������---*/
void Tree::D_print(){
    string name1, name2;
    cout << "��С�������Ķ����Լ���Ϊ��" << endl;
    for (int i = 0; i < ans.size(); i++){

        for (int k = 0; k < name.size(); k++){
            if (ans[i].first == name[k].second)
                name1 = name[k].first;
            if (ans[i].second == name[k].second)
                name2 = name[k].first;
        }

        cout << name1 << "-(" << map[ans[i].first][ans[i].second]
             << ")-" << name2 << "        ";
    }
    cout << endl << endl;
}


int main(){
    cout << "**                     �������ģ��ϵͳ                     **" << endl;
    cout << "==============================================================" << endl;
    cout << "**                     A---������������                     **" << endl;
    cout << "**                     B---��ӵ����ı�                     **" << endl;
    cout << "**                     C---������С������                   **" << endl;
    cout << "**                     D---��ʾ��С������                   **" << endl;
    cout << "**                     E---�˳�    ����                     **" << endl;
    cout << "==============================================================" << endl;

    char order;
    Tree tree;

    //Node * p = tree.create();

    cout << "��ѡ�����:";
    cin >> order;

    while (order != 'E'){
        switch (order){
            case 'A':
                tree.A_InputName();
                break;
            case 'B':
                tree.B_InputMap();
                break;
            case 'C':
                tree.C_buildTree();
                break;
            case 'D':
                tree.D_print();
                break;
            default:
                break;
        }
        cout << "��ѡ�����:";
        cin >> order;
    }
    return 0;
}
