/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

/*
真心给跪了。。。以后碰到模拟真的是要想清楚，调得头都痛了，最后全删重写
输出Unix下的最简路径，Unix文件的根目录为"/"，"."表示当前目录，".."表示上级目录。
例如：
输入1：
/../a/b/c/./.. 
输出1：
/a/b
模拟整个过程：
1. "/" 根目录
2. ".." 跳转上级目录，上级目录为空，所以依旧处于 "/"
3. "a" 进入子目录a，目前处于 "/a"
4. "b" 进入子目录b，目前处于 "/a/b"
5. "c" 进入子目录c，目前处于 "/a/b/c"
6. "." 当前目录，不操作，仍处于 "/a/b/c"
7. ".." 返回上级目录，最终为 "/a/b"

用了stack，遇到"."不操作，遇到".."退栈（判空），其他情况都压入堆栈。
*/

class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty()) {
			return "";
		}
		stack<string> stk;
		int i = 0;
		while (i < path.length()) {
			while (i < path.length() && path[i] == '/') {
				i++;
			}
			int j = i + 1;
			while (j < path.length() && path[j] != '/') {
				j++;
			}

			string cmd = path.substr(i, j - i);
			if (!cmd.empty()) { //如果cmd有内容（小心"///"）
				if (cmd == "..") {
					if (!stk.empty()) {
						stk.pop();
					}
				} else if (cmd != ".") {
					reverse(cmd.begin(), cmd.end());
					stk.push(cmd + "/"); //因为会全反过来，所以相当于/home -> emoh/
				} 
			}
			i = j + 1;
		}

		string res = "";
		while (!stk.empty()) {
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		if (res.empty()) { //可能是退无可退处 /../
			res += "/";
		}
		return res;
	}

};
