libwordring-sample
====

libwordring を使ったサンプル集です。

## libwordring をサブモジュールとして CMake で使う

- サブモジュールとして追加した **libwordring** フォルダを **add_subdirectory()** します
- **libwordring/include** フォルダを **include_directories()** します
- **wordring** を **target_link_libraries** します

以上です。

サンプルの **CMakeLists.txt** を見てください。

## サンプル・プロジェクトの御案内

| プロジェクト | 御説明 |
|----|----|
| html/crawl | ウェブページをダウンロードして URL を抜き出す |