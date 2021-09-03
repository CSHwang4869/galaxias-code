#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
	char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
	for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
	if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
	for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
inline ll read1() {
	char c; ll x; for (c = readChar(); !isdigit(c); c = readChar());
	for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
const int mod = 998244353;
const int N = 2e5 + 10;

int n, m, x, y;
void work(int n, int m, int &x, int &y)
{
	if (n == 1)
	{
		x = y = 0;
		return;
	}
	if (m / (n * n / 4) == 0) work(n >> 1, m % (n * n / 4), y, x);
	else if (m / (n * n / 4) == 1)
	{
		work(n >> 1, m % (n * n / 4), x, y);
		y += (n >> 1);
	}
	else if (m / (n * n / 4) == 2)
	{
		work(n >> 1, m % (n * n / 4), x, y);
		x += (n >> 1);
		y += (n >> 1);
	}
	else
	{
		work((n >> 1), m % (n * n / 4), y, x);
		x = n - 1 - x;
		y = (n >> 1) - 1 - y;
	}
}

int main()
{
	n = read();
	m = read();
	m --;
	work(n, m, x, y);
	cout << x + 1 << ' ' << y + 1 << endl;
	return 0;
}