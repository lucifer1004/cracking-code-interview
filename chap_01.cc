#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Util Functions

void to_lower(string &s)
{
  transform(s.begin(), s.end(),
            s.begin(), ::tolower);
}

// Test whether b is one substring of a
bool is_substring(string &a, string &b)
{
  int la = a.size();
  int lb = b.size();
  if (lb > la)
    return false;
  for (int i = 0; i < la - lb + 1; ++i)
  {
    if (a.substr(i, lb) == b)
      return true;
  }
  return false;
}

// Solutions
// 1.1 Is Unique
bool is_unique_hash(string s)
{
  unordered_map<char, bool> e;
  for (const char &c : s)
  {
    if (e[c])
      return false;
    else
      e[c] = true;
  }
  return true;
}

bool is_unique_brute(string s)
{
  for (int i = 0; i < s.size() - 1; ++i)
  {
    for (int j = i + 1; j < s.size(); ++j)
    {
      if (s[i] == s[j])
        return false;
    }
  }
  return true;
}

bool is_unique_sort(string s)
{
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size() - 1; ++i)
    if (s[i] == s[i + 1])
      return false;
  return true;
}

// 1.2 Check Permutation
bool check_permutation_sort(string s, string t)
{
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

bool check_permutation_hash(string s, string t)
{
  unordered_map<char, int> s_count, t_count;
  for (const char &c : s)
    s_count[c]++;
  for (const char &c : t)
    t_count[c]++;
  return s_count == t_count;
}

// 1.3 URLify
void urlify(string &s)
{
  int space_count = 0;
  int i = s.size() - 1;
  while (s[i] == ' ')
    i--;
  int idx = i;
  while (i >= 0)
  {
    if (s[i] == ' ')
      space_count++;
    i--;
  }
  int hi = idx + space_count * 2;
  i = idx;
  while (i >= 0)
  {
    if (s[i] != ' ')
    {
      s[hi] = s[i];
      hi--;
    }
    else
    {
      s[hi - 2] = '%';
      s[hi - 1] = '2';
      s[hi] = '0';
      hi -= 3;
    }
    i--;
  }
}

// 1.4 Palindrome Permutation
bool is_palindrome_permutation(string s)
{
  unordered_map<char, int> count;
  to_lower(s);
  for (const char &c : s)
  {
    if (c != ' ')
      count[c]++;
  }
  int odd_count = 0;
  for (const auto &p : count)
  {
    if (p.second % 2 == 1)
      odd_count++;
  }
  return odd_count <= 1;
}

// 1.5 One Away
bool is_one_away(string s, string t)
{
  int ls = s.size();
  int lt = t.size();
  if (ls > lt)
    return is_one_away(t, s);
  if (ls + 2 <= lt)
    return false;
  if (ls == 0)
    return true;
  if (ls == lt)
  {
    int diff = 0;
    for (int i = 0; i < ls; ++i)
      if (s[i] != t[i])
        diff++;
    return diff <= 1;
  }
  int i = 0;
  while (i < ls && s[i] == t[i])
    i++;
  return s.substr(i, ls - i) == t.substr(i + 1, ls - i);
}

// 1.6 String Compression
string compress(string s)
{
  if (s.empty())
    return s;
  char curr = s[0];
  int count = 0;
  string compressed;
  for (const char &c : s)
  {
    if (c == curr)
      count++;
    else
    {
      compressed += string{curr} + to_string(count);
      curr = c;
      count = 1;
    }
  }
  return compressed.size() < s.size() ? compressed : s;
}

// 1.7 Rotate Matrix
void rotate_matrix(vector<vector<int>> &mat)
{
  int n = mat.size();
  int r = n / 2;
  int c = n / 2;
  if (n & 1)
    c++;
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      int mi = n - i - 1;
      int mj = n - j - 1;
      int tmp = mat[i][j];
      mat[i][j] = mat[mj][i];
      mat[mj][i] = mat[mi][mj];
      mat[mi][mj] = mat[j][mi];
      mat[j][mi] = tmp;
    }
  }
}

// 1.8 Zero Matrix
void spread_zero(vector<vector<int>> &mat)
{
  int r = mat.size();
  if (r == 0)
    return;
  int c = mat[0].size();
  if (c == 0)
    return;

  unordered_set<int> rows, cols;
  for (int i = 0; i < r; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      if (mat[i][j] == 0)
      {
        rows.insert(i);
        cols.insert(j);
      }
    }
  }

  for (const int &row : rows)
  {
    for (int j = 0; j < c; ++j)
    {
      mat[row][j] = 0;
    }
  }

  for (const int &col : cols)
  {
    for (int i = 0; i < r; ++i)
    {
      mat[i][col] = 0;
    }
  }
}

// 1.9 String Rotation
bool is_rotated_string(string &a, string &b)
{
  if (a.size() != b.size())
    return false;
  string aa = a + a;
  return is_substring(aa, b);
}

int main()
{
  return 0;
}