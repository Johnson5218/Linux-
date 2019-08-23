#define _CRT_SECURE_NO_WARNINGS
#include"CompressFileH.h"
#include"HuffmanFile.hpp"
#include<vector>
#include<assert.h>

using namespace std;

FileCompressHuffM::FileCompressHuffM()
{
	_charInfo.resize(256); //����ռ�
	for (size_t i = 0; i < 256; ++i)
		_charInfo[i]._ch = i;
}

void FileCompressHuffM::CompressFile(const string& strFilePath){
	//1.��ȡԴ�ļ���ÿ���ַ����ֵĴ���
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		cout << "failed" << endl;
		return;
	}
	UCH* pReadBuff = new UCH[1024];

	while (1)
	{
		size_t rdsize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdsize)
		{
			break;
		}
		for (size_t i = 0; i < rdsize; ++i){
			_charInfo[pReadBuff[i]]._charCount++;
		}
	}
	//2.��ÿ���ַ����ֵĵĴ���ΪȨֵ����Huffman��
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo,CharInfo(0));
	
	//3.����Huffman����ȡÿ���ַ��ñ���
	HuffmanCode(ht.GetRoot());

	//4.����ÿ���ַ��ñ�����д��дԴ�ļ�
	FILE* fOut = fopen("1.hzp","w");
	assert(fOut);
	WriteHead(fOut, strFilePath);
	char ch = 0;
	size_t bitCount = 0;
	fseek(fIn, 0, SEEK_SET);   
	while (true)
	{
		size_t rdsize = fread(pReadBuff, 1, 1024, fIn);
		if (rdsize == 0)
			break;
		for (size_t i = 0; i < rdsize; ++i)
		{
			string& strCode = _charInfo[pReadBuff[i]]._strCode;
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;//������1λ
				if (strCode[j] == '1')
					ch |= 1;
				bitCount++;
				if (bitCount == 8)
				{
					fputc(ch, fOut);
					bitCount = 0;
				}	
			}
		}
	}	
	if (bitCount < 8&& bitCount>0)
	{
		ch <<= (8 - bitCount); //�ֶ���䵽8���ֽ�
			fputc(ch, fOut);
	}
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void  FileCompressHuffM::UNCompressFile(const string& strFilePath)
{
	//���ѹ���ļ��ú�׺��ʽ
	string strPostFix = strFilePath.substr(strFilePath.rfind('.'));
	if (".hzp" != strPostFix)
	{
		cout << "ѹ����ʽ������" << endl;
		return;
	}
	//��ȡ��ѹ����Ϣ
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		cout << "ѹ���ļ���ʧ��" << endl;
		return;
	}
	//��ȡ�ļ���׺
	strPostFix = " ";
	GetLine(fIn, strPostFix);
	//��ȡ����
	string strContent;
	GetLine(fIn, strContent);
	size_t lineCount = atoi(strContent.c_str());

	//�ַ���Ϣ
	for (size_t i = 0; i < lineCount; ++i)
	{
		strContent = " ";
		GetLine(fIn, strContent);
		if (strContent.empty())
		{
			strContent += "\n";
			GetLine(fIn, strContent);
		}
		_charInfo[(UCH)strContent[0]]._charCount = atoi(strContent.c_str()+2);
	}
	//����Huffman��
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo, CharInfo(0));

	//��ѹ��
	string strUNCompFile = "2";
	strUNCompFile += strPostFix;
	FILE* fOut = fopen(strUNCompFile.c_str(), "w");
	assert(fOut);
	char* pReadBuff = new char[1024];
	char pos = 7; 
	HuffmanTreeNode<CharInfo>* pCur = ht.GetRoot();
	size_t fileSize = pCur->_weight._charCount;  //�ļ��ַ���С
	while (true)
	{
		pos = 7;
		size_t rdsize = fread(pReadBuff, 1, 1024, fOut);
		if (0 == rdsize)
		{
			break;
		}
		for (size_t i = 0; i < rdsize; ++i)
		{
			for (size_t j = 0; j < 8; ++j)
			{
				if (pReadBuff[i] & (1 << pos)) //��1�����ƶ���λ��������λ�Ƿ�Ϊ1
					pCur=pCur->_pRight;
				else
					pCur = pCur->_pLeft;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					fputc(pCur->_weight._ch, fOut);
					pCur = ht.GetRoot();
					fileSize--;
					if (fileSize == 0)
						break;
				}
				pos--;
			}
		}
	}
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuffM::HuffmanCode(HuffmanTreeNode<CharInfo>* proot)
{
	if (proot==nullptr)
	{
		return;
	}
	HuffmanCode(proot->_pLeft);
	HuffmanCode(proot->_pRight);
	if (proot->_pLeft == nullptr && proot->_pRight == nullptr)
	{
		HuffmanTreeNode<CharInfo>* pCur = proot;
		HuffmanTreeNode<CharInfo>* pParent = pCur->_pParent;
		string& strCode = _charInfo[pCur->_weight._ch]._strCode;
		while (pParent)
		{

			if (pCur == pParent->_pLeft)
				strCode += "0";
			else
				strCode += "1";
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());//����������
	}
		
}
void FileCompressHuffM::WriteHead(FILE* fOut, const string& strFilePath)
{
	string strHeadInfo; 
	strHeadInfo = strFilePath.substr(strFilePath.rfind('.'));//�Ӻ����ȡ�ļ���׺
	strHeadInfo += '\n';
	string strCharInfo;
	char szCount[32];
	size_t lineCount = 0;
	for (size_t i = 0; i < 256; ++i)
	{
		if (_charInfo[i]._charCount)
		{
			strCharInfo += _charInfo[i]._charCount;
			strCharInfo += ',';
			_itoa(_charInfo[i]._charCount, szCount, 10);
			strCharInfo += szCount;
			strCharInfo += '\n';	//����ÿ���ַ����ִ���
			lineCount++;
		}
	}
	_itoa(lineCount, szCount, 10); //��������
	strHeadInfo += szCount;
	strHeadInfo += '\n';
	strHeadInfo += strCharInfo;
	fwrite(strHeadInfo.c_str(), 1,strHeadInfo.size(),fOut );
}

void FileCompressHuffM::GetLine(FILE* fIn, string& strContent) //��ȡÿ����Ϣ
{
	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
		{
			return;
		}
		strContent += ch;
	}
}