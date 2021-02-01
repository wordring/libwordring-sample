
#include <wordring/css/selector.hpp>
#include <wordring/html/simple_html.hpp>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define STRING(str) #str
#define TO_STRING(str) STRING(str)

// CMakeLists.txt からソースコードのあるディレクトリを頂戴します。
std::string current_source_dir = TO_STRING(CURRENT_SOURCE_DIR);

int main(int argc, char** argv)
{
	using namespace wordring;

	// 文字列に HTML ソースを読み込みます。
	std::string s;
	auto ifs = std::ifstream(current_source_dir + "/sample.html");
	std::copy(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), std::back_inserter(s));

	// 文字列から HTML 木を作ります。
	auto doc = html::make_document<html::u8simple_tree>(s.begin(), s.end());

	// CSS セレクタでリンクを抜き出します。
	std::vector<html::u8simple_tree::const_iterator> v;
	css::query_selector_all(doc.begin(), u8"body [href]", std::back_inserter(v));

	// リンクを表示します。
	for (auto np : v) std::cout << np->find(u8"href")->value() << std::endl;

	return 0;
}
