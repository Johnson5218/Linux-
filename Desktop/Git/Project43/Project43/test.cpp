//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//// ��ʾ�������ֵı�־
//const int INT_ONLY = 1;
//// ��ʾС�����ֵı�־
//const int SMALL_ONLY = 2;
//
//
//
//
//bool checkNum(string s) {
//	// atof(s.c_str()) �����Ĺ����ǽ��ַ��� s ת����һ��˫������ֵ�����ؽ��
//	double d = atof(s.c_str());
//	// ֻ�е��û�����һ������0����ʱ���Ż᷵��true
//	if (d > 0) {
//		return true;
//	}
//	return false;
//}
//
//
//string roundString(string s) {
//
//	double d = atof(s.c_str());
//
//	int dec, sign;
//
//	s = fcvt(d, 2, &dec, &sign);
//
//	if (s.length() > 15) {
//		cout << "�������ݹ��󣡣������������13λ����" << endl;
//		return "";
//	}
//	return s;
//}
//
//
//
//string formatChinese(int flag, string s) {
//	int sLength = s.length();
//	// ���Ҵ�д��ʽ
//	string bigLetter[] = { "��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��" };
//	// ���ҵ�λ
//	string unit[] = { "Ԫ", "ʰ", "��", "Ǫ", "��",
//		// ʰ��λ��Ǫ��λ
//		"ʰ", "��", "Ǫ",
//		// ��λ������λ
//		"��", "ʰ", "��", "Ǫ", "��" };
//	string small[] = { "��", "��" };
//	// �������ת��������ַ���
//	string newS = "";
//	// ��λ�滻Ϊ���Ĵ�д��ʽ
//	for (int i = 0; i < sLength; i++) {
//		if (flag == INT_ONLY) {
//			// ת����������Ϊ���Ĵ�д��ʽ������λ��
//			newS = newS + bigLetter[s.at(i) - 48] + unit[sLength - i - 1];
//		}
//		else if (flag == SMALL_ONLY) {
//			// ת��С�����֣�����λ��
//			newS = newS + bigLetter[s.at(i) - 48] + small[sLength - i - 1];
//		}
//	}
//	return newS;
//}
//
//
//
//string splitNum(string s) {
//	// ���������ǿմ���������ؿմ�
//	if ("" == s) {
//		return "";
//	}
//	// ��ȡ�������ֵ���������
//	string intOnly = s.substr(0, s.size() - 2);
//	string intPart = formatChinese(1, intOnly);
//
//	// ��ȡ�������С������
//	string smallOnly = s.substr(s.size() - 2, s.size());
//	string smallPart = formatChinese(2, smallOnly);
//
//	// ��ת�����˵��������ֺ�С����������ƴ��һ���µ��ַ���
//	string newS = intPart + smallPart;
//
//	return newS;
//}
//
//
//
//string replaceAll(string src, string regex, string replacement) {
//	int length = regex.length();
//	while (src.find(regex) < src.length()) {
//		// �滻 src �ַ����дӵ�һ��ƥ�� regex ���ַ���������ʼ�� length ���ַ�Ϊ replacement �ַ���		
//		src.replace(src.find(regex), length, replacement);
//	}
//	return src;
//}
//
//
//
//string cleanZero(string s) {
//	if ("" == s) {
//		return "";
//	}
//	string regex1[] = { "��Ǫ", "���", "��ʰ" };
//	string regex2[] = { "����", "����", "��Ԫ" };
//	string regex3[] = { "��", "��", "Ԫ" };
//	string regex4[] = { "���", "���" };
//
//	for (int i = 0; i < 3; i++) {
//		s = replaceAll(s, regex1[i], "��");
//	}
//
//	for (int i = 0; i < 3; i++) {
//
//		s = replaceAll(s, "������", "��");
//		s = replaceAll(s, "����", "��");
//		s = replaceAll(s, regex2[i], regex3[i]);
//	}
//	for (int i = 0; i < 2; i++) {
//		s = replaceAll(s, regex4[i], "");
//	}
//	s = replaceAll(s, "����", "��");
//	return s;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	vector<string> res;
//	string temp;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (((s[i] - '0') >= 0) && ((s[i] - '0') <= 0) || s[i] == '.'){
//			temp += s[i];
//			continue;
//		}
//		if (s[i] == '\"'){
//			if (checkNum(temp)) {
//				temp = roundString(temp);
//				temp = splitNum(temp);
//				temp = cleanZero(temp);
//				res.push_back(temp);
//				temp.clear();
//			}
//		}
//	}
//	cout << "�����";
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i];
//	}
//	return 0;
//}
