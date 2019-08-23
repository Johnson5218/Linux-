#pragma once
#include"HuffmanFile.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef unsigned char UCH;

struct CharInfo{
	CharInfo(size_t charCount = 0)
	:_charCount(charCount)
	{}

	CharInfo operator+(const CharInfo&  info)
	{
		return CharInfo(_charCount + info._charCount);
	}
	bool operator>(const CharInfo& info)
	{
		return _charCount > info._charCount;
	}
	bool operator != (const CharInfo& info)const
	{
		return _charCount != info._charCount;
	}
	bool operator == (const CharInfo& info)const
	{
		return _charCount == info._charCount;
	}

	UCH _ch;  //�ַ�
	size_t _charCount;//��ǰ�ַ����ִ���
	string _strCode;//�ַ��ñ���
};


class FileCompressHuffM
{
public:
	 FileCompressHuffM();
	void CompressFile(const string& strFilePath);
	void UNCompressFile(const string& strFilePath);
	void WriteHead(FILE* fOut, const string& strFilePath); //�ļ�ͷ����Ϣ
private:
	void HuffmanCode(HuffmanTreeNode<CharInfo>* proot);
	void GetLine(FILE* fIn, string& strContent); 
private:
	vector<CharInfo>_charInfo;
};