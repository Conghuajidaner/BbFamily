// 基于计数的贪心


====================================================
// 基于最大堆的贪心

====================================================
// 假算法：按照出现频率排序，如果第i位的个数大于第i - 1 的前缀和，就返回 false
struct table {
	char c;
	int c_count;
	bool operator<(table& p)
	{
		return c_count < p.c_count;
	}
};

string reorganizeString(string S) {
	vector<table>buf(26);

	for (auto& c : S) buf[c - 'a'].c_count++;
	for (int i = 0; i < 26; ++i) buf[i].c = 'a' + i;
	sort(buf.begin(), buf.end());

	vector<int>tmp(26);
	for (int i = 0; i < 26; ++i)
		tmp[i] = buf[i].c_count;

	for (int i = 1; i < 26; ++i)
		tmp[i] += tmp[i - 1];

	for (int i = 25; i >= 1; i -= 2)
	{
		if (tmp[i - 1] != 0 && buf[i].c_count - tmp[i - 1] > 1)
			return "";
		if (tmp[i - 1] == 0 && buf[i].c_count > 1) return "";
	}

	string ans = "";
	for (int i = 25; i >= 1; --i)
	{
		int j = i - 1;
		while (buf[i].c_count != 0)
		{
			while (j >= 1 && buf[j].c_count <= 0) j--;
			ans += buf[i].c;
			buf[i].c_count--;
			if (buf[i].c_count == 0) continue;
			ans += buf[j].c;
			buf[j].c_count--;
			if (buf[j].c_count <= 0) continue;
		}
	}
	
	for (auto v : buf)
	{
		if (v.c_count)
		ans += v.c;
	}
	return ans;
}
