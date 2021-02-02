# **[libwordring]** サンプル

HTML ソースから HTML 木を構築し、 CSS セレクタで URL を抜き出して出力するsampleです。

**[libwordring]** の HTML パーサーは、 **[WHATWG HTML5]** の実装です。　CSS セレクタは、 **[Selectors Level 4]** の実装です。

----

**[サンプルプロジェクト]** からソースコードの抜粋

```c++
#include <wordring/css/selector.hpp>
#include <wordring/html/simple_html.hpp>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
	using namespace wordring;

	// 文字列に HTML ソースを読み込みます。
	std::string s;
	auto ifs = std::ifstream("sample.html");
	std::copy(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), std::back_inserter(s));

	// 文字列から HTML 木を作ります。
	auto doc = html::make_document<html::u8simple_tree>(s.begin(), s.end());

	// CSS セレクタでリンクを抜き出します。
	std::vector<html::u8simple_tree::const_iterator> v;
	css::query_selector_all(doc.begin(), u8"body [href]", std::back_inserter(v));

	// リンクを表示します。
	for (auto it : v) std::cout << it->find(u8"href")->value() << std::endl;

	return 0;
}

```

**出力**

```console
https://www.boost.org/
https://libexpat.github.io/
http://site.icu-project.org/home
https://www.sqlite.org/index.html
````

## **[make_document()]**

文字列から HTML 木を作る便利関数です。 **[libwordring]** の HTML パーサーは、あらゆる局面で使えるように、複雑なパラメータを指定できますが、それらに妥当な規定値を与え使いやすくしました。

テンプレート引数は、HTML 木構築に使う Tree コンテナの型を指定します。　よく使われそうな3種類の便利な型エイリアスがあります。　**u8** などの接頭辞は、HTML ノードの文字コードです。　HTML ソースの文字コードは、ソース自身が知っています。　あるいは、関数呼び出し時の引数として、信頼度と共に指定します。

- u8simple_tree
- u16simple_tree
- u32simple_tree

関数呼び出しの引数は、HTML ソース文字列を指すイテレータです。　

## **[query_selector_all()]**

引数で指定したノード以下を指定の **CSS セレクタ**で検索し、マッチしたノードをすべて出力イテレータへ書き込みます。

----

[libwordring]:https://github.com/wordring/libwordring
[サンプルプロジェクト]:https://github.com/wordring/libwordring-sample/tree/main/sample/html/crawl-1
[make_document()]:https://wordring.github.io/libwordring/api/html/namespacewordring_1_1html.html#ae52e0499a88c09f71b5e1341d926d216
[query_selector_all()]:https://wordring.github.io/libwordring/api/html/namespacewordring_1_1css.html#ad55886e3ef0d4e3a3d9f217d45eebc84

[WHATWG HTML5]:https://html.spec.whatwg.org/multipage/
[Selectors Level 4]:https://drafts.csswg.org/selectors-4/
 