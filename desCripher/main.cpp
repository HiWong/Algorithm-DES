#include "desCripher.h"
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int main()
{
	
	string key  = "cheng";					//Կ��
	string text = "Welcome to cheng's blog! www.cheng668.com";    //����
	string ent  = "";							//����
	string destring = "";						//��������

	//�޸���Կ��ʽ
	char key11[10];
	memset(key11, 0, 10);
	if (key.size() < 8)
		memcpy(key11, key.c_str(), sizeof(key.c_str()));
	else
		memcpy(key11, key.c_str(), 8);

	//�����ķֿ�ÿ8���ֽڽ��м���
	for (size_t i = 0;i<(text.length()+7)/8;i++)
	{
	    char entext[9],intext[9];
		memset(entext, 0, 9);
		memset(intext, 0, 9);
		_memccpy(intext, text.c_str() + 8 * i, NULL, 8);
		des_encrypt(intext, key11, entext, ENCRYPT);
		ent += entext;
	}
	cout << ent << endl;

	//������ת��Ϊÿ8���ֽڽ��н���
	for (size_t i = 0; i < (ent.length() + 7) / 8; i++)
	{
		char outtext[9],detext[9];
		memset(outtext, 0, 9);
		memset(detext, 0, 9);
		_memccpy(detext, ent.c_str() + 8 * i, NULL, 8);
		des_encrypt(detext, key11, outtext, DECRYPT);
		destring += outtext;
	}
	cout << destring << endl;
	system("pause");
	return 0;
}