/*
Roman to Integer :
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

/*
罗马数字基本符号：
I	 V	X	  L	  C	  D	  M
1  5	10  50 	100 500	1000

计数规则： 
1. 相同连写，且连写不超过3次 e.g. III = 3
2. 小在大右 = 加 e.g. VI = 1 + 5 
3. 大在小右 = 减 e.g. IV = 5 - 1

trick：
从前向后遍历罗马数字，如果某个数比前一个数小(dic[s[i]] <= dic[s[i - 1]])，则加上该数。反之，减去前一个数的两倍然后加上该数
*/
 
class Solution {
public:
  int romanToInt(string s) {
  	if (s.empty()) {
	    return 0;
	  }
		InitDic();
		int sum = dic[s[0]];
		for (int i = 1; i < s.length(); i++) {
			if (dic[s[i]] <= dic[s[i - 1]]) {
				sum += dic[s[i]];
			}
			else {
				sum = sum - 2 * dic[s[i - 1]] + dic[s[i]]; 
			}
		}
		return sum;
  }

private:
	unordered_map<char, int> dic;
	void InitDic() {
		dic['I'] = 1;
		dic['V'] = 5;
		dic['X'] = 10;
		dic['L'] = 50;
		dic['C'] = 100;
		dic['D'] = 500;
		dic['M'] = 1000;
	}
