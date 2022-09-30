#include "tests.hpp"
#include <map>
#include <utility>

template <class T>
static void print_map(T &map)
{
	typename T::iterator it = map.begin();
	std::cout << " --- map of size " << map.size() << " ---" << std::endl;
	while (it != map.end())
	{
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << " --- " << std::endl;
}

static void constructors(void)
{
	print_header("Constructors / Copy");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("(default) m1 == m2", (m1 == m2));
	ft::map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	check("(range) m3 == m4", (m3 == m4));
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	check("(copy) m5 == m6", (m3 == m4));
	ft::map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	check("(copy) m7 == m8", (m7 == m8));
	ft::map<int, int> m9;
	std::map<int, int> m10;
	m9 = m7;
	m10 = m8;
	check("(copy) m9 == m10", (m9 == m10));
}

static void max_size(void)
{
	print_header("Size");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
}

static void access_operator(void)
{
	print_header("[] operator");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	check("m1 == m2", m1 == m2);
	check("m1['a'] == m2['a']", m1["a"], m2["a"]);
	check("m1['d'] == m2['d']", m1["d"], m2["d"]);
	check("m1['test'] == m2['test']", m1["test"], m2["test"]);
	check("m1['z'] == m2['z']", m1["z"], m2["z"]);
}

static void erase(void)
{
	print_header("Erase");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;
	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;
	check("m1 == m2", m1 == m2);
	m1.erase(++m1.begin());
	m2.erase(++m2.begin());
	check("m1 == m2", m1 == m2);
}

static void swap(void)
{
	print_header("Swap");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	check("m1 == m2", m1 == m2);
	check("m3 == m4", m3 == m4);
}

static void clear(void)
{
	print_header("Clear");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	check("m1 == m2", m1 == m2);
}

static void find(void)
{
	print_header("Find");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	check("m1.find('a') == m2.find('a')", m1.find("a")->second, m2.find("a")->second);
	check("m1.find('z') == m2.find('z')", m1.find("a")->second, m2.find("a")->second);
}

static void count(void)
{
	print_header("Count");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	check("m1.count('a') == m2.count('a')", m1.count("a"), m2.count("a"));
	check("m1.count('b') == m2.count('b')", m1.count("b"), m2.count("b"));
	check("m1.count('z') == m2.count('z')", m1.count("z"), m2.count("z"));
}

static void bounds()
{
	print_header("Bounds");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

static void operators_comp(void)
{
	print_header("Operators");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m1["e"] = 1;
	m2["e"] = 1;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m3["e"] = 3;
	m4["e"] = 3;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
}

void test_map(void)
{
	print_header("map");
	constructors();
	max_size();
	access_operator();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	operators_comp();
}

